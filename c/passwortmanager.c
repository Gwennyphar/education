#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include "mylib.h"
#define Dateiname "save.bin"
#define ZEICHEN "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwiyz!$&=?*#"

int iPasswort_erzeugen();
int iMenu();

int iLoeschen()
{
	char sDateiname[255];
	unsigned long size;
	FILE *FpLoeschen;
	Info_K();
	scanf("%s",sDateiname);
	flush();
	FpLoeschen = fopen(Dateiname,"r");
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
	getchar();
	return 0;
}

int iSuchen()
{
	char sDateiname[255];
	long Position = 0;
	char cTaste = 0;
	FILE *FpSuchen;
	Info_F();
	scanf("%s",sDateiname);
	flush();
	FpSuchen=fopen(sDateiname,"r");
	if(FpSuchen == NULL)
	{
		Error();
		return 0;
	}
	else
	{
		Info_E();
		scanf("%ld",&Position);
		flush();
		fseek(FpSuchen, 0L, SEEK_SET);
		fseek(FpSuchen, Position,SEEK_CUR);
		while( (cTaste=getc(FpSuchen)) != EOF)
		printf("%c", cTaste);
	}
	fclose(FpSuchen);
	getchar();
	return 0;
}

int iLesen()
{
	FILE *FpLesen;
	char sTextausgabe[FILENAME_MAX];
	FpLesen = fopen(Dateiname,"r");
	if(FpLesen == NULL)
	{
		Error();
		return 0;
	}
	else
	{
		clr();
		while( fgets(sTextausgabe, sizeof(sTextausgabe), FpLesen) !=0 )
		{
			fputs(sTextausgabe, stdout);
		}
	}
	fclose(FpLesen);
	getchar();
	return 0;
}

int iSchreiben()
{
	FILE *FpSchreiben;
	char cTaste;
	char sTexteingabe[FILENAME_MAX];
	Info_A();
	FpSchreiben = fopen(Dateiname,"w");
	if(FpSchreiben == NULL)
	{
		Error();
		return 0;
	}
	else
	{
		Info_A();
		while((cTaste = getchar()) != '$')
		{
			fgets(sTexteingabe, sizeof(sTexteingabe), stdin);
			fputs(sTexteingabe, FpSchreiben);
			//if(cTaste == '$');
		}
	}
	fclose(FpSchreiben);
	flush();
	return 0;
}

/** Funktion : Zufallszahlen erzeugen
  * Status   : in Arbeit
  */
  int iPasswort_erzeugen()
  {
	  int  i = 0;
   	  char sBuchstaben[69] = ZEICHEN;
   	  char sFeld[12];
   	  srand(time(NULL)); 
   	  FILE *FPZeiger;
   	  	scanf("%c", &cTaste);
	flush();
	if(cTaste == 'j' || 'J')
	{
		iPasswort_erzeugen();
	}
	flush();
   	  FPZeiger = fopen(Dateiname, "ab"); 	  
   	  for(i = 0; i < 12; i++)
   	  {
		  sFeld[i] = sBuchstaben[(rand() % 69+1)];
	  }
	  printf("%s",sFeld);
	  fprintf( FPZeiger,"%s", sFeld );
  	  fclose(FPZeiger);
  	  getchar();
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
			case 'W':
			case 'w':
			{
				iSchreiben();
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
			case 'D':
			case 'd':
			{
				iLoeschen();
				break;
			}
			case 'Q':
			case 'q':
			{
				return 0;
				break;
			}
			default:
			{
				Warnung();
				break;
			}
		}
	}while(cTaste != 'Q' && 'q');
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
