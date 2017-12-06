#include <stdio.h>
#include <stdlib.h>

/** Argumente
  */
  int iArgument( int argc, char *argv[] ) /* Übergabe von iController */
  {
	  int a = 3;                                     /* Deklarationen */
	  int b = 5;
	  int c = 0;
	  int i;
	  c = a + b;
	  while( --argc )
	  {
		  ++**argv;
		  c = atoi( *argv );
		  i++;
	  }
	  printf("%i + %i = %i\n", a, b, c); /* Ausdrucksanweisung */

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
  
