/** Programm : sortierverfahren.c
  * Autor    : Nico Anders
  * Version  : 0.1 stable
  * Datum    : 26.02.2011
  * ToDo     : -
  */

/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #define ELEMENT 10

/** Funktion :Auswahlmenue
  * Status : in Arbeit
  */
  int iMenue()
  {
      int iEingabe = 0;
      
      do
      {
               printf("\n\n\t+---------------------+");
               printf("\n\t| Sortier-Algorithmen |");
               printf("\n\t+---------------------+");
               printf("\n\t<1> Auswahl:ShellSort |");
               printf("\n\t<2> Auswahl:QuickSort |");
               printf("\n\t<3> Auswahl:BubbleSort|");
               printf("\n\t<4> Auswahl:Hilfeseite|");
               printf("\n\t<0> Auswahl:Beenden   |");    
               printf("\n\t+--------------------+|");
               printf("\n\tIhre Auswahl: ");
               scanf("%i", &iEingabe);
               
               switch(iEingabe)
               {
                      case 1:
                           {
                                printf("\n\tDer Shell-Sort Algorithmus");
                                iShell_Sort_Verfahren();
                                break;
                           }
                      case 2:
                           {
                                printf("\n\tDer Quick-Sort Algorithmus");
                                iQuick_Sort_Verfahren();
                                break;
                           }
                      case 3:
                           {
                                printf("Der Bubble-Sort Algorithmus"); 
                                iBubble_Sort();
                                break;
                           }
                      case 4:
                           {
                                printf("\n\tHilfe zum Algorithmus"); 
                                iHilfe_anzeigen();
                                break;
                           }
                      case 0:
                           {
                                printf("\n\tBis Bald!"); 
                           }
                      default:
                           {
                                printf("\n\tSorry, Falsche Taste!"); 
                                break;
                           }
               }
      }while(iEingabe);
      return 0;
  }
  
/** Funktion : Shell Sort => unsortierte Felder sortieren
  * Status   : in Arbeit
  */
  int iShell_Sort_Verfahren(int iFeld[],int iMax)
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
      getchar();
      return (0);
  }

/** Funktion : Shell Sort => Ausgabe (Un)sortierter Zahlen in Konsole
  * Status   : in Arbeit
  */
  int iShell_Sort_Ausgabe()
  {
      int iZaehler;
      int iFeld[ELEMENT]={5,2,9,4,7,0,6,1,3,8};
      
      printf("\n\nUnsortiertes Feld:\n");
      
      for( iZaehler = 0;iZaehler < ELEMENT; iZaehler++ )
      {
          printf("%d ",iFeld[iZaehler]);
      }
      iShell_Sort_Verfahren(iFeld,ELEMENT);
      printf("\n\nSortiertes Feld:\n");
      
      for( iZaehler = 0;iZaehler < ELEMENT;iZaehler++ )
      {
         printf("%d ",iFeld[iZaehler]);
      }
      getchar();
      return 0;
  }

/** Funktion : Quick Sort => zufaellig erzeugte Felder sortieren
  * Status   : in Arbeit
  */
  int iQuick_Sort_Verfahren(int iFeld[],int iMax)
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
      getchar();
      return (1);
  }

/** Funktion : Quick Sort => Ausgabe (Un)sortierter Zufallszahlen in Konsole
  * Status   : in Arbeit
  */
  int iQuick_Sort_Ausgabe()
  {
      int iZaehler;
      int iFeld[ELEMENT]={5,2,9,4,7,0,6,1,3,8};
      
      printf("\n\nUnsortiertes Feld:\n");
      
      for (iZaehler = 0; iZaehler < ELEMENT; iZaehler++)
      {
          iFeld[iZaehler] = rand() % ELEMENT + 1;     /* rand zum Zufallszahlen
                                                         generieren*/ 
          printf("%d", iFeld[iZaehler] );
      }
      
      iQuick_Sort_Verfahren(iFeld,ELEMENT);
      printf("\n\nSortiertes Feld:\n");
      
      for( iZaehler = 0;iZaehler < ELEMENT;iZaehler++ )
      {
         printf("%d ",iFeld[iZaehler]);
      }
      getchar();
      return 0;
  }
  
/** Funktion : Bubble Sort => Zahlen aufsteigend nach Groesse sortieren
  * Status   : in Arbeit 
  */
  int iBubble_Sort()
  {
     int iFeld[20];
     int iZaehler;
     int iWert;
     int iElement;
     int iTemp;
     printf("\n\n\tWie viel Elemente? ");
     scanf("%d",&iZaehler);
     printf("\n\tWie viele Felder? ");
     for( iWert = 0; iWert < iZaehler;iWert++ )
     {
         scanf("%d",&iFeld[iWert]);
         
         /** sortieren
           */ 
           for( iWert = 0;iWert < iZaehler; iWert++ )
           {
               for( iElement = iWert; iElement < iZaehler -iWert -1; iElement++ )
               {
                   if( iFeld[iElement] > iFeld[iElement +1] )
                   {
                      iTemp = iFeld[iElement+1];
                      iFeld[iElement+1]= iFeld[iElement];
                      iFeld[iElement] = iTemp;
                   }
               }
           }
           printf("\n\tDas sortierte Feld lautet:\n");
           for( iWert = 0; iWert < iZaehler; iWert++ )
           {
               printf("\n\t%d",iFeld[iWert]);
           }
     }
     getch();
     return 0;
}

/** Funktion : Hilfe anzeigen
  * Status   : in Planung 
  */
  int iHilfe_anzeigen()
  {
      return 0;
  }

/** Steuerprogramm
  * iController
  */
  int iController()
  {
      iMenue();
      return 0;
  }

/** Programmschnittstelle
  * main()
  */
  int main()
  {
      iController();
      return 0;
  }

/** Ende sortierverfahren.c
  */
