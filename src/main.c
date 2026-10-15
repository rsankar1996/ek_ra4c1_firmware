#include <stdint.h>
#include "main.h"
#include "ioport.h"

extern volatile uint32_t g_tick_count;

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

	while (1)
	{
		IOPORT_TOGGLE_PIN(IO_PORT_06, IO_PIN_10);

		mcu_sleep(1000);
	}

        while(1);
}
