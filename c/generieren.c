/** Programm : gluecksnuss.c
  * Autor	 : Nico Anders
  * Version  : 0.1
  * Datum    : 29.05.2011
  * Stand    : 29.05.2011
  * Status   : in Arbeit
  * ToDo     : bauen
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>
  #define GEN "generator.txt"

/** Funktion : Tipps zufällig auslesen
  * Status   : in Arbeit
  */
  int iNuss()
  {
	  int i       = 0;
	  int iWort1  = 0;
	  int iSek    = 0;
	  char sInhalt[500][FILENAME_MAX];
	  FILE *FPWort1;
	  FPWort1 = fopen(GEN, "r");

	  while( fgets(sInhalt[i], FILENAME_MAX, FPWort1) )
	  {
		  i = i + 1;
	  }
	  fclose(FPWort1);
	  srand( time(NULL) );
	  iWort1 = rand() %i;
	  while( iSek < 1 )
	  {
		  printf("%s", sInhalt[iWort1]);
		  iSek = iSek + 1;
	  };
	  return 0;
  }
	  
/** Steuerprogramm                                                          
  */
  int iController()
  {
      iNuss();
	  return 0; /* Sprung-Anweisung */
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }

/** Programmende
  */
