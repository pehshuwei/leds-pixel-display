//general
int gloop = 6;
int gdelay = 300;
int sloop = 4;

//coin
//int coin_background[]={0,1,8,9,10,19,80,89,90,91,98,99};
//int coin_shining[]={12,13,14,15,16,17,28,31,33,34,35,36,46,48,51,53,68,71};
//int coin_fill[]={21,22,23,24,25,26,27,32,38,41,43,44,45,47,52,54,55,56,58,61,67,72,73,74,75,76,77,78,82,83,84,85,86,87};

//mario
int m_hat_shirt[]={8,10,11,23,28,29,30,31,36,48,49,50,51,56,68,69,70,71,76,88,91};
int m_hair[]={4,5,6,12,15,25,26,27,32,34,64,67,74,75,84};
int m_bibshort[]={37,38,41,42,43,57,58,61,62,63};
int m_shoe[]={20,39,60,79};
int m_skin_v1[]={13,14,17,24,33,35,44,45,46,47,52,53,54,55,65,66,72,73,82,85,86,94};
int m_skin_v2[]={13,14,16,24,33,35,44,45,46,47,52,53,54,55,65,66,72,73,83,85,86,94};

//quest
//int quest_background[]={0,1,8,9,10,19,80,89,90,91,98,99};
//int quest_shadow[]={13,14,15,16,17,21,31,38,41,48,51,58,61,68,71,78,82,83,84,85,86,87};
//int quest_fill[]={22,23,24,25,26,27,32,34,35,36,37,42,43,44,45,46,53,56,62,63,64,66,72,74,75,76,77};
//int quest_mark[]={12,28,33,47,52,54,55,57,65,67,73};

//mushroom
int mr_head[]={4,7,11,12,15,24,25,26,27,29,30,32,33,34,35,44,47,48,49,52,55,64,65,66,67,69,70,71,72,73,74,75,84,87,88,92,95};
int mr_dot[]={5,6,13,14,28,31,45,46,50,51,53,54,68,85,86,93,94};
int mr_body_v1[]={16,17,18,20,21,22,23,38,39,40,41,42,43,56,57,58,59,60,61,76,77,78,79,81,82,83};
int mr_body_v2[]={16,17,18,20,21,22,23,36,38,39,40,41,42,43,56,57,58,59,60,61,63,76,77,78,79,81,82,83};
int mr_eye_v1[]={36,37,62,63};
int mr_eye_v2[]={37,62};

//star
//int star_fill[]={4,14,15,16,20,21,22,23,24,25,32,33,34,37,38,42,43,44,45,46,47,48,52,53,54,57,58,60,61,62,63,64,65,74,75,76,84};
//int star_eye[]={35,36,55,56};
//int star_loop = 10;

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

//If a POST request is made to URI /mario
void displayMario() {
  Serial.println("displayMario()");
  counter = 30;
  
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  //coin
//  for(int i=0;i<sloop;i++){
//      fill_solid(leds, NUM_LEDS, CRGB::DarkOrange);
//      for(int i=0; i<12; i++){
//        leds[coin_background[i]] = CRGB::Blue;
//      }
//      for(int i=0; i<18; i++){
//        leds[coin_shining[i]] = CRGB::LemonChiffon;
//      }
//      for(int i=0; i<34; i++){
//        leds[coin_fill[i]] = CRGB::Gold;
//      }
//      FastLED.show();
//      FastLED.delay(gdelay);
//      fill_solid(leds, NUM_LEDS, CRGB::Blue);
//      FastLED.show();
//      FastLED.delay(gdelay);
//  }
  
  //mario
  for(int i=0;i<gloop;i++){
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
      FastLED.delay(gdelay);
    
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
      FastLED.delay(gdelay);
  }

  //quest
//  for(int i=0;i<sloop;i++){
//      fill_solid(leds, NUM_LEDS, CRGB::SaddleBrown);
//      for(int i=0; i<12; i++){
//        leds[quest_background[i]] = CRGB::Blue;
//      }
//      for(int i=0; i<22; i++){
//        leds[quest_shadow[i]] = CRGB::Orange;
//      }
//      for(int i=0; i<27; i++){
//        leds[quest_fill[i]] = CRGB::Yellow;
//      }
//      for(int i=0; i<11; i++){
//        leds[quest_mark[i]] = CRGB::White;
//      }
//      FastLED.show();
//      FastLED.delay(gdelay);
//      fill_solid(leds, NUM_LEDS, CRGB::Blue);
//      FastLED.show();
//      FastLED.delay(gdelay);
//  }

  //mushroom
  for(int i=0;i<gloop;i++){
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
      FastLED.delay(gdelay);
    
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
      FastLED.delay(gdelay);
  }

  //star
//  for(int i=0; i<star_loop; i++){
//      fill_solid(leds, NUM_LEDS, CRGB::Blue);
//      for(int i=0; i<20; i++){
//        leds[rand()%99+0] = CRGB::White;
//      }
//      for(int i=0; i<37; i++){
//        leds[star_fill[i]] = CRGB::Yellow;
//      }
//      for(int i=0; i<4; i++){
//        leds[star_eye[i]] = CRGB::Orange;
//      }
//      FastLED.show();
//      FastLED.delay(gdelay);
//  }

  //flower
  for(int i=0;i<gloop;i++){
      //v1
      fill_solid(leds, NUM_LEDS, CRGB::Blue);
      for(int i=0; i<16; i++){
        leds[flower_petal_v1[i]] = CRGB::Red;
      }
      for(int i=0; i<12; i++){
        leds[flower_middle_v1[i]] = CRGB::Yellow;
      }
      for(int i=0; i<3; i++){
        leds[flower_center_v1[i]] = CRGB::Yellow;
      }
      for(int i=0; i<2; i++){
        leds[flower_eye_v1[i]] = CRGB::Black;
      }
      for(int i=0; i<19; i++){
        leds[flower_leaf_v1[i]] = CRGB::SpringGreen;
      }
      FastLED.show();
      FastLED.delay(gdelay);
      //v2
      fill_solid(leds, NUM_LEDS, CRGB::Blue);
      for(int i=0; i<16; i++){
        leds[flower_petal_v2[i]] = CRGB::Red;
      }
      for(int i=0; i<12; i++){
        leds[flower_middle_v2[i]] = CRGB::Yellow;
      }
      for(int i=0; i<3; i++){
        leds[flower_center_v2[i]] = CRGB::Yellow;
      }
      for(int i=0; i<2; i++){
        leds[flower_eye_v2[i]] = CRGB::Black;
      }
      for(int i=0; i<19; i++){
        leds[flower_leaf_v2[i]] = CRGB::SpringGreen;
      }
      FastLED.show();
      FastLED.delay(gdelay);
  }

  server.sendHeader("Location","/");        // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                         // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}
