#include <stdint.h>
#include "icu.h"
#include "registers.h"

void icu_event_link(uint8_t nvic_idx, irq_inst_t irq)
{
    ICU_EVLINK(nvic_idx) |= (EV_IRQ15);
    IRQ_CR(irq) &= ~(IRQ_CR_MD_MSK);
    IRQ_CR(irq) |= (IRQ_EDGE_FALL << IRQ_CR_MD_OFF);
}