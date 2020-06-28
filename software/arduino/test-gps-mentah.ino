/*

Urutan test no 4
Program test untuk gps di Arduino Mega2560
buka serial monitor dengan baudrate 9600 untuk melihat data yang terkirim
akan muncul tulisan yang cukup banyak, contohnya

$GPGGA,...
$GPGLL,...
$GPGSA,...
...

kalau tidak dapat di upload atau data tidak muncul pastikan:
driver telah terinstall dengan baik
memilih Mega2560 di board selection
pilih COM yang terdeteksi dengan benar
pilih baudrate pada serial monitor 9600
pastikan koneksinya adalah
Mega2560-TX -> Neo6M-RX
Mega2560-RX <- Neo6M-TX

2black0@gmail.com
http://robot-terbang.web.id

*/

void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop()
{
  while (Serial1.available() > 0)
  {
    Serial.write(Serial1.read());
  }
}
