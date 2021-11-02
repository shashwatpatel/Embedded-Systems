#include <stdint.h>
#include "msp432p401r.h"
#include "Sound.h"
#include "Piano.h"
#include "DAC.h"
#include "SysTickInts.h"
//Call the Switch, Systick and Speaker hardware
//Play the 3 note piano based on the button pressed
void main(void){
Sound_Init(0);
Piano_Init();
while(1){
Sound_Play();
}
}