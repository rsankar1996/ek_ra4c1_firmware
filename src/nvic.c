#include "nvic.h"

void nvic_init(void)
{
    NVIC_IPR = (0x2U << 4);
    NVIC_ICPR = (0x1U);
    NVIC_ISER |= (0x1U);
}