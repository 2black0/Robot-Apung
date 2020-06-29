/*

Urutan test no 5
Program test untuk gps di Arduino Mega2560
buka serial monitor dengan baudrate 9600 untuk melihat data yang terkirim
akan muncul:

-- belum 3D Fix -- (silahkan tunggu atau coba keluar ruangan untuk dapat sinyal)
Location: Not Available
Date: Not Available
Time: Not Available

-- sudah 3D Fix --
Latitude: xxx
Longitude: xxx
Altitude: xxx
Date: xxx
Time: xxx

kalau tidak dapat di upload atau data tidak muncul pastikan:
driver telah terinstall dengan baik
memilih Mega2560 di board selection
pilih COM yang terdeteksi dengan benar
pilih baudrate pada serial monitor 9600
pastikan koneksinya adalah
Mega2560-TX -> Neo6M-RX
Mega2560-RX <- Neo6M-TX

sudah mengcopy library ke folder ../Arduino/libraries

2black0@gmail.com
http://robot-terbang.web.id

*/

#include <TinyGPS++.h>

TinyGPSPlus gps;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop()
{
  while (Serial1.available() > 0)
  {
    if (gps.encode(Serial1.read()))
      displayInfo();
  }

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println("No GPS detected");
    while (true)
      ;
  }
}

void displayInfo()
{
  if (gps.location.isValid())
  {
    Serial.print("Latitude: ");
    Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: ");
    Serial.println(gps.location.lng(), 6);
    Serial.print("Altitude: ");
    Serial.println(gps.altitude.meters());
  }
  else
  {
    Serial.println("Location: Not Available");
  }

  Serial.print("Date: ");
  if (gps.date.isValid())
  {
    Serial.print(gps.date.month());
    Serial.print("/");
    Serial.print(gps.date.day());
    Serial.print("/");
    Serial.println(gps.date.year());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.print("Time: ");
  if (gps.time.isValid())
  {
    if (gps.time.hour() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.hour());
    Serial.print(":");
    if (gps.time.minute() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.minute());
    Serial.print(":");
    if (gps.time.second() < 10)
      Serial.print(F("0"));
    Serial.print(gps.time.second());
    Serial.print(".");
    if (gps.time.centisecond() < 10)
      Serial.print(F("0"));
    Serial.println(gps.time.centisecond());
  }
  else
  {
    Serial.println("Not Available");
  }

  Serial.println();
  Serial.println();
  delay(1000);
}