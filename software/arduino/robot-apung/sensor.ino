void updateSensor() {
  getGPS();
  getCompass();
  getUltrasonic();

  String newPos = "a;" + String(gpsLat) + ";" + String(gpsLong) + ";" + String(compHead) + ";" + String(rangeLeft) + ";" + String(rangeFront) + ";" + String(rangeRight) + "b;";
  //String newPos = "a;-7.123;110.123;180;100;90;80;b";
  Serial.println("Update Sensor");
  Serial.println(newPos);
  Serial1.print(newPos);
}

void FakeupdateSensor() {
  String newPos = "-7.123;110.123;180;100;90;80;";
  Serial.println("Update Sensor");
  Serial.println(newPos);
  Serial1.print(newPos);
}
