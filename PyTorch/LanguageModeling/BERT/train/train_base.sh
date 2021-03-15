bash run_pretraining.sh 2048 6e-3 fp32 1 > new_1_bert_base
rm -rf ../results/
bash run_pretraining.sh 2048 6e-3 fp32 4 > new_4_bert_base
rm -rf ../results/
bash run_pretraining.sh 2048 6e-3 fp32 8 > new_8_bert_base
