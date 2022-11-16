#ifndef PCADriver_h
#define PCADriver_h

//include necessary libraries
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

//create class PCADriver
class PCADriver
{
  public:
  //constructor
  PCADriver(int pulseMin, int pulseMax);
  //functions
  void servoWrite(int servoNum,int angle);
  void driverSetup(int servoFreq, long oscFreq);
  private:
  //create an instance of the servo driver through adafruit library
  Adafruit_PWMServoDriver pwm=Adafruit_PWMServoDriver(0x40);
  //variables
    int _pulseMin;
  int _pulseMax;
  int _servoFreq;
  long _oscFreq;
};
#endif
