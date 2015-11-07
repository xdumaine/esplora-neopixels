struct RGB {
  byte r;
  byte g;
  byte b;
};

RGB KTM_ORANGE = { 255, 42, 0 };
RGB KTM_BLACK = { 0, 0, 0 };
RGB BLUE = { 0, 0, 255 };

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t wheelColor(Adafruit_NeoPixel &strip, byte wheelPos) {
  wheelPos = 255 - wheelPos;
  if(wheelPos < 85) {
    return strip.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  if(wheelPos < 170) {
    wheelPos -= 85;
    return strip.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
  wheelPos -= 170;
  return strip.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
}

// Fill the dots one after the other with a color
void colorWipe(Adafruit_NeoPixel &strip, RGB rgb, uint8_t wait) {
  for(uint16_t i=0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, rgb.r, rgb.g, rgb.b);
    strip.show();
    delay(wait);
  }
}

void colorSet(Adafruit_NeoPixel &strip, RGB rgb) {
  for(uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, rgb.r, rgb.g, rgb.b);
  }
  strip.show();
  delay(10);
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(Adafruit_NeoPixel &strip, uint8_t wait) {
  uint16_t i, j;

  for(j = 0; j < 256*5; j++) { // 5 cycles of all colors on wheel
    for(i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, wheelColor(strip, ((i * 256 / strip.numPixels()) + j) & 255));
      
    }
    strip.show();
    delay(wait);
  }
}


