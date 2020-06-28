/*

Urutan test no 6
Program test untuk gps di Arduino Mega2560
buka serial monitor dengan baudrate 9600 untuk melihat status dan data yang terkirim
motor akan berputar sesuai dengan program yang dibuat

kalau tidak dapat di upload atau data tidak muncul pastikan:
driver telah terinstall dengan baik
memilih Mega2560 di board selection
pilih COM yang terdeteksi dengan benar
pilih baudrate pada serial monitor 9600

2black0@gmail.com
http://robot-terbang.web.id

*/

int enA = 2;
int in1 = 3;
int in2 = 4;
int enB = 7;
int in3 = 5;
int in4 = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop()
{
  directionControl();
  delay(1000);
  speedControl();
  delay(1000);
}

void directionControl()
{
  Serial.println("Set Max Speed Motor A & B : 255");
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  Serial.println("Turning On Motor A & B");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);

  Serial.println("Changin Direction Motor A & B");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);

  Serial.println("Turning Off Motor A & B");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void speedControl()
{
  Serial.println("Turning On Motor A & B");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  Serial.println("Change Speed of Motor A & B from 0 to 255");
  for (int i = 0; i < 256; i++)
  {
    Serial.print("Speed Motor: ");
    Serial.println(i);
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }

  Serial.println("Change Speed of Motor A & B from 255 to 255");
  for (int i = 255; i >= 0; --i)
  {
    Serial.print("Speed Motor: ");
    Serial.println(i);
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }

  Serial.println("Turning Off Motor A & B");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}