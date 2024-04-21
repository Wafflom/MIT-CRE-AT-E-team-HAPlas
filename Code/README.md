# Code used for audio playback

# Using Gesture recognition:
### If the usage of gesture recognition is desired, you can either use the included gesture library:
  - [Gesture Library]()
### Or you can create your own using these instructions provided by Seedduino:
  - [Library creation instructions]()

# File naming convention:
#### When uploading audio files to the SD card for the MP3 player, ensure that the files are in the root directory of the SD card and are named 001, 002, 003... etc. 
#### You will call to play these files using the function:
```ruby
myDFPlayer.play(/*number*/);
```
#### With the number corresponding to the file you want to be played, this convention for naming should also be used if the user desires to use different audio files than the ones we used.


