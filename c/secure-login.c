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

struct User
{
	char sUser[21];
	char sPwd[21];
	int  iCounter;
	int  iReturn;
}stStruktur;

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
	  printf("\n\tWillkommen im System, %s!", stStruktur.sUser);
	  fgetc(stdin);
      return EXIT_SUCCESS;
  }

/** Funktion....: Anmelden
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iLogin()
  {
	  int  iLaenge = 0;
	  int        i = 0;
	  char sEingabe[21];
	  char sEingabe_User[21];
	  char sEingabe_Pwd[21];
	  FILE *FPSchreiben;
	  FILE *FPLesen;
	  stStruktur.iCounter = 4;
	  FPLesen = fopen("login.txt", "r");
	  if(FPLesen == NULL)
	  {
		  printf("\n\tEs ist noch kein Benutzer vorhanden.\n"
		  "\tBitte Namen und Passwort eingeben:\n"
		  "\t____________________________________\n\n\t");
		  FPSchreiben = fopen("login.txt", "w");
		  printf("Neuer Benutzername: ");
		  fgets(stStruktur.sUser, sizeof(stStruktur.sUser), stdin);
		  printf("\tNeues Passwort....: ");
		  fgets(stStruktur.sPwd, sizeof(stStruktur.sPwd), stdin);
		  /* Länge des Strings ermitteln! */
		  iLaenge = strlen(stStruktur.sUser);
		  /* Verschlüsseln des Strings */	
		  for (i = 0; i < iLaenge; i++)
		  {
			  if(stStruktur.sUser[i]=='z' 
			  || stStruktur.sUser[i]=='Z'
			  || stStruktur.sPwd[i] =='z' 
			  || stStruktur.sPwd[i] =='Z')
			  {
				  stStruktur.sUser[i] = 'A';
				  stStruktur.sPwd[i] = 'A';
				  stStruktur.sUser[i] = stStruktur.sUser[i]-1;
				  stStruktur.sPwd[i] = stStruktur.sPwd[i]-1;
			  }
			  stStruktur.sUser[i] = stStruktur.sUser[i]+3;
			  stStruktur.sPwd[i] = stStruktur.sPwd[i]+3;
		  }
		  fputs(stStruktur.sUser, FPSchreiben);
		  fputs(stStruktur.sPwd, FPSchreiben);
		  fclose(FPSchreiben);
	  }
	  else
	  {
		  printf("\n\tProgramm mit 'x' beenden.\n"
		  "\tBitte am System anmelden:\n"
		  "\t_________________________\n");
		  do
		  {
			  fgets(stStruktur.sUser, sizeof(stStruktur.sUser), FPLesen);
			  /* Länge des Strings ermitteln! */
			  iLaenge = strlen(stStruktur.sUser);
			  /* Entschlüsseln des Strings */	
			  for (i = 0; i < iLaenge; i++)
			  {
				  if(stStruktur.sUser[i]=='z' 
				  || stStruktur.sUser[i]=='Z')
				  {
					  stStruktur.sUser[i] = 'A';
					  stStruktur.sUser[i] = stStruktur.sUser[i]+1;
				  }
				  stStruktur.sUser[i] = stStruktur.sUser[i]-3;  
			  }
			  //stStruktur.sUser[strlen(stStruktur.sUser)-1] = '\n';
		  }while(!feof(FPLesen));
		  puts(stStruktur.sUser);
		  fclose(FPLesen);
		  do
		  {
		  sEingabe_User[strlen(sEingabe_User)-1] = '\0';
		  printf("\n\tBenutzername eingeben: ");
		  fgets(sEingabe, sizeof(sEingabe), stdin);
		  sscanf(sEingabe, "%s", sEingabe_User);
		  if(strncmp(sEingabe, stStruktur.sUser, sizeof(stStruktur.sUser)) == 0)
		  {
			  do
			  {
				  /* Nach Abmelden od. falscher Eing. wird der Puffer geleert */
				  sEingabe_Pwd[strlen(sEingabe_Pwd)-1] = '\0';
				  printf("\tPasswort eingeben....: ");
				  fgets(sEingabe, sizeof(sEingabe), stdin);
				  sscanf(sEingabe, "%s", sEingabe_Pwd);
				  if(strcmp(stStruktur.sPwd, sEingabe_Pwd) ==0)
				  {
					  iMenue();
					  iBeenden();
					  break;
				  }
				  else if(strcmp(sEingabe_Pwd, "x") == 0 
				  || strcmp(sEingabe_Pwd, "X") == 0)
				  {
					  printf("\n\tVielen Dank und Auf Wiedersehen!");
					  return EXIT_SUCCESS;
				  }
				  else
				  {
					  fprintf(stderr, "\n\tFehler: ungueltiges Passwort\n"
					  "\tNoch %i Versuche verbleiben\n\n", stStruktur.iCounter-1);
					  stStruktur.iCounter--;
				  }
			  }while(stStruktur.iCounter != 0);
		  }
		  else if(strcmp(sEingabe_User, "x") == 0 
		  || strcmp(sEingabe_User, "X") == 0 )
		  {
			  printf("\n\tVielen Dank und Auf Wiedersehen!");
			  return EXIT_SUCCESS;
		  }
		  else
		  {
			  if(stStruktur.iCounter != 1)
			  {
				  fprintf(stderr, "\n\tFehler: ungueltiger Benutzer\n"
				  "\tNoch %i Versuch(e) verbleiben\n\n", stStruktur.iCounter-1);
			  }
			  stStruktur.iCounter--;
		  }
	  }while(stStruktur.iCounter != 0);
	  fprintf(stderr, "\n\tFehler: Zugriff verweigert!");
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
