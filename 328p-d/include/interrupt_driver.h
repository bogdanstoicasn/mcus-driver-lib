#ifndef INTERRUPT_DRIVER_H
#define INTERRUPT_DRIVER_H

#include "macros328p.h"

/* Disables/Enables interrupts by setting the global interrupt mask.
 * Returns from interrupt routine, enabling global interrupts.
 */
#define ENABLE_INTERRUPTS() __asm__ __volatile__ ("sei" ::: "memory")
#define DISABLE_INTERRUPTS() __asm__ __volatile__("cli" ::: "memory")
#define RETURN_INTERRUPT() __asm__ __volatile__ ("reti"::: "memory")

#endif
