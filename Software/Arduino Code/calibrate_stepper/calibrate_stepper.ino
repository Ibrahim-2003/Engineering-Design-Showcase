#include <TM1637.h>

#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


SoftwareSerial myserial(2, 3); //TX, RX
// CHANGED: Connect ESP TX and RX to RX and TX, respectively, of the MEGA

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define LEDPIN  11

#define STEPPER_DIR 2
#define STEPPER_PULL 3

#define CLK 22//pins definitions for TM1637 and can be changed to other ports
#define DIO 23
TM1637 tm1637(CLK,DIO);

LiquidCrystal_I2C lcd1(0x27, 16, 2);
LiquidCrystal_I2C lcd2(0x26, 16, 2);

boolean setdir = LOW;
int stepper_delay = 100;

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

void setup() {
  Serial.begin(250000);
//  Serial.begin(9600);
  myserial.begin(9600);
  pinMode(STEPPER_PULL, OUTPUT);
  pinMode(STEPPER_DIR, OUTPUT);
  lcd1.init();
  lcd2.init();
  lcd1.backlight();
  lcd2.backlight();
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
  tm1637.display(0,1);
  tm1637.display(1,2);
  tm1637.point(1);
  tm1637.display(2,10);
  tm1637.display(3,11);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(5000);
  lcd1.print("YEAR");
  lcd2.setCursor(4,0);
  lcd2.print("VISITORS");

  // Clear the buffer
  display.clearDisplay();
//  stepBackward(160000);
  reverseMotor();


}

void displayTextOLED(String subject) {
  display.clearDisplay();

  display.setTextSize(3); // Draw 2X-scale text
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(30, 5);
  display.println(subject);
  display.display();      // Show initial text
  delay(100);
}

long step_count = 0;

void loop() {
  String incoming_string = "";
  boolean string_ready = false;
  int visitors = 0;

  digitalWrite(STEPPER_DIR, setdir);
  digitalWrite(STEPPER_PULL, HIGH);
  delayMicroseconds(stepper_delay);
  digitalWrite(STEPPER_PULL, LOW);
//  step_count = step_count + 1;

  while(Serial.available()){
    incoming_string = Serial.readString();
    string_ready = true;
    };

  if(string_ready == true){
    Serial.println("Received String: ");
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
    int year = String(strings[0]).toInt();
    int visitors = String(strings[1]).toInt();
    String oled_vis = String(visitors);
    if(visitors<100){
      oled_vis = "00" + String(visitors);
      }else if(visitors<1000){
        oled_vis = "0" + String(visitors);
        }
    displayTextOLED(oled_vis);
    lcd1.clear();
    lcd1.setCursor(6,0);
    lcd1.print("YEAR");
    lcd1.setCursor(6,1);
    lcd1.print(String(year));
    Serial.print("Year: " + String(year) + "\tVisitors: " + String(visitors) + "\n\n");
    };

//    Serial.println(step_count);

}

void reverseMotor(){
  setdir = !setdir;
}

void stepForward(long steps){
  for(long i = 0; i<steps; i++){
  digitalWrite(STEPPER_DIR, setdir);
  digitalWrite(STEPPER_PULL, HIGH);
  delayMicroseconds(stepper_delay);
  digitalWrite(STEPPER_PULL, LOW);
  delayMicroseconds(stepper_delay);
  }
  }

void stepBackward(long steps){
  reverseMotor();
  for(long i = 0; i<steps; i++){
  digitalWrite(STEPPER_DIR, setdir);
  digitalWrite(STEPPER_PULL, HIGH);
  delayMicroseconds(stepper_delay);
  digitalWrite(STEPPER_PULL, LOW);
  delayMicroseconds(stepper_delay);
  }
  }
