#ifndef REGISTERS_H
#define REGISTERS_H

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

#define IOPORT_BASE	        0x4001F000UL
#define IOPORT_PODR(n)      REG16((IOPORT_BASE + (0x0020 * n)) + 0x000)
#define IOPORT_PDR(n)       REG16((IOPORT_BASE + (0x0020 * n)) + 0x002)

#define PORT_PFSEL_BASE     0x4001F800UL
#define PMN_PFS(m, n)       REG16(PORT_PFSEL_BASE + 0x000U + (0x040 * m) + (0x004 * n))

#define NVIC_ISER           REG32(0xE000E100UL)
#define NVIC_ICER           REG32(0xE000E180UL)
#define NVIC_ISPR           REG32(0xE000E200UL)
#define NVIC_ICPR           REG32(0xE000E280UL)
#define NVIC_IPR            REG8(0xE000E400UL)

#define ICU_BASE            (0x40006000UL)
/* IRQ Control register - n: 0-15 */
#define IRQ_CR(n)           REG8(ICU_BASE + (0x1 * (n)))

#define IRQ_CR_MD_OFF       (0U)
#define IRQ_CR_MD_MSK       (3U)
#define IRQ_EDGE_FALL       (0U)
#define IRQ_EDGE_RISE       (1U)
#define IRQ_EDGE_RANDF      (2U)
#define IRQ_EDGE_LOW_LEV    (3U)

/* ICU Event Link register - n : 0-63 */
#define ICU_EVLINK(n)       REG32(ICU_BASE + 0x300 + (0x4 * n))

#define ICU_IELS_OFF        (0U)
#define ICU_IELS_MSK        (0x1FFU)

/* PMISC: Miscellaneous Port Control. Verify base against the RA4C1 manual */
#define PWPR                REG8(0x4001F800UL + 0x503U)

#define PWPR_PFSWE          (1U << 6)   /* PFS register write enable          */
#define PWPR_B0WI           (1U << 7)   /* PFSWE bit write disable            */

/* Unlock: B0WI must be cleared first, then PFSWE can be set */
#define PFS_WRITE_ENABLE()  do { PWPR = 0x00U;       \
                                  PWPR = PWPR_PFSWE; } while (0)

/* Lock: clear PFSWE first, then set B0WI */
#define PFS_WRITE_DISABLE() do { PWPR = 0x00U;       \
                                  PWPR = PWPR_B0WI;  } while (0)

#endif /* REGISTERS_H */
