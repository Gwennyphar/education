// kap011/aufgabe002.c

double Vquader(double a, double b, double c) {
  static double volumen;
  volumen = a * b * c;
  return volumen;
}
