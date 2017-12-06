/**  Programm: Rechnung.c
  *  Autor   : Nico Anders
  *  Version : 0.2
  *  Datum   : 20.01.2012
  *  Stand   : 20.01.212
  *  Status  : in Arbeit
  *  ToDo    : Berechnung in Schleife korrigieren Loesung mit Struct,
  *            HTML-Code anordnen
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>          /* nuetzlich f. strcat         */
  #include <math.h>            /* nuetzlich f. addition etc   */
  #include <time.h>            /* nuetzlich f. Datum und Zeit */
  #define  DAT "Rechnung.html" /* Output File f. Rechnung     */

/** Funktion : automatisierte Handyrechnungen erstellen
  * Status   : in Arbeit
  */
   int iRechnung_erstellen()
   {
	   double dGebuehr = 0.09;   /* Grundgebuehr in andere Netze */
	   double dBetrag[5]={0};
	   /*dBetrag[0] = 0;
	   dBetrag[1] = 0;
	   dBetrag[2] = 0;
	   dBetrag[3] = 0;
	   dBetrag[4] = 0;*/
	   double dNetto      = 0;
	   double dBrutto     = 0;
	   double dMin        = 0;    /* Gespraechsminuten */
	   int iKunde         = 0;    /* Kundennummer      */
	   int iRechnung      = 0;    /* Rechnungsnummer   */
	   int iVerbindung    = 0;    /* gewlt. Rufnummer  */
	   int iNummer        = 0;    /* eigene Rufnummer  */
	   int iZaehler       = 0;
	   time_t Zeit;
       time(&Zeit);
       srand(time(NULL));
	   FILE *FPSpeichern;
	   char sKunden[FILENAME_MAX];
	   FPSpeichern=fopen( DAT,"w" );
	   /* strcat(ctime(&Zeit), "%s");  * Datum an Datei anheften
	                                   * noch nicht benutzbar */
	   printf("_________Rechnungs_Ersteller____________\n\n");
	   printf("Kundendaten eintragen\n\n");
	   printf("Kundennummer.....: ");
	   scanf("%i",&iKunde);
	   fflush(stdin);
	   printf("Rechnungsnummer..: ");
	   scanf("%i",&iRechnung);
	   fflush(stdin);
	   printf("Rufnummer........: "); /* Rufnummer des Kunden eingeben */
	   scanf("%i",&iNummer);
	   fflush(stdin);
	   if( NULL == FPSpeichern)
	   {
		   fprintf(stderr, "Kann %s nicht oeffnen!\n", DAT);
		   getchar(); /* Fehlerausgabe ungleich 0*/
	   }
	   else
	   {
		   fgets(sKunden, FILENAME_MAX, stdin);
		   fprintf(FPSpeichern,"<html>\n<head>\n<title>Ihre Easy Talk Rechnung"
		   "</title>\n<h3>Ihre Rechnung vom %s</h3>\n<br>"
		   "\nKundennummer...............: %i\n<br>\nRechnungsnummer..........:"
		   " %i\n<br>\n<br>\n</head>\n<body>\n<h5>Einzelnachweise f&uuml;r "
		   "Rufnummer %i</h5>\n <table border=""0"">\n<tr>\n<th align=left>	<h5>Pos</h5><th><h5>Rufnummern</h5><th><h5>Dauer</h5><th><h5>Betr&auml;ge</h5></th>\n<tr>", ctime(&Zeit), iKunde, iRechnung, iNummer);
           /* 5 versch. Telefonate durchlaufen und abspeichern */
		   for(iZaehler = 1; iZaehler <= 5; iZaehler++)
		   {
			   iVerbindung = rand() %10000000; /* 11stell.Handynr. generieren */
			   dMin = rand() %100;        /* 2stell. Gespr.Minuten generieren */
			   dBetrag[0] = dGebuehr * dMin; /* Grundgeb. mal die Minute */
			   fprintf(FPSpeichern,"\n<td align=left><h6>%i.</h6>"
			   "\n<td align=left><h6>0178/%i</h6>"
			   "\n<td align=left><h6>%.2lf min.</h6>"
			   "\n<td align=left><h6>%.2lf &euro </h6>\n<tr>\n",
			   iZaehler, iVerbindung, dMin, dBetrag[0]);
		    }
		    dNetto = dBetrag[0] /** iZaehler*/;/* Betrag * die Anzahl der Gespr. */
		    dBrutto = dNetto * 19/100+(dBetrag[0]);/* Nettobetrag + die 19% MwSt */
		    fprintf(FPSpeichern,"\n</table>\n_________________________________________"
		   "\n<br>\nNettobetrag.....................: %.2lf,- \n<br>\nBetrag"
		   " inkl. 19%% MwSt...: %.2lf,-\n</body>\n</html>", dNetto, dBrutto);
		   printf("\n%s efolgreich erstellt!\n\n", DAT);
	   }
	   fclose(FPSpeichern);
	   system("pause");
	   return 0;
   }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iRechnung_erstellen();
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
