
#define DEBUG_SW 0 // Make it 1 to see all debug messages in Serial Monitor

#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Wire.h>
#include "SparkFunBME280.h"

BME280 mySensor;

// Firebase Credentials
#define FIREBASE_HOST "<project_id_of_firebase>.firebaseio.com/" // Replace with your project ID, or the URL itself
#define FIREBASE_AUTH "<secret_key>" //Secret Key is found in Settings > Project Settings > Database Secrets 

// WiFi Credentials
#define WIFI_SSID "<wifi_name>"
#define WIFI_PASSWORD "<password>"

FirebaseData firebaseData;
FirebaseJson json;


void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  Serial.println("Reading basic values from BME280");

  Wire.begin();

  if (mySensor.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while(1); //Freeze
  }

}

void loop()
{
  json.set("/data", mySensor.readFloatHumidity());
  json.set("/status", "Success !");
  Firebase.updateNode(firebaseData,"/Device%201",json);
  Serial.print("Value: ");
  Serial.println(mySensor.readFloatHumidity()); //Data to be Pushed

  delay(5000);
}
