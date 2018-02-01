//weather icon
//Clear
int sun[] = {4,5,11,12,14,15,17,18,21,22,27,28,34,35,40,41,43,44,45,46,48,49,50,51,53,54,55,56,58,59,64,65,71,72,77,78,81,82,84,85,87,88,94,95};
//Cloud
int cloud[] = {2,3,4,13,14,15,16,17,22,23,24,25,26,33,34,35,36,37,42,43,44,45,54,55,56,57,62,63,64,65,77,76,82,83};
int smallcloud[] = {46,52,53,66,67,68,71,72,73,74,85,86,87,93,94};
//Condition cloud
int condition_cloud[] = {13,14,25,26,27,31,32,33,34,45,46,47,48,52,53,54,65,66,67,73,74,85,86,93,94};
int condition_smallcloud[] = {51,68,69,70,71,72,87,88,92};
//Drizzle
int drizzle[] = {18,24,42,76,80};
//Rain
int rain[] = {0,1,3,4,20,22,23,41,42,44,60,61,63,64,82,83,99};
//Thunder
int thunder[] = {15,20,21,23,24,25,33,34,36,37,38,42,46,61,62,64,74,75,76,77,83,85};
//Atmosphere
int atmosphere[] = {1,4,7,11,14,17,23,26,29,31,34,37,41,44,47,51,54,57,63,66,69,71,74,77,81,84,87,91,94,97};
//Snow
int snow_frame[] = {0,1,2,3,4,5,6,7,8,9,10,29,30,49,50,69,70,89,90};
int snow_flake[] = {13,15,17,21,24,27,31,33,35,37,39,43,44,45,51,52,53,54,56,57,58,59,63,64,65,71,73,75,77,79,81,84,87,93,95,97};
//Additional & Extreme
int AE_void[] = {0,1,2,7,8,9,10,11,18,19,20,29,41,42,44,45,46,47,48,51,52,53,54,55,57,58,70,79,80,81,88,89,90,91,92,97,98,99};

void displayClear(){
  //Clear
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<45; i++){
    leds[sun[i]] = CRGB::Orange;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayCloud(){
  //Cloud
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<34; i++){
    leds[cloud[i]] = CRGB::Cyan;
  }
  for(int i=0; i<15; i++){
    leds[smallcloud[i]] = CRGB::RoyalBlue;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayDrizzle(){
  //Drizzle
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<25; i++){
    leds[condition_cloud[i]] = CRGB::RoyalBlue;
  }
  for(int i=0; i<9; i++){
    leds[condition_smallcloud[i]] = CRGB::DarkGray;
  }
  for(int i=0; i<5; i++){
    leds[drizzle[i]] = CRGB::Cyan;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayRain(){
  //Rain
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<25; i++){
    leds[condition_cloud[i]] = CRGB::RoyalBlue;
  }
  for(int i=0; i<9; i++){
    leds[condition_smallcloud[i]] = CRGB::DarkGray;
  }
  for(int i=0; i<17; i++){
    leds[rain[i]] = CRGB::Cyan;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayThunder(){
  //Thunder
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<25; i++){
    leds[condition_cloud[i]] = CRGB::RoyalBlue;
  }
  for(int i=0; i<9; i++){
    leds[condition_smallcloud[i]] = CRGB::DarkGray;
  }
  for(int i=0; i<22; i++){
    leds[thunder[i]] = CRGB::Yellow;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayAtmosphere(){
  //Atmosphere
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<30; i++){
    leds[atmosphere[i]] = CRGB::Gray;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displaySnow(){
  //Snow
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<19; i++){
    leds[snow_frame[i]] = CRGB::SlateGray;
  }
  for(int i=0; i<36; i++){
    leds[snow_flake[i]] = CRGB::White;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayAdditional(){
  //Additional
  fill_solid(leds, NUM_LEDS, CRGB::Yellow);
  for(int i=0; i<38; i++){
    leds[AE_void[i]] = CRGB::Black;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayExtreme(){
  //Extreme
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  for(int i=0; i<38; i++){
    leds[AE_void[i]] = CRGB::Black;
  }
  FastLED.show();
  FastLED.delay(10000);
}
