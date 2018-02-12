void handleCase(){
    server.handleClient();
    switch(selected)
    {
      case 0:
        break;
      case 1:
        displayPacman();
        break;
      case 2:
        displayMario();
        break;
      case 3:
        displayChessboard();
        break;
      case 4:
        displayWeather();
        break;
      case 5:
        displayText();
        break;
      default:
      break;
    }
}

