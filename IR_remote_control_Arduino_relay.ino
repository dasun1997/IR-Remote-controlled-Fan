#include <IRremote.h>
//Define PIN constant
const int switch_1 = 7;
const int switch_2 = 8;
const int switch_3 = 9;
const int switch_4 = 10;
int RECV_PIN = 11;

int toggleState_1 = 0; //Define integer to remember the toggle state for switch 1
int toggleState_2 = 0; //Define integer to remember the toggle state for switch 2
int toggleState_3 = 0; //Define integer to remember the toggle state for switch 3
int toggleState_4 = 0; //Define integer to remember the toggle state for switch 4


//Define IR receiver and Result Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Enable the IR receiver
   pinMode(switch_1, OUTPUT);
   pinMode(switch_2, OUTPUT);
   pinMode(switch_3, OUTPUT);
   pinMode(switch_4, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {

    switch(results.value){
      case 0x10EFA956:        // 10EFA956 = Hex code for TV remote button 1 
                if(toggleState_1 == 0){
                  digitalWrite(switch_1, HIGH); // turn on switch 1
                  toggleState_1 = 1;
                  }
                else{
                  digitalWrite(switch_1, LOW); // turn off switch 1
                  toggleState_1 = 0;
                  }
                  delay(100);
      break;
      case 0x10EF9966:          // 10EF9966 = Hex code for TV remote button 2 
                if(toggleState_2 == 0){
                  digitalWrite(switch_2, HIGH); // turn on switch 2
                  toggleState_2 = 1;
                  }
                else{
                  digitalWrite(switch_2, LOW); // turn off switch 2
                  toggleState_2 = 0;
                  }
                  delay(100);
      break;
      case 0x10EFB946: 
                if(toggleState_3 == 0){
                  digitalWrite(switch_3, HIGH); // turn on switch 3
                  toggleState_3 = 1;
                  }
                else{
                  digitalWrite(switch_3, LOW); // turn off switch 3
                  toggleState_3 = 0;
                  }
                  delay(100);
      break;
      case 0x10EF6B94: 
                if(toggleState_4 == 0){
                  digitalWrite(switch_4, HIGH); // turn on switch 4
                  toggleState_4 = 1;
                  }
                else{
                  digitalWrite(switch_4, LOW); // turn off switch 4
                  toggleState_4 = 0;
                  }
                  delay(100);
      break;
      default : break;      
      }
    
    irrecv.resume(); // Receive the next value
  }
  
}
