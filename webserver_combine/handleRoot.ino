// When URI / is requested, send a web page with a button to toggle the LED
void handleRoot() {                         
    server.send(200, "text/html", "<form action=\"/pacman\" method=\"POST\"><input type=\"submit\" value=\"Pacman\"></form><form action=\"/mario\" method=\"POST\"><input type=\"submit\" value=\"Mario\"></form><form action=\"/chessboard\" method=\"POST\"><input type=\"submit\" value=\"Chessboard\"></form><form action=\"/weather\" method=\"POST\"><input type=\"submit\" value=\"Weather\"></form>");
}
