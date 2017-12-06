/** Programm : Rückgabewert.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    :
  * Stand    :
  * Status   : Fertig
  * ToDo     : Kommentieren
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : Deklaration zum verlgeichen zweier max Werte
  * Status   : Fertig
  */
  int iMax( int a, int b )
  {
	  if( a > b )
	  {
		  return a;
	  }
	  else
	  {
		  return b;
	  }
  }

/** Funktion : Zahlen eingeben
  * Status   : Fertig
  */	  
  int iEingabe( int iNr )
  {
	  int iEingabe = 0;
	  printf("\n\tBitte die %i.Zahl eingeben: ", iNr);
	  scanf("%i", &iEingabe);
	  return iEingabe;
  }

/** Funktion :liefert Rückgabewerte zurück
  * Status   : Fertig
  */	  
  int iRueckgabe()
  {
	  int i = 2;
	  int iAnzahl = 0;
	  int iMaxim = 0;
	  printf("\n\tZahlen auf Größe vergleichen\n");
	  printf("\n\tWieviel Zahlen eingeben? ");
	  scanf("%i", &iAnzahl);
	  iMaxim = iEingabe(1);
	  for( i = 2; i <= iAnzahl; i++ )
	  {
		  iMaxim = iMax( iEingabe(i), iMaxim);
		  printf("\n\tDie größte Zahl war %i\n", iMaxim);
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iRueckgabe();
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
