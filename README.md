# SoftRobotActuator_Pneumatic_Pressure_Control_System
Aim: To control the internal pressure of an inflatable actuator connected to a conventional pneumatic system while utilizing commercially available pneumatic components.

Applications: Soft Robotics

Operation Video: 

https://github.com/user-attachments/assets/58a3f32a-d9d0-425c-8c7c-23615ccb358c

  
Working Process:
  1. The inflation of the Air Cushions is controlled by a by single 2/2 Solenoid Valve connected to a common pressure line, the state of which is controlled by two 2/2 Solenoid Valves.
  2. HX-710B air pressure sensors monitor the internal air pressure of the actuator.
  3. A Graphical User Interface was developed to allow for individual pressure control for each inflatable actuator.
  4. The switching of the solenoid valves is controlled by a algorithm which aims to keep the internal pressure of the inflatable actuator within 20 Pascals of the target pressure.

Tools and Equipment Used: 
  1. Circuit Design: Eagle EDA
  2. Micro-controller: ATmega328 (Arduino Nano)
  3. Micro-controller programming:  Arduino IDE
  4. GUI: Processing programming language
  5. 2/2 Solenoid Valve: CJAV08-2B05A1 2-Position 2-way Small Mini Electric Solenoid Valve
  6. MOSFETs for Valve control circuit: 2N7000A N-Channel MOSFET
  7. Air Pressure Sensor: HX-710B pressure sensor module

Control Algorithm:

  1. Flow-Chart: <img width="1670" height="988" alt="Program Flowchart" src="https://github.com/user-attachments/assets/24c3680c-b2a2-4f70-822a-3962ae80441a" />
  2. Description:
       1. Initialize Ci (count of cells to be inflated) and Cd (count of cells to be deflated) to 0
       2. Receive pressure targets and empty button state from the GUI
       3. If the empty button has been pressed activate the exhaust valve, deactivate the pressure valve and activate cell valves for all cushions and go to step ii, else go to step 4.
       4. Read and process inputs from the sensors
       5. Determine Ci and Cd by comparing the pressure readings from the sensors to the pressure targets given by the GUI.
       6. If the pressure reading for a cushion is less than the pressure target increment Ci. If the pressure reading for a cushion is more than the pressure target increment Ci.
       7. If Ci is greater than 0, activate the pressure valve, deactivate the exhaust valve, activate the cell valve for every cushion that needs to be inflated and go to step 8, else check the value of Cd.
       8. If Cd is greater than 0, deactivate the pressure valve, activate the exhaust valve, activate the cell valve for every cushion that needs to be deflated and go to step 7, else deactivate all valves of the prototype and go to step viii.
       9. Reset Ci and Cd back to 0.
       10. Send the processed readings from the sensors to the GUI so it can display them in the form of graphs and go to step 2.


Pneumatic Circuit: 
  <img width="2827" height="1599" alt="ThirdPrototypeCircuit" src="https://github.com/user-attachments/assets/fa520eb1-e0ee-4ae0-8f65-38376c686d32" />

GUI Screenshot: 
  <img width="874" height="789" alt="image" src="https://github.com/user-attachments/assets/50cdb527-8281-4d82-bb5a-0ba978378ac9" />

Results:
  This prototype for a Pneumatic Pressure control System for inflatable Actuators was able to achieve the following results:
    1. The prototype was able to accurately inflate each actuator to the target internal pressure set by the user through the GUI and maintained it within the margin of error (20 Pascals) until either the target pressure was changed or the prototype was deflated.
    2. The prototype was able to adjust the inflation of the all actuators in response to any load being applied on it to maintain the internal pressure of each cushion at its target pressure within the margin of error (10 Pascals).
    3. Continuously monitor and display the internal pressure of each inflatable actuator in real time on the GUI
  
  <img width="4366" height="215" alt="image" src="https://github.com/user-attachments/assets/ee9c4a9d-72e1-4e6c-99e1-4e9d4d20cb6a" />

  
