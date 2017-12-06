/** Programmname    :  BubbleSort.c 
  * Autor           :  Nico Anders
  * Version         :  0.1
  * Datum           :  10.02.2011
  * ToDo            :  Code schreiben
  */

/** Praeprozessor
  *
  */
  #include <stdio.h>
  #include <stdlib.h>
  //#include <conio.h>
  #define Tausch
  
/** Funktion : Zufallszahlen generieren und Sortieren
  * Status   : in Arbeit  
  */
  int iBubblesort()
  {
      int iIndexA    = 0; 
      int iIndexB    = 0;
      int iFeld[10] = {0};                           /* speichert 10 Zeichen
                                                         die von Variable iLaenge
                                                         übergeben wird */
      int iLaenge    = 0;
      
      
      for (iLaenge = 0; iLaenge < 10; iLaenge++)
      {
          iFeld[iLaenge] = rand() % 10 + 1;          /* rand fuer Zufallszahlen
                                                         generieren*/ 
          printf("%i", iFeld[iLaenge] );
      }
      getchar();
      return 0;
  }
      
/** Steuerfunktion
  * iController
  */
  int iController()
  {
      iBubblesort();
      return 0;
  }
/** Schnittstelle
  * main()
  */
  int main()
  {
      iController();
      return 0;
  }
