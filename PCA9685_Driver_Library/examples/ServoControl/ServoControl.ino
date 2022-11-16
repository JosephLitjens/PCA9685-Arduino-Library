#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <PCADriver.h>
//make variables for inputs
int servoPulseMin=110;
int servoPulseMax=480;
int servoFreq=50;

//create object PCADriver (give it a name, such as myPCA)
//This function requires two inputs that depend on the servo being used
//This requires knowledge of the frequency of the servo
//first, find the period of the servo from the frequency (9g micro is usually 50hz, so 20ms)
//You will also need to know the range of pulses that the servo accepts
//For example, 9g microservos are about 0.5-2.5ms
//To find pulseMin, divide the lower bound by the period, and then multiply by 4096 for bits 
//EX: (0.5/20)*4096=102.4 goes to ~110 (for safety)
//Same technique to find pulseMax
//EX: (2.5/20)*4096=512 goes to ~500
//THESE MAY NEED CALLIBRATION

PCADriver myPCA(servoPulseMin,servoPulseMax);

void setup() {
//PCADriver requires a setup function, so put that in the setup
//inputs are servo frequency and oscillator frequency
//for this board, oscillator frequency is about 25Mhz
//for 9g microservo, frequency is about 50hz
myPCA.driverSetup(servoFreq,27000000);
}

void loop() {
  //This function "writes" to the servos
  //Easy to use, just like Servo.h library essentially!
  //first argument is the servo number you want to control (from 0-15)
  //second argument is the angle you want the servo to be (0-180)
myPCA.servoWrite(0,90);
}
