/** Programm : multiplizieren.c
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
	  int x    = 0;
	  int iNte = 0;
	  int iPro = 1;
	  /* for Schleife */
	  printf("\n\tBitte den Wert für nte eingeben: ");
	  scanf("%i", &iNte);
	  printf("\n\tErgebnis aller multiplizierten Zahlen mit:\n");
	  for( x = 1; x <= iNte; x = x + 1 )
	  {
		  iPro = iPro * x;
		  printf("\n\t %i = %i", iNte, iPro);  
	  }
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
