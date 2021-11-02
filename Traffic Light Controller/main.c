#include <stdint.h>
#include "SysTick.h"
#include "msp432p401r.h"
#define PedLight (*((volatile uint8_t *)0x40004C03))
struct State{
uint32_t Out, Time, out_2;
const struct State *Next[8];
};
typedef const struct State STyp;
//Define States
//Initial States from part 1
#define goS     &FSM[0]
#define waitS   &FSM[1]
#define goW     &FSM[2]
#define waitW   &FSM[3]
#define wait    &FSM[4]
#define cmpS    &FSM[5] //check to see if walk on south is pressed
#define cmpW    &FSM[6] //check to see if walk on wesy is pressed
#define wlk     &FSM[7]
//Initiate Hurry States (H1 - H6)
#define H1      &FSM[8]
#define H2      &FSM[9]
#define H3      &FSM[10]
#define H4      &FSM[11]
#define H5      &FSM[12]
#define H6      &FSM[13]
#define stop    &FSM[14] //End hurry and initiate next state
STyp FSM[15] = {
// Out | Delay  | LED | State machine from 000 to 111
{0x0C, 100, 0x01, {goS, goS, waitS, waitS, cmpS, cmpS, cmpS, cmpS}}, //goS
{0x0A, 100, 0x01, {wait, wait, goW, goW, wait, wait, wait, wait}}, //waitS
{0x21, 100, 0x01, {goW, waitW, goW, waitW, cmpW, cmpW, cmpW, cmpW}}, //goW
{0x11, 100, 0x01, {wait, goS, wait, goS, wait, wait, wait, wait}}, //waitW
{0x09, 100, 0x01, {goS, goS, goW, goS, wlk, wlk, wlk, wlk}}, //wait
{0x0C, 200, 0x01, {goS, goS, waitS, waitW, wlk, wlk, wlk, wlk}}, //cmpS
{0x21, 200, 0x01, {goW, waitW, goW, waitS, wlk, wlk, wlk, wlk}}, //cmpW
//Initiate Walk/Hurry sequence
{0x09, 300, 0x02, {H1, H1, H1, H1, H1, H1, H1, H1}}, //Walk (LED = Green)
{0x09, 50, 0x01, {H2, H2, H2, H2, H2, H2, H2, H2}},  //H1 (LED = RED), LED toggles
for rest of the Hurry States
{0x09, 50, 0x00, {H3, H3, H3, H3, H3, H3, H3, H3}},  //H2
{0x09, 50, 0x01, {H4, H4, H4, H4, H4, H4, H4, H4}},  //H3
{0x09, 50, 0x00, {H5, H5, H5, H5, H5, H5, H5, H5}},  //H4
{0x09, 50, 0x01, {H6, H6, H6, H6, H6, H6, H6, H6}},  //H5
{0x09, 50, 0x00, {stop, stop, stop, stop, stop, stop, stop, stop}}, //H6
{0x09, 100, 0x01, {goS, goS, goW, goW, wlk, goS, goW, goS}}, //Stop move to next state
};
void main(void){
STyp *Pt; //State pointer
uint32_t Input;

//Initialize ports(2(LED), 4(Output), 5(Input) and timer(Systick)
P2SEL0 &= ~0x03;
P2SEL1 &= ~0x03;
P4SEL0 &= ~0x3F;
P4SEL1 &= ~0x3F;
P5SEL0 &= ~0x07;
P5SEL1 &= ~0x07;
P2DIR |= 0x03;
P4DIR |= 0x3F;
P5DIR &= 0x07;
SysTick_Init();
Pt = goS; //Start State
while(1){
P4->OUT = (Pt->Out)&0x3F; // Set LED out
PedLight = (PedLight)&~0x03 | (Pt->out_2); //Pedestrian light
SysTick_Wait10ms(Pt->Time); //Calling systick timer for specified wait time
Input = (P5->IN)&0x07; //Read sensors (Input)
Pt = Pt->Next[Input]; //Next state and repeat the process
}
}