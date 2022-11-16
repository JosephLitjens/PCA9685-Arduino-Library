# PCA9685-Arduino-Library
This is an Arduino library that can be used to control servos via the PCA9685 driver in a similar style to the standard Servo library
The library builds upon the adafruit library for this specific driver
Although the adafruit library covers a larger scope of things, it is a little bit difficult to use for a beginner
This library makes coding the PCA driver extremely easy and intuitive
There are two main functions in the library: driverSetup and servoWrite
Just put the driverSetup function in the void setup code (the arguments are explained in the example)
Use servoWrite to command a specific servo to go to a certain angle (argument 1 and 2, respectively)
Overall, this library simplififes usage of the PCA9685 driver so that less-experienced coders can develop programs using the driver
