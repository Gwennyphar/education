/** Programm : Mein Calculator.c
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
	  int iAdd  = 0;
	  int iSub  = 0;
	  int iMult = 0;
	  int iDiv  = 0;
	  int iRest = 0;
	  int i     = 0;
	  int x     = 0;
	  int k     = 0;

	  for( k = 0; k < FILENAME_MAX; k++ )
	  {
		  printf("\n");
	  }
	  printf("__Mein_Calculator__\n");
	  printf("\nDas Ergebnis lautet\n");
	  while( --argc )
	  {
		  **argv++;
		  iZahlen[i] = atoi( *argv );
		  i++;
	  }
	  iAdd = iZahlen[0];   /* iAddition mit Werten von iZahlen füllen */
	  iSub = iZahlen[0];/* iSubtraktion mit Werten von iZahlen füllen */
	  iMult = iZahlen[0]; /* iMultipli. mit Werten von iZahlen füllen */
	  iDiv = iZahlen[0];   /* iDivision mit Werten von iZahlen füllen */
	  for( x = 1; x < i; x++ )
	  {
		  iAdd += iZahlen[x];
		  if( x == 1)
		  {
			  printf("%i + %i", iZahlen[0] , iZahlen[x]);
		  }/* Ausdrucksanweisung */
		  else
		  {
			   printf(" + %i", iZahlen[x]);
		  }
	  } 
	  printf(" = %i\n" , iAdd);

	  for( x = 1; x < i; x++ )
	  {
		  iSub -= iZahlen[x];
		  if( x == 1)
		  {
			  printf("%i - %i", iZahlen[0] , iZahlen[x]);
		  }/* Ausdrucksanweisung */
		  else
		  {
			   printf(" - %i", iZahlen[x] );    /* Ausdrucksanweisung */
		  }
	  } 
	  printf(" = %i\n" , iSub);

	  for( x = 1; x < i; x++ )
	  {
		  iMult *= iZahlen[x];
		  if( x == 1)
		  {
			  printf("%i * %i", iZahlen[0], iZahlen[x]);
		  }/* Ausdrucksanweisung */
		  else
		  {
			   printf(" * %i", iZahlen[x] );
		  }
	  } 
	  printf( " = %i\n" , iMult );

	  for( x = 1; x < i; x++ )
	  {
		  iDiv /= iZahlen[x];
		  iRest = iDiv - iZahlen[0];
		  if( x == 1)
		  {
			  printf("%i / %i", iZahlen[0] , iZahlen[x]);
		  }/* Ausdrucksanweisung */
		  else
		  {
			   printf(" / %i", iZahlen[0] );
		  } /* Ausdrucksanweisung */
	  } 
	  printf(" = %i Rest %i\n", iDiv, iRest ); /* Ausdrucksanweisung */
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
