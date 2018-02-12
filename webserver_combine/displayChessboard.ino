int white[]={11,13,15,17,21,23,25,27,31,33,35,37,41,43,45,47,51,53,55,57,61,63,65,67,71,73,75,77,81,83,85,87};
int black[]={12,14,16,18,22,24,26,28,32,34,36,38,42,44,46,48,52,54,56,58,62,64,66,68,72,74,76,78,82,84,86,88};

//If a POST request is made to URI /chessboard
void displayChessboard() {
  Serial.println("displayChessboard()");
  counter = 30;
  
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  fill_solid(leds, NUM_LEDS, CRGB::DarkCyan);
  for(int i=0; i<32; i++){
    leds[white[i]] = CRGB::White;
  }
  for(int i=0; i<32; i++){
    leds[black[i]] = CRGB::Black;
  }
  FastLED.show();
  FastLED.delay(5000);

  server.sendHeader("Location","/");        // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                         // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}
