void getGPS() {
  while (Serial2.available() > 0) {
    gps.encode(Serial2.read());
  }
}

void updateGPS() {
  ///getGPS();
  ///double gpsLat = gps.location.lat(); 
  ///double gpsLong = gps.location.lng();

  double gpsLat = -7.123123;
  double gpsLong = 110.123123;
  
  String newPos = String(gpsLat) + ";" + String(gpsLong); 
  Serial.println("Update Position");
  Serial.println(newPos);
  Serial1.print(newPos);
}
