# Code used for audio playback

# Using Gesture recognition:
### If the usage of gesture recognition is desired, you can either use the included gesture library:
  - [Gesture Library](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/tree/48943a845ded3df958085c8eb5ed810e9c71b0dc/Code/Gesture%20Library)
### Or you can create your own using these instructions provided by Seedduino:
  - [Library creation instructions](https://wiki.seeedstudio.com/XIAOEI/)
  - 
## Default Gestures:
  - Jab (straight punch)
  - Uppercut
  - Hook
## Library upload instructions:
  - Download the library
![Screenshot 2024-04-21 183703](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/e48cb4b2-0d56-455a-828c-47c96e58ffa5)
  - Upload to Arduino IDE
![Screenshot 2024-04-21 183919](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/05f53333-7181-4f0a-af25-1892250372d7)
  - Include in program
![Screenshot 2024-04-21 184022](https://github.com/Wafflom/MIT-CRE-AT-E-team-HAPlas/assets/128776051/73bcea69-021c-4e95-9af9-a23d9a30ee7a)
  **Note If using your own library replace the file name in the quotations with your own library name

# File naming convention:
#### When uploading audio files to the SD card for the MP3 player, ensure that the files are in the root directory of the SD card and are named 001, 002, 003... etc. 
#### You will call to play these files using the function:
```ruby
myDFPlayer.play(/*number*/);
```
#### With the number corresponding to the file you want to be played, this convention for naming should also be used if the user desires to use different audio files than the ones we used.



