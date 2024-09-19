Project Overview
This multi-functional bot is designed to participate in four different competitions: tug of war, robo soccer, sumo war, and racing. It is equipped with essential components to ensure optimal performance in terms of speed, strength, and stability, adaptable to the requirements of each event. The bot is controlled using an ESP8266 microcontroller, providing seamless operation for all competitions.

Components Used:

  DC Motors (4)
    200 RPM Single Shaft BO Motor Straight

  Motor Driver (1)
    L298N Motor Driver

  Buck Converter (1)
    LM2596HVS DC-DC Buck Converter

  Microcontroller (1)
    ESP8266

  Wheels (4)
    7x2 DC Gear Motor Wheels
    BO wheels, diameter: 65mm, thickness: 26mm

  Breadboard (1)

  Batteries (1)
    12V Rechargeable Battery
    (Sufficient to power the motors and ESP8266)

  Jumper Wires
  For circuit connections between the components

Features

Tug of War: High torque output with 200 RPM motors for maximum pulling power.
Robo Soccer: Agile movement and control for precise navigation on the field.
Sumo War: Sturdy design with balanced weight distribution for better grip and pushing force.
Racing: Optimized speed and wheel traction to ensure fast, smooth performance on straight tracks.


Setup Instructions

Assemble the Motors: Connect the 4 BO motors to the wheels and secure them to the bot frame.
Wire the Motors: Use jumper wires to connect the motors to the L298N motor driver.
Connect the Motor Driver: Attach the motor driver to the ESP8266 to enable motor control.
Power Setup: Connect the LM2596HVS buck converter to step down the voltage from the battery for the ESP8266 and other components.
Breadboard: Use the breadboard to manage wiring connections for the motor driver, ESP8266, and power supply.
Control: Program the ESP8266 to handle the different functions for each competition.


How to Use
Control the Bot: The ESP8266 can be programmed to switch between different modes (tug of war, robo soccer, sumo, and racing) using a remote or predefined command sets.
Adjust Speed: Use the motor driver to control the speed and direction of the bot for various competitions.


Future Enhancements
Add sensors for autonomous control in the Robo Soccer competition.
Improve battery management for longer-lasting power during tug of war and sumo competitions.
