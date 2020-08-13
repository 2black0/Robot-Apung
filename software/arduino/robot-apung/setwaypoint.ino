bool addWP() {
  Serial.println("Add Waypoint");
  /*countcmds = 0;
    cmds = "";
    delay(1000);
    while (1) {
    if (Serial1.available() > 0) {
      Serial.println("HELP");
      cmds = Serial1.readString();
      Serial.println(cmds);
      break;
    }
    countcmds++;
    if (countcmds > 500) {
      Serial.println("?????");
      break;
    }
    }
    /*while (1) {
    delay(10);
    if (Serial1.available() > 0) {
      //cmds = Serial1.read();
      cmds = Serial1.readString();
      Serial.println(cmds);
      break;
    }
    countcmds++;
    if (countcmds > 500) {
      cmds = "0;0;";
      Serial.println("?????");
      break;
    }
    }*/
  //cmds = "-7.123;110.123;";
  int firstIndex = cmds.indexOf(';');
  int secondIndex = cmds.indexOf(';', firstIndex + 1);
  String latitude = cmds.substring(1, firstIndex);
  String longitude = cmds.substring(firstIndex + 1, secondIndex);
  latWaypoint[countWaypoint] = latitude;
  longWaypoint[countWaypoint] = longitude;
  Serial.println("Latitude " + String(countWaypoint) + ": " + latWaypoint[countWaypoint]);
  Serial.println("Longitude " + String(countWaypoint) + ": " + longWaypoint[countWaypoint]);
  countWaypoint++;
  if (countWaypoint >= 5) {
    countWaypoint = 5;
  }
}

void delWP() {
  Serial.println("Delete Waypoint");
  countWaypoint--;
  if (countWaypoint >= 0) {
    Serial.println("Latitude " + String(countWaypoint) + ": " + latWaypoint[countWaypoint]);
    Serial.println("Longitude " + String(countWaypoint) + ": " + longWaypoint[countWaypoint]);
    latWaypoint[countWaypoint] = "";
    longWaypoint[countWaypoint] = "";
  }
}

void checkWP() {
  Serial.println("Check Waypoint");
  for (int i = 0; i < 5; i++) {
    Serial.print("Latitude " + String(i) + ": ");
    Serial.println(latWaypoint[i]);
    Serial.print("Longitude " + String(i) + ": ");
    Serial.println(longWaypoint[i]);
  }
}

void clearWP() {
  Serial.println("Clear Waypoint");
  for (int i = 0; i < 5; i++) {
    latWaypoint[i] = "";
    longWaypoint[i] = "";
  }
  countWaypoint = 0;
}

/*void setWaypoint() {
  int wayPointStatus = 1;
  Serial.println("Set Waypoint");

  while (1) {
    cmds = checkCommand();
    cmd = cmds.substring(0, 3);
    if (cmd != "") {
      if (cmd == "ADD") {
        if (countWaypoint >= 5) {
          break;
        }
        int firstIndex = cmds.indexOf(';');
        int secondIndex = cmds.indexOf(';', firstIndex + 1);
        String latitude = cmds.substring(firstIndex + 1, secondIndex);
        String longitude = cmds.substring(secondIndex + 1);
        latWaypoint[countWaypoint] = latitude;
        longWaypoint[countWaypoint] = longitude;

        Serial.println("Command: ADD");
        Serial.println("Latitude" + String(countWaypoint) + ": " + latWaypoint[countWaypoint]);
        Serial.println("Longitude" + String(countWaypoint) + ": " + longWaypoint[countWaypoint]);
        countWaypoint++;
      }
      if (cmd == "DEL") {
        countWaypoint--;
        Serial.println("Command: DEL");
        Serial.println("Latitude" + String(countWaypoint) + ": " + latWaypoint[countWaypoint]);
        Serial.println("Longitude" + String(countWaypoint) + ": " + longWaypoint[countWaypoint]);
        latWaypoint[countWaypoint] = "";
        longWaypoint[countWaypoint] = "";
      }
      if (cmd == "CHK") {
        Serial.println("Command: CHK");
        for (int i = 0; i < 5; i++) {
          Serial.print("Latitude" + String(i) + ": ");
          Serial.println(latWaypoint[i]);
          Serial.print("Longitude" + String(i) + ": ");
          Serial.println(longWaypoint[i]);
        }
      }
      if (cmd == "CLR") {
        Serial.println("Command: CLR");
        clearWaypoint();
      }
      cmd = "";
    }
  }
  }

  void clearWaypoint() {
  for (int i = 0; i < 5; i++) {
    latWaypoint[i] = "";
    longWaypoint[i] = "";
  }
  countWaypoint = 0;
  }*/
