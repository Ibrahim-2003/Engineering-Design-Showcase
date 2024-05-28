#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

File myFile;
LiquidCrystal_I2C lcd1(0x27, 16, 2);

#define DS_PIN 8
#define SHCP_PIN 9
#define STCP_PIN 10

int RED = 0;
int YELLOW = 1;
int GREEN = 2;

const int register_count = 5;

int HOURS[12][3] = {{12,24,37},
                        {0,13,25},
                        {1,14,26},
                        {2,15,27},
                        {3,16,28},
                        {4,5,17},
                        {6,18,29},
                        {7,19,30},
                        {8,23,31},
                        {9,20,32},
                        {10,21,33},
                        {11,22,34}};

float sample_data[12] = {
    207,
    1546,
    4359,
    5393,
    3519,
    1616,
    3101,
    2094,
    1553,
    614,
    504,
    0
};

boolean registers[8*register_count];

void setup() {
  Serial.begin(250000);
  pinMode(DS_PIN, OUTPUT);
  pinMode(SHCP_PIN, OUTPUT);
  pinMode(STCP_PIN, OUTPUT);
  pinMode(4,OUTPUT);
  lcd1.init();
  lcd1.backlight();
  lcd1.setCursor(2,0);
  lcd1.print("OEDK TRAFFIC");
  for(int hour = 0; hour<8*register_count; hour++){
    registers[hour] = LOW;
  };
  writereg();
}

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
  int clock_time = clockTime();
  if(clock_time == 0){
    Serial.println("AM");
    lcd1.setCursor(7,1);
    lcd1.print("AM");
    morningSD();
    }else{
      Serial.println("PM");
      lcd1.setCursor(7,1);
      lcd1.print("PM");
      afternoonSD();
      }
  for(int i = 0; i < 12; i++){
    registers[HOURS[i][trafficLevel(i)]] = HIGH;
    writereg();
  };
}

int clockTime(void){
  int time = 1;
  return time;
}


 float largest(float arr[], int n)
{
    int i;
    
    // Initialize maximum element
    int max = arr[0];
 
    // Traverse array elements from second and
    // compare every element with current max 
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
 
    return max;
}

//This function normalizes the traffic data for each hour and converts to analog output (0 to 255)
int trafficLevel(int hour){
  float current_visits = sample_data[hour];
  if(current_visits <= 1000){
    return GREEN;
    }else if(current_visits <= 3000){
      return YELLOW;
      }else{
        return RED;
        }
//  float largest_num = float(largest(sample_data, 12));
//    float weight = current_visits/largest_num;
//    weight = 255*weight;
//    if(weight>255*2/3){
//      return RED;
//      }else if(weight<=255*2/3 && weight>=255*1/3){
//        return YELLOW;
//        }else{
//          return GREEN;
//          }
}

void afternoonSD(void){
  String incoming_string = "";
  boolean string_ready = false;
  int visitors = 0;

  // re-open the file for reading:
  myFile = SD.open("pm_data.txt");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      incoming_string = myFile.readStringUntil('\n');
      string_ready = true;
      if(string_ready == true){
//    Serial.println("Received String: ");
//    visitors = incoming_string.toInt();
    char *strings[2]; // an array of pointers to the pieces of the above array after strtok()
    char *ptr = NULL;
    byte index = 0;
    ptr = strtok(incoming_string.c_str(), ",");  // parse comma-delimited string as array
    while (ptr != NULL)
    {
       strings[index] = ptr;
       index++;
       ptr = strtok(NULL, ",");
    }
    int hour = String(strings[0]).toInt();
    int visitors = String(strings[1]).toInt();
    sample_data[hour-1] = visitors;
    Serial.println(String(hour) + "-" + String(visitors));
    delay(1000);
      }
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening pm.txt");
  }
  }

void morningSD(void){
  String incoming_string = "";
  boolean string_ready = false;
  int visitors = 0;

  // re-open the file for reading:
  myFile = SD.open("am_data.txt");
  if (myFile) {
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      incoming_string = myFile.readStringUntil('\n');
      string_ready = true;
      if(string_ready == true){
//    Serial.println("Received String: ");
//    visitors = incoming_string.toInt();
    char *strings[2]; // an array of pointers to the pieces of the above array after strtok()
    char *ptr = NULL;
    byte index = 0;
    ptr = strtok(incoming_string.c_str(), ",");  // parse comma-delimited string as array
    while (ptr != NULL)
    {
       strings[index] = ptr;
       index++;
       ptr = strtok(NULL, ",");
    }
    int hour = String(strings[0]).toInt();
    int visitors = String(strings[1]).toInt();
    sample_data[hour-1] = visitors;
    Serial.println(String(hour) + "-" + String(visitors));
    delay(1000);
      }
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening am.txt");
  }
  }
