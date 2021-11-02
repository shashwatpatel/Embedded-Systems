#include <stdint.h>
#include "DAC.h"
#include "msp432p401r.h"
void DAC_Init(void){
//4bit = 4 pins
P4SEL0 &= ~0x0F; //P4.0-3
P4SEL1 &= ~0x0F;
P4DIR |= 0x0F;
}
void DAC_Out(uint32_t data){
//Sends new data value to the DAC
DAC_OUT = (data)&0x0F;
}