/** Programm : .c
  * Autor	 : 
  * Version  : 0.1
  * Datum    : TT.MM.JJ
  * Stand    : TT.MM.JJ
  * Status   : in Planung
  * ToDo     :
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : 1000 Dateien erzeugen mit ftl. Nummer
  * Status   : in Arbeit
  */
  int iIndex()
  {
	  int i = 0;
	  time_t t;
	  time(&t);
	  char cDatei[255];
	  FILE *FPDatei[1000];
	  printf("Programmstart\n");
	  /* Dateiname mit fortlaufender Nummer erzeugen */
	  sprintf(cDatei,cDatei, "%s %s", ctime(&t));
	  FPDatei[i] = fopen( cDatei, "w");
	  if( FPDatei[i] != NULL)
	  {
		  fprintf( FPDatei[i], "Ergebnis der Berechnung Nr.%i", i);
	  }
	  else
	  {
		  fprintf(stderr, "Ergebnis der Berechnung Nr.%i", i);
	  }
	  return EXIT_SUCCESS;
  }
 
/** Steuerprogramm                                                          
  */
  int iController()
  {
      iIndex();
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
