void getGPS() {
  while (Serial2.available() > 0) {
    gps.encode(Serial2.read());
  }
  gpsLat = gps.location.lat();
  gpsLong = gps.location.lng();
}
