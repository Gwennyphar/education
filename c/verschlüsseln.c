#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int iKodieren()
{
	int i = 0;
	int iLaenge = 0;
	char sText[255];
	FILE *FPSchreiben;
	FILE *FPLesen;
	printf("Eingabe.......: ");
	fgets(sText, sizeof(sText), stdin);
	/* Länge des Strings ermitteln! */
	iLaenge = strlen(sText);
	/* Verschlüsseln des Strings */	
	for (i = 0; i < iLaenge; i++)
	{
		if(sText[i]=='z' || sText[i]=='Z')
		{
			sText[i] = 'A';
			sText[i] = sText[i]-1;
		}
		sText[i] = sText[i]+3;
	}
	/* Ausgabe des verschlüsselten Strings */
	printf("Verschluesselt: %s", sText);
	FPSchreiben = fopen("test.txt", "w");
	fputs(sText, FPSchreiben);
	fclose(FPSchreiben);
	getchar();
	FPLesen = fopen("test.txt", "r");
	do
	{
		fgets(sText, sizeof(sText), FPLesen);
	}while(!feof(FPLesen));
	fclose(FPLesen);
	/* Länge des Strings ermitteln! */
	iLaenge = strlen(sText);
	/* Entschlüsseln des Strings */	
	for (i = 0; i < iLaenge; i++)
	{
		if(sText[i]=='z' || sText[i]=='Z')
		{
			sText[i] = 'A';
			sText[i] = sText[i]+1;
		}
		sText[i] = sText[i]-3;
	}
	/* Ausgabe des Entschlüsselten Strings */
	printf("Entschluesselt: %s", sText);
	return EXIT_SUCCESS;
}

int iController()
{
	iKodieren();
	return EXIT_SUCCESS;
} 
int main()
{
	iController();
	return EXIT_SUCCESS;
}
