#include "FastLED.h"
#define NUM_LEDS 100
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(70);   FastLED.clear();
}

int p[]={1,2,3,4,5,6,7,8,11,28,31,32,33,34,25,14};
int s[]={68,51,48,47,46,45,54,65,64,63,62,61,58,41,38};
int c[]={91,88,71,72,73,74,75,76,77,78,81,98};

void loop() {
  for(int i=0; i<16; i++){
      leds[p[i]] = CRGB::DarkCyan;
      FastLED.show();
      FastLED.delay(100);
  }
  for(int i=0; i<15; i++){
      leds[s[i]] = CRGB::RoyalBlue;
      FastLED.show();
      FastLED.delay(100);
  }
  for(int i=0; i<12; i++){
      leds[c[i]] = CRGB::SlateBlue;
      FastLED.show();
      FastLED.delay(100);
  }
  FastLED.delay(3000);
  FastLED.clear();
}
