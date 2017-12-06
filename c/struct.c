#include <stdio.h>
#include <stdlib.h>
struct test
{
	char zeichen;
}ausgabe[5][10];

int main()
{
	int x = 0;
	int i = 0;
	FILE *FP;
	FP = fopen("test.txt", "w");
	printf("anzahl: ");
	scanf("%i", &x);
	for(i=0;i<x;i++)
	{
		printf("eingabe: ");
		scanf("%s", &ausgabe[i][i].zeichen);
	}
		for(i=0;i<x;i++)
	{
		printf("%s\n", &ausgabe[i][i].zeichen);
		printf(FP, "%s\n", &ausgabe[i][i].zeichen);
	}
	fclose(FP);
	
	return 0;
}
