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
	  int iAdd  = 0;
	  int i     = 0;
	  int x     = 0;
	  int k     = 0;

	  for( k = 0; k < FILENAME_MAX; k++ )
	  {
		  printf("\n");
	  }
	  printf("__Mein_Calculator__\n");
	  printf("\nZahlen eingeben: ");
	  fflush(stdin);
	  scanf("%i", &iZahlen[i]);
	  while( --argc )
	  {
		  **argv++;
		  iZahlen[i] = atoi( *argv );
		  i++;
	  }
	  printf("\nDas Ergebnis lautet\n");

	  iAdd = iZahlen[0];   /* iAddition mit Werten von iZahlen füllen */
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
