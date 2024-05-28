#define DS_PIN 8
#define SHCP_PIN 9
#define STCP_PIN 10

const int register_count = 1;

void setup() {
  pinMode(DS_PIN, OUTPUT);
  pinMode(SHCP_PIN, OUTPUT);
  pinMode(STCP_PIN, OUTPUT);
  writereg();
}

boolean registers[8*register_count];

void writereg(void){
  digitalWrite(SHCP_PIN, LOW);
  for (int i = 8*register_count; i>=0; i--){
    digitalWrite(STCP_PIN, LOW);
    digitalWrite(DS_PIN, registers[i]);
    digitalWrite(STCP_PIN, HIGH);
    };
    digitalWrite(SHCP_PIN, HIGH);
  }

void loop() {
  for(int i = 0; i<8; i++){
  registers[0] = HIGH;
  writereg();
  }

}
