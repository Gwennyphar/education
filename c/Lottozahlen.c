/** Programm : Lotto
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

/** Funktion : fakultaet aus 6 aus 49 berechnen
  * Status   : in Arbeit
  */
  double fakultaet( int Zahl )
  {
	  int i = 1;
	  double Ergebnis = 1.0;
	  for( i = 1; i <= Zahl; i++ );
	  Ergebnis = Ergebnis * i;
	  return(Ergebnis);
  }
  
/** Funktion : Ausgabe der möglichen Lottozahlen
  * Status   : in Arbeit
  */
  int main()
  {
	  double Ergebnis;
	  Ergebnis = fakultaet(49) / (fakultaet(43) * fakultaet(6) ) ;
	  printf("\n\tDie Anzahl der möglichen fakultaeten ");
	  printf("im Lotto 6 aus 49 ist: %.0f \n", Ergebnis);
	  return 0;
  }
