#include <stdio.h>
#include <math.h>

int main(void)
{
  double parameter, ergebnis;
  parameter = 36.0;
  ergebnis = sqrt (parameter);
  printf ("sqrt(%lf) = %lf\n", parameter, ergebnis );
  system("pause");
  return 0;
}
