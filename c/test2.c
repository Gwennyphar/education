#include <stdio.h>
#include <stdlib.h>

int iTest()
{
	int  i = 0;
	int  iAnzahl = 0;
	char sBezeichner;
	FILE *FP;
	FP = fopen("test.txt", "w");

	printf("Anzahl: ");
	scanf("%i", &iAnzahl);
	fflush(stdin);


	
	for(i = 1; i <= iAnzahl; i++)
	{
		printf("Bezeichung: ");
		scanf("%s", &sBezeichner);
		fflush(stdin);
		fprintf(FP, "%i:%s\n", i, &sBezeichner);
	}
	fclose(FP);
	return 0;
}

int main()
{
	iTest();
	return 0;
}
