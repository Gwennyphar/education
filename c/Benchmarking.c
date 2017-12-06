/** Programm : Bench
  * Autor	 : Nico Anders
  * Version  : 1.0 testing
  * Datum    : 13.05.2011
  * Stand    : 13.05.2011
  * Status   : in Arbeit
  * ToDo     : verbessern
  */

/** Präprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define  DATEI "Daten.txt"
  
/** Funktion : Zufallsdaten generieren, sortieren speichern und messen
  * Status   : in Arbeit
  */
  int iSortieren( int argc, char *argv[] )
  {
   /* Deklarationen */
	  int i = 0;
	  int j = 0;
	  int iZufall       = 99999;
	  int iFlag         =     0;
	  int iDaten[100];
	  int iWechsel[100];
   /* Datezeiger */
	  FILE *FPStream;
	  FPStream = fopen(DATEI,"w");
   /* Zufallswerte aus Systemzeit */
      srand(time(NULL) );
   /* Datentypen für clock_t und time_t */
      clock_t Start_Dat, End_Dat;
      clock_t Start_Unsort, End_Unsort;
      clock_t Start_Sort, End_Sort;
      clock_t Start_Ausg, End_Ausg;
      clock_t Start_Ges, End_Ges;
   /* Zeitmessung Start */
      Start_Ges  = clock();
      Start_Dat  = clock();
   /* Daten erzeugen und in Datei speichern */
      while( i < argc )
      {
		  iDaten[i] = rand() %iZufall +10000;
		  fprintf(FPStream, "Datensatz %3i: %5i\n",i +1, iDaten[i]);
		  i++;
	  }
	  End_Dat = clock();
	  i = 0;
   /* Ausdrucksanweisung Zufallswerte */
      printf("\n\nUnsortierte Postleitzahlen:\n\n");
      Start_Unsort = clock();
      while( i < argc )
      {
		  iDaten[i] = rand() %iZufall +10000;
		  printf(" %5i |",iDaten[i]);
		  i++;
	  }
	  End_Unsort = clock();
	  printf("\n");
	  while( j <= 79 )
	  {
		  printf("_");
		  j++;
	  }
	  printf("\nSortierte Postleitzahlen:\n\n");
   /* Zeitmessung Start */
      Start_Sort  = clock();
   /* Sortieren */
      do
      {
		  iFlag = 0;
		  i     = 0;
		  while( i <= argc -2)
		  {
			  if( iDaten[i] > iDaten[i +1])
			  {
				  iWechsel[i]   = iDaten[i];
				  iDaten[i]     = iDaten[i +1];
				  iDaten[i+1]   = iWechsel[i];
				  iFlag = 1;
			  }
			  i++;
		  }
	  }while( iFlag == 1 );
    /* Zeitmessung Ende */
       End_Sort = clock();
       i = 0;
    /* Zeitmessung Start */
       Start_Ausg = clock();
       while( i <= argc -1)
       {
		   printf(" %5i |",iDaten[i]);
		   i++;
	   }
	/* Zeitmessung Ende */
	   End_Ausg  = clock();
	   End_Ges   = clock();
	/* Messwerte in Prozent */
	   int iErg_Ges    = 100;
	   int iErg_Save   = (End_Dat-Start_Dat)       / (End_Ges-Start_Ges)*iErg_Ges;
	   int iErg_Unsort = (End_Unsort-Start_Unsort) / (End_Ges-Start_Ges)*iErg_Ges;
	   int iErg_Sort   = (End_Sort-Start_Sort)     / (End_Ges-Start_Ges)*iErg_Ges;
	   int iErg_Ausg   = (End_Ausg-Start_Ausg)     / (End_Ges-Start_Ges)*iErg_Ges;
	/* Ausdrucksanweisung Messwerte */
	   printf("\nGesamtzeit\t\t%.4f Sekunden\n",
	   (float)(End_Ges-Start_Ges) / CLOCKS_PER_SEC);
	   printf("Schreibvorgang\t\t%.4f Sekunden\t\t %3i Prozent\n",
	   (float)(End_Dat-Start_Dat) / CLOCKS_PER_SEC, iErg_Save);
	   printf("Ausgabe Unsortiert\t%.4f Sekunden\t\t %3i Prozent\n",
	   (float)(End_Unsort-Start_Unsort) / CLOCKS_PER_SEC, iErg_Unsort);
	   printf("Werte Sortieren\t\t%.4f Sekunden\t\t %3i Prozent\n",
	   (float)(End_Sort-Start_Sort) / CLOCKS_PER_SEC, iErg_Sort);
	   printf("Ausgabe Sortiert\t%.4f Sekunden\t\t %3i Prozent\n\n",
	   (float)(End_Ausg-Start_Ausg) / CLOCKS_PER_SEC, iErg_Ausg);
	   fclose(FPStream);
	   system("pause");
	   return 0;
}

/** Steuerprogramm                                                          
  */
  int iController( int argc, char *argv[] )
  {
	  iSortieren( argc, argv  );
	  return 0; /* Sprung-Anweisung */
  }

/** Hauptprogramm
  */
  int main( int argc, char *argv[] )
  {
	  iController( argc, argv );
	  return 0;
  }

/** Programmende
  */
