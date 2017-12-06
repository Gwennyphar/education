#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int iFeld[5][5] = {0};

int iBubble_Zahlen()
{
 	int iZaehler_Spalte  =  0; /* Variable zum Sortieren der 10 Zufallszahlen */
	int iZaehler_Zeile   = 0;
 	int iAUX	  =  0; /* Variable zum auslagern 2er benachbarter Zahlen */
 	int iTauscher =  0;/* Variable zum tauschen zweier Zahlen nach Groesse */
 	
 	
 	srand(time(NULL) );             /* srand zum generieren von Zufallszahlen */
    printf("\n\tHier der Unsortierte Vektor: \n\n");
    
 	for( iZaehler_Spalte = 0; iZaehler_Spalte < 5; iZaehler_Spalte++ )
 	{
      for( iZaehler_Zeile = 0; iZaehler_Zeile < 5; iZaehler_Zeile++ )
      {
	   	 iFeld[iZaehler_Spalte][iZaehler_Zeile] = (int) rand() % 100;
      }
	}
	for( iZaehler_Spalte = 0; iZaehler_Spalte < 5; iZaehler_Spalte++ ) 
	{
	  for( iZaehler_Zeile = 0; iZaehler_Zeile < 5; iZaehler_Zeile++ )
	  {
	   printf("[%i][%i]= %i\t",iZaehler_Spalte, iZaehler_Zeile , iFeld[iZaehler_Spalte][iZaehler_Zeile] );
	  }
    }                                               
 	fflush(stdin);
	getch();
	return 0;
}

int iBubble_Spalten()
{
 	int iZaehler_Spalte = 0;
 	int iWechsler       = 0;
 	
 	for( iZaehler_Spalte = 0; iZaehler_Spalte < 5; iZaehler_Spalte++ )
 	{ 
	 	 printf("\t%i\n", iFeld[iZaehler_Spalte] );
	}
	for( iWechsler = 0; iWechsler < iZaehler_Spalte - 1; iWechsler++ )
	{
	 	 for( iZaehler_Spalte = 0; iZaehler_Spalte < 5; iZaehler_Spalte++ )
	 	 {
         }
	}
	fflush(stdin);
 	getch();
 	return 0;
}

int iController()
{
 	iBubble_Zahlen();
 	iBubble_Spalten();
 	return 0;
}

int main()
{
 	iController();
 	return 0;
}
