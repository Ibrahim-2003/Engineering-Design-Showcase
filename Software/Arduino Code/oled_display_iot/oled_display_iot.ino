#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

SoftwareSerial myserial(2, 3); //TX, RX

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

//// defines pins numbers
//const int trigPin1 = 7;
//const int echoPin1 = 6;
//const int trigPin2 = 10;
//const int echoPin2 = 11;
//// defines variables
//long duration;
//int distance;

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
  Serial.begin(9600);
  myserial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(5000);

  // Clear the buffer
  display.clearDisplay();

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

void loop() {
  String incoming_string = "";
  boolean string_ready = false;
  int visitors = 0;

  while(myserial.available()){
    incoming_string = myserial.readString();
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
    displayTextOLED(String(visitors));
    Serial.print("Year: " + String(year) + "\tVisitors: " + String(visitors) + "\n\n");
    };

}
