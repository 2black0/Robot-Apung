void goWP() {
  Serial.println("Run Waypoint");
  countWaypoint = 0;
  while (goStatus) {
    while (Serial1.available()) {
      cmds = Serial1.readString();
      cmd = cmds.substring(0, 3);
      countcmds++;
      if(countcmds >= 100) break;
    }
    if (cmd == "STP") {
      Serial.println("Stop Waypoint");
      goStatus = 0;
    }
    cmd = "";
    cmds = "";
    
    runWP();
    
    if(countUpdateSensor > 100){
      updateSensor();
      countUpdateSensor = 0;
    }
    countUpdateSensor++;
  }
}

void runWP(){
  getGPS();
  getCompass();
  getUltrasonic();

  String latWP = latWaypoint[countWaypoint];
  String longWP = longWaypoint[countWaypoint];
  
  if (millis() > 5000 && gps.charsProcessed() < 10){
    Serial.println("No GPS Data");
  }
  distanceWP = TinyGPSPlus::distanceBetween(gps.location.lat(), gps.location.lng(), latWP.toDouble(), longWP.toDouble());
  GPSCourse = TinyGPSPlus::courseTo(gps.location.lat(), gps.location.lng(), latWP.toDouble(), longWP.toDouble());
  if(distanceWP == 0){
    brake();
    Serial.println("Waypoint" + String(countWaypoint) + "Reached");
    countWaypoint++;
    return;
  }
  if(abs(GPSCourse - compHead) <= 15){
    forward();
  }
  else{
    int x = (GPSCourse - 360);
    int y = (compHead - (x));
    int z = (y - 360);

    if((z <= 180) && (z >= 0)){
      turn_left();
    }
    else{
      turn_right();
    }
  }
}
