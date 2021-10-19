//Install Arduino.JSON Library 


#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include "SparkFunBME280.h"

BME280 mySensor;

const char* ssid = "<wifi_name>";
const char* password = "<password>";

//Your Domain name with URL path or IP address with path
String serverName = "https://api.thingspeak.com/update";

String auth = "?api_key=<API>";

unsigned long lastTime = 0;

unsigned long timerDelay = 5000;

void setup() {
  Serial.begin(115200); 
//-------------------- WIFI INIT --------------------------------
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
  
//---------------------- SENSOR INIT ----------------------------
  Serial.println("Reading basic values from BME280");

  Wire.begin();

  if (mySensor.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while(1); //Freeze
  }
//--------------------------------------------------------------  

}

void loop() {
  //Send an HTTP POST request every 10 minutes
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      String serverPath = serverName + auth + "&field2=" + mySensor.readFloatHumidity();
      
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        String payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
