#include "init.h"
#include "registers.h"

void clock_init(void)
{
	PRCR = (PR_KEY << PR_KEY_OFF) | (WR_EN << PRC0_OFF);              

	HOCOCR  = CR_STOP;
	HOCOCR2 = HOCO_80MHZ;
	HOCOCR  = CR_OPERATE;
    	
	while ((OSCSF & (1 << HOCOSF_OFF)) != OSC_STABLE);

	SCKDIVCR = (CKDIV_2 << FCLK_OFF) | (CKDIV_1 << ICLK_OFF) | 
			(CKDIV_1 << PCKA_OFF) | (CKDIV_2 << PCKB_OFF) |
			(CKDIV_2 << PCKC_OFF) | (CKDIV_1 << PCKD_OFF);
	SCKSCR   = SRC_HOCO;

	PRCR = (PR_KEY << PR_KEY_OFF) | (WR_DIS << PRC0_OFF);
}

void systick_init(void)
{
	SYST_RVR = (CPU_HZ / 1000UL) - 1UL; /* 1 ms */
	SYST_CVR = 0;
	SYST_CSR = 0x7;
}
