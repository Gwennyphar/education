/** Programm.: Performance Tester
  * Autor....: Nico Anders
  * Version..: 1.0
  * Datum....: 30.05.2012
  * Status...: vorgelegt
  */

/** Praeprozessor
  */ 
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <time.h>
  #include <unistd.h>
  #include "./dat/data.h"

int iHauptmenue();

/** Funktion: Datenstruktur fuer erfasste Zugriffszeiten
  * Status..: vorgelegt
  */
  struct messdaten
  {
	  float fDiff_1;
	  float fDiff_2;
	  float fDiff_3;
	  float fDiff_bin_1;
	  float fDiff_bin_2;
	  float fDiff_bin_3;
  }stZeit;


/** Funktion: Datenstruktur fuer erfasste Testdaten
  * Status..: vorgelegt
  */
  struct testdaten
  {
	  char   sArtikelname[32];
	  char   sHersteller[32];
	  int    iArtikelnummer;
	  double dPreis;
  }stDaten;

/** Funktion: aktuelle Messdaten anzeigen
  * Status..: vorgelegt
  */
  int iMessdaten_anzeigen()
  {
	  iHauptbildschirm();
	  cursor(7,17);
	  printf("Datensatz | Textform | Binärform\n");
	  printf("\t\t 1000      | %.2lf sek | %.2lf sek\n", 
	  stZeit.fDiff_1, stZeit.fDiff_bin_1);
	  printf("\t\t 10000     | %.2lf sek | %.2lf sek\n", 
	  stZeit.fDiff_2, stZeit.fDiff_bin_2);
	  printf("\t\t 100000    | %.2lf sek | %.2lf sek\n", 
	  stZeit.fDiff_3, stZeit.fDiff_bin_3);
	  cursor(16,17);
	  printf("Weiter mit beliebiger Taste");
	  fgetc(stdin);
	  return EXIT_SUCCESS;
  }

/** Funktion: Testdatensaetze in Binaerdatei speichern
  * Status..: vorgelegt
  */
  int iTestdaten_bin_speichern()
  {
	  int iLoop = 0;                /* Zaehlerschleife für Simulation */
	  float fStart = 0;                                  /* Startzeit */
	  float fEnde  = 0;                                    /* Endzeit */
	  FILE *FPSchreiben;
	  /* Binaeratei zum Scheiben oeffnen */
	  FPSchreiben = fopen(T_BIN, "wb");
	  /* pruefen ob der Datei angelegt werden kann */
	  if(FPSchreiben != NULL)
	  {
		  iHauptbildschirm();
		  cursor(7,17);
		  printf("Bitte einen Moment Geduld...");
		  /* Zeitmessung starten */
		  fStart = clock();
		  /* 1000 Durchlaufe */
		  for(iLoop = 0; iLoop < 1000; iLoop++)
		  {
			  fwrite(&stDaten.sArtikelname, 
			  sizeof(stDaten.sArtikelname), 1, FPSchreiben);
			  fwrite(&stDaten.iArtikelnummer, 
			  sizeof(stDaten.iArtikelnummer), 1, FPSchreiben);
			  fwrite(&stDaten.sHersteller, 
			  sizeof(stDaten.sHersteller), 1, FPSchreiben);
			  fwrite(&stDaten.dPreis, 
			  sizeof(stDaten.dPreis), 1, FPSchreiben);
		  }
		  /* Zeitmessung beenden */
		  fEnde = clock();
		  /* benoetigte Zeitspanne berechnen */
		  stZeit.fDiff_bin_1 = (fEnde - fStart) / CLOCKS_PER_SEC;
		  /* Binaeratei aus Sicherheitsgruenden schliessen */
		  fclose(FPSchreiben);
		  FPSchreiben = fopen(ZT_BIN, "w");
		  fStart = clock();
		  /* 10000 Durchlaufe */
		  for(iLoop = 0; iLoop < 10000; iLoop++)
		  {
			  fwrite(&stDaten.sArtikelname, 
			  sizeof(stDaten.sArtikelname), 1, FPSchreiben);
			  fwrite(&stDaten.iArtikelnummer, 
			  sizeof(stDaten.iArtikelnummer), 1, FPSchreiben);
			  fwrite(&stDaten.sHersteller, 
			  sizeof(stDaten.sHersteller), 1, FPSchreiben);
			  fwrite(&stDaten.dPreis, 
			  sizeof(stDaten.dPreis), 1, FPSchreiben);
		  }
		  fEnde = clock();
		  stZeit.fDiff_bin_2 = (fEnde - fStart) / CLOCKS_PER_SEC;
		  fclose(FPSchreiben);
		  FPSchreiben = fopen(HT_BIN, "wb");
		  fStart = clock();
		  /* 100000 Durchlaufe */
		  for(iLoop = 0; iLoop < 100000; iLoop++)
		  {
			  fwrite(&stDaten.sArtikelname, 
			  sizeof(stDaten.sArtikelname), 1, FPSchreiben);
			  fwrite(&stDaten.iArtikelnummer, 
			  sizeof(stDaten.iArtikelnummer), 1, FPSchreiben);
			  fwrite(&stDaten.sHersteller, 
			  sizeof(stDaten.sHersteller), 1, FPSchreiben);
			  fwrite(&stDaten.dPreis, 
			  sizeof(stDaten.dPreis), 1, FPSchreiben);
		  }
		  fEnde = clock();
		  stZeit.fDiff_bin_3 = (fEnde - fStart) / CLOCKS_PER_SEC;
		  fclose(FPSchreiben);
		  cursor(7,17);
		  printf("Testdaten erfolgreich gespeichert");
		  /* Binaere Messdaten speichern */
		  FPSchreiben = fopen(LOGS, "a");
		  fprintf(FPSchreiben, "Verfahren, Datensatz, Sekunden\n");
		  fprintf(FPSchreiben, "Binaer, 1000, %.2lf\n", stZeit.fDiff_bin_1);
		  fprintf(FPSchreiben, "Binaer, 10000, %.2lf\n", stZeit.fDiff_bin_2);
		  fprintf(FPSchreiben, "Binaer, 100000, %.2lf\n", stZeit.fDiff_bin_3);
		  /* CSV Datei schliessen */
		  fclose(FPSchreiben);
		  cursor(16,17);
		  printf("Weiter mit beliebiger Taste");
		  fgetc(stdin);
	  }
	  else                       /* sonst mit Fehlermeldung abbrechen */
	  {
		  cursor(7,17);
		  printf("Fehler: Datei nicht erstellt");
		  fgetc(stdin);
		  return EXIT_SUCCESS;
	  }
	  return EXIT_SUCCESS;
  }

