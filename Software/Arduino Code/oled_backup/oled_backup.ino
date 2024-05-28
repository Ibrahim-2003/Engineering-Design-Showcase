void setup() {
  Serial.begin(9600);
}

int visitors[8][2] = {
      {2015, 2552}, {2016, 5212}, {2017, 5821}, {2018, 5319}, {2019, 5819}, {2020, 644}, {2021, 107}, {2022, 45}
  };

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<8; i++){
    Serial.print(String(visitors[i][0]) + "," + String(visitors[i][1]));
    delay(10000);
    }

}
