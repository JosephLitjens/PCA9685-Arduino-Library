//include libraries
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include "PCADriver.h"

//constructor function
//This function requires two inputs that depend on the servo being used
//This requires knowledge of the frequency of the servo
//first, find the period of the servo from the frequency (9g micro is usually 50hz, so 20ms)
//You will also need to know the range of pulses that the servo accepts
//For example, 9g microservos are about 0.5-2.5ms
//To find pulseMin, divide the lower bound by the period, and then multiply by 4096 for bits 
//EX: (0.5/20)*4096=102.4-->110 (for safety)
//Same technique to find pulseMax
//EX: (2.5/20)*4096=512-->510
PCADriver::PCADriver(int pulseMin, int pulseMax){
  _pulseMin=pulseMin;
  _pulseMax=pulseMax;
}

//function to setup the driver
//this sets up the servo driver object created by the adafruit library earlier
//You need to know the servo frequency and the oscillator frequency
//For 9g microservo, the frequency is typically about 50hz
//For this driver, the oscillator frequency is about 25 megahertz, so anything around that works
void PCADriver::driverSetup(int servoFreq, long oscFreq){
  _servoFreq=servoFreq;
  _oscFreq=oscFreq;
 pwm.begin();
pwm.setOscillatorFrequency(_oscFreq);
pwm.setPWMFreq(_servoFreq);
Serial.begin(9600);
Serial.println(_oscFreq);
}

//Servo drive function
void PCADriver::servoWrite (int servoNum,int angle){
  int servoPulse=map(angle,0,180,_pulseMin,_pulseMax);
  pwm.setPWM(servoNum,0,servoPulse);
}
