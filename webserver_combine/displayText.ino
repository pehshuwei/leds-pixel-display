//text
#define TEXTBUFSZ 22

unsigned char currentMsg[TEXTBUFSZ] = "";
//If a POST request is made to URI /text
void displayText(){
    Serial.println("displayText()");
    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(text_leds[0], text_leds.Size());
    //Text
    char dest2[TEXTBUFSZ] = "  "; //set space in front for scroll
    char src2[TEXTBUFSZ];//to store text inserted
    if(server.hasArg("text")){
      memset(currentMsg, 0, TEXTBUFSZ);
      server.arg("text").toCharArray(src2,TEXTBUFSZ); //convert String to char array
      strcat(dest2,src2); //concat dest2 and src2 "  text" to dest2
      strcpy ((char*)currentMsg, dest2); //convert char array dest2 to unsigned char array text
    }
    
    Serial.println((char*)currentMsg);
    
    //display text
    ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0x00, 0xce, 0xd1);
    ScrollingMsg.SetText((unsigned char *)currentMsg, sizeof(currentMsg) - 1);
    for(int x=0;x<((sizeof(currentMsg))*5);x++)
    {
        if (ScrollingMsg.UpdateText() == -1)
          ScrollingMsg.SetText((unsigned char *)currentMsg, sizeof(currentMsg) - 1);
        else
          FastLED.show();
        delay(200);
    }

    server.sendHeader("Location","/");        // Add a header to respond with a new location for the browser to go to the home page again
    server.send(303); 
}
