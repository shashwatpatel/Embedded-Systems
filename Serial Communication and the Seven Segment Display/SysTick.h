// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init();

// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 333 nsec for 3 MHz clock)
void SysTick_Wait(uint32_t delay);

// Time delay using busy wait.
// This assumes 3 MHz system clock.
void SysTick_Wait10ms(uint32_t delay);
