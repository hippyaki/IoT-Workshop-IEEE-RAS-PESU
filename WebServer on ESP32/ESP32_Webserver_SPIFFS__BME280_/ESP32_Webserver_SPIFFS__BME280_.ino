// Import required libraries
#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
#include <Wire.h>
#include "SparkFunBME280.h"

// Replace with your network credentials
const char* ssid = "<wifi_name>";
const char* password = "<password>";

#define SEALEVELPRESSURE_HPA (1013.25)

BME280 bme;
String temperature, humid, pressr, alt ;

// Create AsyncWebServer object on port 80
AsyncWebServer server (80);

// Replaces placeholder with value
String processor(const String& var){
  Serial.print(var);
  if(var == "humid"){
    humid = bme.readFloatHumidity();
    Serial.println(humid);
    return humid;
  }
  else if(var == "temp"){
    temperature = bme.readTempC();
    Serial.println(temperature);
    return temperature;
  }
  else if(var == "pressr"){
    pressr = bme.readFloatPressure()/100;
    Serial.println(pressr);
    return pressr;
  }
  else if(var == "alt"){
    alt = bme.readFloatAltitudeFeet();
    Serial.println(alt);
    return alt;
  }
  return String();
}
 
void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  //pinMode(ledPin, OUTPUT);

  // Initialize SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false, processor);
  });
  
  // Route to load style.css file
  server.on("/main.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/main.css", "text/css");
  });

  server.on("/bgimage.jpg", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/bgimage.jpg", "image/jpg");
  });

  // Start server
  server.begin();

  Wire.begin();

  if (bme.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while(1); //Freeze
  }
}
 
void loop(){
  
}
