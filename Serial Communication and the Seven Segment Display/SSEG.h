/**************** Public Functions ****************/
/*
* SSEG_Init Function
* Initialize 7-segment display
* Inputs: none
* Outputs: none
*/
#define BUTTON (*((volatile uint8_t *)0x40004C20)) //Port 3 input
void SSEG_Init();
int getCondValue();
void check_condition(int y);
void SSEG_Out(uint32_t num);
void PORT3_IRQHandler();
void Port3_Init(void);
uint8_t Port3_In(void);
void SSEG_Shift_Out(uint32_t val);
void SSEG_Disp_Num(int x);
void SSEG_Off();