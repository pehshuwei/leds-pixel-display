#include "FastLED.h"
#define NUM_LEDS 100
#define DATA_PIN 3

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(255); //Number 0-255
  FastLED.clear();
}

//looking left
int eyes_pixels_l[] = {24,26,33,34,35,64,66,73,74,75};
int pupils_pixels_l[] = {25,65};

//looking right
int eyes_pixels_r[] = {24,25,26,33,35,64,65,66,73,75};
int pupils_pixels_r[] = {34,74};

//remove pixels around feet
int void_pixels_1[] = {8,9,10,18,19,20,29,40,41,59,70,78,79,80,89,90,91};
int void_pixels_2[] = {0,8,9,10,20,29,38,39,40,60,61,70,79,89,90,91,99};

int sad_ghost[] = {16,24,33,36,44,56,64,66,75,83};

int feet_delay = 120; //delay in ms b/w feet v1 v2
int eye_loop = 10;
int reg_ghost_loop = 2;
int sad_ghost_loop = 10;
int sad_ghost_blink_loop = 5;

void loop() {

    for(int i = 0; i < reg_ghost_loop; i++){

        //eye to left
        for(int i = 0; i < eye_loop; i++){

            //fill body
            fill_solid(leds, NUM_LEDS, CRGB::Red);
            //set eyes 
            for (int i = 0; i < 10; i++){
                leds[eyes_pixels_l[i]] = CRGB::White;
            }
            //set pupil
            for (int i = 0; i < 2; i++){
                leds[pupils_pixels_l[i]] = CRGB::DarkBlue;
            }
            //remove around feet (v1)
            for (int i = 0; i < 17; i++){
                leds[void_pixels_1[i]] = CRGB::Black;
            }
            FastLED.show();
            delay(feet_delay);

            //fill body
            fill_solid(leds, NUM_LEDS, CRGB::Red);
            //set eyes
            for (int i = 0; i < 10; i++){
                leds[eyes_pixels_l[i]] = CRGB::White;
            }
            //set pupils
            for (int i = 0; i < 2; i++){
                leds[pupils_pixels_l[i]] = CRGB::DarkBlue;
            }
            //remove around feet (v2)
            for (int i = 0; i < 17; i++){
                leds[void_pixels_2[i]] = CRGB::Black;
            }
            FastLED.show();
            delay(feet_delay);
        }

        //eye to right
        for(int i = 0; i < eye_loop; i++){
            
            //fill body
            fill_solid(leds, NUM_LEDS, CRGB::Red);
            //set eyes
            for (int i = 0; i < 10; i++){
                leds[eyes_pixels_r[i]] = CRGB::White;
            }
            //set pupils
            for (int i = 0; i < 2; i++){
                leds[pupils_pixels_r[i]] = CRGB::DarkBlue;
            }
            //remove around feet (v1)
            for (int i = 0; i < 17; i++){
                leds[void_pixels_1[i]] = CRGB::Black;
            }
            FastLED.show();
            delay(feet_delay);
    
            //fill body
            fill_solid(leds, NUM_LEDS, CRGB::Red);
            //set eyes
            for (int i = 0; i < 10; i++){
                leds[eyes_pixels_r[i]] = CRGB::White;
            }
            //set pupils 
            for (int i = 0; i < 2; i++){
                leds[pupils_pixels_r[i]] = CRGB::DarkBlue;
            }
            //remove around feet (v2)
            for (int i = 0; i < 17; i++){
                leds[void_pixels_2[i]] = CRGB::Black;
            }
            FastLED.show();
            delay(feet_delay);
        }
    }

    //sad ghost regular
    for(int i = 0; i < sad_ghost_loop; i++){

        //fill all blue
        fill_solid(leds, NUM_LEDS, CRGB::Blue);
        //set eyes
        for (int i = 0; i < 10; i++){
            leds[sad_ghost[i]] = CRGB::Yellow;
        }
        //remove around feet (v1)
        for (int i = 0; i < 17; i++){
            leds[void_pixels_1[i]] = CRGB::Black;
        }
        FastLED.show();
        delay(feet_delay);
       
        //fill body
        fill_solid(leds, NUM_LEDS, CRGB::Blue);
        //set eyes 
        for (int i = 0; i < 10; i++){
            leds[sad_ghost[i]] = CRGB::Yellow;
        }
        //remove around feet (v2)
        for (int i = 0; i < 17; i++){
            leds[void_pixels_2[i]] = CRGB::Black;
        }
        FastLED.show();
        delay(feet_delay);
    }

    //sad ghost blinking
    for(int i = 0; i < sad_ghost_blink_loop; i++){

        //yellow and red ghost
        //fill body
        fill_solid(leds, NUM_LEDS, CRGB::White);
        //set eyes
        for (int i = 0; i < 10; i++){
            leds[sad_ghost[i]] = CRGB::Red;
        }
        //remove around feet (v1)
        for (int i = 0; i < 17; i++){
            leds[void_pixels_1[i]] = CRGB::Black;
        }
        FastLED.show();
        delay(feet_delay);

        //blue and yellow ghost
        //fill body
        fill_solid(leds, NUM_LEDS, CRGB::Blue);
        //set eyes
        for (int i = 0; i < 10; i++){
            leds[sad_ghost[i]] = CRGB::Yellow;
        }
        //remove around feet (v2)
        for (int i = 0; i < 17; i++){
            leds[void_pixels_2[i]] = CRGB::Black;
        }
        FastLED.show();
        delay(feet_delay);
    }
}
