#include <stdio.h>
#include <stdlib.h>

/** Argumente
  */
  int iArgument( int argc, char *argv[] ) /* Übergabe von iController */
  {
	  int iZahlen[10] = {0};                         /* Deklarationen */
	  int iErgebnis  = 0;
	  int iSum  = 0;
	  int iDiff = 0;
	  int iQuo = 0;
	  int i = 0;
	  int x = 0;
	  while( --argc )
	  {
		  **argv++;
		  iZahlen[i] = atoi( *argv );
		  i++;
	  }
	  iErgebnis = iZahlen[0]; /* iErgebnis mit Werten von iZahlen füllen */
	  for( x = 1; x < i; x++ )
	  {
		  iErgebnis *= iZahlen[x];
		  if( x == 1)
		  {
			  printf(" %i * %i", iZahlen[0] , iZahlen[x]); /* Ausdrucksanweisung */
		  }
		  else
		  {
			   printf(" * %i", iZahlen[x] );
		  }
	  } 
	  printf( " = %i\n" , iErgebnis );

	  iSum = iZahlen[0]; /* iErgebnis mit Werten von iZahlen füllen */
	  for( x = 1; x < i; x++ )
	  {
		  iSum += iZahlen[x];
		  if( x == 1)
		  {
			  printf(" %i + %i", iZahlen[0] , iZahlen[x]); /* Ausdrucksanweisung */
		  }
		  else
		  {
			   printf(" + %i", iZahlen[x] );
		  }
	  } 
	  printf( " = %i\n" , iSum );

	  iDiff = iZahlen[0]; /* iErgebnis mit Werten von iZahlen füllen */
	  for( x = 1; x < i; x++ )
	  {
		  iDiff -= iZahlen[x];
		  if( x == 1)
		  {
			  printf(" %i - %i", iZahlen[0] , iZahlen[x]); /* Ausdrucksanweisung */
		  }
		  else
		  {
			   printf(" - %i", iZahlen[x] );
		  }
	  } 
	  printf( " = %i\n" , iDiff );

	  iQuo = iZahlen[0]; /* iErgebnis mit Werten von iZahlen füllen */
	  for( x = 1; x < i; x++ )
	  {
		  iQuo /= iZahlen[x];
		  if( x == 1)
		  {
			  printf(" %i / %i", iZahlen[0] , iZahlen[x]); /* Ausdrucksanweisung */
		  }
		  else
		  {
			   printf(" / %i", iZahlen[x] );
		  }
	  } 
	  printf( " = %i\n" , iQuo );
	  return 0;                                   /* Sprung-Anweisung */
}

/** Steuerprogramm
  */
  int iController( int argc, char *argv[] )      /* Übergabe von main */
  {
	  iArgument( argc, argv );  /* ...hier iArguemente an iController */
	  return 0;
  }

/** Hauptprogramm
  */
  int main( int argc, char *argv[] )           /* Arguemetenuebergabe */
  {
	  iController( argc, argv );  /* ...und Argumente aus iController */
	  return 0;
  }
  

