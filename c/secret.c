/** Programm....: main.c
  * Entwickler..: 
  * Version.....: 0.1
  * Datum.......: Sun Jul 22 10:47:18 2012
  * Status......: in Arbeit
  * ToDo........: 
  */

/** Praeprozessor
  */
  #include <stdio.h>                     /* Standard-I/O */
  #include <stdlib.h>                    /* Nuetzliche Funktionen */
  #include <string.h>                    /* Zeichenketten */
  #ifdef __unix__
  #define TASTE "D"
  #else
  #define TASTE "Z"
  #endif
  #define DATEI "safe.txt"

int iLogin();

/** Funktion....: Daten Lesen
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iSuchen()
  {
	  char sText[255];
	  char sSuchen[255];
	  int iLaenge = 0;
	  int       i = 0;
	  FILE *FPLesen;
	  FPLesen = fopen(DATEI, "r");
	  if(FPLesen == NULL)
	  {
		  fprintf(stderr, "\n\tFehler: Datei konnte nicht gelesen werden!"
		  "\n\tPuffer wird geleert -Versuchen Sie es erneut\n\n");
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  printf("\n\tSuchwort eingeben: ");
		  fgets(sSuchen, sizeof(sSuchen), stdin);
		  while(fgets(sText, sizeof(sText), FPLesen))
		  {
			  /* Laenge des Strings ermitteln! */
			  iLaenge = strlen(sText);
			  /* Entschluesseln des Strings */	
			  for (i = 0; i < iLaenge; i++)
			  {
				  if(sText[i]=='z' || sText[i]=='Z')
				  {
					  sText[i] = 'A';
					  sText[i] = sText[i]+1;
				  }
				  sText[i] = sText[i]-3;  
			  }
			  if(strstr(sText, sSuchen))
			  {
				  printf("\t%s", sText);
			  }
		  };
	  }
	  fclose(FPLesen);
	  return EXIT_SUCCESS;
  }
   
/** Funktion....: Daten Lesen
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iLesen()
  {
	  char sText[255];
	  int iLaenge = 0;
	  int       i = 0;
	  FILE *FPLesen;
	  FPLesen = fopen("safe.txt", "r");
	  if(FPLesen == NULL)
	  {
		  fprintf(stderr, "\n\tFehler: Datei konnte nicht gelesen werden!"
		  "\n\tPuffer wird geleert -Versuchen Sie es erneut\n\n");
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  while(fgets(sText, sizeof(sText), FPLesen))
		  {			
			  /* Laenge des Strings ermitteln! */
			  iLaenge = strlen(sText);
			  /* Entschluesseln des Strings */	
			  for (i = 0; i < iLaenge; i++)
			  {
				  if(sText[i]=='z' || sText[i]=='Z')
				  {
					  sText[i] = 'A';
					  sText[i] = sText[i]+1;
				  }
				  sText[i] = sText[i]-3;  
			  }
			  printf("\t%s", sText);
		  };
	  }
	  fclose(FPLesen);
	  return EXIT_SUCCESS;
  }

/** Funktion....: Daten Schreiben
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iSchreiben()
  {
	  char sEingabe[20][160];
	  char sFrage[5];
	  char sJaNein[5];
	  int  iZeilen = 0;
	  int  iLaenge = 0;
	  int  i       = 0;
	  int  j       = 0;
	  FILE *FPSchreiben;
	  printf("\n\tBenutzername und Passwort eingeben:"
	  "\n\tEingabe mit [STRG]+[%s] beenden\n"
	  "\n\t", TASTE);
	  while(fgets(sEingabe[iZeilen], sizeof(sEingabe[iZeilen]), stdin))
	  {
		  printf("\t");
		  iZeilen++;
	  }
	  while(1)
	  {
		  printf("\n\tEingaben speichern? Ja/Nein: ");
		  fgets(sFrage, sizeof(sFrage), stdin);
		  sscanf(sFrage, "%s", sJaNein);
		  if( strncmp("ja", sFrage, 1) == 0)
		  {
			  FPSchreiben = fopen("safe.txt", "w");
			  if(FPSchreiben == NULL)
			  {
				  fprintf(stderr, "\n\tFehler: Datei konnte nicht angelegt werden!"
				  "\n\tPuffer wird geleert -Versuchen Sie es erneut\n\n");
				  break;
			  }
			  else
			  {
				  for(j = 0; j < iZeilen; j++)
				  {
					  /* Laenge des Strings ermitteln! */
					  iLaenge = strlen(sEingabe[j]);
					  /* Verschluesseln des Strings */	
					  for (i = 0; i < iLaenge; i++)
					  {
						  if(sEingabe[j][i]=='z' || sEingabe[j][i]=='Z')
						  {
							  sEingabe[j][i] = 'A';
							  sEingabe[j][i] = sEingabe[j][i]-1;
						  }
						  sEingabe[j][i] = sEingabe[j][i]+3;
					  }
					  /* Eingabe in Datei schreiben */
					  fputs(sEingabe[j], FPSchreiben);
				  }
				  fclose(FPSchreiben);
				  fprintf(stderr, "\n\tEingaben erfolgreich gespeichert!"
				  "\n\tPuffer wird geleert\n\n");
				  break;
			  }
		  }
		  else if( strncmp("nein", sFrage, 1) == 0)
		  {
			  fprintf(stderr, "\n\tEingaben nicht gespeichert!"
			  "\n\tPuffer wird geleert\n\n");
			  break;
		  }
	  }
	  return EXIT_SUCCESS;
  }

/** Funktion....: Steuerfunktion fuer das Hauptmenue
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iMenue()
  {
      char cTaste = 0;
      char sEingabe[3];
      do
      {
          printf("\tWas moechten Sie machen?\n"
          "\tMit '0' Auswahl anzeigen: ");
          /* abgesicherte Eingabe */
          fgets(sEingabe, sizeof(sEingabe), stdin);
          sscanf(sEingabe, "%c", &cTaste);
          switch(cTaste)
          {
              case '0':
              {
                  printf("\n\t_________________"
                  "\n\t-0- Auswahl"
                  "\n\t-1- Schreiben"
                  "\n\t-2- Lesen"
                  "\n\t-3- Suchen"
                  "\n\t-4- Abmelden"
                  "\n\t_________________\n\n");
                  continue;
              }
              case '1':
              {
                  iSchreiben();
                  break;
              }
              case '2':
              {
                  iLesen();
                  break;
              }
              case '3':
              {
                  iSuchen();
                  break;
              }
              case '4':
              {
                  /* beende hier */
                  printf("\n\tVom System erfolgreich abgemeldet\n\n");
                  break;
              }
              default:
              {
                  fprintf(stderr, "\n\tFehler: Ungueltige Eingabe\n\n");
                  break;
              }
          }
      }while(cTaste != '4');             /* Ende der Schleife */
      iLogin();
      return EXIT_SUCCESS;
  }

/** Funktion....: Anmelden
  * Beschreibung: 
  * Status......: in Arbeit
  */
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
				printf("\n\tSie sind am System angemeldet!\n\n");
				iMenue();
				break;
			}
			else if(strncmp(sEingabe, "x", 1) == 0)
			{
				printf("\n\tVielen Dank und Auf Wiedersehen!");
				break;
			}
			else if(iCounter == 0)
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
