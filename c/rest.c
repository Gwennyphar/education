#include <stdio.h>

int main(void)
{
	int iDividend = 0;
	int iDivisor  = 0;
	int iQuotient = 0;
	int iRest	  = 0;

	printf("1.Zahl eingeben: ");
	scanf("%i", &iDividend);
	printf("2.Zahl eingeben: ");
	scanf("%i", &iDivisor);


	iRest = (iDividend / iDivisor) % iRest;
	printf("%i * %i / %i = %i Rest: %i\n", iDividend, iDivisor, iQuotient, iDividend / iDivisor, iRest);
	return 0;
}
	
