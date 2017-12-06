/** uebung quick_sort.c
  * Nico Anders
  */
  
/** Preaprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define ELEMENT 10

/** Quick Sort => zufaellig erzeugte Zahlen sortieren
  */
  int iQuick_Sort(int iFeld[],int iMax)
  {
	  int iStop;
      int iTausch;
      int iLimit;
      int iTemp;
      int iZaehler;
      int iWert = (int)(iMax / 2)-1;
      
      while( iWert > 0 )
      {
           iStop = 0;
           iLimit = iMax - iWert;
                
           while( iStop == 0 )
           {
                 iTausch = 0;
                 
                 for( iZaehler = 0; iZaehler < iLimit; iZaehler++)
                 {
                     if( iFeld[iZaehler] > iFeld[iZaehler + iWert] )
                     {
                       iTemp = iFeld[iZaehler];
                       iFeld[iZaehler] = iFeld[iZaehler + iWert];
                       iFeld[iZaehler + iWert] = iTemp;
                       iTausch = iZaehler;
                     }
                 }
                 iLimit = iTausch - iWert;
                 if(iTausch == 0)
                 iStop = 1;
           }
           iWert = (int)(iWert / 2);
      }
      return 0;
  }

/** Quick Sort => (Un)sortierte Zahlen ausgeben
  */
  int iQuick_Sort_Ausgabe()
  {
      int iZaehler;
      int iFeld[ELEMENT]={5,2,9,4,7,0,6,1,3,8};
      
      printf("\n\n+------------------------+");
      printf("\n| Quick Sort Algorithmus |");
      printf("\n+------------------------+");
      printf("\n\nUnsortiertes Feld:\n");
      srand(time(NULL));
      for (iZaehler = 0; iZaehler < ELEMENT; iZaehler++)
      {
          iFeld[iZaehler] = rand() % ELEMENT + 1;     /* rand zum Zufallszahlen
                                                         generieren*/ 
          printf("%d ", iFeld[iZaehler] );
      }
      
      iQuick_Sort(iFeld,ELEMENT);
      printf("\n\nSortiertes Feld:\n");
      
      for( iZaehler = 0;iZaehler < ELEMENT;iZaehler++ )
      {
         printf("%d ",iFeld[iZaehler]);
      }
      getchar();
      return 0;
  }

/** Steuerprogramm
  */
  int iController()
  {
      iQuick_Sort_Ausgabe();
      return 0;
  }

/** Programmschnittstelle
  */
  int main()
  {
      iController();
      return 0;
  }
  
/** Ende
  */
