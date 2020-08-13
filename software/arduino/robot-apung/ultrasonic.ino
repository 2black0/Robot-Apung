void getUltrasonic() {
  rangeLeft = readUltrasonic(trigLPin, echoLPin);
  rangeFront = readUltrasonic(trigFPin, echoFPin);
  rangeRight = readUltrasonic(trigRPin, echoRPin);
}

int readUltrasonic(int trigPin, int echoPin) {
  long duration;
  int distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}
