#include <Wire.h>
#include <LSM6DS3.h>
#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>
SoftwareSerial softSerial(/*rx =*/7, /*tx =*/6);

#define CONVERT_G_TO_MS2    9.80665f
#define MAX_ACCEPTED_RANGE  2.0f 

// IMU
LSM6DS3 myImu(I2C_MODE, 0x6A);  // I2C address for LSM6DS3

// DFPlayer Mini setup
DFRobotDFPlayerMini myDFPlayer;  

void setup() {
  Serial.begin(115200);
  softSerial.begin(9600);
  if (!myDFPlayer.begin(softSerial)) {
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));
  myDFPlayer.volume(20); // Set volume level (0-30)

  if (myImu.begin() != 0) {
    Serial.println("Failed to initialize the LSM6DS3 sensor.");
    while (1);
  }

  Serial.println("LSM6DS3 initialized.");
}

void loop() {
  float x, y, z;
  x = myImu.readFloatAccelX();
  y = myImu.readFloatAccelY();
  z = myImu.readFloatAccelZ();

  // Determine the axis with the greatest acceleration
  if (abs(x) > 2.5 || abs(y) > 2.5|| abs(z) > 2.5) { // Threshold to detect a punch
    Serial.println("Punch detected!");
    
    if (abs(x) > abs(y) && abs(x) > abs(z)) {
      Serial.println("Punch on X-axis");
      myDFPlayer.play(1);
      delay(250);
    } else if (abs(y) > abs(x) && abs(y) > abs(z)) {
      Serial.println("Punch on Y-axis");
      myDFPlayer.play(2);
      delay(250);
    } else {
      Serial.println("Punch on Z-axis");
      myDFPlayer.play(3);
      delay(250);
    }

    delay(500);  // Shorter delay to improve responsiveness
  }

  delay(100);
}