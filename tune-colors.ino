/*
  Esplora controller for Neopixels strip using sensors and inputs
  to change strip colors and brightness for use on a motorcycle
*/

#include <Adafruit_NeoPixel.h>
#include <Esplora.h>

#define PIN     11
#define N_LEDS  30

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  
  strip.begin();
  strip.show();
  strip.setBrightness(64);
}

int red, blue, green, brightness, mode;

void loop() {
  if (Esplora.readButton(SWITCH_LEFT) == LOW) {
    mode = 0;
  } else if (Esplora.readButton(SWITCH_UP) == LOW) {
    mode = 1;
  } else if (Esplora.readButton(SWITCH_RIGHT) == LOW) {
    mode = 2;
  } else {
    mode = 3;
  }
  int value = Esplora.readSlider() / 4;
  switch(mode) {
    case 0:
      red = value;
      break;
    case 1:
      blue = value;
      break;
    case 2:
      green = value;
      break;
    case 3: 
      brightness = value;
      break;
    default:
      return;
  }
  strip.setBrightness(brightness);
  for(int i = 0; i < N_LEDS; i++) {
    strip.setPixelColor(i, red, blue, green);
  }
  strip.show();
  Serial.print(red + ", " + blue + ", " + green);

  // add a delay to keep the LED from flickering:
  delay(10);
}
