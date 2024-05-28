//API GET request test
#include <WiFi.h>
#include <HttpClient.h>
#include <EthernetClient.h>
#include <ArduinoJson.h>

char* ssid = "ORBI43"; //Wifi Access Point name
char* password = "vastcream373"; //Wifi password

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid,password);
  Serial.println("Connecting to WiFi...");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
    };

   Serial.println("\nConnected to WiFi!");
   Serial.println("IP Address: ");
   Serial.println(WiFi.localIP());
}

void loop() {
  if((WiFi.status() == WL_CONNECTED)){

    EthernetClient client;
    HttpClient http(client);

    client.begin("http://localhost/year?year=2019");
    int httpCode = client.GET();

    if(httpCode > 0){

    String payload = client.getString();
    Serial.println("\nStatus Code: " + String(httpCode));
    Serial.println(payload);

    char json[500];
    payload.replace(" ", "");
    payload.replace("\n", "");
    payload.trim();
    payload.remove(0,1);
    payload.toCharArray(json,500);

    StaticJsonDocument<200> doc;
    deserializeJson(doc,json);

    int visitors = doc["visitors"];
    Serial.write(visitors);

    client.end();

      }else{
        Serial.println("Error on HTTP request!");
        }
    
    }else{
      Serial.println("Connection lost!");
      }
  delay(10000);
}
