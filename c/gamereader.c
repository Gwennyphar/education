#include	<stdio.h>
#include	<stdlib.h>
#define		WIDTH 255

int main(void)
{
	FILE *FPFile;
	char sDateiname[255];
	printf("Datei öffnen: ");
	scanf("%s", sDateiname);
	FPFile= fopen(sDateiname, "rb");
	fread(sDateiname, 1, 255, FPFile);
	printf("%s", sDateiname);
	fclose(FPFile);
	getchar();
	return 0;
}
