/** Programm : Herzschlag
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    :
  * Stand    :
  * Status   : Fertig
  * ToDo     :
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : Herzschlaege zaehlen
  * Status   : in Arbeit
  */
  int i()
  {
	  int iSchlaege;
	  int iAlter;
	  printf("\n\tHerzschläge\n");
	  printf("\n\tHerzschläge pro Minute: ");
	  scanf("%i", &iSchlaege);
	  printf("\n\tAlter in Jahren: ");
	  scanf("%i", &iAlter);
	  printf("\n\tIhr Herz hat seit ihrer Geburt \n");
	  printf("\n\t%1.f \n", iSchlaege * 60 *24 *365.25 * iAlter);
	  printf("\n\tmal geschlagen.");
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
