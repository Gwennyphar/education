/** Programm : bubble-sort.c
  * Autor	 : Nico Anders
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

/** Funktion : benachbarte Werte auf Groesse vergleichen und tauschen
  * Status   : in Arbeit
  */
  int iBubblesort(int *iFeld, int iElemente)
  {
	  int i = 0;
	  int iTemp;
	  while(iElemente--)
      for(i = 1; i <= iElemente; i++)
      {
		  if(iFeld[i-1] > iFeld[i])
		  {
			  iTemp=iFeld[i];
			  iFeld[i]=iFeld[i-1];
			  iFeld[i-1]=iTemp;
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
      int iWerte[] = { 5, 2, 7, 9, 1, 4, 3, 8, 6 };
	  printf("unsortiertes Array\n");      
      for( i = 0; i < 9; i++ )
      {
		  printf("%i ", iWerte[i]);
	  }
	  printf("\nsortiertes Array\n");
      int n = sizeof(iWerte)/sizeof(int);
      iBubblesort(iWerte, n);
      for( i = 0; i < n; i++ )
      {
		  printf("%i ", iWerte[i]);
	  }
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
