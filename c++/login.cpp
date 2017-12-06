/** Programm....: main_Sat_Sep_29_23-33-23_2012.c
  * Entwickler..: Nico anders 
  * Version.....: 0.1
  * Datum.......: Sat Sep 29 23:33:23 2012
  * Status......: in Arbeit
  * ToDo........: 
  */
  
/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  #ifdef __linux__
  #define Ae "Ä"
  #define ae "ä"
  #define Ue "Ü"
  #define ue "ü"
  #define Oe "Ö"
  #define oe "ö"
  #define ss "ß"
  #elif __WIN32__ || _MSC_VER__
  #include <windows.h>
  #define Ae "\x8E"
  #define ae "\x84"
  #define Ue "\x9A"
  #define ue "\x81"
  #define Oe "\x99"
  #define oe "\x94"
  #define ss "\xE1"
  #endif

/** Funktion : Benutzerlogin
  * Status   : vorgelegt
  */
  int iLogin()
  {
	  char sUserID[]={"user"};
	  char sPasswd[]={"foo"};
	  char sEingabe[15];
	  char sPruefen[15];
	  /* Login bei 1 beginnen */
	  int  iVersuche = 1;
	  int  iUser     = 0;
	  int  iPwd      = 0;
	  printf("\n\tGeben Sie bitte Benutzername und Password ein."
	  "\n\tDr%scken Sie zum Fortsetzen die Eingabetaste.", ue);
	  /* Auf Eingabetaste warten */
	  fgetc(stdin);
	  /* Scheife bis zu 3 Falscheingaben wiederholen */
	  while(iVersuche <= 3)
	  {
		  /* Benutzereingabe */
		  printf("\n\tBenutzername..: ");
		  /* behandelt auch Leereingaben */
		  fgets(sEingabe, sizeof(sEingabe), stdin);
		  /* sichere Eingabevariante als scanf() */
		  sscanf(sEingabe, "%s",sPruefen);
		  /* Eingabe mit Benutzername vergleichen und in iUser speichern */
		  iUser = strncmp(sPruefen, sUserID, sizeof(sUserID));
		  /* Passworteingabe */
		  printf("\n\tPasswort......: ");
		  /* behandelt auch Leereingaben */
		  fgets(sEingabe, sizeof(sEingabe), stdin);
		  /* sichere Eingabevariante als scanf() */
		  sscanf(sEingabe, "%s",sPruefen);
		  /* Eingabe mit Passwort vergleichen und in iPwd speichern */
		  iPwd = strncmp(sPruefen, sPasswd, sizeof(sPasswd));
		  /* Wenn Benutzer und Passwort okay, dann anmelden... */
		  if(iUser == 0 && iPwd == 0)
		  {
			  printf("\n\tSie haben sich erfolgreich angemeldet.");
			  /* hier Schleife verlassen */
			  break;
		  }
		  /* ...sonst neuer Versuch */
		  else if(iVersuche != 3)
		  {
			  printf("\n\tFalsches Passwort und/oder Benutzername."
			  "\n\tSie haben noch %i Versuch(e).", 3-iVersuche);
			  /* Auf Eingabetaste warten */
			  fgetc(stdin);
		  }
		  /* und um einen Versuch erhoehen */
		  iVersuche++;
	  }
	  /* Bei 3 Falscheingaben abbrechen */
	  if(iVersuche == 4)
	  {
		  printf("\n\tFalsches Passwort und/oder Benutzername."
		  "\n\tSie k%snnen sich nicht anmelden.", oe);
	  }
	  /* Auf Eingabetaste warten und sauber beenden */
	  fgetc(stdin);
	  return EXIT_SUCCESS;
  }

/** Steuerprogramm
  */
  int iController()
  {
      /* Funktion an OS-Ebene weiterleiten */
      iLogin();
      return EXIT_SUCCESS;
  }

/** Hauptprogramm
  */
  int main()
  {
      /* Funktionsaufruf aus iController() */
      iController();
      return EXIT_SUCCESS;
  }

/** Programmende
  */
