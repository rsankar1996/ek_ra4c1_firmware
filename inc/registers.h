#ifndef REGISTERS_H

#include <stdint.h>

#define REG32(a) 		(*(volatile uint32_t *)(a))
#define REG16(a) 		(*(volatile uint16_t *)(a))
#define REG8(a)  		(*(volatile uint8_t  *)(a))

#define SYS_BASE   		0x4001E000UL
#define SCKDIVCR   		REG32(SYS_BASE + 0x020)
#define SCKSCR     		REG8 (SYS_BASE + 0x026)
#define MEMWAIT    		REG8 (SYS_BASE + 0x031)
#define HOCOCR     		REG8 (SYS_BASE + 0x036)
#define HOCOCR2    		REG8 (SYS_BASE + 0x037)
#define OSCSF      		REG8 (SYS_BASE + 0x03C)
#define PRCR       		REG16(SYS_BASE + 0x3FE)

/* SCKDIVCR BITS */
#define PCKD_OFF		(0U)
#define PCKC_OFF		(4U)
#define PCKB_OFF		(8U)
#define PCKA_OFF		(12U)
#define ICLK_OFF		(24U)
#define FCLK_OFF		(28U)

#define CKDIV_1			(0U)
#define CKDIV_2			(1U)
#define CKDIV_4			(2U)
#define CKDIV_8			(3U)
#define CKDIV_16		(4U)
#define CKDIV_32		(5U)
#define CKDIV_64		(6U)

/* SCKSCR BITS */
#define SRC_HOCO		(0U)
#define SRC_MOCO		(1U)
#define SRC_LOCO		(2U)
#define SRC_MOSC		(3U)
#define SRC_SOSC		(4U)
#define SRC_PLL			(5U)

/* MEMWAIT BITS */
#define MW_ZERO			(0U)
#define MW_ONE			(1U)
#define MW_TWO			(2U)

/* HOCOCR BITS */
#define CR_OPERATE		(0U)
#define CR_STOP			(1U)

/* HOCOCR2 BITS */
#define HOCO_48MHZ		(0x00U)
#define HOCO_64MHZ		(0x01U)
#define HOCO_80MHZ		(0x02U)
#define HOCO_24MHZ		(0x03U)
#define HOCO_32MHZ		(0x04U)
#define HOCO_40MHZ		(0x05U)

/* OSCSF BITS */
#define OSC_STOP		(0U)
#define OSC_STABLE		(1U)

#define HOCOSF_OFF		(0U)
#define MOCOSF_OFF		(3U)
#define PLLSF_OFF		(5U)
#define PLLRTC_OFF		(7U)

/* PRCR BITS */
#define PR_KEY			(0xA5U)
#define WR_DIS			(0U)
#define WR_EN			(1U)

#define PRC0_OFF		(0U)
#define PRC1_OFF		(1U)
#define PRC3_OFF		(3U)
#define PRC4_OFF		(4U)
#define PR_KEY_OFF		(8U)


#define SYST_CSR   		REG32(0xE000E010UL)
#define SYST_RVR   		REG32(0xE000E014UL)
#define SYST_CVR   		REG32(0xE000E018UL)
#define SHPR3      		REG32(0xE000ED20UL)

#define CPU_HZ     		80000000UL

#define IOPORT_BASE		0x4001F000UL
#define IOPORT_PODR(n)		REG16((IOPORT_BASE + (0x0020 * n)) + 0x000)
#define IOPORT_PDR(n)		REG16((IOPORT_BASE + (0x0020 * n)) + 0x002)

#endif /* REGISTERS_H */
