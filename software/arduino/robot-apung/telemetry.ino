String checkCommand() {
  String teleCom;
  while (Serial1.available()) {
    teleCom = Serial1.readString();
    return teleCom;
  }
}
