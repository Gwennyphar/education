#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char sText[255];
	char sEingabe[255];
	FILE *FPLesen;
	FPLesen = fopen("login.txt", "r");
	do
	{
		fgets(sText, sizeof(sText), FPLesen);
		sText[strlen(sText)-1] = '\n';
		puts(sText);
	}while(!feof(FPLesen));
	fgets(sEingabe, sizeof(sEingabe), stdin);
	if(strncmp(sEingabe, sText, sizeof(sText)) == 0)
	{
		printf("%s stimmt mit %s ueberein", sEingabe, sText);
	}
	else
	{
		printf("%s stimmt NICHT mit %s ueberein", sEingabe, sText);
	}
	fgetc(stdin);
	return EXIT_SUCCESS;
}
