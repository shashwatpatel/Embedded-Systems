#include <stdint.h>
#include "SysTickInts.h"
#include "LCD.h"
#include "msp432p401r.h"
#define T1ms 1000*3   // 1ms (Added from part 1 for delay between each command)
int Convert_Val(int sample){
//Conversion of 0-16383 to 2000 or 2cm
//Formula:
//Sample = (Sample*1000)/8191
return sample/8.191;
}
void main() {
//25ms = 25000*3Mhz = 75000
SysTick_Init(75000);
ADC0_InitSWTriggerCh0();
LCD_Init();
EnableInterrupts();
//Init port 1 for heartbeat toggle
P1SEL0 &= ~0x01;
P1SEL1 &= ~0x01;
P1DIR |= 0x01;
LCD_OutString("Lab5 Pt 2 Demo");
SysTick_Wait(T1ms);      // Wait 1ms
while(1){
if(ADC_Status() == 1){
uint32_t sample = SysTick_Mailbox(); //Save the date onto mailbox
LCD_OutCmd(0xC0);
SysTick_Wait(T1ms);      // Wait 1ms
LCD_OutUFix(Convert_Val(sample)); //Display converted value using fixed point
LCD_OutString(" cm");
}
}
}