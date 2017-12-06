#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct
{
	char sName[18];
}stDaten;

int main()
{
	char sName[18];
	fgets(stDaten.sName, sizeof(stDaten.sName), stdin);
	printf("\nausgabe\n");
	printf("%s", stDaten.sName);
	stDaten.sName[strlen(stDaten.sName)-1] = '\0';
	strncat(stDaten.sName, ".c", sizeof(stDaten.sName));
	printf("\nstrcat\n");
	printf("%s", stDaten.sName);
	strcpy (sName, stDaten.sName);
	printf("\nsName\n");
	printf("%s", sName);
	return EXIT_SUCCESS;
}

