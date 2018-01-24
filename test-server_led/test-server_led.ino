#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h> 
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

#include <FastLED.h>
#define NUM_LEDS 100
#define DATA_PIN 3
#define COLOR_ORDER    RGB
#define CHIPSET        WS2811

CRGB leds[NUM_LEDS];

ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'

ESP8266WebServer server(80);    // Create a webserver object that listens for HTTP request on port 80

void handleRoot();              // function prototypes for HTTP handlers
void handleLED();
void handleNotFound();

//mario
int m_hat_shirt[]={8,10,11,23,28,29,30,31,36,48,49,50,51,56,68,69,70,71,76,88,91};
int m_hair[]={4,5,6,12,15,25,26,27,32,34,64,67,74,75,84};
int m_bibshort[]={37,38,41,42,43,57,58,61,62,63};
int m_shoe[]={20,39,60,79};
int m_skin_v1[]={13,14,17,24,33,35,44,45,46,47,52,53,54,55,65,66,72,73,82,85,86,94};
int m_skin_v2[]={13,14,16,24,33,35,44,45,46,47,52,53,54,55,65,66,72,73,83,85,86,94};
int mario_delay = 200;

void setup(void){
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');

  delay(2000);
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(70); //Number 0-255
  FastLED.clear();

  wifiMulti.addAP("iPhone", "shuwei97");   // add Wi-Fi networks you want to connect to
  wifiMulti.addAP("ssid_from_AP_2", "your_password_for_AP_2");
  wifiMulti.addAP("ssid_from_AP_3", "your_password_for_AP_3");

  Serial.println("Connecting ...");
  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) { // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    delay(250);
    Serial.print('.');
  }
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());              // Tell us what network we're connected to
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());           // Send the IP address of the ESP8266 to the computer

  if (MDNS.begin("esp8266")) {              // Start the mDNS responder for esp8266.local
    Serial.println("mDNS responder started");
  } else {
    Serial.println("Error setting up MDNS responder!");
  }

  server.on("/", HTTP_GET, handleRoot);     // Call the 'handleRoot' function when a client requests URI "/"
  server.on("/LED", HTTP_POST, handleLED);  // Call the 'handleLED' function when a POST request is made to URI "/LED"
  server.onNotFound(handleNotFound);        // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"

  server.begin();                           // Actually start the server
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();                    // Listen for HTTP requests from clients
}

void handleRoot() {                         // When URI / is requested, send a web page with a button to toggle the LED
  server.send(200, "text/html", "<form action=\"/LED\" method=\"POST\"><input type=\"submit\" value=\"Toggle LED\"></form>");
}

void handleLED() {                          // If a POST request is made to URI /LED

  for(int x=0;x<1000;x++){
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

  server.sendHeader("Location","/");        // Add a header to respond with a new location for the browser to go to the home page again
  server.send(303);                         // Send it back to the browser with an HTTP status 303 (See Other) to redirect
}

void handleNotFound(){
  server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}
