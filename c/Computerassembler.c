/** Programm : Assembler.c
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
  #define  DAT ".save"

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
        char sCase[FILENAME_MAX];
        char sNetz[FILENAME_MAX];
        char sBoard[FILENAME_MAX];
        char sCPU[FILENAME_MAX];
        char sRAM[FILENAME_MAX];
        char sHDD[FILENAME_MAX];
        char sDrive[FILENAME_MAX];
        char sGraka[FILENAME_MAX];
        char sSK[FILENAME_MAX];
        char sMoni[FILENAME_MAX];
        char sBS[FILENAME_MAX];
  }stAssembler;

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
       if(fwrite(&stAssembler, sizeof(stAssembler), 1, FPSpeichern) != 1)
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
	  printf("Gehäuse...........: ");
	  fgets(stAssembler.sCase, sizeof(stAssembler.sCase), stdin);
	  printf("Netzteil..........: ");
	  fgets(stAssembler.sNetz, sizeof(stAssembler.sNetz), stdin);
	  printf("Mainboard.........: ");
	  fgets(stAssembler.sBoard, sizeof(stAssembler.sBoard), stdin);
	  printf("Prozessor.........: ");
	  fgets(stAssembler.sCPU, sizeof(stAssembler.sCPU), stdin);
	  printf("Arbeitsspeicher...: ");
	  fgets(stAssembler.sRAM, sizeof(stAssembler.sRAM), stdin);
	  printf("Festplatte(n).....: ");
	  fgets(stAssembler.sHDD, sizeof(stAssembler.sHDD), stdin);
	  printf("Laufwerke.........: ");
	  fgets(stAssembler.sDrive, sizeof(stAssembler.sDrive), stdin);
	  printf("Grafikkarte.......: ");
	  fgets(stAssembler.sGraka, sizeof(stAssembler.sGraka), stdin);
	  printf("Soundkarte........: ");
	  fgets(stAssembler.sSK, sizeof(stAssembler.sSK), stdin);
	  printf("Monitor...........: ");
	  fgets(stAssembler.sMoni, sizeof(stAssembler.sMoni), stdin);
	  printf("Betriebssystem....: ");
	  fgets(stAssembler.sBS, sizeof(stAssembler.sBS), stdin);
	  printf("\nMöchten Sie Ihre Komponenten speichern? Ja/Nein\n");
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
		  printf("\nMöchten Sie jetzt Komponenten hinzufügen? Ja/Nein\n");
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
      while( fread(&stAssembler, sizeof(stAssembler), 1, FPLesen) ==1)
      {
		  printf("Gehäuse...........: %s", stAssembler.sCase);
          printf("Netzteil..........: %s", stAssembler.sNetz);
          printf("Mainboard.........: %s", stAssembler.sBoard);
          printf("Prozessor.........: %s", stAssembler.sCPU);
          printf("Arbeitsspeicher...: %s", stAssembler.sRAM);
          printf("Festplatte(n).....: %s", stAssembler.sHDD);
          printf("Laufwerke.........: %s", stAssembler.sDrive);
          printf("Grafikkarte.......: %s", stAssembler.sGraka);
          printf("Soundkarte........: %s", stAssembler.sSK);
          printf("Monitor...........: %s", stAssembler.sMoni);
          printf("Betriebssystem....: %s", stAssembler.sBS);
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
		  printf("_________Mein_Assembler_________\n\n");
		  printf("Was möchten Sie machen?\n\n");
		  printf("-1- Computer zusammenstellen\n");
		  printf("-2- Alle Komponenten anzeigen\n");
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
