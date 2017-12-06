/** Programm....: ssl-login.c
  * Entwickler..: Nico
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
  #include <time.h>                      /* Datum Uhrzeit */
  
  #ifdef __linux__
  #define Ae "Ä"
  #define ae "ä"
  #define Ue "Ü"
  #define ue "ü"
  #define Oe "Ö"
  #define oe "ö"
  #define ss "ß"
  #elif __WIN32__ || _MSC_VER__
  #define Ae "\x8E"
  #define ae "\x84"
  #define Ue "\x9A"
  #define ue "\x81"
  #define Oe "\x99"
  #define oe "\x94"
  #define ss "\xE1"
  #endif

  int iLogin();
  int iController();

/** Funktion....: Datenstruktur
  * Beschreibung: 
  * Status......: vorgelegt 
  */
  struct
  {
	  int iVersuche;
  }Struktur;

/** Funktion....: Eingabe verzoegern
  * Beschreibung: 
  * Status......: vorgelegt 
  */
  int iSetze_Pause(int iZeit)
  {
	  time_t tStart;
	  time_t tStop;
	  double dDiff;
	  tStart = time(NULL);
	  while((dDiff = difftime(tStop = time(NULL),tStart)) != iZeit);
	  return EXIT_SUCCESS;
  }

/** Funktion....: Beenden
  * Beschreibung: Benutzer vorher fragen ob beendet werden soll
  * Status......: vorgelegt
  */
  int iBeenden()
  {
	  char cTaste[3];
	  char sEingabe[3];
	  do
	  {
		  printf("\n\tProgramm Beenden: ja/nein? ");
		  fgets(sEingabe, sizeof(sEingabe), stdin);
		  sscanf(sEingabe, "%c", cTaste);
		  switch(cTaste[0])
		  {
			  case 'n':
			  case 'N':
			  {
				  iLogin();
			  }
			  case 'j':
			  case 'J':
			  {
				  printf("\n\tVielen Dank und Auf Wiedersehen!");
				  fgetc(stdin);
				  return EXIT_SUCCESS;
			  }
		  }
	  }while(cTaste[0] != 'j' || 'J');
	  return EXIT_SUCCESS;
  }


/** Funktion....: Registrieren
  * Beschreibung: 
  * Status......: vorgelegt
  */
  int iRegistrieren()
  {
	  char sPasswd_Eingabe[14];
	  char sPasswd_Setzen [14];
	  char sBenutzer      [22];
	  int  iLaenge         = 0;
	  int  i               = 0;
	  FILE *FPSchreiben;
	  FILE *FPLesen;
	  
	  
	  printf("\n\tWillkommen im Loginbereich!\n"
	  "\tBitte im System eintragen:\n"
	  "\t___________________________\n\n");
	  do
	  {
		  /* Array bei Fehler vorher leeren */
		  sBenutzer[0] = '\0';
		  printf("\n\n\tNeuer Benutzer....: ");
		  /* Eingabe des Benutzernamen */
		  fgets(sBenutzer, sizeof(sBenutzer), stdin);
		  /* Leere Benutzereingabe abfangen */
		  if(sBenutzer[0] == '\n')
		  {
			  fprintf(stderr, "\n\tFehler: Leere Eingabe nicht erlaubt!"
			  "\n\t\tVersuchen Sie es erneut");
		  }
		  /* Laenge des User Strings ermitteln! */
		  iLaenge = strlen(sBenutzer);
		  /* Verschluesseln des User Strings */	
		  for (i = 0; i < iLaenge; i++)
		  {
			  if(sBenutzer[i]=='z' || sBenutzer[i]=='Z')
			  {
				  sBenutzer[i] = 'A';
				  sBenutzer[i] = sBenutzer[i]-1;
			  }
			  sBenutzer[i] = sBenutzer[i]+3;
		  }
		  /* Pruefen, ob verschluesselter 
		   * Benutzername schon vergeben ist */
		  FPLesen = fopen(sBenutzer, "r");
		  if(FPLesen != NULL)
		  {
			  fprintf(stderr, "\n\tFehler: Diesen Benutzer gibt es schon!"
			  "\n\t\tVersuchen Sie es erneut");
		  }
		  /* sonst Benutzer vormerken */
		  else
		  {	  
			  printf("\n\tBenutzer gespeichert!\n");
		  }
	  }while(sBenutzer[0] == '\n' || sBenutzer == NULL);
	  /* Wenn Konto erfolgreich angelegt, hier weiter machen */
	  do
	  {
		  /* Arrays vorher leeren */
		  sPasswd_Eingabe[0]     = '\0';
		  sPasswd_Setzen[0] = '\0';
		  printf("\n\n\tNeues Passwort....: ");
		  /* Eingabe des Passworts */
		  fgets(sPasswd_Eingabe, sizeof(sPasswd_Eingabe), stdin);
		  /* Leere Passworteingaben verhindern */
		  if(sPasswd_Eingabe[0] == '\n')
		  {
			  fprintf(stderr, "\n\tFehler: Leere Eingabe nicht erlaubt!"
			  "\n\t\tVersuchen Sie es erneut"); 
		  }
		  /* Passwort wiederholen */
		  else if(sPasswd_Eingabe[0] != '\n')
		  {
			  printf("\n\n\tPasswort wiederholen....: ");
			  /* Eingabe des 2.Passworts */
			  fgets(sPasswd_Setzen, sizeof(sPasswd_Setzen), stdin);
			  /* Falsche Passworteingaben verhindern */
			  if(!strcmp(sPasswd_Eingabe, sPasswd_Setzen) == 0)
			  {
				  fprintf(stderr, "\n\tFehler: Passwort stimmt nicht!"
				  "\n\t\tVersuchen Sie es erneut");
			  }
		  }
	  }while(sPasswd_Eingabe[0] == '\n' || sPasswd_Setzen[0] == '\n' 
	  || !strcmp(sPasswd_Eingabe, sPasswd_Setzen) == 0);
	  /* Laenge des Passwort Strings ermitteln! */
	  iLaenge = strlen(sPasswd_Setzen);
	  /* Verschluesseln des Passwort Strings */	
	  for (i = 0; i < iLaenge; i++)
	  {
		  if(sPasswd_Setzen[i]=='z' || sPasswd_Setzen[i]=='Z')
		  {
			  sPasswd_Setzen[i] = 'A';
			  sPasswd_Setzen[i] = sPasswd_Setzen[i]-1;
		  }
		  sPasswd_Setzen[i] = sPasswd_Setzen[i]+3;
	  }
	  /* Konto mit Zugangsdaten anlegen */
	  FPSchreiben = fopen(sBenutzer, "w");
	  /* Passwort speichern */
	  fputs(sPasswd_Setzen, FPSchreiben);
	  /* Dateien schließen */
	  fclose(FPSchreiben);
	  printf("\n\tPasswort gespeichert!\n");
	  /* Login neu starten */
	  iController();
	  return EXIT_SUCCESS;
  }

