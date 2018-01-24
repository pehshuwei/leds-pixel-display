#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
//display
#include <FastLED.h>
#include <LEDMatrix.h>
#include <LEDText.h>
#include <FontMatrise.h>
//display
#define LED_PIN        3
#define COLOR_ORDER    RGB
#define CHIPSET        WS2811
#define MATRIX_WIDTH   10
#define MATRIX_HEIGHT  10
#define MATRIX_TYPE    VERTICAL_ZIGZAG_MATRIX

#define TEMPBUFSZ 10
#define WEATBUFSZ 15

cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> leds;
cLEDText ScrollingMsg;

const char* ssid     = "iPhone";      // SSID of local network
const char* password = "shuwei97";   // Password on network
String APIKEY = "c3ddf9e303d30d910149f9ba1f9a6de4";
String CityID = "1735106"; 

WiFiClient client;
char servername[]="api.openweathermap.org";  // remote server we will connect to
String result;

int  counter = 30;

String weather = "";
//String weatherDescription = "";
//String weatherLocation = "";
//String Country;
float Temperature;
//float Humidity;
//float Pressure;

//display
unsigned char connecting[] = "  connecting  ";
unsigned char conn[] = "  connected   ";
unsigned char getting[] = "  getting data  ";
unsigned char connfail[] = "  connection failed  ";
unsigned char parsefail[] = "  parseObject() failed  ";
unsigned char psc[] = { EFFECT_HSV_AH "\x00\xff\xff\xff\xff\xff" " PSC" };

void setup() {
  //Serial(57600)
  Serial.begin(57600);
  //display
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds[0], leds.Size());
  FastLED.setBrightness(100);
  FastLED.clear(true);
  delay(500);
  ScrollingMsg.SetFont(MatriseFontData);
  ScrollingMsg.Init(&leds, leds.Width(), ScrollingMsg.FontHeight() + 1, 0, 1);
  ScrollingMsg.SetText((unsigned char *)connecting, sizeof(connecting) - 1);

  //display "connecting"
  for(int x=0;x<(sizeof(connecting)*5);x++)
  {
      if (ScrollingMsg.UpdateText() == -1)
        ScrollingMsg.SetText((unsigned char *)connecting, sizeof(connecting) - 1);
      else
        FastLED.show();
      delay(100);
  }
  
  WiFi.begin(ssid, password);

  //display "connecting"
  while (WiFi.status() != WL_CONNECTED) {
      //Serial(57600)
      Serial.print(".");
      if (ScrollingMsg.UpdateText() == -1)
        ScrollingMsg.SetText((unsigned char *)connecting, sizeof(connecting) - 1);
      else
        FastLED.show();
      delay(100);
  }
  
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
  //Serial(57600)
  Serial.println("connected");
  delay(1000);
}

void loop() {
    if(counter == 30) //Get new data every 5 minutes
    {
        counter = 0;
        displayGettingData();
        delay(1000);
        getWeatherData();
    }
    else
    {
        counter++;
        displayWeather(Temperature,weather);
        delay(100);
    }
}

void getWeatherData() //client function to send/receive GET request data.
{
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
  
//  String location = root["name"];
//  String country = root["sys"]["country"];
  float temperature = root["main"]["temp"];
//  float humidity = root["main"]["humidity"];
  String mainWeather = root["weather"]["main"];
//  String description = root["weather"]["description"];
//  float pressure = root["main"]["pressure"];

    weather = mainWeather;
//  weatherDescription = description;
//  weatherLocation = location;
//  Country = country;
    Temperature = temperature;
//  Humidity = humidity;
//  Pressure = pressure;

}

void displayWeather(float Temperature, String weather)
{    
    //Temperature
    char dest1[TEMPBUFSZ] = "  "; //set space in front for scroll
    char src1[TEMPBUFSZ]; //to store Temperature
    dtostrf(Temperature, 4, 1, src1); //convert float to char array
    strcat(dest1,src1); //concat dest1 and src1 "  99.99" to dest1
    strcat(dest1,"C"); //concat dest1 and "C" "  99.99C" to dest1
    unsigned char temp[TEMPBUFSZ] = "";  //create unsigned char array
    strcpy ((char*)temp, dest1); //convert char array dest1 to unsigned char array temp

    //weather
    Serial.println(weather.length());
    char dest2[WEATBUFSZ] = "  "; //set space in front for scroll
    char src2[WEATBUFSZ]; //to store weather
    weather.toCharArray(src2,WEATBUFSZ); //convert String to char array
    strcat(dest2,src2); //concat dest2 and src2 "  weather" to dest2
    unsigned char weat[WEATBUFSZ] = "";  //create unsigned char array
    strcpy ((char*)weat, dest2); //convert char array dest2 to unsigned char array weat

    //Serial(57600)
    Serial.println(dest1);
    Serial.println(dest2);
    
    //display temperature
    ScrollingMsg.SetText((unsigned char *)temp, sizeof(temp) - 1);
    ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0x00, 0xce, 0xd1);
    for(int x=0;x<((sizeof(temp))*5);x++)
    {
        if (ScrollingMsg.UpdateText() == -1)
          ScrollingMsg.SetText((unsigned char *)temp, sizeof(temp) - 1);
        else
          FastLED.show();
        delay(200);
    }

    //display description
    ScrollingMsg.SetText((unsigned char *)weat, sizeof(weat) - 1);
    ScrollingMsg.SetTextColrOptions(COLR_RGB | COLR_SINGLE, 0x00, 0x8b, 0x8b);
    for(int y=0;y<((sizeof(weat))*5);y++)
    {
        if (ScrollingMsg.UpdateText() == -1)
          ScrollingMsg.SetText((unsigned char *)weat, sizeof(weat) - 1);
        else
          FastLED.show();
        delay(200);
    }

    //display psc
    ScrollingMsg.SetText((unsigned char *)psc, sizeof(psc) - 1);
    for(int z=0;z<((sizeof(psc))*5);z++)
    {
        if (ScrollingMsg.UpdateText() == -1)
          ScrollingMsg.SetText((unsigned char *)psc, sizeof(psc) - 1);
        else
          FastLED.show();
        delay(200);
    }
}

void displayGettingData()
{
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
  //Serial(57600)
  Serial.println("getting data");
}


