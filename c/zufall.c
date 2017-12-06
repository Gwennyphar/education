#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int iSpalte = 0;
	int iZeile = 0;
	int iDoppelt = 0;
	int iAux = 0;
	srand(time(NULL));
	int iMatrix[4][4] ={{0}};
	iMatrix[0][0] = 1 ;
	for (iZeile = 0; iZeile < 16; iZeile++)
	{
		iMatrix[0][iZeile] = iZeile + 1;
	}
	for (iSpalte = 0; iSpalte < 16; iSpalte++)
	{
		iZeile = rand() % (16 - iSpalte) + iSpalte;
		iDoppelt = iMatrix[0][iZeile];
		iMatrix[0][iZeile] = iMatrix[0][iSpalte];
		iMatrix[0][iSpalte] = iDoppelt;
		if(iAux < 4)
		{
			printf("%2i |", iMatrix[0][iSpalte]); iAux++;
		}
		else
		{
			printf("\n"); iAux = 0;
		}
	}
	return (0);
}
