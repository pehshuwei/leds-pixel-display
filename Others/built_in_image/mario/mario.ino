#define FASTLED_ESP8266_RAW_PIN_ORDER
#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
#define NUM_LEDS 100
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(100); //Number 0-255
  FastLED.clear();
  FastLED.setMaxRefreshRate(30);
}

//mario
int m_hat_shirt[]={8,10,11,23,28,29,30,31,36,48,49,50,51,56,68,69,70,71,76,88,91};
int m_hair[]={4,5,6,12,15,25,26,27,32,34,64,67,74,75,84};
int m_bibshort[]={37,38,41,42,43,57,58,61,62,63};
int m_shoe[]={20,39,60,79};
int m_skin_v1[]={13,14,17,24,33,35,44,45,46,47,52,53,54,55,65,66,72,73,82,85,86,94};
int m_skin_v2[]={13,14,16,24,33,35,44,45,46,47,52,53,54,55,65,66,72,73,83,85,86,94};
int mario_delay = 300;

void loop() {
  
  //mario
  //v1
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  for(int i=0;i<21;i++){
    leds[m_hat_shirt[i]] = CRGB::Red;
  }
  for(int i=0;i<15;i++){
    leds[m_hair[i]] = CRGB::Black;
  }
  for(int i=0;i<10;i++){
    leds[m_bibshort[i]] = CRGB::SkyBlue;
  }
  for(int i=0;i<4;i++){
    leds[m_shoe[i]] = CRGB::SaddleBrown;
  }
  for(int i=0;i<22;i++){
    leds[m_skin_v1[i]] = CRGB::LightSalmon;
  }
  FastLED.show();
  FastLED.delay(mario_delay);

  //v2
  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  for(int i=0;i<21;i++){
    leds[m_hat_shirt[i]] = CRGB::Red;
  }
  for(int i=0;i<15;i++){
    leds[m_hair[i]] = CRGB::Black;
  }
  for(int i=0;i<10;i++){
    leds[m_bibshort[i]] = CRGB::SkyBlue;
  }
  for(int i=0;i<4;i++){
    leds[m_shoe[i]] = CRGB::SaddleBrown;
  }
  for(int i=0;i<22;i++){
    leds[m_skin_v2[i]] = CRGB::LightSalmon;
  }
  FastLED.show();
  FastLED.delay(mario_delay);
  

}
