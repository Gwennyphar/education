/** Programm : vergleichen.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    :
  * Stand    :
  * Status   : Fertig
  * ToDo     : Kommentieren
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : integer Werte kleiner Null abfangen
  * Status   : Fertig
  */
  int i()
  {
	  int iZahl = 0;
	  do
	  {
		  printf("\n\tBitte eine Zahl kleiner Null eingeben: ");
		  scanf("%i" , &iZahl);
	  }while( iZahl >= 0 );
	  printf("\n\tDie Zahl %i ist kleiner Null\n", iZahl);
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      i();
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
