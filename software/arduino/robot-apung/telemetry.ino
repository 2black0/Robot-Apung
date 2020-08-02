void checkCMD(){
  cmd = "";
  cmds = "";
  
  while (Serial1.available()) {
    cmds = Serial1.readString();
    cmd = cmds.substring(0, 3);
    countcmds++;
    if(countcmds >= 100) break;
  }
}

/*String checkCommand() {
  String teleCom;
  while (Serial1.available()) {
    teleCom = Serial1.readString();
    return teleCom;
  }
}*/
