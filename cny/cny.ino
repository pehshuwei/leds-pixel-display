#include <FastLED.h>
#include <LEDMatrix.h>
#include <LEDText.h>
#include <FontMatrise.h>

#define LED_PIN        3
#define COLOR_ORDER    RGB
#define CHIPSET        WS2811

#define MATRIX_WIDTH   10
#define MATRIX_HEIGHT  10
#define MATRIX_TYPE    VERTICAL_ZIGZAG_MATRIX

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;
cLEDText ScrollingMsg;

const unsigned char TxtDemo[] = { EFFECT_HSV_CV "\x00\xff\xff\x40\xff\xff" "  HAPPY CHINESE NEW YEAR"
                                  EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff" " - PSC"};


void setup() {
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.setBrightness(100);
  FastLED.clear(true);
  delay(500);
  
  ScrollingMsg.SetFont(MatriseFontData);
  ScrollingMsg.Init(&leds, leds.Width(), ScrollingMsg.FontHeight() + 1, 0, 1);
  ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
}

void loop() {
  if (ScrollingMsg.UpdateText() == -1)
    ScrollingMsg.SetText((unsigned char *)TxtDemo, sizeof(TxtDemo) - 1);
  else
    FastLED.show();
  delay(100);
}
