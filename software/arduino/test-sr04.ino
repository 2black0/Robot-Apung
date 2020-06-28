/*

Urutan test no 3
Program test untuk serial usb Arduino Mega2560
buka serial monitor dan set baudrate 9600 untuk menampilkan data yang dikirim
akan muncul tulisan 'Distance: x' dimana x adalah jarak benda yang ada didepan sensor ultrasonik

kalau tidak dapat di upload atau data tidak muncul pastikan:
driver telah terinstall dengan baik
memilih Mega2560 di board selection
pilih COM yang terdeteksi dengan benar
pilih baudrate pada serial monitor 9600
kabel SR04:
SR04-Trigger <- Mega2560-31
SR04-Echo <-> Mega2560-33

2black0@gmail.com
http://robot-terbang.web.id

*/

const int trigPin = 31;
const int echoPin = 33;

long duration;
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);
}