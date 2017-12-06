#include <stdio.h>
#include <stdlib.h>

int iWerte[]  = { 50, 10, 100, 90, 30, 25};

int iSortieren( const void * a, const void * b)
{
	return( *(int*)a - *(int*)b );
}
	
int iAusgabe()
{	
	int iAnzahl = 0;
    extern void	qsort(iWerte, 6, sizeof(int), iSortieren);
	for( iAnzahl = 0; iAnzahl < 6; iAnzahl++ )
	{
		printf("%d", iWerte[iAnzahl]);
	}
		printf("\n\n");
		return 0;
}

int iController()
{
	iSortieren();
	return 0;
}

int main()
{
	iController();
	return 0;
}
