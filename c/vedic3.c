/** Programm : vedic.c
  * Autor	 : nico
  * Version  : 0.1
  * Datum    : TT.MM.JJ
  * Stand    : TT.MM.JJ
  * Status   : in Planung
  * ToDo     : ab
  * 		   cd
  *           ----
  *           abwx
  */


/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>
  #define ZAHLEN 1


/** Funktion : Beschreibung der Funktion
  * Status   : in Planung
  */
  int iVedic()
  {

	  int a[ZAHLEN];
	  int b[ZAHLEN];
	  int c[ZAHLEN];
	  int d[ZAHLEN];
	  int x[ZAHLEN]; /* Hilfsvariable */
	  srand(time(NULL));
	  a[ZAHLEN] = ( rand() % 9 + 1 );
	  b[ZAHLEN] = ( rand() % 9 + 1 );
	  c[ZAHLEN] = ( rand() % 9 + 1 );
	  d[ZAHLEN] = ( rand() % 9 + 1 );
	  printf("\n\tVedische Regel: Vertikal und Kreuzweise\n");
	  printf("\t---------------------------------------\n\n");
	  printf("\t  %i%i\n",a[ZAHLEN], b[ZAHLEN]);
	  printf("\t* %i%i\n",c[ZAHLEN], d[ZAHLEN]);
	  printf("\t-----\n");	  
	  x[ZAHLEN] = d[ZAHLEN]*b[ZAHLEN]; /* letzte reihe von unten nach oben */
	  d[ZAHLEN] = d[ZAHLEN]*a[ZAHLEN]; /* von rechts nach links */
	  b[ZAHLEN] = c[ZAHLEN]*b[ZAHLEN]; /* von links nach rechts */
	  d[ZAHLEN] = d[ZAHLEN]+b[ZAHLEN]; /* Zwischenergbenisse addieren */
	  a[ZAHLEN] = c[ZAHLEN]*a[ZAHLEN]; /* erste reihe von unten nach oben */
	  printf("\t= %i %i %i\n", a[ZAHLEN], d[ZAHLEN], x[ZAHLEN]); /* Ausgabe */
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iVedic();
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
