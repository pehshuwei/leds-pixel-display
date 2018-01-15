#include "FastLED.h"
#define NUM_LEDS 100
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(70); //Number 0-255
  FastLED.clear();
}

//coin
int coin_background[]={0,1,8,9,10,19,80,89,90,91,98,99};
int coin_shining[]={12,13,14,15,16,17,28,31,33,34,35,36,46,48,51,53,68,71};
int coin_fill[]={21,22,23,24,25,26,27,32,38,41,43,44,45,47,52,54,55,56,58,61,67,72,73,74,75,76,77,78,82,83,84,85,86,87};
int coin_delay = 400;
int coin_blink = 300;

void loop() {

  //coin
  fill_solid(leds, NUM_LEDS, CRGB::DarkOrange);
  for(int i=0; i<12; i++){
    leds[coin_background[i]] = CRGB::Blue;
  }
  for(int i=0; i<18; i++){
    leds[coin_shining[i]] = CRGB::LemonChiffon;
  }
  for(int i=0; i<34; i++){
    leds[coin_fill[i]] = CRGB::Gold;
  }
  FastLED.show();
  FastLED.delay(coin_delay);
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
  FastLED.delay(coin_blink);
}
