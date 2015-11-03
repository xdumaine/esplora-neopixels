/*
  Esplora controller for Neopixels strip using sensors and inputs
  to change strip colors and brightness for use on a motorcycle
*/

#include <Adafruit_NeoPixel.h>
#include <Esplora.h>

#define PIN     11
#define N_LEDS  30

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int motorcycleOrangeRed = 255;
int motorcycleOrangeGreen = 43;
int motorcycleOrangeBlue = 0;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  
  strip.begin();
  strip.show();
  strip.setBrightness(64);
}

void loop() {
  int ambientLight = Esplora.readLightSensor();
  if (ambientLight > 1023) {
    strip.setBrightness(0);
  } else {
    int xAxis = Esplora.readAccelerometer(X_AXIS);
    int yAxis = Esplora.readAccelerometer(Y_AXIS);
    int zAxis = Esplora.readAccelerometer(Z_AXIS);
    for(int i = 0; i < N_LEDS; i++) {
      strip.setPixelColor(i, xAxis, yAxis, zAxis);
    }
    int brightness = Esplora.readMicrophone()/4;
    strip.setBrightness(32);
  }
  strip.show();

  // add a delay to keep the LED from flickering:
  delay(10);
}
