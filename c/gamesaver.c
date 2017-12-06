#include	<stdio.h>
#include	<stdlib.h>
#define		WIDTH 255

int main(void)
{
	FILE *FPFile;
	char sDateiname[255];
	char sText[255];
	printf("Datei anlegen: ");
	scanf("%s", sDateiname);
	FPFile= fopen(sDateiname, "wb");
	printf("Schreibe hier Text: ");
	fgets(sText, 255, stdin);
	fwrite(sText, 1, 255, FPFile);
	fclose(FPFile);
	getchar();
	return 0;
}
