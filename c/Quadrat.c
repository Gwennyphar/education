/** Programm : Quadrat.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    :
  * Stand    :
  * Status   : in Arbeit
  * ToDo     : kommentieren
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : Quadrat rechnen
  * Status   : in Arbeit
  */
  int iQuadrat()
  {
	  int iZahl = 0;
	  printf("\n\tQuadratrechnen '0'Beenden\n");
	  printf("\n\tBitte Zahl eingeben: ");
	  scanf("%i", &iZahl);
	  while( iZahl != 0 )
	  {
		  printf("\n\t%3i ^ 2 = %4i\n", iZahl, iZahl * iZahl);
		  printf("\n\tBitte Zahl eingeben: ");
		  scanf("%i", &iZahl);
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iQuadrat();
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
