/** Programm : Mein Taschenrechner.c
  * Autor	 : Nico Anders
  * Version  : 3.0 simple & stable
  * Datum    : 20.05.2011
  * Stand    : 20.05.2011
  * Status   : in Arbeit
  * ToDo     : % Modulo Funktion korrigieren
  *            Gleitkommazahlen einbauen
  *            in bestehendes Taschenrechner-Programm implentieren
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : Taschenrechner-Programm
  * Status   : in Arbeit
  */
  int iRechner( int argc, char *argv[] ) /* Übergabe von iController */
  {
   /* Deklarationen */
	  int iZahlen[10] = {0};
	  int iAdd        =   0;
	  int iSub        =   0;
	  int iMult      =   0;
	  int iDiv        =   0;
	  int iZahl       =   0;
	  int iRest       =   0;
	  int i           =   0;
	  int x           =   0;
	  printf("__Mein_Calculator__\n");
	  printf("\nDas Ergebnis lautet\n");
	  while( --argc )
	  {
		  **argv++;
		  iZahlen[i] = atoi( *argv );
		  i++;
	  }
	  
	  iAdd = iZahlen[0];        /* iAdd mit Werten von iZahlen füllen */
	  for( x = 1; x < i; x++ )
	  {
		  iAdd += iZahlen[x];
		  iSub -= iZahlen[x];
		  iMult *= iZahlen[x];
		  iDiv /= iZahlen[x];
		  iRest = iDiv - iZahl;
	   /* Ausdrucksanweisung */
		  if( x == 1)
		  {
			  printf(" %i + %i = %i\n", iZahlen[0], iZahlen[x], iAdd);
			  printf(" %i - %i = %i\n", iZahlen[0], iZahlen[x], iSub);
			  printf(" %i * %i = %i\n", iZahlen[0], iZahlen[x], iMult);
			  printf(" %i / %i = %i Rest %i\n", iZahlen[0], iZahlen[x], iDiv, iRest);  
		  }
		  else
		  {
			  printf(" + %i", iZahlen[x]);
			  printf(" - %i", iZahlen[x]);
			  printf(" * %i", iZahlen[x]);
			  printf(" / %i", iZahlen[x]);
		  }
	  }
	  return 0;                                   /* Sprung-Anweisung */
}

/** Steuerprogramm                                                          
  */
  int iController( int argc, char *argv[] )
  {
      iRechner( argc, argv );
	  return 0; /* Sprung-Anweisung */
  }

/** Hauptprogramm
  */
  int main( int argc, char *argv[] )
  {
	  iController( argc, argv );
	  return 0;
  }

/** Programmende
  */
