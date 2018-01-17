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

//quest
int quest_background[]={0,1,8,9,10,19,80,89,90,91,98,99};
int quest_shadow[]={13,14,15,16,17,21,31,38,41,48,51,58,61,68,71,78,82,83,84,85,86,87};
int quest_fill[]={22,23,24,25,26,27,32,34,35,36,37,42,43,44,45,46,53,56,62,63,64,66,72,74,75,76,77};
int quest_mark[]={12,28,33,47,52,54,55,57,65,67,73};

void loop() {
  //quest
  fill_solid(leds, NUM_LEDS, CRGB::SaddleBrown);
  for(int i=0; i<12; i++){
    leds[quest_background[i]] = CRGB::Blue;
  }
  for(int i=0; i<22; i++){
    leds[quest_shadow[i]] = CRGB::Orange;
  }
  for(int i=0; i<27; i++){
    leds[quest_fill[i]] = CRGB::Yellow;
  }
  for(int i=0; i<11; i++){
    leds[quest_mark[i]] = CRGB::White;
  }
  FastLED.show();
  FastLED.delay(300);
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
  FastLED.delay(200);
}
