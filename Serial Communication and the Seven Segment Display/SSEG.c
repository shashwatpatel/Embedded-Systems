#include <stdint.h>
#include "SysTick.h"
#include "msp432p401r.h"
#include "SSEG.h"
// Global Variables
//int ctr=9999;
uint32_t cond_val=9999;
void DisableInterrupts(); // Disable interrupts
void EnableInterrupts(); // Enable interrupts
long StartCritical (); // previous I bit, disable interrupts
void EndCritical(long sr); // restore I bit to previous value
void WaitForInterrupt(); // low power mode
//RCLK pulse
void RCLK(void){
P5OUT |= 0x2;
P5OUT &= ~0x2;
}
//Shift reg clk pulse
void SRCLK(void){
P5OUT |= 0x1;
P5OUT &= ~0x1;
}
/*
* SSEG_Init Function
* Initialize 7-segment display
* Inputs: none
* Outputs: none
*/
void Port3_Init(void){
//Button Init (Input)
DisableInterrupts();
P3SEL0 &= ~0x5; //101 Couldnt find P3.1 on microcontroller
P3SEL1 &= ~0x5;
P3DIR  &= ~0x5;
//IRQ handler
//*****Courtesy of Lecture 9*******
P3IES  &= ~0x5;
P3IFG  &= ~0x5;
P3IE |= 0x05;
NVIC->IP[9] = (NVIC->IP[9]%0xFFFF00FF)|0x00004000;
NVIC->ISER[1] = 0x00000020; //For Port 3
EnableInterrupts();
}
uint8_t Port3_In(void){
//Button input
return (BUTTON)&0x05;
}
void SSEG_Init() {
//Seven seg LED Init (Output)
P4SEL0  &= ~0x0F;
P4SEL1  &= ~0x0F;
P4DIR   |= 0x0F;
P4->OUT = 0x0F;
P5SEL0  &= ~0x07;
P5SEL1  &= ~0x07;
P5DIR   |= 0x07;
}
/*
* SSEG_Out Function
* Output a number to a single digit of the 7-segment display
* Inputs:
* Outputs: none
*/
void SSEG_Out(uint32_t num) {
int placeholder = 0;
switch(num){
case 0:
placeholder = 11111100;
break;
case 1:
placeholder = 1100000;
break;
case 2:
placeholder = 11011010;
break;
case 3:
placeholder = 11110010;
break;
case 4:
placeholder = 1100110;
break;
case 5:
placeholder = 10110110;
break;
case 6:
placeholder = 10111110;
break;
case 7:
placeholder = 11100000;
break;
case 8:
placeholder = 11111110;
break;
case 9:
placeholder = 11110110;
break;
}
SSEG_Shift_Out(placeholder);
}
/*
* SSEG_Shift_Out Function
* Shifts data out serially
* Inputs: 8-bit data
* Outputs: none
*/
void SSEG_Shift_Out(uint32_t val){
P5->OUT &= 0x04; //Initial state
for(int i = 0; i <= 7; i++){
if((val % 10) == 1){
P5->OUT &= ~0x04;
}
else{
P5->OUT |= 0x04;
}
SRCLK(); //Call the shift register clock
val /=10; //Shift to the next bit
}
RCLK(); //Call the pulse latch clock
}
//Check condition in order to function IRQ's increment and decrement
void check_condition(int y){break;
case 6:
placeholder = 10111110;
break;
case 7:
placeholder = 11100000;
break;
case 8:
placeholder = 11111110;
break;
case 9:
placeholder = 11110110;
break;
}
SSEG_Shift_Out(placeholder);
}
/*
* SSEG_Shift_Out Function
* Shifts data out serially
* Inputs: 8-bit data
* Outputs: none
*/
void SSEG_Shift_Out(uint32_t val){
P5->OUT &= 0x04; //Initial state
for(int i = 0; i <= 7; i++){
if((val % 10) == 1){
P5->OUT &= ~0x04;
}
else{
P5->OUT |= 0x04;
}
SRCLK(); //Call the shift register clock
val /=10; //Shift to the next bit
}
RCLK(); //Call the pulse latch clock
}
//Check condition in order to function IRQ's increment and decrement
void check_condition(int y){
if(y > 9999){
y = 0;
}
else if (y < 0){
y = 9999;
}
cond_val = y;
}
//Getters and setters logic
int getCondValue(){
return cond_val;
}
/*
* Port 5 ISR
* Uses P5IV to solve critical section/race
*/
void PORT3_IRQHandler() {
//This function takes buttons as inputs
//If Button 1 is pressed then value gets decremented
//If Button 2 is pressed then value gets incremented
DisableInterrupts();
SysTick_Wait(3000);
switch(Port3_In()){
case 1:
check_condition(getCondValue()+1); //Increment if button 1 is pressed
break;
case 4:
check_condition(getCondValue()-1); //Decrement if other
break;
}
SSEG_Disp_Num(getCondValue()); //Update the display with new value
SysTick_Wait(20000);
P3IFG  &= ~0x5; //Clear flag
EnableInterrupts();
}
/*
* SSEG_Disp_Num Function
* Separate the input number into 4 single digit
* Inputs: num between 0 and 9999
* Outputs: none
*/
void SSEG_Disp_Num(int x){
uint32_t newVar;
//Loops through 4 digits of sseg
for(int i = 0; i< 4; i++){
SSEG_Off(); //initial condition
SSEG_Out(x%10);
newVar = 3-i;
switch (newVar) {
//Activates the cathode related to its case
case 0:
P4OUT = 0x01;
break;
case 1:
P4OUT = 0x02;
break;
case 2:
P4OUT = 0x04;
break;
case 3:
P4OUT = 0x08;
break;
}
x/=10;
SysTick_Wait(10000);
}
}
/*
* SSEG_Off Function
* Turns off all 7-seg digits
* Inputs: none
* Outputs: none
*/
void SSEG_Off(){
P4->OUT = ~0x0F; //or just set to 0x00
}