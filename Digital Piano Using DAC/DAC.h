#include <stdint.h>
#define DAC_OUT (*((volatile uint8_t *)0x40004C23)) //Port 4 Out
//Initialize DAC (4 bit in this case)
void DAC_Init(void);
//This function will read 4 bit data and output it to DAC
void DAC_Out(uint32_t data);