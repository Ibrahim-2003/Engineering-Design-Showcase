/*******************************************************************
    A sample project for making a HTTP/HTTPS GET request on an ESP8266
    and parsing it from JSON
    It will connect to the given request, parse the JSON and print the 
    body to serial monitor
 *******************************************************************/

 //Find ip address on mac: "ipconfig getifaddr en0"


// ----------------------------
// Standard Libraries
// ----------------------------

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

// ----------------------------
// Additional Libraries - each one of these will need to be installed.
// ----------------------------

#include <ArduinoJson.h>
// Library used for parsing Json from the API responses

// Search for "Arduino Json" in the Arduino Library manager
// https://github.com/bblanchon/ArduinoJson

//------- Replace the following! ------
char ssid[] = "WAVLINKN";       // your network SSID (name)
char password[] = "EngI120sp22";  // your network key

// For Non-HTTPS requests
 WiFiClient client;

// For HTTPS requests
//WiFiClientSecure client;


// Just the base of the URL you want to connect to
#define TEST_HOST "192.168.10.186"

// OPTIONAL - The finferprint of the site you want to connect to.
//#define TEST_HOST_FINGERPRINT "89 25 60 5D 50 44 FC C0 85 2B 98 D7 D3 66 52 28 68 4D E6 E2"
// The finger print will change every few months.


void setup() {

  Serial.begin(250000);

  // Connect to the WiFI
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);
  delay(5000);

  //--------

  // If you don't need to check the fingerprint
//   client.setInsecure();

}

void getVisitors(String year) {

  // Opening connection to server (Use 80 as port if HTTP)
  if (!client.connect(TEST_HOST, 80))
  {
    Serial.println(F("Connection failed"));
    Serial.print("SD");
    return;
  }

  // give the esp a breather
  yield();

  // Send HTTP request
  client.print(F("GET "));
  // This is the second half of a request (everything that comes after the base URL)
  client.print("/year?year="+year); // %2C == ,
  client.println(F(" HTTP/1.1"));

  //Headers
  client.print(F("Host: "));
  client.println(TEST_HOST);

  client.println(F("Cache-Control: no-cache"));

  if (client.println() == 0)
  {
    Serial.println(F("Failed to send request"));
    return;
  }
  //delay(100);
  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  if (strcmp(status, "HTTP/1.1 200 OK") != 0)
  {
    Serial.print(F("Unexpected response: "));
    Serial.println(status);
    Serial.print("SD");
    return;
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders))
  {
    Serial.println(F("Invalid response"));
    Serial.print("SD");
    return;
  }

  // This is probably not needed for most, but I had issues
  // with the Tindie api where sometimes there were random
  // characters coming back before the body of the response.
  // This will cause no hard to leave it in
  // peek() will look at the character, but not take it off the queue
  while (client.available() && client.peek() != '{')
  {
    char c = 0;
    client.readBytes(&c, 1);
    Serial.print(c);
    Serial.println("BAD");
  }

  //  // While the client is still availble read each
  //  // byte and print to the serial monitor
  //  while (client.available()) {
  //    char c = 0;
  //    client.readBytes(&c, 1);
  //    Serial.print(c);
  //  }

  //Use the ArduinoJson Assistant to calculate this:

  //StaticJsonDocument<192> doc;
//  DynamicJsonDocument doc(192); //For ESP32/ESP8266 you'll mainly use dynamic.

//  DeserializationError error = deserializeJson(doc, client);

  // Stream& input;

  StaticJsonDocument<48> doc;

  DeserializationError error = deserializeJson(doc, client);

  if (error) {
    Serial.println(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    Serial.print("SD");
    return;
  } else {
    int visitors = doc["visitors"]; // 5819
    Serial.print(year+","+visitors);
    
  }


}

int getYears(void) {

  // Opening connection to server (Use 80 as port if HTTP)
  if (!client.connect(TEST_HOST, 80))
  {
    Serial.println(F("Connection failed"));
    Serial.print("SD");
    return 0;
  }

  // give the esp a breather
  yield();

  // Send HTTP request
  client.print(F("GET "));
  // This is the second half of a request (everything that comes after the base URL)
  client.print("/year_count"); // %2C == ,
  client.println(F(" HTTP/1.1"));

  //Headers
  client.print(F("Host: "));
  client.println(TEST_HOST);

  client.println(F("Cache-Control: no-cache"));

  if (client.println() == 0)
  {
    Serial.println(F("Failed to send request"));
    Serial.print("SD");
    return 0;
  }
  //delay(100);
  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));
  if (strcmp(status, "HTTP/1.1 200 OK") != 0)
  {
    Serial.println(F("Unexpected response: "));
    Serial.println(status);
    Serial.print("SD");
    return 0;
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders))
  {
    Serial.println(F("Invalid response"));
    Serial.print("SD");
    return 0;
  }

  // This is probably not needed for most, but I had issues
  // with the Tindie api where sometimes there were random
  // characters coming back before the body of the response.
  // This will cause no hard to leave it in
  // peek() will look at the character, but not take it off the queue
  while (client.available() && client.peek() != '{')
  {
    char c = 0;
    client.readBytes(&c, 1);
    Serial.print(c);
    Serial.println("BAD");
  }

  //  // While the client is still availble read each
  //  // byte and print to the serial monitor
  //  while (client.available()) {
  //    char c = 0;
  //    client.readBytes(&c, 1);
  //    Serial.print(c);
  //  }

  //Use the ArduinoJson Assistant to calculate this:

  //StaticJsonDocument<192> doc;
//  DynamicJsonDocument doc(192); //For ESP32/ESP8266 you'll mainly use dynamic.

//  DeserializationError error = deserializeJson(doc, client);

  // Stream& input;

  StaticJsonDocument<48> doc;

  DeserializationError error = deserializeJson(doc, client);

  if (error) {
    Serial.println(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    Serial.print("SD");
    return -1;
  } else {
    int year_count = doc["year_count"]; // 7
    return year_count;
    
  }


}

void loop() {
  // put your main code here, to run repeatedly:
  int year_count = getYears();
  for (int i = 0; i < year_count+1; i++){ // dynamically cycle through each year's visitor count
  getVisitors(String(i+2015));
  int minutes = 1;
  delay(1000*100); //update every 100 seconds
  }

}
