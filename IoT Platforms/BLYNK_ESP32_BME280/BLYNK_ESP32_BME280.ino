//#include <Blynk.h>
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#include <Wire.h>
#include "SparkFunBME280.h"

int freq = 2000;
int channel = 0;
int resolution = 8;


BlynkTimer timer;

BME280 bme;
String temperature;

char auth[] = "<auth_token>";       // You should get Auth Token in the Blynk App.
char ssid[] = "<wifi_name>";                    // Your Wi-Fi Credentials
char pass[] = "<password>";

void setup() {  
  pinMode(2, OUTPUT);

  ledcSetup(channel, freq, resolution);
  ledcAttachPin(4, channel);

  Serial.begin(9600);
  
  Serial.println("WiFi connected");  
  
  Blynk.begin(auth, ssid, pass);

  Wire.begin();

  if (bme.beginI2C() == false) //Begin communication over I2C
  {
    Serial.println("The sensor did not respond. Please check wiring.");
    while(1); //Freeze
  }
   timer.setInterval(1000L, myTimerEvent);

   
}

BLYNK_WRITE(V0)
{  // This function gets called each time something changes on the widget
  int value = param.asInt();  // This gets the 'value' of the Widget as an integer
  digitalWrite(2,value);
  Serial.print("Pin 2 - ");
  Serial.println(value);
}


BLYNK_WRITE(V1)
{  // This function gets called each time something changes on the widget
  int value2 = param.asInt();  // This gets the 'value' of the Widget as an integer
  //map(value2, 0, 255, 0, 255)
  
  ledcWrite(channel, value2);
    Serial.print("Pin 4 - ");
    Serial.println(value2);
}

void myTimerEvent()
{
  Blynk.virtualWrite(V2, bme.readFloatHumidity());
}

void loop(){
  Blynk.run();
  timer.run();
}
