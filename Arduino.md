# Vibration sensor with lights

### Introduction
This experiment will show you how to use a vibration sensor with your Arduino board to trigger other components. If the vibration sensor detects any vibration a LED light will turn on, stay turned on for a while then turn itself off. This example will also show how to print a message to the serial monitor when the vibration sensor is triggered, giving you a timestamp for when the trigger happened.

This can be useful if you want something to happen without pressing a button or interacting with the board or a component directly. The vibration sensor only detects vibrations that affect the sensor itself, making its range rather small. This can be expanded upon by attaching the sensor to another surface, making the range on the sensor greater.

### Components for this tutorial:
1. Arduino board
2. Generic wires
3. Breadboard
4. Led light
5. 220 ohm resistor
6. Vibration sensor

### Assembly
First let's go through how to connect everything.

![Vibration sensor](img/VibSensorimg.png)

As you can see on the above image the vibration sensor needs three wires connected to the board.

One that connects to ground (GND).

One that connects to power, 5v in this case.

The last wire will be connected to a numbered pin, in this example we will use pin 10. This can be changed freely as long as the code is changed correctly to match the connected pin. The numbered pin will tell us which pin to listen to in the code to get a reading from the component.

![LED light](img/LEDlight.png)

The light will similarly be connected to a pin slot to let us know where to send values to the light in the code.

The long leg (positive leg) should be connected to pin 13 through a resistor. The pin that you connect the long leg to can be changed, it does not have to be connected to pin 13, if you do decide to change the pin then also change the ledPin variable in the code.

Then connect the short leg (negative leg) of the LED to ground (GND).

![Complete board](img/ArduinoBoard.png)

Connecting it all to a breadboard could look something like this.

You can wire ground into a row, as shown on the picture, for easier access to it from the rest of the board.

### The code
![Code img](img/FullCode.png)
[Link to the code](https://create.arduino.cc/editor/BenjaminD/4699d7c2-6dfc-4504-aba7-bfad5d94bc89/preview)

In the Arduino code editor make sure that you have the right board and port selected. These options can be found under the "tools" tab, as seen in the picture below.

![Settings instructions](img/Instructions.png)

### Conclusion
With this example we now know how to trigger a component or the arduino board by using a sensor that detects vibrations. You now also know how to connect multiple components to an Arduino board with a breadboard. In the code we have also seen how to loop code so that the components reaction will be more noticeable, and how to use certain loops to help us reduce the number of results that are printed in the serial monitor. This is valuable to know for when more components are added and you need to troubleshoot actions and reactions with the arduino board.
