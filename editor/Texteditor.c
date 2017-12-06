#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>                              /* Zeichenkonvertierung */
#include "mylib.h"

int iBeenden()
{
	char cTaste = 0;
	do
	{
		Info_M();
		cTaste = ctrl();
		switch(cTaste)
		{
			case 'j':
			case 'J':
			{
				Info_N();
				exit(1);

			}
			case 'n':
			case 'N':
			{
				iMenu();
				break;
			}
		}
	}while(cTaste != 'n' || 'N');
	return 0;
}

int iLoeschen()
{
	char sDateiname[255];
	unsigned long size;
	FILE *FpLoeschen;
	Info_K();
	scanf("%s",sDateiname);
	flush();
	sDateiname[0] = toupper(sDateiname[0]);
	strcat(sDateiname, ".txt");
	FpLoeschen = fopen(sDateiname,"r");
	if(FpLoeschen == NULL)
	{
		Error();
		return 0;
	}
	else if(FpLoeschen != NULL)
	{
		fseek(FpLoeschen, 0L, SEEK_END);
		size=ftell(FpLoeschen);
		fwrite((char *)' ', 1, size, FpLoeschen);
		fclose(FpLoeschen);
		remove(sDateiname);
		Info_J();
	}
	fgetc(stdin);
	return 0;
}

int iKopieren()
{
	FILE *FpEingabe;
	FILE *FpAusgabe = 0;
	char sKopie[255];
	char sDateiname[255];
	Info_I();
	scanf("%s", sDateiname);
	flush();
	sDateiname[0] = toupper(sDateiname[0]);
	strcat(sDateiname, ".txt");
	FpEingabe = fopen(sDateiname, "r");
	if(FpEingabe == NULL)
	{
		Error();
		return 0;
	}
	else
	{
		Info_H();
		scanf("%s", sKopie);
		flush();
		if(FpAusgabe == NULL)
		{
			Error();
			return 0;
		}
		else
		{
			FpAusgabe = fopen(sKopie, "w");
			while (fgets(sKopie, sizeof(sKopie), FpEingabe))
			{
				fputs(sKopie, FpAusgabe);
			}
			Info_G();
		}
	}
	fclose(FpEingabe);
	fclose(FpAusgabe);
	return 0;
}

int iSuchen()
{
	char sDateiname[255];
	char sSuchen[255];
	FILE *FpSuchen;
	Info_F();
	scanf("%s",sDateiname);
	flush();
	sDateiname[0] = toupper(sDateiname[0]);
	strcat(sDateiname, ".txt");
	FpSuchen=fopen(sDateiname,"r");
	if(FpSuchen != NULL)
	{
		Info_E();
		scanf("%s", sSuchen);
		flush();
		Info_L();
		while(!feof(FpSuchen))
		{
			fgets(sDateiname, sizeof(sDateiname), FpSuchen);
			if(strstr(sDateiname, sSuchen))
			{
				printf("\t\t");
				printf("%s", sDateiname);
			}
		}
	}
	else
	{
		Error();
		return 0;
	}
	fgetc(stdin);
	fclose(FpSuchen);
	return 0;
}

int iLesen()
{
	FILE *FpLesen;
	char sTextausgabe[FILENAME_MAX];
	char sDateiname[255];
	Info_D();
	scanf("%s",sDateiname);
	flush();
	sDateiname[0] = toupper(sDateiname[0]);
	strcat(sDateiname, ".txt");
	FpLesen = fopen(sDateiname,"r");
	if(FpLesen == NULL)
	{
		Error();
		return 0;
	}
	else
	{
		Info_L();
		while(fgets(sTextausgabe, sizeof(sTextausgabe), FpLesen) !=0)
		{
			printf("\t\t");
			fputs(sTextausgabe, stdout);
		}
	}
	fclose(FpLesen);
	fgetc(stdin);
	return 0;
}

int iFortsetzen()
{
	FILE *FpSchreiben;
	char sTexteingabe[FILENAME_MAX];
	char sDateiname[255];
	Info_C();
	scanf("%s",sDateiname);
	flush();
	sDateiname[0] = toupper(sDateiname[0]);
	strcat(sDateiname, ".txt");
	FpSchreiben = fopen(sDateiname,"a");
	if(FpSchreiben == NULL)
	{
		Error();
		return 0;
	}
	else
	{
		Info_A();
		while(fgets(sTexteingabe, sizeof(sTexteingabe), stdin))
		{
			printf("\t\t");
			fputs(sTexteingabe, FpSchreiben);
		}
	}
	fclose(FpSchreiben);
	flush();
	return 0;
}

int iSchreiben()
{
	FILE *FpSchreiben;
	char sTexteingabe[FILENAME_MAX];
	char sDateiname[255];
	Info_B();
	scanf("%s",sDateiname);
	flush();
	sDateiname[0] = toupper(sDateiname[0]);
	strcat(sDateiname, ".txt");
	FpSchreiben = fopen(sDateiname,"w");
	if(FpSchreiben == NULL)
	{
		Error();
		return 0;
	}
	else
	{
		Info_A();
		while(fgets(sTexteingabe, sizeof(sTexteingabe), stdin))
		{
			printf("\t\t");
			fputs(sTexteingabe, FpSchreiben);
		}
	}
	fclose(FpSchreiben);
	return 0;
}

int iMenu()
{
	char cTaste = 0;
	do
	{
		Screen();
		cTaste = ctrl();
		switch(cTaste)
		{
			case 'N':
			case 'n':
			{
				iSchreiben();
				break;
			}
			case 'A':
			case 'a':
			{
				iFortsetzen();
				break;
			}
			case 'O':
			case 'o':
			{
				iLesen();
				break;
			}
			case 'S':
			case 's':
			{
				iSuchen();
				break;
			}
			case 'K':
			case 'k':
			{
				iKopieren();
				break;
			}
			case 'L':
			case 'l':
			{
				iLoeschen();
				break;
			}
			case 'X':
			case 'x':
			{
				iBeenden();
				break;
			}
			default:
			{
				Warnung();
				break;
			}
		}
	}while(cTaste != 'X' && 'x');
	return 0;
}

int iController()
{
	iMenu();
	return 0;
}

int main()
{
	iController();
	return 0;
}
