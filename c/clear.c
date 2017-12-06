#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	double dBasis    = 0;
    double dExpo     = 2;
    double dErgebnis = 0;
	printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tRechenoperation Potenzen\t|\n");
    printf("\t\t+---------------------------------------+\n"); 
    printf("\n\t\t\tBitte Grundzahl eingeben: ");
   	fflush(stdin);
    scanf("%lf",&dBasis);
    dErgebnis = dBasis / dExpo;
    printf("\n\t\t\tDas Ergebnis lautet:\n\n\t\t\t%G ^ %G = %G\n",
    dBasis, dExpo, dErgebnis );
	return 0;
}
