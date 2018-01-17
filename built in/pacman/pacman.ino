#include "FastLED.h"
#define NUM_LEDS 100
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(100); 
  FastLED.clear();
}

//whole pacman
int pacman_whole[] = {2,3,4,5,6,12,13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,72,73,74,75,76,77,78,82,83,84,85,86};

//quater open
int pacman_quateropen[] = {2,3,4,5,6,12,13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,31,32,33,34,36,37,38,39,40,41,42,43,45,46,47,48,51,52,53,54,56,57,58,59,60,61,62,66,67,68,72,73,77,78,82,86};

//half open
int pacman_halfopen[] = {2,3,4,5,6,12,13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,31,32,33,34,36,37,38,39,40,41,42,46,47,48,51,52,53,57,58,59,60,61,67,68,72,78};

//full open
int pacman_fullopen[] = {2,3,4,5,6,12,13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,31,32,33,34,36,37,38,39,40,41,42,46,47,48,51,52,58,59,60,68};

int pm_delay = 100; 

void loop() {

  //whole pacman
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<69; i++){
    leds[pacman_whole[i]] = CRGB::Yellow;
  }
  FastLED.show();
  delay(pm_delay);

  //pacman_quateropen
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<57; i++){
    leds[pacman_quateropen[i]] = CRGB::Yellow;
  }
  FastLED.show();
  delay(pm_delay);

  //pacman_halfopen
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<47; i++){
    leds[pacman_halfopen[i]] = CRGB::Yellow;
  }
  FastLED.show();
  delay(pm_delay);

  //pacman_fullopen
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<41; i++){
    leds[pacman_fullopen[i]] = CRGB::Yellow;
  }
  FastLED.show();
  delay(pm_delay);

  //pacman_halfopen
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<47; i++){
    leds[pacman_halfopen[i]] = CRGB::Yellow;
  }
  FastLED.show();
  delay(pm_delay);

  //pacman_quateropen
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<57; i++){
    leds[pacman_quateropen[i]] = CRGB::Yellow;
  }
  FastLED.show();
  delay(pm_delay);

  //whole pacman
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<69; i++){
    leds[pacman_whole[i]] = CRGB::Yellow;
  }
  FastLED.show();
  delay(pm_delay);
  
}

