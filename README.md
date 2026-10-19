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

Control Algorithm flowchart: 
  <img width="1670" height="988" alt="Program Flowchart" src="https://github.com/user-attachments/assets/24c3680c-b2a2-4f70-822a-3962ae80441a" />

Pneumatic Circuit: 
  <img width="2827" height="1599" alt="ThirdPrototypeCircuit" src="https://github.com/user-attachments/assets/fa520eb1-e0ee-4ae0-8f65-38376c686d32" />

GUI Screenshot: 
  <img width="874" height="789" alt="image" src="https://github.com/user-attachments/assets/50cdb527-8281-4d82-bb5a-0ba978378ac9" />

  
