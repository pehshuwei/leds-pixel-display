//network & weather
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h> 
#include <ArduinoJson.h>

//display
#define FASTLED_ESP8266_RAW_PIN_ORDER
#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
#include <LEDMatrix.h>
#include <LEDText.h>
#include <FontMatrise.h>

#define LED_PIN        3
#define COLOR_ORDER    RGB
#define CHIPSET        WS2811
#define NUM_LEDS 100
#define MATRIX_WIDTH   10
#define MATRIX_HEIGHT  10
#define MATRIX_TYPE    VERTICAL_ZIGZAG_MATRIX

CRGB icon_leds[NUM_LEDS];
cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;
cLEDText ScrollingMsg;

//weather
#define TEMPBUFSZ 10
#define WEATBUFSZ 15

int  counter = 30;
String weather = "";
float Temperature;
int weatherId;

//network
ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'
String APIKEY = "c3ddf9e303d30d910149f9ba1f9a6de4";
String CityID = "1735106"; 

WiFiClient client;
char servername[]="api.openweathermap.org";  // remote server we will connect to
String result;

//display
unsigned char connecting[] = "  connecting  ";
unsigned char conn[] = "  connected   ";
unsigned char getting[] = "  getting data  ";
unsigned char connfail[] = "  connection failed  ";
unsigned char parsefail[] = "  parseObject() failed  ";

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

void setup() {
    Serial.begin(57600);
  
    //display
    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
    FastLED.setBrightness(100);
    FastLED.clear(true);
    FastLED.setMaxRefreshRate(30);
    delay(500);
    ScrollingMsg.SetFont(MatriseFontData);
    ScrollingMsg.Init(&leds, leds.Width(), ScrollingMsg.FontHeight() + 1, 0, 1);
    ScrollingMsg.SetText((unsigned char *)connecting, sizeof(connecting) - 1);
  
    //add Wi-Fi networks you want to connect to
    wifiMulti.addAP("PSC STAFF", "staff.psc321");
    wifiMulti.addAP("iPhone", "shuwei97");
  
    //display "connecting"
    Serial.println("connecting");
    for(int x=0;x<(sizeof(connecting)*5);x++)
    {
        if (ScrollingMsg.UpdateText() == -1)
          ScrollingMsg.SetText((unsigned char *)connecting, sizeof(connecting) - 1);
        else
          FastLED.show();
        delay(100);
    }

    //Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    while (wifiMulti.run() != WL_CONNECTED) 
    { 
        delay(250);
        Serial.print('.');
        if (ScrollingMsg.UpdateText() == -1)
          ScrollingMsg.SetText((unsigned char *)connecting, sizeof(connecting) - 1);
        else
          FastLED.show();
        delay(100);
    }
    Serial.println('\n');
    Serial.print("Connected to ");
    Serial.println(WiFi.SSID());    //Tell which network connected to
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());   //IP address of the ESP8266
    
    //display "connected" 
    ScrollingMsg.SetText((unsigned char *)conn, sizeof(conn) - 1);
    for(int x=0;x<(sizeof(conn)*5);x++)
    {
        if (ScrollingMsg.UpdateText() == -1)
          ScrollingMsg.SetText((unsigned char *)conn, sizeof(conn) - 1);
        else
          FastLED.show();
        delay(100);
    }
    delay(1000);
}

void loop() {
    if(counter == 30) //Get new data every 30 counts
    {
        counter = 0;
        displayGettingData();
        delay(1000);
        getWeatherData();
    }
    else
    {
        counter++;
        displayWeather(Temperature,weather,weatherId);
        delay(100);
    }
}

void getWeatherData() //client function to send/receive GET request data.
{
    result = "";
    if (client.connect(servername, 80)) //starts client connection, checks for connection
    {  
        client.println("GET /data/2.5/weather?id="+CityID+"&units=metric&APPID="+APIKEY);
        client.println("Host: api.openweathermap.org");
        client.println("User-Agent: ArduinoWiFi/1.1");
        client.println("Connection: close");
        client.println();
    } 
    else 
    {
        //display "connection failed"
        ScrollingMsg.SetText((unsigned char *)connfail, sizeof(connfail) - 1);
        for(int x=0;x<(sizeof(connfail)*5);x++)
        {
            if (ScrollingMsg.UpdateText() == -1)
              ScrollingMsg.SetText((unsigned char *)connfail, sizeof(connfail) - 1);
            else
              FastLED.show();
            delay(100);
        }
    }
  
    while(client.connected() && !client.available())
    {
        delay(1); //waits for data
    }
    while (client.connected() || client.available()) //connected or data available
    { 
        char c = client.read(); //gets byte from ethernet buffer
        result = result+c;
    }
    client.stop(); //stop client
    result.replace('[', ' ');
    result.replace(']', ' ');
    ////
    Serial.println(result);
  
    char jsonArray [result.length()+1];
    result.toCharArray(jsonArray,sizeof(jsonArray));
    jsonArray[result.length() + 1] = '\0';
    
    StaticJsonBuffer<1024> json_buf;
    JsonObject &root = json_buf.parseObject(jsonArray);
    if (!root.success())
    {
        //display "parseObject() failed"
        ScrollingMsg.SetText((unsigned char *)parsefail, sizeof(parsefail) - 1);
        for(int x=0;x<(sizeof(parsefail)*5);x++)
        {
            if (ScrollingMsg.UpdateText() == -1)
              ScrollingMsg.SetText((unsigned char *)parsefail, sizeof(parsefail) - 1);
            else
              FastLED.show();
            delay(100);
        }
    }
  
    float temperature = root["main"]["temp"];
    String mainWeather = root["weather"]["main"];
    int weather_id = root["weather"]["id"];
    
    weather = mainWeather;
    weatherId = weather_id;
    Temperature = temperature;

}

