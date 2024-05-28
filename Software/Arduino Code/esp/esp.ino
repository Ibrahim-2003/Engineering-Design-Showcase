#include <SoftwareSerial.h>

SoftwareSerial myserial(2, 3); //TX, RX

void setup(){
  Serial.begin(9600);
  myserial.begin(9600);
  }

void loop(){
  if(myserial.available()){
  Serial.println("Reading: " + myserial.readString());
  }
  }
