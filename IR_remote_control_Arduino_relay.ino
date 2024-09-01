#include <IRremote.h>

// Define constants
const int switchPins[] = {7, 8, 9, 10};
const int numSwitches = sizeof(switchPins) / sizeof(switchPins[0]);
int toggleStates[numSwitches] = {0, 0, 0, 0}; // Toggle states for each switch

int RECV_PIN = 11;

// Define IR receiver and Result Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Enable the IR receiver
  
  for (int i = 0; i < numSwitches; i++) {
    pinMode(switchPins[i], OUTPUT);
  }
}

void loop() {
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0x10EFA956: toggleSwitch(0); break; // Hex code for TV remote button 1
      case 0x10EF9966: toggleSwitch(1); break; // Hex code for TV remote button 2
      case 0x10EFB946: toggleSwitch(2); break; // Hex code for TV remote button 3
      case 0x10EF6B94: toggleSwitch(3); break; // Hex code for TV remote button 4
      default: break;
    }

    irrecv.resume(); // Receive the next value
  }
}

void toggleSwitch(int index) {
  toggleStates[index] = !toggleStates[index]; // Toggle the state
  digitalWrite(switchPins[index], toggleStates[index] ? HIGH : LOW); // Set the switch
  delay(100);
}