#include <stdio.h>
#include <stdlib.h>
#define  BATCH "Batch.csv"

/** Argumente
  */
  int iArgument( int argc, char *argv[] ) /* Übergabe von iController */
  {
	  int iZahlen[10] = {0};                         /* Deklarationen */
	  int iErgebnis  = 0;
	  int i = 0;
	  int x = 0;
	  FILE *FPSchreiben;
	  FPSchreiben = fopen( BATCH, "w");
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
			  printf(" %i * %i", iZahlen[0] , iZahlen[x] ); /* Ausdrucksanweisung */
			  fprintf(FPSchreiben, "%i * %i = %i", iZahlen[0] , iZahlen[x], iErgebnis );
		  }
		  else
		  {
			  printf(" * %i", iZahlen[x] );
		  }
	  } 
	  printf( " = %i\n" , iErgebnis );
	  fclose(FPSchreiben);
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
  

