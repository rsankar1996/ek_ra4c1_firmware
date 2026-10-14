#include <stdint.h>

#define PORT_BASE(n)		(0x4001F000 + (0x0020 * n))
#define PODR(n)			((PORT_BASE(n) + 0x000))
#define PDR(n)				((PORT_BASE(n) + 0x002))

int main(void)
{
	uint16_t * podr = (uint16_t*)PODR(6);
	uint16_t * pdr = (uint16_t*)PDR(6);

	*podr |= (1 << 10);
	*pdr |= (1 << 10);

        while(1);
}
