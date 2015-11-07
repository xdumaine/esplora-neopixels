/*
  Esplora controller for Neopixels strip using sensors and inputs
  to change strip colors and brightness for use on a motorcycle
*/

#include <Adafruit_NeoPixel.h>
#include <Esplora.h>

#include "definitions.h"
#include "board_controls.h"
#include "color_effects.h"


void setup() {
  // initialize the serial communication:
  Serial.begin(9600);

  strip1.begin();
  strip1.show();
  strip1.setBrightness(64);
}

void startShow(int i) {
  int buttons = getButtonsState();
  if ((buttons & 1) == 1) {
    colorWipe(strip1, KTM_ORANGE, 50);
  } else if ((buttons & 2) == 2) {
    colorWipe(strip1, KTM_BLACK, 50);
  } else if ((buttons & 4) == 4) {
    colorWipe(strip1, BLUE, 50);
  } else if ((buttons & 8) == 8) {
    rainbowCycle(strip1, 2);
  }
  Serial.print((buttons & 1) == 1);
  Serial.print(", ");
  Serial.print((buttons & 2) == 2);
  Serial.print(", ");
  Serial.print((buttons & 4) == 4);
  Serial.print(", ");
  Serial.print((buttons & 8) == 8);
  Serial.println("-----");
}

void loop() {
  setBrightness(strip1);
  setBrightness(strip2);
  startShow(mode);
}

