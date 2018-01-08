#include "FastLED.h"
#define NUM_LEDS 100
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(70);
  FastLED.clear();
}

//star
int star_fill[]={4,14,15,16,20,21,22,23,24,25,32,33,34,37,38,42,43,44,45,46,47,48,52,53,54,57,58,60,61,62,63,64,65,74,75,76,84};
int star_eye[]={35,36,55,56};

void loop() {
  //quest
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  for(int i=0;i<20;i++){
    leds[rand()%99+0] = CRGB::White;
  }
  for(int i=0; i<37; i++){
    leds[star_fill[i]] = CRGB::Yellow;
  }
  for(int i=0; i<4; i++){
    leds[star_eye[i]] = CRGB::Orange;
  }
  FastLED.show();
  FastLED.delay(300);
}
