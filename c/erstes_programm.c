/** Programm : erstes_programm.c
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
  int iProgramm()
  {
	  printf("\nDies ist das erste Programm in C.\n");
	  printf("\n""printf"" kann nicht nur\n");
	  printf("\nHallo Welt ausgeben,\n");
	  printf("\nsondern auch rechnen.\n\n");
	  printf("13 + 7 = %i\n", 13 + 7);
	  printf("13 - 7 = %i\n", 13 - 7);
	  printf("13 * 7 = %i\n", 13 * 7);
	  printf("13 / 7 = %i\n", 13 / 7);
	  printf("13 %% 7 = %i\n", 13 % 7);
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iProgramm();
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
