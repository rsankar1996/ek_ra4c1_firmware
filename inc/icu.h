#ifndef ICU_H
#define ICU_H

typedef enum
{
    IRQ0,
    IRQ1,
    IRQ2,
    IRQ3,
    IRQ4,
    IRQ5,
    IRQ6,
    IRQ7,
    IRQ8,
    IRQ9,
    IRQ10,
    IRQ11,
    IRQ12,
    IRQ13,
    IRQ14,
    IRQ15
} irq_inst_t;

typedef enum
{
    EV_IRQ0 = 0x001,
    EV_IRQ1,
    EV_IRQ2,
    EV_IRQ3,
    EV_IRQ4,
    EV_IRQ5,
    EV_IRQ6,
    EV_IRQ7,
    EV_IRQ8,
    EV_IRQ9,
    EV_IRQ10,
    EV_IRQ11,
    EV_IRQ12,
    EV_IRQ13,
    EV_IRQ14,
    EV_IRQ15
} irq_event_t;

void icu_event_link(uint8_t nvic_idx, irq_inst_t irq);

#endif /* ICU_H */