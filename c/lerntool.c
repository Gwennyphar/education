/** Programm    : Galgenraten.c
  * Version     : 0.1 testing
  * Autor       : Nico Anders
  * Datum       : 06.04.2011
  * Status      : in Arbeit
  * ToDo        : Spielermodus verbessern, Konto einrichten
  */
  
/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <conio.h>
  #include <windows.h>

/** Funktion     : SetCsr
  * Beschreibung : Setzt Cursor auf Zeile y und Spalte x.
  * Status       : fertig
  */
  void SetCsr( int iZeile , int iSpalte )
  {
       COORD Koordinate;          /* Datentyp CCORD aus windows.h fuer struct */
       Koordinate.X = iSpalte;              /* sezt Cursor in Spaltenposition */
       Koordinate.Y = iZeile;               /* setzt Cursor in Zeilenposition */
       SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),Koordinate );
  }
  
/** Funktion     : Switch-Case Anweisung
  * Beschreibung : Ja Nein Abfrage zum Beenden
  * Status       : in Arbeit
  */
  int iJa_Nein()
  {
   	  switch(getch() )
   	  {
	   		case 'j':
				 {
				  	 return 1;
				  	 break;
				 }
   		    case 'n':
				 {
				  	 return 0;
				  	 break;
				 }
		    default:
				 {
					 iJa_Nein();
					 break;
				 }
	 }
  }
  
/** Funktion     : Menue
  * Beschreibung : Verwaltet die Funktionen
  * Status       : in Arbeit
  */
  int iMenue()
  {
      int iEingabe = 0;
      do
      {
          system("cls");
          printf("___________________\n");
          printf("    Galgenraten\n");
          printf("___________________\n");
          printf("<1> Spiel erweitern\n");
          printf("<2> Spiel Beginnen\n");
          printf("<0> Spiel Beenden\n");
          printf("___________________\n");
          printf("==> Eingabe:");
          switch(iEingabe = getch() )
          {
             case '1':
                  {
           		  		  printf("\n Erweitern Sie ihr W\x94rterbuch!");
                          sleep(1000);
                          iWoerterbuch();
                          break;
                  }
             case '2':
                  {
             	   		  printf("\n Viel Spa\xE1 bei Galgenraten!\r");
                          sleep(1000);
                          iGalgenraten();
                          break;
                  }
             case '0':
                  {
				   	  if( iJa_Nein() )
				   	  {
                          printf("\n Tsch\x81ss");
                          sleep(1000);
                          exit(0);
                          break;
				  	  }
				  	  else
				  	  {
					   	  printf("Abbruch!");
					   	  sleep(1000);
					   	  iMenue();
				      }
				      break;
                  }
             default:
                  {
                          printf("Falsche Taste!");
                          break;
                  }
          }
      }while(iEingabe != '0');
      return 0;
  }

/** Funktion     : Woerterbuch
  * Beschreibung : in Datei schreiben
  * Status       : in Arbeit
  */
  int iWoerterbuch()
  {
      int iZaehler  = 0;
      int iEingabe = 0;
      char sWort[FILENAME_MAX];
      FILE *FPZeiger_schreiben;
      system("cls");
      printf("___________________\n");
      printf("    W\x94rterbuch\n");
      printf("___________________\n");
      printf("\n Wieviele W\x94rter eintragen?  ");
      fflush(stdin);
      scanf("%i", &iEingabe);
      for( iZaehler = 1; iZaehler <= iEingabe; iZaehler++)
      {
        FPZeiger_schreiben = fopen("Wörterbuch.bin", "ab");
  	    printf(" Bitte das %3i.Wort eingeben: ", iZaehler);
        fflush(stdin);
        fgets(sWort, FILENAME_MAX, stdin);
        fwrite(sWort, 1, FILENAME_MAX, FPZeiger_schreiben);
        fclose(FPZeiger_schreiben);
        printf(" Das eingegebene Wort lautet: %s\n", sWort);
      }
      printf("\n Eingaben gespeichert, weiter mit Taste");
      getch();
      return 0;
  }

/** struct Spieler
  */
  struct spiel
  {
   	char sName[FILENAME_MAX];
  }stSpieler[0];
  
