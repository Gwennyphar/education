#include <stdio.h>
#include <stdlib.h>

/** Argumente an Hello World
  */
  int iArgument( int argc, char *argv[])
  {
	  int i = 0;
	  argv[1] = "Hallo Welt";
	  argv[2] = "ich grüße dich!";
	  for( i = 0; i < argc; i++ )
	  {
		  printf("Argument[%i]      : %s\n", i, argv[i]);
		  printf("Argument[%i]      : %s, %s\n", i, argv[1], argv[2]);
		  printf("Argumente Gesamt : %i\n", argc-1);
		  printf("Letztes Argument : %s\n", argv[argc-1]);
		  printf("\n");
	  }
	  return EXIT_SUCCESS;
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
