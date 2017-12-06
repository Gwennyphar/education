#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Funktion....: Steuerfunktion fuer das Hauptmenue
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iBeenden()
  {
	  printf("\n\tSie wurden am System abgemeldet\n");
      return EXIT_SUCCESS;
  }


/** Funktion....: Steuerfunktion fuer das Hauptmenue
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iMenue()
  {
	  printf("\n\tWillkommen im System");
	  fgetc(stdin);
	  iBeenden();
      return EXIT_SUCCESS;
  }

int iLogin()
{
	char sPasswd[255];
	char sEingabe[21];
	int  iLaenge  = 0;
	int        i  = 0;
	int  iCounter = 3;
	FILE *FPLesen;
	FILE *FPSchreiben;
	FPLesen = fopen("login.txt", "r");
	if(FPLesen == NULL)
	{
		printf("\n\tKeine Anmeldung am System moeglich.\n"
		"\tBitte vergeben Sie ein Passwort:\n"
		"\t____________________________________\n\n\t");
		FPSchreiben = fopen("login.txt", "w");
		printf("Neues Passwort....: ");
		fgets(sPasswd, sizeof(sPasswd), stdin);
		/* Laenge des Strings ermitteln! */
		iLaenge = strlen(sPasswd);
		/* Verschluesseln des Strings */	
		for (i = 0; i < iLaenge; i++)
		{
			if(sPasswd[i]=='z' || sPasswd[i]=='Z')
			{
				sPasswd[i] = 'A';
				sPasswd[i] = sPasswd[i]-1;
			  }
			  sPasswd[i] = sPasswd[i]+3;
		  }
		  fputs(sPasswd, FPSchreiben);
		  fclose(FPSchreiben);
	}
	else
	{
		printf("\n\tProgramm mit 'x' beenden.\n"
		"\tBitte am System anmelden:\n"
		"\t_________________________\n\n");
		/* Zuerst Passwort aus Datei lesen und dechiffrieren */
		do
		{
			fgets(sPasswd, sizeof(sPasswd), FPLesen);
			/* Laenge des Strings ermitteln! */
			iLaenge = strlen(sPasswd);
			/* Entschluesseln des Strings */	
			for (i = 0; i < iLaenge; i++)
			{
				if(sPasswd[i]=='z' || sPasswd[i]=='Z')
				{
					sPasswd[i] = 'A';
					sPasswd[i] = sPasswd[i]+1;
				}
				sPasswd[i] = sPasswd[i]-3;  
			}
		}while(!feof(FPLesen));
		fclose(FPLesen);
		/* und jetzt folgt die Passworteingabe */
		do
		{
			printf("\tPasswort eingeben: ");
			fgets(sEingabe, sizeof(sEingabe), stdin);
			if(strncmp(sEingabe, sPasswd, sizeof(sPasswd)) == 0)
			{
				iMenue();
				break;
			}
			else if(strncmp(sEingabe, "x", 1) == 0)
			{
				printf("\n\tVielen Dank und Auf Wiedersehen!");
				break;
			}
			else if(iCounter < 1)
			{
				fprintf(stderr, "\n\tFehler: Zugriff verweigert!");
				break;
			}
			else if(iCounter != 0)
			{
				fprintf(stderr, "\n\tFehler: ungueltiges Passwort\n"
				"\tNoch %i Versuche verbleiben\n\n", iCounter);
				iCounter--;
			}
		}while(sEingabe[21] != 'x');
		fgetc(stdin);
	}
	return EXIT_SUCCESS;
}

/** Steuerprogramm
  */
  int iController()
  {
      iLogin();                          /* Funktion an OS-Ebene uebergeben */
      return EXIT_SUCCESS;
  }

/** Hauptprogramm
  */
  int main()
  {
      iController();                     /* Rueckgabe aus iController() */
      return EXIT_SUCCESS;
  }

/** Programmende
  */
