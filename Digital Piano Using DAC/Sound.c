#include <stdint.h>
#include "DAC.h"
#include "Piano.h"
#include "Sound.h"
#include "SysTickInts.h"
#include "msp432p401r.h"
//This function calculates ticks for each note
//3MHz/Frequency(note)/32    (Formula from side 30 DAC)
int ticks(note){
return 3000000/note/32;
}
void Sound_Init(uint32_t note){
//Initialize data structure
//Call DAC and Systick
DAC_Init();
SysTick_Init(note);
EnableInterrupts();
}
void Sound_Play(void){
//Use case statements to play notes
//Enable interrupts each time button is pressed for a particular note
//Disable interrupts for default case
//Write the value to SysTick Load when playing a new note
switch(Piano_In()){
case 0x01:
EnableInterrupts();
SysTick->LOAD = ticks(392); //Note G
break;
case 0x02:
EnableInterrupts();
SysTick->LOAD = ticks(349); //Note F
break;
case 0x04:
EnableInterrupts();
SysTick->LOAD = ticks(294); //Note D
break;
default:
DisableInterrupts();
}
}