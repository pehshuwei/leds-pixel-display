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

//flower
int flower_petal_v1[]={7,11,13,25,29,30,34,45,49,50,54,65,69,71,73,87};
int flower_petal_v2[]={12,26,28,30,34,45,49,50,54,65,69,70,74,86,88,92};
int flower_middle_v1[]={12,26,28,31,33,46,48,51,53,66,68,72};
int flower_middle_v2[]={27,31,33,46,48,51,53,66,68,71,73,87};
int flower_center_v1[]={27,47,67};
int flower_center_v2[]={32,52,72};
int flower_eye_v1[]={32,52};
int flower_eye_v2[]={47,67};
int flower_leaf_v1[]={2,17,18,20,21,39,40,41,42,43,44,59,60,61,62,76,77,78,83};
int flower_leaf_v2[]={3,16,17,18,20,21,22,39,40,41,42,56,59,60,61,64,77,78,82};

void loop() {
  //flower
  //v1
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  for(int i=0; i<16; i++){
    leds[flower_petal_v1[i]] = CRGB::Red;
  }
  for(int i=0; i<12; i++){
    leds[flower_middle_v1[i]] = CRGB::Yellow;
  }
  for(int i=0; i<3; i++){
    leds[flower_center_v1[i]] = CRGB::White;
  }
  for(int i=0; i<2; i++){
    leds[flower_eye_v1[i]] = CRGB::Black;
  }
  for(int i=0; i<19; i++){
    leds[flower_leaf_v1[i]] = CRGB::SpringGreen;
  }
  FastLED.show();
  FastLED.delay(300);

  //v2
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  for(int i=0; i<16; i++){
    leds[flower_petal_v2[i]] = CRGB::Red;
  }
  for(int i=0; i<12; i++){
    leds[flower_middle_v2[i]] = CRGB::Yellow;
  }
  for(int i=0; i<3; i++){
    leds[flower_center_v2[i]] = CRGB::White;
  }
  for(int i=0; i<2; i++){
    leds[flower_eye_v2[i]] = CRGB::Black;
  }
  for(int i=0; i<19; i++){
    leds[flower_leaf_v2[i]] = CRGB::SpringGreen;
  }
  FastLED.show();
  FastLED.delay(300);
}
