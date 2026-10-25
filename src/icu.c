#include <stdint.h>
#include "icu.h"
#include "registers.h"

void icu_event_link(uint8_t nvic_idx, irq_inst_t irq)
{
    ICU_EVLINK(nvic_idx) = (ICU_EVLINK(nvic_idx) & ~ICU_IELS_MSK) |
                           (uint32_t)(EV_IRQ0 + irq);
    IRQ_CR(irq) &= ~(IRQ_CR_MD_MSK);
    IRQ_CR(irq) |= (IRQ_EDGE_FALL << IRQ_CR_MD_OFF);
}