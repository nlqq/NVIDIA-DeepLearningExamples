/* Generated automatically by the program `genpeep'
from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "insn-config.h"
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
#include "tm_p.h"
#include "regs.h"
#include "output.h"
#include "recog.h"
#include "except.h"
#include "function.h"
#include "diagnostic-core.h"
#include "flags.h"
#include "tm-constrs.h"

#ifdef HAVE_peephole
extern rtx peep_operand[];

#define operands peep_operand

rtx_insn *
peephole (rtx_insn *ins1)
{
  rtx_insn *insn ATTRIBUTE_UNUSED;
  rtx x ATTRIBUTE_UNUSED, pat ATTRIBUTE_UNUSED;

  if (NEXT_INSN (ins1)
      && BARRIER_P (NEXT_INSN (ins1)))
    return 0;

  return 0;
}

rtx peep_operand[2];
#endif