/** Funktion: Testdatensaetze in Textdatei speichern
  * Status..: vorgelegt
  */
  int iTestdaten_speichern()
  {
	  int iLoop = 0;
	  float fStart = 0;
	  float fEnde  = 0;
	  FILE *FPSchreiben;
	  /* Textdatei zum Scheiben oeffnen */
	  FPSchreiben = fopen(T_TEXT, "w");
	  if(FPSchreiben != NULL)
	  {
		  iHauptbildschirm();
		  cursor(7,17);
		  printf("Bitte einen Moment Geduld...");
		  fStart = clock();
		  /* 1000 Durchlaufe */
		  for(iLoop = 0; iLoop < 1000; iLoop++)
		  {
			  fprintf(FPSchreiben, "%s\n", stDaten.sArtikelname);
			  fprintf(FPSchreiben, "%i\n", stDaten.iArtikelnummer);
			  fprintf(FPSchreiben, "%s\n", stDaten.sHersteller);
			  fprintf(FPSchreiben, "%.2lf\n", stDaten.dPreis);
		  }
		  fEnde = clock();
		  stZeit.fDiff_1 = (fEnde - fStart) / CLOCKS_PER_SEC;
		  /* Textdatei aus Sicherhheitsgruenden schliessen */
		  fclose(FPSchreiben);
		  FPSchreiben = fopen(ZT_TEXT, "w");
		  fStart = clock();
		  /* 10000 Durchlaufe */
		  for(iLoop = 0; iLoop < 10000; iLoop++)
		  {
			  fprintf(FPSchreiben, "%s\n", stDaten.sArtikelname);
			  fprintf(FPSchreiben, "%i\n", stDaten.iArtikelnummer);
			  fprintf(FPSchreiben, "%s\n", stDaten.sHersteller);
			  fprintf(FPSchreiben, "%.2lf\n", stDaten.dPreis);
		  }
		  fEnde = clock();
		  stZeit.fDiff_2 = (fEnde - fStart) / CLOCKS_PER_SEC;
		  fclose(FPSchreiben);
		  FPSchreiben = fopen(HT_TEXT, "w");
		  fStart = clock();
		  /* 100000 Durchlaufe */
		  for(iLoop = 0; iLoop < 100000; iLoop++)
		  {
			  fprintf(FPSchreiben, "%s\n", stDaten.sArtikelname);
			  fprintf(FPSchreiben, "%i\n", stDaten.iArtikelnummer);
			  fprintf(FPSchreiben, "%s\n", stDaten.sHersteller);
			  fprintf(FPSchreiben, "%.2lf\n", stDaten.dPreis);
		  }
		  fEnde = clock();
		  stZeit.fDiff_3 = (fEnde - fStart) / CLOCKS_PER_SEC;
		  fclose(FPSchreiben);
		  cursor(7,17);
		  printf("Testdaten erfolgreich gespeichert");
		  /* Text Messdaten speichern */
		  FPSchreiben = fopen(LOGS, "a");
		  fprintf(FPSchreiben, "Verfahren, Datensatz, Sekunden\n");
		  fprintf(FPSchreiben, "Text, 1000, %.2lf\n", stZeit.fDiff_bin_1);
		  fprintf(FPSchreiben, "Text, 10000, %.2lf\n", stZeit.fDiff_bin_2);
		  fprintf(FPSchreiben, "Text, 100000, %.2lf\n", stZeit.fDiff_bin_3);
		  fclose(FPSchreiben);
		  cursor(16,17);
		  printf("Weiter mit beliebiger Taste");
		  fgetc(stdin);
	  }
	  else                       /* sonst mit Fehlermeldung abbrechen */
	  {
		  cursor(7,17);
		  printf("Fehler: Datei nicht erstellt");
		  fgetc(stdin);
		  return EXIT_FAILURE;
	  }
	  return EXIT_SUCCESS;
  }

