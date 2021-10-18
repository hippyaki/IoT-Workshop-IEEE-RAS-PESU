# WebServer on ESP32

## Folder Content:

####  1. `BME280_testing.ino` : Test the working of BME280 sensor. It works using I2C communication with the ESP32. 
<p align="center">
  <img src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/06/ESP32-bme280_schematic.jpg?resize=768%2C669&quality=100&strip=all&ssl=1png" width="540" height="350"><br>
</p>

- In the code, `Wire.h` and `SparkFunBME280.h` libraries have been used. [Scroll to Libraries](https://github.com/hippyaki/IoT-Workshop-IEEE-RAS-PESU/new/master/WebServer%20on%20ESP32#libraries) 

- After successful compilation, upload to the ESP32. Then go to `Tools`>`Serial Monitor` and wait for the program to be uploaded completely. Post upload, you'll view an output like below: <br>
```json
Humidity: 63 Pressure: 100578 Alt: 204.7 Temp: 86.56
```

- Hint: Make sure the baudrate on the Serial Monitor is set to `115200`.


#### 2. `ESP32_webserver.ino` : Run a Webserver on ESP32. Create an HTML page which can be viewed on the IP address of the ESP32. Using BME280 sensor, use the data on the webpage. 
<p align="center">
  <img src="https://user-images.githubusercontent.com/52236719/137768915-dc954ee5-8118-42b6-a669-3c78c0aa9616.png"><br>
</p>

- In the code, `Wifi.h`, `WebServer.h`, `Wire.h` and `SparkFunBME280.h` libraries have been used. [Scroll to Libraries](https://github.com/hippyaki/IoT-Workshop-IEEE-RAS-PESU/new/master/WebServer%20on%20ESP32#libraries)

- After successful compilation, upload to the ESP32. Then go to `Tools`>`Serial Monitor` and wait for the program to be uploaded completely. Post upload, you'll view an output like below: <br>
```json
Connecting to 
SINHA-HUB
...
WiFi connected..!
Got IP: 192.168.29.203  
HTTP server started
```
- You should see your IP address beside `Got IP`. Copy the IP address and paste it on a browser. You'll see the output webpage as shown in above image.
- To add authentication to the data, if the IP address is leaked, replace the `'/'` in ```server.on("/", handle_OnConnect);``` with `'/password'`. Only the people with correct endpoint can access the ESP32 data.


## Libraries

1. Wire - This library allows you to communicate with I2C / TWI devices. In ESP32, **`SDA -> D21`** and **`SCL -> D22`**. Used to set I2C communication with the BME280 sensor.
2. SparkFunBME280 - This library allows the user to: Read pressure in Pa, Read temperature in C and F, Read humidity in %RH and Read Altitude in feet and meters. [more details](https://github.com/sparkfun/SparkFun_BME280_Arduino_Library)
3. Adafruit Sensor - To use the BME280 library, you also need to install the Adafruit_Sensor library. Follow the next steps to install the library in your Arduino IDE:
Go to `Sketch` > `Include Library` > `Manage Libraries` and type “Adafruit Unified Sensor” in the search box. Scroll all the way down to find the library and install it.

4. WiFi - This library lets the board connect to the internet, wifi service. [more details](https://www.arduino.cc/en/Reference/WiFi)
5. WebServer - Supports in creating a webserver and run an independent simple webserver. [more details](https://github.com/espressif/arduino-esp32/tree/master/libraries/WebServer)

Download all libraries from the folder and paste on the arduino/lib folder. [click here](https://download-directory.github.io?url=https://github.com/hippyaki/IoT-Workshop-IEEE-RAS-PESU/tree/master/WebServer%20on%20ESP32/libraries)
