String cmd = "";
String cmds = "";
String latWaypoint[5] = {
  "",
  "",
  "",
  "",
  ""
};
String longWaypoint[5] = {
  "",
  "",
  "",
  "",
  ""
};
int countWaypoint = 0;
int countUpdateGPS = 0;
int goStatus = 0;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600);

  Serial.println("Initializing...");
  delay(1000);
}

void loop() {
  if (countUpdateGPS >= 10) {
    updateGPS();
    countUpdateGPS = 0;
  }
  cmds = checkCommand();
  cmd = cmds.substring(0, 3);
  if (cmd != "") {
    if (cmd == "ADD") {
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
    if (cmd == "GOO") {
      Serial.println("Command: GOO");
      Serial.println("Run Waypoint");
      goStatus = 1;
    }
    if (cmd == "STP") {
      Serial.println("Command: STP");
      Serial.println("Stop Waypoint");
      goStatus = 0;
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
    cmd = "";
  }

  while (goStatus) {
    go();
    cmds = checkCommand();
    cmd = cmds.substring(0, 3);
    if (cmd == "STP") {
      Serial.println("Command: STP");
      Serial.println("Stop Waypoint");
      goStatus = 0;
    }
  }

  delay(500);
  countUpdateGPS += 1;
}

void go() {
  Serial.println("GO");
  delay(500);
}

String checkCommand() {
  String teleCom;
  while (Serial1.available()) {
    teleCom = Serial1.readString();
    return teleCom;
  }
}

void updateGPS() {
  String newPos = "-7.80349;110.36933";
  Serial.println("");
  Serial.println("Update Position");
  Serial.println(newPos);
  Serial1.print(newPos);
  Serial.println("");
}
