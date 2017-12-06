/** Programm : Benzinverbrauch.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    : 
  * Stand    :
  * Status   : in Arbeit
  * ToDo     : programmieren
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion :
  * Status   : in Arbeit
  */
  int iVerbrauch()
  {
	  double dLiter = 0;
	  double dKm = 0;
	  printf("\n\tBenzinverbrauch Berechnen\n");
	  printf("\n\tBenzinverbrauch: ");
	  scanf("%lf", &dLiter);
	  printf("\n\tGefahrene Kilometer: ");
	  scanf("%lf", &dKm);
	  printf("\n\tIhr Benzinverbauch beträgt: %2.f l pro 100 Km", dLiter * 100 / dKm);
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iVerbrauch();
	  return 0; /* Sprung-Anweisung */
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }

/** Programmende
  */
