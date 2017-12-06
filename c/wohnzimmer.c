/** Programm : Wohnzimmer.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    :
  * Stand    :
  * Status   : in Arbeit
  * ToDo     : Kommentieren
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : Quadratmeter berechnen
  * Status   : in Arbeit
  */
  int iFlaeche()
  {
	  double dFlaeche = 0.0;
	  double dGesamt = 0.0;
	  int iAnzahl = 0;
	  printf("\n\tBerechnung der Wohnfläche\n");
	  printf("\n\tBeenden des Programm mit '0'.\n");
	  printf("\n\tZimmergröße in qm : ");
	  scanf("%lf", &dFlaeche);
	  while( dFlaeche > 0.0 )
	  {
		  dGesamt = dGesamt + dFlaeche;
		  iAnzahl = iAnzahl + 1;
		  printf("\n\tZimmergröße in qm : ");
		  scanf("%lf", &dFlaeche);
		  printf("\nAnzahl der Zimmer = %i", iAnzahl);
		  printf("\nGesamtfläche = %.2lf qm", dGesamt);
		  printf("\nDurchschnittliche Zimmergröße = \n%.2lf", dGesamt / iAnzahl);
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iFlaeche();
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
