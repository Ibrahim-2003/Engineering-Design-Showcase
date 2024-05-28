#include <SoftwareSerial.h>

//CONNECT RX of ESP to TX of Uno, TX of ESP to RX of Uno
#define STATUS_LED  7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(STATUS_LED, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  

}

void recordVisitor(void){
  delay(1000);
  Serial.print(1); // print 1 to Serial to trigger ESP to send POST request
  delay(2000);
  Serial.print("\n");
  while(!Serial.available()){
  delay(1000);
  }
  String receiver = Serial.readString(); // read response from Serial
  Serial.println(receiver);
  if(receiver != "SUCCESS!"){
    digitalWrite(STATUS_LED, HIGH); // if the ESP does not successfully send the data, then turn on error status LED
    }
  else{
    digitalWrite(STATUS_LED, LOW);
    }
  delay(2000);
  }
