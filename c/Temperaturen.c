/** Programm : Temperaturen.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    : 16.06.2011
  * Stand    : 16.06.2011
  * Status   : in Arbeit
  * ToDo     : Datei anlegen, Kommentieren
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : Temperaturen aller Monate eingeben und anzeigen lassen
  * Status   : in Arbeit
  */
  int iTemp()
  {
	  int i = 0;
	  double dTemp[31]; /* Speicher Temperaturen für 30 Monate ab 0 beginnend */
	  double dGesamt = 0;
	  double dSchnitt = 0;
	  printf("\n\tTemperaturen\n");
	  printf("\n\t\tTagestemperaturen des Monats August\n\n");
	  for( i = 0; i <= 3; i++ )
	  {
		  printf("\n\t%2i.Tag : ", i + 1);
		  scanf("%lf", &dTemp[i]);
	  }
	  printf("\n\tAlle Werte des August.\n");
	  for( i = 0; i <= 30; i++ )
	  {
		  printf("\n\t%2i.Tag : %2.lf °C\n", i + 1, dTemp[i] );
		  for( i = 0; i <= 30; i++ )
		  {
			  dGesamt += dTemp[i];
			  dSchnitt = dGesamt / 31;
			  printf("\n\tDurchschnitt, Temperatur = %2.lf Grad.", dSchnitt);
		  }
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iTemp();
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
