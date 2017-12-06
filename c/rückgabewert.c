/** Programm : rückgabewert.c
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

/** Funktion : Deklaration zum verlgeichen zweier max Werte
  * Status   : Fertig
  */
  int iMax( int a, int b )
  {
	  if( a > b )
	  {
		  return a;
	  }
	  else
	  {
		  return b;
	  }
  }

/** Funktion : Deklaration zum verlgeichen zweier min Werte
  * Status   : Fertig
  */
  int iMin( int a, int b )
  {
	  if( a < b )
	  {
		  return a;
	  }
	  else
	  {
		  return b;
	  }
  }

/** Funktion : liefert einen Rückgabewert 
  * Status   : Fertig
  */	  
  int iAufruf()
  {
	  int iZahl1 = 0;
	  int iZahl2 = 0;
	  printf("\n\tBitte geben Sie die 1.Zahl ein: ");
	  scanf("%i", &iZahl1);
	  printf("\n\tBitte geben Sie die 2.Zahl ein: ");
	  scanf("%i", &iZahl2);
	  printf("\n\tDie Zahl %i ist größer!\n", iMax(iZahl1, iZahl2) );
	  printf("\n\tDie Zahl %i ist kleiner!", iMin(iZahl1, iZahl2) );
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iAufruf();
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
