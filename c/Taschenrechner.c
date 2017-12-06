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
	  int iPro  = 0;
	  int iSum  = 0;
	  int iDiff = 0;
	  int iQuo  = 0;
	  int iZahl = 0;
	  int iRest = 0;
	  int i     = 0;
	  int x     = 0;
	  printf("__Mein_Calculator__\n");
	  printf("Das Ergebnis lautet\n");
	  while( --argc )
	  {
		  **argv++;
		  iZahlen[i] = atoi( *argv );
		  i++;
	  }
	  
	  iSum = iZahlen[0];        /* iSum mit Werten von iZahlen füllen */
	  for( x = 1; x < i; x++ )
	  {
		  iSum += iZahlen[x];
		  if( x == 1)
		  {
			  printf(" %i + %i", iZahlen[0] , iZahlen[x]);
		  }/* Ausdrucksanweisung */
		  else
		  {
			   printf(" + %i", iZahlen[x] );
		  }
	  } 
	  printf( " = %i\n" , iSum );

	  iDiff = iZahlen[0]; /* iDifferenz mit Werten von iZahlen füllen */
	  for( x = 1; x < i; x++ )
	  {
		  iDiff -= iZahlen[x];
		  if( x == 1)
		  {
			  printf(" %i - %i", iZahlen[0] , iZahlen[x]);
		  }/* Ausdrucksanweisung */
		  else
		  {
			   printf(" - %i", iZahlen[x] );    /* Ausdrucksanweisung */
		  }
	  } 
	  printf( " = %i\n" , iDiff );

	  iPro = iZahlen[0]; /* iProdukt mit Werten von iZahlen füllen */
	  for( x = 1; x < i; x++ )
	  {
		  iPro *= iZahlen[x];
		  if( x == 1)
		  {
			  printf(" %i * %i", iZahlen[0] , iZahlen[x]);
		  }/* Ausdrucksanweisung */
		  else
		  {
			   printf(" * %i", iZahlen[x] );
		  }
	  } 
	  printf( " = %i\n" , iPro );

	  iQuo = iZahlen[0]; /* iQuotient mit Werten von iZahlen füllen */
	  for( x = 1; x < i; x++ )
	  {
		  iQuo /= iZahlen[x];
		  iRest = iQuo - iZahlen;
		  if( x == 1)
		  {
			  printf(" %i / %i", iZahlen[0] , iZahlen[x]);
		  }/* Ausdrucksanweisung */
		  else
		  {
			   printf(" / %i", iZahlen[0] );
		  } /* Ausdrucksanweisung */
	  } 
	  printf( " = %i Rest %i\n", iQuo, iRest ); /* Ausdrucksanweisung */
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
