/** Programm : vedic.c
  * Autor	 : 
  * Version  : 0.1
  * Datum    : TT.MM.JJ
  * Stand    : TT.MM.JJ
  * Status   : in Planung
  * ToDo     : a*b = {a-(k-b)} k +(k-b)(k-a) = a*b
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : Beschreibung der Funktion
  * Status   : in Planung
  */
  int iVedic()
  {
	  int a = 0;
	  int b = 0;
	  int k = 0;
	  int x = 0;
	  printf("\n\tVedische Regel: Vertikal und Kreuzweise\n");
	  printf("\t----------------------------------------\n\n");
	  printf("\tBitte gebe die 1.Zahl ein: ");
	  fflush(stdin);
	  scanf("%i", &a);
	  printf("\tBitte gebe die 2.Zahl ein: ");
	  fflush(stdin);
	  scanf("%i", &b);
	  
   /* Algorithmus zum multiplizieren */
	  printf("\n\tVedische Regel: Einer mehr als der zuvor\n");
	  printf("\t----------------------------------------\n\n");
	  printf("\t  %4i", a);
	  printf("\n\t* %4i", b);
	  printf("\n\t----------------------------------------\n");
	  
	  printf("\t= %4i => (%i-(%i-%i))*%i+(%i-%i)*(%i-%i)",
	  x = ( a - (k - b) )* k + ( k - b )*( k - a ) );
	  
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
