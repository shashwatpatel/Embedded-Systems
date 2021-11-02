#include <stdint.h>
#include "msp432p401r.h"

// Initialize SysTick with busy wait running at bus clock.
void SysTick_Init(void){
	SysTick->CTRL = 0;                    // disable SysTick during setup
	SysTick->LOAD = 0x00FFFFFF;           // maximum reload value
	SysTick->VAL = 0;                    // any write to current clears it
	SysTick->CTRL = 0x00000005;           // enable SysTick with no interrupts
}
// Time delay using busy wait.
// The delay parameter is in units of the core clock. (units of 333 nsec for 3 MHz clock)
void SysTick_Wait(uint32_t delay){
  // method #1: set Reload Value Register, clear Current Value Register, poll COUNTFLAG in Control and Status Register
  if(delay <= 1){
    // without this step:
    // if delay == 0, this function will wait 0x00FFFFFF cycles
    // if delay == 1, this function will never return (because COUNTFLAG is set on 1->0 transition)
    return;                   // do nothing; at least 1 cycle has already passed anyway
  }
  SysTick->LOAD = (delay - 1);// count down to zero
  SysTick->VAL = 0;          // any write to CVR clears it and COUNTFLAG in CSR
  while((SysTick->CTRL&0x00010000) == 0){};
  // method #2: repeatedly evaluate elapsed time
/*  volatile uint32_t elapsedTime;
  uint32_t startTime = SysTick->VAL;
  do{
    elapsedTime = (startTime-SysTick->VAL)&0x00FFFFFF;
  }
  while(elapsedTime <= delay);*/
}
// Time delay using busy wait.
// This assumes 3 MHz system clock.
void SysTick_Wait10ms(uint32_t delay){
  uint32_t i;
  for(i=0; i<delay; i++){
    SysTick_Wait(30000);  // wait 10ms (assumes 3 MHz clock)
  }
}