/** Programm : Zahlen_vergleichen.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    :
  * Stand    :
  * Status   : in Arbeit
  * ToDo     :
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
  int iVergleichen()
  {
	  int x = 0;
	  int y = 0;
	  int z = 0;
	  
	  printf("\n\tZahlen vergleichen\n");
	  printf("\n\tBitte eine Zahl eingeben: ");
	  scanf("%i", &x);
	  printf("\n\tBitte eine Zahl eingeben: ");
	  scanf("%i", &y);
	  printf("\n\tBitte eine Zahl eingeben: ");
	  scanf("%i", &z);
	  printf("\n\tDie größere Zahl lautet: %i", x>y ? z>x ? z : x : z>y ? z : y);
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iVergleichen();
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
