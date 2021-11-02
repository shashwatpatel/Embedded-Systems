#include "msp432p401r.h"
#include "SSEG.h"
#include <stdio.h>
#include <stdbool.h>
void main() {
SysTick_Init();
SSEG_Init();
Port3_Init();
int number;
bool check = false;
while(!check){
printf("\nEnter an integer between 0 - 9999: ");
scanf("%d", &number);
if (number > 9999){
printf("Error \n");
}
else{
check = true;
check_condition(number);
}
}
while(1){
SSEG_Disp_Num(getCondValue());
}
}