#include <IRremote.h>

const int switch_1 = 7;
const int switch_2 = 8;
const int switch_3 = 9;
const int switch_4 = 10;
const int mosfet_1 = 3;
const int mosfet_2 = 4;

int RECV_PIN = 11;

int toggleState_1 = 0;
int toggleState_2 = 0;
int toggleState_3 = 0;
int toggleState_4 = 0;
int pwmValue_1 = 0;
int pwmValue_2 = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(switch_1, OUTPUT);
  pinMode(switch_2, OUTPUT);
  pinMode(switch_3, OUTPUT);
  pinMode(switch_4, OUTPUT);
  pinMode(mosfet_1, OUTPUT);
  pinMode(mosfet_2, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {

    switch (results.value) {
      case 0x10EFA956:
        if (toggleState_1 == 0) {
          digitalWrite(switch_1, HIGH);
          toggleState_1 = 1;
        }
        else {
          digitalWrite(switch_1, LOW);
          toggleState_1 = 0;
        }
        delay(100);
        break;
      case 0x10EF9966:
        if (toggleState_2 == 0) {
          digitalWrite(switch_2, HIGH);
          toggleState_2 = 1;
        }
        else {
          digitalWrite(switch_2, LOW);
          toggleState_2 = 0;
        }
        delay(100);
        break;
      case 0x10EFB946:
        if (toggleState_3 == 0) {
          digitalWrite(switch_3, HIGH);
          toggleState_3 = 1;
        }
        else {
          digitalWrite(switch_3, LOW);
          toggleState_3 = 0;
        }
        delay(100);
        break;
      case 0x10EF6B94:
        if (toggleState_4 == 0) {
          digitalWrite(switch_4, HIGH);
          toggleState_4 = 1;
        }
        else {
          digitalWrite(switch_4, LOW);
          toggleState_4 = 0;
        }
        delay(100);
        break;
      case 0x10EFD22D: // Example IR remote signal for volume up
        if (pwmValue_1 < 255) {
          pwmValue_1 += 25;
        }
        analogWrite(mosfet_1, pwmValue_1);
        delay(100);
        break;
      case 0x10EF629D: // Example IR remote signal for volume down
        if (pwmValue_1 > 0) {
          pwmValue_1 -= 25;
        }
        analogWrite(mosfet_1, pwmValue_1);
        delay(100);
        break;
      // Add more cases for other IR remote signals to control different MOSFETs or PWM values

      default:
        break;
    }

    irrecv.resume();
  }
}
