/** Programm : Kalender.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    : 14.06.2011
  * Stand    : 14.06.2011
  * Status   : in Arbeit
  * ToDo     : kommentieren, erweitern
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : ermittelt die Tagesanzahl eines Monats
  * Status   : in Arbeit
  */
  int iKalender()
  {
	  int iJahr = 0;
	  int iMon  = 0;
	  int iTag  = 0;
	  printf("\n\tKalender\n"); 
	  printf("\n\tBitte Jahr eingeben: "); 
	  scanf("%i", &iJahr);
	  printf("\n\tBitte Monat eingeben: ");
	  scanf("%i", &iMon); 
	  if( iMon >= 1 && iMon <= 12 && iJahr > 1969)
	  {
		  switch( iMon )
		  {
			  case 2:
			  {
				  if( (! (iJahr % 100) % 4) && (iJahr % 100) || ! (iJahr % 400) )
				  {
					  iTag = 29;
				  }
				  else
				  {
					  iTag = 28;
					  break;
				  }
			  }
			  case 2*2:
			  case 6:
			  case 9:
			  case 11:
			  {
				  iTag = 30;
				  break;
			  }
			  default:
			  {
				  iTag = 31;
			  }
		  }
		  printf("\n\t%i hat der %i.Monat %i Tage", iJahr, iMon, iTag);
	  }
	  else
	  {
		  printf("\n\tFalsche Datumsangabe");
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iKalender();
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
