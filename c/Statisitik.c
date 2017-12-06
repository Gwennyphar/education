/** Programm : Statistik.c
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

/** Funktion : Statistiken auswerten
  * Status   : in Arbeit
  */
  int iStat()
  {
	  int    i        =   0;
	  int    iAnzahl  =   0;
	  double dZahl    = 0.0;
	  double dSum     = 0.0;
	  double dSchnitt = 0.0;
	  char sEingabe[FILENAME_MAX];
	  printf("\n\tStatistik\n");
	  printf("\n\tFür was soll die Statistik die erfasst werden? ");
	  fgets(sEingabe, FILENAME_MAX, stdin);
	  printf("\n\tWieviel Werte wollen Sie erfassen? ");
	  scanf("%i", &iAnzahl);
	  printf("\n");
	  for( i = 1; i <= iAnzahl; i = i +1 )
	  {
		  printf("\n\tBitte %i.Zahl eingeben: ", i);
		  scanf("%lf", &dZahl);
		  dSum = dSum + dZahl;
	  }
	  dSchnitt = dSum / iAnzahl;
	  printf("\n\n\tSumme der Zahlen      = %f %s", dSum, sEingabe);
	  printf("\n\n\tMittelwert der Zahlen = %f %s", dSchnitt, sEingabe);
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iStat();
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
