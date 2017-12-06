#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *FPZeiger;
	char sName;
	system("clear");
	printf("Geben Sie der Datei einen Namen: ");
	scanf( "%s.txt", &sName);
	FPZeiger = fopen("%s.txt", "w");
	fclose(FPZeiger);
	return 0;
}

/*
int iRename()
{
	char sName;
	system("clear");
	printf("Geben Sie der Datei einen Namen: ");
	scanf( "%s.txt", &sName);
	rename("%s.txt", sName);
	return 0;
}
*/
