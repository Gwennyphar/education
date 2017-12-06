/** Programm : Schaltjahre.c
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

/** Funktion : Schaltjahre berechnen
  * Status   : in Arbeit
  */
  int iJahr()
  {
	  int iDatum;
	  printf("\n\tSchaltjahre\n");
	  for( iDatum = 2010; iDatum <= 2030; iDatum++ )
	  {
		  printf("\n\t%i", iDatum);
		  if( iDatum %4 )
		  {
			  continue;
		  }
			  printf(" = Schaltjahr");
		  
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iJahr();
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
