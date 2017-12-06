#include	<stdio.h>
#include	<stdlib.h>
#define		WIDTH 160

int main(void)
{
	FILE *FPFile;
	char sBinary[160];					//zum speichern der 160 Zeichen im Array
	
	FPFile= fopen("logfile.ELF", "wb");
	printf("Schreibe hier Text: ");
	gets(sBinary);
	fwrite(sBinary, 1, 160, FPFile);	  //zum Schreiben 1x, 160 in Binaerdatei
	fclose(FPFile);
	getchar();
	return 0;
}
