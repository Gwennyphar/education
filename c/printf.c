#include	<stdio.h>							  //Header Standard Input Output
#include	<stdlib.h>									//Header Standard Libary

int main(void)
{
	int iVal = 1;
	//Auswertung von links nach rechts
	printf("val = %d		val = %d\n", iVal, iVal++);//Inkrementoperator ++
	//Auch Rechnungen sind möglich
	printf("123+456 = %d	10-3 = %d\n", 123+456, 10-3);
	return 0;
}
