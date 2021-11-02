## Background:

- Most digital music devices rely on high-speed DAC converters to create the analog waveforms required to produce high-quality sound. In this lab, you will create a very simple sound generation system that illustrates this application of the DAC. Your goal is to create an embedded system that plays three notes, representing a digital piano with three keys. The first step is to design and test a 4-bit, binary-weighted DAC; this converts four bits of digital output from the MSP432 to an analog signal. You will convert the four digital bits to an analog output using a simple resistor network. During the static testing phase, you will connect the DAC analog output to a voltmeter or the Visual Analyzer program and measure resolution, range, and precision. 

## DAC Circuit/Specifications:
- Circuit:

![image](https://user-images.githubusercontent.com/35824714/139948986-c2b46236-e99b-4532-9d4a-aa8bd4c1529d.png)
- Specifications:

![image](https://user-images.githubusercontent.com/35824714/139949091-0efad123-04ab-4678-8105-294de09967a0.png)

## Operation of the Circuit:

![image](https://user-images.githubusercontent.com/35824714/139949368-cec21bff-1ca3-49d3-b2df-9e026875547b.png)

## Execution of the System:

![image](https://user-images.githubusercontent.com/35824714/139949500-497d4c78-2fb9-4319-b0f4-8dfccdae1ad8.png)
