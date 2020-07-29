void go() {
  while (goStatus) {
    if (countUpdateGPS >= 10) {
      updateGPS(); // gps
      countUpdateGPS = 0;
    }
    Serial.println("GO");
    delay(500);
    countUpdateGPS += 1;

    cmds = checkCommand();
    cmd = cmds.substring(0, 3);
    if (cmd == "STP") {
      Serial.println("Command: STP");
      Serial.println("Stop Waypoint");
      goStatus = 0;
    }
  }
}
