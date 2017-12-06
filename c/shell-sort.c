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

/** Funktion : Werte aufsteigend vergleichen und tauschen
  * Status   : in Arbeit
  */
  int iShellsort (int *iFeld, int iElemente)
  {
	  int i = 0;
	  int k = 0;
	  int iTemp;
	  int n;
   /* Anfangswert für die Distanz errechnen */
      for ( n = 1; n <= iElemente / 9; n = 3 * n +1 );
      {
		  for (; n > 0; n /= 3)
		  {
			  for ( i = n; i <= iElemente; i++ )
			  {
				  iTemp = iFeld[i];
			   /* Größer als iTemp und nicht iElemente
			    * sowie >= und nicht > */
			    for( k = i; k >= n && iFeld[k-n] > iTemp; k -= n )
			    {
					iFeld[k] = iFeld[k-n];
				}
				iFeld[k] = iTemp;
			  }
		  }
	  }
	  return EXIT_SUCCESS;
  }

/** Funktion : alle Werte sortieren und ausgeben
  * Status   : in Arbeit
  */
  int iSortieren()
  {
	  int i = 0;
   /* das Array zum Sortieren */
      int iWerte[] = { 5, 0, 2, 7, 9, 1, 4, 3, 8, 6 };
      printf("unsortiertes Array\n");      
      for( i = 0; i < 10; i++ )
      {
		  printf("%i ", iWerte[i]);
	  }
		  printf("\n");
	  printf("sortiertes Array\n");
      int n = sizeof(iWerte)/sizeof(int);
      iShellsort(iWerte, n-1);
      for( i = 0; i < n; i++ )
      {
		  printf("%i ", iWerte[i]);
	  }
		  printf("\n");
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
