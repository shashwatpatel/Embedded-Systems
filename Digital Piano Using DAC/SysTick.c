#include <stdint.h>
#include "Sound.h"
#include "msp432p401r.h"
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode
// **************SysTick_Init*********************
// Initialize SysTick periodic interrupts
// Input: interrupt period
//        Units of period are 333ns (assuming 3 MHz clock)
//        Maximum is 2^24-1
//        Minimum is determined by length of ISR
// Output: none
volatile uint32_t Counts;
void SysTick_Init(uint32_t period) {
long sr = StartCritical();
Counts = 0;
SysTick->CTRL = 0;                   // disable SysTick during setup
SysTick->LOAD = period - 1;          // maximum reload value
SysTick->VAL = 0;                    // any write to current clears it
SCB->SHP[3] = (SCB->SHP[3]&0x00FFFFFF)|0x40000000; // priority 2
SysTick->CTRL = 0x00000007;          // enable SysTick with no interrupts
EndCritical(sr);
}
//Define sine table
const uint8_t wave[32]= {8,9,11,12,13,14,14,15,15,15,14,14,13,12,11,9,8,7,5,4,3,2,
2,1,1,1,2,2,3,4,5,7};
int index = 0;
void SysTick_Handler(void){
//If wave index > 31 then set index to 0
if(index > 31){
index = 0;
}
DAC_Out(wave[index]);
index++;
}