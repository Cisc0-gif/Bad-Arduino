/*
ACTIVE BUZZER AND LED PIN LAYOUT:
ABUZZER       BUTTON     Uno/Nano     MEGA
N/A           5v         5v           5v
GND           GND        GND          GND
+             N/A        D9           D9
N/A           READ       D8           D8
*/
int buzzer = 9;           // the PWM pin the active buzzer is attached to
int volume = 0;    // how bright the buzzer is
int fadeAmount = 5;    // how many points to fade the buzzer by
const int button = 8; //the PWM pin the button is attached to 
int state = 0; //state of button
int val = 0; //state of button
int old_val = 0; //state of button


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(buzzer, OUTPUT);
  //declare pin 8 to be an input:
  pinMode(button, INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the volume of pin 9:
  val = digitalRead(button);
  if ((val==HIGH) && (old_val==LOW)) {
    state = 1 - state;
    delay(5010);
  }

  old_val = val;
  
  if (state==1) {
    analogWrite(buzzer, volume);

    // change the volume for next time through the loop:
    volume = volume + fadeAmount;

    // reverse the direction of the fading at the ends of the fade:
    if (volume <= 0 || volume >= 255) {
    fadeAmount = -fadeAmount;
    }
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  } else {
    analogWrite(buzzer, LOW);
  }
}
