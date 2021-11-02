## Background:

Consider a traffic intersection. There are two one-way streets labeled South (cars travel South) and West (cars travel West). There are two inputs (buttons), representing car sensors, to MSP432. The South sensor will be true (1) if one or more cars are at the intersection on the South road. Similarly, the West sensor will be true (1) if one or more cars are at the intersection on the West road. We will use six outputs from your microcontroller to control the traffic lights. 
now add functionality to include a "walk" light. The "walk" button will be pushed by a pedestrian when he or she wishes to cross in any direction. To request a walk, a pedestrian must push and hold the "walk" button for at least two seconds, after which the person can release the button, and the walk request will be remembered. In contrast, when a car sensor is released, it means no cars are waiting to enter the intersection. You will use eight outputs from your microcontroller that control the traffic lights, the "walk" light, and the "don't walk" light. When the "walk" light is on, pedestrians are allowed to cross in any direction across the road. When the "don't walk" light starts to flash (and the two traffic signals are red), pedestrians should hurry up and finish crossing in any direction. When the "don't walk" light stays on, pedestrians should not enter the intersection.

## System Requirements:

- Traffic should not be allowed to crash; i.e., traffic lights at the intersection should be red, or there should only be one green or yellow light active at the intersection
- You should exercise common sense when assigning the length of time that the traffic light will spend in each state so that the system changes at a speed convenient for the you to test and for the instructor to see during the demonstration; e.g., lights change fast enough so the instructor doesn't have to wait a long time, but not so fast that the instructor can't see what is happening
- Cars should not be allowed to hit pedestrians. The walk sequence should be realistic, showing three separate conditions: (1) "walk", (2) "hurry up" using a flashing LED, and (3) "don't walk".
- You may assume the two car sensors remain active for as long as service is required, however, a request for walk is signified by a push and release, where the walk button is pushed for at least two seconds

## Details to Note:
- The system provides for input dependence. This means each state has eight arrows/transitions so that the next state depends on the current state and the input. This means you cannot solve the problem by simply cycling through all the states regardless of the input. This also means you should not implement a Mealy machine.
- There must be a one-to-one mapping between the state graph and the data structure. For a Moore machine, this means each state in the graph has a name, an output, a time to wait, and eight next state arrows/transitions (one for each input combination). The data structure has exactly these components: a name, an output, a time to wait, and eight next-state pointers (one for each input combination). The data structure has the same amount of information as the state graph.
- You do not need to use conditional branches (do-while, while-loop, if-then, or for-loops) in your system, other than in SysTick_Wait and in SysTick_Wait10ms. See the Example 4.4 in the textbook; you will have an unconditional while-loop in the main program that runs the FSM controller.
- The state graph defines exactly what the system does in a clear and unambiguous manner
- Each state has the same, uniform format. This means every state has exactly one name, one eight-bit output, one time to wait, and eight next-state pointers.
- Do not allow cars to crash into each other. Do not allow pedestrians to walk while any cars are allowed to go. Engineers do not want people to get hurt.
- There should be about 15 to 30 states when using a Moore FSM for this system. What if you have less than 15 states? Usually students with less than 15 states did not flash the "don't walk" light, or they flashed the lights using a counter; counters and variables violate the "no conditional branch" requirement. If you have less than 15 states, you may not have handled the two second walk button recognition.
- If the pedestrian pushes the walk button for two or more seconds, eventually a walk light must occur. If the pedestrian pushed the walk button for less than two seconds, it is acceptable for you to choose to either generate or not generate a walk signal.

## FSM 
![image](https://user-images.githubusercontent.com/35824714/139947808-376f0286-894d-46b4-a584-4915f2b0ff1f.png)
![image](https://user-images.githubusercontent.com/35824714/139947864-64b05460-d6e7-4b6f-87df-59e98ec7a797.png)
