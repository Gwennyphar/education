#include	<stdio.h>
#include	<stdlib.h>

long fileSize(FILE *fp)
{
	fseek(fp, 0L, SEEK_END);
	return ftell(fp);
}

int main(void)
{
	FILE *rfp;
	long endPos, /*aktPos,*/ neuPos;
	int c;
	rfp = fopen("logfile.txt", "r");
	if(rfp != NULL)
	{
		endPos = fileSize(rfp);
	}
	rewind(rfp);									  //Wieder zum Anfang zurück
	printf("Lesezeiger nach vorne setzen: ");
	do
	{
		scanf("%ld", &neuPos);
	}while(getchar() != '\n');
	if(neuPos > endPos)
	{
		printf("Fehler: Datei ist nur %ld Byte groß\n", endPos);
	}
	fseek(rfp, neuPos, SEEK_CUR);
	while((c=getc(rfp)) != EOF)
	{
		putc(c, stdout);
	}
	return EXIT_SUCCESS;
}