#include <stdint.h>
#include "Piano.h"
#include "msp432p401r.h"
void Piano_Init(void){
//Initialize input button pins to port 5
P5SEL0 &= ~0x07; //P5.0-2
P5SEL1 &= ~0x07;
P5DIR &= ~0x07;
}
uint8_t Piano_In(void){
//Return the key code for switches being pressed
return (BUTTON)&0x07;
}