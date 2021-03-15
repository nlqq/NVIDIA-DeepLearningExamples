/* Generated automatically by the program `genextract'
   from the machine description file `md'.  */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "tm.h"
#include "rtl.h"
#include "insn-config.h"
#include "recog.h"
#include "diagnostic-core.h"

/* This variable is used as the "location" of any missing operand
   whose numbers are skipped by a given pattern.  */
static rtx junk ATTRIBUTE_UNUSED;

void
insn_extract (rtx_insn *insn)
{
  rtx *ro = recog_data.operand;
  rtx **ro_loc = recog_data.operand_loc;
  rtx pat = PATTERN (insn);
  int i ATTRIBUTE_UNUSED; /* only for peepholes */

#ifdef ENABLE_CHECKING
  memset (ro, 0xab, sizeof (*ro) * MAX_RECOG_OPERANDS);
  memset (ro_loc, 0xab, sizeof (*ro_loc) * MAX_RECOG_OPERANDS);
#endif

  switch (INSN_CODE (insn))
    {
    default:
      /* Control reaches here if insn_extract has been called with an
         unrecognizable insn (code -1), or an insn whose INSN_CODE
         corresponds to a DEFINE_EXPAND in the machine description;
         either way, a bug.  */
      if (INSN_CODE (insn) < 0)
        fatal_insn ("unrecognizable insn:", insn);
      else
        fatal_insn ("insn with invalid code number:", insn);

    case 4952:  /* atomic_xordi */
    case 4951:  /* atomic_ordi */
    case 4950:  /* atomic_anddi */
    case 4949:  /* atomic_xorsi */
    case 4948:  /* atomic_orsi */
    case 4947:  /* atomic_andsi */
    case 4946:  /* atomic_xorhi */
    case 4945:  /* atomic_orhi */
    case 4944:  /* atomic_andhi */
    case 4943:  /* atomic_xorqi */
    case 4942:  /* atomic_orqi */
    case 4941:  /* atomic_andqi */
    case 4940:  /* atomic_subdi */
    case 4939:  /* atomic_subsi */
    case 4938:  /* atomic_subhi */
    case 4937:  /* atomic_subqi */
    case 4936:  /* atomic_adddi */
    case 4935:  /* atomic_addsi */
    case 4934:  /* atomic_addhi */
    case 4933:  /* atomic_addqi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0), 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0), 0);
      recog_data.dup_num[0] = 0;
      break;

    case 4932:  /* atomic_exchangedi */
    case 4931:  /* atomic_exchangesi */
    case 4930:  /* atomic_exchangehi */
    case 4929:  /* atomic_exchangeqi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 4928:  /* *atomic_fetch_add_cmpdi */
    case 4927:  /* *atomic_fetch_add_cmpsi */
    case 4926:  /* *atomic_fetch_add_cmphi */
    case 4925:  /* *atomic_fetch_add_cmpqi */
      ro[0] = *(ro_loc[0] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 0;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[1] = 0;
      break;

    case 4924:  /* atomic_fetch_adddi */
    case 4923:  /* atomic_fetch_addsi */
    case 4922:  /* atomic_fetch_addhi */
    case 4921:  /* atomic_fetch_addqi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[1] = 1;
      break;

    case 4920:  /* atomic_compare_and_swapdi_1 */
    case 4919:  /* atomic_compare_and_swapsi_1 */
    case 4918:  /* atomic_compare_and_swaphi_1 */
    case 4917:  /* atomic_compare_and_swapqi_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 4916:  /* atomic_compare_and_swapti_doubleword */
    case 4915:  /* atomic_compare_and_swapdi_doubleword */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 4));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 4906:  /* mfence_nosse */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0);
      recog_data.dup_num[0] = 0;
      break;

    case 4807:  /* avx512dq_vmfpclassv2df */
    case 4806:  /* avx512dq_vmfpclassv4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      break;

    case 4761:  /* avx512vl_compressstorev2df_mask */
    case 4760:  /* avx512vl_compressstorev2di_mask */
    case 4759:  /* avx512vl_compressstorev4sf_mask */
    case 4758:  /* avx512vl_compressstorev4si_mask */
    case 4757:  /* avx512vl_compressstorev4df_mask */
    case 4756:  /* avx512vl_compressstorev4di_mask */
    case 4755:  /* avx512vl_compressstorev8sf_mask */
    case 4754:  /* avx512vl_compressstorev8si_mask */
    case 4753:  /* avx512f_compressstorev8df_mask */
    case 4752:  /* avx512f_compressstorev8di_mask */
    case 4751:  /* avx512f_compressstorev16sf_mask */
    case 4750:  /* avx512f_compressstorev16si_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 2));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (pat, 1), 0, 1);
      recog_data.dup_num[0] = 0;
      break;

    case 4737:  /* *avx512f_scatterdiv2df */
    case 4736:  /* *avx512f_scatterdiv2df */
    case 4735:  /* *avx512f_scatterdiv2di */
    case 4734:  /* *avx512f_scatterdiv2di */
    case 4733:  /* *avx512f_scatterdiv4sf */
    case 4732:  /* *avx512f_scatterdiv4sf */
    case 4731:  /* *avx512f_scatterdiv4si */
    case 4730:  /* *avx512f_scatterdiv4si */
    case 4729:  /* *avx512f_scatterdiv4df */
    case 4728:  /* *avx512f_scatterdiv4df */
    case 4727:  /* *avx512f_scatterdiv4di */
    case 4726:  /* *avx512f_scatterdiv4di */
    case 4725:  /* *avx512f_scatterdiv8sf */
    case 4724:  /* *avx512f_scatterdiv8sf */
    case 4723:  /* *avx512f_scatterdiv8si */
    case 4722:  /* *avx512f_scatterdiv8si */
    case 4721:  /* *avx512f_scatterdiv8df */
    case 4720:  /* *avx512f_scatterdiv8df */
    case 4719:  /* *avx512f_scatterdiv8di */
    case 4718:  /* *avx512f_scatterdiv8di */
    case 4717:  /* *avx512f_scatterdiv16sf */
    case 4716:  /* *avx512f_scatterdiv16sf */
    case 4715:  /* *avx512f_scatterdiv16si */
    case 4714:  /* *avx512f_scatterdiv16si */
    case 4713:  /* *avx512f_scattersiv2df */
    case 4712:  /* *avx512f_scattersiv2df */
    case 4711:  /* *avx512f_scattersiv2di */
    case 4710:  /* *avx512f_scattersiv2di */
    case 4709:  /* *avx512f_scattersiv4sf */
    case 4708:  /* *avx512f_scattersiv4sf */
    case 4707:  /* *avx512f_scattersiv4si */
    case 4706:  /* *avx512f_scattersiv4si */
    case 4705:  /* *avx512f_scattersiv4df */
    case 4704:  /* *avx512f_scattersiv4df */
    case 4703:  /* *avx512f_scattersiv4di */
    case 4702:  /* *avx512f_scattersiv4di */
    case 4701:  /* *avx512f_scattersiv8sf */
    case 4700:  /* *avx512f_scattersiv8sf */
    case 4699:  /* *avx512f_scattersiv8si */
    case 4698:  /* *avx512f_scattersiv8si */
    case 4697:  /* *avx512f_scattersiv8df */
    case 4696:  /* *avx512f_scattersiv8df */
    case 4695:  /* *avx512f_scattersiv8di */
    case 4694:  /* *avx512f_scattersiv8di */
    case 4693:  /* *avx512f_scattersiv16sf */
    case 4692:  /* *avx512f_scattersiv16sf */
    case 4691:  /* *avx512f_scattersiv16si */
    case 4690:  /* *avx512f_scattersiv16si */
      ro[0] = *(ro_loc[0] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0), 0, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0), 0, 2));
      ro[5] = *(ro_loc[5] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      break;

    case 4689:  /* *avx512f_gatherdiv2df_2 */
    case 4688:  /* *avx512f_gatherdiv2df_2 */
    case 4687:  /* *avx512f_gatherdiv2di_2 */
    case 4686:  /* *avx512f_gatherdiv2di_2 */
    case 4685:  /* *avx512f_gatherdiv4sf_2 */
    case 4684:  /* *avx512f_gatherdiv4sf_2 */
    case 4683:  /* *avx512f_gatherdiv4si_2 */
    case 4682:  /* *avx512f_gatherdiv4si_2 */
    case 4681:  /* *avx512f_gatherdiv4df_2 */
    case 4680:  /* *avx512f_gatherdiv4df_2 */
    case 4679:  /* *avx512f_gatherdiv4di_2 */
    case 4678:  /* *avx512f_gatherdiv4di_2 */
    case 4677:  /* *avx512f_gatherdiv8sf_2 */
    case 4676:  /* *avx512f_gatherdiv8sf_2 */
    case 4675:  /* *avx512f_gatherdiv8si_2 */
    case 4674:  /* *avx512f_gatherdiv8si_2 */
    case 4673:  /* *avx512f_gatherdiv8df_2 */
    case 4672:  /* *avx512f_gatherdiv8df_2 */
    case 4671:  /* *avx512f_gatherdiv8di_2 */
    case 4670:  /* *avx512f_gatherdiv8di_2 */
    case 4669:  /* *avx512f_gatherdiv16sf_2 */
    case 4668:  /* *avx512f_gatherdiv16sf_2 */
    case 4667:  /* *avx512f_gatherdiv16si_2 */
    case 4666:  /* *avx512f_gatherdiv16si_2 */
    case 4641:  /* *avx512f_gathersiv2df_2 */
    case 4640:  /* *avx512f_gathersiv2df_2 */
    case 4639:  /* *avx512f_gathersiv2di_2 */
    case 4638:  /* *avx512f_gathersiv2di_2 */
    case 4637:  /* *avx512f_gathersiv4sf_2 */
    case 4636:  /* *avx512f_gathersiv4sf_2 */
    case 4635:  /* *avx512f_gathersiv4si_2 */
    case 4634:  /* *avx512f_gathersiv4si_2 */
    case 4633:  /* *avx512f_gathersiv4df_2 */
    case 4632:  /* *avx512f_gathersiv4df_2 */
    case 4631:  /* *avx512f_gathersiv4di_2 */
    case 4630:  /* *avx512f_gathersiv4di_2 */
    case 4629:  /* *avx512f_gathersiv8sf_2 */
    case 4628:  /* *avx512f_gathersiv8sf_2 */
    case 4627:  /* *avx512f_gathersiv8si_2 */
    case 4626:  /* *avx512f_gathersiv8si_2 */
    case 4625:  /* *avx512f_gathersiv8df_2 */
    case 4624:  /* *avx512f_gathersiv8df_2 */
    case 4623:  /* *avx512f_gathersiv8di_2 */
    case 4622:  /* *avx512f_gathersiv8di_2 */
    case 4621:  /* *avx512f_gathersiv16sf_2 */
    case 4620:  /* *avx512f_gathersiv16sf_2 */
    case 4619:  /* *avx512f_gathersiv16si_2 */
    case 4618:  /* *avx512f_gathersiv16si_2 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2), 0), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2), 0), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      break;

    case 4665:  /* *avx512f_gatherdiv2df */
    case 4664:  /* *avx512f_gatherdiv2df */
    case 4663:  /* *avx512f_gatherdiv2di */
    case 4662:  /* *avx512f_gatherdiv2di */
    case 4661:  /* *avx512f_gatherdiv4sf */
    case 4660:  /* *avx512f_gatherdiv4sf */
    case 4659:  /* *avx512f_gatherdiv4si */
    case 4658:  /* *avx512f_gatherdiv4si */
    case 4657:  /* *avx512f_gatherdiv4df */
    case 4656:  /* *avx512f_gatherdiv4df */
    case 4655:  /* *avx512f_gatherdiv4di */
    case 4654:  /* *avx512f_gatherdiv4di */
    case 4653:  /* *avx512f_gatherdiv8sf */
    case 4652:  /* *avx512f_gatherdiv8sf */
    case 4651:  /* *avx512f_gatherdiv8si */
    case 4650:  /* *avx512f_gatherdiv8si */
    case 4649:  /* *avx512f_gatherdiv8df */
    case 4648:  /* *avx512f_gatherdiv8df */
    case 4647:  /* *avx512f_gatherdiv8di */
    case 4646:  /* *avx512f_gatherdiv8di */
    case 4645:  /* *avx512f_gatherdiv16sf */
    case 4644:  /* *avx512f_gatherdiv16sf */
    case 4643:  /* *avx512f_gatherdiv16si */
    case 4642:  /* *avx512f_gatherdiv16si */
    case 4617:  /* *avx512f_gathersiv2df */
    case 4616:  /* *avx512f_gathersiv2df */
    case 4615:  /* *avx512f_gathersiv2di */
    case 4614:  /* *avx512f_gathersiv2di */
    case 4613:  /* *avx512f_gathersiv4sf */
    case 4612:  /* *avx512f_gathersiv4sf */
    case 4611:  /* *avx512f_gathersiv4si */
    case 4610:  /* *avx512f_gathersiv4si */
    case 4609:  /* *avx512f_gathersiv4df */
    case 4608:  /* *avx512f_gathersiv4df */
    case 4607:  /* *avx512f_gathersiv4di */
    case 4606:  /* *avx512f_gathersiv4di */
    case 4605:  /* *avx512f_gathersiv8sf */
    case 4604:  /* *avx512f_gathersiv8sf */
    case 4603:  /* *avx512f_gathersiv8si */
    case 4602:  /* *avx512f_gathersiv8si */
    case 4601:  /* *avx512f_gathersiv8df */
    case 4600:  /* *avx512f_gathersiv8df */
    case 4599:  /* *avx512f_gathersiv8di */
    case 4598:  /* *avx512f_gathersiv8di */
    case 4597:  /* *avx512f_gathersiv16sf */
    case 4596:  /* *avx512f_gathersiv16sf */
    case 4595:  /* *avx512f_gathersiv16si */
    case 4594:  /* *avx512f_gathersiv16si */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2), 0), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2), 0), 0, 0));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2), 0), 0, 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      break;

    case 4593:  /* *avx2_gatherdiv8sf_4 */
    case 4592:  /* *avx2_gatherdiv8sf_4 */
    case 4591:  /* *avx2_gatherdiv8si_4 */
    case 4590:  /* *avx2_gatherdiv8si_4 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1), 0), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1), 0), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 3));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1), 0), 0, 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      break;

    case 4589:  /* *avx2_gatherdiv8sf_3 */
    case 4588:  /* *avx2_gatherdiv8sf_3 */
    case 4587:  /* *avx2_gatherdiv8si_3 */
    case 4586:  /* *avx2_gatherdiv8si_3 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1), 0), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1), 0), 0, 1));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1), 0), 0, 2));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      break;

    case 4585:  /* *avx2_gatherdiv8sf_2 */
    case 4584:  /* *avx2_gatherdiv8sf_2 */
    case 4583:  /* *avx2_gatherdiv8si_2 */
    case 4582:  /* *avx2_gatherdiv8si_2 */
    case 4581:  /* *avx2_gatherdiv4sf_2 */
    case 4580:  /* *avx2_gatherdiv4sf_2 */
    case 4579:  /* *avx2_gatherdiv4si_2 */
    case 4578:  /* *avx2_gatherdiv4si_2 */
    case 4577:  /* *avx2_gatherdiv4df_2 */
    case 4576:  /* *avx2_gatherdiv4df_2 */
    case 4575:  /* *avx2_gatherdiv4di_2 */
    case 4574:  /* *avx2_gatherdiv4di_2 */
    case 4573:  /* *avx2_gatherdiv2df_2 */
    case 4572:  /* *avx2_gatherdiv2df_2 */
    case 4571:  /* *avx2_gatherdiv2di_2 */
    case 4570:  /* *avx2_gatherdiv2di_2 */
    case 4553:  /* *avx2_gathersiv8sf_2 */
    case 4552:  /* *avx2_gathersiv8sf_2 */
    case 4551:  /* *avx2_gathersiv8si_2 */
    case 4550:  /* *avx2_gathersiv8si_2 */
    case 4549:  /* *avx2_gathersiv4sf_2 */
    case 4548:  /* *avx2_gathersiv4sf_2 */
    case 4547:  /* *avx2_gathersiv4si_2 */
    case 4546:  /* *avx2_gathersiv4si_2 */
    case 4545:  /* *avx2_gathersiv4df_2 */
    case 4544:  /* *avx2_gathersiv4df_2 */
    case 4543:  /* *avx2_gathersiv4di_2 */
    case 4542:  /* *avx2_gathersiv4di_2 */
    case 4541:  /* *avx2_gathersiv2df_2 */
    case 4540:  /* *avx2_gathersiv2df_2 */
    case 4539:  /* *avx2_gathersiv2di_2 */
    case 4538:  /* *avx2_gathersiv2di_2 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1), 0), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1), 0), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1), 0), 0, 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      break;

    case 4569:  /* *avx2_gatherdiv8sf */
    case 4568:  /* *avx2_gatherdiv8sf */
    case 4567:  /* *avx2_gatherdiv8si */
    case 4566:  /* *avx2_gatherdiv8si */
    case 4565:  /* *avx2_gatherdiv4sf */
    case 4564:  /* *avx2_gatherdiv4sf */
    case 4563:  /* *avx2_gatherdiv4si */
    case 4562:  /* *avx2_gatherdiv4si */
    case 4561:  /* *avx2_gatherdiv4df */
    case 4560:  /* *avx2_gatherdiv4df */
    case 4559:  /* *avx2_gatherdiv4di */
    case 4558:  /* *avx2_gatherdiv4di */
    case 4557:  /* *avx2_gatherdiv2df */
    case 4556:  /* *avx2_gatherdiv2df */
    case 4555:  /* *avx2_gatherdiv2di */
    case 4554:  /* *avx2_gatherdiv2di */
    case 4537:  /* *avx2_gathersiv8sf */
    case 4536:  /* *avx2_gathersiv8sf */
    case 4535:  /* *avx2_gathersiv8si */
    case 4534:  /* *avx2_gathersiv8si */
    case 4533:  /* *avx2_gathersiv4sf */
    case 4532:  /* *avx2_gathersiv4sf */
    case 4531:  /* *avx2_gathersiv4si */
    case 4530:  /* *avx2_gathersiv4si */
    case 4529:  /* *avx2_gathersiv4df */
    case 4528:  /* *avx2_gathersiv4df */
    case 4527:  /* *avx2_gathersiv4di */
    case 4526:  /* *avx2_gathersiv4di */
    case 4525:  /* *avx2_gathersiv2df */
    case 4524:  /* *avx2_gathersiv2df */
    case 4523:  /* *avx2_gathersiv2di */
    case 4522:  /* *avx2_gathersiv2di */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1), 0), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1), 0), 0, 1));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1), 0), 0, 2));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      break;

    case 4516:  /* *vcvtps2ph_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 4435:  /* avx2_maskstoreq256 */
    case 4434:  /* avx2_maskstored256 */
    case 4433:  /* avx2_maskstoreq */
    case 4432:  /* avx2_maskstored */
    case 4431:  /* avx_maskstorepd256 */
    case 4430:  /* avx_maskstoreps256 */
    case 4429:  /* avx_maskstorepd */
    case 4428:  /* avx_maskstoreps */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (pat, 1), 0, 2);
      recog_data.dup_num[0] = 0;
      break;

    case 4427:  /* avx2_maskloadq256 */
    case 4426:  /* avx2_maskloadd256 */
    case 4425:  /* avx2_maskloadq */
    case 4424:  /* avx2_maskloadd */
    case 4423:  /* avx_maskloadpd256 */
    case 4422:  /* avx_maskloadps256 */
    case 4421:  /* avx_maskloadpd */
    case 4420:  /* avx_maskloadps */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 0));
      break;

    case 4393:  /* *avx_vperm2f128v4df_nozero */
    case 4392:  /* *avx_vperm2f128v8sf_nozero */
    case 4391:  /* *avx_vperm2f128v8si_nozero */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      break;

    case 4387:  /* avx512bw_vpermt2varv32hi3_mask */
    case 4386:  /* avx512vl_vpermt2varv16hi3_mask */
    case 4385:  /* avx512vl_vpermt2varv8hi3_mask */
    case 4384:  /* avx512vl_vpermt2varv32qi3_mask */
    case 4383:  /* avx512vl_vpermt2varv16qi3_mask */
    case 4382:  /* avx512bw_vpermt2varv64qi3_mask */
    case 4381:  /* avx512vl_vpermt2varv2df3_mask */
    case 4380:  /* avx512vl_vpermt2varv2di3_mask */
    case 4379:  /* avx512vl_vpermt2varv4sf3_mask */
    case 4378:  /* avx512vl_vpermt2varv4si3_mask */
    case 4377:  /* avx512vl_vpermt2varv4df3_mask */
    case 4376:  /* avx512vl_vpermt2varv4di3_mask */
    case 4375:  /* avx512vl_vpermt2varv8sf3_mask */
    case 4374:  /* avx512vl_vpermt2varv8si3_mask */
    case 4373:  /* avx512f_vpermt2varv8df3_mask */
    case 4372:  /* avx512f_vpermt2varv8di3_mask */
    case 4371:  /* avx512f_vpermt2varv16sf3_mask */
    case 4370:  /* avx512f_vpermt2varv16si3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 2;
      break;

    case 4333:  /* avx512bw_vpermi2varv32hi3_mask */
    case 4332:  /* avx512vl_vpermi2varv16hi3_mask */
    case 4331:  /* avx512vl_vpermi2varv8hi3_mask */
    case 4330:  /* avx512vl_vpermi2varv32qi3_mask */
    case 4329:  /* avx512vl_vpermi2varv16qi3_mask */
    case 4328:  /* avx512bw_vpermi2varv64qi3_mask */
    case 4327:  /* avx512vl_vpermi2varv2df3_mask */
    case 4326:  /* avx512vl_vpermi2varv2di3_mask */
    case 4325:  /* avx512vl_vpermi2varv4sf3_mask */
    case 4324:  /* avx512vl_vpermi2varv4si3_mask */
    case 4323:  /* avx512vl_vpermi2varv4df3_mask */
    case 4322:  /* avx512vl_vpermi2varv4di3_mask */
    case 4321:  /* avx512vl_vpermi2varv8sf3_mask */
    case 4320:  /* avx512vl_vpermi2varv8si3_mask */
    case 4319:  /* avx512f_vpermi2varv8df3_mask */
    case 4318:  /* avx512f_vpermi2varv8di3_mask */
    case 4317:  /* avx512f_vpermi2varv16sf3_mask */
    case 4316:  /* avx512f_vpermi2varv16si3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 0;
      break;

    case 4267:  /* *avx_vpermilpv2df_mask */
    case 4265:  /* *avx_vpermilpv4df_mask */
    case 4263:  /* *avx512f_vpermilpv8df_mask */
    case 4261:  /* *avx_vpermilpv4sf_mask */
    case 4259:  /* *avx_vpermilpv8sf_mask */
    case 4257:  /* *avx512f_vpermilpv16sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 4399:  /* *ssse3_palignrv2df_perm */
    case 4398:  /* *ssse3_palignrv4sf_perm */
    case 4397:  /* *ssse3_palignrv2di_perm */
    case 4396:  /* *ssse3_palignrv4si_perm */
    case 4395:  /* *ssse3_palignrv8hi_perm */
    case 4394:  /* *ssse3_palignrv16qi_perm */
    case 4266:  /* *avx_vpermilpv2df */
    case 4264:  /* *avx_vpermilpv4df */
    case 4262:  /* *avx512f_vpermilpv8df */
    case 4260:  /* *avx_vpermilpv4sf */
    case 4258:  /* *avx_vpermilpv8sf */
    case 4256:  /* *avx512f_vpermilpv16sf */
    case 4255:  /* *avx_vperm_broadcast_v4df */
    case 4254:  /* *avx_vperm_broadcast_v8sf */
    case 4253:  /* *avx_vperm_broadcast_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      break;

    case 4220:  /* avx_vbroadcastf128_v4df */
    case 4219:  /* avx_vbroadcastf128_v8sf */
    case 4218:  /* avx_vbroadcastf128_v4di */
    case 4217:  /* avx_vbroadcastf128_v8si */
    case 4216:  /* avx_vbroadcastf128_v16hi */
    case 4215:  /* avx_vbroadcastf128_v32qi */
    case 4204:  /* avx2_vbroadcasti128_v4di */
    case 4203:  /* avx2_vbroadcasti128_v8si */
    case 4202:  /* avx2_vbroadcasti128_v16hi */
    case 4201:  /* avx2_vbroadcasti128_v32qi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 4042:  /* xop_maskcmp_uns2v2di3 */
    case 4041:  /* xop_maskcmp_uns2v4si3 */
    case 4040:  /* xop_maskcmp_uns2v8hi3 */
    case 4039:  /* xop_maskcmp_uns2v16qi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 1));
      break;

    case 4038:  /* xop_maskcmp_unsv2di3 */
    case 4037:  /* xop_maskcmp_unsv4si3 */
    case 4036:  /* xop_maskcmp_unsv8hi3 */
    case 4035:  /* xop_maskcmp_unsv16qi3 */
    case 4034:  /* xop_maskcmpv2di3 */
    case 4033:  /* xop_maskcmpv4si3 */
    case 4032:  /* xop_maskcmpv8hi3 */
    case 4031:  /* xop_maskcmpv16qi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (pat, 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 4022:  /* xop_shlv2di3 */
    case 4021:  /* xop_shlv4si3 */
    case 4020:  /* xop_shlv8hi3 */
    case 4019:  /* xop_shlv16qi3 */
    case 4018:  /* xop_shav2di3 */
    case 4017:  /* xop_shav4si3 */
    case 4016:  /* xop_shav8hi3 */
    case 4015:  /* xop_shav16qi3 */
    case 4014:  /* xop_vrotlv2di3 */
    case 4013:  /* xop_vrotlv4si3 */
    case 4012:  /* xop_vrotlv8hi3 */
    case 4011:  /* xop_vrotlv16qi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 1), 1);
      recog_data.dup_num[0] = 2;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 2), 0);
      recog_data.dup_num[1] = 1;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 2), 1), 0);
      recog_data.dup_num[2] = 2;
      break;

    case 4002:  /* xop_pperm_pack_v8hi_v16qi */
    case 4001:  /* xop_pperm_pack_v4si_v8hi */
    case 4000:  /* xop_pperm_pack_v2di_v4si */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 3989:  /* xop_phaddubq */
    case 3988:  /* xop_phaddbq */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0), 0);
      recog_data.dup_num[1] = 1;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 0), 0);
      recog_data.dup_num[2] = 1;
      recog_data.dup_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 0), 0);
      recog_data.dup_num[3] = 1;
      recog_data.dup_loc[4] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 0), 0);
      recog_data.dup_num[4] = 1;
      recog_data.dup_loc[5] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 0), 0);
      recog_data.dup_num[5] = 1;
      recog_data.dup_loc[6] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 0), 0);
      recog_data.dup_num[6] = 1;
      break;

    case 3993:  /* xop_phadduwq */
    case 3992:  /* xop_phaddwq */
    case 3987:  /* xop_phaddubd */
    case 3986:  /* xop_phaddbd */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 0);
      recog_data.dup_num[1] = 1;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 0);
      recog_data.dup_num[2] = 1;
      break;

    case 3998:  /* xop_phsubdq */
    case 3997:  /* xop_phsubwd */
    case 3996:  /* xop_phsubbw */
    case 3995:  /* xop_phaddudq */
    case 3994:  /* xop_phadddq */
    case 3991:  /* xop_phadduwd */
    case 3990:  /* xop_phaddwd */
    case 3985:  /* xop_phaddubw */
    case 3984:  /* xop_phaddbw */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 3983:  /* xop_pcmov_v2df */
    case 3982:  /* xop_pcmov_v4df256 */
    case 3981:  /* xop_pcmov_v8df512 */
    case 3980:  /* xop_pcmov_v4sf */
    case 3979:  /* xop_pcmov_v8sf256 */
    case 3978:  /* xop_pcmov_v16sf512 */
    case 3977:  /* xop_pcmov_v2di */
    case 3976:  /* xop_pcmov_v4di256 */
    case 3975:  /* xop_pcmov_v8di512 */
    case 3974:  /* xop_pcmov_v4si */
    case 3973:  /* xop_pcmov_v8si256 */
    case 3972:  /* xop_pcmov_v16si512 */
    case 3971:  /* xop_pcmov_v8hi */
    case 3970:  /* xop_pcmov_v16hi256 */
    case 3969:  /* xop_pcmov_v16qi */
    case 3968:  /* xop_pcmov_v32qi256 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 2));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 3967:  /* xop_pmadcsswd */
    case 3966:  /* xop_pmadcswd */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 0), 0);
      recog_data.dup_num[1] = 2;
      break;

    case 3965:  /* xop_pmacsswd */
    case 3964:  /* xop_pmacswd */
    case 3963:  /* xop_pmacssdqh */
    case 3962:  /* xop_pmacsdqh */
    case 3961:  /* xop_pmacssdql */
    case 3960:  /* xop_pmacsdql */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 3955:  /* avx512er_vmrsqrt28v2df_round */
    case 3953:  /* avx512er_vmrsqrt28v4sf_round */
    case 3943:  /* avx512er_vmrcp28v2df_round */
    case 3941:  /* avx512er_vmrcp28v4sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 3923:  /* *avx512pf_scatterpfv8didf_mask */
    case 3922:  /* *avx512pf_scatterpfv8didf_mask */
    case 3921:  /* *avx512pf_scatterpfv8sidf_mask */
    case 3920:  /* *avx512pf_scatterpfv8sidf_mask */
    case 3919:  /* *avx512pf_scatterpfv8disf_mask */
    case 3918:  /* *avx512pf_scatterpfv8disf_mask */
    case 3917:  /* *avx512pf_scatterpfv16sisf_mask */
    case 3916:  /* *avx512pf_scatterpfv16sisf_mask */
    case 3915:  /* *avx512pf_gatherpfv8didf_mask */
    case 3914:  /* *avx512pf_gatherpfv8didf_mask */
    case 3913:  /* *avx512pf_gatherpfv8sidf_mask */
    case 3912:  /* *avx512pf_gatherpfv8sidf_mask */
    case 3911:  /* *avx512pf_gatherpfv8disf_mask */
    case 3910:  /* *avx512pf_gatherpfv8disf_mask */
    case 3909:  /* *avx512pf_gatherpfv16sisf_mask */
    case 3908:  /* *avx512pf_gatherpfv16sisf_mask */
      ro[0] = *(ro_loc[0] = &XVECEXP (pat, 0, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 0), 0, 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 0), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (pat, 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (pat, 0, 1));
      break;

    case 3907:  /* sse4_2_pcmpistr_cconly */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      break;

    case 3906:  /* sse4_2_pcmpistrm */
    case 3905:  /* sse4_2_pcmpistri */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 2);
      recog_data.dup_num[0] = 3;
      recog_data.dup_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1);
      recog_data.dup_num[1] = 2;
      recog_data.dup_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[2] = 1;
      break;

    case 3904:  /* *sse4_2_pcmpistr_unaligned */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 2);
      recog_data.dup_num[0] = 4;
      recog_data.dup_loc[1] = &XVECEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 1), 0, 0);
      recog_data.dup_num[1] = 3;
      recog_data.dup_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 0);
      recog_data.dup_num[2] = 2;
      recog_data.dup_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 2);
      recog_data.dup_num[3] = 4;
      recog_data.dup_loc[4] = &XVECEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1), 0, 0);
      recog_data.dup_num[4] = 3;
      recog_data.dup_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[5] = 2;
      break;

    case 3903:  /* sse4_2_pcmpistr */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 2);
      recog_data.dup_num[0] = 4;
      recog_data.dup_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 1);
      recog_data.dup_num[1] = 3;
      recog_data.dup_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 0);
      recog_data.dup_num[2] = 2;
      recog_data.dup_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 2);
      recog_data.dup_num[3] = 4;
      recog_data.dup_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1);
      recog_data.dup_num[4] = 3;
      recog_data.dup_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[5] = 2;
      break;

    case 3902:  /* sse4_2_pcmpestr_cconly */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 4));
      break;

    case 3901:  /* sse4_2_pcmpestrm */
    case 3900:  /* sse4_2_pcmpestri */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 4));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 4);
      recog_data.dup_num[0] = 5;
      recog_data.dup_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 3);
      recog_data.dup_num[1] = 4;
      recog_data.dup_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 2);
      recog_data.dup_num[2] = 3;
      recog_data.dup_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1);
      recog_data.dup_num[3] = 2;
      recog_data.dup_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[4] = 1;
      break;

    case 3899:  /* *sse4_2_pcmpestr_unaligned */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2), 0, 0));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 4));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 4);
      recog_data.dup_num[0] = 6;
      recog_data.dup_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 3);
      recog_data.dup_num[1] = 5;
      recog_data.dup_loc[2] = &XVECEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 2), 0, 0);
      recog_data.dup_num[2] = 4;
      recog_data.dup_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 1);
      recog_data.dup_num[3] = 3;
      recog_data.dup_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 0);
      recog_data.dup_num[4] = 2;
      recog_data.dup_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 4);
      recog_data.dup_num[5] = 6;
      recog_data.dup_loc[6] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 3);
      recog_data.dup_num[6] = 5;
      recog_data.dup_loc[7] = &XVECEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 2), 0, 0);
      recog_data.dup_num[7] = 4;
      recog_data.dup_loc[8] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1);
      recog_data.dup_num[8] = 3;
      recog_data.dup_loc[9] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[9] = 2;
      break;

    case 3898:  /* sse4_2_pcmpestr */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 4));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 4);
      recog_data.dup_num[0] = 6;
      recog_data.dup_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 3);
      recog_data.dup_num[1] = 5;
      recog_data.dup_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 2);
      recog_data.dup_num[2] = 4;
      recog_data.dup_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 1);
      recog_data.dup_num[3] = 3;
      recog_data.dup_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 0);
      recog_data.dup_num[4] = 2;
      recog_data.dup_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 4);
      recog_data.dup_num[5] = 6;
      recog_data.dup_loc[6] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 3);
      recog_data.dup_num[6] = 5;
      recog_data.dup_loc[7] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 2);
      recog_data.dup_num[7] = 4;
      recog_data.dup_loc[8] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1);
      recog_data.dup_num[8] = 3;
      recog_data.dup_loc[9] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[9] = 2;
      break;

    case 3897:  /* sse4_1_roundsd */
    case 3896:  /* sse4_1_roundss */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      break;

    case 3891:  /* sse4_1_ptest */
    case 3890:  /* avx_ptest256 */
    case 3889:  /* avx_vtestpd */
    case 3888:  /* avx_vtestpd256 */
    case 3887:  /* avx_vtestps */
    case 3886:  /* avx_vtestps256 */
      ro[0] = *(ro_loc[0] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 1));
      break;

    case 3724:  /* *ssse3_pmulhrswv8hi3_mask */
    case 3722:  /* *avx2_pmulhrswv16hi3_mask */
    case 3720:  /* *avx512bw_pmulhrswv32hi3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3725:  /* *ssse3_pmulhrswv4hi3 */
    case 3723:  /* *ssse3_pmulhrswv8hi3 */
    case 3721:  /* *avx2_pmulhrswv16hi3 */
    case 3719:  /* *avx512bw_pmulhrswv32hi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1));
      break;

    case 3716:  /* avx512bw_umulhrswv32hi3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3715:  /* avx512bw_umulhrswv32hi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 1), 0));
      break;

    case 3703:  /* avx2_phsubdv8si3 */
    case 3702:  /* avx2_phadddv8si3 */
    case 3697:  /* ssse3_phsubswv8hi3 */
    case 3696:  /* ssse3_phsubwv8hi3 */
    case 3695:  /* ssse3_phaddswv8hi3 */
    case 3694:  /* ssse3_phaddwv8hi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0), 0);
      recog_data.dup_num[1] = 1;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 1), 0);
      recog_data.dup_num[2] = 1;
      recog_data.dup_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0), 0);
      recog_data.dup_num[3] = 1;
      recog_data.dup_loc[4] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 1), 0);
      recog_data.dup_num[4] = 1;
      recog_data.dup_loc[5] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 0), 0);
      recog_data.dup_num[5] = 1;
      recog_data.dup_loc[6] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 1), 0);
      recog_data.dup_num[6] = 1;
      recog_data.dup_loc[7] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 1), 0);
      recog_data.dup_num[7] = 2;
      recog_data.dup_loc[8] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 0), 0);
      recog_data.dup_num[8] = 2;
      recog_data.dup_loc[9] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 1), 0);
      recog_data.dup_num[9] = 2;
      recog_data.dup_loc[10] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 0), 0);
      recog_data.dup_num[10] = 2;
      recog_data.dup_loc[11] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 1), 0);
      recog_data.dup_num[11] = 2;
      recog_data.dup_loc[12] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 0), 0);
      recog_data.dup_num[12] = 2;
      recog_data.dup_loc[13] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 1), 0);
      recog_data.dup_num[13] = 2;
      break;

    case 3693:  /* avx2_phsubswv16hi3 */
    case 3692:  /* avx2_phsubwv16hi3 */
    case 3691:  /* avx2_phaddswv16hi3 */
    case 3690:  /* avx2_phaddwv16hi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 1), 0), 0);
      recog_data.dup_num[1] = 1;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 1), 1), 0);
      recog_data.dup_num[2] = 1;
      recog_data.dup_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0), 0), 0);
      recog_data.dup_num[3] = 1;
      recog_data.dup_loc[4] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0), 1), 0);
      recog_data.dup_num[4] = 1;
      recog_data.dup_loc[5] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 1), 0), 0);
      recog_data.dup_num[5] = 1;
      recog_data.dup_loc[6] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 1), 1), 0);
      recog_data.dup_num[6] = 1;
      recog_data.dup_loc[7] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0), 0), 0);
      recog_data.dup_num[7] = 1;
      recog_data.dup_loc[8] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0), 1), 0);
      recog_data.dup_num[8] = 1;
      recog_data.dup_loc[9] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 1), 0), 0);
      recog_data.dup_num[9] = 1;
      recog_data.dup_loc[10] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 1), 1), 0);
      recog_data.dup_num[10] = 1;
      recog_data.dup_loc[11] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 0), 0), 0);
      recog_data.dup_num[11] = 1;
      recog_data.dup_loc[12] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 0), 1), 0);
      recog_data.dup_num[12] = 1;
      recog_data.dup_loc[13] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 1), 0), 0);
      recog_data.dup_num[13] = 1;
      recog_data.dup_loc[14] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 1), 1), 0);
      recog_data.dup_num[14] = 1;
      recog_data.dup_loc[15] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 0), 1), 0);
      recog_data.dup_num[15] = 2;
      recog_data.dup_loc[16] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 1), 0), 0);
      recog_data.dup_num[16] = 2;
      recog_data.dup_loc[17] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 1), 1), 0);
      recog_data.dup_num[17] = 2;
      recog_data.dup_loc[18] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 0), 0), 0);
      recog_data.dup_num[18] = 2;
      recog_data.dup_loc[19] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 0), 1), 0);
      recog_data.dup_num[19] = 2;
      recog_data.dup_loc[20] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 1), 0), 0);
      recog_data.dup_num[20] = 2;
      recog_data.dup_loc[21] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 1), 1), 0);
      recog_data.dup_num[21] = 2;
      recog_data.dup_loc[22] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 0), 0), 0);
      recog_data.dup_num[22] = 2;
      recog_data.dup_loc[23] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 0), 1), 0);
      recog_data.dup_num[23] = 2;
      recog_data.dup_loc[24] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 1), 0), 0);
      recog_data.dup_num[24] = 2;
      recog_data.dup_loc[25] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 1), 1), 0);
      recog_data.dup_num[25] = 2;
      recog_data.dup_loc[26] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 0), 0), 0);
      recog_data.dup_num[26] = 2;
      recog_data.dup_loc[27] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 0), 1), 0);
      recog_data.dup_num[27] = 2;
      recog_data.dup_loc[28] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 1), 0), 0);
      recog_data.dup_num[28] = 2;
      recog_data.dup_loc[29] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 1), 1), 0);
      recog_data.dup_num[29] = 2;
      break;

    case 3672:  /* *sse2_uavgv8hi3_mask */
    case 3670:  /* *avx2_uavgv16hi3_mask */
    case 3668:  /* *avx512bw_uavgv32hi3_mask */
    case 3666:  /* *sse2_uavgv16qi3_mask */
    case 3664:  /* *avx2_uavgv32qi3_mask */
    case 3662:  /* *avx512bw_uavgv64qi3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 1));
      break;

    case 3671:  /* *sse2_uavgv8hi3 */
    case 3669:  /* *avx2_uavgv16hi3 */
    case 3667:  /* *avx512bw_uavgv32hi3 */
    case 3665:  /* *sse2_uavgv16qi3 */
    case 3663:  /* *avx2_uavgv32qi3 */
    case 3661:  /* *avx512bw_uavgv64qi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1));
      break;

    case 3637:  /* sse2_pshufhw_1_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 4));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 5));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 6));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 7));
      ro[6] = *(ro_loc[6] = &XEXP (XEXP (pat, 1), 1));
      ro[7] = *(ro_loc[7] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3636:  /* sse2_pshufhw_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 4));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 5));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 6));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 7));
      break;

    case 3635:  /* avx2_pshufhw_1_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 4));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 5));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 6));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 7));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 12));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 13));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 14));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 15));
      ro[10] = *(ro_loc[10] = &XEXP (XEXP (pat, 1), 1));
      ro[11] = *(ro_loc[11] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3634:  /* avx2_pshufhw_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 4));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 5));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 6));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 7));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 12));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 13));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 14));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 15));
      break;

    case 3629:  /* avx2_pshuflw_1_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 8));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 9));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 10));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 11));
      ro[10] = *(ro_loc[10] = &XEXP (XEXP (pat, 1), 1));
      ro[11] = *(ro_loc[11] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3628:  /* avx2_pshuflw_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 8));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 9));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 10));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 11));
      break;

    case 3623:  /* avx2_pshufd_1_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 4));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 5));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 6));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 7));
      ro[10] = *(ro_loc[10] = &XEXP (XEXP (pat, 1), 1));
      ro[11] = *(ro_loc[11] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3622:  /* avx2_pshufd_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 4));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 5));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 6));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 7));
      break;

    case 3621:  /* avx512f_pshufd_1_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 4));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 5));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 6));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 7));
      ro[10] = *(ro_loc[10] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 8));
      ro[11] = *(ro_loc[11] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 9));
      ro[12] = *(ro_loc[12] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 10));
      ro[13] = *(ro_loc[13] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 11));
      ro[14] = *(ro_loc[14] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 12));
      ro[15] = *(ro_loc[15] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 13));
      ro[16] = *(ro_loc[16] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 14));
      ro[17] = *(ro_loc[17] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 15));
      ro[18] = *(ro_loc[18] = &XEXP (XEXP (pat, 1), 1));
      ro[19] = *(ro_loc[19] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3620:  /* avx512f_pshufd_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 4));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 5));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 6));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 7));
      ro[10] = *(ro_loc[10] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 8));
      ro[11] = *(ro_loc[11] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 9));
      ro[12] = *(ro_loc[12] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 10));
      ro[13] = *(ro_loc[13] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 11));
      ro[14] = *(ro_loc[14] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 12));
      ro[15] = *(ro_loc[15] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 13));
      ro[16] = *(ro_loc[16] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 14));
      ro[17] = *(ro_loc[17] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 15));
      break;

    case 4411:  /* vec_set_lo_v8sf_mask */
    case 4409:  /* vec_set_lo_v8si_mask */
    case 4403:  /* vec_set_lo_v4df_mask */
    case 4401:  /* vec_set_lo_v4di_mask */
    case 3599:  /* vec_set_lo_v8di_mask */
    case 3597:  /* vec_set_lo_v8df_mask */
    case 3591:  /* vec_set_lo_v16si_mask */
    case 3589:  /* vec_set_lo_v16sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3587:  /* avx512f_vinserti32x4_1_mask */
    case 3585:  /* avx512f_vinsertf32x4_1_mask */
    case 3583:  /* avx512dq_vinserti64x2_1_mask */
    case 3581:  /* avx512dq_vinsertf64x2_1_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3586:  /* *avx512f_vinserti32x4_1 */
    case 3584:  /* *avx512f_vinsertf32x4_1 */
    case 3582:  /* *avx512dq_vinserti64x2_1 */
    case 3580:  /* *avx512dq_vinsertf64x2_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3806:  /* sse4_1_packusdw_mask */
    case 3804:  /* avx2_packusdw_mask */
    case 3802:  /* avx512bw_packusdw_mask */
    case 3539:  /* sse2_packuswb_mask */
    case 3537:  /* avx2_packuswb_mask */
    case 3535:  /* avx512bw_packuswb_mask */
    case 3533:  /* sse2_packssdw_mask */
    case 3531:  /* avx2_packssdw_mask */
    case 3529:  /* avx512bw_packssdw_mask */
    case 3527:  /* sse2_packsswb_mask */
    case 3525:  /* avx2_packsswb_mask */
    case 3523:  /* avx512bw_packsswb_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 4805:  /* avx512dq_fpclassv2df_mask */
    case 4803:  /* avx512dq_fpclassv4df_mask */
    case 4801:  /* avx512dq_fpclassv8df_mask */
    case 4799:  /* avx512dq_fpclassv4sf_mask */
    case 4797:  /* avx512dq_fpclassv8sf_mask */
    case 4795:  /* avx512dq_fpclassv16sf_mask */
    case 4515:  /* *vcvtps2ph */
    case 3521:  /* avx512vl_testnmv2di3_mask */
    case 3519:  /* avx512vl_testnmv4di3_mask */
    case 3517:  /* avx512f_testnmv8di3_mask */
    case 3515:  /* avx512vl_testnmv4si3_mask */
    case 3513:  /* avx512vl_testnmv8si3_mask */
    case 3511:  /* avx512f_testnmv16si3_mask */
    case 3509:  /* avx512vl_testnmv8hi3_mask */
    case 3507:  /* avx512vl_testnmv16hi3_mask */
    case 3505:  /* avx512bw_testnmv32hi3_mask */
    case 3503:  /* avx512vl_testnmv32qi3_mask */
    case 3501:  /* avx512vl_testnmv16qi3_mask */
    case 3499:  /* avx512bw_testnmv64qi3_mask */
    case 3497:  /* avx512vl_testmv2di3_mask */
    case 3495:  /* avx512vl_testmv4di3_mask */
    case 3493:  /* avx512f_testmv8di3_mask */
    case 3491:  /* avx512vl_testmv4si3_mask */
    case 3489:  /* avx512vl_testmv8si3_mask */
    case 3487:  /* avx512f_testmv16si3_mask */
    case 3485:  /* avx512vl_testmv8hi3_mask */
    case 3483:  /* avx512vl_testmv16hi3_mask */
    case 3481:  /* avx512bw_testmv32hi3_mask */
    case 3479:  /* avx512vl_testmv32qi3_mask */
    case 3477:  /* avx512vl_testmv16qi3_mask */
    case 3475:  /* avx512bw_testmv64qi3_mask */
    case 3380:  /* avx512vl_gtv8hi3_mask */
    case 3378:  /* avx512vl_gtv16hi3_mask */
    case 3376:  /* avx512bw_gtv32hi3_mask */
    case 3374:  /* avx512vl_gtv32qi3_mask */
    case 3372:  /* avx512vl_gtv16qi3_mask */
    case 3370:  /* avx512bw_gtv64qi3_mask */
    case 3368:  /* avx512vl_gtv2di3_mask */
    case 3366:  /* avx512vl_gtv4di3_mask */
    case 3364:  /* avx512f_gtv8di3_mask */
    case 3362:  /* avx512vl_gtv4si3_mask */
    case 3360:  /* avx512vl_gtv8si3_mask */
    case 3358:  /* avx512f_gtv16si3_mask */
    case 3347:  /* avx512vl_eqv2di3_mask_1 */
    case 3345:  /* avx512vl_eqv4di3_mask_1 */
    case 3343:  /* avx512f_eqv8di3_mask_1 */
    case 3341:  /* avx512vl_eqv4si3_mask_1 */
    case 3339:  /* avx512vl_eqv8si3_mask_1 */
    case 3337:  /* avx512f_eqv16si3_mask_1 */
    case 3335:  /* avx512vl_eqv8hi3_mask_1 */
    case 3333:  /* avx512vl_eqv16hi3_mask_1 */
    case 3331:  /* avx512bw_eqv32hi3_mask_1 */
    case 3329:  /* avx512vl_eqv32qi3_mask_1 */
    case 3327:  /* avx512vl_eqv16qi3_mask_1 */
    case 3325:  /* avx512bw_eqv64qi3_mask_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 3059:  /* *sse4_1_mulv2siv2di3_mask */
    case 3057:  /* *vec_widen_smult_even_v8si_mask */
    case 3055:  /* *vec_widen_smult_even_v16si_mask */
    case 3053:  /* *vec_widen_umult_even_v4si_mask */
    case 3051:  /* *vec_widen_umult_even_v8si_mask */
    case 3049:  /* *vec_widen_umult_even_v16si_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3047:  /* *umulv8hi3_highpart_mask */
    case 3045:  /* *smulv8hi3_highpart_mask */
    case 3043:  /* *umulv16hi3_highpart_mask */
    case 3041:  /* *smulv16hi3_highpart_mask */
    case 3039:  /* *umulv32hi3_highpart_mask */
    case 3037:  /* *smulv32hi3_highpart_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 2909:  /* avx512f_us_truncatev8div16qi2_mask_store */
    case 2908:  /* avx512f_truncatev8div16qi2_mask_store */
    case 2907:  /* avx512f_ss_truncatev8div16qi2_mask_store */
    case 2897:  /* avx512vl_us_truncatev2div2si2_mask_store */
    case 2896:  /* avx512vl_truncatev2div2si2_mask_store */
    case 2895:  /* avx512vl_ss_truncatev2div2si2_mask_store */
    case 2885:  /* avx512vl_us_truncatev2div2hi2_mask_store */
    case 2884:  /* avx512vl_truncatev2div2hi2_mask_store */
    case 2883:  /* avx512vl_ss_truncatev2div2hi2_mask_store */
    case 2876:  /* avx512vl_us_truncatev4div4hi2_mask_store */
    case 2875:  /* avx512vl_truncatev4div4hi2_mask_store */
    case 2874:  /* avx512vl_ss_truncatev4div4hi2_mask_store */
    case 2873:  /* avx512vl_us_truncatev4siv4hi2_mask_store */
    case 2872:  /* avx512vl_truncatev4siv4hi2_mask_store */
    case 2871:  /* avx512vl_ss_truncatev4siv4hi2_mask_store */
    case 2849:  /* avx512vl_us_truncatev8siv8qi2_mask_store */
    case 2848:  /* avx512vl_truncatev8siv8qi2_mask_store */
    case 2847:  /* avx512vl_ss_truncatev8siv8qi2_mask_store */
    case 2846:  /* avx512vl_us_truncatev8hiv8qi2_mask_store */
    case 2845:  /* avx512vl_truncatev8hiv8qi2_mask_store */
    case 2844:  /* avx512vl_ss_truncatev8hiv8qi2_mask_store */
    case 2831:  /* avx512vl_us_truncatev4div4qi2_mask_store */
    case 2830:  /* avx512vl_truncatev4div4qi2_mask_store */
    case 2829:  /* avx512vl_ss_truncatev4div4qi2_mask_store */
    case 2828:  /* avx512vl_us_truncatev4siv4qi2_mask_store */
    case 2827:  /* avx512vl_truncatev4siv4qi2_mask_store */
    case 2826:  /* avx512vl_ss_truncatev4siv4qi2_mask_store */
    case 2813:  /* avx512vl_us_truncatev2div2qi2_mask_store */
    case 2812:  /* avx512vl_truncatev2div2qi2_mask_store */
    case 2811:  /* avx512vl_ss_truncatev2div2qi2_mask_store */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0);
      recog_data.dup_num[0] = 0;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 1), 0);
      recog_data.dup_num[1] = 0;
      break;

    case 2903:  /* *avx512f_us_truncatev8div16qi2_store */
    case 2902:  /* *avx512f_truncatev8div16qi2_store */
    case 2901:  /* *avx512f_ss_truncatev8div16qi2_store */
    case 2891:  /* *avx512vl_us_truncatev2div2si2_store */
    case 2890:  /* *avx512vl_truncatev2div2si2_store */
    case 2889:  /* *avx512vl_ss_truncatev2div2si2_store */
    case 2879:  /* *avx512vl_us_truncatev2div2hi2_store */
    case 2878:  /* *avx512vl_truncatev2div2hi2_store */
    case 2877:  /* *avx512vl_ss_truncatev2div2hi2_store */
    case 2864:  /* *avx512vl_us_truncatev4div4hi2_store */
    case 2863:  /* *avx512vl_truncatev4div4hi2_store */
    case 2862:  /* *avx512vl_ss_truncatev4div4hi2_store */
    case 2861:  /* *avx512vl_us_truncatev4siv4hi2_store */
    case 2860:  /* *avx512vl_truncatev4siv4hi2_store */
    case 2859:  /* *avx512vl_ss_truncatev4siv4hi2_store */
    case 2837:  /* *avx512vl_us_truncatev8siv8qi2_store */
    case 2836:  /* *avx512vl_truncatev8siv8qi2_store */
    case 2835:  /* *avx512vl_ss_truncatev8siv8qi2_store */
    case 2834:  /* *avx512vl_us_truncatev8hiv8qi2_store */
    case 2833:  /* *avx512vl_truncatev8hiv8qi2_store */
    case 2832:  /* *avx512vl_ss_truncatev8hiv8qi2_store */
    case 2819:  /* *avx512vl_us_truncatev4div4qi2_store */
    case 2818:  /* *avx512vl_truncatev4div4qi2_store */
    case 2817:  /* *avx512vl_ss_truncatev4div4qi2_store */
    case 2816:  /* *avx512vl_us_truncatev4siv4qi2_store */
    case 2815:  /* *avx512vl_truncatev4siv4qi2_store */
    case 2814:  /* *avx512vl_ss_truncatev4siv4qi2_store */
    case 2807:  /* *avx512vl_us_truncatev2div2qi2_store */
    case 2806:  /* *avx512vl_truncatev2div2qi2_store */
    case 2805:  /* *avx512vl_ss_truncatev2div2qi2_store */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 1), 0);
      recog_data.dup_num[0] = 0;
      break;

    case 2731:  /* sse2_shufpd_v2df */
    case 2730:  /* sse2_shufpd_v2di */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 1));
      break;

    case 2717:  /* sse2_shufpd_v2df_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 1));
      ro[6] = *(ro_loc[6] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3619:  /* avx512f_shuf_i32x4_1_mask */
    case 3617:  /* avx512f_shuf_f32x4_1_mask */
    case 2712:  /* avx512f_shufps512_1_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 1));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 3));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 4));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 5));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 6));
      ro[10] = *(ro_loc[10] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 7));
      ro[11] = *(ro_loc[11] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 8));
      ro[12] = *(ro_loc[12] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 9));
      ro[13] = *(ro_loc[13] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 10));
      ro[14] = *(ro_loc[14] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 11));
      ro[15] = *(ro_loc[15] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 12));
      ro[16] = *(ro_loc[16] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 13));
      ro[17] = *(ro_loc[17] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 14));
      ro[18] = *(ro_loc[18] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 15));
      ro[19] = *(ro_loc[19] = &XEXP (XEXP (pat, 1), 1));
      ro[20] = *(ro_loc[20] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3618:  /* avx512f_shuf_i32x4_1 */
    case 3616:  /* avx512f_shuf_f32x4_1 */
    case 2711:  /* avx512f_shufps512_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 1));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 3));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 4));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 5));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 6));
      ro[10] = *(ro_loc[10] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 7));
      ro[11] = *(ro_loc[11] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 8));
      ro[12] = *(ro_loc[12] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 9));
      ro[13] = *(ro_loc[13] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 10));
      ro[14] = *(ro_loc[14] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 11));
      ro[15] = *(ro_loc[15] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 12));
      ro[16] = *(ro_loc[16] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 13));
      ro[17] = *(ro_loc[17] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 14));
      ro[18] = *(ro_loc[18] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 15));
      break;

    case 4835:  /* avx512f_vgetmantv2df_round */
    case 4833:  /* avx512f_vgetmantv4sf_round */
    case 4793:  /* avx512dq_rangesv2df_round */
    case 4791:  /* avx512dq_rangesv4sf_round */
    case 2710:  /* avx512f_rndscalev2df_round */
    case 2708:  /* avx512f_rndscalev4sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2682:  /* avx512f_sfixupimmv2df_mask_round */
    case 2680:  /* avx512f_sfixupimmv4sf_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0, 3));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[1] = 1;
      break;

    case 2681:  /* avx512f_sfixupimmv2df_mask */
    case 2679:  /* avx512f_sfixupimmv4sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 3));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 0), 1);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[1] = 1;
      break;

    case 2678:  /* avx512f_sfixupimmv2df_maskz_1_round */
    case 2674:  /* avx512f_sfixupimmv4sf_maskz_1_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0, 3));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[6] = *(ro_loc[6] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[7] = *(ro_loc[7] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2677:  /* avx512f_sfixupimmv2df_maskz_1 */
    case 2673:  /* avx512f_sfixupimmv4sf_maskz_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 3));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 1));
      ro[6] = *(ro_loc[6] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 0), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2676:  /* avx512f_sfixupimmv2df_round */
    case 2672:  /* avx512f_sfixupimmv4sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 3));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2675:  /* avx512f_sfixupimmv2df */
    case 2671:  /* avx512f_sfixupimmv4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 3));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2670:  /* avx512vl_fixupimmv2df_mask_round */
    case 2668:  /* avx512vl_fixupimmv4df_mask_round */
    case 2666:  /* avx512f_fixupimmv8df_mask_round */
    case 2664:  /* avx512vl_fixupimmv4sf_mask_round */
    case 2662:  /* avx512vl_fixupimmv8sf_mask_round */
    case 2660:  /* avx512f_fixupimmv16sf_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 3));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2658:  /* avx512vl_fixupimmv2df_maskz_1_round */
    case 2654:  /* avx512vl_fixupimmv4df_maskz_1_round */
    case 2650:  /* avx512f_fixupimmv8df_maskz_1_round */
    case 2646:  /* avx512vl_fixupimmv4sf_maskz_1_round */
    case 2642:  /* avx512vl_fixupimmv8sf_maskz_1_round */
    case 2638:  /* avx512f_fixupimmv16sf_maskz_1_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 3));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[6] = *(ro_loc[6] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[7] = *(ro_loc[7] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 2656:  /* avx512vl_fixupimmv2df_round */
    case 2652:  /* avx512vl_fixupimmv4df_round */
    case 2648:  /* avx512f_fixupimmv8df_round */
    case 2644:  /* avx512vl_fixupimmv4sf_round */
    case 2640:  /* avx512vl_fixupimmv8sf_round */
    case 2636:  /* avx512f_fixupimmv16sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 2669:  /* avx512vl_fixupimmv2df_mask */
    case 2667:  /* avx512vl_fixupimmv4df_mask */
    case 2665:  /* avx512f_fixupimmv8df_mask */
    case 2663:  /* avx512vl_fixupimmv4sf_mask */
    case 2661:  /* avx512vl_fixupimmv8sf_mask */
    case 2659:  /* avx512f_fixupimmv16sf_mask */
    case 2594:  /* avx512vl_vternlogv2di_mask */
    case 2593:  /* avx512vl_vternlogv4di_mask */
    case 2592:  /* avx512f_vternlogv8di_mask */
    case 2591:  /* avx512vl_vternlogv4si_mask */
    case 2590:  /* avx512vl_vternlogv8si_mask */
    case 2589:  /* avx512f_vternlogv16si_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 3));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2657:  /* avx512vl_fixupimmv2df_maskz_1 */
    case 2653:  /* avx512vl_fixupimmv4df_maskz_1 */
    case 2649:  /* avx512f_fixupimmv8df_maskz_1 */
    case 2645:  /* avx512vl_fixupimmv4sf_maskz_1 */
    case 2641:  /* avx512vl_fixupimmv8sf_maskz_1 */
    case 2637:  /* avx512f_fixupimmv16sf_maskz_1 */
    case 2588:  /* avx512vl_vternlogv2di_maskz_1 */
    case 2586:  /* avx512vl_vternlogv4di_maskz_1 */
    case 2584:  /* avx512f_vternlogv8di_maskz_1 */
    case 2582:  /* avx512vl_vternlogv4si_maskz_1 */
    case 2580:  /* avx512vl_vternlogv8si_maskz_1 */
    case 2578:  /* avx512f_vternlogv16si_maskz_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 3));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 1));
      ro[6] = *(ro_loc[6] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 4050:  /* xop_vpermil2v2df3 */
    case 4049:  /* xop_vpermil2v4df3 */
    case 4048:  /* xop_vpermil2v4sf3 */
    case 4047:  /* xop_vpermil2v8sf3 */
    case 3782:  /* sse4a_insertqi */
    case 2655:  /* avx512vl_fixupimmv2df */
    case 2651:  /* avx512vl_fixupimmv4df */
    case 2647:  /* avx512f_fixupimmv8df */
    case 2643:  /* avx512vl_fixupimmv4sf */
    case 2639:  /* avx512vl_fixupimmv8sf */
    case 2635:  /* avx512f_fixupimmv16sf */
    case 2587:  /* avx512vl_vternlogv2di */
    case 2585:  /* avx512vl_vternlogv4di */
    case 2583:  /* avx512f_vternlogv8di */
    case 2581:  /* avx512vl_vternlogv4si */
    case 2579:  /* avx512vl_vternlogv8si */
    case 2577:  /* avx512f_vternlogv16si */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (pat, 1), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (pat, 1), 0, 3));
      break;

    case 4831:  /* avx512vl_getmantv2df_mask_round */
    case 4827:  /* avx512vl_getmantv4df_mask_round */
    case 4823:  /* avx512f_getmantv8df_mask_round */
    case 4819:  /* avx512vl_getmantv4sf_mask_round */
    case 4815:  /* avx512vl_getmantv8sf_mask_round */
    case 4811:  /* avx512f_getmantv16sf_mask_round */
    case 2706:  /* avx512vl_rndscalev2df_mask_round */
    case 2702:  /* avx512vl_rndscalev4df_mask_round */
    case 2698:  /* avx512f_rndscalev8df_mask_round */
    case 2694:  /* avx512vl_rndscalev4sf_mask_round */
    case 2690:  /* avx512vl_rndscalev8sf_mask_round */
    case 2686:  /* avx512f_rndscalev16sf_mask_round */
    case 2576:  /* avx512vl_scalefv2df_mask_round */
    case 2572:  /* avx512vl_scalefv4df_mask_round */
    case 2568:  /* avx512f_scalefv8df_mask_round */
    case 2564:  /* avx512vl_scalefv4sf_mask_round */
    case 2560:  /* avx512vl_scalefv8sf_mask_round */
    case 2556:  /* avx512f_scalefv16sf_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 4829:  /* avx512vl_getmantv2df_round */
    case 4825:  /* avx512vl_getmantv4df_round */
    case 4821:  /* avx512f_getmantv8df_round */
    case 4817:  /* avx512vl_getmantv4sf_round */
    case 4813:  /* avx512vl_getmantv8sf_round */
    case 4809:  /* avx512f_getmantv16sf_round */
    case 2704:  /* avx512vl_rndscalev2df_round */
    case 2700:  /* avx512vl_rndscalev4df_round */
    case 2696:  /* avx512f_rndscalev8df_round */
    case 2692:  /* avx512vl_rndscalev4sf_round */
    case 2688:  /* avx512vl_rndscalev8sf_round */
    case 2684:  /* avx512f_rndscalev16sf_round */
    case 2574:  /* avx512vl_scalefv2df_round */
    case 2570:  /* avx512vl_scalefv4df_round */
    case 2566:  /* avx512f_scalefv8df_round */
    case 2562:  /* avx512vl_scalefv4sf_round */
    case 2558:  /* avx512vl_scalefv8sf_round */
    case 2554:  /* avx512f_scalefv16sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 2622:  /* avx512f_sgetexpv2df_round */
    case 2620:  /* avx512f_sgetexpv4sf_round */
    case 2552:  /* avx512f_vmscalefv2df_round */
    case 2550:  /* avx512f_vmscalefv4sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2621:  /* avx512f_sgetexpv2df */
    case 2619:  /* avx512f_sgetexpv4sf */
    case 2551:  /* avx512f_vmscalefv2df */
    case 2549:  /* avx512f_vmscalefv4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2479:  /* *avx512dq_vextracti64x2_1 */
    case 2477:  /* *avx512dq_vextractf64x2_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 1));
      break;

    case 4111:  /* avx512f_permv8df_1_mask */
    case 4109:  /* avx512f_permv8di_1_mask */
    case 4107:  /* avx2_permv4df_1_mask */
    case 4105:  /* avx2_permv4di_1_mask */
    case 3631:  /* sse2_pshuflw_1_mask */
    case 3625:  /* sse2_pshufd_1_mask */
    case 2484:  /* avx512f_vextracti32x4_1_mask */
    case 2482:  /* avx512f_vextractf32x4_1_mask */
    case 2476:  /* avx512f_vextracti32x4_1_maskm */
    case 2475:  /* avx512f_vextractf32x4_1_maskm */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 3));
      ro[6] = *(ro_loc[6] = &XEXP (XEXP (pat, 1), 1));
      ro[7] = *(ro_loc[7] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 2480:  /* avx512dq_vextracti64x2_1_mask */
    case 2478:  /* avx512dq_vextractf64x2_1_mask */
    case 2474:  /* avx512dq_vextracti64x2_1_maskm */
    case 2473:  /* avx512dq_vextractf64x2_1_maskm */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3654:  /* *vec_extractv4si_mem */
    case 3652:  /* *vec_extractv4si */
    case 3647:  /* *vec_extractv8hi_mem */
    case 3646:  /* *vec_extractv16qi_mem */
    case 3641:  /* *vec_extractv8hi_sse2 */
    case 3640:  /* *vec_extractv8hi */
    case 3639:  /* *vec_extractv16qi */
    case 2472:  /* *vec_extractv4sf_mem */
    case 2471:  /* *sse4_1_extractps */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      break;

    case 2469:  /* sse4_1_insertps */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (pat, 1), 0, 2));
      break;

    case 3638:  /* sse2_loadld */
    case 2467:  /* vec_setv4sf_0 */
    case 2466:  /* vec_setv4si_0 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      break;

    case 2738:  /* sse2_movsd */
    case 2457:  /* sse_movss */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 4418:  /* vec_set_lo_v32qi */
    case 4416:  /* vec_set_lo_v16hi */
    case 4410:  /* vec_set_lo_v8sf */
    case 4408:  /* vec_set_lo_v8si */
    case 4402:  /* vec_set_lo_v4df */
    case 4400:  /* vec_set_lo_v4di */
    case 3598:  /* vec_set_lo_v8di */
    case 3596:  /* vec_set_lo_v8df */
    case 3590:  /* vec_set_lo_v16si */
    case 3588:  /* vec_set_lo_v16sf */
    case 2737:  /* sse2_loadlpd */
    case 2456:  /* sse_loadlps */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 3606:  /* *avx512dq_shuf_f64x2_1 */
    case 3604:  /* *avx512dq_shuf_i64x2_1 */
    case 2715:  /* avx_shufpd256_1 */
    case 2452:  /* sse_shufps_v4sf */
    case 2451:  /* sse_shufps_v4si */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 1));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 3));
      break;

    case 3607:  /* avx512dq_shuf_f64x2_1_mask */
    case 3605:  /* avx512dq_shuf_i64x2_1_mask */
    case 2716:  /* avx_shufpd256_1_mask */
    case 2450:  /* sse_shufps_v4sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 1));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 3));
      ro[7] = *(ro_loc[7] = &XEXP (XEXP (pat, 1), 1));
      ro[8] = *(ro_loc[8] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3615:  /* avx512vl_shuf_f32x4_1_mask */
    case 3613:  /* avx512vl_shuf_i32x4_1_mask */
    case 3611:  /* avx512f_shuf_i64x2_1_mask */
    case 3609:  /* avx512f_shuf_f64x2_1_mask */
    case 2714:  /* avx512f_shufpd512_1_mask */
    case 2449:  /* avx_shufps256_1_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 1));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 3));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 4));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 5));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 6));
      ro[10] = *(ro_loc[10] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 7));
      ro[11] = *(ro_loc[11] = &XEXP (XEXP (pat, 1), 1));
      ro[12] = *(ro_loc[12] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3614:  /* *avx512vl_shuf_f32x4_1 */
    case 3612:  /* *avx512vl_shuf_i32x4_1 */
    case 3610:  /* avx512f_shuf_i64x2_1 */
    case 3608:  /* avx512f_shuf_f64x2_1 */
    case 2713:  /* avx512f_shufpd512_1 */
    case 2448:  /* avx_shufps256_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 1));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 3));
      ro[7] = *(ro_loc[7] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 4));
      ro[8] = *(ro_loc[8] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 5));
      ro[9] = *(ro_loc[9] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 6));
      ro[10] = *(ro_loc[10] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 7));
      break;

    case 2447:  /* avx512f_movsldup512_mask */
    case 2445:  /* sse3_movsldup_mask */
    case 2443:  /* avx_movsldup256_mask */
    case 2441:  /* avx512f_movshdup512_mask */
    case 2439:  /* sse3_movshdup_mask */
    case 2437:  /* avx_movshdup256_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2446:  /* *avx512f_movsldup512 */
    case 2444:  /* sse3_movsldup */
    case 2442:  /* avx_movsldup256 */
    case 2440:  /* *avx512f_movshdup512 */
    case 2438:  /* sse3_movshdup */
    case 2436:  /* avx_movshdup256 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 0), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 3575:  /* vec_interleave_lowv4si_mask */
    case 3573:  /* avx512f_interleave_lowv16si_mask */
    case 3571:  /* avx2_interleave_lowv8si_mask */
    case 3569:  /* vec_interleave_highv4si_mask */
    case 3567:  /* avx512f_interleave_highv16si_mask */
    case 3565:  /* avx2_interleave_highv8si_mask */
    case 3563:  /* vec_interleave_lowv8hi_mask */
    case 3561:  /* avx2_interleave_lowv16hi_mask */
    case 3559:  /* avx512bw_interleave_lowv32hi_mask */
    case 3557:  /* vec_interleave_highv8hi_mask */
    case 3555:  /* avx2_interleave_highv16hi_mask */
    case 3553:  /* avx512bw_interleave_highv32hi_mask */
    case 3551:  /* vec_interleave_lowv16qi_mask */
    case 3549:  /* avx2_interleave_lowv32qi_mask */
    case 3547:  /* avx512bw_interleave_lowv64qi_mask */
    case 3545:  /* vec_interleave_highv16qi_mask */
    case 3543:  /* avx2_interleave_highv32qi_mask */
    case 3541:  /* avx512bw_interleave_highv64qi_mask */
    case 2729:  /* vec_interleave_lowv2di_mask */
    case 2727:  /* avx512f_interleave_lowv8di_mask */
    case 2725:  /* avx2_interleave_lowv4di_mask */
    case 2723:  /* vec_interleave_highv2di_mask */
    case 2721:  /* avx512f_interleave_highv8di_mask */
    case 2719:  /* avx2_interleave_highv4di_mask */
    case 2547:  /* avx512vl_unpcklpd128_mask */
    case 2546:  /* *avx_unpcklpd256_mask */
    case 2544:  /* *avx512f_unpcklpd512_mask */
    case 2541:  /* avx512vl_unpckhpd128_mask */
    case 2540:  /* avx_unpckhpd256_mask */
    case 2538:  /* avx512f_unpckhpd512_mask */
    case 2434:  /* unpcklps128_mask */
    case 2433:  /* avx_unpcklps256_mask */
    case 2431:  /* avx512f_unpcklps512_mask */
    case 2429:  /* vec_interleave_highv4sf_mask */
    case 2427:  /* avx_unpckhps256_mask */
    case 2425:  /* avx512f_unpckhps512_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 2419:  /* *avx512vl_cvtmask2qv2di */
    case 2418:  /* *avx512vl_cvtmask2qv4di */
    case 2417:  /* *avx512f_cvtmask2qv8di */
    case 2416:  /* *avx512vl_cvtmask2dv4si */
    case 2415:  /* *avx512vl_cvtmask2dv8si */
    case 2414:  /* *avx512f_cvtmask2dv16si */
    case 2413:  /* *avx512vl_cvtmask2wv8hi */
    case 2412:  /* *avx512vl_cvtmask2wv16hi */
    case 2411:  /* *avx512bw_cvtmask2wv32hi */
    case 2410:  /* *avx512vl_cvtmask2bv32qi */
    case 2409:  /* *avx512vl_cvtmask2bv16qi */
    case 2408:  /* *avx512bw_cvtmask2bv64qi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 2));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 4506:  /* vcvtph2ps_mask */
    case 2307:  /* ufix_notruncv2dfv2si2_mask */
    case 2297:  /* sse2_cvtpd2dq_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 4230:  /* avx512dq_broadcastv8sf_mask */
    case 4228:  /* avx512dq_broadcastv16sf_mask */
    case 4226:  /* avx512dq_broadcastv4si_mask */
    case 4224:  /* avx512dq_broadcastv8si_mask */
    case 4222:  /* avx512dq_broadcastv16si_mask */
    case 4153:  /* avx512vl_vec_dupv8hi_mask */
    case 4151:  /* avx512vl_vec_dupv16hi_mask */
    case 4149:  /* avx512bw_vec_dupv32hi_mask */
    case 4147:  /* avx512vl_vec_dupv32qi_mask */
    case 4145:  /* avx512vl_vec_dupv16qi_mask */
    case 4143:  /* avx512bw_vec_dupv64qi_mask */
    case 4141:  /* avx512vl_vec_dupv2df_mask */
    case 4139:  /* avx512vl_vec_dupv4df_mask */
    case 4137:  /* avx512f_vec_dupv8df_mask */
    case 4135:  /* avx512vl_vec_dupv4sf_mask */
    case 4133:  /* avx512vl_vec_dupv8sf_mask */
    case 4131:  /* avx512f_vec_dupv16sf_mask */
    case 4129:  /* avx512vl_vec_dupv2di_mask */
    case 4127:  /* avx512vl_vec_dupv4di_mask */
    case 4125:  /* avx512f_vec_dupv8di_mask */
    case 4123:  /* avx512vl_vec_dupv4si_mask */
    case 4121:  /* avx512vl_vec_dupv8si_mask */
    case 4119:  /* avx512f_vec_dupv16si_mask */
    case 3885:  /* sse4_1_zero_extendv2siv2di2_mask */
    case 3883:  /* sse4_1_sign_extendv2siv2di2_mask */
    case 3873:  /* sse4_1_zero_extendv2hiv2di2_mask */
    case 3871:  /* sse4_1_sign_extendv2hiv2di2_mask */
    case 3869:  /* avx2_zero_extendv4hiv4di2_mask */
    case 3867:  /* avx2_sign_extendv4hiv4di2_mask */
    case 3861:  /* sse4_1_zero_extendv2qiv2di2_mask */
    case 3859:  /* sse4_1_sign_extendv2qiv2di2_mask */
    case 3857:  /* avx2_zero_extendv4qiv4di2_mask */
    case 3855:  /* avx2_sign_extendv4qiv4di2_mask */
    case 3853:  /* avx512f_zero_extendv8qiv8di2_mask */
    case 3851:  /* avx512f_sign_extendv8qiv8di2_mask */
    case 3849:  /* sse4_1_zero_extendv4hiv4si2_mask */
    case 3847:  /* sse4_1_sign_extendv4hiv4si2_mask */
    case 3837:  /* sse4_1_zero_extendv4qiv4si2_mask */
    case 3835:  /* sse4_1_sign_extendv4qiv4si2_mask */
    case 3833:  /* avx2_zero_extendv8qiv8si2_mask */
    case 3831:  /* avx2_sign_extendv8qiv8si2_mask */
    case 3825:  /* sse4_1_zero_extendv8qiv8hi2_mask */
    case 3823:  /* sse4_1_sign_extendv8qiv8hi2_mask */
    case 2421:  /* sse2_cvtps2pd_mask */
    case 2375:  /* sse2_cvttpd2dq_mask */
    case 2369:  /* ufix_truncv2sfv2di2_mask */
    case 2367:  /* fix_truncv2sfv2di2_mask */
    case 2317:  /* ufix_truncv2dfv2si2_mask */
    case 2288:  /* sse2_cvtdq2pd_mask */
    case 2284:  /* ufloatv2siv2df2_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 2906:  /* avx512f_us_truncatev8div16qi2_mask */
    case 2905:  /* avx512f_truncatev8div16qi2_mask */
    case 2904:  /* avx512f_ss_truncatev8div16qi2_mask */
    case 2894:  /* avx512vl_us_truncatev2div2si2_mask */
    case 2893:  /* avx512vl_truncatev2div2si2_mask */
    case 2892:  /* avx512vl_ss_truncatev2div2si2_mask */
    case 2882:  /* avx512vl_us_truncatev2div2hi2_mask */
    case 2881:  /* avx512vl_truncatev2div2hi2_mask */
    case 2880:  /* avx512vl_ss_truncatev2div2hi2_mask */
    case 2870:  /* avx512vl_us_truncatev4div4hi2_mask */
    case 2869:  /* avx512vl_truncatev4div4hi2_mask */
    case 2868:  /* avx512vl_ss_truncatev4div4hi2_mask */
    case 2867:  /* avx512vl_us_truncatev4siv4hi2_mask */
    case 2866:  /* avx512vl_truncatev4siv4hi2_mask */
    case 2865:  /* avx512vl_ss_truncatev4siv4hi2_mask */
    case 2843:  /* avx512vl_us_truncatev8siv8qi2_mask */
    case 2842:  /* avx512vl_truncatev8siv8qi2_mask */
    case 2841:  /* avx512vl_ss_truncatev8siv8qi2_mask */
    case 2840:  /* avx512vl_us_truncatev8hiv8qi2_mask */
    case 2839:  /* avx512vl_truncatev8hiv8qi2_mask */
    case 2838:  /* avx512vl_ss_truncatev8hiv8qi2_mask */
    case 2825:  /* avx512vl_us_truncatev4div4qi2_mask */
    case 2824:  /* avx512vl_truncatev4div4qi2_mask */
    case 2823:  /* avx512vl_ss_truncatev4div4qi2_mask */
    case 2822:  /* avx512vl_us_truncatev4siv4qi2_mask */
    case 2821:  /* avx512vl_truncatev4siv4qi2_mask */
    case 2820:  /* avx512vl_ss_truncatev4siv4qi2_mask */
    case 2810:  /* avx512vl_us_truncatev2div2qi2_mask */
    case 2809:  /* avx512vl_truncatev2div2qi2_mask */
    case 2808:  /* avx512vl_ss_truncatev2div2qi2_mask */
    case 2278:  /* ufloatv2div2sf2_mask */
    case 2277:  /* floatv2div2sf2_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      break;

    case 2190:  /* avx512dq_cvtps2uqqv2di_mask */
    case 2182:  /* avx512dq_cvtps2qqv2di_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 4514:  /* avx512f_vcvtph2ps512_mask_round */
    case 3951:  /* avx512er_rsqrt28v8df_mask_round */
    case 3947:  /* avx512er_rsqrt28v16sf_mask_round */
    case 3939:  /* avx512er_rcp28v8df_mask_round */
    case 3935:  /* avx512er_rcp28v16sf_mask_round */
    case 3931:  /* avx512er_exp2v8df_mask_round */
    case 3927:  /* avx512er_exp2v16sf_mask_round */
    case 2618:  /* avx512vl_getexpv2df_mask_round */
    case 2614:  /* avx512vl_getexpv4df_mask_round */
    case 2610:  /* avx512f_getexpv8df_mask_round */
    case 2606:  /* avx512vl_getexpv4sf_mask_round */
    case 2602:  /* avx512vl_getexpv8sf_mask_round */
    case 2598:  /* avx512f_getexpv16sf_mask_round */
    case 2349:  /* ufix_notruncv8dfv8di2_mask_round */
    case 2341:  /* fix_notruncv8dfv8di2_mask_round */
    case 2305:  /* ufix_notruncv4dfv4si2_mask_round */
    case 2301:  /* ufix_notruncv8dfv8si2_mask_round */
    case 2292:  /* avx512f_cvtpd2dq512_mask_round */
    case 2186:  /* avx512dq_cvtps2uqqv8di_mask_round */
    case 2178:  /* avx512dq_cvtps2qqv8di_mask_round */
    case 2174:  /* avx512vl_ufix_notruncv4sfv4si_mask_round */
    case 2170:  /* avx512vl_ufix_notruncv8sfv8si_mask_round */
    case 2166:  /* avx512f_ufix_notruncv16sfv16si_mask_round */
    case 2162:  /* avx512f_fix_notruncv16sfv16si_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 4512:  /* *avx512f_vcvtph2ps512_round */
    case 3949:  /* *avx512er_rsqrt28v8df_round */
    case 3945:  /* *avx512er_rsqrt28v16sf_round */
    case 3937:  /* *avx512er_rcp28v8df_round */
    case 3933:  /* *avx512er_rcp28v16sf_round */
    case 3929:  /* avx512er_exp2v8df_round */
    case 3925:  /* avx512er_exp2v16sf_round */
    case 2616:  /* avx512vl_getexpv2df_round */
    case 2612:  /* avx512vl_getexpv4df_round */
    case 2608:  /* avx512f_getexpv8df_round */
    case 2604:  /* avx512vl_getexpv4sf_round */
    case 2600:  /* avx512vl_getexpv8sf_round */
    case 2596:  /* avx512f_getexpv16sf_round */
    case 2347:  /* ufix_notruncv8dfv8di2_round */
    case 2339:  /* fix_notruncv8dfv8di2_round */
    case 2303:  /* ufix_notruncv4dfv4si2_round */
    case 2299:  /* ufix_notruncv8dfv8si2_round */
    case 2290:  /* *avx512f_cvtpd2dq512_round */
    case 2184:  /* *avx512dq_cvtps2uqqv8di_round */
    case 2176:  /* *avx512dq_cvtps2qqv8di_round */
    case 2172:  /* *avx512vl_ufix_notruncv4sfv4si_round */
    case 2168:  /* *avx512vl_ufix_notruncv8sfv8si_round */
    case 2164:  /* *avx512f_ufix_notruncv16sfv16si_round */
    case 2160:  /* *avx512f_fix_notruncv16sfv16si_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 2234:  /* sse2_cvttsd2siq_round */
    case 2232:  /* sse2_cvttsd2si_round */
    case 2224:  /* avx512f_vcvttsd2usiq_round */
    case 2222:  /* avx512f_vcvttsd2usi_round */
    case 2216:  /* avx512f_vcvttss2usiq_round */
    case 2214:  /* avx512f_vcvttss2usi_round */
    case 2127:  /* sse_cvttss2siq_round */
    case 2125:  /* sse_cvttss2si_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 2229:  /* sse2_cvtsd2siq_round */
    case 2226:  /* sse2_cvtsd2si_round */
    case 2220:  /* avx512f_vcvtsd2usiq_round */
    case 2218:  /* avx512f_vcvtsd2usi_round */
    case 2212:  /* avx512f_vcvtss2usiq_round */
    case 2210:  /* avx512f_vcvtss2usi_round */
    case 2122:  /* sse_cvtss2siq_round */
    case 2119:  /* sse_cvtss2si_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 2379:  /* sse2_cvtss2sd_round */
    case 2377:  /* sse2_cvtsd2ss_round */
    case 2208:  /* sse2_cvtsi2sdq_round */
    case 2134:  /* cvtusi2sd64_round */
    case 2132:  /* cvtusi2ss64_round */
    case 2129:  /* cvtusi2ss32_round */
    case 2117:  /* sse_cvtsi2ssq_round */
    case 2115:  /* sse_cvtsi2ss_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 4505:  /* vcvtph2ps */
    case 2306:  /* ufix_notruncv2dfv2si2 */
    case 2296:  /* sse2_cvtpd2dq */
    case 2112:  /* sse_cvtps2pi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      break;

    case 2378:  /* sse2_cvtss2sd */
    case 2376:  /* sse2_cvtsd2ss */
    case 2207:  /* sse2_cvtsi2sdq */
    case 2206:  /* sse2_cvtsi2sd */
    case 2133:  /* cvtusi2sd64 */
    case 2131:  /* cvtusi2ss64 */
    case 2130:  /* cvtusi2sd32 */
    case 2128:  /* cvtusi2ss32 */
    case 2116:  /* sse_cvtsi2ssq */
    case 2114:  /* sse_cvtsi2ss */
    case 2111:  /* sse_cvtpi2ps */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      break;

    case 2110:  /* *fma4i_vmfnmsub_v2df */
    case 2109:  /* *fma4i_vmfnmsub_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 2108:  /* *fma4i_vmfnmadd_v2df */
    case 2107:  /* *fma4i_vmfnmadd_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 2106:  /* *fma4i_vmfmsub_v2df */
    case 2105:  /* *fma4i_vmfmsub_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 2104:  /* *fma4i_vmfmadd_v2df */
    case 2103:  /* *fma4i_vmfmadd_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 2102:  /* *fmai_fnmsub_v2df_round */
    case 2100:  /* *fmai_fnmsub_v4sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2101:  /* *fmai_fnmsub_v2df */
    case 2099:  /* *fmai_fnmsub_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2098:  /* *fmai_fnmadd_v2df_round */
    case 2096:  /* *fmai_fnmadd_v4sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2097:  /* *fmai_fnmadd_v2df */
    case 2095:  /* *fmai_fnmadd_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2094:  /* *fmai_fmsub_v2df */
    case 2092:  /* *fmai_fmsub_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2093:  /* *fmai_fmsub_v2df */
    case 2091:  /* *fmai_fmsub_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2090:  /* *fmai_fmadd_v2df */
    case 2088:  /* *fmai_fmadd_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2089:  /* *fmai_fmadd_v2df */
    case 2087:  /* *fmai_fmadd_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2086:  /* avx512vl_fmsubadd_v2df_mask3_round */
    case 2084:  /* avx512vl_fmsubadd_v4df_mask3_round */
    case 2082:  /* avx512f_fmsubadd_v8df_mask3_round */
    case 2080:  /* avx512vl_fmsubadd_v4sf_mask3_round */
    case 2078:  /* avx512vl_fmsubadd_v8sf_mask3_round */
    case 2076:  /* avx512f_fmsubadd_v16sf_mask3_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 2085:  /* avx512vl_fmsubadd_v2df_mask3 */
    case 2083:  /* avx512vl_fmsubadd_v4df_mask3 */
    case 2081:  /* avx512f_fmsubadd_v8df_mask3 */
    case 2079:  /* avx512vl_fmsubadd_v4sf_mask3 */
    case 2077:  /* avx512vl_fmsubadd_v8sf_mask3 */
    case 2075:  /* avx512f_fmsubadd_v16sf_mask3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 2074:  /* avx512vl_fmsubadd_v2df_mask_round */
    case 2072:  /* avx512vl_fmsubadd_v4df_mask_round */
    case 2070:  /* avx512f_fmsubadd_v8df_mask_round */
    case 2068:  /* avx512vl_fmsubadd_v4sf_mask_round */
    case 2066:  /* avx512vl_fmsubadd_v8sf_mask_round */
    case 2064:  /* avx512f_fmsubadd_v16sf_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2073:  /* avx512vl_fmsubadd_v2df_mask */
    case 2071:  /* avx512vl_fmsubadd_v4df_mask */
    case 2069:  /* avx512f_fmsubadd_v8df_mask */
    case 2067:  /* avx512vl_fmsubadd_v4sf_mask */
    case 2065:  /* avx512vl_fmsubadd_v8sf_mask */
    case 2063:  /* avx512f_fmsubadd_v16sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 2058:  /* fma_fmsubadd_v8df_maskz_1_round */
    case 2049:  /* fma_fmsubadd_v16sf_maskz_1_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 2062:  /* fma_fmsubadd_v2df_maskz_1 */
    case 2060:  /* fma_fmsubadd_v4df_maskz_1 */
    case 2057:  /* fma_fmsubadd_v8df_maskz_1 */
    case 2053:  /* fma_fmsubadd_v4sf_maskz_1 */
    case 2051:  /* fma_fmsubadd_v8sf_maskz_1 */
    case 2048:  /* fma_fmsubadd_v16sf_maskz_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 2056:  /* *fma_fmsubadd_v8df_round */
    case 2047:  /* *fma_fmsubadd_v16sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 2061:  /* *fma_fmsubadd_v2df */
    case 2059:  /* *fma_fmsubadd_v4df */
    case 2055:  /* *fma_fmsubadd_v8df */
    case 2054:  /* *fma_fmsubadd_df */
    case 2052:  /* *fma_fmsubadd_v4sf */
    case 2050:  /* *fma_fmsubadd_v8sf */
    case 2046:  /* *fma_fmsubadd_v16sf */
    case 2045:  /* *fma_fmsubadd_sf */
    case 2044:  /* *fma_fmsubadd_v2df */
    case 2043:  /* *fma_fmsubadd_v4df */
    case 2042:  /* *fma_fmsubadd_v4sf */
    case 2041:  /* *fma_fmsubadd_v8sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 2), 0));
      break;

    case 2040:  /* avx512vl_fmaddsub_v2df_mask3_round */
    case 2038:  /* avx512vl_fmaddsub_v4df_mask3_round */
    case 2036:  /* avx512f_fmaddsub_v8df_mask3_round */
    case 2034:  /* avx512vl_fmaddsub_v4sf_mask3_round */
    case 2032:  /* avx512vl_fmaddsub_v8sf_mask3_round */
    case 2030:  /* avx512f_fmaddsub_v16sf_mask3_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 2039:  /* avx512vl_fmaddsub_v2df_mask3 */
    case 2037:  /* avx512vl_fmaddsub_v4df_mask3 */
    case 2035:  /* avx512f_fmaddsub_v8df_mask3 */
    case 2033:  /* avx512vl_fmaddsub_v4sf_mask3 */
    case 2031:  /* avx512vl_fmaddsub_v8sf_mask3 */
    case 2029:  /* avx512f_fmaddsub_v16sf_mask3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 2028:  /* avx512vl_fmaddsub_v2df_mask_round */
    case 2026:  /* avx512vl_fmaddsub_v4df_mask_round */
    case 2024:  /* avx512f_fmaddsub_v8df_mask_round */
    case 2022:  /* avx512vl_fmaddsub_v4sf_mask_round */
    case 2020:  /* avx512vl_fmaddsub_v8sf_mask_round */
    case 2018:  /* avx512f_fmaddsub_v16sf_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 4896:  /* vpamdd52huqv2di_mask */
    case 4895:  /* vpamdd52luqv2di_mask */
    case 4894:  /* vpamdd52huqv4di_mask */
    case 4893:  /* vpamdd52luqv4di_mask */
    case 4892:  /* vpamdd52huqv8di_mask */
    case 4891:  /* vpamdd52luqv8di_mask */
    case 2027:  /* avx512vl_fmaddsub_v2df_mask */
    case 2025:  /* avx512vl_fmaddsub_v4df_mask */
    case 2023:  /* avx512f_fmaddsub_v8df_mask */
    case 2021:  /* avx512vl_fmaddsub_v4sf_mask */
    case 2019:  /* avx512vl_fmaddsub_v8sf_mask */
    case 2017:  /* avx512f_fmaddsub_v16sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 4785:  /* avx512dq_rangepv8df_mask_round */
    case 4777:  /* avx512dq_rangepv16sf_mask_round */
    case 2012:  /* fma_fmaddsub_v8df_maskz_1_round */
    case 2003:  /* fma_fmaddsub_v16sf_maskz_1_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 4890:  /* vpamdd52huqv2di_maskz_1 */
    case 4888:  /* vpamdd52luqv2di_maskz_1 */
    case 4886:  /* vpamdd52huqv4di_maskz_1 */
    case 4884:  /* vpamdd52luqv4di_maskz_1 */
    case 4882:  /* vpamdd52huqv8di_maskz_1 */
    case 4880:  /* vpamdd52luqv8di_maskz_1 */
    case 4841:  /* avx512bw_dbpsadbwv32hi_mask */
    case 4839:  /* avx512bw_dbpsadbwv16hi_mask */
    case 4837:  /* avx512bw_dbpsadbwv8hi_mask */
    case 4789:  /* avx512dq_rangepv2df_mask */
    case 4787:  /* avx512dq_rangepv4df_mask */
    case 4784:  /* avx512dq_rangepv8df_mask */
    case 4781:  /* avx512dq_rangepv4sf_mask */
    case 4779:  /* avx512dq_rangepv8sf_mask */
    case 4776:  /* avx512dq_rangepv16sf_mask */
    case 4369:  /* avx512bw_vpermt2varv32hi3_maskz_1 */
    case 4367:  /* avx512vl_vpermt2varv16hi3_maskz_1 */
    case 4365:  /* avx512vl_vpermt2varv8hi3_maskz_1 */
    case 4363:  /* avx512vl_vpermt2varv32qi3_maskz_1 */
    case 4361:  /* avx512vl_vpermt2varv16qi3_maskz_1 */
    case 4359:  /* avx512bw_vpermt2varv64qi3_maskz_1 */
    case 4357:  /* avx512vl_vpermt2varv2df3_maskz_1 */
    case 4355:  /* avx512vl_vpermt2varv2di3_maskz_1 */
    case 4353:  /* avx512vl_vpermt2varv4sf3_maskz_1 */
    case 4351:  /* avx512vl_vpermt2varv4si3_maskz_1 */
    case 4349:  /* avx512vl_vpermt2varv4df3_maskz_1 */
    case 4347:  /* avx512vl_vpermt2varv4di3_maskz_1 */
    case 4345:  /* avx512vl_vpermt2varv8sf3_maskz_1 */
    case 4343:  /* avx512vl_vpermt2varv8si3_maskz_1 */
    case 4341:  /* avx512f_vpermt2varv8df3_maskz_1 */
    case 4339:  /* avx512f_vpermt2varv8di3_maskz_1 */
    case 4337:  /* avx512f_vpermt2varv16sf3_maskz_1 */
    case 4335:  /* avx512f_vpermt2varv16si3_maskz_1 */
    case 4315:  /* avx512bw_vpermi2varv32hi3_maskz_1 */
    case 4313:  /* avx512vl_vpermi2varv16hi3_maskz_1 */
    case 4311:  /* avx512vl_vpermi2varv8hi3_maskz_1 */
    case 4309:  /* avx512vl_vpermi2varv32qi3_maskz_1 */
    case 4307:  /* avx512vl_vpermi2varv16qi3_maskz_1 */
    case 4305:  /* avx512bw_vpermi2varv64qi3_maskz_1 */
    case 4303:  /* avx512vl_vpermi2varv2df3_maskz_1 */
    case 4301:  /* avx512vl_vpermi2varv2di3_maskz_1 */
    case 4299:  /* avx512vl_vpermi2varv4sf3_maskz_1 */
    case 4297:  /* avx512vl_vpermi2varv4si3_maskz_1 */
    case 4295:  /* avx512vl_vpermi2varv4df3_maskz_1 */
    case 4293:  /* avx512vl_vpermi2varv4di3_maskz_1 */
    case 4291:  /* avx512vl_vpermi2varv8sf3_maskz_1 */
    case 4289:  /* avx512vl_vpermi2varv8si3_maskz_1 */
    case 4287:  /* avx512f_vpermi2varv8df3_maskz_1 */
    case 4285:  /* avx512f_vpermi2varv8di3_maskz_1 */
    case 4283:  /* avx512f_vpermi2varv16sf3_maskz_1 */
    case 4281:  /* avx512f_vpermi2varv16si3_maskz_1 */
    case 3744:  /* ssse3_palignrv16qi_mask */
    case 3743:  /* avx2_palignrv32qi_mask */
    case 3742:  /* avx512bw_palignrv64qi_mask */
    case 2634:  /* avx512vl_alignv2di_mask */
    case 2632:  /* avx512vl_alignv4di_mask */
    case 2630:  /* avx512f_alignv8di_mask */
    case 2628:  /* avx512vl_alignv4si_mask */
    case 2626:  /* avx512vl_alignv8si_mask */
    case 2624:  /* avx512f_alignv16si_mask */
    case 2016:  /* fma_fmaddsub_v2df_maskz_1 */
    case 2014:  /* fma_fmaddsub_v4df_maskz_1 */
    case 2011:  /* fma_fmaddsub_v8df_maskz_1 */
    case 2007:  /* fma_fmaddsub_v4sf_maskz_1 */
    case 2005:  /* fma_fmaddsub_v8sf_maskz_1 */
    case 2002:  /* fma_fmaddsub_v16sf_maskz_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 1994:  /* avx512vl_fnmsub_v2df_mask3_round */
    case 1992:  /* avx512vl_fnmsub_v4df_mask3_round */
    case 1990:  /* avx512f_fnmsub_v8df_mask3_round */
    case 1988:  /* avx512vl_fnmsub_v4sf_mask3_round */
    case 1986:  /* avx512vl_fnmsub_v8sf_mask3_round */
    case 1984:  /* avx512f_fnmsub_v16sf_mask3_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 1993:  /* avx512vl_fnmsub_v2df_mask3 */
    case 1991:  /* avx512vl_fnmsub_v4df_mask3 */
    case 1989:  /* avx512f_fnmsub_v8df_mask3 */
    case 1987:  /* avx512vl_fnmsub_v4sf_mask3 */
    case 1985:  /* avx512vl_fnmsub_v8sf_mask3 */
    case 1983:  /* avx512f_fnmsub_v16sf_mask3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 1980:  /* avx512f_fnmsub_v8df_mask_round */
    case 1976:  /* avx512f_fnmsub_v16sf_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 1982:  /* avx512vl_fnmsub_v2df_mask */
    case 1981:  /* avx512vl_fnmsub_v4df_mask */
    case 1979:  /* avx512f_fnmsub_v8df_mask */
    case 1978:  /* avx512vl_fnmsub_v4sf_mask */
    case 1977:  /* avx512vl_fnmsub_v8sf_mask */
    case 1975:  /* avx512f_fnmsub_v16sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 1970:  /* fma_fnmsub_v8df_maskz_1_round */
    case 1961:  /* fma_fnmsub_v16sf_maskz_1_round */
    case 1956:  /* *fma_fnmsub_v4df */
    case 1952:  /* *fma_fnmsub_v8sf */
    case 1948:  /* *fma_fnmsub_v2df */
    case 1944:  /* *fma_fnmsub_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1974:  /* fma_fnmsub_v2df_maskz_1 */
    case 1972:  /* fma_fnmsub_v4df_maskz_1 */
    case 1969:  /* fma_fnmsub_v8df_maskz_1 */
    case 1965:  /* fma_fnmsub_v4sf_maskz_1 */
    case 1963:  /* fma_fnmsub_v8sf_maskz_1 */
    case 1960:  /* fma_fnmsub_v16sf_maskz_1 */
    case 1955:  /* *fma_fnmsub_v4df */
    case 1951:  /* *fma_fnmsub_v8sf */
    case 1947:  /* *fma_fnmsub_v2df */
    case 1943:  /* *fma_fnmsub_v4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 1968:  /* *fma_fnmsub_v8df_round */
    case 1959:  /* *fma_fnmsub_v16sf_round */
    case 1954:  /* *fma_fnmsub_v4df */
    case 1950:  /* *fma_fnmsub_v8sf */
    case 1946:  /* *fma_fnmsub_v2df */
    case 1942:  /* *fma_fnmsub_v4sf */
    case 1940:  /* *fma_fnmsub_df */
    case 1938:  /* *fma_fnmsub_sf */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2), 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1973:  /* *fma_fnmsub_v2df */
    case 1971:  /* *fma_fnmsub_v4df */
    case 1967:  /* *fma_fnmsub_v8df */
    case 1966:  /* *fma_fnmsub_df */
    case 1964:  /* *fma_fnmsub_v4sf */
    case 1962:  /* *fma_fnmsub_v8sf */
    case 1958:  /* *fma_fnmsub_v16sf */
    case 1957:  /* *fma_fnmsub_sf */
    case 1953:  /* *fma_fnmsub_v4df */
    case 1949:  /* *fma_fnmsub_v8sf */
    case 1945:  /* *fma_fnmsub_v2df */
    case 1941:  /* *fma_fnmsub_v4sf */
    case 1939:  /* *fma_fnmsub_df */
    case 1937:  /* *fma_fnmsub_sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 2), 0));
      break;

    case 1934:  /* avx512f_fnmadd_v8df_mask3_round */
    case 1930:  /* avx512f_fnmadd_v16sf_mask3_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 1936:  /* avx512vl_fnmadd_v2df_mask3 */
    case 1935:  /* avx512vl_fnmadd_v4df_mask3 */
    case 1933:  /* avx512f_fnmadd_v8df_mask3 */
    case 1932:  /* avx512vl_fnmadd_v4sf_mask3 */
    case 1931:  /* avx512vl_fnmadd_v8sf_mask3 */
    case 1929:  /* avx512f_fnmadd_v16sf_mask3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 1926:  /* avx512f_fnmadd_v8df_mask_round */
    case 1922:  /* avx512f_fnmadd_v16sf_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 1928:  /* avx512vl_fnmadd_v2df_mask */
    case 1927:  /* avx512vl_fnmadd_v4df_mask */
    case 1925:  /* avx512f_fnmadd_v8df_mask */
    case 1924:  /* avx512vl_fnmadd_v4sf_mask */
    case 1923:  /* avx512vl_fnmadd_v8sf_mask */
    case 1921:  /* avx512f_fnmadd_v16sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 1916:  /* fma_fnmadd_v8df_maskz_1_round */
    case 1907:  /* fma_fnmadd_v16sf_maskz_1_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1920:  /* fma_fnmadd_v2df_maskz_1 */
    case 1918:  /* fma_fnmadd_v4df_maskz_1 */
    case 1915:  /* fma_fnmadd_v8df_maskz_1 */
    case 1911:  /* fma_fnmadd_v4sf_maskz_1 */
    case 1909:  /* fma_fnmadd_v8sf_maskz_1 */
    case 1906:  /* fma_fnmadd_v16sf_maskz_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 1894:  /* avx512f_fmsub_v8df_mask3_round */
    case 1890:  /* avx512f_fmsub_v16sf_mask3_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 1896:  /* avx512vl_fmsub_v2df_mask3 */
    case 1895:  /* avx512vl_fmsub_v4df_mask3 */
    case 1893:  /* avx512f_fmsub_v8df_mask3 */
    case 1892:  /* avx512vl_fmsub_v4sf_mask3 */
    case 1891:  /* avx512vl_fmsub_v8sf_mask3 */
    case 1889:  /* avx512f_fmsub_v16sf_mask3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 1888:  /* avx512vl_fmsub_v2df_mask_round */
    case 1886:  /* avx512vl_fmsub_v4df_mask_round */
    case 1884:  /* avx512f_fmsub_v8df_mask_round */
    case 1882:  /* avx512vl_fmsub_v4sf_mask_round */
    case 1880:  /* avx512vl_fmsub_v8sf_mask_round */
    case 1878:  /* avx512f_fmsub_v16sf_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 1887:  /* avx512vl_fmsub_v2df_mask */
    case 1885:  /* avx512vl_fmsub_v4df_mask */
    case 1883:  /* avx512f_fmsub_v8df_mask */
    case 1881:  /* avx512vl_fmsub_v4sf_mask */
    case 1879:  /* avx512vl_fmsub_v8sf_mask */
    case 1877:  /* avx512f_fmsub_v16sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 1872:  /* fma_fmsub_v8df_maskz_1_round */
    case 1863:  /* fma_fmsub_v16sf_maskz_1_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1876:  /* fma_fmsub_v2df_maskz_1 */
    case 1874:  /* fma_fmsub_v4df_maskz_1 */
    case 1871:  /* fma_fmsub_v8df_maskz_1 */
    case 1867:  /* fma_fmsub_v4sf_maskz_1 */
    case 1865:  /* fma_fmsub_v8sf_maskz_1 */
    case 1862:  /* fma_fmsub_v16sf_maskz_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 1870:  /* *fma_fmsub_v8df_round */
    case 1861:  /* *fma_fmsub_v16sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2), 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1875:  /* *fma_fmsub_v2df */
    case 1873:  /* *fma_fmsub_v4df */
    case 1869:  /* *fma_fmsub_v8df */
    case 1868:  /* *fma_fmsub_df */
    case 1866:  /* *fma_fmsub_v4sf */
    case 1864:  /* *fma_fmsub_v8sf */
    case 1860:  /* *fma_fmsub_v16sf */
    case 1859:  /* *fma_fmsub_sf */
    case 1858:  /* *fma_fmsub_v4df */
    case 1857:  /* *fma_fmsub_v8sf */
    case 1856:  /* *fma_fmsub_v2df */
    case 1855:  /* *fma_fmsub_v4sf */
    case 1854:  /* *fma_fmsub_df */
    case 1853:  /* *fma_fmsub_sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 2), 0));
      break;

    case 1852:  /* avx512vl_fmadd_v2df_mask3_round */
    case 1850:  /* avx512vl_fmadd_v4df_mask3_round */
    case 1848:  /* avx512f_fmadd_v8df_mask3_round */
    case 1846:  /* avx512vl_fmadd_v4sf_mask3_round */
    case 1844:  /* avx512vl_fmadd_v8sf_mask3_round */
    case 1842:  /* avx512f_fmadd_v16sf_mask3_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 1851:  /* avx512vl_fmadd_v2df_mask3 */
    case 1849:  /* avx512vl_fmadd_v4df_mask3 */
    case 1847:  /* avx512f_fmadd_v8df_mask3 */
    case 1845:  /* avx512vl_fmadd_v4sf_mask3 */
    case 1843:  /* avx512vl_fmadd_v8sf_mask3 */
    case 1841:  /* avx512f_fmadd_v16sf_mask3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 3;
      break;

    case 1838:  /* avx512f_fmadd_v8df_mask_round */
    case 1834:  /* avx512f_fmadd_v16sf_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 1840:  /* avx512vl_fmadd_v2df_mask */
    case 1839:  /* avx512vl_fmadd_v4df_mask */
    case 1837:  /* avx512f_fmadd_v8df_mask */
    case 1836:  /* avx512vl_fmadd_v4sf_mask */
    case 1835:  /* avx512vl_fmadd_v8sf_mask */
    case 1833:  /* avx512f_fmadd_v16sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 1828:  /* fma_fmadd_v8df_maskz_1_round */
    case 1819:  /* fma_fmadd_v16sf_maskz_1_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[6] = *(ro_loc[6] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1832:  /* fma_fmadd_v2df_maskz_1 */
    case 1830:  /* fma_fmadd_v4df_maskz_1 */
    case 1827:  /* fma_fmadd_v8df_maskz_1 */
    case 1823:  /* fma_fmadd_v4sf_maskz_1 */
    case 1821:  /* fma_fmadd_v8sf_maskz_1 */
    case 1818:  /* fma_fmadd_v16sf_maskz_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 1826:  /* *fma_fmadd_v8df_round */
    case 1817:  /* *fma_fmadd_v16sf_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 4415:  /* vec_set_hi_v8sf_mask */
    case 4413:  /* vec_set_hi_v8si_mask */
    case 4407:  /* vec_set_hi_v4df_mask */
    case 4405:  /* vec_set_hi_v4di_mask */
    case 3603:  /* vec_set_hi_v8di_mask */
    case 3601:  /* vec_set_hi_v8df_mask */
    case 3595:  /* vec_set_hi_v16si_mask */
    case 3593:  /* vec_set_hi_v16sf_mask */
    case 3401:  /* *andnotv2di3_mask */
    case 3400:  /* *andnotv4di3_mask */
    case 3399:  /* *andnotv8di3_mask */
    case 3398:  /* *andnotv4si3_mask */
    case 3397:  /* *andnotv8si3_mask */
    case 3396:  /* *andnotv16si3_mask */
    case 2387:  /* *sse2_cvtpd2ps_mask */
    case 1760:  /* avx512f_andnotv8df3_mask */
    case 1758:  /* avx512f_andnotv16sf3_mask */
    case 1756:  /* sse2_andnotv2df3_mask */
    case 1754:  /* avx_andnotv4df3_mask */
    case 1752:  /* sse_andnotv4sf3_mask */
    case 1750:  /* avx_andnotv8sf3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 1748:  /* sse2_ucomi_round */
    case 1746:  /* sse_ucomi_round */
    case 1744:  /* sse2_comi_round */
    case 1742:  /* sse_comi_round */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1747:  /* sse2_ucomi */
    case 1745:  /* sse_ucomi */
    case 1743:  /* sse2_comi */
    case 1741:  /* sse_comi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      break;

    case 1734:  /* avx512f_vmcmpv2df3_mask_round */
    case 1732:  /* avx512f_vmcmpv4sf3_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1733:  /* avx512f_vmcmpv2df3_mask */
    case 1731:  /* avx512f_vmcmpv4sf3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      break;

    case 1730:  /* avx512f_vmcmpv2df3_round */
    case 1728:  /* avx512f_vmcmpv4sf3_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1729:  /* avx512f_vmcmpv2df3 */
    case 1727:  /* avx512f_vmcmpv4sf3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      break;

    case 1686:  /* avx512f_cmpv8df3_mask_round */
    case 1678:  /* avx512f_cmpv16sf3_mask_round */
    case 1670:  /* avx512f_cmpv8di3_mask_round */
    case 1662:  /* avx512f_cmpv16si3_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 4783:  /* avx512dq_rangepv8df_round */
    case 4775:  /* avx512dq_rangepv16sf_round */
    case 2010:  /* *fma_fmaddsub_v8df_round */
    case 2001:  /* *fma_fmaddsub_v16sf_round */
    case 1685:  /* avx512f_cmpv8df3_round */
    case 1677:  /* avx512f_cmpv16sf3_round */
    case 1669:  /* avx512f_cmpv8di3_round */
    case 1661:  /* avx512f_cmpv16si3_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1726:  /* avx512vl_ucmpv2di3_mask */
    case 1724:  /* avx512vl_ucmpv4di3_mask */
    case 1722:  /* avx512f_ucmpv8di3_mask */
    case 1720:  /* avx512vl_ucmpv4si3_mask */
    case 1718:  /* avx512vl_ucmpv8si3_mask */
    case 1716:  /* avx512f_ucmpv16si3_mask */
    case 1714:  /* avx512vl_ucmpv8hi3_mask */
    case 1712:  /* avx512vl_ucmpv16hi3_mask */
    case 1710:  /* avx512bw_ucmpv32hi3_mask */
    case 1708:  /* avx512vl_ucmpv32qi3_mask */
    case 1706:  /* avx512vl_ucmpv16qi3_mask */
    case 1704:  /* avx512bw_ucmpv64qi3_mask */
    case 1702:  /* avx512vl_cmpv8hi3_mask */
    case 1700:  /* avx512vl_cmpv16hi3_mask */
    case 1698:  /* avx512bw_cmpv32hi3_mask */
    case 1696:  /* avx512vl_cmpv32qi3_mask */
    case 1694:  /* avx512vl_cmpv16qi3_mask */
    case 1692:  /* avx512bw_cmpv64qi3_mask */
    case 1690:  /* avx512vl_cmpv2df3_mask */
    case 1688:  /* avx512vl_cmpv4df3_mask */
    case 1684:  /* avx512f_cmpv8df3_mask */
    case 1682:  /* avx512vl_cmpv4sf3_mask */
    case 1680:  /* avx512vl_cmpv8sf3_mask */
    case 1676:  /* avx512f_cmpv16sf3_mask */
    case 1674:  /* avx512vl_cmpv2di3_mask */
    case 1672:  /* avx512vl_cmpv4di3_mask */
    case 1668:  /* avx512f_cmpv8di3_mask */
    case 1666:  /* avx512vl_cmpv4si3_mask */
    case 1664:  /* avx512vl_cmpv8si3_mask */
    case 1660:  /* avx512f_cmpv16si3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 1658:  /* sse2_vmmaskcmpv2df3 */
    case 1657:  /* sse_vmmaskcmpv4sf3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 4834:  /* avx512f_vgetmantv2df */
    case 4832:  /* avx512f_vgetmantv4sf */
    case 4792:  /* avx512dq_rangesv2df */
    case 4790:  /* avx512dq_rangesv4sf */
    case 2709:  /* avx512f_rndscalev2df */
    case 2707:  /* avx512f_rndscalev4sf */
    case 1648:  /* avx_vmcmpv2df3 */
    case 1647:  /* avx_vmcmpv4sf3 */
    case 1642:  /* reducesv2df */
    case 1641:  /* reducesv4sf */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 4902:  /* vpmultishiftqbv32qi_mask */
    case 4900:  /* vpmultishiftqbv16qi_mask */
    case 4898:  /* vpmultishiftqbv64qi_mask */
    case 4830:  /* avx512vl_getmantv2df_mask */
    case 4826:  /* avx512vl_getmantv4df_mask */
    case 4822:  /* avx512f_getmantv8df_mask */
    case 4818:  /* avx512vl_getmantv4sf_mask */
    case 4814:  /* avx512vl_getmantv8sf_mask */
    case 4810:  /* avx512f_getmantv16sf_mask */
    case 4521:  /* avx512f_vcvtps2ph512_mask */
    case 4519:  /* vcvtps2ph256_mask */
    case 4279:  /* avx_vpermilvarv2df3_mask */
    case 4277:  /* avx_vpermilvarv4df3_mask */
    case 4275:  /* avx512f_vpermilvarv8df3_mask */
    case 4273:  /* avx_vpermilvarv4sf3_mask */
    case 4271:  /* avx_vpermilvarv8sf3_mask */
    case 4269:  /* avx512f_vpermilvarv16sf3_mask */
    case 4103:  /* avx512bw_permvarv32hi_mask */
    case 4101:  /* avx512vl_permvarv16hi_mask */
    case 4099:  /* avx512vl_permvarv8hi_mask */
    case 4097:  /* avx512vl_permvarv32qi_mask */
    case 4095:  /* avx512vl_permvarv16qi_mask */
    case 4093:  /* avx512bw_permvarv64qi_mask */
    case 4091:  /* avx2_permvarv4df_mask */
    case 4089:  /* avx2_permvarv4di_mask */
    case 4087:  /* avx512f_permvarv8df_mask */
    case 4085:  /* avx512f_permvarv8di_mask */
    case 4083:  /* avx512f_permvarv16sf_mask */
    case 4081:  /* avx512f_permvarv16si_mask */
    case 4079:  /* avx2_permvarv8sf_mask */
    case 4077:  /* avx2_permvarv8si_mask */
    case 3731:  /* ssse3_pshufbv16qi3_mask */
    case 3729:  /* avx2_pshufbv32qi3_mask */
    case 3727:  /* avx512bw_pshufbv64qi3_mask */
    case 3714:  /* avx512bw_pmaddubsw512v32hi_mask */
    case 3712:  /* avx512bw_pmaddubsw512v16hi_mask */
    case 3710:  /* avx512bw_pmaddubsw512v8hi_mask */
    case 3633:  /* avx512bw_pshufhwv32hi_mask */
    case 3627:  /* avx512bw_pshuflwv32hi_mask */
    case 3065:  /* avx512bw_pmaddwd512v8hi_mask */
    case 3063:  /* avx512bw_pmaddwd512v16hi_mask */
    case 3061:  /* avx512bw_pmaddwd512v32hi_mask */
    case 2705:  /* avx512vl_rndscalev2df_mask */
    case 2701:  /* avx512vl_rndscalev4df_mask */
    case 2697:  /* avx512f_rndscalev8df_mask */
    case 2693:  /* avx512vl_rndscalev4sf_mask */
    case 2689:  /* avx512vl_rndscalev8sf_mask */
    case 2685:  /* avx512f_rndscalev16sf_mask */
    case 2575:  /* avx512vl_scalefv2df_mask */
    case 2571:  /* avx512vl_scalefv4df_mask */
    case 2567:  /* avx512f_scalefv8df_mask */
    case 2563:  /* avx512vl_scalefv4sf_mask */
    case 2559:  /* avx512vl_scalefv8sf_mask */
    case 2555:  /* avx512f_scalefv16sf_mask */
    case 1640:  /* reducepv2df_mask */
    case 1638:  /* reducepv4df_mask */
    case 1636:  /* reducepv8df_mask */
    case 1634:  /* reducepv4sf_mask */
    case 1632:  /* reducepv8sf_mask */
    case 1630:  /* reducepv16sf_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3705:  /* ssse3_phsubdv4si3 */
    case 3704:  /* ssse3_phadddv4si3 */
    case 3701:  /* ssse3_phsubswv4hi3 */
    case 3700:  /* ssse3_phsubwv4hi3 */
    case 3699:  /* ssse3_phaddswv4hi3 */
    case 3698:  /* ssse3_phaddwv4hi3 */
    case 1628:  /* sse3_hsubv4sf3 */
    case 1627:  /* sse3_haddv4sf3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0);
      recog_data.dup_num[1] = 1;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 0);
      recog_data.dup_num[2] = 1;
      recog_data.dup_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 0);
      recog_data.dup_num[3] = 2;
      recog_data.dup_loc[4] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 0);
      recog_data.dup_num[4] = 2;
      recog_data.dup_loc[5] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 0);
      recog_data.dup_num[5] = 2;
      break;

    case 1626:  /* avx_hsubv8sf3 */
    case 1625:  /* avx_haddv8sf3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0), 0);
      recog_data.dup_num[1] = 1;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 1), 0);
      recog_data.dup_num[2] = 1;
      recog_data.dup_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 1), 0);
      recog_data.dup_num[3] = 2;
      recog_data.dup_loc[4] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 0), 0);
      recog_data.dup_num[4] = 2;
      recog_data.dup_loc[5] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 1), 0);
      recog_data.dup_num[5] = 2;
      recog_data.dup_loc[6] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 0), 0);
      recog_data.dup_num[6] = 1;
      recog_data.dup_loc[7] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 1), 0);
      recog_data.dup_num[7] = 1;
      recog_data.dup_loc[8] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 0), 0);
      recog_data.dup_num[8] = 1;
      recog_data.dup_loc[9] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 1), 0);
      recog_data.dup_num[9] = 1;
      recog_data.dup_loc[10] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 0), 0);
      recog_data.dup_num[10] = 2;
      recog_data.dup_loc[11] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 1), 0);
      recog_data.dup_num[11] = 2;
      recog_data.dup_loc[12] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 0), 0);
      recog_data.dup_num[12] = 2;
      recog_data.dup_loc[13] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 1), 0);
      recog_data.dup_num[13] = 2;
      break;

    case 1624:  /* *sse3_hsubv2df3_low */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 1623:  /* *sse3_haddv2df3_low */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 1621:  /* *sse3_haddv2df3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 0, 0));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 0, 0));
      ro[6] = *(ro_loc[6] = &XVECEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0);
      recog_data.dup_num[1] = 2;
      break;

    case 1620:  /* avx_hsubv4df3 */
    case 1619:  /* avx_haddv4df3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 1), 0);
      recog_data.dup_num[1] = 2;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 0);
      recog_data.dup_num[2] = 1;
      recog_data.dup_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 1), 0);
      recog_data.dup_num[3] = 1;
      recog_data.dup_loc[4] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 0);
      recog_data.dup_num[4] = 2;
      recog_data.dup_loc[5] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 1), 0);
      recog_data.dup_num[5] = 2;
      break;

    case 1497:  /* sse2_vmsqrtv2df2_round */
    case 1495:  /* sse_vmsqrtv4sf2_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 2391:  /* avx512f_cvtps2pd512_mask_round */
    case 2383:  /* avx512f_cvtpd2ps512_mask_round */
    case 2361:  /* ufix_truncv8sfv8di2_mask_round */
    case 2357:  /* fix_truncv8sfv8di2_mask_round */
    case 2329:  /* ufix_truncv8dfv8di2_mask_round */
    case 2325:  /* fix_truncv8dfv8di2_mask_round */
    case 2315:  /* ufix_truncv8dfv8si2_mask_round */
    case 2311:  /* fix_truncv8dfv8si2_mask_round */
    case 2270:  /* ufloatv8div8sf2_mask_round */
    case 2266:  /* floatv8div8sf2_mask_round */
    case 2262:  /* ufloatv2div2df2_mask_round */
    case 2258:  /* floatv2div2df2_mask_round */
    case 2254:  /* ufloatv4div4df2_mask_round */
    case 2250:  /* floatv4div4df2_mask_round */
    case 2246:  /* ufloatv8div8df2_mask_round */
    case 2242:  /* floatv8div8df2_mask_round */
    case 2198:  /* ufix_truncv16sfv16si2_mask_round */
    case 2194:  /* fix_truncv16sfv16si2_mask_round */
    case 2154:  /* ufloatv4siv4sf2_mask_round */
    case 2150:  /* ufloatv8siv8sf2_mask_round */
    case 2146:  /* ufloatv16siv16sf2_mask_round */
    case 2138:  /* floatv16siv16sf2_mask_round */
    case 1914:  /* *fma_fnmadd_v8df_round */
    case 1905:  /* *fma_fnmadd_v16sf_round */
    case 1489:  /* avx512f_sqrtv8df2_mask_round */
    case 1481:  /* avx512f_sqrtv16sf2_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 4853:  /* clzv2di2_mask */
    case 4851:  /* clzv4di2_mask */
    case 4849:  /* clzv8di2_mask */
    case 4847:  /* clzv4si2_mask */
    case 4845:  /* clzv8si2_mask */
    case 4843:  /* clzv16si2_mask */
    case 4246:  /* avx512dq_broadcastv4df_mask_1 */
    case 4244:  /* avx512dq_broadcastv4di_mask_1 */
    case 4242:  /* avx512dq_broadcastv8df_mask_1 */
    case 4240:  /* avx512dq_broadcastv8di_mask_1 */
    case 4238:  /* avx512dq_broadcastv16si_mask_1 */
    case 4236:  /* avx512dq_broadcastv16sf_mask_1 */
    case 4234:  /* avx512vl_broadcastv8sf_mask_1 */
    case 4232:  /* avx512vl_broadcastv8si_mask_1 */
    case 4197:  /* avx512vl_vec_dup_gprv2df_mask */
    case 4195:  /* avx512vl_vec_dup_gprv4df_mask */
    case 4193:  /* avx512f_vec_dup_gprv8df_mask */
    case 4191:  /* avx512vl_vec_dup_gprv4sf_mask */
    case 4189:  /* avx512vl_vec_dup_gprv8sf_mask */
    case 4187:  /* avx512f_vec_dup_gprv16sf_mask */
    case 4185:  /* avx512vl_vec_dup_gprv2di_mask */
    case 4183:  /* avx512vl_vec_dup_gprv4di_mask */
    case 4181:  /* avx512f_vec_dup_gprv8di_mask */
    case 4179:  /* avx512vl_vec_dup_gprv4si_mask */
    case 4177:  /* avx512vl_vec_dup_gprv8si_mask */
    case 4175:  /* avx512f_vec_dup_gprv16si_mask */
    case 4173:  /* avx512vl_vec_dup_gprv8hi_mask */
    case 4171:  /* avx512vl_vec_dup_gprv16hi_mask */
    case 4169:  /* avx512bw_vec_dup_gprv32hi_mask */
    case 4167:  /* avx512vl_vec_dup_gprv32qi_mask */
    case 4165:  /* avx512vl_vec_dup_gprv16qi_mask */
    case 4163:  /* avx512bw_vec_dup_gprv64qi_mask */
    case 4161:  /* avx512f_broadcastv8di_mask */
    case 4159:  /* avx512f_broadcastv8df_mask */
    case 4157:  /* avx512f_broadcastv16si_mask */
    case 4155:  /* avx512f_broadcastv16sf_mask */
    case 3881:  /* avx2_zero_extendv4siv4di2_mask */
    case 3879:  /* avx2_sign_extendv4siv4di2_mask */
    case 3877:  /* avx512f_zero_extendv8siv8di2_mask */
    case 3875:  /* avx512f_sign_extendv8siv8di2_mask */
    case 3865:  /* avx512f_zero_extendv8hiv8di2_mask */
    case 3863:  /* avx512f_sign_extendv8hiv8di2_mask */
    case 3845:  /* avx2_zero_extendv8hiv8si2_mask */
    case 3843:  /* avx2_sign_extendv8hiv8si2_mask */
    case 3841:  /* avx512f_zero_extendv16hiv16si2_mask */
    case 3839:  /* avx512f_sign_extendv16hiv16si2_mask */
    case 3829:  /* avx512f_zero_extendv16qiv16si2_mask */
    case 3827:  /* avx512f_sign_extendv16qiv16si2_mask */
    case 3821:  /* avx512bw_zero_extendv32qiv32hi2_mask */
    case 3819:  /* avx512bw_sign_extendv32qiv32hi2_mask */
    case 3817:  /* avx2_zero_extendv16qiv16hi2_mask */
    case 3815:  /* avx2_sign_extendv16qiv16hi2_mask */
    case 3772:  /* absv8hi2_mask */
    case 3771:  /* absv16hi2_mask */
    case 3770:  /* absv32hi2_mask */
    case 3769:  /* absv32qi2_mask */
    case 3768:  /* absv16qi2_mask */
    case 3767:  /* absv64qi2_mask */
    case 3766:  /* absv2di2_mask */
    case 3765:  /* absv4di2_mask */
    case 3764:  /* absv8di2_mask */
    case 3763:  /* absv4si2_mask */
    case 3762:  /* absv8si2_mask */
    case 3761:  /* absv16si2_mask */
    case 2789:  /* avx512vl_us_truncatev16hiv16qi2_mask */
    case 2788:  /* avx512vl_truncatev16hiv16qi2_mask */
    case 2787:  /* avx512vl_ss_truncatev16hiv16qi2_mask */
    case 2786:  /* avx512vl_us_truncatev8siv8hi2_mask */
    case 2785:  /* avx512vl_truncatev8siv8hi2_mask */
    case 2784:  /* avx512vl_ss_truncatev8siv8hi2_mask */
    case 2783:  /* avx512vl_us_truncatev4div4si2_mask */
    case 2782:  /* avx512vl_truncatev4div4si2_mask */
    case 2781:  /* avx512vl_ss_truncatev4div4si2_mask */
    case 2771:  /* avx512bw_us_truncatev32hiv32qi2_mask */
    case 2770:  /* avx512bw_truncatev32hiv32qi2_mask */
    case 2769:  /* avx512bw_ss_truncatev32hiv32qi2_mask */
    case 2765:  /* avx512f_us_truncatev8div8hi2_mask */
    case 2764:  /* avx512f_truncatev8div8hi2_mask */
    case 2763:  /* avx512f_ss_truncatev8div8hi2_mask */
    case 2762:  /* avx512f_us_truncatev8div8si2_mask */
    case 2761:  /* avx512f_truncatev8div8si2_mask */
    case 2760:  /* avx512f_ss_truncatev8div8si2_mask */
    case 2759:  /* avx512f_us_truncatev16siv16hi2_mask */
    case 2758:  /* avx512f_truncatev16siv16hi2_mask */
    case 2757:  /* avx512f_ss_truncatev16siv16hi2_mask */
    case 2756:  /* avx512f_us_truncatev16siv16qi2_mask */
    case 2755:  /* avx512f_truncatev16siv16qi2_mask */
    case 2754:  /* avx512f_ss_truncatev16siv16qi2_mask */
    case 2740:  /* vec_dupv2df_mask */
    case 2528:  /* vec_extract_hi_v8sf_mask */
    case 2526:  /* vec_extract_hi_v8si_mask */
    case 2524:  /* vec_extract_hi_v8sf_maskm */
    case 2523:  /* vec_extract_hi_v8si_maskm */
    case 2522:  /* vec_extract_lo_v8sf_maskm */
    case 2521:  /* vec_extract_lo_v8si_maskm */
    case 2520:  /* vec_extract_lo_v8sf_mask */
    case 2518:  /* vec_extract_lo_v8si_mask */
    case 2514:  /* vec_extract_hi_v4df_mask */
    case 2513:  /* vec_extract_hi_v4di_mask */
    case 2512:  /* vec_extract_hi_v4df_maskm */
    case 2511:  /* vec_extract_hi_v4di_maskm */
    case 2510:  /* vec_extract_lo_v4df_mask */
    case 2508:  /* vec_extract_lo_v4di_mask */
    case 2506:  /* vec_extract_lo_v16si_mask */
    case 2504:  /* vec_extract_lo_v16sf_mask */
    case 2502:  /* vec_extract_hi_v16si_mask */
    case 2500:  /* vec_extract_hi_v16sf_mask */
    case 2498:  /* vec_extract_hi_v16si_maskm */
    case 2497:  /* vec_extract_hi_v16sf_maskm */
    case 2496:  /* vec_extract_hi_v8di_mask */
    case 2494:  /* vec_extract_hi_v8df_mask */
    case 2492:  /* vec_extract_hi_v8di_maskm */
    case 2491:  /* vec_extract_hi_v8df_maskm */
    case 2490:  /* vec_extract_lo_v8di_mask */
    case 2488:  /* vec_extract_lo_v8df_mask */
    case 2486:  /* vec_extract_lo_v8di_maskm */
    case 2485:  /* vec_extract_lo_v8df_maskm */
    case 2393:  /* avx_cvtps2pd256_mask */
    case 2390:  /* avx512f_cvtps2pd512_mask */
    case 2385:  /* avx_cvtpd2ps256_mask */
    case 2382:  /* avx512f_cvtpd2ps512_mask */
    case 2373:  /* ufix_truncv4sfv4si2_mask */
    case 2371:  /* ufix_truncv8sfv8si2_mask */
    case 2365:  /* ufix_truncv4sfv4di2_mask */
    case 2363:  /* fix_truncv4sfv4di2_mask */
    case 2360:  /* ufix_truncv8sfv8di2_mask */
    case 2356:  /* fix_truncv8sfv8di2_mask */
    case 2337:  /* ufix_truncv2dfv2di2_mask */
    case 2335:  /* fix_truncv2dfv2di2_mask */
    case 2333:  /* ufix_truncv4dfv4di2_mask */
    case 2331:  /* fix_truncv4dfv4di2_mask */
    case 2328:  /* ufix_truncv8dfv8di2_mask */
    case 2324:  /* fix_truncv8dfv8di2_mask */
    case 2321:  /* ufix_truncv4dfv4si2_mask */
    case 2319:  /* fix_truncv4dfv4si2_mask */
    case 2314:  /* ufix_truncv8dfv8si2_mask */
    case 2310:  /* fix_truncv8dfv8si2_mask */
    case 2282:  /* ufloatv4siv4df2_mask */
    case 2280:  /* ufloatv8siv8df2_mask */
    case 2274:  /* ufloatv4div4sf2_mask */
    case 2272:  /* floatv4div4sf2_mask */
    case 2269:  /* ufloatv8div8sf2_mask */
    case 2265:  /* floatv8div8sf2_mask */
    case 2261:  /* ufloatv2div2df2_mask */
    case 2257:  /* floatv2div2df2_mask */
    case 2253:  /* ufloatv4div4df2_mask */
    case 2249:  /* floatv4div4df2_mask */
    case 2245:  /* ufloatv8div8df2_mask */
    case 2241:  /* floatv8div8df2_mask */
    case 2238:  /* floatv4siv4df2_mask */
    case 2236:  /* floatv8siv8df2_mask */
    case 2202:  /* fix_truncv4sfv4si2_mask */
    case 2200:  /* fix_truncv8sfv8si2_mask */
    case 2197:  /* ufix_truncv16sfv16si2_mask */
    case 2193:  /* fix_truncv16sfv16si2_mask */
    case 2153:  /* ufloatv4siv4sf2_mask */
    case 2149:  /* ufloatv8siv8sf2_mask */
    case 2145:  /* ufloatv16siv16sf2_mask */
    case 2142:  /* floatv4siv4sf2_mask */
    case 2140:  /* floatv8siv8sf2_mask */
    case 2137:  /* floatv16siv16sf2_mask */
    case 1919:  /* *fma_fnmadd_v2df */
    case 1917:  /* *fma_fnmadd_v4df */
    case 1913:  /* *fma_fnmadd_v8df */
    case 1912:  /* *fma_fnmadd_df */
    case 1910:  /* *fma_fnmadd_v4sf */
    case 1908:  /* *fma_fnmadd_v8sf */
    case 1904:  /* *fma_fnmadd_v16sf */
    case 1903:  /* *fma_fnmadd_sf */
    case 1902:  /* *fma_fnmadd_v4df */
    case 1901:  /* *fma_fnmadd_v8sf */
    case 1900:  /* *fma_fnmadd_v2df */
    case 1899:  /* *fma_fnmadd_v4sf */
    case 1898:  /* *fma_fnmadd_df */
    case 1897:  /* *fma_fnmadd_sf */
    case 1493:  /* sse2_sqrtv2df2_mask */
    case 1491:  /* avx_sqrtv4df2_mask */
    case 1488:  /* avx512f_sqrtv8df2_mask */
    case 1485:  /* sse_sqrtv4sf2_mask */
    case 1483:  /* avx_sqrtv8sf2_mask */
    case 1480:  /* avx512f_sqrtv16sf2_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 4030:  /* *xop_vmfrczv2df2 */
    case 4029:  /* *xop_vmfrczv4sf2 */
    case 3954:  /* avx512er_vmrsqrt28v2df */
    case 3952:  /* avx512er_vmrsqrt28v4sf */
    case 3942:  /* avx512er_vmrcp28v2df */
    case 3940:  /* avx512er_vmrcp28v4sf */
    case 2295:  /* *avx_cvtpd2dq256_2 */
    case 1514:  /* sse_vmrsqrtv4sf2 */
    case 1513:  /* rsqrt14v2df */
    case 1512:  /* rsqrt14v4sf */
    case 1477:  /* srcp14v2df */
    case 1476:  /* srcp14v4sf */
    case 1463:  /* sse_vmrcpv4sf2 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 1602:  /* sse2_vmsminv2df3_round */
    case 1600:  /* sse2_vmsmaxv2df3_round */
    case 1598:  /* sse_vmsminv4sf3_round */
    case 1596:  /* sse_vmsmaxv4sf3_round */
    case 1444:  /* sse2_vmdivv2df3_round */
    case 1442:  /* sse2_vmmulv2df3_round */
    case 1440:  /* sse_vmdivv4sf3_round */
    case 1438:  /* sse_vmmulv4sf3_round */
    case 1412:  /* sse2_vmsubv2df3_round */
    case 1410:  /* sse2_vmaddv2df3_round */
    case 1408:  /* sse_vmsubv4sf3_round */
    case 1406:  /* sse_vmaddv4sf3_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 1601:  /* sse2_vmsminv2df3 */
    case 1599:  /* sse2_vmsmaxv2df3 */
    case 1597:  /* sse_vmsminv4sf3 */
    case 1595:  /* sse_vmsmaxv4sf3 */
    case 1443:  /* sse2_vmdivv2df3 */
    case 1441:  /* sse2_vmmulv2df3 */
    case 1439:  /* sse_vmdivv4sf3 */
    case 1437:  /* sse_vmmulv4sf3 */
    case 1411:  /* sse2_vmsubv2df3 */
    case 1409:  /* sse2_vmaddv2df3 */
    case 1407:  /* sse_vmsubv4sf3 */
    case 1405:  /* sse_vmaddv4sf3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 1586:  /* *sminv8df3_mask_round */
    case 1582:  /* *smaxv8df3_mask_round */
    case 1570:  /* *sminv16sf3_mask_round */
    case 1566:  /* *smaxv16sf3_mask_round */
    case 1562:  /* *sminv2df3_finite_mask_round */
    case 1558:  /* *smaxv2df3_finite_mask_round */
    case 1554:  /* *sminv4df3_finite_mask_round */
    case 1550:  /* *smaxv4df3_finite_mask_round */
    case 1546:  /* *sminv8df3_finite_mask_round */
    case 1542:  /* *smaxv8df3_finite_mask_round */
    case 1538:  /* *sminv4sf3_finite_mask_round */
    case 1534:  /* *smaxv4sf3_finite_mask_round */
    case 1530:  /* *sminv8sf3_finite_mask_round */
    case 1526:  /* *smaxv8sf3_finite_mask_round */
    case 1522:  /* *sminv16sf3_finite_mask_round */
    case 1518:  /* *smaxv16sf3_finite_mask_round */
    case 1456:  /* avx512f_divv8df3_mask_round */
    case 1448:  /* avx512f_divv16sf3_mask_round */
    case 1436:  /* *mulv2df3_mask_round */
    case 1432:  /* *mulv4df3_mask_round */
    case 1428:  /* *mulv8df3_mask_round */
    case 1424:  /* *mulv4sf3_mask_round */
    case 1420:  /* *mulv8sf3_mask_round */
    case 1416:  /* *mulv16sf3_mask_round */
    case 1404:  /* *subv2df3_mask_round */
    case 1400:  /* *addv2df3_mask_round */
    case 1396:  /* *subv4df3_mask_round */
    case 1392:  /* *addv4df3_mask_round */
    case 1388:  /* *subv8df3_mask_round */
    case 1384:  /* *addv8df3_mask_round */
    case 1380:  /* *subv4sf3_mask_round */
    case 1376:  /* *addv4sf3_mask_round */
    case 1372:  /* *subv8sf3_mask_round */
    case 1368:  /* *addv8sf3_mask_round */
    case 1364:  /* *subv16sf3_mask_round */
    case 1360:  /* *addv16sf3_mask_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 4492:  /* avx512bw_lshrvv32hi_mask */
    case 4490:  /* avx512bw_ashlvv32hi_mask */
    case 4488:  /* avx512vl_lshrvv16hi_mask */
    case 4486:  /* avx512vl_ashlvv16hi_mask */
    case 4484:  /* avx512vl_lshrvv8hi_mask */
    case 4482:  /* avx512vl_ashlvv8hi_mask */
    case 4480:  /* avx2_lshrvv2di_mask */
    case 4478:  /* avx2_ashlvv2di_mask */
    case 4476:  /* avx2_lshrvv4di_mask */
    case 4474:  /* avx2_ashlvv4di_mask */
    case 4472:  /* avx512f_lshrvv8di_mask */
    case 4470:  /* avx512f_ashlvv8di_mask */
    case 4468:  /* avx2_lshrvv4si_mask */
    case 4466:  /* avx2_ashlvv4si_mask */
    case 4464:  /* avx2_lshrvv8si_mask */
    case 4462:  /* avx2_ashlvv8si_mask */
    case 4460:  /* avx512f_lshrvv16si_mask */
    case 4458:  /* avx512f_ashlvv16si_mask */
    case 4456:  /* avx512bw_ashrvv32hi_mask */
    case 4454:  /* avx512vl_ashrvv16hi_mask */
    case 4452:  /* avx512vl_ashrvv8hi_mask */
    case 4450:  /* avx512f_ashrvv8di_mask */
    case 4448:  /* avx2_ashrvv4di_mask */
    case 4446:  /* avx2_ashrvv2di_mask */
    case 4444:  /* avx512f_ashrvv16si_mask */
    case 4442:  /* avx2_ashrvv8si_mask */
    case 4440:  /* avx2_ashrvv4si_mask */
    case 3473:  /* *xorv8hi3 */
    case 3471:  /* *iorv8hi3 */
    case 3469:  /* *andv8hi3 */
    case 3467:  /* *xorv16hi3 */
    case 3465:  /* *iorv16hi3 */
    case 3463:  /* *andv16hi3 */
    case 3461:  /* *xorv32hi3 */
    case 3459:  /* *iorv32hi3 */
    case 3457:  /* *andv32hi3 */
    case 3455:  /* *xorv16qi3 */
    case 3453:  /* *iorv16qi3 */
    case 3451:  /* *andv16qi3 */
    case 3449:  /* *xorv32qi3 */
    case 3447:  /* *iorv32qi3 */
    case 3445:  /* *andv32qi3 */
    case 3443:  /* *xorv64qi3 */
    case 3441:  /* *iorv64qi3 */
    case 3439:  /* *andv64qi3 */
    case 3437:  /* xorv2di3_mask */
    case 3435:  /* iorv2di3_mask */
    case 3433:  /* andv2di3_mask */
    case 3431:  /* xorv4di3_mask */
    case 3429:  /* iorv4di3_mask */
    case 3427:  /* andv4di3_mask */
    case 3425:  /* xorv8di3_mask */
    case 3423:  /* iorv8di3_mask */
    case 3421:  /* andv8di3_mask */
    case 3419:  /* xorv4si3_mask */
    case 3417:  /* iorv4si3_mask */
    case 3415:  /* andv4si3_mask */
    case 3413:  /* xorv8si3_mask */
    case 3411:  /* iorv8si3_mask */
    case 3409:  /* andv8si3_mask */
    case 3407:  /* xorv16si3_mask */
    case 3405:  /* iorv16si3_mask */
    case 3403:  /* andv16si3_mask */
    case 3317:  /* *sse4_1_uminv4si3_mask */
    case 3315:  /* *sse4_1_umaxv4si3_mask */
    case 3313:  /* *sse4_1_uminv8hi3_mask */
    case 3311:  /* *sse4_1_umaxv8hi3_mask */
    case 3307:  /* *sse4_1_sminv4si3_mask */
    case 3305:  /* *sse4_1_smaxv4si3_mask */
    case 3303:  /* *sse4_1_sminv16qi3_mask */
    case 3301:  /* *sse4_1_smaxv16qi3_mask */
    case 3299:  /* uminv8hi3_mask */
    case 3297:  /* umaxv8hi3_mask */
    case 3295:  /* sminv8hi3_mask */
    case 3293:  /* smaxv8hi3_mask */
    case 3291:  /* uminv16hi3_mask */
    case 3289:  /* umaxv16hi3_mask */
    case 3287:  /* sminv16hi3_mask */
    case 3285:  /* smaxv16hi3_mask */
    case 3283:  /* uminv32hi3_mask */
    case 3281:  /* umaxv32hi3_mask */
    case 3279:  /* sminv32hi3_mask */
    case 3277:  /* smaxv32hi3_mask */
    case 3275:  /* uminv32qi3_mask */
    case 3273:  /* umaxv32qi3_mask */
    case 3271:  /* sminv32qi3_mask */
    case 3269:  /* smaxv32qi3_mask */
    case 3267:  /* uminv16qi3_mask */
    case 3265:  /* umaxv16qi3_mask */
    case 3263:  /* sminv16qi3_mask */
    case 3261:  /* smaxv16qi3_mask */
    case 3259:  /* uminv64qi3_mask */
    case 3257:  /* umaxv64qi3_mask */
    case 3255:  /* sminv64qi3_mask */
    case 3253:  /* smaxv64qi3_mask */
    case 3251:  /* *avx512f_uminv2di3_mask */
    case 3249:  /* *avx512f_umaxv2di3_mask */
    case 3247:  /* *avx512f_sminv2di3_mask */
    case 3245:  /* *avx512f_smaxv2di3_mask */
    case 3243:  /* *avx512f_uminv4di3_mask */
    case 3241:  /* *avx512f_umaxv4di3_mask */
    case 3239:  /* *avx512f_sminv4di3_mask */
    case 3237:  /* *avx512f_smaxv4di3_mask */
    case 3235:  /* *avx512f_uminv8di3_mask */
    case 3233:  /* *avx512f_umaxv8di3_mask */
    case 3231:  /* *avx512f_sminv8di3_mask */
    case 3229:  /* *avx512f_smaxv8di3_mask */
    case 3227:  /* *avx512f_uminv4si3_mask */
    case 3225:  /* *avx512f_umaxv4si3_mask */
    case 3223:  /* *avx512f_sminv4si3_mask */
    case 3221:  /* *avx512f_smaxv4si3_mask */
    case 3219:  /* *avx512f_uminv8si3_mask */
    case 3217:  /* *avx512f_umaxv8si3_mask */
    case 3215:  /* *avx512f_sminv8si3_mask */
    case 3213:  /* *avx512f_smaxv8si3_mask */
    case 3211:  /* *avx512f_uminv16si3_mask */
    case 3209:  /* *avx512f_umaxv16si3_mask */
    case 3207:  /* *avx512f_sminv16si3_mask */
    case 3205:  /* *avx512f_smaxv16si3_mask */
    case 3191:  /* avx512vl_rorv2di_mask */
    case 3189:  /* avx512vl_rolv2di_mask */
    case 3187:  /* avx512vl_rorv4di_mask */
    case 3185:  /* avx512vl_rolv4di_mask */
    case 3183:  /* avx512f_rorv8di_mask */
    case 3181:  /* avx512f_rolv8di_mask */
    case 3179:  /* avx512vl_rorv4si_mask */
    case 3177:  /* avx512vl_rolv4si_mask */
    case 3175:  /* avx512vl_rorv8si_mask */
    case 3173:  /* avx512vl_rolv8si_mask */
    case 3171:  /* avx512f_rorv16si_mask */
    case 3169:  /* avx512f_rolv16si_mask */
    case 3167:  /* avx512vl_rorvv2di_mask */
    case 3165:  /* avx512vl_rolvv2di_mask */
    case 3163:  /* avx512vl_rorvv4di_mask */
    case 3161:  /* avx512vl_rolvv4di_mask */
    case 3159:  /* avx512f_rorvv8di_mask */
    case 3157:  /* avx512f_rolvv8di_mask */
    case 3155:  /* avx512vl_rorvv4si_mask */
    case 3153:  /* avx512vl_rolvv4si_mask */
    case 3151:  /* avx512vl_rorvv8si_mask */
    case 3149:  /* avx512vl_rolvv8si_mask */
    case 3147:  /* avx512f_rorvv16si_mask */
    case 3145:  /* avx512f_rolvv16si_mask */
    case 3137:  /* lshrv8di3_mask */
    case 3135:  /* ashlv8di3_mask */
    case 3133:  /* lshrv16si3_mask */
    case 3131:  /* ashlv16si3_mask */
    case 3129:  /* lshrv2di3_mask */
    case 3127:  /* ashlv2di3_mask */
    case 3125:  /* lshrv4di3_mask */
    case 3123:  /* ashlv4di3_mask */
    case 3121:  /* lshrv4si3_mask */
    case 3119:  /* ashlv4si3_mask */
    case 3117:  /* lshrv8si3_mask */
    case 3115:  /* ashlv8si3_mask */
    case 3113:  /* lshrv8hi3_mask */
    case 3111:  /* ashlv8hi3_mask */
    case 3109:  /* lshrv16hi3_mask */
    case 3107:  /* ashlv16hi3_mask */
    case 3105:  /* lshrv32hi3_mask */
    case 3103:  /* ashlv32hi3_mask */
    case 3101:  /* ashrv8di3_mask */
    case 3099:  /* ashrv16si3_mask */
    case 3097:  /* ashrv4di3_mask */
    case 3095:  /* ashrv32hi3_mask */
    case 3093:  /* ashrv2di3_mask */
    case 3091:  /* ashrv4si3_mask */
    case 3089:  /* ashrv8si3_mask */
    case 3087:  /* ashrv8hi3_mask */
    case 3085:  /* ashrv16hi3_mask */
    case 3079:  /* *sse4_1_mulv4si3_mask */
    case 3077:  /* *avx2_mulv8si3_mask */
    case 3075:  /* *avx512f_mulv16si3_mask */
    case 3073:  /* avx512dq_mulv2di3_mask */
    case 3071:  /* avx512dq_mulv4di3_mask */
    case 3069:  /* avx512dq_mulv8di3_mask */
    case 3035:  /* *mulv8hi3_mask */
    case 3033:  /* *mulv16hi3_mask */
    case 3031:  /* *mulv32hi3_mask */
    case 3029:  /* *sse2_ussubv8hi3_mask */
    case 3027:  /* *sse2_sssubv8hi3_mask */
    case 3025:  /* *sse2_usaddv8hi3_mask */
    case 3023:  /* *sse2_ssaddv8hi3_mask */
    case 3021:  /* *avx2_ussubv16hi3_mask */
    case 3019:  /* *avx2_sssubv16hi3_mask */
    case 3017:  /* *avx2_usaddv16hi3_mask */
    case 3015:  /* *avx2_ssaddv16hi3_mask */
    case 3013:  /* *avx512bw_ussubv32hi3_mask */
    case 3011:  /* *avx512bw_sssubv32hi3_mask */
    case 3009:  /* *avx512bw_usaddv32hi3_mask */
    case 3007:  /* *avx512bw_ssaddv32hi3_mask */
    case 3005:  /* *sse2_ussubv16qi3_mask */
    case 3003:  /* *sse2_sssubv16qi3_mask */
    case 3001:  /* *sse2_usaddv16qi3_mask */
    case 2999:  /* *sse2_ssaddv16qi3_mask */
    case 2997:  /* *avx2_ussubv32qi3_mask */
    case 2995:  /* *avx2_sssubv32qi3_mask */
    case 2993:  /* *avx2_usaddv32qi3_mask */
    case 2991:  /* *avx2_ssaddv32qi3_mask */
    case 2989:  /* *avx512bw_ussubv64qi3_mask */
    case 2987:  /* *avx512bw_sssubv64qi3_mask */
    case 2985:  /* *avx512bw_usaddv64qi3_mask */
    case 2983:  /* *avx512bw_ssaddv64qi3_mask */
    case 2981:  /* *subv8hi3_mask */
    case 2980:  /* *addv8hi3_mask */
    case 2979:  /* *subv16hi3_mask */
    case 2978:  /* *addv16hi3_mask */
    case 2977:  /* *subv32hi3_mask */
    case 2976:  /* *addv32hi3_mask */
    case 2975:  /* *subv32qi3_mask */
    case 2974:  /* *addv32qi3_mask */
    case 2973:  /* *subv16qi3_mask */
    case 2972:  /* *addv16qi3_mask */
    case 2971:  /* *subv64qi3_mask */
    case 2970:  /* *addv64qi3_mask */
    case 2969:  /* *subv2di3_mask */
    case 2968:  /* *addv2di3_mask */
    case 2967:  /* *subv4di3_mask */
    case 2966:  /* *addv4di3_mask */
    case 2965:  /* *subv8di3_mask */
    case 2964:  /* *addv8di3_mask */
    case 2963:  /* *subv4si3_mask */
    case 2962:  /* *addv4si3_mask */
    case 2961:  /* *subv8si3_mask */
    case 2960:  /* *addv8si3_mask */
    case 2959:  /* *subv16si3_mask */
    case 2958:  /* *addv16si3_mask */
    case 2957:  /* *subv2di3 */
    case 2955:  /* *addv2di3 */
    case 2953:  /* *subv4di3 */
    case 2951:  /* *addv4di3 */
    case 2949:  /* *subv8di3 */
    case 2947:  /* *addv8di3 */
    case 2945:  /* *subv4si3 */
    case 2943:  /* *addv4si3 */
    case 2941:  /* *subv8si3 */
    case 2939:  /* *addv8si3 */
    case 2937:  /* *subv16si3 */
    case 2935:  /* *addv16si3 */
    case 2933:  /* *subv8hi3 */
    case 2931:  /* *addv8hi3 */
    case 2929:  /* *subv16hi3 */
    case 2927:  /* *addv16hi3 */
    case 2925:  /* *subv32hi3 */
    case 2923:  /* *addv32hi3 */
    case 2921:  /* *subv16qi3 */
    case 2919:  /* *addv16qi3 */
    case 2917:  /* *subv32qi3 */
    case 2915:  /* *addv32qi3 */
    case 2913:  /* *subv64qi3 */
    case 2911:  /* *addv64qi3 */
    case 1796:  /* *xorv8df3_mask */
    case 1794:  /* *iorv8df3_mask */
    case 1792:  /* *andv8df3_mask */
    case 1790:  /* *xorv16sf3_mask */
    case 1788:  /* *iorv16sf3_mask */
    case 1786:  /* *andv16sf3_mask */
    case 1784:  /* *xorv2df3_mask */
    case 1782:  /* *iorv2df3_mask */
    case 1780:  /* *andv2df3_mask */
    case 1778:  /* *xorv4df3_mask */
    case 1776:  /* *iorv4df3_mask */
    case 1774:  /* *andv4df3_mask */
    case 1772:  /* *xorv4sf3_mask */
    case 1770:  /* *iorv4sf3_mask */
    case 1768:  /* *andv4sf3_mask */
    case 1766:  /* *xorv8sf3_mask */
    case 1764:  /* *iorv8sf3_mask */
    case 1762:  /* *andv8sf3_mask */
    case 1594:  /* *sminv2df3_mask */
    case 1592:  /* *smaxv2df3_mask */
    case 1590:  /* *sminv4df3_mask */
    case 1588:  /* *smaxv4df3_mask */
    case 1585:  /* *sminv8df3_mask */
    case 1581:  /* *smaxv8df3_mask */
    case 1578:  /* *sminv4sf3_mask */
    case 1576:  /* *smaxv4sf3_mask */
    case 1574:  /* *sminv8sf3_mask */
    case 1572:  /* *smaxv8sf3_mask */
    case 1569:  /* *sminv16sf3_mask */
    case 1565:  /* *smaxv16sf3_mask */
    case 1561:  /* *sminv2df3_finite_mask */
    case 1557:  /* *smaxv2df3_finite_mask */
    case 1553:  /* *sminv4df3_finite_mask */
    case 1549:  /* *smaxv4df3_finite_mask */
    case 1545:  /* *sminv8df3_finite_mask */
    case 1541:  /* *smaxv8df3_finite_mask */
    case 1537:  /* *sminv4sf3_finite_mask */
    case 1533:  /* *smaxv4sf3_finite_mask */
    case 1529:  /* *sminv8sf3_finite_mask */
    case 1525:  /* *smaxv8sf3_finite_mask */
    case 1521:  /* *sminv16sf3_finite_mask */
    case 1517:  /* *smaxv16sf3_finite_mask */
    case 1460:  /* sse2_divv2df3_mask */
    case 1458:  /* avx_divv4df3_mask */
    case 1455:  /* avx512f_divv8df3_mask */
    case 1452:  /* sse_divv4sf3_mask */
    case 1450:  /* avx_divv8sf3_mask */
    case 1447:  /* avx512f_divv16sf3_mask */
    case 1435:  /* *mulv2df3_mask */
    case 1431:  /* *mulv4df3_mask */
    case 1427:  /* *mulv8df3_mask */
    case 1423:  /* *mulv4sf3_mask */
    case 1419:  /* *mulv8sf3_mask */
    case 1415:  /* *mulv16sf3_mask */
    case 1403:  /* *subv2df3_mask */
    case 1399:  /* *addv2df3_mask */
    case 1395:  /* *subv4df3_mask */
    case 1391:  /* *addv4df3_mask */
    case 1387:  /* *subv8df3_mask */
    case 1383:  /* *addv8df3_mask */
    case 1379:  /* *subv4sf3_mask */
    case 1375:  /* *addv4sf3_mask */
    case 1371:  /* *subv8sf3_mask */
    case 1367:  /* *addv8sf3_mask */
    case 1363:  /* *subv16sf3_mask */
    case 1359:  /* *addv16sf3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 1584:  /* *sminv8df3_round */
    case 1580:  /* *smaxv8df3_round */
    case 1568:  /* *sminv16sf3_round */
    case 1564:  /* *smaxv16sf3_round */
    case 1560:  /* *sminv2df3_finite_round */
    case 1556:  /* *smaxv2df3_finite_round */
    case 1552:  /* *sminv4df3_finite_round */
    case 1548:  /* *smaxv4df3_finite_round */
    case 1544:  /* *sminv8df3_finite_round */
    case 1540:  /* *smaxv8df3_finite_round */
    case 1536:  /* *sminv4sf3_finite_round */
    case 1532:  /* *smaxv4sf3_finite_round */
    case 1528:  /* *sminv8sf3_finite_round */
    case 1524:  /* *smaxv8sf3_finite_round */
    case 1520:  /* *sminv16sf3_finite_round */
    case 1516:  /* *smaxv16sf3_finite_round */
    case 1454:  /* avx512f_divv8df3_round */
    case 1446:  /* avx512f_divv16sf3_round */
    case 1434:  /* *mulv2df3_round */
    case 1430:  /* *mulv4df3_round */
    case 1426:  /* *mulv8df3_round */
    case 1422:  /* *mulv4sf3_round */
    case 1418:  /* *mulv8sf3_round */
    case 1414:  /* *mulv16sf3_round */
    case 1402:  /* *subv2df3_round */
    case 1398:  /* *addv2df3_round */
    case 1394:  /* *subv4df3_round */
    case 1390:  /* *addv4df3_round */
    case 1386:  /* *subv8df3_round */
    case 1382:  /* *addv8df3_round */
    case 1378:  /* *subv4sf3_round */
    case 1374:  /* *addv4sf3_round */
    case 1370:  /* *subv8sf3_round */
    case 1366:  /* *addv8sf3_round */
    case 1362:  /* *subv16sf3_round */
    case 1358:  /* *addv16sf3_round */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 1337:  /* avx512vl_storedquv8hi_mask */
    case 1336:  /* avx512vl_storedquv16hi_mask */
    case 1335:  /* avx512bw_storedquv32hi_mask */
    case 1334:  /* avx512vl_storedquv32qi_mask */
    case 1333:  /* avx512vl_storedquv16qi_mask */
    case 1332:  /* avx512bw_storedquv64qi_mask */
    case 1331:  /* avx512vl_storedquv2di_mask */
    case 1330:  /* avx512vl_storedquv4di_mask */
    case 1329:  /* avx512f_storedquv8di_mask */
    case 1328:  /* avx512vl_storedquv4si_mask */
    case 1327:  /* avx512vl_storedquv8si_mask */
    case 1326:  /* avx512f_storedquv16si_mask */
    case 1289:  /* avx512vl_storeupd_mask */
    case 1288:  /* avx512vl_storeupd256_mask */
    case 1287:  /* avx512f_storeupd512_mask */
    case 1286:  /* avx512vl_storeups_mask */
    case 1285:  /* avx512vl_storeups256_mask */
    case 1284:  /* avx512f_storeups512_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 0;
      break;

    case 4865:  /* conflictv2di_mask */
    case 4863:  /* conflictv4di_mask */
    case 4861:  /* conflictv8di_mask */
    case 4859:  /* conflictv4si_mask */
    case 4857:  /* conflictv8si_mask */
    case 4855:  /* conflictv16si_mask */
    case 4513:  /* avx512f_vcvtph2ps512_mask */
    case 4510:  /* vcvtph2ps256_mask */
    case 4508:  /* *vcvtph2ps_load_mask */
    case 3950:  /* avx512er_rsqrt28v8df_mask */
    case 3946:  /* avx512er_rsqrt28v16sf_mask */
    case 3938:  /* avx512er_rcp28v8df_mask */
    case 3934:  /* avx512er_rcp28v16sf_mask */
    case 3930:  /* avx512er_exp2v8df_mask */
    case 3926:  /* avx512er_exp2v16sf_mask */
    case 2617:  /* avx512vl_getexpv2df_mask */
    case 2613:  /* avx512vl_getexpv4df_mask */
    case 2609:  /* avx512f_getexpv8df_mask */
    case 2605:  /* avx512vl_getexpv4sf_mask */
    case 2601:  /* avx512vl_getexpv8sf_mask */
    case 2597:  /* avx512f_getexpv16sf_mask */
    case 2353:  /* ufix_notruncv2dfv2di2_mask */
    case 2351:  /* ufix_notruncv4dfv4di2_mask */
    case 2348:  /* ufix_notruncv8dfv8di2_mask */
    case 2345:  /* fix_notruncv2dfv2di2_mask */
    case 2343:  /* fix_notruncv4dfv4di2_mask */
    case 2340:  /* fix_notruncv8dfv8di2_mask */
    case 2304:  /* ufix_notruncv4dfv4si2_mask */
    case 2300:  /* ufix_notruncv8dfv8si2_mask */
    case 2294:  /* avx_cvtpd2dq256_mask */
    case 2291:  /* avx512f_cvtpd2dq512_mask */
    case 2188:  /* avx512dq_cvtps2uqqv4di_mask */
    case 2185:  /* avx512dq_cvtps2uqqv8di_mask */
    case 2180:  /* avx512dq_cvtps2qqv4di_mask */
    case 2177:  /* avx512dq_cvtps2qqv8di_mask */
    case 2173:  /* avx512vl_ufix_notruncv4sfv4si_mask */
    case 2169:  /* avx512vl_ufix_notruncv8sfv8si_mask */
    case 2165:  /* avx512f_ufix_notruncv16sfv16si_mask */
    case 2161:  /* avx512f_fix_notruncv16sfv16si_mask */
    case 2158:  /* sse2_fix_notruncv4sfv4si_mask */
    case 2156:  /* avx_fix_notruncv8sfv8si_mask */
    case 1511:  /* rsqrt14v2df_mask */
    case 1509:  /* rsqrt14v4df_mask */
    case 1507:  /* rsqrt14v8df_mask */
    case 1505:  /* rsqrt14v4sf_mask */
    case 1503:  /* rsqrt14v8sf_mask */
    case 1501:  /* rsqrt14v16sf_mask */
    case 1475:  /* rcp14v2df_mask */
    case 1473:  /* rcp14v4df_mask */
    case 1471:  /* rcp14v8df_mask */
    case 1469:  /* rcp14v4sf_mask */
    case 1467:  /* rcp14v8sf_mask */
    case 1465:  /* rcp14v16sf_mask */
    case 1313:  /* *avx512vl_loaddquv2di_mask */
    case 1311:  /* *avx512vl_loaddquv4di_mask */
    case 1309:  /* *avx512f_loaddquv8di_mask */
    case 1307:  /* *sse2_loaddquv4si_mask */
    case 1305:  /* *avx_loaddquv8si_mask */
    case 1303:  /* *avx512f_loaddquv16si_mask */
    case 1301:  /* *avx512vl_loaddquv16hi_mask */
    case 1299:  /* *avx512vl_loaddquv8hi_mask */
    case 1297:  /* *avx512bw_loaddquv32hi_mask */
    case 1295:  /* *avx512f_loaddquv64qi_mask */
    case 1293:  /* *sse2_loaddquv16qi_mask */
    case 1291:  /* *avx_loaddquv32qi_mask */
    case 1277:  /* *sse2_loadupd_mask */
    case 1275:  /* *avx_loadupd256_mask */
    case 1273:  /* *avx512f_loadupd512_mask */
    case 1271:  /* *sse_loadups_mask */
    case 1269:  /* *avx_loadups256_mask */
    case 1267:  /* *avx512f_loadups512_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (pat, 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 1263:  /* avx512vl_storev8hi_mask */
    case 1262:  /* avx512vl_storev16hi_mask */
    case 1261:  /* avx512bw_storev32hi_mask */
    case 1260:  /* avx512vl_storev32qi_mask */
    case 1259:  /* avx512vl_storev16qi_mask */
    case 1258:  /* avx512bw_storev64qi_mask */
    case 1257:  /* avx512vl_storev2df_mask */
    case 1256:  /* avx512vl_storev4df_mask */
    case 1255:  /* avx512f_storev8df_mask */
    case 1254:  /* avx512vl_storev4sf_mask */
    case 1253:  /* avx512vl_storev8sf_mask */
    case 1252:  /* avx512f_storev16sf_mask */
    case 1251:  /* avx512vl_storev2di_mask */
    case 1250:  /* avx512vl_storev4di_mask */
    case 1249:  /* avx512f_storev8di_mask */
    case 1248:  /* avx512vl_storev4si_mask */
    case 1247:  /* avx512vl_storev8si_mask */
    case 1246:  /* avx512f_storev16si_mask */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (pat, 1), 1);
      recog_data.dup_num[0] = 0;
      break;

    case 3812:  /* avx2_pblenddv4si */
    case 3811:  /* avx2_pblenddv8si */
    case 3810:  /* *avx2_pblendw */
    case 3809:  /* sse4_1_pblendw */
    case 3787:  /* sse4_1_blendpd */
    case 3786:  /* avx_blendpd256 */
    case 3785:  /* sse4_1_blendps */
    case 3784:  /* avx_blendps256 */
    case 1245:  /* avx512vl_blendmv8hi */
    case 1244:  /* avx512vl_blendmv16hi */
    case 1243:  /* avx512bw_blendmv32hi */
    case 1242:  /* avx512vl_blendmv32qi */
    case 1241:  /* avx512vl_blendmv16qi */
    case 1240:  /* avx512bw_blendmv64qi */
    case 1239:  /* avx512vl_blendmv2df */
    case 1238:  /* avx512vl_blendmv4df */
    case 1237:  /* avx512f_blendmv8df */
    case 1236:  /* avx512vl_blendmv4sf */
    case 1235:  /* avx512vl_blendmv8sf */
    case 1234:  /* avx512f_blendmv16sf */
    case 1233:  /* avx512vl_blendmv2di */
    case 1232:  /* avx512vl_blendmv4di */
    case 1231:  /* avx512f_blendmv8di */
    case 1230:  /* avx512vl_blendmv4si */
    case 1229:  /* avx512vl_blendmv8si */
    case 1228:  /* avx512f_blendmv16si */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 4058:  /* *avx_vzeroall */
    case 1188:  /* *mmx_femms */
    case 1187:  /* *mmx_emms */
      ro[0] = *(ro_loc[0] = &PATTERN (insn));
      break;

    case 3683:  /* *sse2_maskmovdqu */
    case 3682:  /* *sse2_maskmovdqu */
    case 1186:  /* *mmx_maskmovq */
    case 1185:  /* *mmx_maskmovq */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (pat, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 2), 0);
      recog_data.dup_num[0] = 0;
      break;

    case 4110:  /* avx512f_permv8df_1 */
    case 4108:  /* avx512f_permv8di_1 */
    case 4106:  /* avx2_permv4df_1 */
    case 4104:  /* avx2_permv4di_1 */
    case 3630:  /* sse2_pshuflw_1 */
    case 3624:  /* sse2_pshufd_1 */
    case 2483:  /* *avx512f_vextracti32x4_1 */
    case 2481:  /* *avx512f_vextractf32x4_1 */
    case 1173:  /* mmx_pshufw_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XEXP (pat, 1), 1), 0, 3));
      break;

    case 3655:  /* *vec_extractv4si_zext_mem */
    case 3653:  /* *vec_extractv4si_zext */
    case 3645:  /* *vec_extractv8hi_zext */
    case 3644:  /* *vec_extractv8hi_zext */
    case 3643:  /* *vec_extractv16qi_zext */
    case 3642:  /* *vec_extractv16qi_zext */
    case 1180:  /* *vec_extractv2si_zext_mem */
    case 1172:  /* mmx_pextrw */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0, 0));
      break;

    case 3579:  /* sse4_1_pinsrq */
    case 3578:  /* sse4_1_pinsrd */
    case 3577:  /* sse2_pinsrw */
    case 3576:  /* sse4_1_pinsrb */
    case 2468:  /* *vec_setv4sf_sse4_1 */
    case 1171:  /* *mmx_pinsrw */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 3805:  /* sse4_1_packusdw */
    case 3803:  /* avx2_packusdw */
    case 3801:  /* avx512bw_packusdw */
    case 3538:  /* sse2_packuswb */
    case 3536:  /* avx2_packuswb */
    case 3534:  /* avx512bw_packuswb */
    case 3532:  /* sse2_packssdw */
    case 3530:  /* avx2_packssdw */
    case 3528:  /* avx512bw_packssdw */
    case 3526:  /* sse2_packsswb */
    case 3524:  /* avx2_packsswb */
    case 3522:  /* avx512bw_packsswb */
    case 1164:  /* mmx_packuswb */
    case 1163:  /* mmx_packssdw */
    case 1162:  /* mmx_packsswb */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      break;

    case 3058:  /* *sse4_1_mulv2siv2di3 */
    case 3056:  /* *vec_widen_smult_even_v8si */
    case 3054:  /* *vec_widen_smult_even_v16si */
    case 3052:  /* *vec_widen_umult_even_v4si */
    case 3050:  /* *vec_widen_umult_even_v8si */
    case 3048:  /* *vec_widen_umult_even_v16si */
    case 1131:  /* *sse2_umulv1siv1di3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0));
      break;

    case 1182:  /* *mmx_uavgv4hi3 */
    case 1181:  /* *mmx_uavgv8qi3 */
    case 1130:  /* *mmx_pmulhrwv4hi3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 1), 0));
      break;

    case 3718:  /* ssse3_pmaddubsw */
    case 3717:  /* ssse3_pmaddubsw128 */
    case 3708:  /* avx2_pmaddubsw256 */
    case 3067:  /* *sse2_pmaddwd */
    case 3066:  /* *avx2_pmaddwd */
    case 1129:  /* *mmx_pmaddwd */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0), 0);
      recog_data.dup_num[1] = 2;
      break;

    case 3046:  /* *umulv8hi3_highpart */
    case 3044:  /* *smulv8hi3_highpart */
    case 3042:  /* *umulv16hi3_highpart */
    case 3040:  /* *smulv16hi3_highpart */
    case 3038:  /* *umulv32hi3_highpart */
    case 3036:  /* *smulv32hi3_highpart */
    case 1128:  /* *mmx_umulv4hi3_highpart */
    case 1127:  /* *mmx_smulv4hi3_highpart */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1), 0));
      break;

    case 1103:  /* mmx_pi2fw */
    case 1102:  /* mmx_pf2iw */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      break;

    case 1618:  /* sse3_addsubv4sf3 */
    case 1617:  /* avx_addsubv8sf3 */
    case 1616:  /* sse3_addsubv2df3 */
    case 1615:  /* avx_addsubv4df3 */
    case 1097:  /* mmx_addsubv2sf3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 3707:  /* ssse3_phsubdv2si3 */
    case 3706:  /* ssse3_phadddv2si3 */
    case 1622:  /* sse3_hsubv2df3 */
    case 1096:  /* mmx_hsubv2sf3 */
    case 1095:  /* mmx_haddv2sf3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 1), 0);
      recog_data.dup_num[1] = 2;
      break;

    case 1074:  /* *bnd64_stx */
    case 1073:  /* *bnd32_stx */
      ro[0] = *(ro_loc[0] = &XVECEXP (XEXP (XVECEXP (XVECEXP (pat, 0, 0), 0, 0), 0), 0, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (XVECEXP (pat, 0, 0), 0, 0), 0), 0, 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XVECEXP (pat, 0, 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XVECEXP (pat, 0, 0), 0, 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 1), 0));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[0] = 4;
      break;

    case 1072:  /* *bnd64_ldx */
    case 1071:  /* *bnd32_ldx */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 0), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 1070:  /* *bnd64_cn */
    case 1069:  /* *bnd64_cu */
    case 1068:  /* *bnd64_cl */
    case 1067:  /* *bnd32_cn */
    case 1066:  /* *bnd32_cu */
    case 1065:  /* *bnd32_cl */
      ro[0] = *(ro_loc[0] = &XVECEXP (XVECEXP (pat, 0, 0), 0, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XVECEXP (pat, 0, 0), 0, 1));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[0] = 2;
      break;

    case 1062:  /* *bnd64_mk */
    case 1061:  /* *bnd32_mk */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (pat, 1), 0, 0));
      break;

    case 1052:  /* xbegin_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[0] = 0;
      break;

    case 1036:  /* *lwp_lwpinsdi3_1 */
    case 1035:  /* *lwp_lwpinssi3_1 */
      ro[0] = *(ro_loc[0] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 2));
      break;

    case 1026:  /* fldenv */
      ro[0] = *(ro_loc[0] = &XVECEXP (XVECEXP (pat, 0, 0), 0, 0));
      break;

    case 3689:  /* sse3_monitor_di */
    case 3688:  /* sse3_monitor_si */
    case 1060:  /* monitorx_di */
    case 1059:  /* monitorx_si */
    case 1058:  /* mwaitx */
    case 1034:  /* *lwp_lwpvaldi3_1 */
    case 1033:  /* *lwp_lwpvalsi3_1 */
    case 1024:  /* xrstors64 */
    case 1023:  /* xrstor64 */
    case 1022:  /* xrstors_rex64 */
    case 1021:  /* xrstor_rex64 */
      ro[0] = *(ro_loc[0] = &XVECEXP (pat, 0, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (pat, 0, 1));
      ro[2] = *(ro_loc[2] = &XVECEXP (pat, 0, 2));
      break;

    case 3687:  /* sse3_mwait */
    case 1020:  /* xrstors */
    case 1019:  /* xrstor */
      ro[0] = *(ro_loc[0] = &XVECEXP (pat, 0, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (pat, 0, 1));
      break;

    case 1002:  /* rdtscp_rex64 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 2), 0));
      break;

    case 1001:  /* rdtscp */
    case 1000:  /* rdtsc_rex64 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 982:  /* *prefetch_sse */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (pat, 2));
      break;

    case 978:  /* adjust_stack_and_probedi */
    case 977:  /* adjust_stack_and_probesi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1));
      break;

    case 1831:  /* *fma_fmadd_v2df */
    case 1829:  /* *fma_fmadd_v4df */
    case 1825:  /* *fma_fmadd_v8df */
    case 1824:  /* *fma_fmadd_df */
    case 1822:  /* *fma_fmadd_v4sf */
    case 1820:  /* *fma_fmadd_v8sf */
    case 1816:  /* *fma_fmadd_v16sf */
    case 1815:  /* *fma_fmadd_sf */
    case 1814:  /* *fma_fmadd_v4df */
    case 1813:  /* *fma_fmadd_v8sf */
    case 1812:  /* *fma_fmadd_v2df */
    case 1811:  /* *fma_fmadd_v4sf */
    case 1810:  /* *fma_fmadd_df */
    case 1809:  /* *fma_fmadd_sf */
    case 1227:  /* avx512vl_loadv8hi_mask */
    case 1226:  /* avx512vl_loadv16hi_mask */
    case 1225:  /* avx512bw_loadv32hi_mask */
    case 1224:  /* avx512vl_loadv32qi_mask */
    case 1223:  /* avx512vl_loadv16qi_mask */
    case 1222:  /* avx512bw_loadv64qi_mask */
    case 1221:  /* avx512vl_loadv2df_mask */
    case 1220:  /* avx512vl_loadv4df_mask */
    case 1219:  /* avx512f_loadv8df_mask */
    case 1218:  /* avx512vl_loadv4sf_mask */
    case 1217:  /* avx512vl_loadv8sf_mask */
    case 1216:  /* avx512f_loadv16sf_mask */
    case 1215:  /* avx512vl_loadv2di_mask */
    case 1214:  /* avx512vl_loadv4di_mask */
    case 1213:  /* avx512f_loadv8di_mask */
    case 1212:  /* avx512vl_loadv4si_mask */
    case 1211:  /* avx512vl_loadv8si_mask */
    case 1210:  /* avx512f_loadv16si_mask */
    case 962:  /* *xop_pcmov_df */
    case 961:  /* *xop_pcmov_sf */
    case 960:  /* *movsfcc_1_387 */
    case 959:  /* *movdfcc_1 */
    case 958:  /* *movxfcc_1 */
    case 957:  /* *movqicc_noc */
    case 956:  /* *movdicc_noc */
    case 955:  /* *movsicc_noc */
    case 954:  /* *movhicc_noc */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 2));
      break;

    case 947:  /* *strlenqi_1 */
    case 946:  /* *strlenqi_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      ro[5] = *(ro_loc[5] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0), 0));
      break;

    case 945:  /* *cmpstrnqi_1 */
    case 944:  /* *cmpstrnqi_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 3), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 4), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 5), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 1), 0));
      ro[6] = *(ro_loc[6] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      break;

    case 943:  /* *cmpstrnqi_nz_1 */
    case 942:  /* *cmpstrnqi_nz_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 3), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 4), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 5), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[6] = *(ro_loc[6] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 941:  /* *rep_stosqi */
    case 940:  /* *rep_stosqi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 3), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 4), 0);
      recog_data.dup_num[0] = 4;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 2), 0), 0);
      recog_data.dup_num[1] = 3;
      break;

    case 939:  /* *rep_stossi */
    case 938:  /* *rep_stossi */
    case 937:  /* *rep_stosdi_rex64 */
    case 936:  /* *rep_stosdi_rex64 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 3), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 4), 0);
      recog_data.dup_num[0] = 4;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 2), 0), 0);
      recog_data.dup_num[1] = 3;
      break;

    case 935:  /* *strsetqi_1 */
    case 934:  /* *strsetqi_1 */
    case 933:  /* *strsethi_1 */
    case 932:  /* *strsethi_1 */
    case 931:  /* *strsetsi_1 */
    case 930:  /* *strsetsi_1 */
    case 929:  /* *strsetdi_rex_1 */
    case 928:  /* *strsetdi_rex_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 927:  /* *rep_movqi */
    case 926:  /* *rep_movqi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 4), 0);
      recog_data.dup_num[0] = 5;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 3), 0), 0);
      recog_data.dup_num[1] = 3;
      recog_data.dup_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 3), 1), 0);
      recog_data.dup_num[2] = 4;
      recog_data.dup_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 2), 1), 1);
      recog_data.dup_num[3] = 5;
      break;

    case 925:  /* *rep_movsi */
    case 924:  /* *rep_movsi */
    case 923:  /* *rep_movdi_rex64 */
    case 922:  /* *rep_movdi_rex64 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 2), 1), 1));
      ro[5] = *(ro_loc[5] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 4), 0);
      recog_data.dup_num[0] = 5;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 3), 0), 0);
      recog_data.dup_num[1] = 3;
      recog_data.dup_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 3), 1), 0);
      recog_data.dup_num[2] = 4;
      recog_data.dup_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0), 0);
      recog_data.dup_num[3] = 5;
      break;

    case 921:  /* *strmovqi_1 */
    case 920:  /* *strmovqi_1 */
    case 919:  /* *strmovhi_1 */
    case 918:  /* *strmovhi_1 */
    case 917:  /* *strmovsi_1 */
    case 916:  /* *strmovsi_1 */
    case 915:  /* *strmovdi_rex_1 */
    case 914:  /* *strmovdi_rex_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0);
      recog_data.dup_num[0] = 3;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[1] = 2;
      break;

    case 898:  /* fistdi2_ceil_with_temp */
    case 897:  /* fistdi2_floor_with_temp */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 3), 0));
      ro[5] = *(ro_loc[5] = &XEXP (XVECEXP (pat, 0, 4), 0));
      break;

    case 906:  /* fistsi2_ceil_with_temp */
    case 905:  /* fistsi2_floor_with_temp */
    case 904:  /* fisthi2_ceil_with_temp */
    case 903:  /* fisthi2_floor_with_temp */
    case 896:  /* fistdi2_ceil */
    case 895:  /* fistdi2_floor */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 3), 0));
      break;

    case 976:  /* allocate_stack_worker_probe_di */
    case 975:  /* allocate_stack_worker_probe_si */
    case 894:  /* *fistdi2_ceil_1 */
    case 893:  /* *fistdi2_floor_1 */
    case 892:  /* *fistsi2_ceil_1 */
    case 891:  /* *fistsi2_floor_1 */
    case 890:  /* *fisthi2_ceil_1 */
    case 889:  /* *fisthi2_floor_1 */
    case 887:  /* frndintxf2_mask_pm */
    case 883:  /* frndintxf2_trunc */
    case 882:  /* frndintxf2_ceil */
    case 881:  /* frndintxf2_floor */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      break;

    case 4912:  /* atomic_storedi_fpu */
    case 4907:  /* atomic_loaddi_fpu */
    case 902:  /* fistsi2_ceil */
    case 901:  /* fistsi2_floor */
    case 900:  /* fisthi2_ceil */
    case 899:  /* fisthi2_floor */
    case 888:  /* frndintxf2_mask_pm_i387 */
    case 886:  /* frndintxf2_trunc_i387 */
    case 885:  /* frndintxf2_ceil_i387 */
    case 884:  /* frndintxf2_floor_i387 */
    case 874:  /* fistdi2_with_temp */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 2), 0));
      break;

    case 988:  /* stack_tls_protect_set_di */
    case 987:  /* stack_tls_protect_set_si */
    case 986:  /* stack_protect_set_di */
    case 985:  /* stack_protect_set_si */
    case 880:  /* fistsi2_with_temp */
    case 879:  /* fisthi2_with_temp */
    case 873:  /* fistdi2 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 868:  /* fscalexf4_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1);
      recog_data.dup_num[0] = 3;
      recog_data.dup_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[1] = 2;
      break;

    case 863:  /* fyl2xp1_extenddfxf3_i387 */
    case 862:  /* fyl2xp1_extendsfxf3_i387 */
    case 860:  /* fyl2x_extenddfxf3_i387 */
    case 859:  /* fyl2x_extendsfxf3_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 857:  /* fpatan_extenddfxf3_i387 */
    case 856:  /* fpatan_extendsfxf3_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 992:  /* stack_tls_protect_test_di */
    case 991:  /* stack_tls_protect_test_si */
    case 990:  /* stack_protect_test_di */
    case 989:  /* stack_protect_test_si */
    case 861:  /* fyl2xp1xf3_i387 */
    case 858:  /* fyl2xxf3_i387 */
    case 855:  /* *fpatanxf3_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 854:  /* fptan_extenddfxf4_i387 */
    case 853:  /* fptan_extendsfxf4_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 0), 1));
      break;

    case 852:  /* fptanxf4_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 0), 1));
      break;

    case 866:  /* fxtract_extenddfxf3_i387 */
    case 865:  /* fxtract_extendsfxf3_i387 */
    case 851:  /* sincos_extenddfxf3_i387 */
    case 850:  /* sincos_extendsfxf3_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0), 0));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0), 0);
      recog_data.dup_num[0] = 2;
      break;

    case 998:  /* rdpmc_rex64 */
    case 864:  /* fxtractxf3_i387 */
    case 849:  /* sincosxf3 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[0] = 2;
      break;

    case 842:  /* fprem1xf4_i387 */
    case 841:  /* fpremxf4_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 1);
      recog_data.dup_num[0] = 3;
      recog_data.dup_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 2), 1), 0, 0);
      recog_data.dup_num[1] = 2;
      recog_data.dup_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 1);
      recog_data.dup_num[2] = 3;
      recog_data.dup_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0, 0);
      recog_data.dup_num[3] = 2;
      break;

    case 832:  /* *fop_xf_6_i387 */
    case 831:  /* *fop_xf_6_i387 */
    case 820:  /* *fop_df_6_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (pat, 1));
      break;

    case 830:  /* *fop_xf_5_i387 */
    case 829:  /* *fop_xf_5_i387 */
    case 826:  /* *fop_xf_3_i387 */
    case 825:  /* *fop_xf_3_i387 */
    case 819:  /* *fop_df_5_i387 */
    case 817:  /* *fop_df_3_i387 */
    case 816:  /* *fop_sf_3_i387 */
    case 815:  /* *fop_df_3_i387 */
    case 814:  /* *fop_sf_3_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (pat, 1));
      break;

    case 828:  /* *fop_xf_4_i387 */
    case 827:  /* *fop_xf_4_i387 */
    case 824:  /* *fop_xf_2_i387 */
    case 823:  /* *fop_xf_2_i387 */
    case 818:  /* *fop_df_4_i387 */
    case 813:  /* *fop_df_2_i387 */
    case 812:  /* *fop_sf_2_i387 */
    case 811:  /* *fop_df_2_i387 */
    case 810:  /* *fop_sf_2_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (pat, 1));
      break;

    case 796:  /* *tls_dynamic_gnu2_combine_64 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      break;

    case 793:  /* *tls_dynamic_gnu2_combine_32 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 2));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      break;

    case 792:  /* *tls_dynamic_gnu2_call_32 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      break;

    case 791:  /* *tls_dynamic_gnu2_lea_32 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0, 0));
      break;

    case 788:  /* *add_tp_x32_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      break;

    case 790:  /* *add_tp_di */
    case 789:  /* *add_tp_si */
    case 787:  /* *add_tp_x32 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 782:  /* *tls_local_dynamic_32_once */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0, 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[5] = *(ro_loc[5] = &XEXP (XVECEXP (pat, 0, 2), 0));
      break;

    case 781:  /* *tls_local_dynamic_base_64_largepic */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 778:  /* *tls_local_dynamic_base_32_gnu */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 2), 0));
      break;

    case 777:  /* *tls_global_dynamic_64_largepic */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 776:  /* *tls_global_dynamic_64_di */
    case 775:  /* *tls_global_dynamic_64_si */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 774:  /* *tls_global_dynamic_32_gnu */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[5] = *(ro_loc[5] = &XEXP (XVECEXP (pat, 0, 2), 0));
      break;

    case 773:  /* *parityhi2_cmp */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      break;

    case 772:  /* paritysi2_cmp */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      break;

    case 771:  /* paritydi2_cmp */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 3), 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      break;

    case 770:  /* bswaphi_lowpart */
    case 769:  /* *bswaphi_lowpart_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0);
      recog_data.dup_num[0] = 0;
      break;

    case 757:  /* *bsrhi */
    case 756:  /* bsr */
    case 755:  /* bsr_rex64 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      break;

    case 754:  /* *tbm_tzmsk_di */
    case 753:  /* *tbm_tzmsk_si */
    case 752:  /* *tbm_t1mskc_di */
    case 751:  /* *tbm_t1mskc_si */
    case 750:  /* *tbm_blsic_di */
    case 749:  /* *tbm_blsic_si */
    case 742:  /* *tbm_blcic_di */
    case 741:  /* *tbm_blcic_si */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 740:  /* *tbm_blci_di */
    case 739:  /* *tbm_blci_si */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 736:  /* tbm_bextri_di */
    case 735:  /* tbm_bextri_si */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2));
      break;

    case 4911:  /* atomic_storedi_1 */
    case 4910:  /* atomic_storesi_1 */
    case 4909:  /* atomic_storehi_1 */
    case 4908:  /* atomic_storeqi_1 */
    case 4901:  /* vpmultishiftqbv32qi */
    case 4899:  /* vpmultishiftqbv16qi */
    case 4897:  /* vpmultishiftqbv64qi */
    case 4871:  /* sha256msg2 */
    case 4870:  /* sha256msg1 */
    case 4868:  /* sha1nexte */
    case 4867:  /* sha1msg2 */
    case 4866:  /* sha1msg1 */
    case 4828:  /* avx512vl_getmantv2df */
    case 4824:  /* avx512vl_getmantv4df */
    case 4820:  /* avx512f_getmantv8df */
    case 4816:  /* avx512vl_getmantv4sf */
    case 4812:  /* avx512vl_getmantv8sf */
    case 4808:  /* avx512f_getmantv16sf */
    case 4804:  /* avx512dq_fpclassv2df */
    case 4802:  /* avx512dq_fpclassv4df */
    case 4800:  /* avx512dq_fpclassv8df */
    case 4798:  /* avx512dq_fpclassv4sf */
    case 4796:  /* avx512dq_fpclassv8sf */
    case 4794:  /* avx512dq_fpclassv16sf */
    case 4520:  /* *avx512f_vcvtps2ph512 */
    case 4518:  /* vcvtps2ph256 */
    case 4517:  /* *vcvtps2ph_store */
    case 4278:  /* avx_vpermilvarv2df3 */
    case 4276:  /* avx_vpermilvarv4df3 */
    case 4274:  /* avx512f_vpermilvarv8df3 */
    case 4272:  /* avx_vpermilvarv4sf3 */
    case 4270:  /* avx_vpermilvarv8sf3 */
    case 4268:  /* avx512f_vpermilvarv16sf3 */
    case 4102:  /* avx512bw_permvarv32hi */
    case 4100:  /* avx512vl_permvarv16hi */
    case 4098:  /* avx512vl_permvarv8hi */
    case 4096:  /* avx512vl_permvarv32qi */
    case 4094:  /* avx512vl_permvarv16qi */
    case 4092:  /* avx512bw_permvarv64qi */
    case 4090:  /* avx2_permvarv4df */
    case 4088:  /* avx2_permvarv4di */
    case 4086:  /* avx512f_permvarv8df */
    case 4084:  /* avx512f_permvarv8di */
    case 4082:  /* avx512f_permvarv16sf */
    case 4080:  /* avx512f_permvarv16si */
    case 4078:  /* avx2_permvarv8sf */
    case 4076:  /* avx2_permvarv8si */
    case 4056:  /* aeskeygenassist */
    case 4054:  /* aesdeclast */
    case 4053:  /* aesdec */
    case 4052:  /* aesenclast */
    case 4051:  /* aesenc */
    case 3895:  /* sse4_1_roundpd */
    case 3894:  /* avx_roundpd256 */
    case 3893:  /* sse4_1_roundps */
    case 3892:  /* avx_roundps256 */
    case 3783:  /* sse4a_insertq */
    case 3781:  /* sse4a_extrq */
    case 3741:  /* ssse3_psignv2si3 */
    case 3740:  /* ssse3_psignv4hi3 */
    case 3739:  /* ssse3_psignv8qi3 */
    case 3738:  /* ssse3_psignv4si3 */
    case 3737:  /* avx2_psignv8si3 */
    case 3736:  /* ssse3_psignv8hi3 */
    case 3735:  /* avx2_psignv16hi3 */
    case 3734:  /* ssse3_psignv16qi3 */
    case 3733:  /* avx2_psignv32qi3 */
    case 3732:  /* ssse3_pshufbv8qi3 */
    case 3730:  /* ssse3_pshufbv16qi3 */
    case 3728:  /* avx2_pshufbv32qi3 */
    case 3726:  /* avx512bw_pshufbv64qi3 */
    case 3713:  /* avx512bw_pmaddubsw512v32hi */
    case 3711:  /* avx512bw_pmaddubsw512v16hi */
    case 3709:  /* avx512bw_pmaddubsw512v8hi */
    case 3675:  /* sse2_psadbw */
    case 3674:  /* avx2_psadbw */
    case 3673:  /* avx512f_psadbw */
    case 3632:  /* *avx512bw_pshufhwv32hi */
    case 3626:  /* *avx512bw_pshuflwv32hi */
    case 3520:  /* avx512vl_testnmv2di3 */
    case 3518:  /* avx512vl_testnmv4di3 */
    case 3516:  /* avx512f_testnmv8di3 */
    case 3514:  /* avx512vl_testnmv4si3 */
    case 3512:  /* avx512vl_testnmv8si3 */
    case 3510:  /* avx512f_testnmv16si3 */
    case 3508:  /* avx512vl_testnmv8hi3 */
    case 3506:  /* avx512vl_testnmv16hi3 */
    case 3504:  /* avx512bw_testnmv32hi3 */
    case 3502:  /* avx512vl_testnmv32qi3 */
    case 3500:  /* avx512vl_testnmv16qi3 */
    case 3498:  /* avx512bw_testnmv64qi3 */
    case 3496:  /* avx512vl_testmv2di3 */
    case 3494:  /* avx512vl_testmv4di3 */
    case 3492:  /* avx512f_testmv8di3 */
    case 3490:  /* avx512vl_testmv4si3 */
    case 3488:  /* avx512vl_testmv8si3 */
    case 3486:  /* avx512f_testmv16si3 */
    case 3484:  /* avx512vl_testmv8hi3 */
    case 3482:  /* avx512vl_testmv16hi3 */
    case 3480:  /* avx512bw_testmv32hi3 */
    case 3478:  /* avx512vl_testmv32qi3 */
    case 3476:  /* avx512vl_testmv16qi3 */
    case 3474:  /* avx512bw_testmv64qi3 */
    case 3379:  /* avx512vl_gtv8hi3 */
    case 3377:  /* avx512vl_gtv16hi3 */
    case 3375:  /* avx512bw_gtv32hi3 */
    case 3373:  /* avx512vl_gtv32qi3 */
    case 3371:  /* avx512vl_gtv16qi3 */
    case 3369:  /* avx512bw_gtv64qi3 */
    case 3367:  /* avx512vl_gtv2di3 */
    case 3365:  /* avx512vl_gtv4di3 */
    case 3363:  /* avx512f_gtv8di3 */
    case 3361:  /* avx512vl_gtv4si3 */
    case 3359:  /* avx512vl_gtv8si3 */
    case 3357:  /* avx512f_gtv16si3 */
    case 3346:  /* avx512vl_eqv2di3_1 */
    case 3344:  /* avx512vl_eqv4di3_1 */
    case 3342:  /* avx512f_eqv8di3_1 */
    case 3340:  /* avx512vl_eqv4si3_1 */
    case 3338:  /* avx512vl_eqv8si3_1 */
    case 3336:  /* avx512f_eqv16si3_1 */
    case 3334:  /* avx512vl_eqv8hi3_1 */
    case 3332:  /* avx512vl_eqv16hi3_1 */
    case 3330:  /* avx512bw_eqv32hi3_1 */
    case 3328:  /* avx512vl_eqv32qi3_1 */
    case 3326:  /* avx512vl_eqv16qi3_1 */
    case 3324:  /* avx512bw_eqv64qi3_1 */
    case 3064:  /* avx512bw_pmaddwd512v8hi */
    case 3062:  /* avx512bw_pmaddwd512v16hi */
    case 3060:  /* avx512bw_pmaddwd512v32hi */
    case 2703:  /* avx512vl_rndscalev2df */
    case 2699:  /* avx512vl_rndscalev4df */
    case 2695:  /* avx512f_rndscalev8df */
    case 2691:  /* avx512vl_rndscalev4sf */
    case 2687:  /* avx512vl_rndscalev8sf */
    case 2683:  /* avx512f_rndscalev16sf */
    case 2573:  /* avx512vl_scalefv2df */
    case 2569:  /* avx512vl_scalefv4df */
    case 2565:  /* avx512f_scalefv8df */
    case 2561:  /* avx512vl_scalefv4sf */
    case 2557:  /* avx512vl_scalefv8sf */
    case 2553:  /* avx512f_scalefv16sf */
    case 1639:  /* *reducepv2df */
    case 1637:  /* *reducepv4df */
    case 1635:  /* *reducepv8df */
    case 1633:  /* *reducepv4sf */
    case 1631:  /* *reducepv8sf */
    case 1629:  /* *reducepv16sf */
    case 1614:  /* *ieee_smaxv2df3 */
    case 1613:  /* *ieee_smaxv4df3 */
    case 1612:  /* *ieee_smaxv8df3 */
    case 1611:  /* *ieee_smaxv4sf3 */
    case 1610:  /* *ieee_smaxv8sf3 */
    case 1609:  /* *ieee_smaxv16sf3 */
    case 1608:  /* *ieee_sminv2df3 */
    case 1607:  /* *ieee_sminv4df3 */
    case 1606:  /* *ieee_sminv8df3 */
    case 1605:  /* *ieee_sminv4sf3 */
    case 1604:  /* *ieee_sminv8sf3 */
    case 1603:  /* *ieee_sminv16sf3 */
    case 1183:  /* mmx_psadbw */
    case 1094:  /* mmx_rsqit1v2sf3 */
    case 1092:  /* mmx_rcpit2v2sf3 */
    case 1091:  /* mmx_rcpit1v2sf3 */
    case 1018:  /* xsaves64 */
    case 1017:  /* xsavec64 */
    case 1016:  /* xsaveopt64 */
    case 1015:  /* xsave64 */
    case 1014:  /* xsaves_rex64 */
    case 1013:  /* xsavec_rex64 */
    case 1012:  /* xsaveopt_rex64 */
    case 1011:  /* xsave_rex64 */
    case 996:  /* sse4_2_crc32di */
    case 995:  /* sse4_2_crc32si */
    case 994:  /* sse4_2_crc32hi */
    case 993:  /* sse4_2_crc32qi */
    case 970:  /* *ieee_smindf3 */
    case 969:  /* *ieee_smaxdf3 */
    case 968:  /* *ieee_sminsf3 */
    case 967:  /* *ieee_smaxsf3 */
    case 870:  /* sse4_1_rounddf2 */
    case 869:  /* sse4_1_roundsf2 */
    case 734:  /* bmi2_pext_di3 */
    case 733:  /* bmi2_pext_si3 */
    case 732:  /* bmi2_pdep_di3 */
    case 731:  /* bmi2_pdep_si3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      break;

    case 730:  /* *bmi2_bzhi_di3_1 */
    case 729:  /* *bmi2_bzhi_si3_1 */
    case 728:  /* *bmi2_bzhi_di3 */
    case 727:  /* *bmi2_bzhi_si3 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 1));
      break;

    case 748:  /* *tbm_blsfill_di */
    case 747:  /* *tbm_blsfill_si */
    case 746:  /* *tbm_blcs_di */
    case 745:  /* *tbm_blcs_si */
    case 744:  /* *tbm_blcmsk_di */
    case 743:  /* *tbm_blcmsk_si */
    case 738:  /* *tbm_blcfill_di */
    case 737:  /* *tbm_blcfill_si */
    case 726:  /* *bmi_blsr_di */
    case 725:  /* *bmi_blsr_si */
    case 724:  /* *bmi_blsmsk_di */
    case 723:  /* *bmi_blsmsk_si */
    case 722:  /* *bmi_blsi_di */
    case 721:  /* *bmi_blsi_si */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 980:  /* probe_stack_rangedi */
    case 979:  /* probe_stack_rangesi */
    case 795:  /* *tls_dynamic_gnu2_call_64 */
    case 720:  /* bmi_bextr_di */
    case 719:  /* bmi_bextr_si */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      break;

    case 2389:  /* avx512f_cvtps2pd512_round */
    case 2381:  /* *avx512f_cvtpd2ps512_round */
    case 2359:  /* ufix_truncv8sfv8di2_round */
    case 2355:  /* fix_truncv8sfv8di2_round */
    case 2327:  /* ufix_truncv8dfv8di2_round */
    case 2323:  /* fix_truncv8dfv8di2_round */
    case 2313:  /* ufix_truncv8dfv8si2_round */
    case 2309:  /* fix_truncv8dfv8si2_round */
    case 2268:  /* ufloatv8div8sf2_round */
    case 2264:  /* floatv8div8sf2_round */
    case 2260:  /* ufloatv2div2df2_round */
    case 2256:  /* floatv2div2df2_round */
    case 2252:  /* ufloatv4div4df2_round */
    case 2248:  /* floatv4div4df2_round */
    case 2244:  /* ufloatv8div8df2_round */
    case 2240:  /* floatv8div8df2_round */
    case 2196:  /* ufix_truncv16sfv16si2_round */
    case 2192:  /* fix_truncv16sfv16si2_round */
    case 2152:  /* ufloatv4siv4sf2_round */
    case 2148:  /* ufloatv8siv8sf2_round */
    case 2144:  /* ufloatv16siv16sf2_round */
    case 2136:  /* floatv16siv16sf2_round */
    case 1487:  /* avx512f_sqrtv8df2_round */
    case 1479:  /* avx512f_sqrtv16sf2_round */
    case 761:  /* *popcountdi2_falsedep */
    case 760:  /* *popcountsi2_falsedep */
    case 713:  /* *clzdi2_lzcnt_falsedep */
    case 712:  /* *clzsi2_lzcnt_falsedep */
    case 706:  /* *ctzdi2_falsedep */
    case 705:  /* *ctzsi2_falsedep */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XVECEXP (pat, 0, 1), 0, 0));
      break;

    case 702:  /* *bsfdi_1 */
    case 701:  /* *bsfsi_1 */
    case 700:  /* *tzcntdi_1 */
    case 699:  /* *tzcntsi_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 3779:  /* sse4a_vmmovntv2df */
    case 3778:  /* sse4a_vmmovntv4sf */
    case 2228:  /* sse2_cvtsd2siq */
    case 2225:  /* sse2_cvtsd2si */
    case 2219:  /* avx512f_vcvtsd2usiq */
    case 2217:  /* avx512f_vcvtsd2usi */
    case 2211:  /* avx512f_vcvtss2usiq */
    case 2209:  /* avx512f_vcvtss2usi */
    case 2189:  /* *avx512dq_cvtps2uqqv2di */
    case 2181:  /* *avx512dq_cvtps2qqv2di */
    case 2121:  /* sse_cvtss2siq */
    case 2118:  /* sse_cvtss2si */
    case 848:  /* *cos_extenddfxf2_i387 */
    case 847:  /* *sin_extenddfxf2_i387 */
    case 846:  /* *cos_extendsfxf2_i387 */
    case 845:  /* *sin_extendsfxf2_i387 */
    case 693:  /* set_got_offset_rex64 */
    case 692:  /* set_rip_rex64 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 0));
      break;

    case 690:  /* set_got_labelled */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0), 0));
      break;

    case 1050:  /* rdseeddi_1 */
    case 1049:  /* rdseedsi_1 */
    case 1048:  /* rdseedhi_1 */
    case 1047:  /* rdranddi_1 */
    case 1046:  /* rdrandsi_1 */
    case 1045:  /* rdrandhi_1 */
    case 1025:  /* fnstenv */
    case 689:  /* set_got */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      break;

    case 685:  /* simple_return_indirect_internal */
    case 684:  /* simple_return_pop_internal */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 3686:  /* sse2_clflush */
    case 3684:  /* sse_ldmxcsr */
    case 1057:  /* clflushopt */
    case 1056:  /* clwb */
    case 1054:  /* xabort */
    case 1044:  /* wrgsbasedi */
    case 1043:  /* wrfsbasedi */
    case 1042:  /* wrgsbasesi */
    case 1041:  /* wrfsbasesi */
    case 1030:  /* *lwp_llwpcbdi1 */
    case 1029:  /* *lwp_llwpcbsi1 */
    case 1006:  /* fxrstor64 */
    case 1005:  /* fxrstor */
    case 697:  /* split_stack_return */
    case 688:  /* pad */
    case 687:  /* nops */
    case 681:  /* prologue_use */
      ro[0] = *(ro_loc[0] = &XVECEXP (pat, 0, 0));
      break;

    case 4905:  /* mfence_sse2 */
    case 4904:  /* *sse_sfence */
    case 4903:  /* *sse2_lfence */
    case 1051:  /* *pause */
    case 680:  /* *memory_blockage */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      recog_data.dup_loc[0] = &XVECEXP (XEXP (pat, 1), 0, 0);
      recog_data.dup_num[0] = 0;
      break;

    case 4059:  /* avx_vzeroupper */
    case 1055:  /* xtest_1 */
    case 1053:  /* xend */
    case 1028:  /* fnclex */
    case 981:  /* trap */
    case 913:  /* cld */
    case 696:  /* leave_rex64 */
    case 695:  /* leave */
    case 694:  /* eh_return_internal */
    case 686:  /* nop */
    case 683:  /* simple_return_internal_long */
    case 682:  /* simple_return_internal */
    case 679:  /* blockage */
      break;

    case 678:  /* *sibcall_value_pop_memory */
    case 677:  /* *sibcall_value_pop */
    case 676:  /* *call_value_pop */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1));
      break;

    case 4419:  /* vec_set_hi_v32qi */
    case 4417:  /* vec_set_hi_v16hi */
    case 4414:  /* vec_set_hi_v8sf */
    case 4412:  /* vec_set_hi_v8si */
    case 4406:  /* vec_set_hi_v4df */
    case 4404:  /* vec_set_hi_v4di */
    case 3602:  /* vec_set_hi_v8di */
    case 3600:  /* vec_set_hi_v8df */
    case 3594:  /* vec_set_hi_v16si */
    case 3592:  /* vec_set_hi_v16sf */
    case 3395:  /* *andnotv2di3 */
    case 3394:  /* *andnotv4di3 */
    case 3393:  /* *andnotv4si3 */
    case 3392:  /* *andnotv8si3 */
    case 3391:  /* *andnotv8hi3 */
    case 3390:  /* *andnotv16hi3 */
    case 3389:  /* *andnotv32hi3 */
    case 3388:  /* *andnotv16qi3 */
    case 3387:  /* *andnotv32qi3 */
    case 3386:  /* *andnotv64qi3 */
    case 3385:  /* *andnotv8di3 */
    case 3384:  /* *andnotv16si3 */
    case 2888:  /* *avx512vl_us_truncatev2div2si2 */
    case 2887:  /* *avx512vl_truncatev2div2si2 */
    case 2886:  /* *avx512vl_ss_truncatev2div2si2 */
    case 2858:  /* *avx512vl_us_truncatev4siv4hi2 */
    case 2857:  /* *avx512vl_truncatev4siv4hi2 */
    case 2856:  /* *avx512vl_ss_truncatev4siv4hi2 */
    case 2855:  /* *avx512vl_us_truncatev2div2hi2 */
    case 2854:  /* *avx512vl_truncatev2div2hi2 */
    case 2853:  /* *avx512vl_ss_truncatev2div2hi2 */
    case 2852:  /* *avx512vl_us_truncatev4div4hi2 */
    case 2851:  /* *avx512vl_truncatev4div4hi2 */
    case 2850:  /* *avx512vl_ss_truncatev4div4hi2 */
    case 2804:  /* *avx512vl_us_truncatev8hiv8qi2 */
    case 2803:  /* *avx512vl_truncatev8hiv8qi2 */
    case 2802:  /* *avx512vl_ss_truncatev8hiv8qi2 */
    case 2801:  /* *avx512vl_us_truncatev4siv4qi2 */
    case 2800:  /* *avx512vl_truncatev4siv4qi2 */
    case 2799:  /* *avx512vl_ss_truncatev4siv4qi2 */
    case 2798:  /* *avx512vl_us_truncatev8siv8qi2 */
    case 2797:  /* *avx512vl_truncatev8siv8qi2 */
    case 2796:  /* *avx512vl_ss_truncatev8siv8qi2 */
    case 2795:  /* *avx512vl_us_truncatev2div2qi2 */
    case 2794:  /* *avx512vl_truncatev2div2qi2 */
    case 2793:  /* *avx512vl_ss_truncatev2div2qi2 */
    case 2792:  /* *avx512vl_us_truncatev4div4qi2 */
    case 2791:  /* *avx512vl_truncatev4div4qi2 */
    case 2790:  /* *avx512vl_ss_truncatev4div4qi2 */
    case 2736:  /* sse2_loadhpd */
    case 2454:  /* sse_loadhps */
    case 2386:  /* *sse2_cvtpd2ps */
    case 1799:  /* *andnottf3 */
    case 1798:  /* *andnotdf3 */
    case 1797:  /* *andnotsf3 */
    case 1759:  /* avx512f_andnotv8df3 */
    case 1757:  /* avx512f_andnotv16sf3 */
    case 1755:  /* sse2_andnotv2df3 */
    case 1753:  /* avx_andnotv4df3 */
    case 1751:  /* sse_andnotv4sf3 */
    case 1749:  /* avx_andnotv8sf3 */
    case 1496:  /* sse2_vmsqrtv2df2 */
    case 1494:  /* sse_vmsqrtv4sf2 */
    case 1152:  /* mmx_andnotv2si3 */
    case 1151:  /* mmx_andnotv4hi3 */
    case 1150:  /* mmx_andnotv8qi3 */
    case 673:  /* *sibcall_value */
    case 672:  /* *sibcall_value */
    case 671:  /* *call_value */
    case 670:  /* *call_value */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 669:  /* *sibcall_pop_memory */
    case 668:  /* *sibcall_pop */
    case 667:  /* *call_pop */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1));
      break;

    case 660:  /* *tablejump_1 */
    case 659:  /* *tablejump_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 1));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 0), 0));
      break;

    case 656:  /* jump */
    case 655:  /* jump_bnd */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 654:  /* *jccxf_si_r_i387 */
    case 653:  /* *jccdf_si_r_i387 */
    case 652:  /* *jccsf_si_r_i387 */
    case 651:  /* *jccxf_hi_r_i387 */
    case 650:  /* *jccdf_hi_r_i387 */
    case 649:  /* *jccsf_hi_r_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2), 0));
      ro[5] = *(ro_loc[5] = &XEXP (XVECEXP (pat, 0, 3), 0));
      break;

    case 648:  /* *jccxf_si_i387 */
    case 647:  /* *jccdf_si_i387 */
    case 646:  /* *jccsf_si_i387 */
    case 645:  /* *jccxf_hi_i387 */
    case 644:  /* *jccdf_hi_i387 */
    case 643:  /* *jccsf_hi_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[5] = *(ro_loc[5] = &XEXP (XVECEXP (pat, 0, 3), 0));
      break;

    case 642:  /* *jccuxf_r_i387 */
    case 641:  /* *jccudf_r_i387 */
    case 640:  /* *jccusf_r_i387 */
    case 636:  /* *jccdf_r_i387 */
    case 635:  /* *jccsf_r_i387 */
    case 632:  /* *jccxf_r_i387 */
    case 630:  /* *jccxf_0_r_i387 */
    case 629:  /* *jccdf_0_r_i387 */
    case 628:  /* *jccsf_0_r_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 3), 0));
      break;

    case 639:  /* *jccuxf_i387 */
    case 638:  /* *jccudf_i387 */
    case 637:  /* *jccusf_i387 */
    case 634:  /* *jccdf_i387 */
    case 633:  /* *jccsf_i387 */
    case 631:  /* *jccxf_i387 */
    case 627:  /* *jccxf_0_i387 */
    case 626:  /* *jccdf_0_i387 */
    case 625:  /* *jccsf_0_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 3), 0));
      break;

    case 624:  /* *jcc_btsi_mask_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 1), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      break;

    case 623:  /* *jcc_btsi_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      break;

    case 622:  /* *jcc_btdi_mask */
    case 621:  /* *jcc_btsi_mask */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 2), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 2), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      break;

    case 620:  /* *jcc_btdi_1 */
    case 619:  /* *jcc_btsi_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 2));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      break;

    case 618:  /* *jcc_btdi */
    case 617:  /* *jcc_btsi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 2), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      break;

    case 616:  /* *jcc_2 */
    case 615:  /* *jcc_2_bnd */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 2), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 614:  /* *jcc_1 */
    case 613:  /* *jcc_1_bnd */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 1740:  /* avx512f_maskcmpv2df3 */
    case 1739:  /* avx512f_maskcmpv4df3 */
    case 1738:  /* avx512f_maskcmpv8df3 */
    case 1737:  /* avx512f_maskcmpv4sf3 */
    case 1736:  /* avx512f_maskcmpv8sf3 */
    case 1735:  /* avx512f_maskcmpv16sf3 */
    case 1656:  /* sse2_maskcmpv2df3 */
    case 1655:  /* avx_maskcmpv4df3 */
    case 1654:  /* sse_maskcmpv4sf3 */
    case 1653:  /* avx_maskcmpv8sf3 */
    case 1652:  /* *sse2_maskcmpv2df3_comm */
    case 1651:  /* *avx_maskcmpv4df3_comm */
    case 1650:  /* *sse_maskcmpv4sf3_comm */
    case 1649:  /* *avx_maskcmpv8sf3_comm */
    case 822:  /* *fop_xf_1_i387 */
    case 821:  /* *fop_xf_comm_i387 */
    case 809:  /* *fop_df_1_i387 */
    case 808:  /* *fop_sf_1_i387 */
    case 807:  /* *fop_df_1_sse */
    case 806:  /* *fop_sf_1_sse */
    case 804:  /* *fop_df_1_mixed */
    case 803:  /* *fop_sf_1_mixed */
    case 802:  /* *fop_df_comm_i387 */
    case 801:  /* *fop_sf_comm_i387 */
    case 800:  /* *fop_df_comm_sse */
    case 799:  /* *fop_sf_comm_sse */
    case 798:  /* *fop_df_comm_mixed */
    case 797:  /* *fop_sf_comm_mixed */
    case 612:  /* setcc_df_sse */
    case 611:  /* setcc_sf_sse */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (pat, 1));
      break;

    case 605:  /* *btdi */
    case 604:  /* *btsi */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      break;

    case 603:  /* *btcq */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 2));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0);
      recog_data.dup_num[0] = 0;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 2);
      recog_data.dup_num[1] = 1;
      break;

    case 602:  /* *btrq */
    case 601:  /* *btsq */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 2));
      break;

    case 585:  /* ix86_rotrti3_doubleword */
    case 584:  /* ix86_rotrdi3_doubleword */
    case 583:  /* ix86_rotlti3_doubleword */
    case 582:  /* ix86_rotldi3_doubleword */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 2), 0));
      break;

    case 3574:  /* vec_interleave_lowv4si */
    case 3572:  /* *avx512f_interleave_lowv16si */
    case 3570:  /* avx2_interleave_lowv8si */
    case 3568:  /* vec_interleave_highv4si */
    case 3566:  /* *avx512f_interleave_highv16si */
    case 3564:  /* avx2_interleave_highv8si */
    case 3562:  /* vec_interleave_lowv8hi */
    case 3560:  /* avx2_interleave_lowv16hi */
    case 3558:  /* *avx512bw_interleave_lowv32hi */
    case 3556:  /* vec_interleave_highv8hi */
    case 3554:  /* avx2_interleave_highv16hi */
    case 3552:  /* avx512bw_interleave_highv32hi */
    case 3550:  /* vec_interleave_lowv16qi */
    case 3548:  /* avx2_interleave_lowv32qi */
    case 3546:  /* avx512bw_interleave_lowv64qi */
    case 3544:  /* vec_interleave_highv16qi */
    case 3542:  /* avx2_interleave_highv32qi */
    case 3540:  /* avx512bw_interleave_highv64qi */
    case 2728:  /* vec_interleave_lowv2di */
    case 2726:  /* *avx512f_interleave_lowv8di */
    case 2724:  /* avx2_interleave_lowv4di */
    case 2722:  /* vec_interleave_highv2di */
    case 2720:  /* *avx512f_interleave_highv8di */
    case 2718:  /* avx2_interleave_highv4di */
    case 2548:  /* *vec_interleave_lowv2df */
    case 2545:  /* *avx_unpcklpd256 */
    case 2543:  /* *avx512f_unpcklpd512 */
    case 2542:  /* *vec_interleave_highv2df */
    case 2539:  /* avx_unpckhpd256 */
    case 2537:  /* *avx512f_unpckhpd512 */
    case 2435:  /* vec_interleave_lowv4sf */
    case 2432:  /* avx_unpcklps256 */
    case 2430:  /* *avx512f_unpcklps512 */
    case 2428:  /* vec_interleave_highv4sf */
    case 2426:  /* avx_unpckhps256 */
    case 2424:  /* *avx512f_unpckhps512 */
    case 2423:  /* sse_movlhps */
    case 2422:  /* sse_movhlps */
    case 1170:  /* mmx_punpckldq */
    case 1169:  /* mmx_punpckhdq */
    case 1168:  /* mmx_punpcklwd */
    case 1167:  /* mmx_punpckhwd */
    case 1166:  /* mmx_punpcklbw */
    case 1165:  /* mmx_punpckhbw */
    case 592:  /* *bmi2_rorxsi3_1_zext */
    case 551:  /* *bmi2_ashrsi3_1_zext */
    case 550:  /* *bmi2_lshrsi3_1_zext */
    case 515:  /* *bmi2_ashlsi3_1_zext */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      break;

    case 581:  /* *rotrdi3_mask */
    case 580:  /* *rotldi3_mask */
    case 579:  /* *rotrsi3_mask */
    case 578:  /* *rotlsi3_mask */
    case 532:  /* *ashrdi3_mask */
    case 531:  /* *lshrdi3_mask */
    case 530:  /* *ashrsi3_mask */
    case 529:  /* *lshrsi3_mask */
    case 510:  /* *ashldi3_mask */
    case 509:  /* *ashlsi3_mask */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 1));
      break;

    case 538:  /* x86_shrd */
    case 537:  /* x86_64_shrd */
    case 508:  /* x86_shld */
    case 507:  /* x86_64_shld */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0);
      recog_data.dup_num[0] = 0;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 1), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 504:  /* *one_cmplsi2_2_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 494:  /* copysigntf3_var */
    case 493:  /* copysigndf3_var */
    case 492:  /* copysignsf3_var */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 0));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 1));
      ro[4] = *(ro_loc[4] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 2));
      ro[5] = *(ro_loc[5] = &XVECEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0, 3));
      break;

    case 4889:  /* vpamdd52huqv2di */
    case 4887:  /* vpamdd52luqv2di */
    case 4885:  /* vpamdd52huqv4di */
    case 4883:  /* vpamdd52luqv4di */
    case 4881:  /* vpamdd52huqv8di */
    case 4879:  /* vpamdd52luqv8di */
    case 4872:  /* sha256rnds2 */
    case 4869:  /* sha1rnds4 */
    case 4840:  /* *avx512bw_dbpsadbwv32hi */
    case 4838:  /* *avx512bw_dbpsadbwv16hi */
    case 4836:  /* *avx512bw_dbpsadbwv8hi */
    case 4788:  /* avx512dq_rangepv2df */
    case 4786:  /* avx512dq_rangepv4df */
    case 4782:  /* avx512dq_rangepv8df */
    case 4780:  /* avx512dq_rangepv4sf */
    case 4778:  /* avx512dq_rangepv8sf */
    case 4774:  /* avx512dq_rangepv16sf */
    case 4773:  /* avx512vl_expandv2df_mask */
    case 4772:  /* avx512vl_expandv2di_mask */
    case 4771:  /* avx512vl_expandv4sf_mask */
    case 4770:  /* avx512vl_expandv4si_mask */
    case 4769:  /* avx512vl_expandv4df_mask */
    case 4768:  /* avx512vl_expandv4di_mask */
    case 4767:  /* avx512vl_expandv8sf_mask */
    case 4766:  /* avx512vl_expandv8si_mask */
    case 4765:  /* avx512f_expandv8df_mask */
    case 4764:  /* avx512f_expandv8di_mask */
    case 4763:  /* avx512f_expandv16sf_mask */
    case 4762:  /* avx512f_expandv16si_mask */
    case 4749:  /* avx512vl_compressv2df_mask */
    case 4748:  /* avx512vl_compressv2di_mask */
    case 4747:  /* avx512vl_compressv4sf_mask */
    case 4746:  /* avx512vl_compressv4si_mask */
    case 4745:  /* avx512vl_compressv4df_mask */
    case 4744:  /* avx512vl_compressv4di_mask */
    case 4743:  /* avx512vl_compressv8sf_mask */
    case 4742:  /* avx512vl_compressv8si_mask */
    case 4741:  /* avx512f_compressv8df_mask */
    case 4740:  /* avx512f_compressv8di_mask */
    case 4739:  /* avx512f_compressv16sf_mask */
    case 4738:  /* avx512f_compressv16si_mask */
    case 4390:  /* *avx_vperm2f128v4df_full */
    case 4389:  /* *avx_vperm2f128v8sf_full */
    case 4388:  /* *avx_vperm2f128v8si_full */
    case 4368:  /* avx512bw_vpermt2varv32hi3 */
    case 4366:  /* avx512vl_vpermt2varv16hi3 */
    case 4364:  /* avx512vl_vpermt2varv8hi3 */
    case 4362:  /* avx512vl_vpermt2varv32qi3 */
    case 4360:  /* avx512vl_vpermt2varv16qi3 */
    case 4358:  /* avx512bw_vpermt2varv64qi3 */
    case 4356:  /* avx512vl_vpermt2varv2df3 */
    case 4354:  /* avx512vl_vpermt2varv2di3 */
    case 4352:  /* avx512vl_vpermt2varv4sf3 */
    case 4350:  /* avx512vl_vpermt2varv4si3 */
    case 4348:  /* avx512vl_vpermt2varv4df3 */
    case 4346:  /* avx512vl_vpermt2varv4di3 */
    case 4344:  /* avx512vl_vpermt2varv8sf3 */
    case 4342:  /* avx512vl_vpermt2varv8si3 */
    case 4340:  /* avx512f_vpermt2varv8df3 */
    case 4338:  /* avx512f_vpermt2varv8di3 */
    case 4336:  /* avx512f_vpermt2varv16sf3 */
    case 4334:  /* avx512f_vpermt2varv16si3 */
    case 4314:  /* avx512bw_vpermi2varv32hi3 */
    case 4312:  /* avx512vl_vpermi2varv16hi3 */
    case 4310:  /* avx512vl_vpermi2varv8hi3 */
    case 4308:  /* avx512vl_vpermi2varv32qi3 */
    case 4306:  /* avx512vl_vpermi2varv16qi3 */
    case 4304:  /* avx512bw_vpermi2varv64qi3 */
    case 4302:  /* avx512vl_vpermi2varv2df3 */
    case 4300:  /* avx512vl_vpermi2varv2di3 */
    case 4298:  /* avx512vl_vpermi2varv4sf3 */
    case 4296:  /* avx512vl_vpermi2varv4si3 */
    case 4294:  /* avx512vl_vpermi2varv4df3 */
    case 4292:  /* avx512vl_vpermi2varv4di3 */
    case 4290:  /* avx512vl_vpermi2varv8sf3 */
    case 4288:  /* avx512vl_vpermi2varv8si3 */
    case 4286:  /* avx512f_vpermi2varv8df3 */
    case 4284:  /* avx512f_vpermi2varv8di3 */
    case 4282:  /* avx512f_vpermi2varv16sf3 */
    case 4280:  /* avx512f_vpermi2varv16si3 */
    case 4112:  /* avx2_permv2ti */
    case 4057:  /* pclmulqdq */
    case 4046:  /* xop_pcom_tfv2di3 */
    case 4045:  /* xop_pcom_tfv4si3 */
    case 4044:  /* xop_pcom_tfv8hi3 */
    case 4043:  /* xop_pcom_tfv16qi3 */
    case 3999:  /* xop_pperm */
    case 3808:  /* sse4_1_pblendvb */
    case 3807:  /* avx2_pblendvb */
    case 3800:  /* sse4_1_mpsadbw */
    case 3799:  /* avx2_mpsadbw */
    case 3795:  /* sse4_1_dppd */
    case 3794:  /* avx_dppd256 */
    case 3793:  /* sse4_1_dpps */
    case 3792:  /* avx_dpps256 */
    case 3791:  /* sse4_1_blendvpd */
    case 3790:  /* avx_blendvpd256 */
    case 3789:  /* sse4_1_blendvps */
    case 3788:  /* avx_blendvps256 */
    case 3780:  /* sse4a_extrqi */
    case 3748:  /* ssse3_palignrdi */
    case 3747:  /* ssse3_palignrti */
    case 3746:  /* avx2_palignrv2ti */
    case 3745:  /* avx512bw_palignrv4ti */
    case 2633:  /* *avx512vl_alignv2di */
    case 2631:  /* *avx512vl_alignv4di */
    case 2629:  /* *avx512f_alignv8di */
    case 2627:  /* *avx512vl_alignv4si */
    case 2625:  /* *avx512vl_alignv8si */
    case 2623:  /* *avx512f_alignv16si */
    case 2015:  /* *fma_fmaddsub_v2df */
    case 2013:  /* *fma_fmaddsub_v4df */
    case 2009:  /* *fma_fmaddsub_v8df */
    case 2008:  /* *fma_fmaddsub_df */
    case 2006:  /* *fma_fmaddsub_v4sf */
    case 2004:  /* *fma_fmaddsub_v8sf */
    case 2000:  /* *fma_fmaddsub_v16sf */
    case 1999:  /* *fma_fmaddsub_sf */
    case 1998:  /* *fma_fmaddsub_v2df */
    case 1997:  /* *fma_fmaddsub_v4df */
    case 1996:  /* *fma_fmaddsub_v4sf */
    case 1995:  /* *fma_fmaddsub_v8sf */
    case 1725:  /* avx512vl_ucmpv2di3 */
    case 1723:  /* avx512vl_ucmpv4di3 */
    case 1721:  /* avx512f_ucmpv8di3 */
    case 1719:  /* avx512vl_ucmpv4si3 */
    case 1717:  /* avx512vl_ucmpv8si3 */
    case 1715:  /* avx512f_ucmpv16si3 */
    case 1713:  /* avx512vl_ucmpv8hi3 */
    case 1711:  /* avx512vl_ucmpv16hi3 */
    case 1709:  /* avx512bw_ucmpv32hi3 */
    case 1707:  /* avx512vl_ucmpv32qi3 */
    case 1705:  /* avx512vl_ucmpv16qi3 */
    case 1703:  /* avx512bw_ucmpv64qi3 */
    case 1701:  /* avx512vl_cmpv8hi3 */
    case 1699:  /* avx512vl_cmpv16hi3 */
    case 1697:  /* avx512bw_cmpv32hi3 */
    case 1695:  /* avx512vl_cmpv32qi3 */
    case 1693:  /* avx512vl_cmpv16qi3 */
    case 1691:  /* avx512bw_cmpv64qi3 */
    case 1689:  /* avx512vl_cmpv2df3 */
    case 1687:  /* avx512vl_cmpv4df3 */
    case 1683:  /* avx512f_cmpv8df3 */
    case 1681:  /* avx512vl_cmpv4sf3 */
    case 1679:  /* avx512vl_cmpv8sf3 */
    case 1675:  /* avx512f_cmpv16sf3 */
    case 1673:  /* avx512vl_cmpv2di3 */
    case 1671:  /* avx512vl_cmpv4di3 */
    case 1667:  /* avx512f_cmpv8di3 */
    case 1665:  /* avx512vl_cmpv4si3 */
    case 1663:  /* avx512vl_cmpv8si3 */
    case 1659:  /* avx512f_cmpv16si3 */
    case 1646:  /* avx_cmpv2df3 */
    case 1645:  /* avx_cmpv4df3 */
    case 1644:  /* avx_cmpv4sf3 */
    case 1643:  /* avx_cmpv8sf3 */
    case 491:  /* copysigntf3_const */
    case 490:  /* copysigndf3_const */
    case 489:  /* copysignsf3_const */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      ro[2] = *(ro_loc[2] = &XVECEXP (XEXP (pat, 1), 0, 1));
      ro[3] = *(ro_loc[3] = &XVECEXP (XEXP (pat, 1), 0, 2));
      break;

    case 1356:  /* *absnegv2df2 */
    case 1355:  /* *absnegv4df2 */
    case 1354:  /* *absnegv8df2 */
    case 1353:  /* *absnegv4sf2 */
    case 1352:  /* *absnegv8sf2 */
    case 1351:  /* *absnegv16sf2 */
    case 476:  /* *absnegtf2_sse */
    case 475:  /* *absnegxf2_i387 */
    case 474:  /* *absnegdf2_i387 */
    case 473:  /* *absnegsf2_i387 */
    case 472:  /* *absnegdf2_sse */
    case 471:  /* *absnegsf2_sse */
    case 470:  /* *absnegdf2_mixed */
    case 469:  /* *absnegsf2_mixed */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 0), 1));
      break;

    case 468:  /* *negvdi3 */
    case 467:  /* *negvsi3 */
    case 466:  /* *negvhi3 */
    case 465:  /* *negvqi3 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 464:  /* *negsi2_cmpz_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 503:  /* *one_cmpldi2_2 */
    case 502:  /* *one_cmplsi2_2 */
    case 501:  /* *one_cmplhi2_2 */
    case 500:  /* *one_cmplqi2_2 */
    case 463:  /* *negdi2_cmpz */
    case 462:  /* *negsi2_cmpz */
    case 461:  /* *neghi2_cmpz */
    case 460:  /* *negqi2_cmpz */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      break;

    case 459:  /* *negsi2_1_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      break;

    case 435:  /* *xorsi_2_zext_imm */
    case 434:  /* *iorsi_2_zext_imm */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 431:  /* kunpckdi */
    case 430:  /* kunpcksi */
    case 429:  /* kunpckhi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 1), 0));
      break;

    case 452:  /* *xorqi_cc_ext_1 */
    case 398:  /* *andqi_ext_0_cc */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 437:  /* *xorqi_2_slp */
    case 436:  /* *iorqi_2_slp */
    case 396:  /* *andqi_2_slp */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 0), 0);
      recog_data.dup_num[0] = 0;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[1] = 0;
      recog_data.dup_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[2] = 1;
      break;

    case 780:  /* *tls_local_dynamic_base_64_di */
    case 779:  /* *tls_local_dynamic_base_64_si */
    case 718:  /* *bmi_andn_di */
    case 717:  /* *bmi_andn_si */
    case 675:  /* *sibcall_value_memory */
    case 674:  /* *sibcall_value_memory */
    case 412:  /* *xorsi_1_zext_imm */
    case 411:  /* *iorsi_1_zext_imm */
    case 389:  /* kandnhi */
    case 388:  /* kandnqi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 4504:  /* avx_vec_concatv8df */
    case 4503:  /* avx_vec_concatv16sf */
    case 4502:  /* avx_vec_concatv8di */
    case 4501:  /* avx_vec_concatv16si */
    case 4500:  /* avx_vec_concatv32hi */
    case 4499:  /* avx_vec_concatv64qi */
    case 4498:  /* avx_vec_concatv4df */
    case 4497:  /* avx_vec_concatv8sf */
    case 4496:  /* avx_vec_concatv4di */
    case 4495:  /* avx_vec_concatv8si */
    case 4494:  /* avx_vec_concatv16hi */
    case 4493:  /* avx_vec_concatv32qi */
    case 4491:  /* avx512bw_lshrvv32hi */
    case 4489:  /* avx512bw_ashlvv32hi */
    case 4487:  /* avx512vl_lshrvv16hi */
    case 4485:  /* avx512vl_ashlvv16hi */
    case 4483:  /* avx512vl_lshrvv8hi */
    case 4481:  /* avx512vl_ashlvv8hi */
    case 4479:  /* avx2_lshrvv2di */
    case 4477:  /* avx2_ashlvv2di */
    case 4475:  /* avx2_lshrvv4di */
    case 4473:  /* avx2_ashlvv4di */
    case 4471:  /* avx512f_lshrvv8di */
    case 4469:  /* avx512f_ashlvv8di */
    case 4467:  /* avx2_lshrvv4si */
    case 4465:  /* avx2_ashlvv4si */
    case 4463:  /* avx2_lshrvv8si */
    case 4461:  /* avx2_ashlvv8si */
    case 4459:  /* avx512f_lshrvv16si */
    case 4457:  /* avx512f_ashlvv16si */
    case 4455:  /* avx512bw_ashrvv32hi */
    case 4453:  /* avx512vl_ashrvv16hi */
    case 4451:  /* avx512vl_ashrvv8hi */
    case 4449:  /* avx512f_ashrvv8di */
    case 4447:  /* avx2_ashrvv4di */
    case 4445:  /* avx2_ashrvv2di */
    case 4443:  /* avx512f_ashrvv16si */
    case 4441:  /* avx2_ashrvv8si */
    case 4439:  /* avx2_ashrvv4si */
    case 4010:  /* xop_rotrv2di3 */
    case 4009:  /* xop_rotrv4si3 */
    case 4008:  /* xop_rotrv8hi3 */
    case 4007:  /* xop_rotrv16qi3 */
    case 4006:  /* xop_rotlv2di3 */
    case 4005:  /* xop_rotlv4si3 */
    case 4004:  /* xop_rotlv8hi3 */
    case 4003:  /* xop_rotlv16qi3 */
    case 3660:  /* vec_concatv2di */
    case 3659:  /* *vec_concatv4si */
    case 3658:  /* *vec_concatv2si */
    case 3657:  /* *vec_concatv2si_sse4_1 */
    case 3472:  /* *xorv8hi3 */
    case 3470:  /* *iorv8hi3 */
    case 3468:  /* *andv8hi3 */
    case 3466:  /* *xorv16hi3 */
    case 3464:  /* *iorv16hi3 */
    case 3462:  /* *andv16hi3 */
    case 3460:  /* *xorv32hi3 */
    case 3458:  /* *iorv32hi3 */
    case 3456:  /* *andv32hi3 */
    case 3454:  /* *xorv16qi3 */
    case 3452:  /* *iorv16qi3 */
    case 3450:  /* *andv16qi3 */
    case 3448:  /* *xorv32qi3 */
    case 3446:  /* *iorv32qi3 */
    case 3444:  /* *andv32qi3 */
    case 3442:  /* *xorv64qi3 */
    case 3440:  /* *iorv64qi3 */
    case 3438:  /* *andv64qi3 */
    case 3436:  /* *xorv2di3 */
    case 3434:  /* *iorv2di3 */
    case 3432:  /* *andv2di3 */
    case 3430:  /* *xorv4di3 */
    case 3428:  /* *iorv4di3 */
    case 3426:  /* *andv4di3 */
    case 3424:  /* *xorv8di3 */
    case 3422:  /* *iorv8di3 */
    case 3420:  /* *andv8di3 */
    case 3418:  /* *xorv4si3 */
    case 3416:  /* *iorv4si3 */
    case 3414:  /* *andv4si3 */
    case 3412:  /* *xorv8si3 */
    case 3410:  /* *iorv8si3 */
    case 3408:  /* *andv8si3 */
    case 3406:  /* *xorv16si3 */
    case 3404:  /* *iorv16si3 */
    case 3402:  /* *andv16si3 */
    case 3383:  /* sse2_gtv4si3 */
    case 3382:  /* sse2_gtv8hi3 */
    case 3381:  /* sse2_gtv16qi3 */
    case 3356:  /* avx2_gtv4di3 */
    case 3355:  /* avx2_gtv8si3 */
    case 3354:  /* avx2_gtv16hi3 */
    case 3353:  /* avx2_gtv32qi3 */
    case 3352:  /* sse4_2_gtv2di3 */
    case 3351:  /* *sse2_eqv4si3 */
    case 3350:  /* *sse2_eqv8hi3 */
    case 3349:  /* *sse2_eqv16qi3 */
    case 3348:  /* *sse4_1_eqv2di3 */
    case 3323:  /* *avx2_eqv4di3 */
    case 3322:  /* *avx2_eqv8si3 */
    case 3321:  /* *avx2_eqv16hi3 */
    case 3320:  /* *avx2_eqv32qi3 */
    case 3319:  /* *uminv16qi3 */
    case 3318:  /* *umaxv16qi3 */
    case 3316:  /* *sse4_1_uminv4si3 */
    case 3314:  /* *sse4_1_umaxv4si3 */
    case 3312:  /* *sse4_1_uminv8hi3 */
    case 3310:  /* *sse4_1_umaxv8hi3 */
    case 3309:  /* *sminv8hi3 */
    case 3308:  /* *smaxv8hi3 */
    case 3306:  /* *sse4_1_sminv4si3 */
    case 3304:  /* *sse4_1_smaxv4si3 */
    case 3302:  /* *sse4_1_sminv16qi3 */
    case 3300:  /* *sse4_1_smaxv16qi3 */
    case 3298:  /* *uminv8hi3 */
    case 3296:  /* *umaxv8hi3 */
    case 3294:  /* *sminv8hi3 */
    case 3292:  /* *smaxv8hi3 */
    case 3290:  /* *uminv16hi3 */
    case 3288:  /* *umaxv16hi3 */
    case 3286:  /* *sminv16hi3 */
    case 3284:  /* *smaxv16hi3 */
    case 3282:  /* *uminv32hi3 */
    case 3280:  /* *umaxv32hi3 */
    case 3278:  /* *sminv32hi3 */
    case 3276:  /* *smaxv32hi3 */
    case 3274:  /* *uminv32qi3 */
    case 3272:  /* *umaxv32qi3 */
    case 3270:  /* *sminv32qi3 */
    case 3268:  /* *smaxv32qi3 */
    case 3266:  /* *uminv16qi3 */
    case 3264:  /* *umaxv16qi3 */
    case 3262:  /* *sminv16qi3 */
    case 3260:  /* *smaxv16qi3 */
    case 3258:  /* *uminv64qi3 */
    case 3256:  /* *umaxv64qi3 */
    case 3254:  /* *sminv64qi3 */
    case 3252:  /* *smaxv64qi3 */
    case 3250:  /* *avx512f_uminv2di3 */
    case 3248:  /* *avx512f_umaxv2di3 */
    case 3246:  /* *avx512f_sminv2di3 */
    case 3244:  /* *avx512f_smaxv2di3 */
    case 3242:  /* *avx512f_uminv4di3 */
    case 3240:  /* *avx512f_umaxv4di3 */
    case 3238:  /* *avx512f_sminv4di3 */
    case 3236:  /* *avx512f_smaxv4di3 */
    case 3234:  /* *avx512f_uminv8di3 */
    case 3232:  /* *avx512f_umaxv8di3 */
    case 3230:  /* *avx512f_sminv8di3 */
    case 3228:  /* *avx512f_smaxv8di3 */
    case 3226:  /* *avx512f_uminv4si3 */
    case 3224:  /* *avx512f_umaxv4si3 */
    case 3222:  /* *avx512f_sminv4si3 */
    case 3220:  /* *avx512f_smaxv4si3 */
    case 3218:  /* *avx512f_uminv8si3 */
    case 3216:  /* *avx512f_umaxv8si3 */
    case 3214:  /* *avx512f_sminv8si3 */
    case 3212:  /* *avx512f_smaxv8si3 */
    case 3210:  /* *avx512f_uminv16si3 */
    case 3208:  /* *avx512f_umaxv16si3 */
    case 3206:  /* *avx512f_sminv16si3 */
    case 3204:  /* *avx512f_smaxv16si3 */
    case 3203:  /* *avx2_uminv8si3 */
    case 3202:  /* *avx2_umaxv8si3 */
    case 3201:  /* *avx2_sminv8si3 */
    case 3200:  /* *avx2_smaxv8si3 */
    case 3199:  /* *avx2_uminv16hi3 */
    case 3198:  /* *avx2_umaxv16hi3 */
    case 3197:  /* *avx2_sminv16hi3 */
    case 3196:  /* *avx2_smaxv16hi3 */
    case 3195:  /* *avx2_uminv32qi3 */
    case 3194:  /* *avx2_umaxv32qi3 */
    case 3193:  /* *avx2_sminv32qi3 */
    case 3192:  /* *avx2_smaxv32qi3 */
    case 3190:  /* avx512vl_rorv2di */
    case 3188:  /* avx512vl_rolv2di */
    case 3186:  /* avx512vl_rorv4di */
    case 3184:  /* avx512vl_rolv4di */
    case 3182:  /* avx512f_rorv8di */
    case 3180:  /* avx512f_rolv8di */
    case 3178:  /* avx512vl_rorv4si */
    case 3176:  /* avx512vl_rolv4si */
    case 3174:  /* avx512vl_rorv8si */
    case 3172:  /* avx512vl_rolv8si */
    case 3170:  /* avx512f_rorv16si */
    case 3168:  /* avx512f_rolv16si */
    case 3166:  /* avx512vl_rorvv2di */
    case 3164:  /* avx512vl_rolvv2di */
    case 3162:  /* avx512vl_rorvv4di */
    case 3160:  /* avx512vl_rolvv4di */
    case 3158:  /* avx512f_rorvv8di */
    case 3156:  /* avx512f_rolvv8di */
    case 3154:  /* avx512vl_rorvv4si */
    case 3152:  /* avx512vl_rolvv4si */
    case 3150:  /* avx512vl_rorvv8si */
    case 3148:  /* avx512vl_rolvv8si */
    case 3146:  /* avx512f_rorvv16si */
    case 3144:  /* avx512f_rolvv16si */
    case 3143:  /* sse2_lshrv1ti3 */
    case 3142:  /* avx2_lshrv2ti3 */
    case 3141:  /* avx512bw_lshrv4ti3 */
    case 3140:  /* sse2_ashlv1ti3 */
    case 3139:  /* avx2_ashlv2ti3 */
    case 3138:  /* avx512bw_ashlv4ti3 */
    case 3136:  /* lshrv8di3 */
    case 3134:  /* ashlv8di3 */
    case 3132:  /* lshrv16si3 */
    case 3130:  /* ashlv16si3 */
    case 3128:  /* lshrv2di3 */
    case 3126:  /* ashlv2di3 */
    case 3124:  /* lshrv4di3 */
    case 3122:  /* ashlv4di3 */
    case 3120:  /* lshrv4si3 */
    case 3118:  /* ashlv4si3 */
    case 3116:  /* lshrv8si3 */
    case 3114:  /* ashlv8si3 */
    case 3112:  /* lshrv8hi3 */
    case 3110:  /* ashlv8hi3 */
    case 3108:  /* lshrv16hi3 */
    case 3106:  /* ashlv16hi3 */
    case 3104:  /* lshrv32hi3 */
    case 3102:  /* ashlv32hi3 */
    case 3100:  /* ashrv8di3 */
    case 3098:  /* ashrv16si3 */
    case 3096:  /* ashrv4di3 */
    case 3094:  /* ashrv32hi3 */
    case 3092:  /* *ashrv2di3 */
    case 3090:  /* *ashrv4si3 */
    case 3088:  /* *ashrv8si3 */
    case 3086:  /* *ashrv8hi3 */
    case 3084:  /* *ashrv16hi3 */
    case 3083:  /* ashrv4si3 */
    case 3082:  /* ashrv8si3 */
    case 3081:  /* ashrv8hi3 */
    case 3080:  /* ashrv16hi3 */
    case 3078:  /* *sse4_1_mulv4si3 */
    case 3076:  /* *avx2_mulv8si3 */
    case 3074:  /* *avx512f_mulv16si3 */
    case 3072:  /* avx512dq_mulv2di3 */
    case 3070:  /* avx512dq_mulv4di3 */
    case 3068:  /* avx512dq_mulv8di3 */
    case 3034:  /* *mulv8hi3 */
    case 3032:  /* *mulv16hi3 */
    case 3030:  /* *mulv32hi3 */
    case 3028:  /* *sse2_ussubv8hi3 */
    case 3026:  /* *sse2_sssubv8hi3 */
    case 3024:  /* *sse2_usaddv8hi3 */
    case 3022:  /* *sse2_ssaddv8hi3 */
    case 3020:  /* *avx2_ussubv16hi3 */
    case 3018:  /* *avx2_sssubv16hi3 */
    case 3016:  /* *avx2_usaddv16hi3 */
    case 3014:  /* *avx2_ssaddv16hi3 */
    case 3012:  /* *avx512bw_ussubv32hi3 */
    case 3010:  /* *avx512bw_sssubv32hi3 */
    case 3008:  /* *avx512bw_usaddv32hi3 */
    case 3006:  /* *avx512bw_ssaddv32hi3 */
    case 3004:  /* *sse2_ussubv16qi3 */
    case 3002:  /* *sse2_sssubv16qi3 */
    case 3000:  /* *sse2_usaddv16qi3 */
    case 2998:  /* *sse2_ssaddv16qi3 */
    case 2996:  /* *avx2_ussubv32qi3 */
    case 2994:  /* *avx2_sssubv32qi3 */
    case 2992:  /* *avx2_usaddv32qi3 */
    case 2990:  /* *avx2_ssaddv32qi3 */
    case 2988:  /* *avx512bw_ussubv64qi3 */
    case 2986:  /* *avx512bw_sssubv64qi3 */
    case 2984:  /* *avx512bw_usaddv64qi3 */
    case 2982:  /* *avx512bw_ssaddv64qi3 */
    case 2956:  /* *subv2di3 */
    case 2954:  /* *addv2di3 */
    case 2952:  /* *subv4di3 */
    case 2950:  /* *addv4di3 */
    case 2948:  /* *subv8di3 */
    case 2946:  /* *addv8di3 */
    case 2944:  /* *subv4si3 */
    case 2942:  /* *addv4si3 */
    case 2940:  /* *subv8si3 */
    case 2938:  /* *addv8si3 */
    case 2936:  /* *subv16si3 */
    case 2934:  /* *addv16si3 */
    case 2932:  /* *subv8hi3 */
    case 2930:  /* *addv8hi3 */
    case 2928:  /* *subv16hi3 */
    case 2926:  /* *addv16hi3 */
    case 2924:  /* *subv32hi3 */
    case 2922:  /* *addv32hi3 */
    case 2920:  /* *subv16qi3 */
    case 2918:  /* *addv16qi3 */
    case 2916:  /* *subv32qi3 */
    case 2914:  /* *addv32qi3 */
    case 2912:  /* *subv64qi3 */
    case 2910:  /* *addv64qi3 */
    case 2741:  /* *vec_concatv2df */
    case 2465:  /* *vec_concatv4sf */
    case 2464:  /* *vec_concatv2sf_sse */
    case 2463:  /* *vec_concatv2sf_sse4_1 */
    case 1808:  /* *xortf3 */
    case 1807:  /* *iortf3 */
    case 1806:  /* *andtf3 */
    case 1805:  /* *xordf3 */
    case 1804:  /* *iordf3 */
    case 1803:  /* *anddf3 */
    case 1802:  /* *xorsf3 */
    case 1801:  /* *iorsf3 */
    case 1800:  /* *andsf3 */
    case 1795:  /* *xorv8df3 */
    case 1793:  /* *iorv8df3 */
    case 1791:  /* *andv8df3 */
    case 1789:  /* *xorv16sf3 */
    case 1787:  /* *iorv16sf3 */
    case 1785:  /* *andv16sf3 */
    case 1783:  /* *xorv2df3 */
    case 1781:  /* *iorv2df3 */
    case 1779:  /* *andv2df3 */
    case 1777:  /* *xorv4df3 */
    case 1775:  /* *iorv4df3 */
    case 1773:  /* *andv4df3 */
    case 1771:  /* *xorv4sf3 */
    case 1769:  /* *iorv4sf3 */
    case 1767:  /* *andv4sf3 */
    case 1765:  /* *xorv8sf3 */
    case 1763:  /* *iorv8sf3 */
    case 1761:  /* *andv8sf3 */
    case 1593:  /* *sminv2df3 */
    case 1591:  /* *smaxv2df3 */
    case 1589:  /* *sminv4df3 */
    case 1587:  /* *smaxv4df3 */
    case 1583:  /* *sminv8df3 */
    case 1579:  /* *smaxv8df3 */
    case 1577:  /* *sminv4sf3 */
    case 1575:  /* *smaxv4sf3 */
    case 1573:  /* *sminv8sf3 */
    case 1571:  /* *smaxv8sf3 */
    case 1567:  /* *sminv16sf3 */
    case 1563:  /* *smaxv16sf3 */
    case 1559:  /* *sminv2df3_finite */
    case 1555:  /* *smaxv2df3_finite */
    case 1551:  /* *sminv4df3_finite */
    case 1547:  /* *smaxv4df3_finite */
    case 1543:  /* *sminv8df3_finite */
    case 1539:  /* *smaxv8df3_finite */
    case 1535:  /* *sminv4sf3_finite */
    case 1531:  /* *smaxv4sf3_finite */
    case 1527:  /* *sminv8sf3_finite */
    case 1523:  /* *smaxv8sf3_finite */
    case 1519:  /* *sminv16sf3_finite */
    case 1515:  /* *smaxv16sf3_finite */
    case 1459:  /* sse2_divv2df3 */
    case 1457:  /* avx_divv4df3 */
    case 1453:  /* avx512f_divv8df3 */
    case 1451:  /* sse_divv4sf3 */
    case 1449:  /* avx_divv8sf3 */
    case 1445:  /* avx512f_divv16sf3 */
    case 1433:  /* *mulv2df3 */
    case 1429:  /* *mulv4df3 */
    case 1425:  /* *mulv8df3 */
    case 1421:  /* *mulv4sf3 */
    case 1417:  /* *mulv8sf3 */
    case 1413:  /* *mulv16sf3 */
    case 1401:  /* *subv2df3 */
    case 1397:  /* *addv2df3 */
    case 1393:  /* *subv4df3 */
    case 1389:  /* *addv4df3 */
    case 1385:  /* *subv8df3 */
    case 1381:  /* *addv8df3 */
    case 1377:  /* *subv4sf3 */
    case 1373:  /* *addv4sf3 */
    case 1369:  /* *subv8sf3 */
    case 1365:  /* *addv8sf3 */
    case 1361:  /* *subv16sf3 */
    case 1357:  /* *addv16sf3 */
    case 1177:  /* *mmx_concatv2si */
    case 1161:  /* *mmx_xorv2si3 */
    case 1160:  /* *mmx_iorv2si3 */
    case 1159:  /* *mmx_andv2si3 */
    case 1158:  /* *mmx_xorv4hi3 */
    case 1157:  /* *mmx_iorv4hi3 */
    case 1156:  /* *mmx_andv4hi3 */
    case 1155:  /* *mmx_xorv8qi3 */
    case 1154:  /* *mmx_iorv8qi3 */
    case 1153:  /* *mmx_andv8qi3 */
    case 1149:  /* mmx_gtv2si3 */
    case 1148:  /* mmx_gtv4hi3 */
    case 1147:  /* mmx_gtv8qi3 */
    case 1146:  /* *mmx_eqv2si3 */
    case 1145:  /* *mmx_eqv4hi3 */
    case 1144:  /* *mmx_eqv8qi3 */
    case 1143:  /* mmx_lshrv1di3 */
    case 1142:  /* mmx_ashlv1di3 */
    case 1141:  /* mmx_lshrv2si3 */
    case 1140:  /* mmx_ashlv2si3 */
    case 1139:  /* mmx_lshrv4hi3 */
    case 1138:  /* mmx_ashlv4hi3 */
    case 1137:  /* mmx_ashrv2si3 */
    case 1136:  /* mmx_ashrv4hi3 */
    case 1135:  /* *mmx_uminv8qi3 */
    case 1134:  /* *mmx_umaxv8qi3 */
    case 1133:  /* *mmx_sminv4hi3 */
    case 1132:  /* *mmx_smaxv4hi3 */
    case 1126:  /* *mmx_mulv4hi3 */
    case 1125:  /* *mmx_ussubv4hi3 */
    case 1124:  /* *mmx_sssubv4hi3 */
    case 1123:  /* *mmx_usaddv4hi3 */
    case 1122:  /* *mmx_ssaddv4hi3 */
    case 1121:  /* *mmx_ussubv8qi3 */
    case 1120:  /* *mmx_sssubv8qi3 */
    case 1119:  /* *mmx_usaddv8qi3 */
    case 1118:  /* *mmx_ssaddv8qi3 */
    case 1117:  /* *mmx_subv1di3 */
    case 1116:  /* *mmx_addv1di3 */
    case 1115:  /* *mmx_subv2si3 */
    case 1114:  /* *mmx_addv2si3 */
    case 1113:  /* *mmx_subv4hi3 */
    case 1112:  /* *mmx_addv4hi3 */
    case 1111:  /* *mmx_subv8qi3 */
    case 1110:  /* *mmx_addv8qi3 */
    case 1107:  /* *mmx_concatv2sf */
    case 1100:  /* mmx_gev2sf3 */
    case 1099:  /* mmx_gtv2sf3 */
    case 1098:  /* *mmx_eqv2sf3 */
    case 1089:  /* *mmx_sminv2sf3 */
    case 1088:  /* *mmx_smaxv2sf3 */
    case 1087:  /* *mmx_sminv2sf3_finite */
    case 1086:  /* *mmx_smaxv2sf3_finite */
    case 1085:  /* *mmx_mulv2sf3 */
    case 1084:  /* *mmx_subv2sf3 */
    case 1083:  /* *mmx_addv2sf3 */
    case 966:  /* smindf3 */
    case 965:  /* smaxdf3 */
    case 964:  /* sminsf3 */
    case 963:  /* smaxsf3 */
    case 587:  /* *bmi2_rorxdi3_1 */
    case 586:  /* *bmi2_rorxsi3_1 */
    case 545:  /* *bmi2_ashrdi3_1 */
    case 544:  /* *bmi2_lshrdi3_1 */
    case 543:  /* *bmi2_ashrsi3_1 */
    case 542:  /* *bmi2_lshrsi3_1 */
    case 512:  /* *bmi2_ashldi3_1 */
    case 511:  /* *bmi2_ashlsi3_1 */
    case 381:  /* *kxordi */
    case 380:  /* *kordi */
    case 379:  /* *kanddi */
    case 378:  /* *kxorsi */
    case 377:  /* *korsi */
    case 376:  /* *kandsi */
    case 375:  /* *kxorhi */
    case 374:  /* *korhi */
    case 373:  /* *kandhi */
    case 372:  /* *kxorqi */
    case 371:  /* *korqi */
    case 370:  /* *kandqi */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 369:  /* *testqi_ext_3 */
    case 368:  /* *testqi_ext_3 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 2));
      break;

    case 367:  /* *testqi_ext_2 */
    case 366:  /* *testqi_ext_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 1), 0));
      break;

    case 365:  /* *testqi_ext_0 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      break;

    case 359:  /* udivmodhiqi3 */
    case 348:  /* divmodhiqi3 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 0), 1), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0), 1), 0);
      recog_data.dup_num[1] = 2;
      break;

    case 358:  /* *udivmoddi4_noext */
    case 357:  /* *udivmodsi4_noext */
    case 356:  /* *udivmodhi4_noext */
    case 347:  /* *divmoddi4_noext */
    case 346:  /* *divmodsi4_noext */
    case 345:  /* *divmodhi4_noext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 2), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 2;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 3;
      break;

    case 355:  /* *udivmoddi4_pow2 */
    case 354:  /* *udivmodsi4_pow2 */
    case 353:  /* *udivmoddi4 */
    case 352:  /* *udivmodsi4 */
    case 351:  /* *udivmodhi4 */
    case 350:  /* udivmoddi4_1 */
    case 349:  /* udivmodsi4_1 */
    case 344:  /* *divmoddi4 */
    case 343:  /* *divmodsi4 */
    case 342:  /* *divmodhi4 */
    case 341:  /* divmoddi4_1 */
    case 340:  /* divmodsi4_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 2;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 3;
      break;

    case 339:  /* *umulsi3_highpart_zext */
    case 338:  /* *smulsi3_highpart_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 337:  /* *umulsi3_highpart_1 */
    case 336:  /* *smulsi3_highpart_1 */
    case 335:  /* *umuldi3_highpart_1 */
    case 334:  /* *smuldi3_highpart_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 333:  /* *umulqihi3_1 */
    case 332:  /* *mulqihi3_1 */
    case 331:  /* *mulditi3_1 */
    case 330:  /* *mulsidi3_1 */
    case 329:  /* *umulditi3_1 */
    case 328:  /* *umulsidi3_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      break;

    case 327:  /* *bmi2_umulsidi3_1 */
    case 326:  /* *bmi2_umulditi3_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0), 0), 0);
      recog_data.dup_num[0] = 2;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0), 1), 0);
      recog_data.dup_num[1] = 3;
      break;

    case 323:  /* *umulvdi4 */
    case 322:  /* *umulvsi4 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 2), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0);
      recog_data.dup_num[2] = 1;
      recog_data.dup_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 1);
      recog_data.dup_num[3] = 2;
      break;

    case 306:  /* *addsi3_zext_cc_overflow */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 1);
      recog_data.dup_num[1] = 2;
      recog_data.dup_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[2] = 1;
      break;

    case 305:  /* *adddi3_cc_overflow */
    case 304:  /* *addsi3_cc_overflow */
    case 303:  /* *addhi3_cc_overflow */
    case 302:  /* *addqi3_cc_overflow */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      recog_data.dup_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[2] = 1;
      break;

    case 301:  /* *adddi3_cconly_overflow */
    case 300:  /* *addsi3_cconly_overflow */
    case 299:  /* *addhi3_cconly_overflow */
    case 298:  /* *addqi3_cconly_overflow */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[0] = 1;
      break;

    case 297:  /* subborrowdi */
    case 296:  /* subborrowsi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 1);
      recog_data.dup_num[1] = 4;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 1), 0);
      recog_data.dup_num[2] = 3;
      recog_data.dup_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[3] = 2;
      break;

    case 295:  /* *subsi3_carry_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 1));
      break;

    case 294:  /* subdi3_carry */
    case 293:  /* subsi3_carry */
    case 292:  /* subhi3_carry */
    case 291:  /* subqi3_carry */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      break;

    case 290:  /* addcarrydi */
    case 289:  /* addcarrysi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 4;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0), 0);
      recog_data.dup_num[1] = 3;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 1);
      recog_data.dup_num[2] = 1;
      recog_data.dup_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[3] = 2;
      recog_data.dup_loc[4] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1);
      recog_data.dup_num[4] = 1;
      break;

    case 288:  /* *addsi3_carry_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      break;

    case 287:  /* adddi3_carry */
    case 286:  /* addsi3_carry */
    case 285:  /* addhi3_carry */
    case 284:  /* addqi3_carry */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      break;

    case 283:  /* *subsi_3_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 282:  /* *subdi_3 */
    case 281:  /* *subsi_3 */
    case 280:  /* *subhi_3 */
    case 279:  /* *subqi_3 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 255:  /* *lea_general_3 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[4] = *(ro_loc[4] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 3959:  /* xop_pmacssdd */
    case 3958:  /* xop_pmacsdd */
    case 3957:  /* xop_pmacssww */
    case 3956:  /* xop_pmacsww */
    case 257:  /* *lea_general_4 */
    case 256:  /* *lea_general_4 */
    case 254:  /* *lea_general_2 */
    case 253:  /* *lea_general_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 321:  /* *mulvdi4_1 */
    case 320:  /* *mulvdi4_1 */
    case 319:  /* *mulvsi4_1 */
    case 318:  /* *mulvsi4_1 */
    case 317:  /* *mulvhi4_1 */
    case 316:  /* *mulvhi4_1 */
    case 315:  /* *mulvqi4_1 */
    case 314:  /* *mulvqi4_1 */
    case 278:  /* *subvdi4_1 */
    case 277:  /* *subvsi4_1 */
    case 276:  /* *subvhi4_1 */
    case 275:  /* *subvqi4_1 */
    case 252:  /* *addvdi4_1 */
    case 251:  /* *addvsi4_1 */
    case 250:  /* *addvhi4_1 */
    case 249:  /* *addvqi4_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 1));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0);
      recog_data.dup_num[2] = 1;
      break;

    case 325:  /* *umulvqi4 */
    case 324:  /* *mulvqi4 */
    case 313:  /* *mulvdi4 */
    case 312:  /* *mulvsi4 */
    case 274:  /* *subvdi4 */
    case 273:  /* *subvsi4 */
    case 272:  /* *subvhi4 */
    case 271:  /* *subvqi4 */
    case 248:  /* *addvdi4 */
    case 247:  /* *addvsi4 */
    case 246:  /* *addvhi4 */
    case 245:  /* *addvqi4 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      recog_data.dup_loc[2] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 0);
      recog_data.dup_num[2] = 1;
      recog_data.dup_loc[3] = &XEXP (XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0), 1);
      recog_data.dup_num[3] = 2;
      break;

    case 451:  /* *xorqi_ext_2 */
    case 450:  /* *iorqi_ext_2 */
    case 449:  /* *xorqi_ext_1 */
    case 448:  /* *iorqi_ext_1 */
    case 400:  /* *andqi_ext_2 */
    case 399:  /* *andqi_ext_1 */
    case 244:  /* *addqi_ext_2 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      break;

    case 447:  /* *xorqi_ext_0 */
    case 446:  /* *iorqi_ext_0 */
    case 397:  /* andqi_ext_0 */
    case 243:  /* addqi_ext_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 577:  /* *ashrdi3_cconly */
    case 576:  /* *lshrdi3_cconly */
    case 575:  /* *ashrsi3_cconly */
    case 574:  /* *lshrsi3_cconly */
    case 573:  /* *ashrhi3_cconly */
    case 572:  /* *lshrhi3_cconly */
    case 571:  /* *ashrqi3_cconly */
    case 570:  /* *lshrqi3_cconly */
    case 528:  /* *ashldi3_cconly */
    case 527:  /* *ashlsi3_cconly */
    case 526:  /* *ashlhi3_cconly */
    case 525:  /* *ashlqi3_cconly */
    case 445:  /* *xordi_3 */
    case 444:  /* *iordi_3 */
    case 443:  /* *xorsi_3 */
    case 442:  /* *iorsi_3 */
    case 441:  /* *xorhi_3 */
    case 440:  /* *iorhi_3 */
    case 439:  /* *xorqi_3 */
    case 438:  /* *iorqi_3 */
    case 242:  /* *adddi_5 */
    case 241:  /* *addsi_5 */
    case 240:  /* *addhi_5 */
    case 239:  /* *addqi_5 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      break;

    case 234:  /* *addsi_3_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 233:  /* *adddi_3 */
    case 232:  /* *addsi_3 */
    case 231:  /* *addhi_3 */
    case 230:  /* *addqi_3 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      break;

    case 569:  /* *ashrsi3_cmp_zext */
    case 568:  /* *lshrsi3_cmp_zext */
    case 524:  /* *ashlsi3_cmp_zext */
    case 433:  /* *xorsi_2_zext */
    case 432:  /* *iorsi_2_zext */
    case 395:  /* *andsi_2_zext */
    case 270:  /* *subsi_2_zext */
    case 229:  /* *addsi_2_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 567:  /* *ashrdi3_cmp */
    case 566:  /* *lshrdi3_cmp */
    case 565:  /* *ashrsi3_cmp */
    case 564:  /* *lshrsi3_cmp */
    case 563:  /* *ashrhi3_cmp */
    case 562:  /* *lshrhi3_cmp */
    case 561:  /* *ashrqi3_cmp */
    case 560:  /* *lshrqi3_cmp */
    case 523:  /* *ashldi3_cmp */
    case 522:  /* *ashlsi3_cmp */
    case 521:  /* *ashlhi3_cmp */
    case 520:  /* *ashlqi3_cmp */
    case 422:  /* *xordi_2 */
    case 421:  /* *iordi_2 */
    case 420:  /* *xorsi_2 */
    case 419:  /* *iorsi_2 */
    case 418:  /* *xorhi_2 */
    case 417:  /* *iorhi_2 */
    case 416:  /* *xorqi_2 */
    case 415:  /* *iorqi_2 */
    case 394:  /* *andsi_2 */
    case 393:  /* *andhi_2 */
    case 392:  /* *andqi_2 */
    case 391:  /* *andqi_2_maybe_si */
    case 390:  /* *anddi_2 */
    case 269:  /* *subdi_2 */
    case 268:  /* *subsi_2 */
    case 267:  /* *subhi_2 */
    case 266:  /* *subqi_2 */
    case 228:  /* *adddi_2 */
    case 227:  /* *addsi_2 */
    case 226:  /* *addhi_2 */
    case 225:  /* *addqi_2 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 1), 1), 1);
      recog_data.dup_num[1] = 2;
      break;

    case 600:  /* *rotrqi3_1_slp */
    case 599:  /* *rotlqi3_1_slp */
    case 559:  /* *ashrqi3_1_slp */
    case 558:  /* *lshrqi3_1_slp */
    case 519:  /* *ashlqi3_1_slp */
    case 414:  /* *xorqi_1_slp */
    case 413:  /* *iorqi_1_slp */
    case 387:  /* *andqi_1_slp */
    case 265:  /* *subqi_1_slp */
    case 224:  /* *addqi_1_slp */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      recog_data.dup_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0);
      recog_data.dup_num[0] = 0;
      break;

    case 594:  /* *rotrsi3_1_zext */
    case 593:  /* *rotlsi3_1_zext */
    case 553:  /* *ashrsi3_1_zext */
    case 552:  /* *lshrsi3_1_zext */
    case 541:  /* *ashrsi3_cvt_zext */
    case 516:  /* *ashlsi3_1_zext */
    case 426:  /* kxnordi */
    case 425:  /* kxnorsi */
    case 424:  /* kxnorhi */
    case 423:  /* kxnorqi */
    case 410:  /* *xorsi_1_zext */
    case 409:  /* *iorsi_1_zext */
    case 384:  /* *andsi_1_zext */
    case 309:  /* *mulsi3_1_zext */
    case 264:  /* *subsi_1_zext */
    case 221:  /* addsi_1_zext */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0), 1));
      break;

    case 974:  /* pro_epilogue_adjust_stack_di_sub */
    case 973:  /* pro_epilogue_adjust_stack_si_sub */
    case 972:  /* pro_epilogue_adjust_stack_di_add */
    case 971:  /* pro_epilogue_adjust_stack_si_add */
    case 598:  /* *rotrhi3_1 */
    case 597:  /* *rotlhi3_1 */
    case 596:  /* *rotrqi3_1 */
    case 595:  /* *rotlqi3_1 */
    case 591:  /* *rotrdi3_1 */
    case 590:  /* *rotldi3_1 */
    case 589:  /* *rotrsi3_1 */
    case 588:  /* *rotlsi3_1 */
    case 557:  /* *ashrhi3_1 */
    case 556:  /* *lshrhi3_1 */
    case 555:  /* *ashrqi3_1 */
    case 554:  /* *lshrqi3_1 */
    case 549:  /* *ashrdi3_1 */
    case 548:  /* *lshrdi3_1 */
    case 547:  /* *ashrsi3_1 */
    case 546:  /* *lshrsi3_1 */
    case 540:  /* ashrsi3_cvt */
    case 539:  /* ashrdi3_cvt */
    case 536:  /* *ashrti3_doubleword */
    case 535:  /* *lshrti3_doubleword */
    case 534:  /* *ashrdi3_doubleword */
    case 533:  /* *lshrdi3_doubleword */
    case 518:  /* *ashlqi3_1 */
    case 517:  /* *ashlhi3_1 */
    case 514:  /* *ashldi3_1 */
    case 513:  /* *ashlsi3_1 */
    case 506:  /* *ashlti3_doubleword */
    case 505:  /* *ashldi3_doubleword */
    case 408:  /* *xorqi_1 */
    case 407:  /* *iorqi_1 */
    case 406:  /* *xorhi_1 */
    case 405:  /* *iorhi_1 */
    case 404:  /* *xordi_1 */
    case 403:  /* *iordi_1 */
    case 402:  /* *xorsi_1 */
    case 401:  /* *iorsi_1 */
    case 386:  /* *andqi_1 */
    case 385:  /* *andhi_1 */
    case 383:  /* *andsi_1 */
    case 382:  /* *anddi_1 */
    case 311:  /* *mulqi3_1 */
    case 310:  /* *mulhi3_1 */
    case 308:  /* *muldi3_1 */
    case 307:  /* *mulsi3_1 */
    case 263:  /* *subdi_1 */
    case 262:  /* *subsi_1 */
    case 261:  /* *subhi_1 */
    case 260:  /* *subqi_1 */
    case 259:  /* *subti3_doubleword */
    case 258:  /* *subdi3_doubleword */
    case 223:  /* *addqi_1 */
    case 222:  /* *addhi_1 */
    case 220:  /* *adddi_1 */
    case 219:  /* *addsi_1 */
    case 218:  /* *addti3_doubleword */
    case 217:  /* *adddi3_doubleword */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 214:  /* *floatunssixf2_i387_with_xmm */
    case 213:  /* *floatunssidf2_i387_with_xmm */
    case 212:  /* *floatunssisf2_i387_with_xmm */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 211:  /* floatdixf2_i387_with_xmm */
    case 210:  /* floatdidf2_i387_with_xmm */
    case 209:  /* floatdisf2_i387_with_xmm */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 3), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 2), 0));
      break;

    case 189:  /* fix_truncdi_i387_with_temp */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 3), 0));
      ro[5] = *(ro_loc[5] = &XEXP (XVECEXP (pat, 0, 4), 0));
      break;

    case 193:  /* fix_truncsi_i387_with_temp */
    case 192:  /* fix_trunchi_i387_with_temp */
    case 188:  /* fix_truncdi_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 3), 0));
      break;

    case 191:  /* fix_truncsi_i387 */
    case 190:  /* fix_trunchi_i387 */
    case 184:  /* fix_truncdi_i387_fisttp_with_temp */
    case 183:  /* fix_truncsi_i387_fisttp_with_temp */
    case 182:  /* fix_trunchi_i387_fisttp_with_temp */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (pat, 0, 2), 0));
      break;

    case 171:  /* *fixuns_truncdf_1 */
    case 170:  /* *fixuns_truncsf_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 2), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 3), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[4] = *(ro_loc[4] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 1265:  /* movdi_to_sse */
    case 698:  /* ffssi2_no_cmove */
    case 181:  /* fix_truncdi_i387_fisttp */
    case 180:  /* fix_truncsi_i387_fisttp */
    case 179:  /* fix_trunchi_i387_fisttp */
    case 165:  /* *truncxfdf2_mixed */
    case 164:  /* *truncxfsf2_mixed */
    case 162:  /* *truncdfsf_i387 */
    case 161:  /* *truncdfsf_mixed */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 1), 0));
      break;

    case 145:  /* extendsidi2_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (pat, 0, 2), 0));
      break;

    case 953:  /* *x86_movdicc_0_m1_neg */
    case 952:  /* *x86_movsicc_0_m1_neg */
    case 951:  /* *x86_movdicc_0_m1_se */
    case 950:  /* *x86_movsicc_0_m1_se */
    case 949:  /* *x86_movdicc_0_m1 */
    case 948:  /* *x86_movsicc_0_m1 */
    case 764:  /* *popcountdi2 */
    case 763:  /* *popcountsi2 */
    case 762:  /* *popcounthi2 */
    case 759:  /* *popcountdi2_falsedep_1 */
    case 758:  /* *popcountsi2_falsedep_1 */
    case 716:  /* *clzdi2_lzcnt */
    case 715:  /* *clzsi2_lzcnt */
    case 714:  /* *clzhi2_lzcnt */
    case 711:  /* *clzdi2_lzcnt_falsedep_1 */
    case 710:  /* *clzsi2_lzcnt_falsedep_1 */
    case 709:  /* *ctzdi2 */
    case 708:  /* *ctzsi2 */
    case 707:  /* *ctzhi2 */
    case 704:  /* *ctzdi2_falsedep_1 */
    case 703:  /* *ctzsi2_falsedep_1 */
    case 458:  /* *negdi2_1 */
    case 457:  /* *negsi2_1 */
    case 456:  /* *neghi2_1 */
    case 455:  /* *negqi2_1 */
    case 454:  /* *negti2_doubleword */
    case 453:  /* *negdi2_doubleword */
    case 187:  /* *fix_truncdi_i387_1 */
    case 186:  /* *fix_truncsi_i387_1 */
    case 185:  /* *fix_trunchi_i387_1 */
    case 142:  /* zero_extendqihi2_and */
    case 139:  /* zero_extendhisi2_and */
    case 138:  /* zero_extendqisi2_and */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      break;

    case 658:  /* *indirect_jump */
    case 657:  /* *indirect_jump */
    case 123:  /* *pushxf_rounded */
    case 122:  /* *pushxf_rounded */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 1));
      break;

    case 120:  /* *movqi_insv_2 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (pat, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 4252:  /* avx512cd_maskw_vec_dupv4si */
    case 4251:  /* avx512cd_maskw_vec_dupv8si */
    case 4250:  /* avx512cd_maskw_vec_dupv16si */
    case 4249:  /* avx512cd_maskb_vec_dupv2di */
    case 4248:  /* avx512cd_maskb_vec_dupv4di */
    case 4247:  /* avx512cd_maskb_vec_dupv8di */
    case 4229:  /* *avx512dq_broadcastv8sf */
    case 4227:  /* *avx512dq_broadcastv16sf */
    case 4225:  /* *avx512dq_broadcastv4si */
    case 4223:  /* *avx512dq_broadcastv8si */
    case 4221:  /* *avx512dq_broadcastv16si */
    case 4152:  /* avx512vl_vec_dupv8hi */
    case 4150:  /* avx512vl_vec_dupv16hi */
    case 4148:  /* avx512bw_vec_dupv32hi */
    case 4146:  /* avx512vl_vec_dupv32qi */
    case 4144:  /* avx512vl_vec_dupv16qi */
    case 4142:  /* avx512bw_vec_dupv64qi */
    case 4140:  /* avx512vl_vec_dupv2df */
    case 4138:  /* avx512vl_vec_dupv4df */
    case 4136:  /* avx512f_vec_dupv8df */
    case 4134:  /* avx512vl_vec_dupv4sf */
    case 4132:  /* avx512vl_vec_dupv8sf */
    case 4130:  /* avx512f_vec_dupv16sf */
    case 4128:  /* avx512vl_vec_dupv2di */
    case 4126:  /* avx512vl_vec_dupv4di */
    case 4124:  /* avx512f_vec_dupv8di */
    case 4122:  /* avx512vl_vec_dupv4si */
    case 4120:  /* avx512vl_vec_dupv8si */
    case 4118:  /* avx512f_vec_dupv16si */
    case 4117:  /* avx512bw_vec_dupv64qi_1 */
    case 4116:  /* avx512bw_vec_dupv32hi_1 */
    case 4115:  /* avx512f_vec_dupv8di_1 */
    case 4114:  /* avx512f_vec_dupv16si_1 */
    case 4113:  /* avx2_vec_dupv4df */
    case 4075:  /* avx2_pbroadcastv4di_1 */
    case 4074:  /* avx2_pbroadcastv8si_1 */
    case 4073:  /* avx2_pbroadcastv16hi_1 */
    case 4072:  /* avx2_pbroadcastv32qi_1 */
    case 4071:  /* avx2_pbroadcastv2di */
    case 4070:  /* avx2_pbroadcastv4di */
    case 4069:  /* avx2_pbroadcastv4si */
    case 4068:  /* avx2_pbroadcastv8si */
    case 4067:  /* avx2_pbroadcastv8hi */
    case 4066:  /* avx2_pbroadcastv16hi */
    case 4065:  /* avx2_pbroadcastv32hi */
    case 4064:  /* avx2_pbroadcastv16qi */
    case 4063:  /* avx2_pbroadcastv32qi */
    case 4062:  /* avx2_pbroadcastv64qi */
    case 4061:  /* avx2_pbroadcastv8di */
    case 4060:  /* avx2_pbroadcastv16si */
    case 3884:  /* sse4_1_zero_extendv2siv2di2 */
    case 3882:  /* sse4_1_sign_extendv2siv2di2 */
    case 3872:  /* sse4_1_zero_extendv2hiv2di2 */
    case 3870:  /* sse4_1_sign_extendv2hiv2di2 */
    case 3868:  /* avx2_zero_extendv4hiv4di2 */
    case 3866:  /* avx2_sign_extendv4hiv4di2 */
    case 3860:  /* sse4_1_zero_extendv2qiv2di2 */
    case 3858:  /* sse4_1_sign_extendv2qiv2di2 */
    case 3856:  /* avx2_zero_extendv4qiv4di2 */
    case 3854:  /* avx2_sign_extendv4qiv4di2 */
    case 3852:  /* avx512f_zero_extendv8qiv8di2 */
    case 3850:  /* avx512f_sign_extendv8qiv8di2 */
    case 3848:  /* sse4_1_zero_extendv4hiv4si2 */
    case 3846:  /* sse4_1_sign_extendv4hiv4si2 */
    case 3836:  /* sse4_1_zero_extendv4qiv4si2 */
    case 3834:  /* sse4_1_sign_extendv4qiv4si2 */
    case 3832:  /* avx2_zero_extendv8qiv8si2 */
    case 3830:  /* avx2_sign_extendv8qiv8si2 */
    case 3824:  /* sse4_1_zero_extendv8qiv8hi2 */
    case 3822:  /* sse4_1_sign_extendv8qiv8hi2 */
    case 3650:  /* *vec_extractv4si_0_zext */
    case 2900:  /* *avx512f_us_truncatev8div16qi2 */
    case 2899:  /* *avx512f_truncatev8div16qi2 */
    case 2898:  /* *avx512f_ss_truncatev8div16qi2 */
    case 2462:  /* avx512f_vec_dupv8df_1 */
    case 2461:  /* avx512f_vec_dupv16sf_1 */
    case 2460:  /* avx2_vec_dupv8sf_1 */
    case 2459:  /* avx2_vec_dupv4sf */
    case 2458:  /* avx2_vec_dupv8sf */
    case 2420:  /* sse2_cvtps2pd */
    case 2395:  /* vec_unpacks_lo_v16sf */
    case 2394:  /* *avx_cvtps2pd256_2 */
    case 2374:  /* sse2_cvttpd2dq */
    case 2368:  /* ufix_truncv2sfv2di2 */
    case 2366:  /* fix_truncv2sfv2di2 */
    case 2316:  /* ufix_truncv2dfv2si2 */
    case 2287:  /* sse2_cvtdq2pd */
    case 2286:  /* avx_cvtdq2pd256_2 */
    case 2285:  /* avx512f_cvtdq2pd512_2 */
    case 2283:  /* ufloatv2siv2df2 */
    case 2276:  /* *ufloatv2div2sf2 */
    case 2275:  /* *floatv2div2sf2 */
    case 2233:  /* sse2_cvttsd2siq */
    case 2231:  /* sse2_cvttsd2si */
    case 2223:  /* avx512f_vcvttsd2usiq */
    case 2221:  /* avx512f_vcvttsd2usi */
    case 2215:  /* avx512f_vcvttss2usiq */
    case 2213:  /* avx512f_vcvttss2usi */
    case 2126:  /* sse_cvttss2siq */
    case 2124:  /* sse_cvttss2si */
    case 2113:  /* sse_cvttps2pi */
    case 1264:  /* sse2_movq128 */
    case 1175:  /* *vec_dupv4hi */
    case 837:  /* sqrt_extenddfxf2_i387 */
    case 836:  /* sqrt_extendsfxf2_i387 */
    case 499:  /* *one_cmplsi2_1_zext */
    case 488:  /* *negextenddfxf2 */
    case 487:  /* *absextenddfxf2 */
    case 486:  /* *negextendsfxf2 */
    case 485:  /* *absextendsfxf2 */
    case 484:  /* *negextendsfdf2 */
    case 483:  /* *absextendsfdf2 */
    case 151:  /* *extendqisi2_zext */
    case 149:  /* *extendhisi2_zext */
    case 117:  /* *movqi_extzv_2 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      break;

    case 666:  /* *sibcall_memory */
    case 665:  /* *sibcall_memory */
    case 111:  /* *movstricthi_xor */
    case 110:  /* *movstrictqi_xor */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      break;

    case 134:  /* *swapdf */
    case 133:  /* *swapsf */
    case 132:  /* swapxf */
    case 107:  /* *swaphi_2 */
    case 106:  /* *swapqi_2 */
    case 105:  /* *swaphi_1 */
    case 104:  /* *swapqi_1 */
    case 103:  /* *swapdi */
    case 102:  /* *swapsi */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      recog_data.dup_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0);
      recog_data.dup_num[0] = 1;
      recog_data.dup_loc[1] = &XEXP (XVECEXP (pat, 0, 1), 1);
      recog_data.dup_num[1] = 0;
      break;

    case 4852:  /* clzv2di2 */
    case 4850:  /* clzv4di2 */
    case 4848:  /* clzv8di2 */
    case 4846:  /* clzv4si2 */
    case 4844:  /* clzv8si2 */
    case 4842:  /* clzv16si2 */
    case 4245:  /* *avx512dq_broadcastv4df_1 */
    case 4243:  /* *avx512dq_broadcastv4di_1 */
    case 4241:  /* *avx512dq_broadcastv8df_1 */
    case 4239:  /* *avx512dq_broadcastv8di_1 */
    case 4237:  /* *avx512dq_broadcastv16si_1 */
    case 4235:  /* *avx512dq_broadcastv16sf_1 */
    case 4233:  /* *avx512vl_broadcastv8sf_1 */
    case 4231:  /* *avx512vl_broadcastv8si_1 */
    case 4214:  /* vec_dupv4df */
    case 4213:  /* vec_dupv4di */
    case 4212:  /* vec_dupv8sf */
    case 4211:  /* vec_dupv8si */
    case 4210:  /* *vec_dupv4si */
    case 4209:  /* *vec_dupv8si */
    case 4208:  /* *vec_dupv8hi */
    case 4207:  /* *vec_dupv16hi */
    case 4206:  /* *vec_dupv16qi */
    case 4205:  /* *vec_dupv32qi */
    case 4200:  /* *vec_dupv2di */
    case 4199:  /* *vec_dupv4si */
    case 4198:  /* vec_dupv4sf */
    case 4196:  /* *avx512vl_vec_dup_gprv2df */
    case 4194:  /* *avx512vl_vec_dup_gprv4df */
    case 4192:  /* *avx512f_vec_dup_gprv8df */
    case 4190:  /* *avx512vl_vec_dup_gprv4sf */
    case 4188:  /* *avx512vl_vec_dup_gprv8sf */
    case 4186:  /* *avx512f_vec_dup_gprv16sf */
    case 4184:  /* *avx512vl_vec_dup_gprv2di */
    case 4182:  /* *avx512vl_vec_dup_gprv4di */
    case 4180:  /* *avx512f_vec_dup_gprv8di */
    case 4178:  /* *avx512vl_vec_dup_gprv4si */
    case 4176:  /* *avx512vl_vec_dup_gprv8si */
    case 4174:  /* *avx512f_vec_dup_gprv16si */
    case 4172:  /* *avx512vl_vec_dup_gprv8hi */
    case 4170:  /* *avx512vl_vec_dup_gprv16hi */
    case 4168:  /* *avx512bw_vec_dup_gprv32hi */
    case 4166:  /* *avx512vl_vec_dup_gprv32qi */
    case 4164:  /* *avx512vl_vec_dup_gprv16qi */
    case 4162:  /* *avx512bw_vec_dup_gprv64qi */
    case 4160:  /* *avx512f_broadcastv8di */
    case 4158:  /* *avx512f_broadcastv8df */
    case 4156:  /* *avx512f_broadcastv16si */
    case 4154:  /* *avx512f_broadcastv16sf */
    case 3880:  /* avx2_zero_extendv4siv4di2 */
    case 3878:  /* avx2_sign_extendv4siv4di2 */
    case 3876:  /* avx512f_zero_extendv8siv8di2 */
    case 3874:  /* avx512f_sign_extendv8siv8di2 */
    case 3864:  /* avx512f_zero_extendv8hiv8di2 */
    case 3862:  /* avx512f_sign_extendv8hiv8di2 */
    case 3844:  /* avx2_zero_extendv8hiv8si2 */
    case 3842:  /* avx2_sign_extendv8hiv8si2 */
    case 3840:  /* avx512f_zero_extendv16hiv16si2 */
    case 3838:  /* avx512f_sign_extendv16hiv16si2 */
    case 3828:  /* *avx512f_zero_extendv16qiv16si2 */
    case 3826:  /* *avx512f_sign_extendv16qiv16si2 */
    case 3820:  /* avx512bw_zero_extendv32qiv32hi2 */
    case 3818:  /* avx512bw_sign_extendv32qiv32hi2 */
    case 3816:  /* avx2_zero_extendv16qiv16hi2 */
    case 3814:  /* avx2_sign_extendv16qiv16hi2 */
    case 3775:  /* absv2si2 */
    case 3774:  /* absv4hi2 */
    case 3773:  /* absv8qi2 */
    case 3760:  /* *absv2di2 */
    case 3759:  /* *absv4di2 */
    case 3758:  /* *absv8di2 */
    case 3757:  /* *absv4si2 */
    case 3756:  /* *absv8si2 */
    case 3755:  /* *absv16si2 */
    case 3754:  /* *absv8hi2 */
    case 3753:  /* *absv16hi2 */
    case 3752:  /* *absv32hi2 */
    case 3751:  /* *absv16qi2 */
    case 3750:  /* *absv32qi2 */
    case 3749:  /* *absv64qi2 */
    case 3656:  /* *vec_extractv2di_1 */
    case 3651:  /* *vec_extractv2di_0_sse */
    case 3649:  /* *vec_extractv2di_0 */
    case 3648:  /* *vec_extractv4si_0 */
    case 2780:  /* *avx512vl_us_truncatev16hiv16qi2 */
    case 2779:  /* *avx512vl_truncatev16hiv16qi2 */
    case 2778:  /* *avx512vl_ss_truncatev16hiv16qi2 */
    case 2777:  /* *avx512vl_us_truncatev8siv8hi2 */
    case 2776:  /* *avx512vl_truncatev8siv8hi2 */
    case 2775:  /* *avx512vl_ss_truncatev8siv8hi2 */
    case 2774:  /* *avx512vl_us_truncatev4div4si2 */
    case 2773:  /* *avx512vl_truncatev4div4si2 */
    case 2772:  /* *avx512vl_ss_truncatev4div4si2 */
    case 2768:  /* avx512bw_us_truncatev32hiv32qi2 */
    case 2767:  /* avx512bw_truncatev32hiv32qi2 */
    case 2766:  /* avx512bw_ss_truncatev32hiv32qi2 */
    case 2753:  /* *avx512f_us_truncatev8div8hi2 */
    case 2752:  /* *avx512f_truncatev8div8hi2 */
    case 2751:  /* *avx512f_ss_truncatev8div8hi2 */
    case 2750:  /* *avx512f_us_truncatev8div8si2 */
    case 2749:  /* *avx512f_truncatev8div8si2 */
    case 2748:  /* *avx512f_ss_truncatev8div8si2 */
    case 2747:  /* *avx512f_us_truncatev16siv16hi2 */
    case 2746:  /* *avx512f_truncatev16siv16hi2 */
    case 2745:  /* *avx512f_ss_truncatev16siv16hi2 */
    case 2744:  /* *avx512f_us_truncatev16siv16qi2 */
    case 2743:  /* *avx512f_truncatev16siv16qi2 */
    case 2742:  /* *avx512f_ss_truncatev16siv16qi2 */
    case 2739:  /* vec_dupv2df */
    case 2735:  /* *vec_extractv2df_0_sse */
    case 2734:  /* sse2_storelpd */
    case 2733:  /* *vec_extractv2df_1_sse */
    case 2732:  /* sse2_storehpd */
    case 2536:  /* vec_extract_hi_v32qi */
    case 2535:  /* vec_extract_lo_v32qi */
    case 2534:  /* vec_extract_hi_v64qi */
    case 2533:  /* vec_extract_lo_v64qi */
    case 2532:  /* vec_extract_hi_v16hi */
    case 2531:  /* vec_extract_lo_v16hi */
    case 2530:  /* vec_extract_hi_v32hi */
    case 2529:  /* vec_extract_lo_v32hi */
    case 2527:  /* vec_extract_hi_v8sf */
    case 2525:  /* vec_extract_hi_v8si */
    case 2519:  /* vec_extract_lo_v8sf */
    case 2517:  /* vec_extract_lo_v8si */
    case 2516:  /* vec_extract_hi_v4df */
    case 2515:  /* vec_extract_hi_v4di */
    case 2509:  /* vec_extract_lo_v4df */
    case 2507:  /* vec_extract_lo_v4di */
    case 2505:  /* vec_extract_lo_v16si */
    case 2503:  /* vec_extract_lo_v16sf */
    case 2501:  /* vec_extract_hi_v16si */
    case 2499:  /* vec_extract_hi_v16sf */
    case 2495:  /* vec_extract_hi_v8di */
    case 2493:  /* vec_extract_hi_v8df */
    case 2489:  /* vec_extract_lo_v8di */
    case 2487:  /* vec_extract_lo_v8df */
    case 2470:  /* *vec_extractv4sf_0 */
    case 2455:  /* sse_storelps */
    case 2453:  /* sse_storehps */
    case 2392:  /* avx_cvtps2pd256 */
    case 2388:  /* avx512f_cvtps2pd512 */
    case 2384:  /* avx_cvtpd2ps256 */
    case 2380:  /* *avx512f_cvtpd2ps512 */
    case 2372:  /* ufix_truncv4sfv4si2 */
    case 2370:  /* ufix_truncv8sfv8si2 */
    case 2364:  /* ufix_truncv4sfv4di2 */
    case 2362:  /* fix_truncv4sfv4di2 */
    case 2358:  /* ufix_truncv8sfv8di2 */
    case 2354:  /* fix_truncv8sfv8di2 */
    case 2336:  /* ufix_truncv2dfv2di2 */
    case 2334:  /* fix_truncv2dfv2di2 */
    case 2332:  /* ufix_truncv4dfv4di2 */
    case 2330:  /* fix_truncv4dfv4di2 */
    case 2326:  /* ufix_truncv8dfv8di2 */
    case 2322:  /* fix_truncv8dfv8di2 */
    case 2320:  /* ufix_truncv4dfv4si2 */
    case 2318:  /* fix_truncv4dfv4si2 */
    case 2312:  /* ufix_truncv8dfv8si2 */
    case 2308:  /* fix_truncv8dfv8si2 */
    case 2281:  /* ufloatv4siv4df2 */
    case 2279:  /* ufloatv8siv8df2 */
    case 2273:  /* ufloatv4div4sf2 */
    case 2271:  /* floatv4div4sf2 */
    case 2267:  /* ufloatv8div8sf2 */
    case 2263:  /* floatv8div8sf2 */
    case 2259:  /* ufloatv2div2df2 */
    case 2255:  /* floatv2div2df2 */
    case 2251:  /* ufloatv4div4df2 */
    case 2247:  /* floatv4div4df2 */
    case 2243:  /* ufloatv8div8df2 */
    case 2239:  /* floatv8div8df2 */
    case 2237:  /* floatv4siv4df2 */
    case 2235:  /* floatv8siv8df2 */
    case 2205:  /* sse2_cvttpd2pi */
    case 2203:  /* sse2_cvtpi2pd */
    case 2201:  /* fix_truncv4sfv4si2 */
    case 2199:  /* fix_truncv8sfv8si2 */
    case 2195:  /* ufix_truncv16sfv16si2 */
    case 2191:  /* fix_truncv16sfv16si2 */
    case 2151:  /* ufloatv4siv4sf2 */
    case 2147:  /* ufloatv8siv8sf2 */
    case 2143:  /* ufloatv16siv16sf2 */
    case 2141:  /* floatv4siv4sf2 */
    case 2139:  /* floatv8siv8sf2 */
    case 2135:  /* floatv16siv16sf2 */
    case 1492:  /* sse2_sqrtv2df2 */
    case 1490:  /* avx_sqrtv4df2 */
    case 1486:  /* avx512f_sqrtv8df2 */
    case 1484:  /* sse_sqrtv4sf2 */
    case 1482:  /* avx_sqrtv8sf2 */
    case 1478:  /* avx512f_sqrtv16sf2 */
    case 1179:  /* *vec_extractv2si_1 */
    case 1178:  /* *vec_extractv2si_0 */
    case 1176:  /* *vec_dupv2si */
    case 1174:  /* mmx_pswapdv2si2 */
    case 1109:  /* *vec_extractv2sf_1 */
    case 1108:  /* *vec_extractv2sf_0 */
    case 1106:  /* *vec_dupv2sf */
    case 1105:  /* mmx_pswapdv2sf2 */
    case 1104:  /* mmx_floatv2si2 */
    case 1101:  /* mmx_pf2id */
    case 840:  /* *sqrtdf2_sse */
    case 839:  /* *sqrtsf2_sse */
    case 835:  /* sqrtxf2 */
    case 768:  /* *bswapdi2 */
    case 767:  /* *bswapsi2 */
    case 766:  /* *bswapdi2_movbe */
    case 765:  /* *bswapsi2_movbe */
    case 498:  /* *one_cmplqi2_1 */
    case 497:  /* *one_cmplhi2_1 */
    case 496:  /* *one_cmpldi2_1 */
    case 495:  /* *one_cmplsi2_1 */
    case 482:  /* *negxf2_1 */
    case 481:  /* *absxf2_1 */
    case 480:  /* *negdf2_1 */
    case 479:  /* *absdf2_1 */
    case 478:  /* *negsf2_1 */
    case 477:  /* *abssf2_1 */
    case 208:  /* *floatdidf2_i387 */
    case 207:  /* *floatdisf2_i387 */
    case 206:  /* *floatsidf2_i387 */
    case 205:  /* *floatsisf2_i387 */
    case 204:  /* *floatdidf2_sse */
    case 203:  /* *floatsidf2_sse */
    case 202:  /* *floatdisf2_sse */
    case 201:  /* *floatsisf2_sse */
    case 200:  /* floatdixf2 */
    case 199:  /* floatsixf2 */
    case 198:  /* floathixf2 */
    case 197:  /* floathidf2 */
    case 196:  /* floathisf2 */
    case 178:  /* fix_truncdi_fisttp_i387_1 */
    case 177:  /* fix_truncsi_fisttp_i387_1 */
    case 176:  /* fix_trunchi_fisttp_i387_1 */
    case 175:  /* fix_truncdfdi_sse */
    case 174:  /* fix_truncdfsi_sse */
    case 173:  /* fix_truncsfdi_sse */
    case 172:  /* fix_truncsfsi_sse */
    case 169:  /* *truncxfdf2_i387 */
    case 168:  /* *truncxfsf2_i387 */
    case 167:  /* truncxfdf2_i387_noop */
    case 166:  /* truncxfsf2_i387_noop */
    case 163:  /* *truncdfsf2_i387_1 */
    case 160:  /* *truncdfsf_fast_i387 */
    case 159:  /* *truncdfsf_fast_sse */
    case 158:  /* *truncdfsf_fast_mixed */
    case 157:  /* *extenddfxf2_i387 */
    case 156:  /* *extendsfxf2_i387 */
    case 155:  /* *extendsfdf2_i387 */
    case 154:  /* *extendsfdf2_sse */
    case 153:  /* *extendsfdf2_mixed */
    case 152:  /* extendqihi2 */
    case 150:  /* extendqisi2 */
    case 148:  /* extendhisi2 */
    case 147:  /* extendhidi2 */
    case 146:  /* extendqidi2 */
    case 144:  /* *extendsidi2_rex64 */
    case 143:  /* *zero_extendqihi2 */
    case 141:  /* *zero_extendhisi2 */
    case 140:  /* *zero_extendqisi2 */
    case 137:  /* zero_extendhidi2 */
    case 136:  /* zero_extendqidi2 */
    case 135:  /* *zero_extendsidi2 */
    case 116:  /* *movdi_extzv_1 */
    case 115:  /* *movsi_extzv_1 */
    case 114:  /* *movqi_extv_1 */
    case 113:  /* *movsi_extv_1 */
    case 112:  /* *movhi_extv_1 */
    case 101:  /* *movabsdi_2 */
    case 100:  /* *movabssi_2 */
    case 99:  /* *movabshi_2 */
    case 98:  /* *movabsqi_2 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 0));
      break;

    case 664:  /* *sibcall */
    case 663:  /* *sibcall */
    case 662:  /* *call */
    case 661:  /* *call */
    case 610:  /* *setcc_qi_slp */
    case 119:  /* movdi_insv_1 */
    case 118:  /* movsi_insv_1 */
    case 109:  /* *movstricthi_1 */
    case 108:  /* *movstrictqi_1 */
    case 97:  /* *movabsdi_1 */
    case 96:  /* *movabssi_1 */
    case 95:  /* *movabshi_1 */
    case 94:  /* *movabsqi_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (pat, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (pat, 1));
      break;

    case 4914:  /* storedi_via_fpu */
    case 4913:  /* loaddi_via_fpu */
    case 4878:  /* avx512f_pd512_256pd */
    case 4877:  /* avx512f_ps512_256ps */
    case 4876:  /* avx512f_si512_256si */
    case 4875:  /* avx512f_pd512_pd */
    case 4874:  /* avx512f_ps512_ps */
    case 4873:  /* avx512f_si512_si */
    case 4864:  /* *conflictv2di */
    case 4862:  /* *conflictv4di */
    case 4860:  /* *conflictv8di */
    case 4858:  /* *conflictv4si */
    case 4856:  /* *conflictv8si */
    case 4854:  /* *conflictv16si */
    case 4511:  /* *avx512f_vcvtph2ps512 */
    case 4509:  /* vcvtph2ps256 */
    case 4507:  /* *vcvtph2ps_load */
    case 4438:  /* avx_pd256_pd */
    case 4437:  /* avx_ps256_ps */
    case 4436:  /* avx_si256_si */
    case 4055:  /* aesimc */
    case 4028:  /* xop_frczv4df2 */
    case 4027:  /* xop_frczv8sf2 */
    case 4026:  /* xop_frczv2df2 */
    case 4025:  /* xop_frczv4sf2 */
    case 4024:  /* xop_frczdf2 */
    case 4023:  /* xop_frczsf2 */
    case 3948:  /* *avx512er_rsqrt28v8df */
    case 3944:  /* *avx512er_rsqrt28v16sf */
    case 3936:  /* *avx512er_rcp28v8df */
    case 3932:  /* *avx512er_rcp28v16sf */
    case 3928:  /* avx512er_exp2v8df */
    case 3924:  /* avx512er_exp2v16sf */
    case 3813:  /* sse4_1_phminposuw */
    case 3798:  /* sse4_1_movntdqa */
    case 3797:  /* avx2_movntdqa */
    case 3796:  /* avx512f_movntdqa */
    case 3777:  /* sse4a_movntdf */
    case 3776:  /* sse4a_movntsf */
    case 3681:  /* sse2_pmovmskb */
    case 3680:  /* avx2_pmovmskb */
    case 3679:  /* sse2_movmskpd */
    case 3678:  /* avx_movmskpd256 */
    case 3677:  /* sse_movmskps */
    case 3676:  /* avx_movmskps256 */
    case 2615:  /* avx512vl_getexpv2df */
    case 2611:  /* avx512vl_getexpv4df */
    case 2607:  /* avx512f_getexpv8df */
    case 2603:  /* avx512vl_getexpv4sf */
    case 2599:  /* avx512vl_getexpv8sf */
    case 2595:  /* avx512f_getexpv16sf */
    case 2407:  /* avx512vl_cvtq2maskv2di */
    case 2406:  /* avx512vl_cvtq2maskv4di */
    case 2405:  /* avx512f_cvtq2maskv8di */
    case 2404:  /* avx512vl_cvtd2maskv4si */
    case 2403:  /* avx512vl_cvtd2maskv8si */
    case 2402:  /* avx512f_cvtd2maskv16si */
    case 2401:  /* avx512vl_cvtw2maskv8hi */
    case 2400:  /* avx512vl_cvtw2maskv16hi */
    case 2399:  /* avx512bw_cvtw2maskv32hi */
    case 2398:  /* avx512vl_cvtb2maskv32qi */
    case 2397:  /* avx512vl_cvtb2maskv16qi */
    case 2396:  /* avx512bw_cvtb2maskv64qi */
    case 2352:  /* ufix_notruncv2dfv2di2 */
    case 2350:  /* ufix_notruncv4dfv4di2 */
    case 2346:  /* ufix_notruncv8dfv8di2 */
    case 2344:  /* fix_notruncv2dfv2di2 */
    case 2342:  /* fix_notruncv4dfv4di2 */
    case 2338:  /* fix_notruncv8dfv8di2 */
    case 2302:  /* ufix_notruncv4dfv4si2 */
    case 2298:  /* ufix_notruncv8dfv8si2 */
    case 2293:  /* avx_cvtpd2dq256 */
    case 2289:  /* *avx512f_cvtpd2dq512 */
    case 2230:  /* sse2_cvtsd2siq_2 */
    case 2227:  /* sse2_cvtsd2si_2 */
    case 2204:  /* sse2_cvtpd2pi */
    case 2187:  /* *avx512dq_cvtps2uqqv4di */
    case 2183:  /* *avx512dq_cvtps2uqqv8di */
    case 2179:  /* *avx512dq_cvtps2qqv4di */
    case 2175:  /* *avx512dq_cvtps2qqv8di */
    case 2171:  /* *avx512vl_ufix_notruncv4sfv4si */
    case 2167:  /* *avx512vl_ufix_notruncv8sfv8si */
    case 2163:  /* *avx512f_ufix_notruncv16sfv16si */
    case 2159:  /* *avx512f_fix_notruncv16sfv16si */
    case 2157:  /* sse2_fix_notruncv4sfv4si */
    case 2155:  /* avx_fix_notruncv8sfv8si */
    case 2123:  /* sse_cvtss2siq_2 */
    case 2120:  /* sse_cvtss2si_2 */
    case 1510:  /* *rsqrt14v2df */
    case 1508:  /* *rsqrt14v4df */
    case 1506:  /* *rsqrt14v8df */
    case 1504:  /* *rsqrt14v4sf */
    case 1502:  /* *rsqrt14v8sf */
    case 1500:  /* *rsqrt14v16sf */
    case 1499:  /* sse_rsqrtv4sf2 */
    case 1498:  /* avx_rsqrtv8sf2 */
    case 1474:  /* *rcp14v2df */
    case 1472:  /* *rcp14v4df */
    case 1470:  /* *rcp14v8df */
    case 1468:  /* *rcp14v4sf */
    case 1466:  /* *rcp14v8sf */
    case 1464:  /* *rcp14v16sf */
    case 1462:  /* sse_rcpv4sf2 */
    case 1461:  /* avx_rcpv8sf2 */
    case 1350:  /* sse2_movntv2di */
    case 1349:  /* avx_movntv4di */
    case 1348:  /* avx512f_movntv8di */
    case 1347:  /* sse2_movntv2df */
    case 1346:  /* avx_movntv4df */
    case 1345:  /* avx512f_movntv8df */
    case 1344:  /* sse_movntv4sf */
    case 1343:  /* avx_movntv8sf */
    case 1342:  /* avx512f_movntv16sf */
    case 1341:  /* sse2_movntidi */
    case 1340:  /* sse2_movntisi */
    case 1339:  /* sse3_lddqu */
    case 1338:  /* avx_lddqu256 */
    case 1325:  /* avx512vl_storedquv2di */
    case 1324:  /* avx512vl_storedquv4di */
    case 1323:  /* avx512f_storedquv8di */
    case 1322:  /* sse2_storedquv4si */
    case 1321:  /* avx_storedquv8si */
    case 1320:  /* avx512f_storedquv16si */
    case 1319:  /* avx512vl_storedquv16hi */
    case 1318:  /* avx512vl_storedquv8hi */
    case 1317:  /* avx512bw_storedquv32hi */
    case 1316:  /* avx512f_storedquv64qi */
    case 1315:  /* sse2_storedquv16qi */
    case 1314:  /* avx_storedquv32qi */
    case 1312:  /* *avx512vl_loaddquv2di */
    case 1310:  /* *avx512vl_loaddquv4di */
    case 1308:  /* *avx512f_loaddquv8di */
    case 1306:  /* *sse2_loaddquv4si */
    case 1304:  /* *avx_loaddquv8si */
    case 1302:  /* *avx512f_loaddquv16si */
    case 1300:  /* *avx512vl_loaddquv16hi */
    case 1298:  /* *avx512vl_loaddquv8hi */
    case 1296:  /* *avx512bw_loaddquv32hi */
    case 1294:  /* *avx512f_loaddquv64qi */
    case 1292:  /* *sse2_loaddquv16qi */
    case 1290:  /* *avx_loaddquv32qi */
    case 1283:  /* sse2_storeupd */
    case 1282:  /* avx_storeupd256 */
    case 1281:  /* avx512f_storeupd512 */
    case 1280:  /* sse_storeups */
    case 1279:  /* avx_storeups256 */
    case 1278:  /* avx512f_storeups512 */
    case 1276:  /* *sse2_loadupd */
    case 1274:  /* *avx_loadupd256 */
    case 1272:  /* *avx512f_loadupd512 */
    case 1270:  /* *sse_loadups */
    case 1268:  /* *avx_loadups256 */
    case 1266:  /* *avx512f_loadups512 */
    case 1184:  /* mmx_pmovmskb */
    case 1093:  /* mmx_rsqrtv2sf2 */
    case 1090:  /* mmx_rcpv2sf2 */
    case 1082:  /* sse_movntq */
    case 1076:  /* move_size_reloc_di */
    case 1075:  /* move_size_reloc_si */
    case 1010:  /* xsaves */
    case 1009:  /* xsavec */
    case 1008:  /* xsaveopt */
    case 1007:  /* xsave */
    case 997:  /* rdpmc */
    case 912:  /* movmsk_df */
    case 911:  /* fxamdf2_i387_with_temp */
    case 910:  /* fxamsf2_i387_with_temp */
    case 909:  /* fxamxf2_i387 */
    case 908:  /* fxamdf2_i387 */
    case 907:  /* fxamsf2_i387 */
    case 878:  /* fistsi2 */
    case 877:  /* fisthi2 */
    case 876:  /* *fistsi2_1 */
    case 875:  /* *fisthi2_1 */
    case 872:  /* *fistdi2_1 */
    case 871:  /* rintxf2 */
    case 867:  /* *f2xm1xf2_i387 */
    case 844:  /* *cosxf2_i387 */
    case 843:  /* *sinxf2_i387 */
    case 838:  /* *rsqrtsf2_sse */
    case 834:  /* truncxfdf2_i387_noop_unspec */
    case 833:  /* truncxfsf2_i387_noop_unspec */
    case 805:  /* *rcpsf2_sse */
    case 794:  /* *tls_dynamic_gnu2_lea_64 */
    case 91:  /* kmovw */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XVECEXP (XEXP (pat, 1), 0, 0));
      break;

    case 607:  /* *setcc_si_1_and */
    case 85:  /* *movdi_or */
    case 84:  /* *movsi_or */
    case 83:  /* *movdi_xor */
    case 82:  /* *movsi_xor */
    case 77:  /* *popdi1_epilogue */
    case 76:  /* *popsi1_epilogue */
    case 73:  /* *pushdi2_prologue */
    case 72:  /* *pushsi2_prologue */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (pat, 0, 0), 1));
      break;

    case 1209:  /* *movv2df_internal */
    case 1208:  /* *movv4df_internal */
    case 1207:  /* *movv8df_internal */
    case 1206:  /* *movv4sf_internal */
    case 1205:  /* *movv8sf_internal */
    case 1204:  /* *movv16sf_internal */
    case 1203:  /* *movv1ti_internal */
    case 1202:  /* *movv2ti_internal */
    case 1201:  /* *movv4ti_internal */
    case 1200:  /* *movv2di_internal */
    case 1199:  /* *movv4di_internal */
    case 1198:  /* *movv8di_internal */
    case 1197:  /* *movv4si_internal */
    case 1196:  /* *movv8si_internal */
    case 1195:  /* *movv16si_internal */
    case 1194:  /* *movv8hi_internal */
    case 1193:  /* *movv16hi_internal */
    case 1192:  /* *movv32hi_internal */
    case 1191:  /* *movv16qi_internal */
    case 1190:  /* *movv32qi_internal */
    case 1189:  /* *movv64qi_internal */
    case 1081:  /* *movv2sf_internal */
    case 1080:  /* *movv1di_internal */
    case 1079:  /* *movv2si_internal */
    case 1078:  /* *movv4hi_internal */
    case 1077:  /* *movv8qi_internal */
    case 1064:  /* *movbnd64_internal_mpx */
    case 1063:  /* *movbnd32_internal_mpx */
    case 983:  /* *prefetch_3dnow */
    case 609:  /* *setcc_qi */
    case 608:  /* *setcc_si_1_movzbl */
    case 606:  /* *setcc_di_1 */
    case 216:  /* *leadi */
    case 215:  /* *leasi */
    case 131:  /* *movsf_internal */
    case 130:  /* *movdf_internal */
    case 129:  /* *movxf_internal */
    case 128:  /* *movtf_internal */
    case 127:  /* *pushsf */
    case 126:  /* *pushsf_rex64 */
    case 125:  /* *pushdf */
    case 124:  /* *pushxf */
    case 121:  /* *pushtf */
    case 93:  /* *movqi_internal */
    case 92:  /* *movhi_internal */
    case 90:  /* *movsi_internal */
    case 89:  /* *movdi_internal */
    case 88:  /* *movti_internal */
    case 87:  /* *movoi_internal_avx */
    case 86:  /* *movxi_internal_avx512f */
    case 81:  /* *popfldi1 */
    case 80:  /* *popflsi1 */
    case 79:  /* *pushfldi2 */
    case 78:  /* *pushflsi2 */
    case 75:  /* *popdi1 */
    case 74:  /* *popsi1 */
    case 71:  /* *pushhi2 */
    case 70:  /* *pushqi2 */
    case 69:  /* *pushsi2_rex64 */
    case 68:  /* *pushhi2_rex64 */
    case 67:  /* *pushqi2_rex64 */
    case 66:  /* *pushsi2 */
    case 65:  /* *pushdi2_rex64 */
    case 64:  /* *pushti2 */
    case 63:  /* *pushdi2 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (pat, 1));
      break;

    case 195:  /* x86_fldcw_1 */
    case 48:  /* x86_sahf_1 */
      ro[0] = *(ro_loc[0] = &XVECEXP (XEXP (pat, 1), 0, 0));
      break;

    case 3685:  /* sse_stmxcsr */
    case 1040:  /* rdgsbasedi */
    case 1039:  /* rdfsbasedi */
    case 1038:  /* rdgsbasesi */
    case 1037:  /* rdfsbasesi */
    case 1032:  /* lwp_slwpcbdi */
    case 1031:  /* lwp_slwpcbsi */
    case 1027:  /* fnstsw */
    case 1004:  /* fxsave64 */
    case 1003:  /* fxsave */
    case 999:  /* rdtsc */
    case 984:  /* *prefetch_prefetchwt1 */
    case 786:  /* *load_tp_di */
    case 785:  /* *load_tp_si */
    case 784:  /* *load_tp_x32_zext */
    case 783:  /* *load_tp_x32 */
    case 691:  /* set_got_rex64 */
    case 194:  /* x86_fnstcw_1 */
    case 47:  /* x86_fnstsw_1 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      break;

    case 46:  /* *cmpxf_si_cc_i387 */
    case 45:  /* *cmpdf_si_cc_i387 */
    case 44:  /* *cmpsf_si_cc_i387 */
    case 43:  /* *cmpxf_hi_cc_i387 */
    case 42:  /* *cmpdf_hi_cc_i387 */
    case 41:  /* *cmpsf_hi_cc_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 40:  /* *cmpxf_si_i387 */
    case 39:  /* *cmpdf_si_i387 */
    case 38:  /* *cmpsf_si_i387 */
    case 37:  /* *cmpxf_hi_i387 */
    case 36:  /* *cmpdf_hi_i387 */
    case 35:  /* *cmpsf_hi_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 1), 0));
      ro[3] = *(ro_loc[3] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 1));
      break;

    case 238:  /* *addsi_4 */
    case 237:  /* *addhi_4 */
    case 236:  /* *addqi_4 */
    case 235:  /* *adddi_4 */
    case 34:  /* *cmpuxf_cc_i387 */
    case 33:  /* *cmpudf_cc_i387 */
    case 32:  /* *cmpusf_cc_i387 */
    case 28:  /* *cmpdf_cc_i387 */
    case 27:  /* *cmpsf_cc_i387 */
    case 24:  /* *cmpxf_cc_i387 */
    case 22:  /* *cmpxf_0_cc_i387 */
    case 21:  /* *cmpdf_0_cc_i387 */
    case 20:  /* *cmpsf_0_cc_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (XVECEXP (pat, 0, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XEXP (XVECEXP (pat, 0, 0), 1), 1));
      break;

    case 31:  /* *cmpuxf_i387 */
    case 30:  /* *cmpudf_i387 */
    case 29:  /* *cmpusf_i387 */
    case 26:  /* *cmpdf_i387 */
    case 25:  /* *cmpsf_i387 */
    case 23:  /* *cmpxf_i387 */
    case 19:  /* *cmpxf_0_i387 */
    case 18:  /* *cmpdf_0_i387 */
    case 17:  /* *cmpsf_0_i387 */
      ro[0] = *(ro_loc[0] = &XEXP (pat, 0));
      ro[1] = *(ro_loc[1] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 0));
      ro[2] = *(ro_loc[2] = &XEXP (XVECEXP (XEXP (pat, 1), 0, 0), 1));
      break;

    case 16:  /* *cmpqi_ext_4 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0));
      break;

    case 15:  /* *cmpqi_ext_3 */
    case 14:  /* *cmpqi_ext_2 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 0), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 1));
      break;

    case 13:  /* *cmpqi_ext_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (pat, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (XEXP (pat, 1), 1), 0), 0));
      break;

    case 428:  /* kortestchi */
    case 427:  /* kortestzhi */
    case 364:  /* *testsi_1 */
    case 363:  /* *testhi_1 */
    case 362:  /* *testqi_1 */
    case 361:  /* *testqi_1_maybe_si */
    case 360:  /* *testdi_1 */
    case 12:  /* *cmpdi_minus_1 */
    case 11:  /* *cmpsi_minus_1 */
    case 10:  /* *cmphi_minus_1 */
    case 9:  /* *cmpqi_minus_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (XEXP (pat, 1), 0), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (XEXP (pat, 1), 0), 1));
      break;

    case 62:  /* *cmpiuxf_i387 */
    case 61:  /* *cmpiudf_i387 */
    case 60:  /* *cmpiusf_i387 */
    case 59:  /* *cmpixf_i387 */
    case 58:  /* *cmpidf_i387 */
    case 57:  /* *cmpisf_i387 */
    case 56:  /* *cmpiudf_sse */
    case 55:  /* *cmpiusf_sse */
    case 54:  /* *cmpidf_sse */
    case 53:  /* *cmpisf_sse */
    case 52:  /* *cmpiudf_mixed */
    case 51:  /* *cmpiusf_mixed */
    case 50:  /* *cmpidf_mixed */
    case 49:  /* *cmpisf_mixed */
    case 8:  /* *cmpdi_1 */
    case 7:  /* *cmpsi_1 */
    case 6:  /* *cmphi_1 */
    case 5:  /* *cmpqi_1 */
    case 4:  /* *cmpdi_ccno_1 */
    case 3:  /* *cmpsi_ccno_1 */
    case 2:  /* *cmphi_ccno_1 */
    case 1:  /* *cmpqi_ccno_1 */
      ro[0] = *(ro_loc[0] = &XEXP (XEXP (pat, 1), 0));
      ro[1] = *(ro_loc[1] = &XEXP (XEXP (pat, 1), 1));
      break;

    }
}
