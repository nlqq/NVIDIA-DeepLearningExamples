#!/usr/bin/python

# Copyright (c) 2020, NVIDIA CORPORATION. All rights reserved. 
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License. 
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, 
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
# See the License for the specific language governing permissions and
# limitations under the License. 

import torch
import argparse
import deployer_lib
# 
import sys
sys.path.append('../')
from modeling_jit import BertForQuestionAnswering, BertConfig
from tokenization import BertTokenizer
from inference import preprocess_tokenized_text


def get_model_args(model_args):
    ''' the arguments initialize_model will receive '''
    parser = argparse.ArgumentParser()
    ## Required parameters by the model. 
    parser.add_argument("--checkpoint", 
                        default=None, 
                        type=str, 
                        required=True, 
                        help="The checkpoint of the model. ")
    parser.add_argument('--batch_size', 
                        default=1, 
                        type=int, 
                        help='Batch size for inference')
    parser.add_argument("--bert_model", default="bert-large-uncased", type=str, 
                        help="Bert pre-trained model selected in the list: bert-base-uncased, "
                             "bert-large-uncased, bert-base-cased, bert-large-cased, bert-base-multilingual-uncased, "
                             "bert-base-multilingual-cased, bert-base-chinese.")
    parser.add_argument("--question1", default="Most antibiotics target bacteria and don't affect what class of organisms? ", 
                                              type=str, help="question")
    parser.add_argument("--context1", default="Within the genitourinary and gastrointestinal tracts, commensal flora serve as biological barriers by competing with pathogenic bacteria for food and space and, in some cases, by changing the conditions in their environment, such as pH or available iron. This reduces the probability that pathogens will reach sufficient numbers to cause illness. However, since most antibiotics non-specifically target bacteria and do not affect fungi, oral antibiotics can lead to an overgrowth of fungi and cause conditions such as a vaginal candidiasis (a yeast infection). There is good evidence that re-introduction of probiotic flora, such as pure cultures of the lactobacilli normally found in unpasteurized yogurt, helps restore a healthy balance of microbial populations in intestinal infections in children and encouraging preliminary data in studies on bacterial gastroenteritis, inflammatory bowel diseases, urinary tract infection and post-surgical infections. ", 
                                              type=str, help="context")
    parser.add_argument("--question2", default="What is probiotic flora good for? ", 
                                              type=str, help="question")
    parser.add_argument("--context2", default="Within the genitourinary and gastrointestinal tracts, commensal flora serve as biological barriers by competing with pathogenic bacteria for food and space and, in some cases, by changing the conditions in their environment, such as pH or available iron. This reduces the probability that pathogens will reach sufficient numbers to cause illness. However, since most antibiotics non-specifically target bacteria and do not affect fungi, oral antibiotics can lead to an overgrowth of fungi and cause conditions such as a vaginal candidiasis (a yeast infection). There is good evidence that re-introduction of probiotic flora, such as pure cultures of the lactobacilli normally found in unpasteurized yogurt, helps restore a healthy balance of microbial populations in intestinal infections in children and encouraging preliminary data in studies on bacterial gastroenteritis, inflammatory bowel diseases, urinary tract infection and post-surgical infections. ", 
                                              type=str, help="context")
    parser.add_argument("--question3", default="What is probiotic flora? ", 
                                              type=str, help="question")
    parser.add_argument("--context3", default="There is good evidence that re-introduction of probiotic flora, such as pure cultures of the lactobacilli normally found in unpasteurized yogurt, helps restore a healthy balance of microbial populations in intestinal infections in children and encouraging preliminary data in studies on bacterial gastroenteritis, inflammatory bowel diseases, urinary tract infection and post-surgical infections. ", 
                                              type=str, help="context")
    parser.add_argument("--max_seq_length", default=384, type=int, 
                        help="The maximum total input sequence length after WordPiece tokenization. Sequences "
                             "longer than this will be truncated, and sequences shorter than this will be padded.")
    parser.add_argument("--max_query_length", default=64, type=int, 
                        help="The maximum number of tokens for the question. Questions longer than this will "
                             "be truncated to this length.")
    parser.add_argument("--do_lower_case", 
                        action='store_true', 
                        help="Whether to lower case the input text. True for uncased models, False for cased models.")
    parser.add_argument('--vocab_file', 
                        type=str, default=None, required=True, 
                        help="Vocabulary mapping/file BERT was pretrainined on")
    parser.add_argument("--config_file", 
                        default=None, 
                        type=str, 
                        required=True, 
                        help="The BERT model config")
    parser.add_argument('--fp16',
                        action='store_true',
                        help="use mixed-precision")
    return parser.parse_args(model_args)


def initialize_model(args):
    ''' return model, ready to trace '''
    config = BertConfig.from_json_file(args.config_file)
    if config.vocab_size % 8 != 0:
        config.vocab_size += 8 - (config.vocab_size % 8)
    model = BertForQuestionAnswering(config)
    state_dict = torch.load(args.checkpoint, map_location='cpu')["model"]
    model.load_state_dict(state_dict)
    if args.fp16:
        model.half()
    return model


def get_dataloader(args):
    ''' return dataloader for inference '''
    contexts = [args.context1, args.context2, args.context3]
    questions = [args.question1, args.question2, args.question3]
    tokenizer = BertTokenizer(args.vocab_file, do_lower_case=args.do_lower_case, max_len=512) # for bert large
    data = []
    for question, context in zip(questions, contexts):
        doc_tokens = context.split()
        query_tokens = tokenizer.tokenize(question)
        feature = preprocess_tokenized_text(doc_tokens, 
                                            query_tokens, 
                                            tokenizer, 
                                            max_seq_length=args.max_seq_length, 
                                            max_query_length=args.max_query_length)
        tensors_for_inference, _ = feature
        input_ids = torch.tensor(tensors_for_inference.input_ids, dtype=torch.long)
        segment_ids = torch.tensor(tensors_for_inference.segment_ids, dtype=torch.long)
        input_mask = torch.tensor(tensors_for_inference.input_mask, dtype=torch.long)
        inp = (input_ids, segment_ids, input_mask)
        for _ in range(args.batch_size):
            data.append(inp)
    # 
    test_loader = torch.utils.data.DataLoader(
        data, 
        batch_size=args.batch_size, 
        shuffle=False, 
        num_workers=1, 
        pin_memory=True)
    return test_loader


if __name__=='__main__':
    # don't touch this! 
    deployer, model_argv = deployer_lib.create_deployer(sys.argv[1:]) # deployer and returns removed deployer arguments
    
    model_args = get_model_args(model_argv)
    
    model = initialize_model(model_args)
    dataloader = get_dataloader(model_args)
    
    deployer.deploy(dataloader, model)

