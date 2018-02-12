//html
const char * htmlMessage = "<!DOCTYPE html>"
"<html>"
"<head>"
  "<link href=\"https://fonts.googleapis.com/css?family=Montserrat:400\" rel=\"stylesheet\">"
  "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />"
  "<style>"
    "body *{"
      "font-family: 'Montserrat', sans-serif;"
      "font-size: 18px;"
      "color: #FFFFFF;" 
    "}"
    "div{"
      "width: 70%;"
      "margin: 0 auto;"
      "padding: 10% 0;"
      "display: -webkit-flex;"
      "display: flex;"
      "-webkit-flex-flow: row wrap;"
      "justify-content: space-around;"
    "}"
    "form{"
      "margin: 30px 10px;"
      "line-height: 70px;"
    "}"
    "form.display{"   
      "width: 30%;"
    "}"
    "form.special{"
      "width: 100%;"
    "}"
    "form.text{"
      "display: -webkit-flex;"
      "display: flex;"
        "-webkit-flex-flow: row wrap;"
        "justify-content: space-between;"
    "}"
    "input:focus{"
      "outline: none;"
    "}"
    "input[type=\"submit\"]{"
      "cursor: pointer;"
      "width: 100%;"
      "height: 100%;"
      "border-radius: 5px;"
      "border: none;"
      "box-shadow: 1px 1px #E0E0E0;"
      "-webkit-appearance: none;"
      "-moz-appearance: none;"
      "appearance: none;"
    "}"
    "input[type=\"submit\"].one{"
      "background-color: #F44336;"
    "}"
    "input[type=\"submit\"].two{"
      "background-color: #E91E63;"
    "}"
    "input[type=\"submit\"].three{"
     "background-color: #9C27B0;"
    "}"
    "input[type=\"submit\"].four{"
      "background-color: #3F51B5;"
    "}"
    "input[type=\"submit\"].five{"
      "width: 30%;"
      "line-height: 60px;"
      "background-color: #009688;"
    "}"
    "input[type=\"submit\"]:hover{"
      "background-color: #000000;"
      "transition: all 300ms ease-in-out;"
    "}"
    "input[type=\"submit\"]:active{"
      "background-color: #545454;"
      "transition: all 300ms ease-in-out;"
    "}"
    "input[type=\"text\"]{"
        "color: #000000;"
        "width: 60%;"
        "padding: 10px;"
        "border-radius: 5px;"
    "}"
    "@media only screen and (max-width: 880px){"
      "form.display{"   
        "width: 100%;"
      "}"
      "form{"
        "margin: 20px 10px;"
      "}"
    "}"
    "@media only screen and (max-width: 600px){"
      "div{"
        "width: 90%;"
        "padding: 5% 0;"
      "}"
      "input[type=\"text\"]{"
          "width: 100%;"
          "margin-bottom: 20px;"
      "}"
      "input[type=\"submit\"].five{"
        "width: 100%;"
        "background-color: #009688;"
        "line-height: 0;"
      "}"
    "}"

  "</style>"
"</head>"
  "<body>"
  "<div>"
    "<form  class=\"display\" action=\"/pacman\" method=\"POST\"><input class=\"one\" type=\"submit\" value=\"Pacman\"></form>"
    "<form  class=\"display\" action=\"/mario\" method=\"POST\"><input class=\"two\" type=\"submit\" value=\"Mario\"></form>"
    "<form  class=\"display\" action=\"/chessboard\" method=\"POST\"><input class=\"three\" type=\"submit\" value=\"Chessboard\"></form>"
    "<form class=\"special\" action=\"/weather\" method=\"POST\"><input class=\"four\" type=\"submit\" value=\"Weather\"></form>"
    "<form class=\"special text\" action=\"/text\" method=\"POST\">"
      "<input type=\"text\" name=\"text\" maxlength=\"20\" minlength=\"15\" placeholder=\"Insert the sentence that you want it to display!\">"
      "<input class=\"five\" type=\"submit\" value=\"Display\">"
      "</form>"
      "</div>"
  "</body>"
"</html>" ;

// When URI / is requested, send a web page with a button to toggle the LED
void handleRoot() {                         
    server.send(200, "text/html", htmlMessage);
}
