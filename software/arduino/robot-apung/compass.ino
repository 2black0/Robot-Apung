void getCompass() {
  Vector norm = compass.readNormalize();
  float heading = atan2(norm.YAxis, norm.XAxis);
  if (heading < 0)
    heading += 2 * M_PI;
  compHead = (int)(heading * 180 / M_PI);
}
