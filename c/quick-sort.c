/** Programm : bubble-sort.c
  * Autor	 : nico Anders
  * Version  : 0.1
  * Datum    : 
  * Stand    : 
  * Status   : in Arbeit
  * ToDo     :
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define MAX 50000

/** Funktion : das Array zum Sortieren
  * Status   : akzeptiert 
  */
  int iFeld[MAX];

  void Qsort(int*, int*);

/** Funktion : Werte in Feldern initialisieren
  * Status   : in Arbeit
  */
  int iFeld_init()
  {
	  int i = 0;
	  int j = 0;
	  for( i = MAX,j=0; i >= 0; i--,j++ )
	  {
		  iFeld[j] = i;
	  }
	  return EXIT_SUCCESS;
  }
/** Funktion : Werte aufsteigend vergleichen und tauschen
  * Status   : in Arbeit
  */
  int iAusgabe()
  {
	  int i;
	  for( i= 0; i < MAX; i++ )
	  {
		  printf("%d ",iFeld[i]);
	  }
	  return EXIT_SUCCESS;
  }

/** Funktion     : Werte aufsteigend vergleichen und tauschen
  * Beschreibung : Die Funktion erhält einen Zeiger auf das erste
  *                und einen zweiten Zeiger auf das letzte Element.
  *                Hier werden dazu die Namen »iLinks« und »iRechts« verwendet.
  * Status       : in Arbeit
  */
  int iQuicksort(int *iLinks, int *iRechts)
  {
	  int *iPtr1 = iLinks;
	  int *iPtr2 = iRechts;
	  int w = 0;
	  int x = 0;
   /* x bekommt die Anfangsadresse der
    * Mitte von iLinks und iRechts.
    * Anstatt der Bitverschiebung hätten Sie
    * auch einfach »geteilt durch 2« rechnen können.
    */
      x = *(iLinks + (iRechts - iLinks >> 1) );
      do
      {
		  while(*iPtr1 < x) iPtr1++;
		  while(*iPtr2 > x) iPtr2--;
		  if(iPtr1 > iPtr2)
		  {
			  break;
		  }
		  w = *iPtr1;
		  *iPtr1 = *iPtr2;
		  *iPtr2 = w;
	  }while( ++iPtr1 <= --iPtr2 );
	  if(iLinks < iPtr2)  iQuicksort(iLinks, iPtr2);
	  {
		  if(iPtr1 < iRechts) iQuicksort(iPtr1, iRechts);
		  {}
	  }
	  return EXIT_SUCCESS;
  }

/** Funktion : alle Werte sortieren und ausgeben
  * Status   : in Arbeit
  */
  int iSortieren()
  {
	  iFeld_init();
	  Qsort(iFeld, iFeld + MAX);
	  print_iFeld();
	  return EXIT_SUCCESS;
  }

/** Steuerprogramm
  */
  int iController()
  {
	  iSortieren();
	  return 0;
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }
