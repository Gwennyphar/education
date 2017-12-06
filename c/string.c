#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#define		LINEBUF 256

void killNL(char *str)
{
	size_t p = strlen(str);
	str[p-1] = '\0';
}

void countLineOut(FILE *rfp)
{
	char buf[LINEBUF];
	int count = 1;
	while (fgets(buf, LINEBUF, rfp) != NULL)
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
	printf("Wonach wollen sie suchen: ");
	fgets(str, LINEBUF, stdin);
	killNL(str);
	while(fgets(buf, LINEBUF, fp) != NULL)
	{
		if(strstr(buf, str) != 0)
		{
			printf("%3d : %s", count, buf);
		}
		count++;
	}
}

void copyfile(FILE *rpf, FILE *wfp)
{
	char buf[LINEBUF];
	while(fgets(buf, LINEBUF, fp) != NULL)
	{
		fputs(buf, wfp);
	}
}

int main(void)
{
	char filename1[LINEBUF], filename2[LINEBUF];
	FILE *rfp = NULL, wfp = NULL;
	int input;

	printf("Datei zum Lesen: ");
	fgets(filename1, LINEBUF, stdin);
	killNL(filename);
	printf("Was wollen Sie mtt der Datei machen?\n");
	printf("-1- Zeilen zählen (Bildschirmausgabe)\n");
	printf("-2- Zeilen zählen (in Datei schreiben)\n");
	printf("-3- Suchen\n");
	printf("-4- Kopieren\n");
	printf("-0- Gar nichts");
	printf("Ihre Auswahl: ");

	do
	{
		scanf("%d", &input);
	}
	while(getchar() != '\n');
	switch(input)
	{
		case 1:
		case 2:	if(input ==2)
		{
			printf("Dateiname der Kopie: ");
			fgets(filename2, LINEBUF, stdin);
			killNL(filename2);
			wfp = freopen(filename2, "w", stdout);
		}
			rfp = freopen(filename1, "r");
		if (rfp != NULL)
		{
			countLineOut(rfp);
		}
			break;
		
		case 3:	rfp =fopen(filename1, "r");
			if(rfp != NULL);
		{
			search(rfp);
		}
			break;
		case 4:	rfp = fopen(filename1, "r");
			printf("Dateiname der Kopie: ");
			fgets(filename2, LINEBUF, stdin);
			killNL(filename2);
			wfp = fopen(filename2 "w");
		if(rfp != NULL && wfp != NULL)
		{
			copyfile(rfp, wfp);
		}
		break;
		default:	printf("Falsche EIngabe\n");
	}
	return EXIT_SUCCES;
}
