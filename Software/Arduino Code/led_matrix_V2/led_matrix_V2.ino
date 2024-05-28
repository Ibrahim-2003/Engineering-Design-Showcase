#define DS_PIN 8 //data pin
#define SHCP_PIN 9 // clock pin
#define STCP_PIN 10 // latch pin

const int register_count = 5;

void setup() {
  pinMode(DS_PIN, OUTPUT);
  pinMode(SHCP_PIN, OUTPUT);
  pinMode(STCP_PIN, OUTPUT);
  writereg();
}

boolean registers[8*register_count];

//void tester(void){
//  digitalWrite(latchPin, LOW);
// 
//    // Shift out the bits
//    shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
// 
//    // ST_CP HIGH change LEDs
//    digitalWrite(latchPin, HIGH);
//  }

void writereg(void){
  digitalWrite(STCP_PIN, LOW);
  for (int i = 8*register_count; i>=0; i--){
    digitalWrite(SHCP_PIN, LOW);
    digitalWrite(DS_PIN, registers[i]);
    digitalWrite(SHCP_PIN, HIGH);
    };
    digitalWrite(STCP_PIN, HIGH);
  }

void loop() {
  for(int i = 0; i<register_count*8; i++){
    registers[i] = HIGH;
    writereg();
    delay(1000);
    };

}
