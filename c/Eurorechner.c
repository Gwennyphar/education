/** Programm : Eurorechner
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

/** Funktion : Euro und DM umrechnen
  * Status   : in Arbeit
  */
  int iRechner()
  {
	  int    iWahl   =   0;
	  double dBetrag = 0.0;
	  printf("\n\tEurorechner\n");
	  printf("\n\t<1> DM   --> Euro\n\t<2> Euro --> DM\n");
	  printf("\n\tBitte auswählen: ");
	  scanf("%i", &iWahl);
	  if( iWahl == 1 )
	  {
		  printf("\n\tBitte DM-Betrag eingeben: ");
		  scanf("%lf", &dBetrag);
		  printf("\n\t%.2f DM = %.2f Euro", dBetrag, dBetrag * 0.51129);
	  }
	  if( iWahl == 2 )
	  {
		  printf("\n\tBitte Euro-Betrag eingeben: ");
		  scanf("%lf", &dBetrag);
		  printf("\n\t%.2f Euro = %.2f DM", dBetrag, dBetrag * 1.95583);
	  }
	  else
	  {
		  printf("\n\tUngültige Eingabe!");
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iRechner();
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
