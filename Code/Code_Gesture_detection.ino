
/* Includes ---------------------------------------------------------------- */
#include <motion_recognition_test_MIT_inferencing.h>
#include <LSM6DS3.h>
#include <Wire.h>
#include <DFRobotDFPlayerMini.h>
/* Constant defines -------------------------------------------------------- */
#define CONVERT_G_TO_MS2    9.80665f
#define MAX_ACCEPTED_RANGE  2.0f        // starting 03/2022, models are generated setting range to +-2, but this example use Arudino library which set range to +-4g. If you are using an older model, ignore this value and use 4.0f instead
/* MP3 Player Setup -------------------------------------------------------- */
DFRobotDFPlayerMini myDFPlayer;
SoftwareSerial softSerial(/*rx =*/7, /*tx =*/6);
/* Private variables ------------------------------------------------------- */
static bool debug_nn = false; // Set this to true to see e.g. features generated from the raw signal
LSM6DS3 myIMU(I2C_MODE, 0x6A);
/**
* @brief      Arduino setup function
*/
void setup()
{
    // put your setup code here, to run once:
    Serial.begin(115200);

    if (!myDFPlayer.begin(Serial)) {
      Serial.println(F("Unable to begin:"));
      Serial.println(F("1.Please recheck the connection!"));
      Serial.println(F("2.Please insert the SD card!"));
    while (true);
    }

    Serial.println(F("DFPlayer Mini online."));
    myDFPlayer.volume(30);  // Set volume level (0-30)
    Serial.println("Edge Impulse Inferencing Demo");

    if (!myIMU.begin()) {
      Serial.println("Failed to initialize IMU!\r\n");
    } else {
      Serial.println("IMU initialized\r\n");
    }

    if (EI_CLASSIFIER_RAW_SAMPLES_PER_FRAME != 3) {
      Serial.println("ERR: EI_CLASSIFIER_RAW_SAMPLES_PER_FRAME should be equal to 3 (the 3 sensor axes)\n");
      return;
    }
}

/**
 * @brief Return the sign of the number
 * 
 * @param number 
 * @return int 1 if positive (or 0) -1 if negative
 */
float ei_get_sign(float number) {
    return (number >= 0.0) ? 1.0 : -1.0;
}

/**
* @brief      Get data and run inferencing
*
* @param[in]  debug  Get debug info if true
*/
void loop()
{


    delay(2000);

    // Allocate a buffer here for the values we'll read from the IMU
    float buffer[EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE] = { 0 };

    for (size_t ix = 0; ix < EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE; ix += 3) {
        // Determine the next tick (and then sleep later)
        uint64_t next_tick = micros() + (EI_CLASSIFIER_INTERVAL_MS * 1000);

buffer[ix] = myIMU.readFloatAccelX();
buffer[ix+1] = myIMU.readFloatAccelY();
buffer[ix+2] = myIMU.readFloatAccelZ();


        for (int i = 0; i < 3; i++) {
            if (fabs(buffer[ix + i]) > MAX_ACCEPTED_RANGE) {
                buffer[ix + i] = ei_get_sign(buffer[ix + i]) * MAX_ACCEPTED_RANGE;
            }
        }

        buffer[ix + 0] *= CONVERT_G_TO_MS2;
        buffer[ix + 1] *= CONVERT_G_TO_MS2;
        buffer[ix + 2] *= CONVERT_G_TO_MS2;

        delayMicroseconds(next_tick - micros());
    }

    // Turn the raw buffer in a signal which we can the classify
    signal_t signal;
    int err = numpy::signal_from_buffer(buffer, EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE, &signal);
    if (err != 0) {
        Serial.println("Failed to create signal from buffer (%d)\n", err);
        return;
    }

    // Run the classifier
    ei_impulse_result_t result = { 0 };

    err = run_classifier(&signal, &result, debug_nn);
    if (err != EI_IMPULSE_OK) {
        Serial.println("ERR: Failed to run classifier (%d)\n", err);
        return;
    }

#if EI_CLASSIFIER_HAS_ANOMALY == 1
    Serial.println("    anomaly score: %.3f\n", result.anomaly);
#endif

  if (result.classification[1].value > 0.5) {
      myDFPlayer.play(1);  // Play file number 1 for "FORWARD BACKWARD"
      Serial.println("Playing audio for 'FORWARD BACKWARD'");
      delay(2000);
   }
   
  if (result.classification[0].value > 0.5) {
       myDFPlayer.play(2);  // Play file number 2 for "UPPERCUT"
      Serial.println("Playing audio for 'UPPERCUT'");
      delay(2000);
   }
 
   if (result.classification[2].value > 0.5) {
      myDFPlayer.play(3);  // Play file number 3 for "HOOK"
      Serial.println("Playing audio for 'HOOK'");
          delay(2000);
   }
 
}
