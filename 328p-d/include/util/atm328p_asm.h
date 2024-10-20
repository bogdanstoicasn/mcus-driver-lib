#ifndef ATM_328P_ASM_H
#define ATM_328P_ASM_H

/* Disables/Enables interrupts by setting the global interrupt mask.
 * Returns from interrupt routine, enabling global interrupts.
 */
#define ENABLE_INTERRUPTS() __asm__ __volatile__ ("sei" ::: "memory")
#define DISABLE_INTERRUPTS() __asm__ __volatile__("cli" ::: "memory")
#define RETURN_INTERRUPT() __asm__ __volatile__ ("reti"::: "memory")

#define WDT_RESET() __asm__ __volatile__ ("wdr")

#endif
