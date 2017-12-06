
/** Programm : shell-sort_clock.c
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
  #define MAX 10000000
  #define MAX_ANZAHL 10

/** Funktion : das Array zum Sortieren
  * Status   : akzeptiert 
  */
  int iFeld[MAX];

/** Funktion : Werte aufsteigend vergleichen und tauschen
  * Status   : in Arbeit
  */
  int iSortieren()
  {
	  int i,j;
	  for(i = MAX, j = 0; i >= 0; i--,j++)
	  {
		  iFeld[j] = i;
	  }
	  return EXIT_SUCCESS;
  }
  
/** Funktion : alle Werte sortieren und ausgeben
  * Status   : in Arbeit
  */
  int iShellsort(int *iFeld, int iElemente, int iDistanz)
  {
	  int i = 0;
	  int j = 0;
	  int iTemp;
	  int n = 0;
	  n = iElemente;
	  for( i = 0; n > 0; n /= iDistanz )
	  {
		  for ( i = n; i <= iElemente; i++ )
		  {
			  iTemp = iFeld[i];
		   /* Größer als iTemp und nicht iElemente
            * sowie >= und nicht > */
            for( j = i; j >= n && iFeld[j-n] > iTemp; j -= n )
            {
				iFeld[j] = iFeld[j-n];
			}
			iFeld[j] = iTemp;
		  }
	  }
	  return EXIT_SUCCESS;
  }
/** Funktion : Laufzeit zum sortieren messen
  * Status   : in Arbeit
  */
  int iZeitmessung()
  {
	  int iDistanz;
	  float fZeit;
	  clock_t tStart, tEnde;
	  for( iDistanz = 2; iDistanz <= MAX_ANZAHL; iDistanz++ )
	  {
		  iSortieren();
	  }
	  tStart = clock();
      iShellsort(iFeld, MAX-1, iDistanz);
      tEnde = clock();
      /* Ergebnis der LauffZeitmessung in Sekunden */
      fZeit = (float)(tEnde-tStart) / (float)CLOCKS_PER_SEC;
      printf("Die Laufzeitmessung der Distanzfolge "
             "%i ergab %2.2f Sekunden.\n" ,iDistanz,fZeit);
      return EXIT_SUCCESS;
  }

/** Steuerprogramm
  */
  int iController()
  {
	  iZeitmessung();
	  return 0;
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }
