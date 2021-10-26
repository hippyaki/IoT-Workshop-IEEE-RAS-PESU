# IoT Platforms

## Folder Content:

####  1. `BLYNK_ESP32_BME280.ino` : Using Blynk App, control and monitor with the ESP32 board. Make sure to use the `auth_token` that you received on your email ID when you created the project in the App.
<p align="center">
  <img src="https://user-images.githubusercontent.com/52236719/137901894-b8d6359c-9ea1-4746-8ddb-769e84484f71.jpeg"width="240" height="540">
 <!--- <img src="https://user-images.githubusercontent.com/52236719/137902081-1d188c57-eda4-401b-911a-a7f3e948c66f.jpeg"width="240" height="540">  --->
  <img src="https://user-images.githubusercontent.com/52236719/137903934-ab3fce2f-cbc3-4d69-9945-a7b6e25db7b3.jpeg"width="240" height="540">
  <img src="https://user-images.githubusercontent.com/52236719/137903992-3da85dfe-4f59-474b-89ae-7c38c4bca41e.jpeg"width="240" height="540">
  <img src="https://user-images.githubusercontent.com/52236719/137903845-a633a002-65eb-4a06-85e5-706cc7541646.jpeg"width="240" height="540">
  <br>
</p>

- In the code, `WiFi.h`, `WiFiClient.h`, `Wire.h`, and `BlynkSimpleEsp32.h` libraries have been used. [Scroll to Libraries](https://github.com/hippyaki/IoT-Workshop-IEEE-RAS-PESU/tree/master/IoT%20Platforms#libraries)
- Replace `<wifi_name>`, `<password`, and `auth_token` under ssid, password, and auth with your WiFi and Blynk credentials. (Hint - Check the settings of the Project in App for Auth)
- After successful compilation, upload to the ESP32. Then go to `Tools`>`Serial Monitor` and wait for the program to be uploaded completely. Post upload, you'll view an output like below: <br>
```json
rst:0x1 (POWERON_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:1
load:0x3fff0018,len:4
load:0x3fff001c,len:1216
ho 0 tail 12 room 4
load:0x40078000,len:10944
load:0x40080400,len:6388
entry 0x400806b4
```
- Open the Blynk App > Add `Button`, `Slider` and `Value Display` on the blank space. Make changes as shown in the above images. 
- Run the Project and plug in the Dev Board. You should see the values and be able to control `PIN 2` and `PIN 4`

####  2. `Thingspeak_ESP32_BME280` : Thingspeak is not really an IoT Platform, but it is an API provider that lets you use hte site and its platform to send data into. It is mostly used to receive data from computational devices to gather the data and run a MATLAB code on it on the online platform itself. <br> You'll mostly watch people using a mincrocomputer (Raspberry Pi) to send data as an IoT device. Use this code to send data from the ESP32 itself. 

Below is a Public LIVE View of such a device:
<br>
<p align="center"><a href="https://thingspeak.com/channels/1518815/charts/2?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15&title=Humidity">
  <img src="https://user-images.githubusercontent.com/52236719/138034641-a03f0e36-b855-46a8-b89d-3abc37776de3.png" alt = "ThingSpeak API for my IoT Control">
<a>
</p>

- In this code, `Wifi.h`,  `HTTPClient.h`, `Wire.h`, and `SparkFunBME280.h` libraries have been used. [Scroll to Libraries](https://github.com/hippyaki/IoT-Workshop-IEEE-RAS-PESU/tree/master/IoT%20Platforms#libraries)
- Replace `<wifi_name>` and `<password` under ssid and password with your WiFi credentials. Get the `Write API Key` from API Keys section in ThingSpeak Channel. Paste it on code over `<API>`
- In the `serverPath` variable change the field no. according to your requirement. In case you're using Field 1, then change `"&field2="` -> `"&field1="`. For multiple fields, add ` + "&field3=" + readTemperature();`.
- After successful compilation, upload to the ESP32. If there was no error, check the Chart of the Channel > Field. 
  
-----------------------------------------------------------------------------------------------


## Libraries

1. Wire - This library allows you to communicate with I2C / TWI devices. In ESP32, **`SDA -> D21`** and **`SCL -> D22`**. Used to set I2C communication with the BME280 sensor.
2. SparkFunBME280 - This library allows the user to: Read pressure in Pa, Read temperature in C and F, Read humidity in %RH and Read Altitude in feet and meters. [more details](https://github.com/sparkfun/SparkFun_BME280_Arduino_Library)
3. Adafruit Sensor - To use the BME280 library, you also need to install the Adafruit_Sensor library. Follow the next steps to install the library in your Arduino IDE:
Go to `Sketch` > `Include Library` > `Manage Libraries` and type “Adafruit Unified Sensor” in the search box. Scroll all the way down to find the library and install it.
4. WiFi - This library lets the board connect to the internet, wifi service. [more details](https://www.arduino.cc/en/Reference/WiFi)
5. WiFiClient - Creates a client that can connect to to a specified internet IP address and port as defined in client.connect(). Required for ESP8266 devices to avoid error. [more details](https://www.arduino.cc/en/Reference/WiFiClient)
6. BlynkSimpleEsp32 - Use the Blynk IoT platform with this library to build IoT applications over simple code. [download link](https://github.com/blynkkk/blynk-library/releases/download/v1.0.1/Blynk_Release_v1.0.1.zip)
7. HTTPClient - Library to easily make HTTP GET, POST and PUT requests to a web server. Works with any class derived from Client - so switching between Ethernet, WiFi and GSMClient requires minimal code changes. [more details](https://github.com/amcewen/HttpClient)
