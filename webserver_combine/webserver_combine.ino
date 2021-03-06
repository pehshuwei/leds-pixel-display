//ibraries
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h> 
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h>

//thread - libraries
#include <TimedAction.h>

//weather - libraries
#include <ArduinoJson.h>

//display - libraries
#define FASTLED_ESP8266_RAW_PIN_ORDER
#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
#include <LEDMatrix.h>
#include <LEDText.h>
#include <FontMatrise.h>

//display - define
#define DATA_PIN        3
#define COLOR_ORDER    RGB
#define CHIPSET        WS2811
#define NUM_LEDS 100
#define MATRIX_WIDTH   10
#define MATRIX_HEIGHT  10
#define MATRIX_TYPE    VERTICAL_ZIGZAG_MATRIX

CRGB leds[NUM_LEDS];
cLEDMatrix<MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_TYPE> text_leds;
cLEDText ScrollingMsg;

unsigned char connecting[] = "  connecting  ";
unsigned char conn[] = "  connected   ";

//network - init
ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'
ESP8266WebServer server(80);    // Create a webserver object that listens for HTTP request on port 80
WiFiClient client;
IPAddress ip(10,0,55,240);   
IPAddress gateway(10,0,0,1);   
IPAddress subnet(255,255,255,0);  

//function prototypes for HTTP handlers
void handleCase();
void handleRoot();              
void setDisplay1();
void setDisplay2();
void setDisplay3();
void setDisplay4();
void setDisplay5();
void handleNotFound();

//global variable init
byte selected = 4;
int counter = 30;

TimedAction caseThread = TimedAction(1000,handleCase);

void setup(void) {
    Serial.begin(57600);

    //display - init
    FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(text_leds[0], text_leds.Size());
    FastLED.setBrightness(100);
    FastLED.clear(true);
    FastLED.setMaxRefreshRate(30);
    ScrollingMsg.SetFont(MatriseFontData);
    ScrollingMsg.Init(&text_leds, text_leds.Width(), ScrollingMsg.FontHeight() + 1, 0, 1);
    ScrollingMsg.SetText((unsigned char *)connecting, sizeof(connecting) - 1);
    delay(500);

    //network - add Wi-Fi networks you want to connect to
    wifiMulti.addAP("ssid_from_AP_1", "password_for_AP_1");
    wifiMulti.addAP("ssid_from_AP_2", "password_for_AP_2");

    //display "connecting"
    Serial.println("Connecting");
    for(int x=0;x<(sizeof(connecting)*5);x++)
    {
        if (ScrollingMsg.UpdateText() == -1)
          ScrollingMsg.SetText((unsigned char *)connecting, sizeof(connecting) - 1);
        else
          FastLED.show();
        delay(100);
    }

    //network - Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    while (wifiMulti.run() != WL_CONNECTED) 
    { 
        delay(1000);
        Serial.print('.');
        if (ScrollingMsg.UpdateText() == -1)
          ScrollingMsg.SetText((unsigned char *)connecting, sizeof(connecting) - 1);
        else
          FastLED.show();
        delay(100);
    }
    WiFi.config(ip, gateway, subnet);

    Serial.println('\n');
    Serial.print("Connected to ");
    Serial.println(WiFi.SSID());   //Tell which network connected to
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

    //dns
    if (!MDNS.begin("pixeldisplay")) {             // Start the mDNS responder for pixeldisplay.local
        Serial.println("Error setting up MDNS responder!");
    }
    else{
        Serial.println("mDNS responder started");
    }

    // Add service to MDNS-SD
    MDNS.addService("http", "tcp", 80);

    //server
    server.on("/", HTTP_GET, handleRoot);     // Call the 'handleRoot' function when a client requests URI "/"
    server.on("/pacman", HTTP_POST, setDisplay1);  // Call the 'setDisplay1' function when a POST request is made to URI "/mario"
    server.on("/mario", HTTP_POST, setDisplay2);
    server.on("/chessboard", HTTP_POST, setDisplay3);
    server.on("/weather", HTTP_POST, setDisplay4);
    server.on("/text", HTTP_POST, setDisplay5);

    server.onNotFound(handleNotFound);        // When a client requests an unknown URI (i.e. something other than "/"), call function "handleNotFound"
  
    server.begin();                           // Actually start the server
    Serial.println("HTTP server started");
}

void loop() {
    server.handleClient();
    //check for request every 1 sec
    caseThread.check();
}

void handleNotFound(){
   server.send(404, "text/plain", "404: Not found"); // Send HTTP status 404 (Not Found) when there's no handler for the URI in the request
}

