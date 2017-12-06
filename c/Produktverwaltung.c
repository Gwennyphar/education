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
  #define  DAT ".register.bin"

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

/** Funktion : Artikel speichern
  * Status   : in Arbeit
  */
  struct
  {
	  char sArtikel[20];
	  char sModell[20];
	  char sKonfektion[20];
	  char sHersteller[20];
	  char sPreis[10];
	  char sLieferant[20];
	  char sLager[20];
	  char sKommentar[140];
   }stWaren;

/** Funktion : Prototypen
  * Status   : Fertig                                               
  */
  int iSpeichern();
  int iEingabe();
  int iAusgabe();
  int iMenue();
  int iController();

/** Funktion : Artikel speichern
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
       if(fwrite(&stWaren, sizeof(stWaren), 1, FPSpeichern) != 1)
       {
		   fprintf(stderr,"Fehler beim Schreiben!\n");
		   exit (1);
	   }
    /* Wir geben unseren Datei-Zeiger wieder frei */
       fclose(FPSpeichern);
       return 0;
   }

/** Funktion : Artikel eingeben
  * Status   : in Arbeit
  */
  int iEingabe()
  {
	  printf("Artikel...........: ");
	  fgets(stWaren.sArtikel, sizeof(stWaren.sArtikel), stdin);
	  printf("Modell............: ");
	  fgets(stWaren.sModell, sizeof(stWaren.sModell),stdin);
	  printf("Konfektion........: ");
	  fgets(stWaren.sKonfektion, sizeof(stWaren.sKonfektion), stdin);
	  printf("Hersteller........: ");
	  fgets(stWaren.sHersteller,sizeof(stWaren.sHersteller),stdin);
	  printf("Preis.............: ");
	  fgets(stWaren.sPreis, sizeof(stWaren.sPreis), stdin);
	  printf("Lieferant.........: ");
	  fgets(stWaren.sLieferant, sizeof(stWaren.sLieferant), stdin);
	  printf("Lager.............: ");
	  fgets(stWaren.sLager,sizeof(stWaren.sLager),stdin);
	  printf("Kommentar.........: ");
	  fgets(stWaren.sKommentar, sizeof(stWaren.sKommentar), stdin);
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

/** Funktion : Artikel ausgeben
  * Status   : in Arbeit
  */
  int iAusgabe()
  {
	  FILE *FPLesen;
      FPLesen = fopen( DAT,"r+b" );
      if( NULL == FPLesen )
      {
		  fprintf(stderr, "Konnte \"%s\" nicht öffnen\n", DAT);
		  printf("\nMöchten Sie jetzt Artikel anlegen? Ja/Nein\n");
		  if( iJa_Nein() )
		  {
			  iEingabe();
		  }
		  else
		  {
			  return EXIT_FAILURE;
		  }
	  }
   /* Wir lesen alle Artikel aus "register.bin" */
      while( fread(&stWaren, sizeof(stWaren), 1, FPLesen) ==1)
      {
		  printf("Artikel...........: %s", stWaren.sArtikel);
          printf("Modell............: %s", stWaren.sModell);
          printf("Konfektion........: %s", stWaren.sKonfektion);
          printf("Hersteller........: %s", stWaren.sHersteller);
          printf("Preis.............: %s", stWaren.sPreis);
          printf("Lieferant.........: %s", stWaren.sLieferant);
          printf("Lager.............: %s", stWaren.sLager);
          printf("Beschreibung......: %s", stWaren.sKommentar);
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
		  printf("_________Meine_Produktverwaltung_________\n\n");
		  printf("Was möchten Sie machen?\n\n");
		  printf("-1- Neuen Artikel hinzufügen\n");
		  printf("-2- Alle Artikel anzeigen\n");
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
