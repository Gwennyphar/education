#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int iEingabe = 0;
	int iX		 = 0;
	int iZahl    = 0;
	srand(time(NULL));
	printf("Anzahl: ");
	fflush(stdin);
	scanf("%i", &iEingabe);
	for( iX = 0; iX <= iEingabe; iX++ )
	{
		iZahl = rand() %10000000;
		printf("0178/%i\n", iZahl);
	}
getchar();
return 0;
}
