void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write("Hello from ESP-01");
  delay(2000);
}
