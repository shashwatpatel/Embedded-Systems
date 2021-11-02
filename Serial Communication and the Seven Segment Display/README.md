## Seven Segment Display:
- There are a total of 34 LEDs as shown in the figure below, however, there are only 14 pins. The circuit diagram shows five common cathodes. In addition, the anodes of the same LEDs are connected together. So, if you connect all the LED pins to VDD and common pins to ground, you will turn all LEDs of all four digits. By switching between the four common cathodes we can choose which display to turn on, however, we cannot display four different digits at the same time in this display as anodes are the same for all four digits.
![image](https://user-images.githubusercontent.com/35824714/139951520-c4775c8c-39cc-4970-ba11-0e7bdf1fdf10.png)


## Time Multiplexing:
- Multiplexed displays only show one digit at a time, but by cycling through all digits repetitively and cycling very fast, a multi-digit display is perceived. To drive a particular digit, its common cathode is connected to common ground and the LEDs are driven as needed for the desired number in that position. Cycling through the digits must be done quick enough for your eye to not see flickering LEDs; this is accomplished through the system's software

## Shift Register:
- We will use the 74HC595N IC. This IC is a shift register and it converts serial data to parallel data to reduce the number of digital I/O pins required to control the seven-segment display. Please refer to our lecture on the seven-segment display for more information about this shift register.
![image](https://user-images.githubusercontent.com/35824714/139951653-b61aaf31-accf-4a6a-aaf7-de6e84eefe6d.png)

## Circuit Design:
![image](https://user-images.githubusercontent.com/35824714/139951744-475b50ae-f1e0-42cf-936d-2523534f6584.png)
