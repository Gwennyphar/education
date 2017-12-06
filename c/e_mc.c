#include <stdio.h>
#include <math.h>

/** Steuerprogramm
  */
  int iController()
  {
	  float E = 0.00;
	  float m = 0.00;
	  float c = 3.0;
	  char  sEingabe[11];
	  printf("\n\tGewicht eingeben: ");
	  fgets(sEingabe, sizeof(sEingabe), stdin);
	  sscanf(sEingabe,"%g", &m);
	  E = m * c * c;
	  printf("\n\tDas Objekt hat %.2lf Joule. ", E);
	  fgetc(stdin);
	  return 0;
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }

