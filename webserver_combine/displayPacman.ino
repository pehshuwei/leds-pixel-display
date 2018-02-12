//PACMAN
//whole pacman
int pacman_whole[] = {2,3,4,5,6,12,13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,72,73,74,75,76,77,78,82,83,84,85,86};
//quater open
int pacman_quateropen[] = {2,3,4,5,6,12,13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,31,32,33,34,36,37,38,39,40,41,42,43,45,46,47,48,51,52,53,54,56,57,58,59,60,61,62,66,67,68,72,73,77,78,82,86};
//half open
int pacman_halfopen[] = {2,3,4,5,6,12,13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,31,32,33,34,36,37,38,39,40,41,42,46,47,48,51,52,53,57,58,59,60,61,67,68,72,78};
//full open
int pacman_fullopen[] = {2,3,4,5,6,12,13,14,15,16,17,18,20,21,22,23,24,25,26,27,28,31,32,33,34,36,37,38,39,40,41,42,46,47,48,51,52,58,59,60,68};

int pm_delay = 100; 
int pm_loop = 5;

//GHOST
//looking left
int eyes_pixels_l[] = {24,26,33,34,35,64,66,73,74,75};
int pupils_pixels_l[] = {25,65};
//looking right
int eyes_pixels_r[] = {24,25,26,33,35,64,65,66,73,75};
int pupils_pixels_r[] = {34,74};
//remove pixels around feet
int void_pixels_1[] = {8,9,10,18,19,20,29,40,41,59,70,78,79,80,89,90,91};
int void_pixels_2[] = {0,8,9,10,20,29,38,39,40,60,61,70,79,89,90,91,99};
//sad_ghost
int sad_ghost[] = {16,24,33,36,44,56,64,66,75,83};

int feet_delay = 120; //delay in ms b/w feet v1 v2
int eye_loop = 10;
int reg_ghost_loop = 2;
int sad_ghost_loop = 10;
int sad_ghost_blink_loop = 5;

//If a POST request is made to URI /pacman
void displayPacman(){
  Serial.println("displayPacman()");
  counter = 30;
  
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  //PACMAN
  for(int i=0; i<pm_loop; i++){
      //whole pacman
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      for(int i=0; i<69; i++){
        leds[pacman_whole[i]] = CRGB::Yellow;
      }
      FastLED.show();
      FastLED.delay(pm_delay);
    
      //pacman_quateropen
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      for(int i=0; i<57; i++){
        leds[pacman_quateropen[i]] = CRGB::Yellow;
      }
      FastLED.show();
      FastLED.delay(pm_delay);
    
      //pacman_halfopen
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      for(int i=0; i<47; i++){
        leds[pacman_halfopen[i]] = CRGB::Yellow;
      }
      FastLED.show();
      FastLED.delay(pm_delay);
    
      //pacman_fullopen
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      for(int i=0; i<41; i++){
        leds[pacman_fullopen[i]] = CRGB::Yellow;
      }
      FastLED.show();
      FastLED.delay(pm_delay);
    
      //pacman_halfopen
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      for(int i=0; i<47; i++){
        leds[pacman_halfopen[i]] = CRGB::Yellow;
      }
      FastLED.show();
      FastLED.delay(pm_delay);
    
      //pacman_quateropen
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      for(int i=0; i<57; i++){
        leds[pacman_quateropen[i]] = CRGB::Yellow;
      }
      FastLED.show();
      FastLED.delay(pm_delay);
    
      //whole pacman
      fill_solid(leds, NUM_LEDS, CRGB::Black);
      for(int i=0; i<69; i++){
        leds[pacman_whole[i]] = CRGB::Yellow;
      }
      FastLED.show();
      FastLED.delay(pm_delay);
  }

  //GHOST
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
          FastLED.delay(feet_delay);

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
          FastLED.delay(feet_delay);
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
          FastLED.delay(feet_delay);
  
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
          FastLED.delay(feet_delay);
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
      FastLED.delay(feet_delay);
     
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
      FastLED.delay(feet_delay);
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
      FastLED.delay(feet_delay);

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
      FastLED.delay(feet_delay);
  }

  server.sendHeader("Location","/");        // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                         // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

