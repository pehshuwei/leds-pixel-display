# LEDs Pixel Display
A 10x10 pixels IoT display that can be controlled through a webpage. 
**ESPresso Lite V2.0** and **WS2811 Addressable LEDs strip** are used in this project, coded with Arduino IDE. 

Refer to [LEDs Pixel Display](https://www.pehshuwei.me/projects/pixeldisplay) for more details. Folder [webserver_combine](https://github.com/pehshuwei/leds-pixel-display/tree/master/webserver_combine) is the sketch for the project.

### The display
![display](https://github.com/pehshuwei/leds-pixel-display/blob/master/image/display.jpg)

### The webpage
![webpage](https://github.com/pehshuwei/leds-pixel-display/blob/master/image/webpage.png)

## How does it work?
1. Connect to the wifi that the display connected to.
2. Open browser.
3. Go to pixeldisplay.local/, and you will see a webpage.
4. Click the function that you want it to display.

## The 3 main functions the display can show are
- Built-in image sets such as Pacman, Mario, and Chessboard
- Temperature and weather
- Text

## Code

Programmed in C/C++ with Arduino IDE, and some HTML and CSS in between for the webpage.

### ESPresso Lite V2.0
In this project, [ESPresso Lite V2.0](http://learn.espressolite.com/) works as the web server for the display because it has the WiFi module. 
It serves the website to let clients make requests and send the correct codes for display.

For the basic structure, can refer to [A Beginner's Guide to the ESP8266](https://tttapa.github.io/ESP8266/Chap01%20-%20ESP8266.html).

### Built-in image sets
When "Pacman", "Mario" or "Chessboard" is clicked, the display will display related image set.

LEDs are controlled by [FastLED library](https://github.com/FastLED/FastLED) for image sets. 
It is easy to use for beginners.

### Text
For text display, users need to insert text they want the display to display and click "Display". xD

LEDs are controlled by [LEDText library](https://github.com/AaronLiddiment/LEDText) in this features.

### Temperature and weather
When the "Weather" button is clicked, temperature and icon for current weather will be displayed. 

The data is from [OpenWeatherMap](http://openweathermap.org/) through [Weather API](http://openweathermap.org/api) with [ArduinoJson](https://arduinojson.org/). 
Display includes text and weather icons sets, which uses [FastLED](https://github.com/FastLED/FastLED) and [LEDText](https://github.com/AaronLiddiment/LEDText) libraries.

## Libraries
- ESP8266WiFi
- WiFiClient
- ESP8266WiFiMulti
- ESP8266mDNS
- ESP8266WebServer

### Thread
- [TimedAction](https://playground.arduino.cc/Code/TimedAction)

### Weather 
- [ArduinoJson](https://arduinojson.org/)

### Display
- [FastLED](https://github.com/FastLED/FastLED)
- [LEDText](https://github.com/AaronLiddiment/LEDText)
- [LEDMatrix](https://github.com/AaronLiddiment/LEDMatrix)
- [FontMatrise](https://github.com/FastLED/FastLED)

