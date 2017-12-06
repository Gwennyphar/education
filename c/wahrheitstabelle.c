/** Programm : wahrheitstabelle.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    : 19.05.2011
  * Stand    : 19.05.2011
  * Status   : in Arbeit
  * ToDo     : kommentieren
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion :
  * Status   : in Arbeit
  */
  int iTabelle()
  {
	  int TC1 = 0;
	  int TC2 = 0;
	  int TC3 = 0;
	  int CED = 0;
	  printf("\n\tTrue-False Tabelle\n");
	  printf("\n\tC1\tC2\tC3\tCED\n");
	  TC1 = 0; TC2 = 0; TC3 = 0 ; CED =! (TC1&&!TC2&&!TC3);
	  printf("\nTC1\t%i\t%i\t%i\t%i", TC1, TC2, TC3, CED);
	  TC1 = 0; TC2 = 1; TC3 = 0 ; CED =! (TC1&&!TC2&&!TC3);
	  printf("\nTC2\t%i\t%i\t%i\t%i", TC1, TC2, TC3, CED);
	  TC1 = 0; TC2 = 0; TC3 = 1 ; CED =! (TC1&&!TC2&&!TC3);
	  printf("\nTC3\t%i\t%i\t%i\t%i", TC1, TC2, TC3, CED);  
	  TC1 = 1; TC2 = 0; TC3 = 0 ; CED =! (TC1&&!TC2&&!TC3);
	  printf("\nTC4\t%i\t%i\t%i\t%i", TC1, TC2, TC3, CED);  
	  TC1 = 1; TC2 = 0; TC3 = 1 ; CED =! (TC1&&!TC2&&!TC3);
	  printf("\nTC5\t%i\t%i\t%i\t%i", TC1, TC2, TC3, CED);  
	  TC1 = 0; TC2 = 1; TC3 = 1 ; CED =! (TC1&&!TC2&&!TC3);
	  printf("\nTC6\t%i\t%i\t%i\t%i", TC1, TC2, TC3, CED);  
	  TC1 = 1; TC2 = 1; TC3 = 1 ; CED =! (TC1&&!TC2&&!TC3);
	  printf("\nTC7\t%i\t%i\t%i\t%i", TC1, TC2, TC3, CED);
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iTabelle();
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