/** Funktion     : Galgenraten
  * Beschreibung : Hauptprogramm fuer das Spiel
  * Status       : in Arbeit
  */
  int iGalgenraten()
  {
      int iZaehler  = 0;
      int iZufall   = 0;
      int iLaenge   = 0;
      int iVersuche = 0;
      int iAnzahl   = 0;
      int iRichtig[100];
      int iMax;
      int iRaten    = 1;
      char sWort[FILENAME_MAX];
      char cZeichen;
      FILE *FPZeiger_lesen;
      FPZeiger_lesen = fopen("Wörterbuch.bin", "rb");
      if(!FPZeiger_lesen)
	  {
	   	printf(" Kein W\x94rterbuch gefunden!  \r");
	   	sleep(2000);
	   	printf(" Bitte legen Sie ein W\x94rterbuch an!\r");
	   	sleep(3000);
        printf(" Weiter geht's mit <Enter>         \r");
        getch() != 0x0d;
		return 0;
  	  }
  	   else
	   { 
	 /* SEEK_SET setzt Zeiger auf Dateiende */
		fseek(FPZeiger_lesen,0,SEEK_END);
	 /* Variable iMax uebrgibt aktuellen Wert von ftell an srand... */
        iMax = (ftell(FPZeiger_lesen) / FILENAME_MAX);
     /* nuetzlich zum zuruecksetzen von Fehlern im Stream*/
        rewind(FPZeiger_lesen);
     /* Zufall anhand von Systemzeit; Startwert 0 */
        srand(time(NULL));
        for( iZaehler = 0; iZaehler < 1000; iZaehler++ )
        {
     /* ...und holt ein zufaelliges Wort aus Datei */
           iZufall = rand() % iMax;
        }
     /* SEEK_SET setzt Zeiger auf Dateianfang */
        fseek(FPZeiger_lesen, (iZufall * FILENAME_MAX), SEEK_SET);
     /* zum binaeren Lesen in Datei */
        fread(sWort, FILENAME_MAX, 1, FPZeiger_lesen);
        fclose(FPZeiger_lesen);
     /* strlen zum pruefen der Dateigroesse, -1 zum erstezen des \0 Term */
        iLaenge = strlen(sWort)-1;
        iVersuche = iLaenge;
		}
      system("cls");
	  printf("___________________\n");
	  printf("    Galgenraten\n");
	  printf("___________________\n\n");
	  
   /* Spielername aus struct.stSpieler anzeigen */   
      sprintf(stSpieler[0].sName, "Spieler 1");
      sprintf(stSpieler[1].sName, "Spieler 2");
      for( iZaehler=0; iZaehler < iLaenge; iZaehler++)
	  {
	   	printf(" _");
	  }
		printf("\n");
      do
      {
         fflush(stdin);
      /* zeichenweise einlesen mt charakter */
         cZeichen = getch();
         iAnzahl = 0;
         for( iZaehler = 0; iZaehler < iLaenge; iZaehler++ )
         {
     /* prueft wieviel mal das Zeichen im Wort enthalten ist
   	    -32 nuetzlich fuer Unabhängigkeit zwischen Groß und Kleinbuchstaben */
           if(sWort[iZaehler] == cZeichen || sWort[iZaehler] == (cZeichen-32))
           {
               SetCsr(11, iRichtig[iZaehler]); /* Position Zeile und Spalte */
               printf("\n Gut                               \r");
               iAnzahl++;
           }
         }
         if(iAnzahl == 0)
         {
		  	if( iRaten == 1)
  			{
                SetCsr(10, iRichtig[iZaehler]); /* Position Zeile und Spalte */
			 	printf("\n Leider falsch, %s ist dran!\r", stSpieler[1].sName);
				iRaten = 0;
         	}
			else
			{
                SetCsr(10, iRichtig[iZaehler]); /* Position Zeile und Spalte */
			 	printf("\n Leider falsch, %s ist dran!\r", stSpieler[0].sName);
				iRaten = 1;
		  	}
	     }
		 else
		 {
		  	 for( iZaehler = 0; iZaehler < iAnzahl; iZaehler++)
			 {
			    SetCsr(10, (iRichtig[iZaehler]*2)+1); /* Position Zeile und Spalte */
				printf("%c\x07", cZeichen);
				iVersuche--;
			}
         }
      }while(iVersuche > 0);
      printf("\n Super!                                \r");
      getch();
	  return 0;
  }

/** Steuerprogramm
  */
  int iController()
  {
      iMenue();
      return 0;
  }

/** Schnittstelle
  */
  int main()
  {
      iController();
      return 0;
  }
