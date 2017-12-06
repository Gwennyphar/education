#include	<stdio.h>
#include	<stdlib.h>

int main(void)
{
	int iVal1	= 0;
	int iVal2	= 0;
	int iDiv	= 0;
	int iRest	= 0;
	
	printf("Rechnen mit 3 Ganzzahlen\n");
	printf("------------------------\n");
	printf("Wert 1	:	");
	scanf("%d", &iVal1);
	printf("Wert 2	:	");
	scanf("%d", &iVal2);
	
	iDiv = iVal1 / iVal2;
	printf("%d / %d = %d\n", iVal1, iVal2, iDiv);
	iRest = iVal1 %iVal2;
	printf("%d / %d = %d (Rest: %d)\n", iVal1, iVal2, iDiv, iRest);
	return 0;
	
}
