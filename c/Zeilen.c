#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#define		LINEBUF 256

void killNL(char *str)
{
	size_t p = strlen(str);
	str[p-1] = '\0';
}

void countlineOut(FILE *rfp)
{
	char buf[LINEBUF];
	int count = 1;
	while(fgets(buf, LINEBUF, rfp) != NULL)
	{
		printf("%3d | ", count);
		fputs(buf, stdout);
		count++;
	}	
}

void search(FILE *fp)
{
	char str[LINEBUF], buf[LINEBUF];
	int count = 1;
	printf("Wonach soll gesucht werden: ");
	fgets(str. LINEBUF, stdin);
	killNL(str);
	while(fgets(buf, LINEBUF, fp) != NULL)
	{
		if(strstr(buf, str) != 0)
		{
			printf("%3d	: %s", count, buf);
		}
		count++
}

void copyFile(FILE *rfp, FILE *wfp)
{
	char buf[LINEBUF];
	while(fgets(buf, LINEBUF, rfp) != NULL)
	{
		fputs(buf, wfp);
	}
}

int main(void)
{
	char filename1[LINEBUF], filename2[LINEBUF];
	FILE *rfp = NULL, *wfp = NULL;
	int Input;
	
	printf("Datei zum Lesen; ");
	fgets(filename1, LINEBUF, stdin);
	killNL(filename1);
	
	printf("Was soll mit der Datei geschehen?\n");
	printf("<1>	Zeilen zählen (Bildschirmausgabe\n");
	printf("<2>	Zeilen zählen (in Datei screiben)");
	printf("<3>	Suchen");
	printf("<4>	Kopieren");
	printf("<0>	abbrechen");
	do
	{
	  scanf("%d", &Input);
	  {
			while(getchar() != '\n');
			switch(Input)
			{
		case 1 :
		case 2 :
				if(Input == 2)
				{
					printf("Dateiname der Kopie: ");
					fgets(filename2, LINEBUF, stdin);
					killNL(filename2);
					wfp = freopen(filename2, "w", stdout);
				}
				rfp = fopen(filename1, "r");
				if(rfp != NULL)
				{
					countLineOut(rfp);
				}
				break;
				case 3 :
				rfp = fopen(filename1, "r");
				if(rfp != NULL)
				{
					search(rfp);
				}
				break;
		case 4 :
				rfp = fopen(filename1, "r");
				printf("Dateiname der Kopie: ");
				fgets(filename2, LINEBUF, stdin);
				killNL(filename2);
				wfp = fopen(filename2, "w");
				if(rfp != NULL && wfp != NULL)
				{
					copyFile(rfp, wfp);
				}
				break;
		default:
				printf("Falsche EIngabe\n");
	 }
	}
		return EXIT_SUCCESS;
 }
}