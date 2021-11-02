#include <stdint.h>
#define BUTTON (*((volatile uint8_t *)0x40004C40)) //Port 5 input
//Initialize Port 5 pins for buttons
void Piano_Init(void);
//Returns the key code based on the input
uint8_t Piano_In(void);