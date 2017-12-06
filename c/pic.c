#include	<stdio.h>
#include	<stdlib.h>

int main(void)
{
	double dRadius	= 0;	   //Fliekommatyp double Wertübrgabe an Variable dPI
	double dPI		= 3.14159265358979;
	double dKreis	= 0;
	
	printf("Kreisflaechenberechnung\n");
	printf("-----------------------\n");
	printf("Radius eingeben	:	");
	scanf("%lf", &dRadius);								 //einlesen fuer dRadius
	dKreis = dRadius * dRadius *dPI;					   //fuer die Berechnung
	printf("Kreisflaeche bei Radius %.2lf betraegt %.2lf\n", dRadius, dKreis);
	//Ausgabe des Ergebnis in printf()
	return 0;	
}
