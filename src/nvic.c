#include "nvic.h"
#include "registers.h"

void nvic_init(void)
{
    NVIC_ISER |= (0x1U);
    NVIC_IPR |= (0x2U);
    NVIC_ICPR |= (0x20U);
}