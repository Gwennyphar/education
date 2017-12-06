#include <stdio.h>
#include <stdlib.h>

#include <time.h>

int iBubble_Korrektur()
{
 	int iFeld[10] = {0};          /* String zum speichern der 10 Zufallzahlen */
 	int iZaehler  =  0;        /* Variable zum Sortieren der 10 Zufallszahlen */
 	int iAUX	  =  0;     /* Variable zum auslagern 2er benachbarter Zahlen */
 	int iTauscher =  0;   /* Variable zum tauschen zweier Zahlen nach Groesse */
 	
 	srand(time(NULL) );             /* srand zum generieren von Zufallszahlen */
 	for( iZaehler = 0; iZaehler <10; iZaehler++ )
 	{
	 	 iFeld[iZaehler] = (int) rand() % 100; 			/* zum generieren von
						   		 		  				   Zufallszahlen 1-100 */
	}
 	printf("\n\tHier der Unsortierte Vektor: \n");
 	for( iZaehler = 0; iZaehler < 10; iZaehler++ )     /* zum durchlaufen
 	                                                      der 10 Zufallzahlen */
 	{
	 	 printf("\tiFeld[%i] = %i\n", iZaehler, iFeld[iZaehler] );
	}
	for( iTauscher = 0; iTauscher < iZaehler; iTauscher++ ) /* fuer 10fachen
																   Durchlauf durch
																   Uebergabe an
																   an iZaehler */
	{
	 	 for( iZaehler = 0; iZaehler < 10; iZaehler++ )
		 {
		  	  if( iFeld[iZaehler] < iFeld[iZaehler - 1]  )  /* zum vergleichen
		  	                                                   der gespeicherten
		  	                                                   Werte in iFeld */
			  {
			   	  iAUX				 = iFeld[iZaehler]; /* fuer die Uebergabe an
			   	                                           iAUX in iZaehler */
			   	                                           
				  iFeld[iZaehler]	 = iFeld[iZaehler - 1];  /* fuer Uebergabe
				                                                der Zahl im
				                                                iZaehler an iFeld
				                                                */
				                                                
				  iFeld[iZaehler - 1] = iAUX;   /* zum nachrueckend der Werte */
			  }
	     }
	}
	 	 
	printf("\n\tHier der Sortierte Vektor: \n");
	for( iZaehler = 0; iZaehler < 10; iZaehler++) /* zum durchlaufen der 10 Zahlen */
	{
	 	 printf("\tiFeld[%i] = %i\n", iZaehler, iFeld[iZaehler]);
	}
	getchar();
	return 0;
}

int iController()
{
 	iBubble_Korrektur();
 	return 0;
}

int main()
{
 	iController();
 	return 0;
}