/** Funktion: Testdatensaetze eingeben
  * Status..: vorgelegt
  */
  int iTestdaten_erfassen()
  {
	  char cEingabe[11];
	  /* Eingabe Testdaten */
	  iEingabebildschirm();
	  /* Artikelname eingeben */
	  cursor(7,34);
	  fgets(stDaten.sArtikelname, sizeof(stDaten.sArtikelname), stdin);
	  /* Nullterminierung aus String entfernen */
	  stDaten.sArtikelname[strlen(stDaten.sArtikelname)-1] = '\0';
	  /* Artikelnummer eingeben */
	  cursor(9,34);
	  fgets(cEingabe, sizeof(cEingabe), stdin);
	  sscanf(cEingabe, "%i", &stDaten.iArtikelnummer);
	  /* Hersteller eingeben */
	  cursor(11,34);
	  fgets(stDaten.sHersteller, sizeof(stDaten.sHersteller), stdin);
	  stDaten.sHersteller[strlen(stDaten.sHersteller)-1] = '\0';
	  /* Preis eingeben */
	  cursor(13,34);
	  fgets(cEingabe, sizeof(cEingabe), stdin);
	  sscanf(cEingabe, "%lf", &stDaten.dPreis);
	  /* Ausgabe Testdaten */
	  iEingabebildschirm();
	  cursor(7,34);
	  printf("%s", stDaten.sArtikelname);
	  cursor(9,34);
	  printf("%i", stDaten.iArtikelnummer);
	  cursor(11,34);
	  printf("%s", stDaten.sHersteller);
	  cursor(13,34);
	  printf("%.2lf", stDaten.dPreis);
	  cursor(16,17);
	  printf("Weiter mit beliebiger Taste");
	  fgetc(stdin);
	  return EXIT_SUCCESS;
  }


/** Funktion: Abschlussbildschirm ausgeben
  * Status..: vorgelegt
  */
  int iEnde()
  {
	  iAbschlussbildschirm();
	  iPause_Ende(2);
	  return EXIT_SUCCESS;
  }

/** Funktion: Startbildschirm ausgeben
  * Status..: vorgelegt
  */
  int iStart()
  {
	  iPause_Start(2);
	  iHauptmenue();
	  return EXIT_SUCCESS;
  }
  
/** Funktion: Hauptmenue fuer Auswahl
  * Status..: vorgelegt
  */
  int iHauptmenue()
  {
	  char cAuswahl;
	  do
	  {
		  iMenuebildschirm();                       /* Menue anzeigen */
		  cursor(18,35);
		  scanf("%c", &cAuswahl);
		  flush();
		  switch(cAuswahl)
		  {
			  case '1':
			  {
				  iTestdaten_erfassen();
				  break;
			  }
			  case '2':
			  {
				  iTestdaten_speichern();
				  break;
			  }
			  case '3':
			  {
				  iTestdaten_bin_speichern();
				  break;
			  }
			  case '4':
			  {
				  iMessdaten_anzeigen();
				  break;
			  }
			  case '0':
			  {
				  iEnde();
				  break;
			  }
			  default:
			  {
				  iHauptbildschirm();
				  cursor(7,17);
				  printf("Diese Funktion gibt es leider nicht");
				  fgetc(stdin);
				  break;
			  }
		  }
	  }while(cAuswahl != '0');
	  return EXIT_SUCCESS;
  }

/** Steuerprogramm
  */ 
  int iController()
  {
	  iStart();
	  return EXIT_SUCCESS;
  }

/** Hauptprogramm
  */ 
  int main()
  {
	  iController();
	  return EXIT_SUCCESS;
  }

