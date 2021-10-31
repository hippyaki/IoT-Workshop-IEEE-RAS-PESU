#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char THING_ID[]           = " "; //Select your 'Thing' > Bottom Right Corner OR Present in URL
const char DEVICE_LOGIN_NAME[]  = " ";//Device ID - Present along with Device Name

const char SSID[]               = " ";    // Network SSID (name)
const char PASS[]               = " ";    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]         = " ";    // Secret Key
void onLightChange();

float bme;
bool light;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(bme, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(light, READWRITE, ON_CHANGE, onLightChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);


int LED = 2;

void setup() {
  pinMode(LED, OUTPUT);
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  bme = random(0, 500);
  delay(500);
}


void onLightChange() {
  // Do something
  if(light){
    digitalWrite(LED, HIGH);
  }
  else{
    digitalWrite(LED, LOW);
  }
}
