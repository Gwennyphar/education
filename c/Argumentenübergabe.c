#include <stdio.h>
#include <stdlib.h>
#define  BATCH "Batch.csv"

/** Übergabe der Arguemente an das Hauptprogramm
  */
  int iArgument( int argc, char *argv[] ) /* Übergabe von iController */
  {
	  int i     = 0;
	  int x     = 0;
	  int iZahl = 0;
	  double dErg[20] = {0};
	  FILE *FPSchreiben;
	  FPSchreiben = fopen(BATCH, "w");
	  while(--argc)
	  {
		  ++**argv;
		  iZahl = atof( *argv );
		  i++; 
	  }
	  for( x = 1; x <= i; x++ )
	  {  
		  printf("%i %G", i, dErg[i]);
		  fprintf(FPSchreiben, "%i %G", i, dErg[i]);
	  }
	  fclose(FPSchreiben);
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
	  iController( argc , argv ); /* ...und Argumente aus iController */
	  return 0;
  }
