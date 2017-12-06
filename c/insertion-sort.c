/** Programm : insertion-sort.c
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
  int iInsertionsort(int *iFeld, int iElemente)
  {
	  int iIndex;
	  int iIndex_klein;
	  int iWert_klein;
   /* Schleife von links-1 nach rechts */
      for( iIndex = 1; iIndex <= iElemente; iIndex++ )
      {
		  /* aktuelle Position zwischenspeichern */
		     iWert_klein = iFeld[iIndex];
          /* Kleineren Wert als iWert_klein suchen. Schleife  läuft
           * von aktueller Position von rechts nach links durch. */
             for( iIndex_klein = iIndex; iFeld[iIndex_klein -1] > iWert_klein &&
                  iIndex_klein > 0; iIndex_klein-- )
          /* wenn Vorgänger größer als aktuelles
           * Element in iWert_klein */
             iFeld[iIndex_klein] = iFeld[iIndex_klein -1];
          /* gespeichertes Element an neue Position ->
           * Lücke auffüllen */
             iFeld[iIndex_klein] = iWert_klein;
	   }
	   return EXIT_SUCCESS;
   }

/** Funktion : alle Werte von rechts nach links sortieren und ausgeben
  * Status   : in Arbeit
  */
  int iSortieren()
  {
	  int i;
   /* das Array zum Sortieren */
      int iFeld[9] = { 5, 2, 7, 9, 1, 4, 3, 8, 6 };
      int n = sizeof(iFeld)/sizeof(int);
      for( i = 0; i < n; i++ )
      {
		  printf("%i ", iFeld[i]);
	  }
	  printf("\n");
	  iInsertionsort(iFeld, n-1);
	  for( i = 0; i < n; i++ )
	  {
		  printf("%i ", iFeld[i]);
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
