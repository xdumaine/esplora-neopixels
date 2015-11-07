int getButtonsState() {
  int buttons = 0;
  if (Esplora.readButton(SWITCH_LEFT) == LOW) {
    buttons |= 1;
  } else if (Esplora.readButton(SWITCH_UP) == LOW) {
    buttons |= 2;
  } else if (Esplora.readButton(SWITCH_RIGHT) == LOW) {
    buttons |= 4;
  } else if (Esplora.readButton(SWITCH_DOWN) == LOW) {
    buttons |= 8;
  }
  return buttons;
}

void setBrightness(Adafruit_NeoPixel &strip) {
  uint8_t brightness = Esplora.readSlider() / 4;
  strip.setBrightness(brightness);
}
