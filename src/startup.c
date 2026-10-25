#include <stdint.h>
#include "init.h"
#include "main.h"
#include "nvic.h"

extern uint32_t _estack, _sidata, _sdata, _edata, _sbss, _ebss;

void Default_Handler(void) 
{ 
	while (1);
}

void NMI_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)  __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)   __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SecureFault_Handler(void)__attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)        __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)     __attribute__((weak, alias("Default_Handler")));

volatile uint32_t g_tick_count;
volatile uint8_t g_irq15_stat;

void SysTick_Handler(void)
{
	g_tick_count++;
}

void Reset_Handler(void)
{
        uint32_t *src = &_sidata;
        uint32_t *dst = &_sdata;

	clock_init();

        while (dst < &_edata)
        {
                *dst++ = *src++;
        }

        for (dst = &_sbss; dst < &_ebss; )
        {
                *dst++ = 0;
        }

	systick_init();

        nvic_init();

        main();

        while (1); 
}

void IRQ15_Handler(void)
{
        /* Implementation pending */
        g_irq15_stat++;
}

__attribute__((section(".vectors"), used))
void (* const vector_table[])(void) = {
        (void (*)(void))&_estack,
        Reset_Handler,
        NMI_Handler,
        HardFault_Handler,
        MemManage_Handler,
        BusFault_Handler,
        UsageFault_Handler,
        SecureFault_Handler,
        0, 
        0, 
        0,
        SVC_Handler,
        0,
        0,
        PendSV_Handler,
        SysTick_Handler,
        /* Peripheral IRQs */
        IRQ15_Handler,
};
