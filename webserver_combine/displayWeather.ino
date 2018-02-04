//weather
#define TEMPBUFSZ 10
#define WEATBUFSZ 15

int  counter = 30;
String weather = "";
float Temperature;
int weatherId;

//network
String APIKEY = "c3ddf9e303d30d910149f9ba1f9a6de4";
String CityID = "1735106"; 

char servername[]="api.openweathermap.org";  // remote server we will connect to
String result;

//display
unsigned char getting[] = "  getting data  ";
unsigned char connfail[] = "  connection failed  ";
unsigned char parsefail[] = "  parseObject() failed  ";

//If a POST request is made to URI /weather
void displayWeather(){
    Serial.println("displayWeather()");
  
    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(text_leds[0], text_leds.Size());
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
        displayData(Temperature,weather,weatherId);
        delay(100);
    }
    server.sendHeader("Location","/");        // Add a header to respond with a new location for the browser to go to the home page again
    server.send(303); 
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

void displayData(float Temperature, String weather, int weatherId)
{    
    //Temperature
    char dest1[TEMPBUFSZ] = "  "; //set space in front for scroll
    char src1[TEMPBUFSZ]; //to store Temperature
    dtostrf(Temperature, 4, 1, src1); //convert float to char array
    strcat(dest1,src1); //concat dest1 and src1 "  99.99" to dest1
    strcat(dest1,"°C"); //concat dest1 and "C" "  99.99C" to dest1
    unsigned char temp[TEMPBUFSZ] = "";  //create unsigned char array
    strcpy ((char*)temp, dest1); //convert char array dest1 to unsigned char array temp

    //Serial(57600)
    Serial.println(dest1);
    Serial.print(weatherId);
    Serial.println(weather);
    
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

    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
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
