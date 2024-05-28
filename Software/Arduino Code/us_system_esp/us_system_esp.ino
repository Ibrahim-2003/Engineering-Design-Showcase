#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

char ssid[] = "WAVLINKN";       // your network SSID (name)
char password[] = "EngI120sp22";  // your network key

WiFiClient client;

#define TEST_HOST "192.168.10.186"

void setup() {
Serial.begin(9600);
// Connect to the WiFI
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password); // if wifi has password, then use WiFi.begin(ssid,password);
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
}

void recordVisitor(void) {

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
  client.print("/sensor_triggered"); // %2C == ,
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

//  DeserializationError error = deserializeJson(doc, client);\

  // Stream& input;

  StaticJsonDocument<48> doc;

  DeserializationError error = deserializeJson(doc, client);

  if (error) {
    Serial.println(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    Serial.print("SD");
    return;
  } else {
    String post_status = doc["Status"]; // 5819
    Serial.print(post_status);
    
  }


}

void deleteVisitor(void) {

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
  client.print("/sensor_delete"); // %2C == ,
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

//  DeserializationError error = deserializeJson(doc, client);\

  // Stream& input;

  StaticJsonDocument<48> doc;

  DeserializationError error = deserializeJson(doc, client);

  if (error) {
    Serial.println(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    Serial.print("SD");
    return;
  } else {
    String post_status = doc["Status"]; // 5819
    Serial.print(post_status);
    
  }


}

void loop() {
if(Serial.available()){
  int reading = Serial.readString().toInt();
  if(reading>0){
    recordVisitor();
    }else if(reading < 0){
      deleteVisitor();
      }
  }
}
