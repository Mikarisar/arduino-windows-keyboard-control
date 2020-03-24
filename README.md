# arduino-windows-keyboard-control
This is a guide how to make Arduino UNO/NANO press buttons on your Windows PC using only Arduino IDE 
and some C++ IDE (If You want to change keys and COM number (my COM is COM3)).
In this case Arduino receives signals from an infrared remote control by infrared sensor.
So, what you gonna do:
  1. Connect infrared sensor to your Arduino
  2. Change infrared sensor pin number in Arduino sketches
  3. Flash RemoteButtonReader.ino and replace button codes in ArduinoCOMRemote.ino to yours
  4. If needed - change buttons' names or something else in ArduinoCOMRemote.ino
  5. If your Arduino is connected to COM3 and you dont want to change my settings you may use COM_HID.exe
     Otherwise modify and compile COM_HID.cpp in Microsoft Visual Studio or other.

More comments you may find in sources. Good luck!
 *I made this to control youtube lying on the bed:D
