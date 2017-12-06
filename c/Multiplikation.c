/** Programm : Multiplikation.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    : 14.06.2011
  * Stand    : 14.06.2011
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

/** Funktion : 1 x 1 Reihen
  * Status   : in Arbeit
  */
  int iMulti()
  {
	  int x        = 0;
	  int y        = 0;
	  printf("\n\tDas Große 1 x 1\n");
	  for( x = 1; x <= 20; x = x + 1 )   /* äußere Schleife */
	  {
		  printf("\n");
		  for( y = 1; y <= 20; y = y + 1 ) /* innere Schleife */
		  {
			  printf("%4i", x*y);
		  }
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iMulti();
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
