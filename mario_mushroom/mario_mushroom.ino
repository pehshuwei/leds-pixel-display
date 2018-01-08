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

//mushroom
int mr_head[]={4,7,11,12,15,24,25,26,27,29,30,32,33,34,35,44,47,48,49,52,55,64,65,66,67,69,70,71,72,73,74,75,84,87,88,92,95};
int mr_dot[]={5,6,13,14,28,31,45,46,50,51,53,54,68,85,86,93,94};
int mr_body_v1[]={16,17,18,20,21,22,23,38,39,40,41,42,43,56,57,58,59,60,61,76,77,78,79,81,82,83};
int mr_body_v2[]={16,17,18,20,21,22,23,36,38,39,40,41,42,43,56,57,58,59,60,61,63,76,77,78,79,81,82,83};
int mr_eye_v1[]={36,37,62,63};
int mr_eye_v2[]={37,62};
int mushroom_delay = 200;


void loop() {
  //mushroom
  //v1
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  for(int i=0;i<37;i++){
    leds[mr_head[i]] = CRGB::Red;
  }
  for(int i=0;i<17;i++){
    leds[mr_dot[i]] = CRGB::White;
  }
  for(int i=0;i<26;i++){
    leds[mr_body_v1[i]] = CRGB::LightSalmon;
  }
  for(int i=0;i<4;i++){
    leds[mr_eye_v1[i]] = CRGB::Black;
  }
  FastLED.show();
  FastLED.delay(mushroom_delay);

  //v2
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  for(int i=0;i<37;i++){
    leds[mr_head[i]] = CRGB::Red;
  }
  for(int i=0;i<17;i++){
    leds[mr_dot[i]] = CRGB::White;
  }
  for(int i=0;i<28;i++){
    leds[mr_body_v2[i]] = CRGB::LightSalmon;
  }
  for(int i=0;i<2;i++){
    leds[mr_eye_v2[i]] = CRGB::Black;
  }
  FastLED.show();
  FastLED.delay(mushroom_delay);

}
