// SysTick.h
// Runs on MSP432
// Provide functions that initialize the SysTick module, wait at least a
// designated number of clock cycles, and wait approximately a multiple
// of 10 milliseconds using busy wait.  After a power-on-reset, the
// MSP432 gets its clock from the internal digitally controlled
// oscillator, which is set to 3 MHz by default.  One distinct advantage
// of the MSP432 is that it has low-power clock options to reduce power
// consumption by reducing clock frequency.  This matters for the
// function SysTick_Wait10ms(), which will wait longer than 10 ms if the
// clock is slower.


// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void);

// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 333 nsec for 3 MHz clock)
void SysTick_Wait(uint32_t delay);

// Time delay using busy wait.
// This assumes 3 MHz system clock.
void SysTick_Wait10ms(uint32_t delay);
