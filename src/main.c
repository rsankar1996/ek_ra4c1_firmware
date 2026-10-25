#include <stdint.h>
#include "main.h"
#include "ioport.h"
#include "icu.h"
#include "nvic.h"

extern volatile uint32_t g_tick_count;
extern volatile uint8_t g_irq15_stat;

static void mcu_sleep(uint32_t delay_ms)
{
	uint32_t init = g_tick_count;
	uint32_t curr = g_tick_count;

	while ((curr - init) < delay_ms)
	{
		curr = g_tick_count;
	}
}

int main(void)
{
	IOPORT_SET_OUT(IO_PORT_06, IO_PIN_10);

	PFS_WRITE_ENABLE();
	PMN_PFS(5U, 13U) |= (1U << 14);
	PFS_WRITE_DISABLE();

	nvic_init();
	icu_event_link(0U, IRQ15);

	while (1)
	{
		#if 0
		if (g_irq15_stat > 0U)
		{
			IOPORT_SET_PIN(IO_PORT_06, IO_PIN_10);

			g_irq15_stat = 0;
		}
			#endif
	}

        //while(1);
}
