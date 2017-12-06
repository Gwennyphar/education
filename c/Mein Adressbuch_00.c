/** Programm : Produktverwaltung.c
  * Autor	 : Nico Anders
  * Version  : 0.9 beta
  * Datum    : 20.02.2011
  * Stand    : 20.02.2011
  * Status   : in Arbeit
  * ToDo     : Programm erweitern
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>
  #define  DAT ".Adressbuch.bin"

/** Funktion : switch-case Ja Nein Funktion  
  * Status   : Fertig                                               
  */
  int iJa_Nein(void)
  {
	  switch( getchar() )
	  {
		  case 'j':
		  {
			  return 1;  /* positives Verhalten; beendet das Programm */
			  break;
		  }
		  case 'n':
		  {
			  return 0; /* negatives Verhalten; kehrt zum Programm zurück */
			  break;
		  }
		  default:
		  {
			  iJa_Nein();
			  break;
		  }
	  }
	  return 1;
  }

/** Funktion : Adressen speichern
  * Status   : in Arbeit
  */
  struct
  {
	  char sVorname[FILENAME_MAX];
	  char sNachname[FILENAME_MAX];
	  char sDatum[12];
	  char sAlter[4];
	  char sAstro[20];
	  char sStrasse[20];
	  char sHausnummer[5];
	  char sPlz[8];
	  char sOrt[FILENAME_MAX];
	  char sTel[15];
	  char sMail[FILENAME_MAX];
	  char sSocial[FILENAME_MAX];
   }stAdressen;

/** Funktion : Prototypen
  * Status   : Fertig                                               
  */
  int iSpeichern();
  int iEingabe();
  int iAusgabe();
  int iMenue();
  int iController();

/** Funktion : Adressen speichern
  * Status   : in Arbeit
  */
   int iSpeichern()
   {
	   FILE *FPSpeichern;
	   FPSpeichern=fopen( DAT,"r+b" );
	   if( NULL == FPSpeichern)
	   {
		   FPSpeichern = fopen( DAT,"w+b" );
		   if( NULL == FPSpeichern )
		   {
			   fprintf(stderr, "Kann \%s\" nicht öffnen!\n", DAT);
			   exit (0);
		   }
	   }
    /* Datei-Zeiger FPSpeichern auf das Ende der Datei setzen */
       fseek(FPSpeichern, 0, SEEK_END);
    /* Wir schreiben eine Adresse ans Ende von "Adressbuch.bin" */
       if(fwrite(&stAdressen, sizeof(stAdressen), 1, FPSpeichern) != 1)
       {
		   fprintf(stderr,"Fehler beim Schreiben!\n");
		   exit (1);
	   }
    /* Wir geben unseren Datei-Zeiger wieder frei */
       fclose(FPSpeichern);
       return 0;
   }

/** Funktion : Adressen eingeben
  * Status   : in Arbeit
  */
  int iEingabe()
  {
	  printf("Vorname...............: ");
	  fgets(stAdressen.sVorname, sizeof(stAdressen.sVorname), stdin);
	  printf("Nachname..............: ");
	  fgets(stAdressen.sNachname, sizeof(stAdressen.sNachname),stdin);
	  printf("Geburtsdatum..........: ");
	  fgets(stAdressen.sDatum,sizeof(stAdressen.sDatum),stdin);
	  printf("Alter.................: ");
	  fgets(stAdressen.sAlter,sizeof(stAdressen.sAlter),stdin);
	  printf("Sternzeichen..........: ");
	  fgets(stAdressen.sAstro,sizeof(stAdressen.sAstro),stdin);
	  printf("Straße................: ");
	  fgets(stAdressen.sStrasse, sizeof(stAdressen.sStrasse), stdin);
	  printf("Hausnummer............: ");
	  fgets(stAdressen.sHausnummer,sizeof(stAdressen.sHausnummer),stdin);
	  printf("Postleitzahl..........: ");
	  fgets(stAdressen.sPlz, sizeof(stAdressen.sPlz), stdin);
	  printf("Ort...................: ");
	  fgets(stAdressen.sOrt, sizeof(stAdressen.sOrt), stdin);
	  printf("Telefonnummer.........: ");
	  fgets(stAdressen.sTel, sizeof(stAdressen.sTel), stdin);
      printf("E-Mail................: ");
      fgets(stAdressen.sMail, sizeof(stAdressen.sMail), stdin);
      printf("Social-Network........: ");
      fgets(stAdressen.sSocial, sizeof(stAdressen.sSocial), stdin);
      		  printf("Vorname...........: %s", stAdressen.sVorname);
	  printf("\nMöchten Sie Ihre Eingaben speichern? Ja/Nein\n");
	  if( iJa_Nein() )
	  {
		  iSpeichern();
	  }
	  else
	  {
		  iMenue();
	  }
	  return 0;
  }

/** Funktion : Adressen ausgeben
  * Status   : in Arbeit
  */
  int iAusgabe()
  {
	  FILE *FPLesen;
      FPLesen = fopen( DAT,"r+b" );
      if( NULL == FPLesen )
      {
		  fprintf(stderr, "Konnte \"%s\" nicht öffnen\n", DAT);
		  printf("\nMöchten Sie jetzt Adressen hinzufügen? Ja/Nein\n");
		  if( iJa_Nein() )
		  {
			  iEingabe();
		  }
		  else
		  {
			  return EXIT_FAILURE;
		  }
	  }
   /* Wir lesen alle Adressen aus "Adressbuch.bin" */
      while( fread(&stAdressen, sizeof(stAdressen), 1, FPLesen) ==1)
      {
		  printf("Vorname...........: %s", stAdressen.sVorname);
          printf("Nachname..........: %s", stAdressen.sNachname);
          printf("Geburtsdatum......: %s", stAdressen.sDatum);
          printf("Alter.............: %s", stAdressen.sAlter);
          printf("Sternzeichen......: %s", stAdressen.sAstro);
          printf("Straße............: %s", stAdressen.sStrasse);
          printf("Hausnummer........: %s", stAdressen.sHausnummer);
          printf("Postleitzahl......: %s", stAdressen.sPlz);
          printf("Ort...............: %s", stAdressen.sOrt);
          printf("Telefonnummer.....: %s", stAdressen.sTel);
          printf("E-Mail............: %s", stAdressen.sMail);
          printf("Social-Network....: %s", stAdressen.sSocial);
          printf("\n\n");
      }
      fclose(FPLesen);
      return 0;
  }

/** Funktion : Auwahlbereich
  * Status   : in Arbeit
  */
 int iMenue()
  {
	  int iAuswahl = 0;
	  do
	  {
		  printf("_________Mein_Adressbuch____________\n\n");
		  printf("Was möchten Sie machen?\n\n");
		  printf("-1- Neue Adresse hinzufügen\n");
		  printf("-2- Alle Einträge anzeigen\n");
		  printf("-0- Programm beenden\n\n");
		  printf("Ihre Auswahl : ");
		  do
		  {
			  scanf("%i", &iAuswahl);
		  }while(getchar() != '\n');
		  switch(iAuswahl)
		  {
			  case 1:
			  {
				  iEingabe();
                  break;
			  }
              case 2:
              {
				  iAusgabe();
				  break;
			  }
			  case 0:
              {
				  printf("...Programm wird beendet\n");
                  break;
			  }
              default:
              {
				  printf(">>%i<< ??\n",iAuswahl);
			  }
           }
      }while(iAuswahl != 0);
      return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iMenue();
	  return 0; /* Sprung-Anweisung */
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }

/** Programmende
  */
