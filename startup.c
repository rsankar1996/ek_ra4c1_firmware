#include <stdint.h>

extern uint32_t _estack, _sidata, _sdata, _edata, _sbss, _ebss;

int main(void);

void Default_Handler(void) { while (1) {} }

/* Weak aliases: override any of these by defining a function with the same name */
void NMI_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SecureFault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)     __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)    __attribute__((weak, alias("Default_Handler")));

void Reset_Handler(void)
{
        uint32_t *src = &_sidata;
        uint32_t *dst = &_sdata;

        while (dst < &_edata)
        {
                *dst++ = *src++;
        }

        for (dst = &_sbss; dst < &_ebss; )
        {
                *dst++ = 0;
        }

        main();

        while (1) 
        {
                /* Nothing to do here */
        }
}

__attribute__((section(".vectors"), used))
void (* const vector_table[])(void) = {
        (void (*)(void))&_estack,   /* 0: initial stack pointer */
        Reset_Handler,              /* 1: reset */
        NMI_Handler,                /* 2 */
        HardFault_Handler,          /* 3 */
        MemManage_Handler,          /* 4 */
        BusFault_Handler,           /* 5 */
        UsageFault_Handler,         /* 6 */
        SecureFault_Handler,        /* 7 (Cortex-M33) */
        0, 
        0, 
        0,                    /* 8-10 reserved */
        SVC_Handler,                /* 11 */
        0,                          /* 12 debug monitor */
        0,                          /* 13 reserved */
        PendSV_Handler,             /* 14 */
        SysTick_Handler,            /* 15 */
        /* Peripheral IRQs (16+) go here once you use interrupts */
};
