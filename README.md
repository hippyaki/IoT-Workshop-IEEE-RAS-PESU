# IoT-Workshop-IEEE-RAS-PESU
This repository contains files, content, code and projects related to the IoT workshop.

--------------------------------------------------------------------------------------------

## Getting Started with ESP32 on Arduino:

#### 1. Install ESP32 Add-on in Arduino IDE

- In your Arduino IDE, go to File > Preferences
    
    Enter https://dl.espressif.com/dl/package_esp32_index.json into the “Additional Boards Manager URLs” field as shown in the figure below. 
    
    ![Screenshot (1905)](https://user-images.githubusercontent.com/52236719/137845481-5e9e8920-8a1f-4276-a114-2a615c6345a9.png)

    Then, click the “OK” button:
 
- Open the Boards Manager. Go to Tools > Board > Boards Manager…
    
    Search for ESP32 and press install button for the "esp32".
    
    ![Screenshot (1907)](https://user-images.githubusercontent.com/52236719/137845836-82e02c8a-3f94-4453-9d47-12a6008e000a.png)

    That's it !! You are SET and ready to start with the ESP32 Development using Arduino IDE.
    

#### 2. Install SPIFFS (SPI Flash Filesystem) on Arduino IDE for ESP32:
- Download [ESP32FS-1.0.zip](https://github.com/me-no-dev/arduino-esp32fs-plugin/releases/download/1.0/ESP32FS-1.0.zip) from [ESP32 release page on Github](https://github.com/me-no-dev/arduino-esp32fs-plugin/releases/)\
- Go to the Arduino IDE directory, and open the Tools folder. Unzip the downloaded .zip folder to the Tools folder. You should have a similar folder structure:`<home_dir>/Arduino-<version>/tools/ESP32FS/tool/esp32fs.jar`
![Screenshot (1909)](https://user-images.githubusercontent.com/52236719/137848717-c5de39ed-7ebc-4fe1-b170-2f1e3f4d8ff0.png)

- Restart the Arduino IDE and and check for `ESP32 Sketch Data Upload` under `Tools` section.

  ![](https://i1.wp.com/randomnerdtutorials.com/wp-content/uploads/2018/10/sketch-data-upload.png)

That's it !! Now you can start using SPIFFS on your ESP32 board. Use the File system to load and save data on its memory.
