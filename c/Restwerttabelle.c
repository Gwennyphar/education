/** Programm : Restwerttabelle.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    :
  * Stand    :
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

/** Funktion : Abschreibung berechnen
  * Status   : in Arbeit
  */
  int iTabelle()
  {
	  int y = 0;
	  int x = 0;
	  double dPreis = 0;
	  double dRest  = 0;
	  printf("\n\tRestwertetabelle\n");
	  printf("\n\tBitte Neupreis in € eingeben: ");
	  scanf("%lf", &dPreis);
	  printf("\n\tAFA - Zeitraum\n");
	  printf("\n\tJahr\t8 Jahre\t6 Jahre\t4 Jahre");
	  for( x = 1; x <= 8; x++ ) /* äußere Schleife */
	  {
		  printf("\n\t%i\t", x);
		  for( y = 8; y >= 4; y = y -2) /* innere Schleife zählt solange
										   bis der Wert kleiner als 0 ist */
		  {
			  dRest = dPreis - x * dPreis / y;
			  if( dRest < 0 )
			  
				  break; /* Schleife wird abgebrochen und neue Zeile ausgegeben */
				  printf("%8.2f", dRest);  
		  }
	  }	  
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
