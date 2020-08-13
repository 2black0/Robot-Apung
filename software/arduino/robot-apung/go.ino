void goWP() {
  Serial.println("Run Waypoint");
  countWaypoint = 0;
  while (goStatus) {
    if (Serial1.available() > 0) {
      int inByte = Serial1.read();
      if (inByte == 'f') {
        Serial.println("Stop Waypoint");
        goStatus = 0;
      }
    }
    runWP();
    if (countUpdateSensor > 100) {
      updateSensor();
      countUpdateSensor = 0;
    }
    countUpdateSensor++;
  }
}

void runWP() {
  getGPS();
  getCompass();
  getUltrasonic();

  String latWP = latWaypoint[countWaypoint];
  String longWP = longWaypoint[countWaypoint];

  if (millis() > 5000 && gps.charsProcessed() < 10) {
    Serial.println("No GPS Data");
  }
  distanceWP = TinyGPSPlus::distanceBetween(gps.location.lat(), gps.location.lng(), latWP.toDouble(), longWP.toDouble());
  GPSCourse = TinyGPSPlus::courseTo(gps.location.lat(), gps.location.lng(), latWP.toDouble(), longWP.toDouble());
  if (distanceWP == 0) {
    brake();
    Serial.println("Waypoint" + String(countWaypoint) + "Reached");
    countWaypoint++;
    return;
  }
  if (abs(GPSCourse - compHead) <= 15) {
    forward();
  }
  else {
    int x = (GPSCourse - 360);
    int y = (compHead - (x));
    int z = (y - 360);

    if ((z <= 180) && (z >= 0)) {
      turn_left();
    }
    else {
      turn_right();
    }
  }
}
