#include <stdint.h>
//Function that will call the DAC and enable systick interrupt
void Sound_Init(uint32_t note);
//Function that will play note based on the value provided
void Sound_Play(void);