/** Funktion....: Anmelden
  * Beschreibung: 
  * Status......: vorgelegt
  */
  int iLogin()
  {
	  char sPasswd_Eingabe      [14];
	  char sPasswd_Lesen        [14];
	  char sBenutzer            [22];
	  char cTaste                [1];
	  char sEingabe              [6];
	  char sBeenden     [2] = {"-b"};
	  int  iLaenge          =      0;
	  int  i                =      0;
	  FILE *FPLesen;
	  
	  printf("\n\tBitte am System anmelden!\n"
	  "\tProgramm mit '-b' Beenden:\n"
	  "\t___________________________\n\n");
	  do
	  {
		  /* Array bei Fehler vorher leeren */
		  sBenutzer[0] = '\0';
		  printf("\n\n\tBenutzer eingeben....: ");
		  /* Benutzernamen eingeben */
		  fgets(sBenutzer, sizeof(sBenutzer), stdin);
		  /* Laenge des User Strings ermitteln! */
		  iLaenge = strlen(sBenutzer);
		  if(strncmp(sBenutzer, sBeenden, sizeof(sBeenden)) == 0)
		  {
			  iBeenden();
			  return EXIT_SUCCESS;
		  }
		  /* Entschluesseln des User Strings, 
		   * indem die Eingabe verschluesselt wird */	
		   for (i = 0; i < iLaenge; i++)
		   {
			   if(sBenutzer[i]=='z' || sBenutzer[i]=='Z')
			   {
				   sBenutzer[i] = 'A';
				   sBenutzer[i] = sBenutzer[i]-1;
			   }
			   sBenutzer[i] = sBenutzer[i]+3;
		   }
		   /* Verschluesselte Benutzer Session oeffnen. 
		    * Benutzereingabe ist gleich der Name der jeiwligen Session */
		   FPLesen = fopen(sBenutzer, "r");
		   /* Bei Erfolg mit Passworteingabe fortfahren */
		   if(FPLesen != NULL)
		   {
			   break;
		   }
		   /* Sonst Passworteingabe blockieren */
		   else if(Struktur.iVersuche == 0)
		   {
			   fprintf(stderr, "\n\tFehler: Zugriff verweigert!");
			   return EXIT_SUCCESS;
		   }
		   /* Vorher aber Versuche abziehen */
		   else if(FPLesen == NULL)
		   {
			   fprintf(stderr, "\n\tFehler: Falscher Benutzer!\n"
			   "\t\tNoch %i Versuch(e)\n\n", Struktur.iVersuche);
			   Struktur.iVersuche--;
			   do
			   {
				   printf("\n\tNeuen Benutzer hinzuf%sgen: ja/nein? ", ue);
				   fgets(sEingabe, sizeof(sEingabe), stdin);
				   sscanf(sEingabe, "%c", cTaste);
				   switch(cTaste[0])
				   {
					   case 'n':
					   case 'N':
					   {
						   break;
					   }
					   case 'j':
					   case 'J':
					   {
						   iRegistrieren();
					   }
				   }
			   }while(cTaste[0] != 'n' || cTaste[0] != 'n');
			   if(Struktur.iVersuche < 1)
			   {
				   printf("\n\tBitte warten...\n");
				   iSetze_Pause(30);
			   }
		   }
	   }while(sBenutzer[sizeof(sBenutzer)] != sBeenden[sizeof(sBeenden)] 
	   || FPLesen == NULL);
	   /* Verschluesselte Benutzer Session beenden */
	   fclose(FPLesen);	   
	   /* hier beginnt die Passwortabfrage */
	   do
	   {
		   /* Array bei Fehler vorher leeren */
		   sPasswd_Eingabe[0] = '\0';
		   printf("\n\n\tPasswort eingeben....: ");
		   /* Passwort eingeben */
		   fgets(sPasswd_Eingabe, sizeof(sPasswd_Eingabe), stdin);
		   /* Laenge des User Strings ermitteln! */
		   iLaenge = strlen(sBenutzer);
		   if(strncmp(sPasswd_Eingabe, sBeenden, sizeof(sBeenden)) == 0)
		   {
			   iBeenden();
			   return EXIT_SUCCESS;
		   }
		   /* Verschluesselte Benutzer Session oeffnen */
		   FPLesen = fopen(sBenutzer, "r");
		   /* Wenn Konto gehackt, Fehler anzeigen */
		   if(FPLesen == NULL)
		   {
			   fprintf(stderr, "\n\tFehler: Ihr Konto wurde gehackt!\n"
			  "\t\tMelden Sie sich erneut an\n\n");
			  iRegistrieren();
		  }
		  /* Bei Erfolg mit Passworteingabe fortfahren */
		  do
		  {
			  /* hier extra variable setzen, fgets kann andere haben */
			  fgets(sPasswd_Lesen, sizeof(sPasswd_Lesen), FPLesen);
			  /* Laenge des Passwort Strings ermitteln! */
			  iLaenge = strlen(sPasswd_Lesen);
			  /* Entschluesseln des Passwort Strings */	
			  for (i = 0; i < iLaenge; i++)
			  {
				  if(sPasswd_Lesen[i] == 'z' || sPasswd_Lesen[i] == 'Z')
				  {
					  sPasswd_Lesen[i] = 'A';
					  sPasswd_Lesen[i] = sPasswd_Lesen[i]+1;
				  }
				  sPasswd_Lesen[i] = sPasswd_Lesen[i]-3;  
			  }
		  }while(!feof(FPLesen));
		  /* Bei Erfolg Zugang gewaehren */
		  if(strncmp(sPasswd_Eingabe, sPasswd_Lesen, 
		  sizeof(sPasswd_Lesen)) == 0)
		  {
			  printf("\n\tWillkommen im System!\n\n");
			  /* Verschluesselte Benutzer Session beenden */
			  fclose(FPLesen);
			  fgetc(stdin);
			  iController();
		  }
		  /* Sonst Passworteingabe blockieren */
		  else if(Struktur.iVersuche == 0)
		  {
			  fprintf(stderr, "\n\tFehler: Zugriff verweigert!");
			  /* Verschluesselte Benutzer Session beenden */
			  fclose(FPLesen);
			  fgetc(stdin);
			  break;
		  }
		  /* Vorher aber Versuche abziehen */
		  else if(!strncmp(sPasswd_Eingabe, sPasswd_Lesen, 
		  sizeof(sPasswd_Lesen)) == 0)
		  {
			  fprintf(stderr, "\n\tFehler: Falsches Passwort!\n"
			  "\t\tNoch %i Versuch(e)\n\n", Struktur.iVersuche);
			  /* Verschluesselte Benutzer Session beenden */
			  fclose(FPLesen);
			  Struktur.iVersuche--;
			  if(Struktur.iVersuche < 1)
			  {
				  printf("\n\tBitte warten...\n");
				  iSetze_Pause(30);
			  }
		  }
	  }while(sBenutzer[sizeof(sBenutzer)] != sBeenden[sizeof(sBeenden)] 
	  || !strncmp(sPasswd_Eingabe, sPasswd_Lesen, sizeof(sPasswd_Lesen)) == 0);
	  return EXIT_SUCCESS;
  }

/** Steuerprogramm
  */
  int iController()
  {
	  printf("\n\t\t\tL o g i n  -  Z o n e\n\n"
	  "\tDieses Tool simuliert eine Login-Zone f%sr Testzwecke.\n"
	  "\t_____________________________________________________\n\n"
	  ,ue);
	  iSetze_Pause(3);
	  Struktur.iVersuche = 3;
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

