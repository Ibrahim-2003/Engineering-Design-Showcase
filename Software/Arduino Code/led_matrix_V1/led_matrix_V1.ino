/**
  * Library for PWM control of the 74HC595 shift register.
  * Created by Timo Denk (www.timodenk.com), 2017.
  * Additional information is available at https://timodenk.com/blog/shiftregister-pwm-library/
  * Released into the public domain.
  */

// Definition for that latch clock to be connected to pin 8
// See https://www.arduino.cc/en/Reference/PortManipulation
#define ShiftRegisterPWM_LATCH_PORT PORTB
#define ShiftRegisterPWM_LATCH_MASK 1
#include "ShiftRegisterPWM.h"

int numOfRegisters = 3;
int resolution = 60;

void setup() {
  pinMode(2, OUTPUT); // data
  pinMode(3, OUTPUT); // clock
  pinMode(8, OUTPUT); // latch pin is now 8 (opposed to the default value 4)
}

void loop()
{
  ShiftRegisterPWM sr(numOfRegisters, resolution); // Create a shift register object with 2 chained registers and a resolution of 255

  sr.interrupt(ShiftRegisterPWM::UpdateFrequency::SuperFast);
  while(true){
//    sr.set(0,resolution); //led 1 green
//    sr.set(1,resolution); //led 1 red
//    sr.set(2,resolution); //led 2 blue
//    sr.set(3,resolution); //led 2 red
//    sr.set(4,resolution); //led 2 green
//    sr.set(5,resolution); //led 3 blue
//    sr.set(6,resolution); //led 3 green
//    sr.set(7,resolution); //led 3 red
//    sr.set(8,resolution);
//    sr.set(9,resolution);
//    sr.set(10,resolution);
//    sr.set(11,resolution);
//    sr.set(12,resolution);
//    sr.set(13,resolution);
//    sr.set(14,resolution);
//    sr.set(15,resolution); //led 1 blue
//    sr.set(16,resolution);
    for(int i = 0; i<numOfRegisters*8; i++){
      sr.set(i,resolution);
      delay(500);
      sr.set(i,0);
      delay(500);
      };
    };
  
}
