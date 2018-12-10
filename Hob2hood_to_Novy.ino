#include <IRremote.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

// IR commands from AEG hob2hood device
const long IRCMD_VENT_1 = 0xE3C01BE2;     //Hob2hood On (level 1)
const long IRCMD_VENT_2 = 0xD051C301;     //Hob2hood level 2
const long IRCMD_VENT_3 = 0xC22FFFD7;     //Hob2hood level 3
const long IRCMD_VENT_4 = 0xB9121B29;     //Hob2hood level 4
const long IRCMD_VENT_OFF = 0x55303A3;    //Hob2hood off
const long IRCMD_LIGHT_ON = 0xE208293C;   //Light on (Hood on)
const long IRCMD_LIGHT_OFF = 0x24ACF947;  //Light off (Automatic after 2min)

// IR Receiver config
const int PIN_IR_RECEIVER = 2;
IRrecv irrecv(PIN_IR_RECEIVER); // create instance of 'irrecv'
decode_results results;

// ventilation, light and mode status init
int ventilation = 0;
int last_ventilation = 0;
int light = 0;
int last_light = 0;

void setup() {
  Serial.begin(9600); // for serial monitor output
  Serial.println("Hob2Hood Starting ...");
  Serial.println(" ... Setup IR receiver");
  irrecv.enableIRIn(); // Start the IR receiver
  Serial.println("Hob2Hood ready ...");
  
  // Transmitter is connected to Arduino Pin #10  
  mySwitch.enableTransmit(10);
  // Optional set pulse length.
  mySwitch.setPulseLength(300);
  // Optional set number of transmission repetitions.
  mySwitch.setRepeatTransmit(3);

}

// Receive and decode IR commands and control hood upon received command
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); //Show raw data
    switch (results.value) {
      case IRCMD_LIGHT_ON:
        light = 1;
        Serial.println("Hood on");
        mySwitch.send("1011001011001011001011001011001001001011001011011001001");
        delay(1000);  
        break;

      case IRCMD_LIGHT_OFF:
        light = 0;
        Serial.println("LIGHT OFF");
        mySwitch.send("1011001011001011001011001011001001001011001011011011001");
        delay(1000);  
        break;

      case IRCMD_VENT_1:
        ventilation = 1;
        Serial.println("1011001011001011001011001011001011001");
        break;

      case IRCMD_VENT_2:
        //if vent = 1
        //if vent = 3
        //if vent = 4
        ventilation = 2;
        Serial.println("1011001011001011001011001011001011001");
        break;

      case IRCMD_VENT_3:
        ventilation = 3;
        Serial.println("1011001011001011001011001011001011001");
        break;

      case IRCMD_VENT_4:
        ventilation = 4;
        Serial.println("1011001011001011001011001011001011001");
        break;

      case IRCMD_VENT_OFF:
        ventilation = 0;
        Serial.println("vent off > hood off");
        mySwitch.send("1011001011001011001011001011001001001011001011011001001");
        delay(1000);  
        break;

      default:
        break;
    }
        irrecv.resume();
  }
}