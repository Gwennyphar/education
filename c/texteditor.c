#include <stdio.h>
#include <stdlib.h>
#define DATEI "Dokument.txt"

int iTexteditor()
{
	int i = 0;
	int iEingabe = 0;
 	char sText[FILENAME_MAX];
 	FILE *FPText;
 	FPText = fopen(DATEI, "a");
 	printf("\t___________________________\n");
 	printf("\t\tLinux-Pad");
 	printf("\n\t___________________________\n\n");
 	printf("Zeilen: ");
 	scanf("%i", &iEingabe);
 	for( i = 0; i < iEingabe; i++ )
 	{
		fgets(sText, FILENAME_MAX, stdin);
		fprintf(FPText, "%s", sText);
	}
		fclose(FPText);
		getchar();
		return 0;
}

int iController()
{
 	iTexteditor();
 	return 0;
}

int main()
{
 	iController();
 	return 0;
}
