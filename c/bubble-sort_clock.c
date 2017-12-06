#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

int iBubblesort()
{
 	int iFeld[1000] = {0};
 	int iZaehler  =  0;
 	int iAUX	  =  0;
 	int iTauscher =  0;
 	float fZeit;
 	clock_t tStart;
 	clock_t tEnde;
 	srand(time(NULL) );
 	tStart = clock();
 	printf("Bitte warten...");
 	for( iZaehler = 0; iZaehler < MAX; iZaehler++ )
 	{
		iFeld[iZaehler] = (int) rand() % 100;
	}
	for( iTauscher = 0; iTauscher < iZaehler; iTauscher++ )
	{
	 	 for( iZaehler = 0; iZaehler < MAX; iZaehler++ )
		 {
		  	  if( iFeld[iZaehler] < iFeld[iZaehler - 1]  )
			  {
			   	  iAUX = iFeld[iZaehler];                                  
				  iFeld[iZaehler] = iFeld[iZaehler - 1];                                 
				  iFeld[iZaehler - 1] = iAUX;
			  }
	     }
	}
	tEnde = clock();
	/* Ergebnis der LauffZeitmessung in Sekunden */
	fZeit = (float)(tEnde-tStart) / (float)CLOCKS_PER_SEC;
	printf("Die Laufzeitmessung ergab %2.2f Sekunden.\n", fZeit);
	fgetc(stdin);
	return 0;
}

int iController()
{
 	iBubblesort();
 	return 0;
}

int main()
{
 	iController();
 	return 0;
}
