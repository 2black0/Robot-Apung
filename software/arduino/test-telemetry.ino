/*

Urutan test no 7
Program test untuk gps di Arduino Mega2560
buka serial monitor dengan baudrate 9600 untuk melihat data yang terkirim
akan muncul tulisan yang dikirim melalui hp Android

kalau tidak dapat di upload atau data tidak muncul pastikan:
driver telah terinstall dengan baik
memilih Mega2560 di board selection
pilih COM yang terdeteksi dengan benar
pilih baudrate pada serial monitor 9600
pastikan koneksinya adalah
Mega2560-TX -> Telemetry-RX
Mega2560-RX <- Telemetry-TX

2black0@gmail.com
http://robot-terbang.web.id

*/

void setup()
{
  Serial.begin(9600);
  Serial2.begin(9600);
}

void loop()
{
  while (Serial2.available() > 0)
  {
    Serial.write(Serial2.read());
  }
}
