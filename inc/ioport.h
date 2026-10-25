#ifndef IOPORT_H
#define IOPORT_H

#include <stdint.h>
#include "registers.h"

typedef enum
{
	IO_PORT_00,
	IO_PORT_01,
	IO_PORT_02,
	IO_PORT_03,
	IO_PORT_04,
	IO_PORT_05,
	IO_PORT_06,
	IO_PORT_07,
	IO_PORT_08
} ioport_port_t;

typedef enum
{
	IO_PIN_00,
	IO_PIN_01,
	IO_PIN_02,
	IO_PIN_03,
	IO_PIN_04,
	IO_PIN_05,
	IO_PIN_06,
	IO_PIN_07,
	IO_PIN_08,
	IO_PIN_09,
	IO_PIN_10,
	IO_PIN_11,
	IO_PIN_12,
	IO_PIN_13,
	IO_PIN_14,
	IO_PIN_15
} ioport_pin_t;

#define IOPORT_SET_OUT(port, pin)	(IOPORT_PDR(port) |= (1 << pin))
#define IOPORT_SET_IN(port, pin)	(IOPORT_PDR(port) &= ~(1 << pin))
#define IOPORT_SET_PIN(port, pin)	(IOPORT_PODR(port) |= (1 << pin))
#define IOPORT_RESET_PIN(port, pin)	(IOPORT_PODR(port) &= ~(1 << pin))
#define IOPORT_TOGGLE_PIN(port, pin)	(IOPORT_PODR(port) ^= (1 << pin))

#endif /* IOPORT_H */
