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
  #include <conio.h>
  #define Tausch
  
/** Funktion : Zufallszahlen generieren und Sortieren
  * Status   : in Arbeit  
  */
  int iBubblesort()
  {
      int iIndexA    = 0; 
      int iIndexB    = 0;
      int iFeld[100] = {0};                           /* speichert 100 Zeichen
                                                         die von Variable iLaenge
                                                         übergeben wird */
      int iLaenge    = 0;
      
      
      for (iLaenge = 0; iLaenge < 100; iLaenge++)
      {
          iFeld[iLaenge] = rand() % 100 + 1;          /* rand fuer Zufallszahlen
                                                         generieren*/ 
          printf("%i", iFeld[iLaenge] );
          
          if( iFeld[iIndexB] > iFeld[iIndexB + 1])
          {
                  Tausch(iFeld[iIndexB], iFeld[iIndexB+1]); /* Zum sortieren der
                                                               Zufallszahlen*/
                  printf("%i", iFeld[iIndexB]);
          }
                            
      }
          /*for (i = 0; iIndexB < iLaenge - iIndexB - 1; iIndexB++)
          {
              if ( iFeld[iIndexB] > iFeld[iIndexB + 1])
              {
                   iFeld[iIndexB] = iFeld[iIndexB + 1];
                   iFeld[iIndexB + 1];
                   printf("", iFeld[iIndexA +1]);
                   fflush(stdin);*/                 /* vorerst auskommentiert */
          fflush(stdin);
          getch();
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
