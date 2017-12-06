/** Programm : Aggregatzustand
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    : 14.06.2011
  * Stand    : 14.06.2011
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

/** Funktion : Aggregatzustand ermitteln
  * Status   : in Arbeit
  */
  int iTemperatur()
  {
	  double dTemp = 0.0;
	  printf("\n\tTemperaturen\n");
	  printf("\n\tTemperatur eingeben: ");
	  scanf("%lf", &dTemp);
	  if( dTemp >= 60 )
	  {
		  printf("\n\tWasser verdampft bei %.2f Grad °C", dTemp);
	  }
	  if( dTemp > 0)
	  {
		  printf("\n\tWasser bleibt bei %.2f Grad °C flüssig", dTemp);
	  }
	  if( dTemp <= 0)
	  {
		  printf("\n\tWasser gefriert bei %.2f Grad °C", dTemp);
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iTemperatur();
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
