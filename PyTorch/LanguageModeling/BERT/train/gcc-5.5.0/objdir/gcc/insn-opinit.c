/* Generated automatically by the program `genopinit'
   from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "hash-set.h"
#include "machmode.h"
#include "vec.h"
#include "double-int.h"
#include "input.h"
#include "alias.h"
#include "symtab.h"
#include "wide-int.h"
#include "inchash.h"
#include "tree.h"
#include "varasm.h"
#include "stor-layout.h"
#include "calls.h"
#include "rtl.h"
#include "predict.h"
#include "tm_p.h"
#include "flags.h"
#include "insn-config.h"
#include "hashtab.h"
#include "hard-reg-set.h"
#include "function.h"
#include "statistics.h"
#include "real.h"
#include "fixed-value.h"
#include "expmed.h"
#include "dojump.h"
#include "explow.h"
#include "emit-rtl.h"
#include "stmt.h"
#include "expr.h"
#include "insn-codes.h"
#include "optabs.h"

struct optab_pat {
  unsigned scode;
  enum insn_code icode;
};

static const struct optab_pat pats[NUM_OPTAB_PATTERNS] = {
  { 0x010e0f, CODE_FOR_extendqihi2 },
  { 0x010e10, CODE_FOR_extendqisi2 },
  { 0x010e11, CODE_FOR_extendqidi2 },
  { 0x010f10, CODE_FOR_extendhisi2 },
  { 0x010f11, CODE_FOR_extendhidi2 },
  { 0x011011, CODE_FOR_extendsidi2 },
  { 0x01292a, CODE_FOR_extendsfdf2 },
  { 0x01292b, CODE_FOR_extendsfxf2 },
  { 0x012a2b, CODE_FOR_extenddfxf2 },
  { 0x022a29, CODE_FOR_truncdfsf2 },
  { 0x022b29, CODE_FOR_truncxfsf2 },
  { 0x022b2a, CODE_FOR_truncxfdf2 },
  { 0x030e0f, CODE_FOR_zero_extendqihi2 },
  { 0x030e10, CODE_FOR_zero_extendqisi2 },
  { 0x030e11, CODE_FOR_zero_extendqidi2 },
  { 0x030f10, CODE_FOR_zero_extendhisi2 },
  { 0x030f11, CODE_FOR_zero_extendhidi2 },
  { 0x031011, CODE_FOR_zero_extendsidi2 },
  { 0x060f29, CODE_FOR_floathisf2 },
  { 0x060f2a, CODE_FOR_floathidf2 },
  { 0x060f2b, CODE_FOR_floathixf2 },
  { 0x061029, CODE_FOR_floatsisf2 },
  { 0x06102a, CODE_FOR_floatsidf2 },
  { 0x06102b, CODE_FOR_floatsixf2 },
  { 0x061129, CODE_FOR_floatdisf2 },
  { 0x06112a, CODE_FOR_floatdidf2 },
  { 0x06112b, CODE_FOR_floatdixf2 },
  { 0x06485b, CODE_FOR_floatv4siv4sf2 },
  { 0x06485e, CODE_FOR_floatv4siv4df2 },
  { 0x06495c, CODE_FOR_floatv2div2df2 },
  { 0x064d5d, CODE_FOR_floatv8siv8sf2 },
  { 0x064d61, CODE_FOR_floatv8siv8df2 },
  { 0x064e5b, CODE_FOR_floatv4div4sf2 },
  { 0x064e5e, CODE_FOR_floatv4div4df2 },
  { 0x065260, CODE_FOR_floatv16siv16sf2 },
  { 0x06535d, CODE_FOR_floatv8div8sf2 },
  { 0x065361, CODE_FOR_floatv8div8df2 },
  { 0x070e29, CODE_FOR_floatunsqisf2 },
  { 0x070e2a, CODE_FOR_floatunsqidf2 },
  { 0x070f29, CODE_FOR_floatunshisf2 },
  { 0x070f2a, CODE_FOR_floatunshidf2 },
  { 0x071029, CODE_FOR_floatunssisf2 },
  { 0x07102a, CODE_FOR_floatunssidf2 },
  { 0x07102b, CODE_FOR_floatunssixf2 },
  { 0x071129, CODE_FOR_floatunsdisf2 },
  { 0x07112a, CODE_FOR_floatunsdidf2 },
  { 0x07485b, CODE_FOR_floatunsv4siv4sf2 },
  { 0x074d5d, CODE_FOR_floatunsv8siv8sf2 },
  { 0x075260, CODE_FOR_floatunsv16siv16sf2 },
  { 0x082910, CODE_FOR_lrintsfsi2 },
  { 0x082911, CODE_FOR_lrintsfdi2 },
  { 0x082a10, CODE_FOR_lrintdfsi2 },
  { 0x082a11, CODE_FOR_lrintdfdi2 },
  { 0x082b0f, CODE_FOR_lrintxfhi2 },
  { 0x082b10, CODE_FOR_lrintxfsi2 },
  { 0x082b11, CODE_FOR_lrintxfdi2 },
  { 0x09290f, CODE_FOR_lroundsfhi2 },
  { 0x092910, CODE_FOR_lroundsfsi2 },
  { 0x092911, CODE_FOR_lroundsfdi2 },
  { 0x092a0f, CODE_FOR_lrounddfhi2 },
  { 0x092a10, CODE_FOR_lrounddfsi2 },
  { 0x092a11, CODE_FOR_lrounddfdi2 },
  { 0x092b0f, CODE_FOR_lroundxfhi2 },
  { 0x092b10, CODE_FOR_lroundxfsi2 },
  { 0x092b11, CODE_FOR_lroundxfdi2 },
  { 0x0a2910, CODE_FOR_lfloorsfsi2 },
  { 0x0a2911, CODE_FOR_lfloorsfdi2 },
  { 0x0a2a10, CODE_FOR_lfloordfsi2 },
  { 0x0a2a11, CODE_FOR_lfloordfdi2 },
  { 0x0a2b0f, CODE_FOR_lfloorxfhi2 },
  { 0x0a2b10, CODE_FOR_lfloorxfsi2 },
  { 0x0a2b11, CODE_FOR_lfloorxfdi2 },
  { 0x0b2910, CODE_FOR_lceilsfsi2 },
  { 0x0b2911, CODE_FOR_lceilsfdi2 },
  { 0x0b2a10, CODE_FOR_lceildfsi2 },
  { 0x0b2a11, CODE_FOR_lceildfdi2 },
  { 0x0b2b0f, CODE_FOR_lceilxfhi2 },
  { 0x0b2b10, CODE_FOR_lceilxfsi2 },
  { 0x0b2b11, CODE_FOR_lceilxfdi2 },
  { 0x10290f, CODE_FOR_fix_truncsfhi2 },
  { 0x102910, CODE_FOR_fix_truncsfsi2 },
  { 0x102911, CODE_FOR_fix_truncsfdi2 },
  { 0x102a0f, CODE_FOR_fix_truncdfhi2 },
  { 0x102a10, CODE_FOR_fix_truncdfsi2 },
  { 0x102a11, CODE_FOR_fix_truncdfdi2 },
  { 0x102b0f, CODE_FOR_fix_truncxfhi2 },
  { 0x102b10, CODE_FOR_fix_truncxfsi2 },
  { 0x102b11, CODE_FOR_fix_truncxfdi2 },
  { 0x105a49, CODE_FOR_fix_truncv2sfv2di2 },
  { 0x105b48, CODE_FOR_fix_truncv4sfv4si2 },
  { 0x105b4e, CODE_FOR_fix_truncv4sfv4di2 },
  { 0x105c49, CODE_FOR_fix_truncv2dfv2di2 },
  { 0x105d4d, CODE_FOR_fix_truncv8sfv8si2 },
  { 0x105d53, CODE_FOR_fix_truncv8sfv8di2 },
  { 0x105e48, CODE_FOR_fix_truncv4dfv4si2 },
  { 0x105e4e, CODE_FOR_fix_truncv4dfv4di2 },
  { 0x106052, CODE_FOR_fix_truncv16sfv16si2 },
  { 0x10614d, CODE_FOR_fix_truncv8dfv8si2 },
  { 0x106153, CODE_FOR_fix_truncv8dfv8di2 },
  { 0x11290f, CODE_FOR_fixuns_truncsfhi2 },
  { 0x112910, CODE_FOR_fixuns_truncsfsi2 },
  { 0x112a0f, CODE_FOR_fixuns_truncdfhi2 },
  { 0x112a10, CODE_FOR_fixuns_truncdfsi2 },
  { 0x115b48, CODE_FOR_fixuns_truncv4sfv4si2 },
  { 0x115d4d, CODE_FOR_fixuns_truncv8sfv8si2 },
  { 0x116052, CODE_FOR_fixuns_truncv16sfv16si2 },
  { 0x120e0f, CODE_FOR_mulqihi3 },
  { 0x121011, CODE_FOR_mulsidi3 },
  { 0x121112, CODE_FOR_mulditi3 },
  { 0x130e0f, CODE_FOR_umulqihi3 },
  { 0x131011, CODE_FOR_umulsidi3 },
  { 0x131112, CODE_FOR_umulditi3 },
  { 0x1f4646, CODE_FOR_vcondv16qiv16qi },
  { 0x1f4647, CODE_FOR_vcondv8hiv16qi },
  { 0x1f4648, CODE_FOR_vcondv4siv16qi },
  { 0x1f4649, CODE_FOR_vcondv2div16qi },
  { 0x1f465b, CODE_FOR_vcondv4sfv16qi },
  { 0x1f465c, CODE_FOR_vcondv2dfv16qi },
  { 0x1f4746, CODE_FOR_vcondv16qiv8hi },
  { 0x1f4747, CODE_FOR_vcondv8hiv8hi },
  { 0x1f4748, CODE_FOR_vcondv4siv8hi },
  { 0x1f4749, CODE_FOR_vcondv2div8hi },
  { 0x1f475b, CODE_FOR_vcondv4sfv8hi },
  { 0x1f475c, CODE_FOR_vcondv2dfv8hi },
  { 0x1f4846, CODE_FOR_vcondv16qiv4si },
  { 0x1f4847, CODE_FOR_vcondv8hiv4si },
  { 0x1f4848, CODE_FOR_vcondv4siv4si },
  { 0x1f4849, CODE_FOR_vcondv2div4si },
  { 0x1f485b, CODE_FOR_vcondv4sfv4si },
  { 0x1f485c, CODE_FOR_vcondv2dfv4si },
  { 0x1f4949, CODE_FOR_vcondv2div2di },
  { 0x1f495c, CODE_FOR_vcondv2dfv2di },
  { 0x1f4b4b, CODE_FOR_vcondv32qiv32qi },
  { 0x1f4b4c, CODE_FOR_vcondv16hiv32qi },
  { 0x1f4b4d, CODE_FOR_vcondv8siv32qi },
  { 0x1f4b4e, CODE_FOR_vcondv4div32qi },
  { 0x1f4b5d, CODE_FOR_vcondv8sfv32qi },
  { 0x1f4b5e, CODE_FOR_vcondv4dfv32qi },
  { 0x1f4c4b, CODE_FOR_vcondv32qiv16hi },
  { 0x1f4c4c, CODE_FOR_vcondv16hiv16hi },
  { 0x1f4c4d, CODE_FOR_vcondv8siv16hi },
  { 0x1f4c4e, CODE_FOR_vcondv4div16hi },
  { 0x1f4c5d, CODE_FOR_vcondv8sfv16hi },
  { 0x1f4c5e, CODE_FOR_vcondv4dfv16hi },
  { 0x1f4d4b, CODE_FOR_vcondv32qiv8si },
  { 0x1f4d4c, CODE_FOR_vcondv16hiv8si },
  { 0x1f4d4d, CODE_FOR_vcondv8siv8si },
  { 0x1f4d4e, CODE_FOR_vcondv4div8si },
  { 0x1f4d5d, CODE_FOR_vcondv8sfv8si },
  { 0x1f4d5e, CODE_FOR_vcondv4dfv8si },
  { 0x1f4e4b, CODE_FOR_vcondv32qiv4di },
  { 0x1f4e4c, CODE_FOR_vcondv16hiv4di },
  { 0x1f4e4d, CODE_FOR_vcondv8siv4di },
  { 0x1f4e4e, CODE_FOR_vcondv4div4di },
  { 0x1f4e5d, CODE_FOR_vcondv8sfv4di },
  { 0x1f4e5e, CODE_FOR_vcondv4dfv4di },
  { 0x1f5050, CODE_FOR_vcondv64qiv64qi },
  { 0x1f5051, CODE_FOR_vcondv32hiv64qi },
  { 0x1f5052, CODE_FOR_vcondv16siv64qi },
  { 0x1f5053, CODE_FOR_vcondv8div64qi },
  { 0x1f5060, CODE_FOR_vcondv16sfv64qi },
  { 0x1f5061, CODE_FOR_vcondv8dfv64qi },
  { 0x1f5150, CODE_FOR_vcondv64qiv32hi },
  { 0x1f5151, CODE_FOR_vcondv32hiv32hi },
  { 0x1f5152, CODE_FOR_vcondv16siv32hi },
  { 0x1f5153, CODE_FOR_vcondv8div32hi },
  { 0x1f5160, CODE_FOR_vcondv16sfv32hi },
  { 0x1f5161, CODE_FOR_vcondv8dfv32hi },
  { 0x1f5250, CODE_FOR_vcondv64qiv16si },
  { 0x1f5251, CODE_FOR_vcondv32hiv16si },
  { 0x1f5252, CODE_FOR_vcondv16siv16si },
  { 0x1f5253, CODE_FOR_vcondv8div16si },
  { 0x1f5260, CODE_FOR_vcondv16sfv16si },
  { 0x1f5261, CODE_FOR_vcondv8dfv16si },
  { 0x1f5350, CODE_FOR_vcondv64qiv8di },
  { 0x1f5351, CODE_FOR_vcondv32hiv8di },
  { 0x1f5352, CODE_FOR_vcondv16siv8di },
  { 0x1f5353, CODE_FOR_vcondv8div8di },
  { 0x1f5360, CODE_FOR_vcondv16sfv8di },
  { 0x1f5361, CODE_FOR_vcondv8dfv8di },
  { 0x1f5b46, CODE_FOR_vcondv16qiv4sf },
  { 0x1f5b47, CODE_FOR_vcondv8hiv4sf },
  { 0x1f5b48, CODE_FOR_vcondv4siv4sf },
  { 0x1f5b49, CODE_FOR_vcondv2div4sf },
  { 0x1f5b5b, CODE_FOR_vcondv4sfv4sf },
  { 0x1f5b5c, CODE_FOR_vcondv2dfv4sf },
  { 0x1f5c46, CODE_FOR_vcondv16qiv2df },
  { 0x1f5c47, CODE_FOR_vcondv8hiv2df },
  { 0x1f5c48, CODE_FOR_vcondv4siv2df },
  { 0x1f5c49, CODE_FOR_vcondv2div2df },
  { 0x1f5c5b, CODE_FOR_vcondv4sfv2df },
  { 0x1f5c5c, CODE_FOR_vcondv2dfv2df },
  { 0x1f5d4b, CODE_FOR_vcondv32qiv8sf },
  { 0x1f5d4c, CODE_FOR_vcondv16hiv8sf },
  { 0x1f5d4d, CODE_FOR_vcondv8siv8sf },
  { 0x1f5d4e, CODE_FOR_vcondv4div8sf },
  { 0x1f5d5d, CODE_FOR_vcondv8sfv8sf },
  { 0x1f5d5e, CODE_FOR_vcondv4dfv8sf },
  { 0x1f5e4b, CODE_FOR_vcondv32qiv4df },
  { 0x1f5e4c, CODE_FOR_vcondv16hiv4df },
  { 0x1f5e4d, CODE_FOR_vcondv8siv4df },
  { 0x1f5e4e, CODE_FOR_vcondv4div4df },
  { 0x1f5e5d, CODE_FOR_vcondv8sfv4df },
  { 0x1f5e5e, CODE_FOR_vcondv4dfv4df },
  { 0x1f6050, CODE_FOR_vcondv64qiv16sf },
  { 0x1f6051, CODE_FOR_vcondv32hiv16sf },
  { 0x1f6052, CODE_FOR_vcondv16siv16sf },
  { 0x1f6053, CODE_FOR_vcondv8div16sf },
  { 0x1f6060, CODE_FOR_vcondv16sfv16sf },
  { 0x1f6061, CODE_FOR_vcondv8dfv16sf },
  { 0x1f6150, CODE_FOR_vcondv64qiv8df },
  { 0x1f6151, CODE_FOR_vcondv32hiv8df },
  { 0x1f6152, CODE_FOR_vcondv16siv8df },
  { 0x1f6153, CODE_FOR_vcondv8div8df },
  { 0x1f6160, CODE_FOR_vcondv16sfv8df },
  { 0x1f6161, CODE_FOR_vcondv8dfv8df },
  { 0x204646, CODE_FOR_vconduv16qiv16qi },
  { 0x204647, CODE_FOR_vconduv8hiv16qi },
  { 0x204648, CODE_FOR_vconduv4siv16qi },
  { 0x204649, CODE_FOR_vconduv2div16qi },
  { 0x20465b, CODE_FOR_vconduv4sfv16qi },
  { 0x20465c, CODE_FOR_vconduv2dfv16qi },
  { 0x204746, CODE_FOR_vconduv16qiv8hi },
  { 0x204747, CODE_FOR_vconduv8hiv8hi },
  { 0x204748, CODE_FOR_vconduv4siv8hi },
  { 0x204749, CODE_FOR_vconduv2div8hi },
  { 0x20475b, CODE_FOR_vconduv4sfv8hi },
  { 0x20475c, CODE_FOR_vconduv2dfv8hi },
  { 0x204846, CODE_FOR_vconduv16qiv4si },
  { 0x204847, CODE_FOR_vconduv8hiv4si },
  { 0x204848, CODE_FOR_vconduv4siv4si },
  { 0x204849, CODE_FOR_vconduv2div4si },
  { 0x20485b, CODE_FOR_vconduv4sfv4si },
  { 0x20485c, CODE_FOR_vconduv2dfv4si },
  { 0x204949, CODE_FOR_vconduv2div2di },
  { 0x20495c, CODE_FOR_vconduv2dfv2di },
  { 0x204b4b, CODE_FOR_vconduv32qiv32qi },
  { 0x204b4c, CODE_FOR_vconduv16hiv32qi },
  { 0x204b4d, CODE_FOR_vconduv8siv32qi },
  { 0x204b4e, CODE_FOR_vconduv4div32qi },
  { 0x204b5d, CODE_FOR_vconduv8sfv32qi },
  { 0x204b5e, CODE_FOR_vconduv4dfv32qi },
  { 0x204c4b, CODE_FOR_vconduv32qiv16hi },
  { 0x204c4c, CODE_FOR_vconduv16hiv16hi },
  { 0x204c4d, CODE_FOR_vconduv8siv16hi },
  { 0x204c4e, CODE_FOR_vconduv4div16hi },
  { 0x204c5d, CODE_FOR_vconduv8sfv16hi },
  { 0x204c5e, CODE_FOR_vconduv4dfv16hi },
  { 0x204d4b, CODE_FOR_vconduv32qiv8si },
  { 0x204d4c, CODE_FOR_vconduv16hiv8si },
  { 0x204d4d, CODE_FOR_vconduv8siv8si },
  { 0x204d4e, CODE_FOR_vconduv4div8si },
  { 0x204d5d, CODE_FOR_vconduv8sfv8si },
  { 0x204d5e, CODE_FOR_vconduv4dfv8si },
  { 0x204e4b, CODE_FOR_vconduv32qiv4di },
  { 0x204e4c, CODE_FOR_vconduv16hiv4di },
  { 0x204e4d, CODE_FOR_vconduv8siv4di },
  { 0x204e4e, CODE_FOR_vconduv4div4di },
  { 0x204e5d, CODE_FOR_vconduv8sfv4di },
  { 0x204e5e, CODE_FOR_vconduv4dfv4di },
  { 0x205050, CODE_FOR_vconduv64qiv64qi },
  { 0x205051, CODE_FOR_vconduv32hiv64qi },
  { 0x205052, CODE_FOR_vconduv16siv64qi },
  { 0x205053, CODE_FOR_vconduv8div64qi },
  { 0x205060, CODE_FOR_vconduv16sfv64qi },
  { 0x205061, CODE_FOR_vconduv8dfv64qi },
  { 0x205150, CODE_FOR_vconduv64qiv32hi },
  { 0x205151, CODE_FOR_vconduv32hiv32hi },
  { 0x205152, CODE_FOR_vconduv16siv32hi },
  { 0x205153, CODE_FOR_vconduv8div32hi },
  { 0x205160, CODE_FOR_vconduv16sfv32hi },
  { 0x205161, CODE_FOR_vconduv8dfv32hi },
  { 0x205250, CODE_FOR_vconduv64qiv16si },
  { 0x205251, CODE_FOR_vconduv32hiv16si },
  { 0x205252, CODE_FOR_vconduv16siv16si },
  { 0x205253, CODE_FOR_vconduv8div16si },
  { 0x205260, CODE_FOR_vconduv16sfv16si },
  { 0x205261, CODE_FOR_vconduv8dfv16si },
  { 0x205350, CODE_FOR_vconduv64qiv8di },
  { 0x205351, CODE_FOR_vconduv32hiv8di },
  { 0x205352, CODE_FOR_vconduv16siv8di },
  { 0x205353, CODE_FOR_vconduv8div8di },
  { 0x205360, CODE_FOR_vconduv16sfv8di },
  { 0x205361, CODE_FOR_vconduv8dfv8di },
  { 0x21000e, CODE_FOR_addqi3 },
  { 0x21000f, CODE_FOR_addhi3 },
  { 0x210010, CODE_FOR_addsi3 },
  { 0x210011, CODE_FOR_adddi3 },
  { 0x210012, CODE_FOR_addti3 },
  { 0x210029, CODE_FOR_addsf3 },
  { 0x21002a, CODE_FOR_adddf3 },
  { 0x21002b, CODE_FOR_addxf3 },
  { 0x210046, CODE_FOR_addv16qi3 },
  { 0x210047, CODE_FOR_addv8hi3 },
  { 0x210048, CODE_FOR_addv4si3 },
  { 0x210049, CODE_FOR_addv2di3 },
  { 0x21004b, CODE_FOR_addv32qi3 },
  { 0x21004c, CODE_FOR_addv16hi3 },
  { 0x21004d, CODE_FOR_addv8si3 },
  { 0x21004e, CODE_FOR_addv4di3 },
  { 0x210050, CODE_FOR_addv64qi3 },
  { 0x210051, CODE_FOR_addv32hi3 },
  { 0x210052, CODE_FOR_addv16si3 },
  { 0x210053, CODE_FOR_addv8di3 },
  { 0x21005b, CODE_FOR_addv4sf3 },
  { 0x21005c, CODE_FOR_addv2df3 },
  { 0x21005d, CODE_FOR_addv8sf3 },
  { 0x21005e, CODE_FOR_addv4df3 },
  { 0x210060, CODE_FOR_addv16sf3 },
  { 0x210061, CODE_FOR_addv8df3 },
  { 0x25000e, CODE_FOR_subqi3 },
  { 0x25000f, CODE_FOR_subhi3 },
  { 0x250010, CODE_FOR_subsi3 },
  { 0x250011, CODE_FOR_subdi3 },
  { 0x250012, CODE_FOR_subti3 },
  { 0x250029, CODE_FOR_subsf3 },
  { 0x25002a, CODE_FOR_subdf3 },
  { 0x25002b, CODE_FOR_subxf3 },
  { 0x250046, CODE_FOR_subv16qi3 },
  { 0x250047, CODE_FOR_subv8hi3 },
  { 0x250048, CODE_FOR_subv4si3 },
  { 0x250049, CODE_FOR_subv2di3 },
  { 0x25004b, CODE_FOR_subv32qi3 },
  { 0x25004c, CODE_FOR_subv16hi3 },
  { 0x25004d, CODE_FOR_subv8si3 },
  { 0x25004e, CODE_FOR_subv4di3 },
  { 0x250050, CODE_FOR_subv64qi3 },
  { 0x250051, CODE_FOR_subv32hi3 },
  { 0x250052, CODE_FOR_subv16si3 },
  { 0x250053, CODE_FOR_subv8di3 },
  { 0x25005b, CODE_FOR_subv4sf3 },
  { 0x25005c, CODE_FOR_subv2df3 },
  { 0x25005d, CODE_FOR_subv8sf3 },
  { 0x25005e, CODE_FOR_subv4df3 },
  { 0x250060, CODE_FOR_subv16sf3 },
  { 0x250061, CODE_FOR_subv8df3 },
  { 0x29000e, CODE_FOR_mulqi3 },
  { 0x29000f, CODE_FOR_mulhi3 },
  { 0x290010, CODE_FOR_mulsi3 },
  { 0x290011, CODE_FOR_muldi3 },
  { 0x290029, CODE_FOR_mulsf3 },
  { 0x29002a, CODE_FOR_muldf3 },
  { 0x29002b, CODE_FOR_mulxf3 },
  { 0x290046, CODE_FOR_mulv16qi3 },
  { 0x290047, CODE_FOR_mulv8hi3 },
  { 0x290048, CODE_FOR_mulv4si3 },
  { 0x290049, CODE_FOR_mulv2di3 },
  { 0x29004b, CODE_FOR_mulv32qi3 },
  { 0x29004c, CODE_FOR_mulv16hi3 },
  { 0x29004d, CODE_FOR_mulv8si3 },
  { 0x29004e, CODE_FOR_mulv4di3 },
  { 0x290050, CODE_FOR_mulv64qi3 },
  { 0x290051, CODE_FOR_mulv32hi3 },
  { 0x290052, CODE_FOR_mulv16si3 },
  { 0x290053, CODE_FOR_mulv8di3 },
  { 0x29005b, CODE_FOR_mulv4sf3 },
  { 0x29005c, CODE_FOR_mulv2df3 },
  { 0x29005d, CODE_FOR_mulv8sf3 },
  { 0x29005e, CODE_FOR_mulv4df3 },
  { 0x290060, CODE_FOR_mulv16sf3 },
  { 0x290061, CODE_FOR_mulv8df3 },
  { 0x2d0029, CODE_FOR_divsf3 },
  { 0x2d002a, CODE_FOR_divdf3 },
  { 0x2d002b, CODE_FOR_divxf3 },
  { 0x2d005b, CODE_FOR_divv4sf3 },
  { 0x2d005c, CODE_FOR_divv2df3 },
  { 0x2d005d, CODE_FOR_divv8sf3 },
  { 0x2d005e, CODE_FOR_divv4df3 },
  { 0x2d0060, CODE_FOR_divv16sf3 },
  { 0x2d0061, CODE_FOR_divv8df3 },
  { 0x32000e, CODE_FOR_divmodqi4 },
  { 0x32000f, CODE_FOR_divmodhi4 },
  { 0x320010, CODE_FOR_divmodsi4 },
  { 0x320011, CODE_FOR_divmoddi4 },
  { 0x33000e, CODE_FOR_udivmodqi4 },
  { 0x33000f, CODE_FOR_udivmodhi4 },
  { 0x330010, CODE_FOR_udivmodsi4 },
  { 0x330011, CODE_FOR_udivmoddi4 },
  { 0x37000e, CODE_FOR_andqi3 },
  { 0x37000f, CODE_FOR_andhi3 },
  { 0x370010, CODE_FOR_andsi3 },
  { 0x370011, CODE_FOR_anddi3 },
  { 0x37002c, CODE_FOR_andtf3 },
  { 0x370046, CODE_FOR_andv16qi3 },
  { 0x370047, CODE_FOR_andv8hi3 },
  { 0x370048, CODE_FOR_andv4si3 },
  { 0x370049, CODE_FOR_andv2di3 },
  { 0x37004b, CODE_FOR_andv32qi3 },
  { 0x37004c, CODE_FOR_andv16hi3 },
  { 0x37004d, CODE_FOR_andv8si3 },
  { 0x37004e, CODE_FOR_andv4di3 },
  { 0x370050, CODE_FOR_andv64qi3 },
  { 0x370051, CODE_FOR_andv32hi3 },
  { 0x370052, CODE_FOR_andv16si3 },
  { 0x370053, CODE_FOR_andv8di3 },
  { 0x37005b, CODE_FOR_andv4sf3 },
  { 0x37005c, CODE_FOR_andv2df3 },
  { 0x37005d, CODE_FOR_andv8sf3 },
  { 0x37005e, CODE_FOR_andv4df3 },
  { 0x370060, CODE_FOR_andv16sf3 },
  { 0x370061, CODE_FOR_andv8df3 },
  { 0x38000e, CODE_FOR_iorqi3 },
  { 0x38000f, CODE_FOR_iorhi3 },
  { 0x380010, CODE_FOR_iorsi3 },
  { 0x380011, CODE_FOR_iordi3 },
  { 0x38002c, CODE_FOR_iortf3 },
  { 0x380046, CODE_FOR_iorv16qi3 },
  { 0x380047, CODE_FOR_iorv8hi3 },
  { 0x380048, CODE_FOR_iorv4si3 },
  { 0x380049, CODE_FOR_iorv2di3 },
  { 0x38004b, CODE_FOR_iorv32qi3 },
  { 0x38004c, CODE_FOR_iorv16hi3 },
  { 0x38004d, CODE_FOR_iorv8si3 },
  { 0x38004e, CODE_FOR_iorv4di3 },
  { 0x380050, CODE_FOR_iorv64qi3 },
  { 0x380051, CODE_FOR_iorv32hi3 },
  { 0x380052, CODE_FOR_iorv16si3 },
  { 0x380053, CODE_FOR_iorv8di3 },
  { 0x38005b, CODE_FOR_iorv4sf3 },
  { 0x38005c, CODE_FOR_iorv2df3 },
  { 0x38005d, CODE_FOR_iorv8sf3 },
  { 0x38005e, CODE_FOR_iorv4df3 },
  { 0x380060, CODE_FOR_iorv16sf3 },
  { 0x380061, CODE_FOR_iorv8df3 },
  { 0x39000e, CODE_FOR_xorqi3 },
  { 0x39000f, CODE_FOR_xorhi3 },
  { 0x390010, CODE_FOR_xorsi3 },
  { 0x390011, CODE_FOR_xordi3 },
  { 0x39002c, CODE_FOR_xortf3 },
  { 0x390046, CODE_FOR_xorv16qi3 },
  { 0x390047, CODE_FOR_xorv8hi3 },
  { 0x390048, CODE_FOR_xorv4si3 },
  { 0x390049, CODE_FOR_xorv2di3 },
  { 0x39004b, CODE_FOR_xorv32qi3 },
  { 0x39004c, CODE_FOR_xorv16hi3 },
  { 0x39004d, CODE_FOR_xorv8si3 },
  { 0x39004e, CODE_FOR_xorv4di3 },
  { 0x390050, CODE_FOR_xorv64qi3 },
  { 0x390051, CODE_FOR_xorv32hi3 },
  { 0x390052, CODE_FOR_xorv16si3 },
  { 0x390053, CODE_FOR_xorv8di3 },
  { 0x39005b, CODE_FOR_xorv4sf3 },
  { 0x39005c, CODE_FOR_xorv2df3 },
  { 0x39005d, CODE_FOR_xorv8sf3 },
  { 0x39005e, CODE_FOR_xorv4df3 },
  { 0x390060, CODE_FOR_xorv16sf3 },
  { 0x390061, CODE_FOR_xorv8df3 },
  { 0x3a000e, CODE_FOR_ashlqi3 },
  { 0x3a000f, CODE_FOR_ashlhi3 },
  { 0x3a0010, CODE_FOR_ashlsi3 },
  { 0x3a0011, CODE_FOR_ashldi3 },
  { 0x3a0012, CODE_FOR_ashlti3 },
  { 0x3a0046, CODE_FOR_ashlv16qi3 },
  { 0x3a0047, CODE_FOR_ashlv8hi3 },
  { 0x3a0048, CODE_FOR_ashlv4si3 },
  { 0x3a0049, CODE_FOR_ashlv2di3 },
  { 0x3a004b, CODE_FOR_ashlv32qi3 },
  { 0x3a004c, CODE_FOR_ashlv16hi3 },
  { 0x3a004d, CODE_FOR_ashlv8si3 },
  { 0x3a004e, CODE_FOR_ashlv4di3 },
  { 0x3a0050, CODE_FOR_ashlv64qi3 },
  { 0x3a0051, CODE_FOR_ashlv32hi3 },
  { 0x3a0052, CODE_FOR_ashlv16si3 },
  { 0x3a0053, CODE_FOR_ashlv8di3 },
  { 0x3d000e, CODE_FOR_ashrqi3 },
  { 0x3d000f, CODE_FOR_ashrhi3 },
  { 0x3d0010, CODE_FOR_ashrsi3 },
  { 0x3d0011, CODE_FOR_ashrdi3 },
  { 0x3d0012, CODE_FOR_ashrti3 },
  { 0x3d0046, CODE_FOR_ashrv16qi3 },
  { 0x3d0047, CODE_FOR_ashrv8hi3 },
  { 0x3d0048, CODE_FOR_ashrv4si3 },
  { 0x3d0049, CODE_FOR_ashrv2di3 },
  { 0x3d004b, CODE_FOR_ashrv32qi3 },
  { 0x3d004c, CODE_FOR_ashrv16hi3 },
  { 0x3d004d, CODE_FOR_ashrv8si3 },
  { 0x3d004e, CODE_FOR_ashrv4di3 },
  { 0x3d0050, CODE_FOR_ashrv64qi3 },
  { 0x3d0051, CODE_FOR_ashrv32hi3 },
  { 0x3d0052, CODE_FOR_ashrv16si3 },
  { 0x3d0053, CODE_FOR_ashrv8di3 },
  { 0x3e000e, CODE_FOR_lshrqi3 },
  { 0x3e000f, CODE_FOR_lshrhi3 },
  { 0x3e0010, CODE_FOR_lshrsi3 },
  { 0x3e0011, CODE_FOR_lshrdi3 },
  { 0x3e0012, CODE_FOR_lshrti3 },
  { 0x3e0046, CODE_FOR_lshrv16qi3 },
  { 0x3e0047, CODE_FOR_lshrv8hi3 },
  { 0x3e0048, CODE_FOR_lshrv4si3 },
  { 0x3e0049, CODE_FOR_lshrv2di3 },
  { 0x3e004b, CODE_FOR_lshrv32qi3 },
  { 0x3e004c, CODE_FOR_lshrv16hi3 },
  { 0x3e004d, CODE_FOR_lshrv8si3 },
  { 0x3e004e, CODE_FOR_lshrv4di3 },
  { 0x3e0050, CODE_FOR_lshrv64qi3 },
  { 0x3e0051, CODE_FOR_lshrv32hi3 },
  { 0x3e0052, CODE_FOR_lshrv16si3 },
  { 0x3e0053, CODE_FOR_lshrv8di3 },
  { 0x3f000e, CODE_FOR_rotlqi3 },
  { 0x3f000f, CODE_FOR_rotlhi3 },
  { 0x3f0010, CODE_FOR_rotlsi3 },
  { 0x3f0011, CODE_FOR_rotldi3 },
  { 0x3f0012, CODE_FOR_rotlti3 },
  { 0x3f0046, CODE_FOR_rotlv16qi3 },
  { 0x3f0047, CODE_FOR_rotlv8hi3 },
  { 0x3f0048, CODE_FOR_rotlv4si3 },
  { 0x3f0049, CODE_FOR_rotlv2di3 },
  { 0x40000e, CODE_FOR_rotrqi3 },
  { 0x40000f, CODE_FOR_rotrhi3 },
  { 0x400010, CODE_FOR_rotrsi3 },
  { 0x400011, CODE_FOR_rotrdi3 },
  { 0x400012, CODE_FOR_rotrti3 },
  { 0x400046, CODE_FOR_rotrv16qi3 },
  { 0x400047, CODE_FOR_rotrv8hi3 },
  { 0x400048, CODE_FOR_rotrv4si3 },
  { 0x400049, CODE_FOR_rotrv2di3 },
  { 0x410046, CODE_FOR_vashlv16qi3 },
  { 0x410047, CODE_FOR_vashlv8hi3 },
  { 0x410048, CODE_FOR_vashlv4si3 },
  { 0x410049, CODE_FOR_vashlv2di3 },
  { 0x41004d, CODE_FOR_vashlv8si3 },
  { 0x41004e, CODE_FOR_vashlv4di3 },
  { 0x410052, CODE_FOR_vashlv16si3 },
  { 0x410053, CODE_FOR_vashlv8di3 },
  { 0x420046, CODE_FOR_vashrv16qi3 },
  { 0x420047, CODE_FOR_vashrv8hi3 },
  { 0x420048, CODE_FOR_vashrv4si3 },
  { 0x420049, CODE_FOR_vashrv2di3 },
  { 0x42004d, CODE_FOR_vashrv8si3 },
  { 0x420052, CODE_FOR_vashrv16si3 },
  { 0x430046, CODE_FOR_vlshrv16qi3 },
  { 0x430047, CODE_FOR_vlshrv8hi3 },
  { 0x430048, CODE_FOR_vlshrv4si3 },
  { 0x430049, CODE_FOR_vlshrv2di3 },
  { 0x43004d, CODE_FOR_vlshrv8si3 },
  { 0x43004e, CODE_FOR_vlshrv4di3 },
  { 0x430052, CODE_FOR_vlshrv16si3 },
  { 0x430053, CODE_FOR_vlshrv8di3 },
  { 0x440046, CODE_FOR_vrotlv16qi3 },
  { 0x440047, CODE_FOR_vrotlv8hi3 },
  { 0x440048, CODE_FOR_vrotlv4si3 },
  { 0x440049, CODE_FOR_vrotlv2di3 },
  { 0x450046, CODE_FOR_vrotrv16qi3 },
  { 0x450047, CODE_FOR_vrotrv8hi3 },
  { 0x450048, CODE_FOR_vrotrv4si3 },
  { 0x450049, CODE_FOR_vrotrv2di3 },
  { 0x460029, CODE_FOR_sminsf3 },
  { 0x46002a, CODE_FOR_smindf3 },
  { 0x460046, CODE_FOR_sminv16qi3 },
  { 0x460047, CODE_FOR_sminv8hi3 },
  { 0x460048, CODE_FOR_sminv4si3 },
  { 0x460049, CODE_FOR_sminv2di3 },
  { 0x46004b, CODE_FOR_sminv32qi3 },
  { 0x46004c, CODE_FOR_sminv16hi3 },
  { 0x46004d, CODE_FOR_sminv8si3 },
  { 0x46004e, CODE_FOR_sminv4di3 },
  { 0x460050, CODE_FOR_sminv64qi3 },
  { 0x460051, CODE_FOR_sminv32hi3 },
  { 0x460052, CODE_FOR_sminv16si3 },
  { 0x460053, CODE_FOR_sminv8di3 },
  { 0x46005b, CODE_FOR_sminv4sf3 },
  { 0x46005c, CODE_FOR_sminv2df3 },
  { 0x46005d, CODE_FOR_sminv8sf3 },
  { 0x46005e, CODE_FOR_sminv4df3 },
  { 0x460060, CODE_FOR_sminv16sf3 },
  { 0x460061, CODE_FOR_sminv8df3 },
  { 0x470029, CODE_FOR_smaxsf3 },
  { 0x47002a, CODE_FOR_smaxdf3 },
  { 0x470046, CODE_FOR_smaxv16qi3 },
  { 0x470047, CODE_FOR_smaxv8hi3 },
  { 0x470048, CODE_FOR_smaxv4si3 },
  { 0x470049, CODE_FOR_smaxv2di3 },
  { 0x47004b, CODE_FOR_smaxv32qi3 },
  { 0x47004c, CODE_FOR_smaxv16hi3 },
  { 0x47004d, CODE_FOR_smaxv8si3 },
  { 0x47004e, CODE_FOR_smaxv4di3 },
  { 0x470050, CODE_FOR_smaxv64qi3 },
  { 0x470051, CODE_FOR_smaxv32hi3 },
  { 0x470052, CODE_FOR_smaxv16si3 },
  { 0x470053, CODE_FOR_smaxv8di3 },
  { 0x47005b, CODE_FOR_smaxv4sf3 },
  { 0x47005c, CODE_FOR_smaxv2df3 },
  { 0x47005d, CODE_FOR_smaxv8sf3 },
  { 0x47005e, CODE_FOR_smaxv4df3 },
  { 0x470060, CODE_FOR_smaxv16sf3 },
  { 0x470061, CODE_FOR_smaxv8df3 },
  { 0x480046, CODE_FOR_uminv16qi3 },
  { 0x480047, CODE_FOR_uminv8hi3 },
  { 0x480048, CODE_FOR_uminv4si3 },
  { 0x480049, CODE_FOR_uminv2di3 },
  { 0x48004b, CODE_FOR_uminv32qi3 },
  { 0x48004c, CODE_FOR_uminv16hi3 },
  { 0x48004d, CODE_FOR_uminv8si3 },
  { 0x48004e, CODE_FOR_uminv4di3 },
  { 0x480050, CODE_FOR_uminv64qi3 },
  { 0x480051, CODE_FOR_uminv32hi3 },
  { 0x480052, CODE_FOR_uminv16si3 },
  { 0x480053, CODE_FOR_uminv8di3 },
  { 0x490046, CODE_FOR_umaxv16qi3 },
  { 0x490047, CODE_FOR_umaxv8hi3 },
  { 0x490048, CODE_FOR_umaxv4si3 },
  { 0x490049, CODE_FOR_umaxv2di3 },
  { 0x49004b, CODE_FOR_umaxv32qi3 },
  { 0x49004c, CODE_FOR_umaxv16hi3 },
  { 0x49004d, CODE_FOR_umaxv8si3 },
  { 0x49004e, CODE_FOR_umaxv4di3 },
  { 0x490050, CODE_FOR_umaxv64qi3 },
  { 0x490051, CODE_FOR_umaxv32hi3 },
  { 0x490052, CODE_FOR_umaxv16si3 },
  { 0x490053, CODE_FOR_umaxv8di3 },
  { 0x4a000e, CODE_FOR_negqi2 },
  { 0x4a000f, CODE_FOR_neghi2 },
  { 0x4a0010, CODE_FOR_negsi2 },
  { 0x4a0011, CODE_FOR_negdi2 },
  { 0x4a0012, CODE_FOR_negti2 },
  { 0x4a0029, CODE_FOR_negsf2 },
  { 0x4a002a, CODE_FOR_negdf2 },
  { 0x4a002b, CODE_FOR_negxf2 },
  { 0x4a002c, CODE_FOR_negtf2 },
  { 0x4a0046, CODE_FOR_negv16qi2 },
  { 0x4a0047, CODE_FOR_negv8hi2 },
  { 0x4a0048, CODE_FOR_negv4si2 },
  { 0x4a0049, CODE_FOR_negv2di2 },
  { 0x4a004b, CODE_FOR_negv32qi2 },
  { 0x4a004c, CODE_FOR_negv16hi2 },
  { 0x4a004d, CODE_FOR_negv8si2 },
  { 0x4a004e, CODE_FOR_negv4di2 },
  { 0x4a0050, CODE_FOR_negv64qi2 },
  { 0x4a0051, CODE_FOR_negv32hi2 },
  { 0x4a0052, CODE_FOR_negv16si2 },
  { 0x4a0053, CODE_FOR_negv8di2 },
  { 0x4a005b, CODE_FOR_negv4sf2 },
  { 0x4a005c, CODE_FOR_negv2df2 },
  { 0x4a005d, CODE_FOR_negv8sf2 },
  { 0x4a005e, CODE_FOR_negv4df2 },
  { 0x4a0060, CODE_FOR_negv16sf2 },
  { 0x4a0061, CODE_FOR_negv8df2 },
  { 0x4e0029, CODE_FOR_abssf2 },
  { 0x4e002a, CODE_FOR_absdf2 },
  { 0x4e002b, CODE_FOR_absxf2 },
  { 0x4e002c, CODE_FOR_abstf2 },
  { 0x4e003f, CODE_FOR_absv8qi2 },
  { 0x4e0040, CODE_FOR_absv4hi2 },
  { 0x4e0041, CODE_FOR_absv2si2 },
  { 0x4e0046, CODE_FOR_absv16qi2 },
  { 0x4e0047, CODE_FOR_absv8hi2 },
  { 0x4e0048, CODE_FOR_absv4si2 },
  { 0x4e0049, CODE_FOR_absv2di2 },
  { 0x4e004b, CODE_FOR_absv32qi2 },
  { 0x4e004c, CODE_FOR_absv16hi2 },
  { 0x4e004d, CODE_FOR_absv8si2 },
  { 0x4e004e, CODE_FOR_absv4di2 },
  { 0x4e0050, CODE_FOR_absv64qi2 },
  { 0x4e0051, CODE_FOR_absv32hi2 },
  { 0x4e0052, CODE_FOR_absv16si2 },
  { 0x4e0053, CODE_FOR_absv8di2 },
  { 0x4e005b, CODE_FOR_absv4sf2 },
  { 0x4e005c, CODE_FOR_absv2df2 },
  { 0x4e005d, CODE_FOR_absv8sf2 },
  { 0x4e005e, CODE_FOR_absv4df2 },
  { 0x4e0060, CODE_FOR_absv16sf2 },
  { 0x4e0061, CODE_FOR_absv8df2 },
  { 0x50000e, CODE_FOR_one_cmplqi2 },
  { 0x50000f, CODE_FOR_one_cmplhi2 },
  { 0x500010, CODE_FOR_one_cmplsi2 },
  { 0x500011, CODE_FOR_one_cmpldi2 },
  { 0x500046, CODE_FOR_one_cmplv16qi2 },
  { 0x500047, CODE_FOR_one_cmplv8hi2 },
  { 0x500048, CODE_FOR_one_cmplv4si2 },
  { 0x500049, CODE_FOR_one_cmplv2di2 },
  { 0x50004b, CODE_FOR_one_cmplv32qi2 },
  { 0x50004c, CODE_FOR_one_cmplv16hi2 },
  { 0x50004d, CODE_FOR_one_cmplv8si2 },
  { 0x50004e, CODE_FOR_one_cmplv4di2 },
  { 0x500050, CODE_FOR_one_cmplv64qi2 },
  { 0x500051, CODE_FOR_one_cmplv32hi2 },
  { 0x500052, CODE_FOR_one_cmplv16si2 },
  { 0x500053, CODE_FOR_one_cmplv8di2 },
  { 0x510010, CODE_FOR_bswapsi2 },
  { 0x510011, CODE_FOR_bswapdi2 },
  { 0x520010, CODE_FOR_ffssi2 },
  { 0x520011, CODE_FOR_ffsdi2 },
  { 0x53000f, CODE_FOR_clzhi2 },
  { 0x530010, CODE_FOR_clzsi2 },
  { 0x530011, CODE_FOR_clzdi2 },
  { 0x530048, CODE_FOR_clzv4si2 },
  { 0x530049, CODE_FOR_clzv2di2 },
  { 0x53004d, CODE_FOR_clzv8si2 },
  { 0x53004e, CODE_FOR_clzv4di2 },
  { 0x530052, CODE_FOR_clzv16si2 },
  { 0x530053, CODE_FOR_clzv8di2 },
  { 0x54000f, CODE_FOR_ctzhi2 },
  { 0x540010, CODE_FOR_ctzsi2 },
  { 0x540011, CODE_FOR_ctzdi2 },
  { 0x56000f, CODE_FOR_popcounthi2 },
  { 0x560010, CODE_FOR_popcountsi2 },
  { 0x560011, CODE_FOR_popcountdi2 },
  { 0x570010, CODE_FOR_paritysi2 },
  { 0x570011, CODE_FOR_paritydi2 },
  { 0x620029, CODE_FOR_sqrtsf2 },
  { 0x62002a, CODE_FOR_sqrtdf2 },
  { 0x62002b, CODE_FOR_sqrtxf2 },
  { 0x62005b, CODE_FOR_sqrtv4sf2 },
  { 0x62005c, CODE_FOR_sqrtv2df2 },
  { 0x62005d, CODE_FOR_sqrtv8sf2 },
  { 0x62005e, CODE_FOR_sqrtv4df2 },
  { 0x620060, CODE_FOR_sqrtv16sf2 },
  { 0x620061, CODE_FOR_sqrtv8df2 },
  { 0x71000e, CODE_FOR_movqi },
  { 0x71000f, CODE_FOR_movhi },
  { 0x710010, CODE_FOR_movsi },
  { 0x710011, CODE_FOR_movdi },
  { 0x710012, CODE_FOR_movti },
  { 0x710013, CODE_FOR_movoi },
  { 0x710014, CODE_FOR_movxi },
  { 0x710015, CODE_FOR_movbnd32 },
  { 0x710016, CODE_FOR_movbnd64 },
  { 0x710029, CODE_FOR_movsf },
  { 0x71002a, CODE_FOR_movdf },
  { 0x71002b, CODE_FOR_movxf },
  { 0x71002c, CODE_FOR_movtf },
  { 0x710033, CODE_FOR_movcdi },
  { 0x71003f, CODE_FOR_movv8qi },
  { 0x710040, CODE_FOR_movv4hi },
  { 0x710041, CODE_FOR_movv2si },
  { 0x710042, CODE_FOR_movv1di },
  { 0x710046, CODE_FOR_movv16qi },
  { 0x710047, CODE_FOR_movv8hi },
  { 0x710048, CODE_FOR_movv4si },
  { 0x710049, CODE_FOR_movv2di },
  { 0x71004a, CODE_FOR_movv1ti },
  { 0x71004b, CODE_FOR_movv32qi },
  { 0x71004c, CODE_FOR_movv16hi },
  { 0x71004d, CODE_FOR_movv8si },
  { 0x71004e, CODE_FOR_movv4di },
  { 0x71004f, CODE_FOR_movv2ti },
  { 0x710050, CODE_FOR_movv64qi },
  { 0x710051, CODE_FOR_movv32hi },
  { 0x710052, CODE_FOR_movv16si },
  { 0x710053, CODE_FOR_movv8di },
  { 0x710054, CODE_FOR_movv4ti },
  { 0x71005a, CODE_FOR_movv2sf },
  { 0x71005b, CODE_FOR_movv4sf },
  { 0x71005c, CODE_FOR_movv2df },
  { 0x71005d, CODE_FOR_movv8sf },
  { 0x71005e, CODE_FOR_movv4df },
  { 0x710060, CODE_FOR_movv16sf },
  { 0x710061, CODE_FOR_movv8df },
  { 0x72000e, CODE_FOR_movstrictqi },
  { 0x72000f, CODE_FOR_movstricthi },
  { 0x73003f, CODE_FOR_movmisalignv8qi },
  { 0x730040, CODE_FOR_movmisalignv4hi },
  { 0x730041, CODE_FOR_movmisalignv2si },
  { 0x730042, CODE_FOR_movmisalignv1di },
  { 0x730046, CODE_FOR_movmisalignv16qi },
  { 0x730047, CODE_FOR_movmisalignv8hi },
  { 0x730048, CODE_FOR_movmisalignv4si },
  { 0x730049, CODE_FOR_movmisalignv2di },
  { 0x73004a, CODE_FOR_movmisalignv1ti },
  { 0x73004b, CODE_FOR_movmisalignv32qi },
  { 0x73004c, CODE_FOR_movmisalignv16hi },
  { 0x73004d, CODE_FOR_movmisalignv8si },
  { 0x73004e, CODE_FOR_movmisalignv4di },
  { 0x73004f, CODE_FOR_movmisalignv2ti },
  { 0x730050, CODE_FOR_movmisalignv64qi },
  { 0x730051, CODE_FOR_movmisalignv32hi },
  { 0x730052, CODE_FOR_movmisalignv16si },
  { 0x730053, CODE_FOR_movmisalignv8di },
  { 0x730054, CODE_FOR_movmisalignv4ti },
  { 0x73005a, CODE_FOR_movmisalignv2sf },
  { 0x73005b, CODE_FOR_movmisalignv4sf },
  { 0x73005c, CODE_FOR_movmisalignv2df },
  { 0x73005d, CODE_FOR_movmisalignv8sf },
  { 0x73005e, CODE_FOR_movmisalignv4df },
  { 0x730060, CODE_FOR_movmisalignv16sf },
  { 0x730061, CODE_FOR_movmisalignv8df },
  { 0x740010, CODE_FOR_storentsi },
  { 0x740011, CODE_FOR_storentdi },
  { 0x740029, CODE_FOR_storentsf },
  { 0x74002a, CODE_FOR_storentdf },
  { 0x740049, CODE_FOR_storentv2di },
  { 0x74004e, CODE_FOR_storentv4di },
  { 0x740053, CODE_FOR_storentv8di },
  { 0x74005b, CODE_FOR_storentv4sf },
  { 0x74005c, CODE_FOR_storentv2df },
  { 0x74005d, CODE_FOR_storentv8sf },
  { 0x74005e, CODE_FOR_storentv4df },
  { 0x740060, CODE_FOR_storentv16sf },
  { 0x740061, CODE_FOR_storentv8df },
  { 0x7e0002, CODE_FOR_cbranchcc4 },
  { 0x7e000e, CODE_FOR_cbranchqi4 },
  { 0x7e000f, CODE_FOR_cbranchhi4 },
  { 0x7e0010, CODE_FOR_cbranchsi4 },
  { 0x7e0011, CODE_FOR_cbranchdi4 },
  { 0x7e0012, CODE_FOR_cbranchti4 },
  { 0x7e0029, CODE_FOR_cbranchsf4 },
  { 0x7e002a, CODE_FOR_cbranchdf4 },
  { 0x7e002b, CODE_FOR_cbranchxf4 },
  { 0x7f000e, CODE_FOR_addqicc },
  { 0x7f000f, CODE_FOR_addhicc },
  { 0x7f0010, CODE_FOR_addsicc },
  { 0x7f0011, CODE_FOR_adddicc },
  { 0x80000e, CODE_FOR_movqicc },
  { 0x80000f, CODE_FOR_movhicc },
  { 0x800010, CODE_FOR_movsicc },
  { 0x800011, CODE_FOR_movdicc },
  { 0x800029, CODE_FOR_movsfcc },
  { 0x80002a, CODE_FOR_movdfcc },
  { 0x80002b, CODE_FOR_movxfcc },
  { 0x820002, CODE_FOR_cstorecc4 },
  { 0x82000e, CODE_FOR_cstoreqi4 },
  { 0x82000f, CODE_FOR_cstorehi4 },
  { 0x820010, CODE_FOR_cstoresi4 },
  { 0x820011, CODE_FOR_cstoredi4 },
  { 0x820029, CODE_FOR_cstoresf4 },
  { 0x82002a, CODE_FOR_cstoredf4 },
  { 0x82002b, CODE_FOR_cstorexf4 },
  { 0x84000e, CODE_FOR_addvqi4 },
  { 0x84000f, CODE_FOR_addvhi4 },
  { 0x840010, CODE_FOR_addvsi4 },
  { 0x840011, CODE_FOR_addvdi4 },
  { 0x85000e, CODE_FOR_subvqi4 },
  { 0x85000f, CODE_FOR_subvhi4 },
  { 0x850010, CODE_FOR_subvsi4 },
  { 0x850011, CODE_FOR_subvdi4 },
  { 0x86000e, CODE_FOR_mulvqi4 },
  { 0x860010, CODE_FOR_mulvsi4 },
  { 0x860011, CODE_FOR_mulvdi4 },
  { 0x87000e, CODE_FOR_umulvqi4 },
  { 0x870010, CODE_FOR_umulvsi4 },
  { 0x870011, CODE_FOR_umulvdi4 },
  { 0x88000e, CODE_FOR_negvqi3 },
  { 0x88000f, CODE_FOR_negvhi3 },
  { 0x880010, CODE_FOR_negvsi3 },
  { 0x880011, CODE_FOR_negvdi3 },
  { 0x8a0010, CODE_FOR_smulsi3_highpart },
  { 0x8a0011, CODE_FOR_smuldi3_highpart },
  { 0x8a0047, CODE_FOR_smulv8hi3_highpart },
  { 0x8a004c, CODE_FOR_smulv16hi3_highpart },
  { 0x8a0051, CODE_FOR_smulv32hi3_highpart },
  { 0x8b0010, CODE_FOR_umulsi3_highpart },
  { 0x8b0011, CODE_FOR_umuldi3_highpart },
  { 0x8b0047, CODE_FOR_umulv8hi3_highpart },
  { 0x8b004c, CODE_FOR_umulv16hi3_highpart },
  { 0x8b0051, CODE_FOR_umulv32hi3_highpart },
  { 0x8e0010, CODE_FOR_cmpstrnsi },
  { 0x8f0010, CODE_FOR_movmemsi },
  { 0x8f0011, CODE_FOR_movmemdi },
  { 0x900010, CODE_FOR_setmemsi },
  { 0x900011, CODE_FOR_setmemdi },
  { 0x910010, CODE_FOR_strlensi },
  { 0x910011, CODE_FOR_strlendi },
  { 0x920029, CODE_FOR_fmasf4 },
  { 0x92002a, CODE_FOR_fmadf4 },
  { 0x92005b, CODE_FOR_fmav4sf4 },
  { 0x92005c, CODE_FOR_fmav2df4 },
  { 0x92005d, CODE_FOR_fmav8sf4 },
  { 0x92005e, CODE_FOR_fmav4df4 },
  { 0x920060, CODE_FOR_fmav16sf4 },
  { 0x920061, CODE_FOR_fmav8df4 },
  { 0x930029, CODE_FOR_fmssf4 },
  { 0x93002a, CODE_FOR_fmsdf4 },
  { 0x93005b, CODE_FOR_fmsv4sf4 },
  { 0x93005c, CODE_FOR_fmsv2df4 },
  { 0x93005d, CODE_FOR_fmsv8sf4 },
  { 0x93005e, CODE_FOR_fmsv4df4 },
  { 0x930060, CODE_FOR_fmsv16sf4 },
  { 0x930061, CODE_FOR_fmsv8df4 },
  { 0x940029, CODE_FOR_fnmasf4 },
  { 0x94002a, CODE_FOR_fnmadf4 },
  { 0x94005b, CODE_FOR_fnmav4sf4 },
  { 0x94005c, CODE_FOR_fnmav2df4 },
  { 0x94005d, CODE_FOR_fnmav8sf4 },
  { 0x94005e, CODE_FOR_fnmav4df4 },
  { 0x940060, CODE_FOR_fnmav16sf4 },
  { 0x940061, CODE_FOR_fnmav8df4 },
  { 0x950029, CODE_FOR_fnmssf4 },
  { 0x95002a, CODE_FOR_fnmsdf4 },
  { 0x95005b, CODE_FOR_fnmsv4sf4 },
  { 0x95005c, CODE_FOR_fnmsv2df4 },
  { 0x95005d, CODE_FOR_fnmsv8sf4 },
  { 0x95005e, CODE_FOR_fnmsv4df4 },
  { 0x950060, CODE_FOR_fnmsv16sf4 },
  { 0x950061, CODE_FOR_fnmsv8df4 },
  { 0x960029, CODE_FOR_rintsf2 },
  { 0x96002a, CODE_FOR_rintdf2 },
  { 0x96002b, CODE_FOR_rintxf2 },
  { 0x970029, CODE_FOR_roundsf2 },
  { 0x97002a, CODE_FOR_rounddf2 },
  { 0x97002b, CODE_FOR_roundxf2 },
  { 0x97005b, CODE_FOR_roundv4sf2 },
  { 0x97005c, CODE_FOR_roundv2df2 },
  { 0x97005d, CODE_FOR_roundv8sf2 },
  { 0x97005e, CODE_FOR_roundv4df2 },
  { 0x970060, CODE_FOR_roundv16sf2 },
  { 0x970061, CODE_FOR_roundv8df2 },
  { 0x980029, CODE_FOR_floorsf2 },
  { 0x98002a, CODE_FOR_floordf2 },
  { 0x98002b, CODE_FOR_floorxf2 },
  { 0x990029, CODE_FOR_ceilsf2 },
  { 0x99002a, CODE_FOR_ceildf2 },
  { 0x99002b, CODE_FOR_ceilxf2 },
  { 0x9a0029, CODE_FOR_btruncsf2 },
  { 0x9a002a, CODE_FOR_btruncdf2 },
  { 0x9a002b, CODE_FOR_btruncxf2 },
  { 0x9b0029, CODE_FOR_nearbyintsf2 },
  { 0x9b002a, CODE_FOR_nearbyintdf2 },
  { 0x9b002b, CODE_FOR_nearbyintxf2 },
  { 0x9c0029, CODE_FOR_acossf2 },
  { 0x9c002a, CODE_FOR_acosdf2 },
  { 0x9c002b, CODE_FOR_acosxf2 },
  { 0x9d0029, CODE_FOR_asinsf2 },
  { 0x9d002a, CODE_FOR_asindf2 },
  { 0x9d002b, CODE_FOR_asinxf2 },
  { 0x9e0029, CODE_FOR_atan2sf3 },
  { 0x9e002a, CODE_FOR_atan2df3 },
  { 0x9e002b, CODE_FOR_atan2xf3 },
  { 0x9f0029, CODE_FOR_atansf2 },
  { 0x9f002a, CODE_FOR_atandf2 },
  { 0x9f002b, CODE_FOR_atanxf2 },
  { 0xa00029, CODE_FOR_copysignsf3 },
  { 0xa0002a, CODE_FOR_copysigndf3 },
  { 0xa0002c, CODE_FOR_copysigntf3 },
  { 0xa0005b, CODE_FOR_copysignv4sf3 },
  { 0xa0005c, CODE_FOR_copysignv2df3 },
  { 0xa0005d, CODE_FOR_copysignv8sf3 },
  { 0xa0005e, CODE_FOR_copysignv4df3 },
  { 0xa00060, CODE_FOR_copysignv16sf3 },
  { 0xa00061, CODE_FOR_copysignv8df3 },
  { 0xa20029, CODE_FOR_exp10sf2 },
  { 0xa2002a, CODE_FOR_exp10df2 },
  { 0xa2002b, CODE_FOR_exp10xf2 },
  { 0xa30029, CODE_FOR_exp2sf2 },
  { 0xa3002a, CODE_FOR_exp2df2 },
  { 0xa3002b, CODE_FOR_exp2xf2 },
  { 0xa40029, CODE_FOR_expsf2 },
  { 0xa4002a, CODE_FOR_expdf2 },
  { 0xa4002b, CODE_FOR_expxf2 },
  { 0xa50029, CODE_FOR_expm1sf2 },
  { 0xa5002a, CODE_FOR_expm1df2 },
  { 0xa5002b, CODE_FOR_expm1xf2 },
  { 0xa60029, CODE_FOR_fmodsf3 },
  { 0xa6002a, CODE_FOR_fmoddf3 },
  { 0xa6002b, CODE_FOR_fmodxf3 },
  { 0xa70029, CODE_FOR_ilogbsf2 },
  { 0xa7002a, CODE_FOR_ilogbdf2 },
  { 0xa7002b, CODE_FOR_ilogbxf2 },
  { 0xa80029, CODE_FOR_isinfsf2 },
  { 0xa8002a, CODE_FOR_isinfdf2 },
  { 0xa8002b, CODE_FOR_isinfxf2 },
  { 0xa90029, CODE_FOR_ldexpsf3 },
  { 0xa9002a, CODE_FOR_ldexpdf3 },
  { 0xa9002b, CODE_FOR_ldexpxf3 },
  { 0xaa0029, CODE_FOR_log10sf2 },
  { 0xaa002a, CODE_FOR_log10df2 },
  { 0xaa002b, CODE_FOR_log10xf2 },
  { 0xab0029, CODE_FOR_log1psf2 },
  { 0xab002a, CODE_FOR_log1pdf2 },
  { 0xab002b, CODE_FOR_log1pxf2 },
  { 0xac0029, CODE_FOR_log2sf2 },
  { 0xac002a, CODE_FOR_log2df2 },
  { 0xac002b, CODE_FOR_log2xf2 },
  { 0xad0029, CODE_FOR_logsf2 },
  { 0xad002a, CODE_FOR_logdf2 },
  { 0xad002b, CODE_FOR_logxf2 },
  { 0xae0029, CODE_FOR_logbsf2 },
  { 0xae002a, CODE_FOR_logbdf2 },
  { 0xae002b, CODE_FOR_logbxf2 },
  { 0xb00029, CODE_FOR_remaindersf3 },
  { 0xb0002a, CODE_FOR_remainderdf3 },
  { 0xb0002b, CODE_FOR_remainderxf3 },
  { 0xb10029, CODE_FOR_scalbsf3 },
  { 0xb1002a, CODE_FOR_scalbdf3 },
  { 0xb1002b, CODE_FOR_scalbxf3 },
  { 0xb20029, CODE_FOR_signbitsf2 },
  { 0xb2002a, CODE_FOR_signbitdf2 },
  { 0xb2002b, CODE_FOR_signbitxf2 },
  { 0xb30029, CODE_FOR_significandsf2 },
  { 0xb3002a, CODE_FOR_significanddf2 },
  { 0xb3002b, CODE_FOR_significandxf2 },
  { 0xb50029, CODE_FOR_sincossf3 },
  { 0xb5002a, CODE_FOR_sincosdf3 },
  { 0xb5002b, CODE_FOR_sincosxf3 },
  { 0xb60029, CODE_FOR_tansf2 },
  { 0xb6002a, CODE_FOR_tandf2 },
  { 0xb6002b, CODE_FOR_tanxf2 },
  { 0xbc004b, CODE_FOR_reduc_smax_v32qi },
  { 0xbc004c, CODE_FOR_reduc_smax_v16hi },
  { 0xbc004d, CODE_FOR_reduc_smax_v8si },
  { 0xbc004e, CODE_FOR_reduc_smax_v4di },
  { 0xbc0050, CODE_FOR_reduc_smax_v64qi },
  { 0xbc0051, CODE_FOR_reduc_smax_v32hi },
  { 0xbc0052, CODE_FOR_reduc_smax_v16si },
  { 0xbc0053, CODE_FOR_reduc_smax_v8di },
  { 0xbc005b, CODE_FOR_reduc_smax_v4sf },
  { 0xbc005d, CODE_FOR_reduc_smax_v8sf },
  { 0xbc005e, CODE_FOR_reduc_smax_v4df },
  { 0xbc0060, CODE_FOR_reduc_smax_v16sf },
  { 0xbc0061, CODE_FOR_reduc_smax_v8df },
  { 0xbd004b, CODE_FOR_reduc_smin_v32qi },
  { 0xbd004c, CODE_FOR_reduc_smin_v16hi },
  { 0xbd004d, CODE_FOR_reduc_smin_v8si },
  { 0xbd004e, CODE_FOR_reduc_smin_v4di },
  { 0xbd0050, CODE_FOR_reduc_smin_v64qi },
  { 0xbd0051, CODE_FOR_reduc_smin_v32hi },
  { 0xbd0052, CODE_FOR_reduc_smin_v16si },
  { 0xbd0053, CODE_FOR_reduc_smin_v8di },
  { 0xbd005b, CODE_FOR_reduc_smin_v4sf },
  { 0xbd005d, CODE_FOR_reduc_smin_v8sf },
  { 0xbd005e, CODE_FOR_reduc_smin_v4df },
  { 0xbd0060, CODE_FOR_reduc_smin_v16sf },
  { 0xbd0061, CODE_FOR_reduc_smin_v8df },
  { 0xbe005b, CODE_FOR_reduc_splus_v4sf },
  { 0xbe005c, CODE_FOR_reduc_splus_v2df },
  { 0xbe005d, CODE_FOR_reduc_splus_v8sf },
  { 0xbe005e, CODE_FOR_reduc_splus_v4df },
  { 0xbe0060, CODE_FOR_reduc_splus_v16sf },
  { 0xbe0061, CODE_FOR_reduc_splus_v8df },
  { 0xbf004b, CODE_FOR_reduc_umax_v32qi },
  { 0xbf004c, CODE_FOR_reduc_umax_v16hi },
  { 0xbf004d, CODE_FOR_reduc_umax_v8si },
  { 0xbf004e, CODE_FOR_reduc_umax_v4di },
  { 0xbf0050, CODE_FOR_reduc_umax_v64qi },
  { 0xbf0051, CODE_FOR_reduc_umax_v32hi },
  { 0xbf0052, CODE_FOR_reduc_umax_v16si },
  { 0xbf0053, CODE_FOR_reduc_umax_v8di },
  { 0xc00047, CODE_FOR_reduc_umin_v8hi },
  { 0xc0004b, CODE_FOR_reduc_umin_v32qi },
  { 0xc0004c, CODE_FOR_reduc_umin_v16hi },
  { 0xc0004d, CODE_FOR_reduc_umin_v8si },
  { 0xc0004e, CODE_FOR_reduc_umin_v4di },
  { 0xc00050, CODE_FOR_reduc_umin_v64qi },
  { 0xc00051, CODE_FOR_reduc_umin_v32hi },
  { 0xc00052, CODE_FOR_reduc_umin_v16si },
  { 0xc00053, CODE_FOR_reduc_umin_v8di },
  { 0xc20047, CODE_FOR_sdot_prodv8hi },
  { 0xc20048, CODE_FOR_sdot_prodv4si },
  { 0xc2004c, CODE_FOR_sdot_prodv16hi },
  { 0xc20051, CODE_FOR_sdot_prodv32hi },
  { 0xc60046, CODE_FOR_usadv16qi },
  { 0xc6004b, CODE_FOR_usadv32qi },
  { 0xc80048, CODE_FOR_maskloadv4si },
  { 0xc80049, CODE_FOR_maskloadv2di },
  { 0xc8004d, CODE_FOR_maskloadv8si },
  { 0xc8004e, CODE_FOR_maskloadv4di },
  { 0xc8005b, CODE_FOR_maskloadv4sf },
  { 0xc8005c, CODE_FOR_maskloadv2df },
  { 0xc8005d, CODE_FOR_maskloadv8sf },
  { 0xc8005e, CODE_FOR_maskloadv4df },
  { 0xc90048, CODE_FOR_maskstorev4si },
  { 0xc90049, CODE_FOR_maskstorev2di },
  { 0xc9004d, CODE_FOR_maskstorev8si },
  { 0xc9004e, CODE_FOR_maskstorev4di },
  { 0xc9005b, CODE_FOR_maskstorev4sf },
  { 0xc9005c, CODE_FOR_maskstorev2df },
  { 0xc9005d, CODE_FOR_maskstorev8sf },
  { 0xc9005e, CODE_FOR_maskstorev4df },
  { 0xca003f, CODE_FOR_vec_extractv8qi },
  { 0xca0040, CODE_FOR_vec_extractv4hi },
  { 0xca0041, CODE_FOR_vec_extractv2si },
  { 0xca0046, CODE_FOR_vec_extractv16qi },
  { 0xca0047, CODE_FOR_vec_extractv8hi },
  { 0xca0048, CODE_FOR_vec_extractv4si },
  { 0xca0049, CODE_FOR_vec_extractv2di },
  { 0xca004b, CODE_FOR_vec_extractv32qi },
  { 0xca004c, CODE_FOR_vec_extractv16hi },
  { 0xca004d, CODE_FOR_vec_extractv8si },
  { 0xca004e, CODE_FOR_vec_extractv4di },
  { 0xca0050, CODE_FOR_vec_extractv64qi },
  { 0xca0051, CODE_FOR_vec_extractv32hi },
  { 0xca0052, CODE_FOR_vec_extractv16si },
  { 0xca0053, CODE_FOR_vec_extractv8di },
  { 0xca005a, CODE_FOR_vec_extractv2sf },
  { 0xca005b, CODE_FOR_vec_extractv4sf },
  { 0xca005c, CODE_FOR_vec_extractv2df },
  { 0xca005d, CODE_FOR_vec_extractv8sf },
  { 0xca005e, CODE_FOR_vec_extractv4df },
  { 0xca0060, CODE_FOR_vec_extractv16sf },
  { 0xca0061, CODE_FOR_vec_extractv8df },
  { 0xcb003f, CODE_FOR_vec_initv8qi },
  { 0xcb0040, CODE_FOR_vec_initv4hi },
  { 0xcb0041, CODE_FOR_vec_initv2si },
  { 0xcb0046, CODE_FOR_vec_initv16qi },
  { 0xcb0047, CODE_FOR_vec_initv8hi },
  { 0xcb0048, CODE_FOR_vec_initv4si },
  { 0xcb0049, CODE_FOR_vec_initv2di },
  { 0xcb004b, CODE_FOR_vec_initv32qi },
  { 0xcb004c, CODE_FOR_vec_initv16hi },
  { 0xcb004d, CODE_FOR_vec_initv8si },
  { 0xcb004e, CODE_FOR_vec_initv4di },
  { 0xcb0050, CODE_FOR_vec_initv64qi },
  { 0xcb0051, CODE_FOR_vec_initv32hi },
  { 0xcb0052, CODE_FOR_vec_initv16si },
  { 0xcb0053, CODE_FOR_vec_initv8di },
  { 0xcb005a, CODE_FOR_vec_initv2sf },
  { 0xcb005b, CODE_FOR_vec_initv4sf },
  { 0xcb005c, CODE_FOR_vec_initv2df },
  { 0xcb005d, CODE_FOR_vec_initv8sf },
  { 0xcb005e, CODE_FOR_vec_initv4df },
  { 0xcb0060, CODE_FOR_vec_initv16sf },
  { 0xcb0061, CODE_FOR_vec_initv8df },
  { 0xcc005c, CODE_FOR_vec_pack_sfix_trunc_v2df },
  { 0xcc005e, CODE_FOR_vec_pack_sfix_trunc_v4df },
  { 0xcc0061, CODE_FOR_vec_pack_sfix_trunc_v8df },
  { 0xce0047, CODE_FOR_vec_pack_trunc_v8hi },
  { 0xce0048, CODE_FOR_vec_pack_trunc_v4si },
  { 0xce0049, CODE_FOR_vec_pack_trunc_v2di },
  { 0xce004c, CODE_FOR_vec_pack_trunc_v16hi },
  { 0xce004d, CODE_FOR_vec_pack_trunc_v8si },
  { 0xce004e, CODE_FOR_vec_pack_trunc_v4di },
  { 0xce0051, CODE_FOR_vec_pack_trunc_v32hi },
  { 0xce0052, CODE_FOR_vec_pack_trunc_v16si },
  { 0xce0053, CODE_FOR_vec_pack_trunc_v8di },
  { 0xce005c, CODE_FOR_vec_pack_trunc_v2df },
  { 0xce005e, CODE_FOR_vec_pack_trunc_v4df },
  { 0xce0061, CODE_FOR_vec_pack_trunc_v8df },
  { 0xcf005c, CODE_FOR_vec_pack_ufix_trunc_v2df },
  { 0xcf005e, CODE_FOR_vec_pack_ufix_trunc_v4df },
  { 0xcf0061, CODE_FOR_vec_pack_ufix_trunc_v8df },
  { 0xd10046, CODE_FOR_vec_perm_constv16qi },
  { 0xd10047, CODE_FOR_vec_perm_constv8hi },
  { 0xd10048, CODE_FOR_vec_perm_constv4si },
  { 0xd10049, CODE_FOR_vec_perm_constv2di },
  { 0xd1004b, CODE_FOR_vec_perm_constv32qi },
  { 0xd1004c, CODE_FOR_vec_perm_constv16hi },
  { 0xd1004d, CODE_FOR_vec_perm_constv8si },
  { 0xd1004e, CODE_FOR_vec_perm_constv4di },
  { 0xd10050, CODE_FOR_vec_perm_constv64qi },
  { 0xd10051, CODE_FOR_vec_perm_constv32hi },
  { 0xd10052, CODE_FOR_vec_perm_constv16si },
  { 0xd10053, CODE_FOR_vec_perm_constv8di },
  { 0xd1005b, CODE_FOR_vec_perm_constv4sf },
  { 0xd1005c, CODE_FOR_vec_perm_constv2df },
  { 0xd1005d, CODE_FOR_vec_perm_constv8sf },
  { 0xd1005e, CODE_FOR_vec_perm_constv4df },
  { 0xd10060, CODE_FOR_vec_perm_constv16sf },
  { 0xd10061, CODE_FOR_vec_perm_constv8df },
  { 0xd20046, CODE_FOR_vec_permv16qi },
  { 0xd20047, CODE_FOR_vec_permv8hi },
  { 0xd20048, CODE_FOR_vec_permv4si },
  { 0xd20049, CODE_FOR_vec_permv2di },
  { 0xd2004b, CODE_FOR_vec_permv32qi },
  { 0xd2004c, CODE_FOR_vec_permv16hi },
  { 0xd2004d, CODE_FOR_vec_permv8si },
  { 0xd2004e, CODE_FOR_vec_permv4di },
  { 0xd20050, CODE_FOR_vec_permv64qi },
  { 0xd20051, CODE_FOR_vec_permv32hi },
  { 0xd20052, CODE_FOR_vec_permv16si },
  { 0xd20053, CODE_FOR_vec_permv8di },
  { 0xd2005b, CODE_FOR_vec_permv4sf },
  { 0xd2005c, CODE_FOR_vec_permv2df },
  { 0xd2005d, CODE_FOR_vec_permv8sf },
  { 0xd2005e, CODE_FOR_vec_permv4df },
  { 0xd20060, CODE_FOR_vec_permv16sf },
  { 0xd20061, CODE_FOR_vec_permv8df },
  { 0xd4003f, CODE_FOR_vec_setv8qi },
  { 0xd40040, CODE_FOR_vec_setv4hi },
  { 0xd40041, CODE_FOR_vec_setv2si },
  { 0xd40046, CODE_FOR_vec_setv16qi },
  { 0xd40047, CODE_FOR_vec_setv8hi },
  { 0xd40048, CODE_FOR_vec_setv4si },
  { 0xd40049, CODE_FOR_vec_setv2di },
  { 0xd4004b, CODE_FOR_vec_setv32qi },
  { 0xd4004c, CODE_FOR_vec_setv16hi },
  { 0xd4004d, CODE_FOR_vec_setv8si },
  { 0xd4004e, CODE_FOR_vec_setv4di },
  { 0xd40052, CODE_FOR_vec_setv16si },
  { 0xd40053, CODE_FOR_vec_setv8di },
  { 0xd4005a, CODE_FOR_vec_setv2sf },
  { 0xd4005b, CODE_FOR_vec_setv4sf },
  { 0xd4005c, CODE_FOR_vec_setv2df },
  { 0xd4005d, CODE_FOR_vec_setv8sf },
  { 0xd4005e, CODE_FOR_vec_setv4df },
  { 0xd40060, CODE_FOR_vec_setv16sf },
  { 0xd40061, CODE_FOR_vec_setv8df },
  { 0xd50046, CODE_FOR_vec_shr_v16qi },
  { 0xd50047, CODE_FOR_vec_shr_v8hi },
  { 0xd50048, CODE_FOR_vec_shr_v4si },
  { 0xd50049, CODE_FOR_vec_shr_v2di },
  { 0xd60047, CODE_FOR_vec_unpacks_float_hi_v8hi },
  { 0xd60048, CODE_FOR_vec_unpacks_float_hi_v4si },
  { 0xd6004c, CODE_FOR_vec_unpacks_float_hi_v16hi },
  { 0xd6004d, CODE_FOR_vec_unpacks_float_hi_v8si },
  { 0xd60051, CODE_FOR_vec_unpacks_float_hi_v32hi },
  { 0xd60052, CODE_FOR_vec_unpacks_float_hi_v16si },
  { 0xd70047, CODE_FOR_vec_unpacks_float_lo_v8hi },
  { 0xd70048, CODE_FOR_vec_unpacks_float_lo_v4si },
  { 0xd7004c, CODE_FOR_vec_unpacks_float_lo_v16hi },
  { 0xd7004d, CODE_FOR_vec_unpacks_float_lo_v8si },
  { 0xd70051, CODE_FOR_vec_unpacks_float_lo_v32hi },
  { 0xd70052, CODE_FOR_vec_unpacks_float_lo_v16si },
  { 0xd80046, CODE_FOR_vec_unpacks_hi_v16qi },
  { 0xd80047, CODE_FOR_vec_unpacks_hi_v8hi },
  { 0xd80048, CODE_FOR_vec_unpacks_hi_v4si },
  { 0xd8004b, CODE_FOR_vec_unpacks_hi_v32qi },
  { 0xd8004c, CODE_FOR_vec_unpacks_hi_v16hi },
  { 0xd8004d, CODE_FOR_vec_unpacks_hi_v8si },
  { 0xd80050, CODE_FOR_vec_unpacks_hi_v64qi },
  { 0xd80051, CODE_FOR_vec_unpacks_hi_v32hi },
  { 0xd80052, CODE_FOR_vec_unpacks_hi_v16si },
  { 0xd8005b, CODE_FOR_vec_unpacks_hi_v4sf },
  { 0xd8005d, CODE_FOR_vec_unpacks_hi_v8sf },
  { 0xd80060, CODE_FOR_vec_unpacks_hi_v16sf },
  { 0xd90046, CODE_FOR_vec_unpacks_lo_v16qi },
  { 0xd90047, CODE_FOR_vec_unpacks_lo_v8hi },
  { 0xd90048, CODE_FOR_vec_unpacks_lo_v4si },
  { 0xd9004b, CODE_FOR_vec_unpacks_lo_v32qi },
  { 0xd9004c, CODE_FOR_vec_unpacks_lo_v16hi },
  { 0xd9004d, CODE_FOR_vec_unpacks_lo_v8si },
  { 0xd90050, CODE_FOR_vec_unpacks_lo_v64qi },
  { 0xd90051, CODE_FOR_vec_unpacks_lo_v32hi },
  { 0xd90052, CODE_FOR_vec_unpacks_lo_v16si },
  { 0xd9005b, CODE_FOR_vec_unpacks_lo_v4sf },
  { 0xd9005d, CODE_FOR_vec_unpacks_lo_v8sf },
  { 0xd90060, CODE_FOR_vec_unpacks_lo_v16sf },
  { 0xda0047, CODE_FOR_vec_unpacku_float_hi_v8hi },
  { 0xda0048, CODE_FOR_vec_unpacku_float_hi_v4si },
  { 0xda004c, CODE_FOR_vec_unpacku_float_hi_v16hi },
  { 0xda004d, CODE_FOR_vec_unpacku_float_hi_v8si },
  { 0xda0051, CODE_FOR_vec_unpacku_float_hi_v32hi },
  { 0xda0052, CODE_FOR_vec_unpacku_float_hi_v16si },
  { 0xdb0047, CODE_FOR_vec_unpacku_float_lo_v8hi },
  { 0xdb0048, CODE_FOR_vec_unpacku_float_lo_v4si },
  { 0xdb004c, CODE_FOR_vec_unpacku_float_lo_v16hi },
  { 0xdb004d, CODE_FOR_vec_unpacku_float_lo_v8si },
  { 0xdb0051, CODE_FOR_vec_unpacku_float_lo_v32hi },
  { 0xdb0052, CODE_FOR_vec_unpacku_float_lo_v16si },
  { 0xdc0046, CODE_FOR_vec_unpacku_hi_v16qi },
  { 0xdc0047, CODE_FOR_vec_unpacku_hi_v8hi },
  { 0xdc0048, CODE_FOR_vec_unpacku_hi_v4si },
  { 0xdc004b, CODE_FOR_vec_unpacku_hi_v32qi },
  { 0xdc004c, CODE_FOR_vec_unpacku_hi_v16hi },
  { 0xdc004d, CODE_FOR_vec_unpacku_hi_v8si },
  { 0xdc0050, CODE_FOR_vec_unpacku_hi_v64qi },
  { 0xdc0051, CODE_FOR_vec_unpacku_hi_v32hi },
  { 0xdc0052, CODE_FOR_vec_unpacku_hi_v16si },
  { 0xdd0046, CODE_FOR_vec_unpacku_lo_v16qi },
  { 0xdd0047, CODE_FOR_vec_unpacku_lo_v8hi },
  { 0xdd0048, CODE_FOR_vec_unpacku_lo_v4si },
  { 0xdd004b, CODE_FOR_vec_unpacku_lo_v32qi },
  { 0xdd004c, CODE_FOR_vec_unpacku_lo_v16hi },
  { 0xdd004d, CODE_FOR_vec_unpacku_lo_v8si },
  { 0xdd0050, CODE_FOR_vec_unpacku_lo_v64qi },
  { 0xdd0051, CODE_FOR_vec_unpacku_lo_v32hi },
  { 0xdd0052, CODE_FOR_vec_unpacku_lo_v16si },
  { 0xde0048, CODE_FOR_vec_widen_smult_even_v4si },
  { 0xde004d, CODE_FOR_vec_widen_smult_even_v8si },
  { 0xde0052, CODE_FOR_vec_widen_smult_even_v16si },
  { 0xdf0046, CODE_FOR_vec_widen_smult_hi_v16qi },
  { 0xdf0047, CODE_FOR_vec_widen_smult_hi_v8hi },
  { 0xdf0048, CODE_FOR_vec_widen_smult_hi_v4si },
  { 0xdf004b, CODE_FOR_vec_widen_smult_hi_v32qi },
  { 0xdf004c, CODE_FOR_vec_widen_smult_hi_v16hi },
  { 0xdf004d, CODE_FOR_vec_widen_smult_hi_v8si },
  { 0xe00046, CODE_FOR_vec_widen_smult_lo_v16qi },
  { 0xe00047, CODE_FOR_vec_widen_smult_lo_v8hi },
  { 0xe00048, CODE_FOR_vec_widen_smult_lo_v4si },
  { 0xe0004b, CODE_FOR_vec_widen_smult_lo_v32qi },
  { 0xe0004c, CODE_FOR_vec_widen_smult_lo_v16hi },
  { 0xe0004d, CODE_FOR_vec_widen_smult_lo_v8si },
  { 0xe10048, CODE_FOR_vec_widen_smult_odd_v4si },
  { 0xe1004d, CODE_FOR_vec_widen_smult_odd_v8si },
  { 0xe10052, CODE_FOR_vec_widen_smult_odd_v16si },
  { 0xe40048, CODE_FOR_vec_widen_umult_even_v4si },
  { 0xe4004d, CODE_FOR_vec_widen_umult_even_v8si },
  { 0xe40052, CODE_FOR_vec_widen_umult_even_v16si },
  { 0xe50046, CODE_FOR_vec_widen_umult_hi_v16qi },
  { 0xe50047, CODE_FOR_vec_widen_umult_hi_v8hi },
  { 0xe50048, CODE_FOR_vec_widen_umult_hi_v4si },
  { 0xe5004b, CODE_FOR_vec_widen_umult_hi_v32qi },
  { 0xe5004c, CODE_FOR_vec_widen_umult_hi_v16hi },
  { 0xe5004d, CODE_FOR_vec_widen_umult_hi_v8si },
  { 0xe60046, CODE_FOR_vec_widen_umult_lo_v16qi },
  { 0xe60047, CODE_FOR_vec_widen_umult_lo_v8hi },
  { 0xe60048, CODE_FOR_vec_widen_umult_lo_v4si },
  { 0xe6004b, CODE_FOR_vec_widen_umult_lo_v32qi },
  { 0xe6004c, CODE_FOR_vec_widen_umult_lo_v16hi },
  { 0xe6004d, CODE_FOR_vec_widen_umult_lo_v8si },
  { 0xe70048, CODE_FOR_vec_widen_umult_odd_v4si },
  { 0xe7004d, CODE_FOR_vec_widen_umult_odd_v8si },
  { 0xe70052, CODE_FOR_vec_widen_umult_odd_v16si },
  { 0xf2000e, CODE_FOR_atomic_addqi },
  { 0xf2000f, CODE_FOR_atomic_addhi },
  { 0xf20010, CODE_FOR_atomic_addsi },
  { 0xf20011, CODE_FOR_atomic_adddi },
  { 0xf4000e, CODE_FOR_atomic_andqi },
  { 0xf4000f, CODE_FOR_atomic_andhi },
  { 0xf40010, CODE_FOR_atomic_andsi },
  { 0xf40011, CODE_FOR_atomic_anddi },
  { 0xf5000e, CODE_FOR_atomic_compare_and_swapqi },
  { 0xf5000f, CODE_FOR_atomic_compare_and_swaphi },
  { 0xf50010, CODE_FOR_atomic_compare_and_swapsi },
  { 0xf50011, CODE_FOR_atomic_compare_and_swapdi },
  { 0xf50012, CODE_FOR_atomic_compare_and_swapti },
  { 0xf6000e, CODE_FOR_atomic_exchangeqi },
  { 0xf6000f, CODE_FOR_atomic_exchangehi },
  { 0xf60010, CODE_FOR_atomic_exchangesi },
  { 0xf60011, CODE_FOR_atomic_exchangedi },
  { 0xf7000e, CODE_FOR_atomic_fetch_addqi },
  { 0xf7000f, CODE_FOR_atomic_fetch_addhi },
  { 0xf70010, CODE_FOR_atomic_fetch_addsi },
  { 0xf70011, CODE_FOR_atomic_fetch_adddi },
  { 0xfd000e, CODE_FOR_atomic_loadqi },
  { 0xfd000f, CODE_FOR_atomic_loadhi },
  { 0xfd0010, CODE_FOR_atomic_loadsi },
  { 0xfd0011, CODE_FOR_atomic_loaddi },
  { 0x101000e, CODE_FOR_atomic_orqi },
  { 0x101000f, CODE_FOR_atomic_orhi },
  { 0x1010010, CODE_FOR_atomic_orsi },
  { 0x1010011, CODE_FOR_atomic_ordi },
  { 0x102000e, CODE_FOR_atomic_storeqi },
  { 0x102000f, CODE_FOR_atomic_storehi },
  { 0x1020010, CODE_FOR_atomic_storesi },
  { 0x1020011, CODE_FOR_atomic_storedi },
  { 0x104000e, CODE_FOR_atomic_subqi },
  { 0x104000f, CODE_FOR_atomic_subhi },
  { 0x1040010, CODE_FOR_atomic_subsi },
  { 0x1040011, CODE_FOR_atomic_subdi },
  { 0x106000e, CODE_FOR_atomic_xorqi },
  { 0x106000f, CODE_FOR_atomic_xorhi },
  { 0x1060010, CODE_FOR_atomic_xorsi },
  { 0x1060011, CODE_FOR_atomic_xordi },
};

void
init_all_optabs (struct target_optabs *optabs)
{
  bool *ena = optabs->pat_enable;
  ena[0] = HAVE_extendqihi2;
  ena[1] = HAVE_extendqisi2;
  ena[2] = HAVE_extendqidi2;
  ena[3] = HAVE_extendhisi2;
  ena[4] = HAVE_extendhidi2;
  ena[5] = HAVE_extendsidi2;
  ena[6] = HAVE_extendsfdf2;
  ena[7] = HAVE_extendsfxf2;
  ena[8] = HAVE_extenddfxf2;
  ena[9] = HAVE_truncdfsf2;
  ena[10] = HAVE_truncxfsf2;
  ena[11] = HAVE_truncxfdf2;
  ena[12] = HAVE_zero_extendqihi2;
  ena[13] = HAVE_zero_extendqisi2;
  ena[14] = HAVE_zero_extendqidi2;
  ena[15] = HAVE_zero_extendhisi2;
  ena[16] = HAVE_zero_extendhidi2;
  ena[17] = HAVE_zero_extendsidi2;
  ena[18] = HAVE_floathisf2;
  ena[19] = HAVE_floathidf2;
  ena[20] = HAVE_floathixf2;
  ena[21] = HAVE_floatsisf2;
  ena[22] = HAVE_floatsidf2;
  ena[23] = HAVE_floatsixf2;
  ena[24] = HAVE_floatdisf2;
  ena[25] = HAVE_floatdidf2;
  ena[26] = HAVE_floatdixf2;
  ena[27] = HAVE_floatv4siv4sf2;
  ena[28] = HAVE_floatv4siv4df2;
  ena[29] = HAVE_floatv2div2df2;
  ena[30] = HAVE_floatv8siv8sf2;
  ena[31] = HAVE_floatv8siv8df2;
  ena[32] = HAVE_floatv4div4sf2;
  ena[33] = HAVE_floatv4div4df2;
  ena[34] = HAVE_floatv16siv16sf2;
  ena[35] = HAVE_floatv8div8sf2;
  ena[36] = HAVE_floatv8div8df2;
  ena[37] = HAVE_floatunsqisf2;
  ena[38] = HAVE_floatunsqidf2;
  ena[39] = HAVE_floatunshisf2;
  ena[40] = HAVE_floatunshidf2;
  ena[41] = HAVE_floatunssisf2;
  ena[42] = HAVE_floatunssidf2;
  ena[43] = HAVE_floatunssixf2;
  ena[44] = HAVE_floatunsdisf2;
  ena[45] = HAVE_floatunsdidf2;
  ena[46] = HAVE_floatunsv4siv4sf2;
  ena[47] = HAVE_floatunsv8siv8sf2;
  ena[48] = HAVE_floatunsv16siv16sf2;
  ena[49] = HAVE_lrintsfsi2;
  ena[50] = HAVE_lrintsfdi2;
  ena[51] = HAVE_lrintdfsi2;
  ena[52] = HAVE_lrintdfdi2;
  ena[53] = HAVE_lrintxfhi2;
  ena[54] = HAVE_lrintxfsi2;
  ena[55] = HAVE_lrintxfdi2;
  ena[56] = HAVE_lroundsfhi2;
  ena[57] = HAVE_lroundsfsi2;
  ena[58] = HAVE_lroundsfdi2;
  ena[59] = HAVE_lrounddfhi2;
  ena[60] = HAVE_lrounddfsi2;
  ena[61] = HAVE_lrounddfdi2;
  ena[62] = HAVE_lroundxfhi2;
  ena[63] = HAVE_lroundxfsi2;
  ena[64] = HAVE_lroundxfdi2;
  ena[65] = HAVE_lfloorsfsi2;
  ena[66] = HAVE_lfloorsfdi2;
  ena[67] = HAVE_lfloordfsi2;
  ena[68] = HAVE_lfloordfdi2;
  ena[69] = HAVE_lfloorxfhi2;
  ena[70] = HAVE_lfloorxfsi2;
  ena[71] = HAVE_lfloorxfdi2;
  ena[72] = HAVE_lceilsfsi2;
  ena[73] = HAVE_lceilsfdi2;
  ena[74] = HAVE_lceildfsi2;
  ena[75] = HAVE_lceildfdi2;
  ena[76] = HAVE_lceilxfhi2;
  ena[77] = HAVE_lceilxfsi2;
  ena[78] = HAVE_lceilxfdi2;
  ena[79] = HAVE_fix_truncsfhi2;
  ena[80] = HAVE_fix_truncsfsi2;
  ena[81] = HAVE_fix_truncsfdi2;
  ena[82] = HAVE_fix_truncdfhi2;
  ena[83] = HAVE_fix_truncdfsi2;
  ena[84] = HAVE_fix_truncdfdi2;
  ena[85] = HAVE_fix_truncxfhi2;
  ena[86] = HAVE_fix_truncxfsi2;
  ena[87] = HAVE_fix_truncxfdi2;
  ena[88] = HAVE_fix_truncv2sfv2di2;
  ena[89] = HAVE_fix_truncv4sfv4si2;
  ena[90] = HAVE_fix_truncv4sfv4di2;
  ena[91] = HAVE_fix_truncv2dfv2di2;
  ena[92] = HAVE_fix_truncv8sfv8si2;
  ena[93] = HAVE_fix_truncv8sfv8di2;
  ena[94] = HAVE_fix_truncv4dfv4si2;
  ena[95] = HAVE_fix_truncv4dfv4di2;
  ena[96] = HAVE_fix_truncv16sfv16si2;
  ena[97] = HAVE_fix_truncv8dfv8si2;
  ena[98] = HAVE_fix_truncv8dfv8di2;
  ena[99] = HAVE_fixuns_truncsfhi2;
  ena[100] = HAVE_fixuns_truncsfsi2;
  ena[101] = HAVE_fixuns_truncdfhi2;
  ena[102] = HAVE_fixuns_truncdfsi2;
  ena[103] = HAVE_fixuns_truncv4sfv4si2;
  ena[104] = HAVE_fixuns_truncv8sfv8si2;
  ena[105] = HAVE_fixuns_truncv16sfv16si2;
  ena[106] = HAVE_mulqihi3;
  ena[107] = HAVE_mulsidi3;
  ena[108] = HAVE_mulditi3;
  ena[109] = HAVE_umulqihi3;
  ena[110] = HAVE_umulsidi3;
  ena[111] = HAVE_umulditi3;
  ena[112] = HAVE_vcondv16qiv16qi;
  ena[113] = HAVE_vcondv8hiv16qi;
  ena[114] = HAVE_vcondv4siv16qi;
  ena[115] = HAVE_vcondv2div16qi;
  ena[116] = HAVE_vcondv4sfv16qi;
  ena[117] = HAVE_vcondv2dfv16qi;
  ena[118] = HAVE_vcondv16qiv8hi;
  ena[119] = HAVE_vcondv8hiv8hi;
  ena[120] = HAVE_vcondv4siv8hi;
  ena[121] = HAVE_vcondv2div8hi;
  ena[122] = HAVE_vcondv4sfv8hi;
  ena[123] = HAVE_vcondv2dfv8hi;
  ena[124] = HAVE_vcondv16qiv4si;
  ena[125] = HAVE_vcondv8hiv4si;
  ena[126] = HAVE_vcondv4siv4si;
  ena[127] = HAVE_vcondv2div4si;
  ena[128] = HAVE_vcondv4sfv4si;
  ena[129] = HAVE_vcondv2dfv4si;
  ena[130] = HAVE_vcondv2div2di;
  ena[131] = HAVE_vcondv2dfv2di;
  ena[132] = HAVE_vcondv32qiv32qi;
  ena[133] = HAVE_vcondv16hiv32qi;
  ena[134] = HAVE_vcondv8siv32qi;
  ena[135] = HAVE_vcondv4div32qi;
  ena[136] = HAVE_vcondv8sfv32qi;
  ena[137] = HAVE_vcondv4dfv32qi;
  ena[138] = HAVE_vcondv32qiv16hi;
  ena[139] = HAVE_vcondv16hiv16hi;
  ena[140] = HAVE_vcondv8siv16hi;
  ena[141] = HAVE_vcondv4div16hi;
  ena[142] = HAVE_vcondv8sfv16hi;
  ena[143] = HAVE_vcondv4dfv16hi;
  ena[144] = HAVE_vcondv32qiv8si;
  ena[145] = HAVE_vcondv16hiv8si;
  ena[146] = HAVE_vcondv8siv8si;
  ena[147] = HAVE_vcondv4div8si;
  ena[148] = HAVE_vcondv8sfv8si;
  ena[149] = HAVE_vcondv4dfv8si;
  ena[150] = HAVE_vcondv32qiv4di;
  ena[151] = HAVE_vcondv16hiv4di;
  ena[152] = HAVE_vcondv8siv4di;
  ena[153] = HAVE_vcondv4div4di;
  ena[154] = HAVE_vcondv8sfv4di;
  ena[155] = HAVE_vcondv4dfv4di;
  ena[156] = HAVE_vcondv64qiv64qi;
  ena[157] = HAVE_vcondv32hiv64qi;
  ena[158] = HAVE_vcondv16siv64qi;
  ena[159] = HAVE_vcondv8div64qi;
  ena[160] = HAVE_vcondv16sfv64qi;
  ena[161] = HAVE_vcondv8dfv64qi;
  ena[162] = HAVE_vcondv64qiv32hi;
  ena[163] = HAVE_vcondv32hiv32hi;
  ena[164] = HAVE_vcondv16siv32hi;
  ena[165] = HAVE_vcondv8div32hi;
  ena[166] = HAVE_vcondv16sfv32hi;
  ena[167] = HAVE_vcondv8dfv32hi;
  ena[168] = HAVE_vcondv64qiv16si;
  ena[169] = HAVE_vcondv32hiv16si;
  ena[170] = HAVE_vcondv16siv16si;
  ena[171] = HAVE_vcondv8div16si;
  ena[172] = HAVE_vcondv16sfv16si;
  ena[173] = HAVE_vcondv8dfv16si;
  ena[174] = HAVE_vcondv64qiv8di;
  ena[175] = HAVE_vcondv32hiv8di;
  ena[176] = HAVE_vcondv16siv8di;
  ena[177] = HAVE_vcondv8div8di;
  ena[178] = HAVE_vcondv16sfv8di;
  ena[179] = HAVE_vcondv8dfv8di;
  ena[180] = HAVE_vcondv16qiv4sf;
  ena[181] = HAVE_vcondv8hiv4sf;
  ena[182] = HAVE_vcondv4siv4sf;
  ena[183] = HAVE_vcondv2div4sf;
  ena[184] = HAVE_vcondv4sfv4sf;
  ena[185] = HAVE_vcondv2dfv4sf;
  ena[186] = HAVE_vcondv16qiv2df;
  ena[187] = HAVE_vcondv8hiv2df;
  ena[188] = HAVE_vcondv4siv2df;
  ena[189] = HAVE_vcondv2div2df;
  ena[190] = HAVE_vcondv4sfv2df;
  ena[191] = HAVE_vcondv2dfv2df;
  ena[192] = HAVE_vcondv32qiv8sf;
  ena[193] = HAVE_vcondv16hiv8sf;
  ena[194] = HAVE_vcondv8siv8sf;
  ena[195] = HAVE_vcondv4div8sf;
  ena[196] = HAVE_vcondv8sfv8sf;
  ena[197] = HAVE_vcondv4dfv8sf;
  ena[198] = HAVE_vcondv32qiv4df;
  ena[199] = HAVE_vcondv16hiv4df;
  ena[200] = HAVE_vcondv8siv4df;
  ena[201] = HAVE_vcondv4div4df;
  ena[202] = HAVE_vcondv8sfv4df;
  ena[203] = HAVE_vcondv4dfv4df;
  ena[204] = HAVE_vcondv64qiv16sf;
  ena[205] = HAVE_vcondv32hiv16sf;
  ena[206] = HAVE_vcondv16siv16sf;
  ena[207] = HAVE_vcondv8div16sf;
  ena[208] = HAVE_vcondv16sfv16sf;
  ena[209] = HAVE_vcondv8dfv16sf;
  ena[210] = HAVE_vcondv64qiv8df;
  ena[211] = HAVE_vcondv32hiv8df;
  ena[212] = HAVE_vcondv16siv8df;
  ena[213] = HAVE_vcondv8div8df;
  ena[214] = HAVE_vcondv16sfv8df;
  ena[215] = HAVE_vcondv8dfv8df;
  ena[216] = HAVE_vconduv16qiv16qi;
  ena[217] = HAVE_vconduv8hiv16qi;
  ena[218] = HAVE_vconduv4siv16qi;
  ena[219] = HAVE_vconduv2div16qi;
  ena[220] = HAVE_vconduv4sfv16qi;
  ena[221] = HAVE_vconduv2dfv16qi;
  ena[222] = HAVE_vconduv16qiv8hi;
  ena[223] = HAVE_vconduv8hiv8hi;
  ena[224] = HAVE_vconduv4siv8hi;
  ena[225] = HAVE_vconduv2div8hi;
  ena[226] = HAVE_vconduv4sfv8hi;
  ena[227] = HAVE_vconduv2dfv8hi;
  ena[228] = HAVE_vconduv16qiv4si;
  ena[229] = HAVE_vconduv8hiv4si;
  ena[230] = HAVE_vconduv4siv4si;
  ena[231] = HAVE_vconduv2div4si;
  ena[232] = HAVE_vconduv4sfv4si;
  ena[233] = HAVE_vconduv2dfv4si;
  ena[234] = HAVE_vconduv2div2di;
  ena[235] = HAVE_vconduv2dfv2di;
  ena[236] = HAVE_vconduv32qiv32qi;
  ena[237] = HAVE_vconduv16hiv32qi;
  ena[238] = HAVE_vconduv8siv32qi;
  ena[239] = HAVE_vconduv4div32qi;
  ena[240] = HAVE_vconduv8sfv32qi;
  ena[241] = HAVE_vconduv4dfv32qi;
  ena[242] = HAVE_vconduv32qiv16hi;
  ena[243] = HAVE_vconduv16hiv16hi;
  ena[244] = HAVE_vconduv8siv16hi;
  ena[245] = HAVE_vconduv4div16hi;
  ena[246] = HAVE_vconduv8sfv16hi;
  ena[247] = HAVE_vconduv4dfv16hi;
  ena[248] = HAVE_vconduv32qiv8si;
  ena[249] = HAVE_vconduv16hiv8si;
  ena[250] = HAVE_vconduv8siv8si;
  ena[251] = HAVE_vconduv4div8si;
  ena[252] = HAVE_vconduv8sfv8si;
  ena[253] = HAVE_vconduv4dfv8si;
  ena[254] = HAVE_vconduv32qiv4di;
  ena[255] = HAVE_vconduv16hiv4di;
  ena[256] = HAVE_vconduv8siv4di;
  ena[257] = HAVE_vconduv4div4di;
  ena[258] = HAVE_vconduv8sfv4di;
  ena[259] = HAVE_vconduv4dfv4di;
  ena[260] = HAVE_vconduv64qiv64qi;
  ena[261] = HAVE_vconduv32hiv64qi;
  ena[262] = HAVE_vconduv16siv64qi;
  ena[263] = HAVE_vconduv8div64qi;
  ena[264] = HAVE_vconduv16sfv64qi;
  ena[265] = HAVE_vconduv8dfv64qi;
  ena[266] = HAVE_vconduv64qiv32hi;
  ena[267] = HAVE_vconduv32hiv32hi;
  ena[268] = HAVE_vconduv16siv32hi;
  ena[269] = HAVE_vconduv8div32hi;
  ena[270] = HAVE_vconduv16sfv32hi;
  ena[271] = HAVE_vconduv8dfv32hi;
  ena[272] = HAVE_vconduv64qiv16si;
  ena[273] = HAVE_vconduv32hiv16si;
  ena[274] = HAVE_vconduv16siv16si;
  ena[275] = HAVE_vconduv8div16si;
  ena[276] = HAVE_vconduv16sfv16si;
  ena[277] = HAVE_vconduv8dfv16si;
  ena[278] = HAVE_vconduv64qiv8di;
  ena[279] = HAVE_vconduv32hiv8di;
  ena[280] = HAVE_vconduv16siv8di;
  ena[281] = HAVE_vconduv8div8di;
  ena[282] = HAVE_vconduv16sfv8di;
  ena[283] = HAVE_vconduv8dfv8di;
  ena[284] = HAVE_addqi3;
  ena[285] = HAVE_addhi3;
  ena[286] = HAVE_addsi3;
  ena[287] = HAVE_adddi3;
  ena[288] = HAVE_addti3;
  ena[289] = HAVE_addsf3;
  ena[290] = HAVE_adddf3;
  ena[291] = HAVE_addxf3;
  ena[292] = HAVE_addv16qi3;
  ena[293] = HAVE_addv8hi3;
  ena[294] = HAVE_addv4si3;
  ena[295] = HAVE_addv2di3;
  ena[296] = HAVE_addv32qi3;
  ena[297] = HAVE_addv16hi3;
  ena[298] = HAVE_addv8si3;
  ena[299] = HAVE_addv4di3;
  ena[300] = HAVE_addv64qi3;
  ena[301] = HAVE_addv32hi3;
  ena[302] = HAVE_addv16si3;
  ena[303] = HAVE_addv8di3;
  ena[304] = HAVE_addv4sf3;
  ena[305] = HAVE_addv2df3;
  ena[306] = HAVE_addv8sf3;
  ena[307] = HAVE_addv4df3;
  ena[308] = HAVE_addv16sf3;
  ena[309] = HAVE_addv8df3;
  ena[310] = HAVE_subqi3;
  ena[311] = HAVE_subhi3;
  ena[312] = HAVE_subsi3;
  ena[313] = HAVE_subdi3;
  ena[314] = HAVE_subti3;
  ena[315] = HAVE_subsf3;
  ena[316] = HAVE_subdf3;
  ena[317] = HAVE_subxf3;
  ena[318] = HAVE_subv16qi3;
  ena[319] = HAVE_subv8hi3;
  ena[320] = HAVE_subv4si3;
  ena[321] = HAVE_subv2di3;
  ena[322] = HAVE_subv32qi3;
  ena[323] = HAVE_subv16hi3;
  ena[324] = HAVE_subv8si3;
  ena[325] = HAVE_subv4di3;
  ena[326] = HAVE_subv64qi3;
  ena[327] = HAVE_subv32hi3;
  ena[328] = HAVE_subv16si3;
  ena[329] = HAVE_subv8di3;
  ena[330] = HAVE_subv4sf3;
  ena[331] = HAVE_subv2df3;
  ena[332] = HAVE_subv8sf3;
  ena[333] = HAVE_subv4df3;
  ena[334] = HAVE_subv16sf3;
  ena[335] = HAVE_subv8df3;
  ena[336] = HAVE_mulqi3;
  ena[337] = HAVE_mulhi3;
  ena[338] = HAVE_mulsi3;
  ena[339] = HAVE_muldi3;
  ena[340] = HAVE_mulsf3;
  ena[341] = HAVE_muldf3;
  ena[342] = HAVE_mulxf3;
  ena[343] = HAVE_mulv16qi3;
  ena[344] = HAVE_mulv8hi3;
  ena[345] = HAVE_mulv4si3;
  ena[346] = HAVE_mulv2di3;
  ena[347] = HAVE_mulv32qi3;
  ena[348] = HAVE_mulv16hi3;
  ena[349] = HAVE_mulv8si3;
  ena[350] = HAVE_mulv4di3;
  ena[351] = HAVE_mulv64qi3;
  ena[352] = HAVE_mulv32hi3;
  ena[353] = HAVE_mulv16si3;
  ena[354] = HAVE_mulv8di3;
  ena[355] = HAVE_mulv4sf3;
  ena[356] = HAVE_mulv2df3;
  ena[357] = HAVE_mulv8sf3;
  ena[358] = HAVE_mulv4df3;
  ena[359] = HAVE_mulv16sf3;
  ena[360] = HAVE_mulv8df3;
  ena[361] = HAVE_divsf3;
  ena[362] = HAVE_divdf3;
  ena[363] = HAVE_divxf3;
  ena[364] = HAVE_divv4sf3;
  ena[365] = HAVE_divv2df3;
  ena[366] = HAVE_divv8sf3;
  ena[367] = HAVE_divv4df3;
  ena[368] = HAVE_divv16sf3;
  ena[369] = HAVE_divv8df3;
  ena[370] = HAVE_divmodqi4;
  ena[371] = HAVE_divmodhi4;
  ena[372] = HAVE_divmodsi4;
  ena[373] = HAVE_divmoddi4;
  ena[374] = HAVE_udivmodqi4;
  ena[375] = HAVE_udivmodhi4;
  ena[376] = HAVE_udivmodsi4;
  ena[377] = HAVE_udivmoddi4;
  ena[378] = HAVE_andqi3;
  ena[379] = HAVE_andhi3;
  ena[380] = HAVE_andsi3;
  ena[381] = HAVE_anddi3;
  ena[382] = HAVE_andtf3;
  ena[383] = HAVE_andv16qi3;
  ena[384] = HAVE_andv8hi3;
  ena[385] = HAVE_andv4si3;
  ena[386] = HAVE_andv2di3;
  ena[387] = HAVE_andv32qi3;
  ena[388] = HAVE_andv16hi3;
  ena[389] = HAVE_andv8si3;
  ena[390] = HAVE_andv4di3;
  ena[391] = HAVE_andv64qi3;
  ena[392] = HAVE_andv32hi3;
  ena[393] = HAVE_andv16si3;
  ena[394] = HAVE_andv8di3;
  ena[395] = HAVE_andv4sf3;
  ena[396] = HAVE_andv2df3;
  ena[397] = HAVE_andv8sf3;
  ena[398] = HAVE_andv4df3;
  ena[399] = HAVE_andv16sf3;
  ena[400] = HAVE_andv8df3;
  ena[401] = HAVE_iorqi3;
  ena[402] = HAVE_iorhi3;
  ena[403] = HAVE_iorsi3;
  ena[404] = HAVE_iordi3;
  ena[405] = HAVE_iortf3;
  ena[406] = HAVE_iorv16qi3;
  ena[407] = HAVE_iorv8hi3;
  ena[408] = HAVE_iorv4si3;
  ena[409] = HAVE_iorv2di3;
  ena[410] = HAVE_iorv32qi3;
  ena[411] = HAVE_iorv16hi3;
  ena[412] = HAVE_iorv8si3;
  ena[413] = HAVE_iorv4di3;
  ena[414] = HAVE_iorv64qi3;
  ena[415] = HAVE_iorv32hi3;
  ena[416] = HAVE_iorv16si3;
  ena[417] = HAVE_iorv8di3;
  ena[418] = HAVE_iorv4sf3;
  ena[419] = HAVE_iorv2df3;
  ena[420] = HAVE_iorv8sf3;
  ena[421] = HAVE_iorv4df3;
  ena[422] = HAVE_iorv16sf3;
  ena[423] = HAVE_iorv8df3;
  ena[424] = HAVE_xorqi3;
  ena[425] = HAVE_xorhi3;
  ena[426] = HAVE_xorsi3;
  ena[427] = HAVE_xordi3;
  ena[428] = HAVE_xortf3;
  ena[429] = HAVE_xorv16qi3;
  ena[430] = HAVE_xorv8hi3;
  ena[431] = HAVE_xorv4si3;
  ena[432] = HAVE_xorv2di3;
  ena[433] = HAVE_xorv32qi3;
  ena[434] = HAVE_xorv16hi3;
  ena[435] = HAVE_xorv8si3;
  ena[436] = HAVE_xorv4di3;
  ena[437] = HAVE_xorv64qi3;
  ena[438] = HAVE_xorv32hi3;
  ena[439] = HAVE_xorv16si3;
  ena[440] = HAVE_xorv8di3;
  ena[441] = HAVE_xorv4sf3;
  ena[442] = HAVE_xorv2df3;
  ena[443] = HAVE_xorv8sf3;
  ena[444] = HAVE_xorv4df3;
  ena[445] = HAVE_xorv16sf3;
  ena[446] = HAVE_xorv8df3;
  ena[447] = HAVE_ashlqi3;
  ena[448] = HAVE_ashlhi3;
  ena[449] = HAVE_ashlsi3;
  ena[450] = HAVE_ashldi3;
  ena[451] = HAVE_ashlti3;
  ena[452] = HAVE_ashlv16qi3;
  ena[453] = HAVE_ashlv8hi3;
  ena[454] = HAVE_ashlv4si3;
  ena[455] = HAVE_ashlv2di3;
  ena[456] = HAVE_ashlv32qi3;
  ena[457] = HAVE_ashlv16hi3;
  ena[458] = HAVE_ashlv8si3;
  ena[459] = HAVE_ashlv4di3;
  ena[460] = HAVE_ashlv64qi3;
  ena[461] = HAVE_ashlv32hi3;
  ena[462] = HAVE_ashlv16si3;
  ena[463] = HAVE_ashlv8di3;
  ena[464] = HAVE_ashrqi3;
  ena[465] = HAVE_ashrhi3;
  ena[466] = HAVE_ashrsi3;
  ena[467] = HAVE_ashrdi3;
  ena[468] = HAVE_ashrti3;
  ena[469] = HAVE_ashrv16qi3;
  ena[470] = HAVE_ashrv8hi3;
  ena[471] = HAVE_ashrv4si3;
  ena[472] = HAVE_ashrv2di3;
  ena[473] = HAVE_ashrv32qi3;
  ena[474] = HAVE_ashrv16hi3;
  ena[475] = HAVE_ashrv8si3;
  ena[476] = HAVE_ashrv4di3;
  ena[477] = HAVE_ashrv64qi3;
  ena[478] = HAVE_ashrv32hi3;
  ena[479] = HAVE_ashrv16si3;
  ena[480] = HAVE_ashrv8di3;
  ena[481] = HAVE_lshrqi3;
  ena[482] = HAVE_lshrhi3;
  ena[483] = HAVE_lshrsi3;
  ena[484] = HAVE_lshrdi3;
  ena[485] = HAVE_lshrti3;
  ena[486] = HAVE_lshrv16qi3;
  ena[487] = HAVE_lshrv8hi3;
  ena[488] = HAVE_lshrv4si3;
  ena[489] = HAVE_lshrv2di3;
  ena[490] = HAVE_lshrv32qi3;
  ena[491] = HAVE_lshrv16hi3;
  ena[492] = HAVE_lshrv8si3;
  ena[493] = HAVE_lshrv4di3;
  ena[494] = HAVE_lshrv64qi3;
  ena[495] = HAVE_lshrv32hi3;
  ena[496] = HAVE_lshrv16si3;
  ena[497] = HAVE_lshrv8di3;
  ena[498] = HAVE_rotlqi3;
  ena[499] = HAVE_rotlhi3;
  ena[500] = HAVE_rotlsi3;
  ena[501] = HAVE_rotldi3;
  ena[502] = HAVE_rotlti3;
  ena[503] = HAVE_rotlv16qi3;
  ena[504] = HAVE_rotlv8hi3;
  ena[505] = HAVE_rotlv4si3;
  ena[506] = HAVE_rotlv2di3;
  ena[507] = HAVE_rotrqi3;
  ena[508] = HAVE_rotrhi3;
  ena[509] = HAVE_rotrsi3;
  ena[510] = HAVE_rotrdi3;
  ena[511] = HAVE_rotrti3;
  ena[512] = HAVE_rotrv16qi3;
  ena[513] = HAVE_rotrv8hi3;
  ena[514] = HAVE_rotrv4si3;
  ena[515] = HAVE_rotrv2di3;
  ena[516] = HAVE_vashlv16qi3;
  ena[517] = HAVE_vashlv8hi3;
  ena[518] = HAVE_vashlv4si3;
  ena[519] = HAVE_vashlv2di3;
  ena[520] = HAVE_vashlv8si3;
  ena[521] = HAVE_vashlv4di3;
  ena[522] = HAVE_vashlv16si3;
  ena[523] = HAVE_vashlv8di3;
  ena[524] = HAVE_vashrv16qi3;
  ena[525] = HAVE_vashrv8hi3;
  ena[526] = HAVE_vashrv4si3;
  ena[527] = HAVE_vashrv2di3;
  ena[528] = HAVE_vashrv8si3;
  ena[529] = HAVE_vashrv16si3;
  ena[530] = HAVE_vlshrv16qi3;
  ena[531] = HAVE_vlshrv8hi3;
  ena[532] = HAVE_vlshrv4si3;
  ena[533] = HAVE_vlshrv2di3;
  ena[534] = HAVE_vlshrv8si3;
  ena[535] = HAVE_vlshrv4di3;
  ena[536] = HAVE_vlshrv16si3;
  ena[537] = HAVE_vlshrv8di3;
  ena[538] = HAVE_vrotlv16qi3;
  ena[539] = HAVE_vrotlv8hi3;
  ena[540] = HAVE_vrotlv4si3;
  ena[541] = HAVE_vrotlv2di3;
  ena[542] = HAVE_vrotrv16qi3;
  ena[543] = HAVE_vrotrv8hi3;
  ena[544] = HAVE_vrotrv4si3;
  ena[545] = HAVE_vrotrv2di3;
  ena[546] = HAVE_sminsf3;
  ena[547] = HAVE_smindf3;
  ena[548] = HAVE_sminv16qi3;
  ena[549] = HAVE_sminv8hi3;
  ena[550] = HAVE_sminv4si3;
  ena[551] = HAVE_sminv2di3;
  ena[552] = HAVE_sminv32qi3;
  ena[553] = HAVE_sminv16hi3;
  ena[554] = HAVE_sminv8si3;
  ena[555] = HAVE_sminv4di3;
  ena[556] = HAVE_sminv64qi3;
  ena[557] = HAVE_sminv32hi3;
  ena[558] = HAVE_sminv16si3;
  ena[559] = HAVE_sminv8di3;
  ena[560] = HAVE_sminv4sf3;
  ena[561] = HAVE_sminv2df3;
  ena[562] = HAVE_sminv8sf3;
  ena[563] = HAVE_sminv4df3;
  ena[564] = HAVE_sminv16sf3;
  ena[565] = HAVE_sminv8df3;
  ena[566] = HAVE_smaxsf3;
  ena[567] = HAVE_smaxdf3;
  ena[568] = HAVE_smaxv16qi3;
  ena[569] = HAVE_smaxv8hi3;
  ena[570] = HAVE_smaxv4si3;
  ena[571] = HAVE_smaxv2di3;
  ena[572] = HAVE_smaxv32qi3;
  ena[573] = HAVE_smaxv16hi3;
  ena[574] = HAVE_smaxv8si3;
  ena[575] = HAVE_smaxv4di3;
  ena[576] = HAVE_smaxv64qi3;
  ena[577] = HAVE_smaxv32hi3;
  ena[578] = HAVE_smaxv16si3;
  ena[579] = HAVE_smaxv8di3;
  ena[580] = HAVE_smaxv4sf3;
  ena[581] = HAVE_smaxv2df3;
  ena[582] = HAVE_smaxv8sf3;
  ena[583] = HAVE_smaxv4df3;
  ena[584] = HAVE_smaxv16sf3;
  ena[585] = HAVE_smaxv8df3;
  ena[586] = HAVE_uminv16qi3;
  ena[587] = HAVE_uminv8hi3;
  ena[588] = HAVE_uminv4si3;
  ena[589] = HAVE_uminv2di3;
  ena[590] = HAVE_uminv32qi3;
  ena[591] = HAVE_uminv16hi3;
  ena[592] = HAVE_uminv8si3;
  ena[593] = HAVE_uminv4di3;
  ena[594] = HAVE_uminv64qi3;
  ena[595] = HAVE_uminv32hi3;
  ena[596] = HAVE_uminv16si3;
  ena[597] = HAVE_uminv8di3;
  ena[598] = HAVE_umaxv16qi3;
  ena[599] = HAVE_umaxv8hi3;
  ena[600] = HAVE_umaxv4si3;
  ena[601] = HAVE_umaxv2di3;
  ena[602] = HAVE_umaxv32qi3;
  ena[603] = HAVE_umaxv16hi3;
  ena[604] = HAVE_umaxv8si3;
  ena[605] = HAVE_umaxv4di3;
  ena[606] = HAVE_umaxv64qi3;
  ena[607] = HAVE_umaxv32hi3;
  ena[608] = HAVE_umaxv16si3;
  ena[609] = HAVE_umaxv8di3;
  ena[610] = HAVE_negqi2;
  ena[611] = HAVE_neghi2;
  ena[612] = HAVE_negsi2;
  ena[613] = HAVE_negdi2;
  ena[614] = HAVE_negti2;
  ena[615] = HAVE_negsf2;
  ena[616] = HAVE_negdf2;
  ena[617] = HAVE_negxf2;
  ena[618] = HAVE_negtf2;
  ena[619] = HAVE_negv16qi2;
  ena[620] = HAVE_negv8hi2;
  ena[621] = HAVE_negv4si2;
  ena[622] = HAVE_negv2di2;
  ena[623] = HAVE_negv32qi2;
  ena[624] = HAVE_negv16hi2;
  ena[625] = HAVE_negv8si2;
  ena[626] = HAVE_negv4di2;
  ena[627] = HAVE_negv64qi2;
  ena[628] = HAVE_negv32hi2;
  ena[629] = HAVE_negv16si2;
  ena[630] = HAVE_negv8di2;
  ena[631] = HAVE_negv4sf2;
  ena[632] = HAVE_negv2df2;
  ena[633] = HAVE_negv8sf2;
  ena[634] = HAVE_negv4df2;
  ena[635] = HAVE_negv16sf2;
  ena[636] = HAVE_negv8df2;
  ena[637] = HAVE_abssf2;
  ena[638] = HAVE_absdf2;
  ena[639] = HAVE_absxf2;
  ena[640] = HAVE_abstf2;
  ena[641] = HAVE_absv8qi2;
  ena[642] = HAVE_absv4hi2;
  ena[643] = HAVE_absv2si2;
  ena[644] = HAVE_absv16qi2;
  ena[645] = HAVE_absv8hi2;
  ena[646] = HAVE_absv4si2;
  ena[647] = HAVE_absv2di2;
  ena[648] = HAVE_absv32qi2;
  ena[649] = HAVE_absv16hi2;
  ena[650] = HAVE_absv8si2;
  ena[651] = HAVE_absv4di2;
  ena[652] = HAVE_absv64qi2;
  ena[653] = HAVE_absv32hi2;
  ena[654] = HAVE_absv16si2;
  ena[655] = HAVE_absv8di2;
  ena[656] = HAVE_absv4sf2;
  ena[657] = HAVE_absv2df2;
  ena[658] = HAVE_absv8sf2;
  ena[659] = HAVE_absv4df2;
  ena[660] = HAVE_absv16sf2;
  ena[661] = HAVE_absv8df2;
  ena[662] = HAVE_one_cmplqi2;
  ena[663] = HAVE_one_cmplhi2;
  ena[664] = HAVE_one_cmplsi2;
  ena[665] = HAVE_one_cmpldi2;
  ena[666] = HAVE_one_cmplv16qi2;
  ena[667] = HAVE_one_cmplv8hi2;
  ena[668] = HAVE_one_cmplv4si2;
  ena[669] = HAVE_one_cmplv2di2;
  ena[670] = HAVE_one_cmplv32qi2;
  ena[671] = HAVE_one_cmplv16hi2;
  ena[672] = HAVE_one_cmplv8si2;
  ena[673] = HAVE_one_cmplv4di2;
  ena[674] = HAVE_one_cmplv64qi2;
  ena[675] = HAVE_one_cmplv32hi2;
  ena[676] = HAVE_one_cmplv16si2;
  ena[677] = HAVE_one_cmplv8di2;
  ena[678] = HAVE_bswapsi2;
  ena[679] = HAVE_bswapdi2;
  ena[680] = HAVE_ffssi2;
  ena[681] = HAVE_ffsdi2;
  ena[682] = HAVE_clzhi2;
  ena[683] = HAVE_clzsi2;
  ena[684] = HAVE_clzdi2;
  ena[685] = HAVE_clzv4si2;
  ena[686] = HAVE_clzv2di2;
  ena[687] = HAVE_clzv8si2;
  ena[688] = HAVE_clzv4di2;
  ena[689] = HAVE_clzv16si2;
  ena[690] = HAVE_clzv8di2;
  ena[691] = HAVE_ctzhi2;
  ena[692] = HAVE_ctzsi2;
  ena[693] = HAVE_ctzdi2;
  ena[694] = HAVE_popcounthi2;
  ena[695] = HAVE_popcountsi2;
  ena[696] = HAVE_popcountdi2;
  ena[697] = HAVE_paritysi2;
  ena[698] = HAVE_paritydi2;
  ena[699] = HAVE_sqrtsf2;
  ena[700] = HAVE_sqrtdf2;
  ena[701] = HAVE_sqrtxf2;
  ena[702] = HAVE_sqrtv4sf2;
  ena[703] = HAVE_sqrtv2df2;
  ena[704] = HAVE_sqrtv8sf2;
  ena[705] = HAVE_sqrtv4df2;
  ena[706] = HAVE_sqrtv16sf2;
  ena[707] = HAVE_sqrtv8df2;
  ena[708] = HAVE_movqi;
  ena[709] = HAVE_movhi;
  ena[710] = HAVE_movsi;
  ena[711] = HAVE_movdi;
  ena[712] = HAVE_movti;
  ena[713] = HAVE_movoi;
  ena[714] = HAVE_movxi;
  ena[715] = HAVE_movbnd32;
  ena[716] = HAVE_movbnd64;
  ena[717] = HAVE_movsf;
  ena[718] = HAVE_movdf;
  ena[719] = HAVE_movxf;
  ena[720] = HAVE_movtf;
  ena[721] = HAVE_movcdi;
  ena[722] = HAVE_movv8qi;
  ena[723] = HAVE_movv4hi;
  ena[724] = HAVE_movv2si;
  ena[725] = HAVE_movv1di;
  ena[726] = HAVE_movv16qi;
  ena[727] = HAVE_movv8hi;
  ena[728] = HAVE_movv4si;
  ena[729] = HAVE_movv2di;
  ena[730] = HAVE_movv1ti;
  ena[731] = HAVE_movv32qi;
  ena[732] = HAVE_movv16hi;
  ena[733] = HAVE_movv8si;
  ena[734] = HAVE_movv4di;
  ena[735] = HAVE_movv2ti;
  ena[736] = HAVE_movv64qi;
  ena[737] = HAVE_movv32hi;
  ena[738] = HAVE_movv16si;
  ena[739] = HAVE_movv8di;
  ena[740] = HAVE_movv4ti;
  ena[741] = HAVE_movv2sf;
  ena[742] = HAVE_movv4sf;
  ena[743] = HAVE_movv2df;
  ena[744] = HAVE_movv8sf;
  ena[745] = HAVE_movv4df;
  ena[746] = HAVE_movv16sf;
  ena[747] = HAVE_movv8df;
  ena[748] = HAVE_movstrictqi;
  ena[749] = HAVE_movstricthi;
  ena[750] = HAVE_movmisalignv8qi;
  ena[751] = HAVE_movmisalignv4hi;
  ena[752] = HAVE_movmisalignv2si;
  ena[753] = HAVE_movmisalignv1di;
  ena[754] = HAVE_movmisalignv16qi;
  ena[755] = HAVE_movmisalignv8hi;
  ena[756] = HAVE_movmisalignv4si;
  ena[757] = HAVE_movmisalignv2di;
  ena[758] = HAVE_movmisalignv1ti;
  ena[759] = HAVE_movmisalignv32qi;
  ena[760] = HAVE_movmisalignv16hi;
  ena[761] = HAVE_movmisalignv8si;
  ena[762] = HAVE_movmisalignv4di;
  ena[763] = HAVE_movmisalignv2ti;
  ena[764] = HAVE_movmisalignv64qi;
  ena[765] = HAVE_movmisalignv32hi;
  ena[766] = HAVE_movmisalignv16si;
  ena[767] = HAVE_movmisalignv8di;
  ena[768] = HAVE_movmisalignv4ti;
  ena[769] = HAVE_movmisalignv2sf;
  ena[770] = HAVE_movmisalignv4sf;
  ena[771] = HAVE_movmisalignv2df;
  ena[772] = HAVE_movmisalignv8sf;
  ena[773] = HAVE_movmisalignv4df;
  ena[774] = HAVE_movmisalignv16sf;
  ena[775] = HAVE_movmisalignv8df;
  ena[776] = HAVE_storentsi;
  ena[777] = HAVE_storentdi;
  ena[778] = HAVE_storentsf;
  ena[779] = HAVE_storentdf;
  ena[780] = HAVE_storentv2di;
  ena[781] = HAVE_storentv4di;
  ena[782] = HAVE_storentv8di;
  ena[783] = HAVE_storentv4sf;
  ena[784] = HAVE_storentv2df;
  ena[785] = HAVE_storentv8sf;
  ena[786] = HAVE_storentv4df;
  ena[787] = HAVE_storentv16sf;
  ena[788] = HAVE_storentv8df;
  ena[789] = HAVE_cbranchcc4;
  ena[790] = HAVE_cbranchqi4;
  ena[791] = HAVE_cbranchhi4;
  ena[792] = HAVE_cbranchsi4;
  ena[793] = HAVE_cbranchdi4;
  ena[794] = HAVE_cbranchti4;
  ena[795] = HAVE_cbranchsf4;
  ena[796] = HAVE_cbranchdf4;
  ena[797] = HAVE_cbranchxf4;
  ena[798] = HAVE_addqicc;
  ena[799] = HAVE_addhicc;
  ena[800] = HAVE_addsicc;
  ena[801] = HAVE_adddicc;
  ena[802] = HAVE_movqicc;
  ena[803] = HAVE_movhicc;
  ena[804] = HAVE_movsicc;
  ena[805] = HAVE_movdicc;
  ena[806] = HAVE_movsfcc;
  ena[807] = HAVE_movdfcc;
  ena[808] = HAVE_movxfcc;
  ena[809] = HAVE_cstorecc4;
  ena[810] = HAVE_cstoreqi4;
  ena[811] = HAVE_cstorehi4;
  ena[812] = HAVE_cstoresi4;
  ena[813] = HAVE_cstoredi4;
  ena[814] = HAVE_cstoresf4;
  ena[815] = HAVE_cstoredf4;
  ena[816] = HAVE_cstorexf4;
  ena[817] = HAVE_addvqi4;
  ena[818] = HAVE_addvhi4;
  ena[819] = HAVE_addvsi4;
  ena[820] = HAVE_addvdi4;
  ena[821] = HAVE_subvqi4;
  ena[822] = HAVE_subvhi4;
  ena[823] = HAVE_subvsi4;
  ena[824] = HAVE_subvdi4;
  ena[825] = HAVE_mulvqi4;
  ena[826] = HAVE_mulvsi4;
  ena[827] = HAVE_mulvdi4;
  ena[828] = HAVE_umulvqi4;
  ena[829] = HAVE_umulvsi4;
  ena[830] = HAVE_umulvdi4;
  ena[831] = HAVE_negvqi3;
  ena[832] = HAVE_negvhi3;
  ena[833] = HAVE_negvsi3;
  ena[834] = HAVE_negvdi3;
  ena[835] = HAVE_smulsi3_highpart;
  ena[836] = HAVE_smuldi3_highpart;
  ena[837] = HAVE_smulv8hi3_highpart;
  ena[838] = HAVE_smulv16hi3_highpart;
  ena[839] = HAVE_smulv32hi3_highpart;
  ena[840] = HAVE_umulsi3_highpart;
  ena[841] = HAVE_umuldi3_highpart;
  ena[842] = HAVE_umulv8hi3_highpart;
  ena[843] = HAVE_umulv16hi3_highpart;
  ena[844] = HAVE_umulv32hi3_highpart;
  ena[845] = HAVE_cmpstrnsi;
  ena[846] = HAVE_movmemsi;
  ena[847] = HAVE_movmemdi;
  ena[848] = HAVE_setmemsi;
  ena[849] = HAVE_setmemdi;
  ena[850] = HAVE_strlensi;
  ena[851] = HAVE_strlendi;
  ena[852] = HAVE_fmasf4;
  ena[853] = HAVE_fmadf4;
  ena[854] = HAVE_fmav4sf4;
  ena[855] = HAVE_fmav2df4;
  ena[856] = HAVE_fmav8sf4;
  ena[857] = HAVE_fmav4df4;
  ena[858] = HAVE_fmav16sf4;
  ena[859] = HAVE_fmav8df4;
  ena[860] = HAVE_fmssf4;
  ena[861] = HAVE_fmsdf4;
  ena[862] = HAVE_fmsv4sf4;
  ena[863] = HAVE_fmsv2df4;
  ena[864] = HAVE_fmsv8sf4;
  ena[865] = HAVE_fmsv4df4;
  ena[866] = HAVE_fmsv16sf4;
  ena[867] = HAVE_fmsv8df4;
  ena[868] = HAVE_fnmasf4;
  ena[869] = HAVE_fnmadf4;
  ena[870] = HAVE_fnmav4sf4;
  ena[871] = HAVE_fnmav2df4;
  ena[872] = HAVE_fnmav8sf4;
  ena[873] = HAVE_fnmav4df4;
  ena[874] = HAVE_fnmav16sf4;
  ena[875] = HAVE_fnmav8df4;
  ena[876] = HAVE_fnmssf4;
  ena[877] = HAVE_fnmsdf4;
  ena[878] = HAVE_fnmsv4sf4;
  ena[879] = HAVE_fnmsv2df4;
  ena[880] = HAVE_fnmsv8sf4;
  ena[881] = HAVE_fnmsv4df4;
  ena[882] = HAVE_fnmsv16sf4;
  ena[883] = HAVE_fnmsv8df4;
  ena[884] = HAVE_rintsf2;
  ena[885] = HAVE_rintdf2;
  ena[886] = HAVE_rintxf2;
  ena[887] = HAVE_roundsf2;
  ena[888] = HAVE_rounddf2;
  ena[889] = HAVE_roundxf2;
  ena[890] = HAVE_roundv4sf2;
  ena[891] = HAVE_roundv2df2;
  ena[892] = HAVE_roundv8sf2;
  ena[893] = HAVE_roundv4df2;
  ena[894] = HAVE_roundv16sf2;
  ena[895] = HAVE_roundv8df2;
  ena[896] = HAVE_floorsf2;
  ena[897] = HAVE_floordf2;
  ena[898] = HAVE_floorxf2;
  ena[899] = HAVE_ceilsf2;
  ena[900] = HAVE_ceildf2;
  ena[901] = HAVE_ceilxf2;
  ena[902] = HAVE_btruncsf2;
  ena[903] = HAVE_btruncdf2;
  ena[904] = HAVE_btruncxf2;
  ena[905] = HAVE_nearbyintsf2;
  ena[906] = HAVE_nearbyintdf2;
  ena[907] = HAVE_nearbyintxf2;
  ena[908] = HAVE_acossf2;
  ena[909] = HAVE_acosdf2;
  ena[910] = HAVE_acosxf2;
  ena[911] = HAVE_asinsf2;
  ena[912] = HAVE_asindf2;
  ena[913] = HAVE_asinxf2;
  ena[914] = HAVE_atan2sf3;
  ena[915] = HAVE_atan2df3;
  ena[916] = HAVE_atan2xf3;
  ena[917] = HAVE_atansf2;
  ena[918] = HAVE_atandf2;
  ena[919] = HAVE_atanxf2;
  ena[920] = HAVE_copysignsf3;
  ena[921] = HAVE_copysigndf3;
  ena[922] = HAVE_copysigntf3;
  ena[923] = HAVE_copysignv4sf3;
  ena[924] = HAVE_copysignv2df3;
  ena[925] = HAVE_copysignv8sf3;
  ena[926] = HAVE_copysignv4df3;
  ena[927] = HAVE_copysignv16sf3;
  ena[928] = HAVE_copysignv8df3;
  ena[929] = HAVE_exp10sf2;
  ena[930] = HAVE_exp10df2;
  ena[931] = HAVE_exp10xf2;
  ena[932] = HAVE_exp2sf2;
  ena[933] = HAVE_exp2df2;
  ena[934] = HAVE_exp2xf2;
  ena[935] = HAVE_expsf2;
  ena[936] = HAVE_expdf2;
  ena[937] = HAVE_expxf2;
  ena[938] = HAVE_expm1sf2;
  ena[939] = HAVE_expm1df2;
  ena[940] = HAVE_expm1xf2;
  ena[941] = HAVE_fmodsf3;
  ena[942] = HAVE_fmoddf3;
  ena[943] = HAVE_fmodxf3;
  ena[944] = HAVE_ilogbsf2;
  ena[945] = HAVE_ilogbdf2;
  ena[946] = HAVE_ilogbxf2;
  ena[947] = HAVE_isinfsf2;
  ena[948] = HAVE_isinfdf2;
  ena[949] = HAVE_isinfxf2;
  ena[950] = HAVE_ldexpsf3;
  ena[951] = HAVE_ldexpdf3;
  ena[952] = HAVE_ldexpxf3;
  ena[953] = HAVE_log10sf2;
  ena[954] = HAVE_log10df2;
  ena[955] = HAVE_log10xf2;
  ena[956] = HAVE_log1psf2;
  ena[957] = HAVE_log1pdf2;
  ena[958] = HAVE_log1pxf2;
  ena[959] = HAVE_log2sf2;
  ena[960] = HAVE_log2df2;
  ena[961] = HAVE_log2xf2;
  ena[962] = HAVE_logsf2;
  ena[963] = HAVE_logdf2;
  ena[964] = HAVE_logxf2;
  ena[965] = HAVE_logbsf2;
  ena[966] = HAVE_logbdf2;
  ena[967] = HAVE_logbxf2;
  ena[968] = HAVE_remaindersf3;
  ena[969] = HAVE_remainderdf3;
  ena[970] = HAVE_remainderxf3;
  ena[971] = HAVE_scalbsf3;
  ena[972] = HAVE_scalbdf3;
  ena[973] = HAVE_scalbxf3;
  ena[974] = HAVE_signbitsf2;
  ena[975] = HAVE_signbitdf2;
  ena[976] = HAVE_signbitxf2;
  ena[977] = HAVE_significandsf2;
  ena[978] = HAVE_significanddf2;
  ena[979] = HAVE_significandxf2;
  ena[980] = HAVE_sincossf3;
  ena[981] = HAVE_sincosdf3;
  ena[982] = HAVE_sincosxf3;
  ena[983] = HAVE_tansf2;
  ena[984] = HAVE_tandf2;
  ena[985] = HAVE_tanxf2;
  ena[986] = HAVE_reduc_smax_v32qi;
  ena[987] = HAVE_reduc_smax_v16hi;
  ena[988] = HAVE_reduc_smax_v8si;
  ena[989] = HAVE_reduc_smax_v4di;
  ena[990] = HAVE_reduc_smax_v64qi;
  ena[991] = HAVE_reduc_smax_v32hi;
  ena[992] = HAVE_reduc_smax_v16si;
  ena[993] = HAVE_reduc_smax_v8di;
  ena[994] = HAVE_reduc_smax_v4sf;
  ena[995] = HAVE_reduc_smax_v8sf;
  ena[996] = HAVE_reduc_smax_v4df;
  ena[997] = HAVE_reduc_smax_v16sf;
  ena[998] = HAVE_reduc_smax_v8df;
  ena[999] = HAVE_reduc_smin_v32qi;
  ena[1000] = HAVE_reduc_smin_v16hi;
  ena[1001] = HAVE_reduc_smin_v8si;
  ena[1002] = HAVE_reduc_smin_v4di;
  ena[1003] = HAVE_reduc_smin_v64qi;
  ena[1004] = HAVE_reduc_smin_v32hi;
  ena[1005] = HAVE_reduc_smin_v16si;
  ena[1006] = HAVE_reduc_smin_v8di;
  ena[1007] = HAVE_reduc_smin_v4sf;
  ena[1008] = HAVE_reduc_smin_v8sf;
  ena[1009] = HAVE_reduc_smin_v4df;
  ena[1010] = HAVE_reduc_smin_v16sf;
  ena[1011] = HAVE_reduc_smin_v8df;
  ena[1012] = HAVE_reduc_splus_v4sf;
  ena[1013] = HAVE_reduc_splus_v2df;
  ena[1014] = HAVE_reduc_splus_v8sf;
  ena[1015] = HAVE_reduc_splus_v4df;
  ena[1016] = HAVE_reduc_splus_v16sf;
  ena[1017] = HAVE_reduc_splus_v8df;
  ena[1018] = HAVE_reduc_umax_v32qi;
  ena[1019] = HAVE_reduc_umax_v16hi;
  ena[1020] = HAVE_reduc_umax_v8si;
  ena[1021] = HAVE_reduc_umax_v4di;
  ena[1022] = HAVE_reduc_umax_v64qi;
  ena[1023] = HAVE_reduc_umax_v32hi;
  ena[1024] = HAVE_reduc_umax_v16si;
  ena[1025] = HAVE_reduc_umax_v8di;
  ena[1026] = HAVE_reduc_umin_v8hi;
  ena[1027] = HAVE_reduc_umin_v32qi;
  ena[1028] = HAVE_reduc_umin_v16hi;
  ena[1029] = HAVE_reduc_umin_v8si;
  ena[1030] = HAVE_reduc_umin_v4di;
  ena[1031] = HAVE_reduc_umin_v64qi;
  ena[1032] = HAVE_reduc_umin_v32hi;
  ena[1033] = HAVE_reduc_umin_v16si;
  ena[1034] = HAVE_reduc_umin_v8di;
  ena[1035] = HAVE_sdot_prodv8hi;
  ena[1036] = HAVE_sdot_prodv4si;
  ena[1037] = HAVE_sdot_prodv16hi;
  ena[1038] = HAVE_sdot_prodv32hi;
  ena[1039] = HAVE_usadv16qi;
  ena[1040] = HAVE_usadv32qi;
  ena[1041] = HAVE_maskloadv4si;
  ena[1042] = HAVE_maskloadv2di;
  ena[1043] = HAVE_maskloadv8si;
  ena[1044] = HAVE_maskloadv4di;
  ena[1045] = HAVE_maskloadv4sf;
  ena[1046] = HAVE_maskloadv2df;
  ena[1047] = HAVE_maskloadv8sf;
  ena[1048] = HAVE_maskloadv4df;
  ena[1049] = HAVE_maskstorev4si;
  ena[1050] = HAVE_maskstorev2di;
  ena[1051] = HAVE_maskstorev8si;
  ena[1052] = HAVE_maskstorev4di;
  ena[1053] = HAVE_maskstorev4sf;
  ena[1054] = HAVE_maskstorev2df;
  ena[1055] = HAVE_maskstorev8sf;
  ena[1056] = HAVE_maskstorev4df;
  ena[1057] = HAVE_vec_extractv8qi;
  ena[1058] = HAVE_vec_extractv4hi;
  ena[1059] = HAVE_vec_extractv2si;
  ena[1060] = HAVE_vec_extractv16qi;
  ena[1061] = HAVE_vec_extractv8hi;
  ena[1062] = HAVE_vec_extractv4si;
  ena[1063] = HAVE_vec_extractv2di;
  ena[1064] = HAVE_vec_extractv32qi;
  ena[1065] = HAVE_vec_extractv16hi;
  ena[1066] = HAVE_vec_extractv8si;
  ena[1067] = HAVE_vec_extractv4di;
  ena[1068] = HAVE_vec_extractv64qi;
  ena[1069] = HAVE_vec_extractv32hi;
  ena[1070] = HAVE_vec_extractv16si;
  ena[1071] = HAVE_vec_extractv8di;
  ena[1072] = HAVE_vec_extractv2sf;
  ena[1073] = HAVE_vec_extractv4sf;
  ena[1074] = HAVE_vec_extractv2df;
  ena[1075] = HAVE_vec_extractv8sf;
  ena[1076] = HAVE_vec_extractv4df;
  ena[1077] = HAVE_vec_extractv16sf;
  ena[1078] = HAVE_vec_extractv8df;
  ena[1079] = HAVE_vec_initv8qi;
  ena[1080] = HAVE_vec_initv4hi;
  ena[1081] = HAVE_vec_initv2si;
  ena[1082] = HAVE_vec_initv16qi;
  ena[1083] = HAVE_vec_initv8hi;
  ena[1084] = HAVE_vec_initv4si;
  ena[1085] = HAVE_vec_initv2di;
  ena[1086] = HAVE_vec_initv32qi;
  ena[1087] = HAVE_vec_initv16hi;
  ena[1088] = HAVE_vec_initv8si;
  ena[1089] = HAVE_vec_initv4di;
  ena[1090] = HAVE_vec_initv64qi;
  ena[1091] = HAVE_vec_initv32hi;
  ena[1092] = HAVE_vec_initv16si;
  ena[1093] = HAVE_vec_initv8di;
  ena[1094] = HAVE_vec_initv2sf;
  ena[1095] = HAVE_vec_initv4sf;
  ena[1096] = HAVE_vec_initv2df;
  ena[1097] = HAVE_vec_initv8sf;
  ena[1098] = HAVE_vec_initv4df;
  ena[1099] = HAVE_vec_initv16sf;
  ena[1100] = HAVE_vec_initv8df;
  ena[1101] = HAVE_vec_pack_sfix_trunc_v2df;
  ena[1102] = HAVE_vec_pack_sfix_trunc_v4df;
  ena[1103] = HAVE_vec_pack_sfix_trunc_v8df;
  ena[1104] = HAVE_vec_pack_trunc_v8hi;
  ena[1105] = HAVE_vec_pack_trunc_v4si;
  ena[1106] = HAVE_vec_pack_trunc_v2di;
  ena[1107] = HAVE_vec_pack_trunc_v16hi;
  ena[1108] = HAVE_vec_pack_trunc_v8si;
  ena[1109] = HAVE_vec_pack_trunc_v4di;
  ena[1110] = HAVE_vec_pack_trunc_v32hi;
  ena[1111] = HAVE_vec_pack_trunc_v16si;
  ena[1112] = HAVE_vec_pack_trunc_v8di;
  ena[1113] = HAVE_vec_pack_trunc_v2df;
  ena[1114] = HAVE_vec_pack_trunc_v4df;
  ena[1115] = HAVE_vec_pack_trunc_v8df;
  ena[1116] = HAVE_vec_pack_ufix_trunc_v2df;
  ena[1117] = HAVE_vec_pack_ufix_trunc_v4df;
  ena[1118] = HAVE_vec_pack_ufix_trunc_v8df;
  ena[1119] = HAVE_vec_perm_constv16qi;
  ena[1120] = HAVE_vec_perm_constv8hi;
  ena[1121] = HAVE_vec_perm_constv4si;
  ena[1122] = HAVE_vec_perm_constv2di;
  ena[1123] = HAVE_vec_perm_constv32qi;
  ena[1124] = HAVE_vec_perm_constv16hi;
  ena[1125] = HAVE_vec_perm_constv8si;
  ena[1126] = HAVE_vec_perm_constv4di;
  ena[1127] = HAVE_vec_perm_constv64qi;
  ena[1128] = HAVE_vec_perm_constv32hi;
  ena[1129] = HAVE_vec_perm_constv16si;
  ena[1130] = HAVE_vec_perm_constv8di;
  ena[1131] = HAVE_vec_perm_constv4sf;
  ena[1132] = HAVE_vec_perm_constv2df;
  ena[1133] = HAVE_vec_perm_constv8sf;
  ena[1134] = HAVE_vec_perm_constv4df;
  ena[1135] = HAVE_vec_perm_constv16sf;
  ena[1136] = HAVE_vec_perm_constv8df;
  ena[1137] = HAVE_vec_permv16qi;
  ena[1138] = HAVE_vec_permv8hi;
  ena[1139] = HAVE_vec_permv4si;
  ena[1140] = HAVE_vec_permv2di;
  ena[1141] = HAVE_vec_permv32qi;
  ena[1142] = HAVE_vec_permv16hi;
  ena[1143] = HAVE_vec_permv8si;
  ena[1144] = HAVE_vec_permv4di;
  ena[1145] = HAVE_vec_permv64qi;
  ena[1146] = HAVE_vec_permv32hi;
  ena[1147] = HAVE_vec_permv16si;
  ena[1148] = HAVE_vec_permv8di;
  ena[1149] = HAVE_vec_permv4sf;
  ena[1150] = HAVE_vec_permv2df;
  ena[1151] = HAVE_vec_permv8sf;
  ena[1152] = HAVE_vec_permv4df;
  ena[1153] = HAVE_vec_permv16sf;
  ena[1154] = HAVE_vec_permv8df;
  ena[1155] = HAVE_vec_setv8qi;
  ena[1156] = HAVE_vec_setv4hi;
  ena[1157] = HAVE_vec_setv2si;
  ena[1158] = HAVE_vec_setv16qi;
  ena[1159] = HAVE_vec_setv8hi;
  ena[1160] = HAVE_vec_setv4si;
  ena[1161] = HAVE_vec_setv2di;
  ena[1162] = HAVE_vec_setv32qi;
  ena[1163] = HAVE_vec_setv16hi;
  ena[1164] = HAVE_vec_setv8si;
  ena[1165] = HAVE_vec_setv4di;
  ena[1166] = HAVE_vec_setv16si;
  ena[1167] = HAVE_vec_setv8di;
  ena[1168] = HAVE_vec_setv2sf;
  ena[1169] = HAVE_vec_setv4sf;
  ena[1170] = HAVE_vec_setv2df;
  ena[1171] = HAVE_vec_setv8sf;
  ena[1172] = HAVE_vec_setv4df;
  ena[1173] = HAVE_vec_setv16sf;
  ena[1174] = HAVE_vec_setv8df;
  ena[1175] = HAVE_vec_shr_v16qi;
  ena[1176] = HAVE_vec_shr_v8hi;
  ena[1177] = HAVE_vec_shr_v4si;
  ena[1178] = HAVE_vec_shr_v2di;
  ena[1179] = HAVE_vec_unpacks_float_hi_v8hi;
  ena[1180] = HAVE_vec_unpacks_float_hi_v4si;
  ena[1181] = HAVE_vec_unpacks_float_hi_v16hi;
  ena[1182] = HAVE_vec_unpacks_float_hi_v8si;
  ena[1183] = HAVE_vec_unpacks_float_hi_v32hi;
  ena[1184] = HAVE_vec_unpacks_float_hi_v16si;
  ena[1185] = HAVE_vec_unpacks_float_lo_v8hi;
  ena[1186] = HAVE_vec_unpacks_float_lo_v4si;
  ena[1187] = HAVE_vec_unpacks_float_lo_v16hi;
  ena[1188] = HAVE_vec_unpacks_float_lo_v8si;
  ena[1189] = HAVE_vec_unpacks_float_lo_v32hi;
  ena[1190] = HAVE_vec_unpacks_float_lo_v16si;
  ena[1191] = HAVE_vec_unpacks_hi_v16qi;
  ena[1192] = HAVE_vec_unpacks_hi_v8hi;
  ena[1193] = HAVE_vec_unpacks_hi_v4si;
  ena[1194] = HAVE_vec_unpacks_hi_v32qi;
  ena[1195] = HAVE_vec_unpacks_hi_v16hi;
  ena[1196] = HAVE_vec_unpacks_hi_v8si;
  ena[1197] = HAVE_vec_unpacks_hi_v64qi;
  ena[1198] = HAVE_vec_unpacks_hi_v32hi;
  ena[1199] = HAVE_vec_unpacks_hi_v16si;
  ena[1200] = HAVE_vec_unpacks_hi_v4sf;
  ena[1201] = HAVE_vec_unpacks_hi_v8sf;
  ena[1202] = HAVE_vec_unpacks_hi_v16sf;
  ena[1203] = HAVE_vec_unpacks_lo_v16qi;
  ena[1204] = HAVE_vec_unpacks_lo_v8hi;
  ena[1205] = HAVE_vec_unpacks_lo_v4si;
  ena[1206] = HAVE_vec_unpacks_lo_v32qi;
  ena[1207] = HAVE_vec_unpacks_lo_v16hi;
  ena[1208] = HAVE_vec_unpacks_lo_v8si;
  ena[1209] = HAVE_vec_unpacks_lo_v64qi;
  ena[1210] = HAVE_vec_unpacks_lo_v32hi;
  ena[1211] = HAVE_vec_unpacks_lo_v16si;
  ena[1212] = HAVE_vec_unpacks_lo_v4sf;
  ena[1213] = HAVE_vec_unpacks_lo_v8sf;
  ena[1214] = HAVE_vec_unpacks_lo_v16sf;
  ena[1215] = HAVE_vec_unpacku_float_hi_v8hi;
  ena[1216] = HAVE_vec_unpacku_float_hi_v4si;
  ena[1217] = HAVE_vec_unpacku_float_hi_v16hi;
  ena[1218] = HAVE_vec_unpacku_float_hi_v8si;
  ena[1219] = HAVE_vec_unpacku_float_hi_v32hi;
  ena[1220] = HAVE_vec_unpacku_float_hi_v16si;
  ena[1221] = HAVE_vec_unpacku_float_lo_v8hi;
  ena[1222] = HAVE_vec_unpacku_float_lo_v4si;
  ena[1223] = HAVE_vec_unpacku_float_lo_v16hi;
  ena[1224] = HAVE_vec_unpacku_float_lo_v8si;
  ena[1225] = HAVE_vec_unpacku_float_lo_v32hi;
  ena[1226] = HAVE_vec_unpacku_float_lo_v16si;
  ena[1227] = HAVE_vec_unpacku_hi_v16qi;
  ena[1228] = HAVE_vec_unpacku_hi_v8hi;
  ena[1229] = HAVE_vec_unpacku_hi_v4si;
  ena[1230] = HAVE_vec_unpacku_hi_v32qi;
  ena[1231] = HAVE_vec_unpacku_hi_v16hi;
  ena[1232] = HAVE_vec_unpacku_hi_v8si;
  ena[1233] = HAVE_vec_unpacku_hi_v64qi;
  ena[1234] = HAVE_vec_unpacku_hi_v32hi;
  ena[1235] = HAVE_vec_unpacku_hi_v16si;
  ena[1236] = HAVE_vec_unpacku_lo_v16qi;
  ena[1237] = HAVE_vec_unpacku_lo_v8hi;
  ena[1238] = HAVE_vec_unpacku_lo_v4si;
  ena[1239] = HAVE_vec_unpacku_lo_v32qi;
  ena[1240] = HAVE_vec_unpacku_lo_v16hi;
  ena[1241] = HAVE_vec_unpacku_lo_v8si;
  ena[1242] = HAVE_vec_unpacku_lo_v64qi;
  ena[1243] = HAVE_vec_unpacku_lo_v32hi;
  ena[1244] = HAVE_vec_unpacku_lo_v16si;
  ena[1245] = HAVE_vec_widen_smult_even_v4si;
  ena[1246] = HAVE_vec_widen_smult_even_v8si;
  ena[1247] = HAVE_vec_widen_smult_even_v16si;
  ena[1248] = HAVE_vec_widen_smult_hi_v16qi;
  ena[1249] = HAVE_vec_widen_smult_hi_v8hi;
  ena[1250] = HAVE_vec_widen_smult_hi_v4si;
  ena[1251] = HAVE_vec_widen_smult_hi_v32qi;
  ena[1252] = HAVE_vec_widen_smult_hi_v16hi;
  ena[1253] = HAVE_vec_widen_smult_hi_v8si;
  ena[1254] = HAVE_vec_widen_smult_lo_v16qi;
  ena[1255] = HAVE_vec_widen_smult_lo_v8hi;
  ena[1256] = HAVE_vec_widen_smult_lo_v4si;
  ena[1257] = HAVE_vec_widen_smult_lo_v32qi;
  ena[1258] = HAVE_vec_widen_smult_lo_v16hi;
  ena[1259] = HAVE_vec_widen_smult_lo_v8si;
  ena[1260] = HAVE_vec_widen_smult_odd_v4si;
  ena[1261] = HAVE_vec_widen_smult_odd_v8si;
  ena[1262] = HAVE_vec_widen_smult_odd_v16si;
  ena[1263] = HAVE_vec_widen_umult_even_v4si;
  ena[1264] = HAVE_vec_widen_umult_even_v8si;
  ena[1265] = HAVE_vec_widen_umult_even_v16si;
  ena[1266] = HAVE_vec_widen_umult_hi_v16qi;
  ena[1267] = HAVE_vec_widen_umult_hi_v8hi;
  ena[1268] = HAVE_vec_widen_umult_hi_v4si;
  ena[1269] = HAVE_vec_widen_umult_hi_v32qi;
  ena[1270] = HAVE_vec_widen_umult_hi_v16hi;
  ena[1271] = HAVE_vec_widen_umult_hi_v8si;
  ena[1272] = HAVE_vec_widen_umult_lo_v16qi;
  ena[1273] = HAVE_vec_widen_umult_lo_v8hi;
  ena[1274] = HAVE_vec_widen_umult_lo_v4si;
  ena[1275] = HAVE_vec_widen_umult_lo_v32qi;
  ena[1276] = HAVE_vec_widen_umult_lo_v16hi;
  ena[1277] = HAVE_vec_widen_umult_lo_v8si;
  ena[1278] = HAVE_vec_widen_umult_odd_v4si;
  ena[1279] = HAVE_vec_widen_umult_odd_v8si;
  ena[1280] = HAVE_vec_widen_umult_odd_v16si;
  ena[1281] = HAVE_atomic_addqi;
  ena[1282] = HAVE_atomic_addhi;
  ena[1283] = HAVE_atomic_addsi;
  ena[1284] = HAVE_atomic_adddi;
  ena[1285] = HAVE_atomic_andqi;
  ena[1286] = HAVE_atomic_andhi;
  ena[1287] = HAVE_atomic_andsi;
  ena[1288] = HAVE_atomic_anddi;
  ena[1289] = HAVE_atomic_compare_and_swapqi;
  ena[1290] = HAVE_atomic_compare_and_swaphi;
  ena[1291] = HAVE_atomic_compare_and_swapsi;
  ena[1292] = HAVE_atomic_compare_and_swapdi;
  ena[1293] = HAVE_atomic_compare_and_swapti;
  ena[1294] = HAVE_atomic_exchangeqi;
  ena[1295] = HAVE_atomic_exchangehi;
  ena[1296] = HAVE_atomic_exchangesi;
  ena[1297] = HAVE_atomic_exchangedi;
  ena[1298] = HAVE_atomic_fetch_addqi;
  ena[1299] = HAVE_atomic_fetch_addhi;
  ena[1300] = HAVE_atomic_fetch_addsi;
  ena[1301] = HAVE_atomic_fetch_adddi;
  ena[1302] = HAVE_atomic_loadqi;
  ena[1303] = HAVE_atomic_loadhi;
  ena[1304] = HAVE_atomic_loadsi;
  ena[1305] = HAVE_atomic_loaddi;
  ena[1306] = HAVE_atomic_orqi;
  ena[1307] = HAVE_atomic_orhi;
  ena[1308] = HAVE_atomic_orsi;
  ena[1309] = HAVE_atomic_ordi;
  ena[1310] = HAVE_atomic_storeqi;
  ena[1311] = HAVE_atomic_storehi;
  ena[1312] = HAVE_atomic_storesi;
  ena[1313] = HAVE_atomic_storedi;
  ena[1314] = HAVE_atomic_subqi;
  ena[1315] = HAVE_atomic_subhi;
  ena[1316] = HAVE_atomic_subsi;
  ena[1317] = HAVE_atomic_subdi;
  ena[1318] = HAVE_atomic_xorqi;
  ena[1319] = HAVE_atomic_xorhi;
  ena[1320] = HAVE_atomic_xorsi;
  ena[1321] = HAVE_atomic_xordi;
}

static int
lookup_handler (unsigned scode)
{
  int l = 0, h = ARRAY_SIZE (pats), m;
  while (h > l)
    {
      m = (h + l) / 2;
      if (scode == pats[m].scode)
        return m;
      else if (scode < pats[m].scode)
        h = m;
      else
        l = m + 1;
    }
  return -1;
}

enum insn_code
raw_optab_handler (unsigned scode)
{
  int i = lookup_handler (scode);
  return (i >= 0 && this_fn_optabs->pat_enable[i]
          ? pats[i].icode : CODE_FOR_nothing);
}

bool
swap_optab_enable (optab op, machine_mode m, bool set)
{
  unsigned scode = (op << 16) | m;
  int i = lookup_handler (scode);
  if (i >= 0)
    {
      bool ret = this_fn_optabs->pat_enable[i];
      this_fn_optabs->pat_enable[i] = set;
      return ret;
    }
  else
    {
      gcc_assert (!set);
      return false;
    }
}

const struct convert_optab_libcall_d convlib_def[NUM_CONVLIB_OPTABS] = {
  { "extend", gen_extend_conv_libfunc },
  { "trunc", gen_trunc_conv_libfunc },
  { NULL, NULL },
  { "fix", gen_fp_to_int_conv_libfunc },
  { "fixuns", gen_fp_to_int_conv_libfunc },
  { "float", gen_int_to_fp_conv_libfunc },
  { NULL, gen_ufloat_conv_libfunc },
  { "lrint", gen_int_to_fp_nondecimal_conv_libfunc },
  { "lround", gen_int_to_fp_nondecimal_conv_libfunc },
  { "lfloor", gen_int_to_fp_nondecimal_conv_libfunc },
  { "lceil", gen_int_to_fp_nondecimal_conv_libfunc },
  { "fract", gen_fract_conv_libfunc },
  { "fractuns", gen_fractuns_conv_libfunc },
  { "satfract", gen_satfract_conv_libfunc },
  { "satfractuns", gen_satfractuns_conv_libfunc },
};

const struct optab_libcall_d normlib_def[NUM_NORMLIB_OPTABS] = {
  { '3', "add", gen_int_fp_fixed_libfunc },
  { '3', "add", gen_intv_fp_libfunc },
  { '3', "ssadd", gen_signed_fixed_libfunc },
  { '3', "usadd", gen_unsigned_fixed_libfunc },
  { '3', "sub", gen_int_fp_fixed_libfunc },
  { '3', "sub", gen_intv_fp_libfunc },
  { '3', "sssub", gen_signed_fixed_libfunc },
  { '3', "ussub", gen_unsigned_fixed_libfunc },
  { '3', "mul", gen_int_fp_fixed_libfunc },
  { '3', "mul", gen_intv_fp_libfunc },
  { '3', "ssmul", gen_signed_fixed_libfunc },
  { '3', "usmul", gen_unsigned_fixed_libfunc },
  { '3', "div", gen_int_fp_signed_fixed_libfunc },
  { '3', "divv", gen_int_libfunc },
  { '3', "ssdiv", gen_signed_fixed_libfunc },
  { '3', "udiv", gen_int_unsigned_fixed_libfunc },
  { '3', "usdiv", gen_unsigned_fixed_libfunc },
  { '4', "divmod", gen_int_libfunc },
  { '4', "udivmod", gen_int_libfunc },
  { '3', "mod", gen_int_libfunc },
  { '3', "umod", gen_int_libfunc },
  { '2', "ftrunc", gen_fp_libfunc },
  { '3', "and", gen_int_libfunc },
  { '3', "ior", gen_int_libfunc },
  { '3', "xor", gen_int_libfunc },
  { '3', "ashl", gen_int_fixed_libfunc },
  { '3', "ssashl", gen_signed_fixed_libfunc },
  { '3', "usashl", gen_unsigned_fixed_libfunc },
  { '3', "ashr", gen_int_signed_fixed_libfunc },
  { '3', "lshr", gen_int_unsigned_fixed_libfunc },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '3', "min", gen_int_fp_libfunc },
  { '3', "max", gen_int_fp_libfunc },
  { '3', "umin", gen_int_libfunc },
  { '3', "umax", gen_int_libfunc },
  { '2', "neg", gen_int_fp_fixed_libfunc },
  { '2', "neg", gen_intv_fp_libfunc },
  { '2', "ssneg", gen_signed_fixed_libfunc },
  { '2', "usneg", gen_unsigned_fixed_libfunc },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '2', "one_cmpl", gen_int_libfunc },
  { '\0', NULL, NULL },
  { '2', "ffs", gen_int_libfunc },
  { '2', "clz", gen_int_libfunc },
  { '2', "ctz", gen_int_libfunc },
  { '2', "clrsb", gen_int_libfunc },
  { '2', "popcount", gen_int_libfunc },
  { '2', "parity", gen_int_libfunc },
  { '2', "cmp", gen_int_fp_fixed_libfunc },
  { '2', "ucmp", gen_int_libfunc },
  { '2', "eq", gen_fp_libfunc },
  { '2', "ne", gen_fp_libfunc },
  { '2', "gt", gen_fp_libfunc },
  { '2', "ge", gen_fp_libfunc },
  { '2', "lt", gen_fp_libfunc },
  { '2', "le", gen_fp_libfunc },
  { '2', "unord", gen_fp_libfunc },
  { '2', "powi", gen_fp_libfunc },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
  { '\0', NULL, NULL },
};

enum rtx_code const optab_to_code_[NUM_OPTABS] = {
  UNKNOWN,
  SIGN_EXTEND,
  TRUNCATE,
  ZERO_EXTEND,
  FIX,
  UNSIGNED_FIX,
  FLOAT,
  UNSIGNED_FLOAT,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  FRACT_CONVERT,
  UNSIGNED_FRACT_CONVERT,
  SAT_FRACT,
  UNSIGNED_SAT_FRACT,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  PLUS,
  PLUS,
  SS_PLUS,
  US_PLUS,
  MINUS,
  MINUS,
  SS_MINUS,
  US_MINUS,
  MULT,
  MULT,
  SS_MULT,
  US_MULT,
  DIV,
  DIV,
  SS_DIV,
  UDIV,
  US_DIV,
  UNKNOWN,
  UNKNOWN,
  MOD,
  UMOD,
  UNKNOWN,
  AND,
  IOR,
  XOR,
  ASHIFT,
  SS_ASHIFT,
  US_ASHIFT,
  ASHIFTRT,
  LSHIFTRT,
  ROTATE,
  ROTATERT,
  ASHIFT,
  ASHIFTRT,
  LSHIFTRT,
  ROTATE,
  ROTATERT,
  SMIN,
  SMAX,
  UMIN,
  UMAX,
  NEG,
  NEG,
  SS_NEG,
  US_NEG,
  ABS,
  ABS,
  NOT,
  BSWAP,
  FFS,
  CLZ,
  CTZ,
  CLRSB,
  POPCOUNT,
  PARITY,
  UNKNOWN,
  UNKNOWN,
  EQ,
  NE,
  GT,
  GE,
  LT,
  LE,
  UNORDERED,
  UNKNOWN,
  SQRT,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  SET,
  STRICT_LOW_PART,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  COMPARE,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  FMA,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
  UNKNOWN,
};

const optab code_to_optab_[NUM_RTX_CODE] = {
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  mov_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  movstrict_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  cbranch_optab,
  add_optab,
  sub_optab,
  neg_optab,
  smul_optab,
  ssmul_optab,
  usmul_optab,
  sdiv_optab,
  ssdiv_optab,
  usdiv_optab,
  smod_optab,
  udiv_optab,
  umod_optab,
  and_optab,
  ior_optab,
  xor_optab,
  one_cmpl_optab,
  ashl_optab,
  rotl_optab,
  ashr_optab,
  lshr_optab,
  rotr_optab,
  smin_optab,
  smax_optab,
  umin_optab,
  umax_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  ne_optab,
  eq_optab,
  ge_optab,
  gt_optab,
  le_optab,
  lt_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unord_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  abs_optab,
  sqrt_optab,
  bswap_optab,
  ffs_optab,
  clrsb_optab,
  clz_optab,
  ctz_optab,
  popcount_optab,
  parity_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  ssadd_optab,
  usadd_optab,
  sssub_optab,
  ssneg_optab,
  usneg_optab,
  unknown_optab,
  ssashl_optab,
  usashl_optab,
  ussub_optab,
  unknown_optab,
  unknown_optab,
  fma_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
  unknown_optab,
};

