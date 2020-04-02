/*
RGB LAYOUT:
RGB_LED     Uno/Nano    MEGA
RED         D11         D13 
GND         GND         GND
GREEN       D10         D12
BLUE        D9          D11

NOTE: Remeber to use resistors on RGB wiring to prevent a burn out
*/

int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

int red_light_two = 6;
int green_light_two = 5;
int blue_light_two = 3;

void setup() {
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
  pinMode(red_light_two, OUTPUT);
  pinMode(green_light_two, OUTPUT);
  pinMode(blue_light_two, OUTPUT);
}

void loop() {
  /*
  RGB_color(255, 0, 0); // Red
  delay(2000);
  RGB_color(0, 255, 0); // Green
  delay(2000);
  RGB_color(0, 0, 255); // Blue
  delay(2000);
  RGB_color(255, 255, 125); // Raspberry
  delay(2000);
  RGB_color(0, 255, 255); // Cyan
  delay(2000);
  */
  RGB_color_two(255, 0, 255);
  RGB_color(255, 0, 255); // Magenta
  delay(1000);
  /*
  RGB_color(255, 255, 0); // Yellow
  delay(2000);
  RGB_color(255, 255, 255); // White
  delay(2000);
  */
}

void RGB_color_two(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_two, red_light_value);
  analogWrite(green_light_two, green_light_value);
  analogWrite(blue_light_two, blue_light_value);
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
