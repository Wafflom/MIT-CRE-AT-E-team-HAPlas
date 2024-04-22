# MIT-CRE[AT]E-team-HAPlas
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
  - 12mm Brass rod (other types of dense metal can be used depending on preference and availiability)

### Tools:
  - Soldering Iron
  - 3d Printer
  - Screwdriver
  - Lathe

# Printed Parts and settings
[STL's found here](https://github.com/Wafflom/MIT-CREATE-team-HAPlas/tree/002e4f92e56438b101ec2bbca2ead18dcc9f6623/STL's)
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
## Install the Arduino IDE 
  - [Download link](https://www.arduino.cc/en/software)
## Install the Seeed Studio board library
  - After opening the Arduino IDE click on File > Preference, and fill in Additional Boards Manager URLs with the URL below:
    https://files.seeedstudio.com/arduino/package_seeeduino_boards_index.json
![Screenshot 2024-04-21 192040](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/669a1af1-e168-4f81-8e60-15b3c4b7a20f)
## Select which program variant you want to use
  - [click here for code options](https://github.com/Wafflom/MIT-CREATE-team-HAPlas/tree/86a4da8f8bbf2c63ec49366ca752f0183104cafe/Code)
## Select the board in Arduino programmer and hit upload
![Screenshot 2024-04-21 192322](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/50197656-fb2b-4b20-8055-c5b251d984f0)


