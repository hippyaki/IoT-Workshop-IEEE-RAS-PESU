# WebServer on ESP32

## Folder Content:

####  1. `BME280_testing.ino` : Test the working of BME280 sensor. It works using I2C communication with the ESP32. 
<p align="center">
  <img src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2019/06/ESP32-bme280_schematic.jpg?resize=768%2C669&quality=100&strip=all&ssl=1png" width="540" height="350"><br>
</p>

- In the code, `Wire.h` and `SparkFunBME280.h` libraries have been used. [Scroll to Libraries](https://github.com/hippyaki/IoT-Workshop-IEEE-RAS-PESU/tree/master/WebServer%20on%20ESP32#libraries) 

- After successful compilation, upload to the ESP32. Then go to `Tools`>`Serial Monitor` and wait for the program to be uploaded completely. Post upload, you'll view an output like below: <br>
```json
Humidity: 63 Pressure: 100578 Alt: 204.7 Temp: 86.56
```

- Hint: Make sure the baudrate on the Serial Monitor is set to `115200`.


#### 2. `ESP32_webserver.ino` : Run a Webserver on ESP32. Create an HTML page which can be viewed on the IP address of the ESP32. Using BME280 sensor, use the data on the webpage. 

<p align="center">
  <img src="https://user-images.githubusercontent.com/52236719/137768915-dc954ee5-8118-42b6-a669-3c78c0aa9616.png"><br>
</p>

- In the code, `Wifi.h`, `WebServer.h`, `Wire.h` and `SparkFunBME280.h` libraries have been used. [Scroll to Libraries](https://github.com/hippyaki/IoT-Workshop-IEEE-RAS-PESU/tree/master/WebServer%20on%20ESP32#libraries)

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

#### 3. `ESP32_Webserver_SPIFFS__BME280_` : Run a WebServer that uses SPIFFS and displays HTML, CSS file present in the ESP32 memory. Hosted a background image from the memory.

<p align="center">
  <img src="https://user-images.githubusercontent.com/52236719/137867659-52e5ed37-5527-4b28-a524-4b7dbd6dc390.png"><br>
</p>

- In the code, `Wifi.h`, `ESPAsyncWebServer.h`, `SPIFFS.h`, `Wire.h` and `SparkFunBME280.h` libraries have been used. [Scroll to Libraries](https://github.com/hippyaki/IoT-Workshop-IEEE-RAS-PESU/tree/master/WebServer%20on%20ESP32#libraries)
- After successful compilation, go to `Tools` > `ESP32 Sketch Data Upload` to upload the `data` folder which contains the HTML, CSS and Image file, to the ESP32 board.
- Upload the code and then go to `Tools`>`Serial Monitor` and wait for the program to be uploaded completely. Post upload, you'll view an output like below: <br>
```json
ets Jun  8 2016 00:22:57

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
Connecting to WiFi..
Connecting to WiFi..
Connecting to WiFi..
192.168.29.203
```
- Go to a Web Browser and enter the IP adress on the URL address bar. The Webpage will open, similar to the image given above.
- Check the serial monitor now, and you'll see additional lines printed:
```json
temp30.81
humid61.59
pressr1003.65
alt263.09
```
-----------------------------------------------------------------------------------------------------------------------------------

## Libraries

1. Wire - This library allows you to communicate with I2C / TWI devices. In ESP32, **`SDA -> D21`** and **`SCL -> D22`**. Used to set I2C communication with the BME280 sensor.
2. SparkFunBME280 - This library allows the user to: Read pressure in Pa, Read temperature in C and F, Read humidity in %RH and Read Altitude in feet and meters. [more details](https://github.com/sparkfun/SparkFun_BME280_Arduino_Library)
3. Adafruit Sensor - To use the BME280 library, you also need to install the Adafruit_Sensor library. Follow the next steps to install the library in your Arduino IDE:
Go to `Sketch` > `Include Library` > `Manage Libraries` and type “Adafruit Unified Sensor” in the search box. Scroll all the way down to find the library and install it.

4. WiFi - This library lets the board connect to the internet, wifi service. [more details](https://www.arduino.cc/en/Reference/WiFi)
5. WebServer - Supports in creating a webserver and run an independent simple webserver. [more details](https://github.com/espressif/arduino-esp32/tree/master/libraries/WebServer)
6. ESPAsyncWebServer - Creates Async HTTP and WebSocket Server on ESP32. Requires [AsyncTCP](https://github.com/me-no-dev/AsyncTCP) to use with ESP32. [more details](https://github.com/me-no-dev/ESPAsyncWebServer)
7. SPIFFS - It lets you access the flash memory like you would do in a normal filesystem in your computer, but simpler and more limited. You can read, write, close, and delete files. [more details](https://github.com/me-no-dev/arduino-esp32fs-plugin/) 


Download most of the libraries from the folder and paste on the `arduino/lib` folder. [click here](https://download-directory.github.io?url=https://github.com/hippyaki/IoT-Workshop-IEEE-RAS-PESU/tree/master/WebServer%20on%20ESP32/libraries). In case of inability to download or search for the libraries, mail me at akshayan.sinha@gmail.com with screenshot of the issue. Or create an issue on this Github Repo.
