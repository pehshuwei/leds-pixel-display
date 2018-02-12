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

//row
int r1[]={9,10,29,30,49,50,69,70,89,90};
int r2[]={8,11,28,31,48,51,68,71,88,91};
int r3[]={7,12,27,32,47,52,67,72,87,92};
int r4[]={6,13,26,33,46,53,66,73,86,93};
int r5[]={5,14,25,34,45,54,65,74,85,94};
int r6[]={4,15,24,35,44,55,64,75,84,95};
int r7[]={3,16,23,36,43,56,63,76,83,96};
int r8[]={2,17,22,37,42,57,62,77,82,97};
int r9[]={1,18,21,38,41,58,61,78,81,98};
int r10[]={0,19,20,39,40,59,60,79,80,99};
int rowbyrow_delay = 100;

void loop() {

    //fill
//  fill_solid(leds, NUM_LEDS, CRGB::White);

  //row
  for (int i = 0; i < 10; i++){
      leds[r1[i]] = CRGB::DarkCyan;
  }
  FastLED.show();
  FastLED.delay(rowbyrow_delay);
  for (int i = 0; i < 10; i++){
      leds[r2[i]] = CRGB::Aqua;
  }
  FastLED.show();
  FastLED.delay(rowbyrow_delay);
  for (int i = 0; i < 10; i++){
      leds[r3[i]] = CRGB::Aquamarine;
  }
  FastLED.show();
  FastLED.delay(rowbyrow_delay);
  for (int i = 0; i < 10; i++){
      leds[r4[i]] = CRGB::SlateGray;
  }
  FastLED.show();
  FastLED.delay(rowbyrow_delay);
  for (int i = 0; i < 10; i++){
      leds[r5[i]] = CRGB::Yellow;
  }
  FastLED.show();
  FastLED.delay(rowbyrow_delay);
  for (int i = 0; i < 10; i++){
      leds[r6[i]] = CRGB::SlateGray;
  }
  FastLED.show();
  FastLED.delay(rowbyrow_delay);
  for (int i = 0; i < 10; i++){
      leds[r7[i]] = CRGB::LightSalmon;
  }
  FastLED.show();
  FastLED.delay(rowbyrow_delay);
  for (int i = 0; i < 10; i++){
      leds[r8[i]] = CRGB::SlateGray;
  }
  FastLED.show();
  FastLED.delay(rowbyrow_delay);
  for (int i = 0; i < 10; i++){
      leds[r9[i]] = CRGB::Red;
  }
  FastLED.show();
  FastLED.delay(rowbyrow_delay);
  for (int i = 0; i < 10; i++){
      leds[r10[i]] = CRGB::SlateGray;
  }
  FastLED.show();
  FastLED.delay(2000);
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  FastLED.show();
}
