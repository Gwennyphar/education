/** Proramm : adressbuch.c
  * Autor   : Nico Anders
  * Version : 1.0 stable
  * Status  : in Arbeit
  */

/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>

/** struct
  */
  struct
  {
	  char sVorname[20];
      char sNachname[30];
      char sStrasse[30];
      char sHausnummer[5];
      char sPlz[7];
      char sOrt[30];
      char sDatum[10];
      char sSternzeichen[30];
      char sAlter[3];
      char sTel[11];
      char sMail[30];
   }stAdressen;

/** erfasste Eingaben speichern
  */
  int iSpeichern()
  {
	  FILE *FPSpeichern;
	  FPSpeichern=fopen("Adressbuch.bin","r+b");
	  if( NULL == FPSpeichern)
      {
		  FPSpeichern = fopen("Adressbuch.bin","w+b");
		  if( NULL == FPSpeichern )
		  {
			  fprintf(stderr, "Kann \"Adressbuch.bin\" nicht oeffnen!\n");
			  exit (0);
		  }
      }
   /* Datei-Zeiger FPSpeichern auf das Ende der Datei setzen */
      fseek(FPSpeichern, 0, SEEK_END);
    /* Wir schreiben eine Adresse ans Ende von "Adressbuch.bin" */
      if(fwrite(&stAdressen, sizeof(stAdressen), 1, FPSpeichern) != 1)
      {
		  fprintf(stderr,"Fehler bei fwrite...!!!\n");
		  exit (1);
      }
   /* Wir geben unseren Datei-Zeiger wieder frei */
      fclose(FPSpeichern);
      return 0;
  }
  
/** Daten erfassen
  */
  int iEingabe()
  {
	  printf("Vorname...........: ");
	  fgets(stAdressen.sVorname, sizeof(stAdressen.sVorname), stdin);
	  printf("Nachname..........: ");
	  fgets(stAdressen.sNachname, sizeof(stAdressen.sNachname),stdin);
	  printf("Strasse...........: ");
	  fgets(stAdressen.sStrasse, sizeof(stAdressen.sStrasse), stdin);
	  printf("Hausnummer........: ");
	  fgets(stAdressen.sHausnummer,sizeof(stAdressen.sHausnummer),stdin);
	  printf("Postleitzahl......: ");
	  fgets(stAdressen.sPlz, sizeof(stAdressen.sPlz), stdin);
	  printf("Ort...............: ");
	  fgets(stAdressen.sOrt, sizeof(stAdressen.sOrt), stdin);
	  printf("Sternzeichen......: ");
	  fgets(stAdressen.sSternzeichen,sizeof(stAdressen.sSternzeichen),stdin);
	  printf("Alter.............: ");
	  fgets(stAdressen.sAlter, sizeof(stAdressen.sAlter), stdin);
	  iSpeichern();
	  return 0;
  }
  
/** Daten aus Datei lesen
  */
  int iAusgabe()
  {
	  FILE *FPLesen;
      FPLesen = fopen("Adressbuch.bin","r+b");
      if( NULL == FPLesen )
      {
		  fprintf(stderr, "Konnte \"Adressbuch.bin\" nicht oeffnen\n");
		  exit (2);
      }
    /*Wir lesen alle Adressen aus "adressen.dat"*/
      while( fread(&stAdressen, sizeof(stAdressen), 1, FPLesen) ==1)
      {
		  printf("Vorname...........: %s", stAdressen.sVorname);
          printf("Nachname..........: %s", stAdressen.sNachname);
          printf("Strasse...........: %s", stAdressen.sStrasse);
          printf("Hausnummer........: %s", stAdressen.sHausnummer);
          printf("Postleitzahl......: %s", stAdressen.sPlz);
          printf("Ort...............: %s", stAdressen.sOrt);
          printf("Sternzeichen......: %s", stAdressen.sSternzeichen);
          printf("Alter.............: %s", stAdressen.sAlter);
          printf("\n\n");
      }
      fclose(FPLesen);
      return 0;
  }

/** Hauptmenue
  */
  int iMenue()
  {
	  int iWahl = 0;
	  do
	  {
		  printf("_________Mein_Adressbuch____________\n\n");
		  printf("Was möchten Sie machen?\n\n");
		  printf("-1- Neuen Datensatz hinzufuegen\n");
		  printf("-2- Alle Datensaetze ausgeben\n");
		  printf("-3- Programm beenden\n\n");
		  printf("Ihre Auswahl : ");
		  do
		  {
			  scanf("%i",&iWahl);
		  }while(getchar() != '\n');
		  switch(iWahl)
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
			  case 3:
              {
				  printf("...Programm wird beendet\n");
                  break;
			  }
              default:
              {
				  printf(">>%d<< ??\n",iWahl);
			  }
           }
      }while(iWahl != 3);
      return 0;
  }
  
/** Steuerprogramm
  */
  int iController()
  {
	  iMenue();
	  return 0;
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }
