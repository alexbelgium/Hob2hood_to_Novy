# Hob2hood_to_Novy
Seamless connection of AEG hob and Novy hood by converting IR to 433 Mhz with an Arduino nano

Introduction
************
- AEG hob uses the hob2hood protocol and communicates through IR codes.
- Novy hood communicates through a proprietary 433Mhz protocol.
- The aim of this project is to allow the AEG hob to communicate with Novy by interpreting the IR commands and translating them to the 433 Mhz protocol

Material needed
***************
- Arduino nano (from amazon)
- 433 Mhz emitter : FS1000a (from amazon)
- IR receiver : https://www.dfrobot.com/product-351.html (from amazon)
- power source (5V by mini USB)

Arduino wiring
**************
<img src="https://github.com/alexbelgium/Hob2hood_to_Novy/blob/master/Arduino_wiring.jpg" width="250">

Instructions
************
- Connect IR receiver on arduino nano
- Connect 433Mhz emitter on arduino nano
- Install RCSwitch_novy.zip as a custom library
- Install Hob2hood_to_Novy.ino as a script
- Upload on arduino nano

Sources
*******
- https://github.com/martijndierckx/novy-433 : command Novy hood from rpi
- https://github.com/tuxedo0801/Arduino-Hob2Hood : command AEG hob from arduino
