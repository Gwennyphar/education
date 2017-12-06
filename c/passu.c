#include	<stdio.h>
#include	<stdlib.h>
#define 	DATEI ".ecryptfs"
#define		NAME 20
#define     F_MAX FILENAME_MAX

int iSchreiben()
{
	system("sudo -v");
	if("sudo -v" != 0)
	{
		FILE *FPStream;
		char sZeichen[F_MAX];					
		FPStream = fopen( DATEI, "wb" );
		printf("\n");
		printf("\necryptfs-unwrap-passphrase\n");
		printf("________________________\n");
		printf("Geben Sie die Passphrase ein: ");
		fflush(stdin);
		scanf("%s", sZeichen);
		fwrite(sZeichen, 1, F_MAX, FPStream);
		fclose(FPStream);
	}
	else
	{
		printf("Zugriff verweigert\n");
	}
	getchar();
	return 0;
}

int iLesen()
{
	system("sudo -v");
	if("sudo -v" != 0)
	{
		FILE *FPStream;
		char sZeichen[F_MAX];
		FPStream = fopen( DATEI, "rb" );
		fread(sZeichen, 1, F_MAX, FPStream);
		printf("Ihre Passphrase lautet: ");
		printf("%s", sZeichen);
		fclose(FPStream);
	}
	else
	{
		printf("Zugriff verweigert\n");
	}
	getchar();
	return 0;
}

int iEntfernen()
{
	unsigned long size;
	system("sudo -v");
	if("sudo -v" != 0)
	{
		FILE *FPStream;
		FPStream = fopen(DATEI, "w+b");
		if(FPStream != NULL)
		{
			fseek(FPStream, 0L, SEEK_END); /* Stream an das Dateiende */
			size=ftell(FPStream);        /* Grösse in Bytes ermitteln */
			/* Kompletten Inhalt mit Leerzeichen überschreiben */
			fwrite((char *)' ', 1, size, FPStream);
			/* damit die Datei gelöscht werden kann, schliessen */
			fclose(FPStream);
			remove(DATEI);                         /* Jetzt weg damit */
			printf("Datei wurde entfernt!");
		}
	}
	else
	{
		printf("Zugriff verweigert\n");
	}
	getchar();
	return 0;
}

int iMenue()
{
	int iEingabe = 0;
	do
	{
		printf("\n");
		printf("\n  Ubuntu's Passphraser  \n");
		printf("________________________\n");
		printf("<1> Passphrase speichern\n");
		printf("<2> Passphrase anzeigen \n");
		printf("<3> Passphrase löschen  \n");
		printf("<0> Programm   Beenden  \n");
		printf("==> Ihre Auswahl: ");
		fflush(stdin);
		scanf("%i", &iEingabe);
		switch(iEingabe)
		{
			case 1:
			{
				iSchreiben();
				break;
			}
			case 2:
			{
				iLesen();
				break;
			}
			case 3:
			{
				iEntfernen();
				break;
			}
			case 0:
			{
				system("exit");
				break;
			}
			default:
			{
				printf("Falsche Taste!\n");
				break;
			}
		}
	}while(iEingabe);
	return 0;
}

int iController()
{
	iMenue();
	return 0;
}

int main()
{
	iController();
	return 0;
}
