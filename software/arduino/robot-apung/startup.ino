void startup() {
  int numbSats = 0;
  
  Serial.print("Waiting");
  for (int i = 5; i >= 1; i--) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  Serial.println("Searching for Satellites ");
  while (numbSats <= 4) {
    getGPS(); // gps
    numbSats = (int)(gps.satellites.value());
  }
  getGPS();
  Serial.print(numbSats);
  Serial.println(" Satellites Acquired");
}
