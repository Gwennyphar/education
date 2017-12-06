#include <stdio.h>
#include <stdlib.h>
#include <time.h>                    /* Headerdatei für Zeitmessungen */
#define  BATCH "Batch.txt"                /* Definition für Textdatei */
#define  TEST  "Datenbank.csv"            /* Definition für Testdatei */

/** Argumente
  */
  int iArgument( int argc, char *argv[] ) /* Übergabe von iController */
  {
   /* Deklarationen */
	  int iZahlen[10] = {0};
	  char sContainer[20] = {0};
	  int iZufall     = 0;
	  int i = 0;
	  int x = 0;
   /* Datezeiger */
	  FILE *FPSchreiben, *FPTesten;
   /* Erzeugen von Textateien */
	  FPSchreiben = fopen( BATCH, "a+");
	  FPTesten = fopen( TEST, "a+");
	  srand(time(NULL) );
	  while( --argc )
	  {
		  **argv++;
		  iZahlen[i] = atoi( *argv );
		  i++;
	  }
   /* iContainer mit Werten von iZahlen füllen */
	  sContainer[i] = iZahlen[0];
	  
	  for( x = 1; x < i; x++ )
	  {
		  sContainer[i] = rand() %iZufall +10000;
		  if( x == 1)
		  {
		   /* Ausdrucksanweisung */
			  printf(" %i * %i", iZahlen[0] , iZahlen[x] );
			  fprintf(FPSchreiben, "%i * %i", iZahlen[0], iZahlen[x] );
		  }
		  else
		  {
			   printf(" * %i", iZahlen[x] );
			   fprintf(FPSchreiben, " * %i", iZahlen[x] );
		  }
	  } 
	  printf( " = %s\n" , sContainer );
	  fprintf(FPSchreiben, " = %s\n", sContainer );
	  fclose(FPTesten);
   /* Sprung-Anweisung */
	  return 0;  
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
