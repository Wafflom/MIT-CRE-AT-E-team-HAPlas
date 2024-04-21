# MIT-CRE-AT-E-team-HAPlas
Code and CAD models repository for our MIT CRE[AT]E challenge device, a haptic and auditory feedback device.

# BOM:
### Electronics:
  - [Seeed Studio XIAO nRF52840 Sense](https://www.seeedstudio.com/Seeed-XIAO-BLE-Sense-nRF52840-p-5253.html)
  - [DFPlayer mini MP3 player](https://www.dfrobot.com/product-1121.html)
  - [1W 40mm 2 pin speaker](https://www.amazon.com/Fielect-Magnet-Speaker-Internal-Loudspeaker/dp/B083TDLGNB?th=1)
  - [UltraFire 10440 Li-ion battery](https://www.batteryupgrade.com/shopBrowser.php?assortmentProductId=21883872&shopGroupId=70741364)
  - Sacrificial USB-C Cable (it will be cut to hijack the power pins, so use one you do not need anymore)
### Hardware:
  - 4x M3x8mm Countersunk hex head screws
  - 1.5mm thick, 15mm wide double-sided foam tape
  - 26AWG wire (for the electronics)
  - 250~ grams of PLA (PLA+ recommended, color is up to preference) We used [Bambulabs PLA MATTE](https://us.store.bambulab.com/products/pla-matte-filament?variant=41078280093832)

### Tools:
  - Soldering Iron
  - 3d Printer
  - Screwdriver

# Printed Parts and settings
## Main Body STL
#### QTY: 1
### Suggested Print Settings:
  - 0.16mm Layer Height
  - 3 Walls
  - 6 Top & Bottom layers
  - 20% Infill
  - Cubic infill pattern
  - Supports on (tree supports suggested)

#### Orientation in slicer (Orca slicer shown)
![Screenshot 2024-04-21 171936](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/62be353e-50b7-43f5-bed8-149db5c053ae)
#### Sliced with Supports (Orca slicer shown)
![Screenshot 2024-04-21 172137](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/8db7320b-3451-4ecb-8d23-d4d9305bb765)


## Electronics Bay Cap STL
#### QTY: 1
### Suggested Print Settings:
  - 0.2mm Layer Height
  - 3 Walls
  - 100% Infill
  - Supports off

#### Orientation in slicer (Orca slicer shown)
![Screenshot 2024-04-21 175325](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/c72ea51c-c83c-41b8-b700-d7b885a9bb0b)
#### Sliced No Supports
![Screenshot 2024-04-21 175444](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/7d12a601-3af2-460d-a372-5d9828e0e3b5)



## Cap STL
#### QTY: 2
### Suggested Print Settings:
  - 0.16mm Layer Height
  - 3 Walls
  - 4 Top & Bottom layers
  - 40% infill
  - Cubic infill pattern
  - Supports off

#### Orientation in slicer (Orca slicer shown)
![Screenshot 2024-04-21 174940](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/92957a9c-2f2d-41d6-bdc3-618abf81aa0e)
#### Sliced No Supports (Orca slicer shown)
![Screenshot 2024-04-21 175055](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/6dc53d9c-9836-4a8f-8b4e-471d5fa204ed)


## Battery Holder STL
#### QTY: 1
### Suggested Print Settings:
  - 0.16mm Layer Height
  - 3 Walls
  - 100% Infill
  - Supports on (tree supports suggested)

#### Orientation in slicer (Orca slicer shown)
![Screenshot 2024-04-21 175623](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/9f16c979-9573-4cbf-a245-9e6677db56b0)
#### Sliced with Supports (Orca slicer shown)
![Screenshot 2024-04-21 175740](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/7008d793-6a03-4064-9dfc-bb9eaba1327b)

# Code upload instructions

## Code used for audio playback
Two different variants of the program have been provided. The first, `Code_Simple.ino` is a simple one that activates the audio upon exceeding an acceleration threshold (measured in m/s^2) that can be used by users desiring a more simple device that always activates sound on the action. The second program, `Code_Gesture_detection.ino`, the one used in our final product and testing footage, utilizes a gesture recognition machine learning model made using edge impulse. This option allows users to correspond specific sounds to specific actions that can be made; we have provided the one we used for our final iteration if you would like to try it out without having to create your own model. ``Note that this model was calibrated for the movements of a 5-year-old and may not function well for an adult.``
## Using Gesture recognition:
#### If the usage of gesture recognition is desired, you can either use the included gesture library:
  - [Gesture Library](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/tree/48943a845ded3df958085c8eb5ed810e9c71b0dc/Code/Gesture%20Library)
#### Or you can create your own using these instructions provided by Seedduino:
  - [Library creation instructions](https://wiki.seeedstudio.com/XIAOEI/)
    
### Default Gestures:
  - Jab (straight punch)
  - Uppercut
  - Hook
### Library upload instructions:
  - Download the library
![Screenshot 2024-04-21 183703](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/e48cb4b2-0d56-455a-828c-47c96e58ffa5)
  - Upload to Arduino IDE
![Screenshot 2024-04-21 183919](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/05f53333-7181-4f0a-af25-1892250372d7)
  - Include the library in the program
![Screenshot 2024-04-21 184022](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/73bcea69-021c-4e95-9af9-a23d9a30ee7a)
  **Note If using your own library, replace the file name in the quotations with your own library name

## File naming convention:
##### When uploading audio files to the SD card for the MP3 player, ensure that the files are in the root directory of the SD card and are named 001, 002, 003... etc. 
##### You will call to play these files using the function:
```ruby
myDFPlayer.play(/*number*/);
```
##### With the number corresponding to the file you want to be played, this convention for naming should also be used if the user desires to use different audio files than the ones we used.