void displayWeather(float Temperature, String weather, int weatherId)
{    
    //Temperature
    char dest1[TEMPBUFSZ] = "  "; //set space in front for scroll
    char src1[TEMPBUFSZ]; //to store Temperature
    dtostrf(Temperature, 4, 1, src1); //convert float to char array
    strcat(dest1,src1); //concat dest1 and src1 "  99.99" to dest1
    strcat(dest1,"C"); //concat dest1 and "C" "  99.99C" to dest1
    unsigned char temp[TEMPBUFSZ] = "";  //create unsigned char array
    strcpy ((char*)temp, dest1); //convert char array dest1 to unsigned char array temp

    //Serial(57600)
    Serial.println(dest1);
    Serial.println(weather);
    Serial.println(weatherId);
    
    //display temperature
    ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0x00, 0xce, 0xd1);
    ScrollingMsg.SetText((unsigned char *)temp, sizeof(temp) - 1);
    for(int x=0;x<((sizeof(temp))*5);x++)
    {
        if (ScrollingMsg.UpdateText() == -1)
          ScrollingMsg.SetText((unsigned char *)temp, sizeof(temp) - 1);
        else
          FastLED.show();
        delay(200);
    }

    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(icon_leds, NUM_LEDS);
    //display weather icon
    if(weatherId>=200 && weatherId<300)
    {   displayThunder();}
    else if(weatherId>=300 && weatherId<400)
      {   displayDrizzle();}
    else if(weatherId>=500 && weatherId<600)
    {   displayRain();}
    else if(weatherId>=600 && weatherId<700)
    {   displaySnow();}
    else if(weatherId>=700 && weatherId<800)
    {   displayAtmosphere();}
    else if(weatherId==800)
    {   displayClear();}
    else if(weatherId>800 && weatherId<900)
    {   displayCloud();}
    else if(weatherId>=900 && weatherId<910)
    {   displayExtreme();}
    else if(weatherId>=910 && weatherId<1000)
    {   displayAdditional();}
    FastLED.clear(true);
    FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());

    ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0xff, 0xff, 0xff);
}

void displayGettingData()
{
    //Serial(57600)
    Serial.println("getting data");
    //display getting data
    ScrollingMsg.SetText((unsigned char *)getting, sizeof(getting) - 1);
    for(int x=0;x<(sizeof(getting)*5);x++)
    {
      if (ScrollingMsg.UpdateText() == -1)
        ScrollingMsg.SetText((unsigned char *)getting, sizeof(getting) - 1);
      else
        FastLED.show();
      delay(100);
    }
}

void displayClear(){
  //Clear
  fill_solid(icon_leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<45; i++){
    icon_leds[sun[i]] = CRGB::Orange;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayCloud(){
  //Cloud
  fill_solid(icon_leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<34; i++){
    icon_leds[cloud[i]] = CRGB::Cyan;
  }
  for(int i=0; i<15; i++){
    icon_leds[smallcloud[i]] = CRGB::RoyalBlue;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayDrizzle(){
  //Drizzle
  fill_solid(icon_leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<25; i++){
    icon_leds[condition_cloud[i]] = CRGB::RoyalBlue;
  }
  for(int i=0; i<9; i++){
    icon_leds[condition_smallcloud[i]] = CRGB::DarkGray;
  }
  for(int i=0; i<5; i++){
    icon_leds[drizzle[i]] = CRGB::Cyan;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayRain(){
  //Rain
  fill_solid(icon_leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<25; i++){
    icon_leds[condition_cloud[i]] = CRGB::RoyalBlue;
  }
  for(int i=0; i<9; i++){
    icon_leds[condition_smallcloud[i]] = CRGB::DarkGray;
  }
  for(int i=0; i<17; i++){
    icon_leds[rain[i]] = CRGB::Cyan;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayThunder(){
  //Thunder
  fill_solid(icon_leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<25; i++){
    icon_leds[condition_cloud[i]] = CRGB::RoyalBlue;
  }
  for(int i=0; i<9; i++){
    icon_leds[condition_smallcloud[i]] = CRGB::DarkGray;
  }
  for(int i=0; i<22; i++){
    icon_leds[thunder[i]] = CRGB::Yellow;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayAtmosphere(){
  //Atmosphere
  fill_solid(icon_leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<30; i++){
    icon_leds[atmosphere[i]] = CRGB::Gray;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displaySnow(){
  //Snow
  fill_solid(icon_leds, NUM_LEDS, CRGB::Black);
  for(int i=0; i<19; i++){
    icon_leds[snow_frame[i]] = CRGB::SlateGray;
  }
  for(int i=0; i<36; i++){
    icon_leds[snow_flake[i]] = CRGB::White;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayAdditional(){
  //Additional
  fill_solid(icon_leds, NUM_LEDS, CRGB::Yellow);
  for(int i=0; i<38; i++){
    icon_leds[AE_void[i]] = CRGB::Black;
  }
  FastLED.show();
  FastLED.delay(10000);
}

void displayExtreme(){
  //Extreme
  fill_solid(icon_leds, NUM_LEDS, CRGB::Red);
  for(int i=0; i<38; i++){
    icon_leds[AE_void[i]] = CRGB::Black;
  }
  FastLED.show();
  FastLED.delay(10000);
}
