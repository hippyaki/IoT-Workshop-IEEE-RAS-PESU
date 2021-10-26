# Data Management
## Folder Content:

####  1. `BLYNK_INTEGROMAT_ESP32` : Using Blynk App, send the data of ESP32 board to the Cloud. Make sure to use the credentials of Blynk IoT as mentioned in `IoT Platform` folder. 

<p align="center">
  <img src="https://user-images.githubusercontent.com/52236719/138923252-b2f14649-11bc-4461-8e12-940663b9b13a.png">

  <br>
</p>

- In the code, same libraries have been used from the `IoT Platforms` folder. There are no difference, but make sure to cross check for any changes in the future.
- This time, we used a GET method on the Blynk API to access the data from the Blynk-Cloud.
- `http://188.166.206.43/<auth_token>/get/V2` is the API URL which can be accessed from the broswer itself. 
- Make sure to replace `<auth_token>` with the Blynk Project token available in project settings (Blynk App)
- The Blynk-Cloud is updated every second from the ESP32's V2 pin.
- Follow the Flow Diagram from the `Day 2` Presentation to follow up with the flow of Data.

####  2. `FireBase_Integromat_ESP32` : Contains the code to send ESP32 data to the Firebase's Realtime Database.
<p align="center">
  <img src="https://user-images.githubusercontent.com/52236719/138938697-dc90cfcd-c45c-4d8d-aedc-c2d5b018cba9.png">

  <br>
</p>

- In the code, `FirebaseESP32.h`, and other libraries from `IoT Platforms` has been used. [Scroll to Libraries](https://github.com/hippyaki/IoT-Workshop-IEEE-RAS-PESU/tree/master/Data%20Management#libraries)
- Using the updateNode function from the Firebase ibrary, the data in Realitime Database is updated regularly.
- The code currently has `Device 1`'s child, i.e. `Data` and `Status` keys, who's values are updated using the below code.
```
  json.set("/data", mySensor.readFloatHumidity());
  json.set("/status", "Success !");
  Firebase.updateNode(firebaseData,"/Device 1",json);
```

<p align="center">
  <img src="https://user-images.githubusercontent.com/52236719/138925237-df1581a3-077c-4851-b0af-8d9c8888a58c.png">

  <br>
</p>

- Make sure to choose appropriate key to update the value of. For a parent like `Device 1`, use the above code.
- When using no parent, and the data is single handed value, use the below code
```
  json.set("Device 4", mySensor.readFloatHumidity());
  Firebase.updateNode(firebaseData,"/", json); 
```
<p align="center">
  <img src="https://user-images.githubusercontent.com/52236719/138935635-47e96545-9006-460d-9230-28a5c6f80bdf.png">

  <br>
</p>

---------------------------------------------------------------------------------------------------------------------------

## Libraries

1. FirebaseESP32 - This library helps in connecting to the FireBase, updating the data in it using simple build-in APIs. Has readmade functions, to send data from ESP32 to the Realtime Database. [more details](https://github.com/mobizt/Firebase-ESP32) - [Download Link](https://github.com/mobizt/Firebase-ESP32/releases/download/v3.11.12/Firebase-ESP32.zip)         
