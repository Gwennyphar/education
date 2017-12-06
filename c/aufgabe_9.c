/** Programm : Aufabe_9.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    :
  * Stand    :
  * Status   : Fertig
  * ToDo     :
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
  int iAufgabe()
  {
	  double iSumme = 10;
	  double iZahl = 10;
	  iSumme = iSumme + iZahl;
	  iSumme = iSumme + iZahl;
	  printf("Ergebnis = %f", iSumme);
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iAufgabe();
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
