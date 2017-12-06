/** Programm : addieren.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    :
  * Stand    :
  * Status   : in Arbeit
  * ToDo     : Kommentieren
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : alle ungeraden Zahlen bis nte addieren
  * Status   : in Arbeit
  */
  int i()
  {
	  int x     = 0;
	  int iNte  = 0;
	  int iSum  = 0;
	  int iSumm = 0;
	  /* for Schleife */
	  printf("\n\tBitte den Wert für nte eingeben: ");
	  scanf("%i", &iNte);
	  for( x = 1; x <= iNte; x = x + 2 )
	  {
		  iSum = iSum + x;  
	  }
	  printf("\n\tSumme aller ungeraden Zahlen von:\n");
	  printf("\n\t1 bis %i = %i\n", iNte, iSum);
	  /* while Schleife */
	  x = 1;
	  while( x <= iNte )
	  {
		  iSumm = iSumm + x; 
		  x = x + 2; 
	  }
	  printf("\n\tSumme aller ungeraden Zahlen von:\n");
	  printf("\n\t1 bis %i = %i", iNte, iSumm);
	  
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      i();
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
