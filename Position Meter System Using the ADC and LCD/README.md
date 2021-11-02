## Background
- In this part of the lab, you will interface a 16x2 character LCD to the MSP432 using a Hitachi HD44780 LCD controller (Links to an external site.) shown in the figure below. This part of the lab will primarily use "blind-cycle transfer" synchronization, which means before the software issues an output command to the LCD, it will wait a significant amount of time for the display to be ready
- Design a position meter. The software will use the 14-bit ADC built into the microcontroller. A linear slide potentiometer (Bourns PTA2043-2015DPB103) converts position into resistance (0 ≤ R ≤ 10 kΩ). The full scale range of position may be anywhere from 1.5 to 2 cm; adjust this distance to match the size of the potentiometer you are using. You will use an electrical circuit to convert resistance into voltage (Vin). Since the potentiometer has three leads, one possible solution is shown in the figure below. Add a RI resistor in the circuit so the input to the ADC ranges from 0 to 2.5 V. You may use any ADC channel. The MSP432 ADC will convert voltage into a 14-bit digital number (0 to 16383). This ADC is a successive approximation device with a conversion time on the order of several microseconds. Your software will calculate position from the ADC sample as a decimal fixed-point number (resolution of 0.001 cm). The position measurements will be displayed on the LCD using the LCD device driver 

## Data Flow of the System:

![image](https://user-images.githubusercontent.com/35824714/139950377-b315d218-7fbd-40e9-998a-af052b703fba.png)

## Execution of the System:

![image](https://user-images.githubusercontent.com/35824714/139950460-2a825177-50d0-446c-99e5-67c64a96cff6.png)
