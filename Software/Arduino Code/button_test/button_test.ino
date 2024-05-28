#define READER 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(READER, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(READER);
  if(val == 0){
    Serial.print(1);
    };
    delay(2000);
}
