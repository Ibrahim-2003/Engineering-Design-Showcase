// ---------------------------------------------------------------- //
// OEDK Visitor Counting Ultrasoninc Sensor System
// Ibrahim Al-Akash
// Using HC-SR04 Module
// Tested on 17 March 2022
// ---------------------------------------------------------------- //

// First Sensor
int echoPin = 8; // Attach pin D2 Arduino to pin Echo of HC-SR04
int trigPin = 9; // Attach pin D3 Arduino to pin Trig of HC-SR04

//Second Sensor
int echoPin2 = 4; // Attach pin D4 Arduino to pin Echo of HC-SR04
int trigPin2 = 5; // Attach pin D5 Arduino to pin Trig of HC-SR04

//Status LED
int ledPin = 7; // Attach pin D7 Arduino to cathode of LED

// defines variables
long duration; // Variable for the duration of sound wave travel
int distance1; // Variable for the distance measurement
int distance2; // Variable for the distance measurement
int baseline = 500; // Variable for the baseline distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(trigPin2, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin2, INPUT); // Sets the echoPin as an INPUT
  pinMode(ledPin, OUTPUT); // Sets the ledPin as an OUTPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
}
void loop() {

  distance1 = ultrasonicSensor(trigPin, echoPin);
  if(distance1 < baseline){ // If sensor 1 is triggered, check sensor 2
    delay(100); // Allow "cool down" for sound waves of sensor 1 to dissipate
    distance2 = ultrasonicSensor(trigPin2, echoPin2);
    if(distance2 < baseline){ // Sensor 2 is triggered
      while(distance2 < baseline){
        distance2 = ultrasonicSensor(trigPin2, echoPin2);
        delay(1); // Wait until visitor finishes walking past sensor
        }
        alertESP(); // Signal to the ESP to send HTTP POST request
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
      }
    delay(100);
    }
  
}

// This function runs the code for the sensor to measure distance
float ultrasonicSensor(int trigpin, int echopin){
  // Clears the trigPin condition
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echopin, HIGH);
  digitalWrite(trigpin, LOW);
  // Calculating the distance
  float dist = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  return dist;
  }

// This function alerts the ESP that a visitor has passed by
// so it can initiate the HTTP POST request to database
void alertESP(){
  Serial.print(1);
  }

// This function is the failsafe for the IoT system
void checkPost(void){
  if(Serial.available()){
    String post_status = Serial.readString(); // Read the message from the ESP after sending the HTTP POST request
    if(post_status != "SUCCESS"){ 
      digitalWrite(ledPin, HIGH); // If the message does not read success, turn on the error status LED
      }else{
        digitalWrite(ledPin, LOW); // If the message reads success, turn off the error status LED
        }
    }
  }
