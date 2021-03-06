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

void startShow() {
  int buttons = getButtonsState();
  if (buttons == 0) {
    buttons = mode;
  }
  switch (buttons) {
    case 1: // left
      if (mode == buttons) {
        return;
      }
      colorWipe(strip1, KTM_ORANGE, 50);
      break;
    case 2: // up
      if (mode == buttons) {
        return;
      }
      colorWipe(strip1, KTM_BLACK, 50);
      break;
    case 4: // right
      if (mode == buttons) {
        return;
      }
      colorWipe(strip1, BLUE, 50);
      break;
    case 8: // down
      rainbowCycle(strip1, 1);
      break;
    case 3: // left, up
      colorWipe(strip1, (RGB){0, 255, 0}, 50);
      break;
  }
  mode = buttons;
}

void loop() {
  setBrightness(strip1);
  setBrightness(strip2);
  startShow();
}
