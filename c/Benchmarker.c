/** Programm : Benchmarker
  * Autor	 : Nico Anders
  * Version  : 1.0 stable
  * Datum    : 13.05.2011
  * Stand    : 15.05.2011
  * Status   : in Arbeit
  * ToDo     : verbessern
  */

/** Präprozessor
  * Bibliothek-Einbindung fÃ¼r Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define  UNSORT "PLZ.txt"
  #define  SORT   "PLZ_Sortiert.txt"
  #define  TIME   "Benchhmark.csv"
  
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
	  int iZahl[99999];
	  int iWechsel[99999];
   /* Datezeiger */
	  FILE *FPUnsort, *FPSort, *FPTime;
   /* Dateien öffnen bzw. erzeugen */
	  FPUnsort = fopen(UNSORT,"a");
	  FPSort   = fopen(SORT,"a");
	  FPTime   = fopen(TIME,"a");
   /* Zufallswerte aus Systemzeit */
      srand(time(NULL) );
   /* Datentypen fÃ¼r clock_t und time_t */
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
		  iZahl[i] = rand() %iZufall +9999;
		  fprintf(FPUnsort, "PLZ[%5i]: %5i\n",i +1, iZahl[i]);
		  i++;
	  }
	  End_Dat = clock();
	  i = 0;
   /* Ausdrucksanweisung Zufallswerte */
      printf("\n\n Unsortierte Postleitzahlen:\n\n");
      Start_Unsort = clock();
      while( i < argc )
      {
		  printf(" %5i |",iZahl[i]);
		  i++;
	  }
	  End_Unsort = clock();
	  printf("\n");
	  while( j <= 79 )
	  {
		  printf("_");
		  j++;
	  }
	  printf("\n Sortierte Postleitzahlen:\n\n");
   /* Zeitmessung Start */
      Start_Sort  = clock();
   /* Sortieren */
      do
      {
		  iFlag = 0;
		  i     = 0;
		  while( i <= argc -2)
		  {
			  if( iZahl[i] > iZahl[i +1])
			  {
				  iWechsel[i]  = iZahl[i];
				  iZahl[i]     = iZahl[i +1];
				  iZahl[i+1]   = iWechsel[i];
				  iFlag = 1;
                  fprintf(FPSort, "PLZ[%5i]: %5i\n",i +1, iWechsel[i]);
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
		   printf(" %5i |",iZahl[i]);
		   i++;
	   }
	/* Zeitmessung Ende */
	   End_Ausg  = clock();
	   End_Ges   = clock();
	/* Messwerte in Prozent */
	   int iErg_Ges    = 100;
	   int iErg_Write   = (End_Dat-Start_Dat)      / (End_Ges-Start_Ges)*iErg_Ges;
	   int iErg_Unsort = (End_Unsort-Start_Unsort) / (End_Ges-Start_Ges)*iErg_Ges;
	   int iErg_Sort   = (End_Sort-Start_Sort)     / (End_Ges-Start_Ges)*iErg_Ges;
	   int iErg_Ausg   = (End_Ausg-Start_Ausg)     / (End_Ges-Start_Ges)*iErg_Ges;
	/* Ausdrucksanweisung Messwerte */
	   printf("\n\n Gesamtzeit    : %.4f  Sekunden",
	   (float)(End_Ges-Start_Ges) / CLOCKS_PER_SEC, iErg_Ges);
   	/* Ausdrucksanweisung Prozent */
	   printf("\t%.2f  %%\n", iErg_Ges);
    /* Schreiben */
       fprintf(FPTime, "%.4f sek.;", (float) End_Ges-Start_Ges / CLOCKS_PER_SEC );
   	/* Ausdrucksanweisung Messwerte */   
	   printf(" Schreibzeit   : %.4f  Sekunden",
 	   (float)(End_Dat-Start_Dat) / CLOCKS_PER_SEC);
	/* Ausdrucksanweisung Prozent */
	   printf("\t%.2f  %%\n", iErg_Write);
    /* Schreiben */
       fprintf(FPTime, "%.4f sek.;", (float) End_Dat-Start_Dat / CLOCKS_PER_SEC );
	/* Ausdrucksanweisung Messwerte */ 
	   printf(" PLZ Unsortiert: %.4f  Sekunden",
	   (float)(End_Unsort-Start_Unsort) / CLOCKS_PER_SEC);
   	/* Ausdrucksanweisung Prozent */
	   printf("\t%.2f  %%\n", iErg_Unsort);
    /* Schreiben */
       fprintf(FPTime, "%.4f sek.;", (float) End_Unsort-Start_Unsort / CLOCKS_PER_SEC );
	/* Ausdrucksanweisung Messwerte */  
	   printf(" PLZ Sortieren : %.4f  Sekunden",
	   (float)(End_Sort-Start_Sort) / CLOCKS_PER_SEC);
   	/* Ausdrucksanweisung Prozent */
	   printf("\t%.2f  %%\n", iErg_Sort);
    /* Schreiben */
       fprintf(FPTime, "%.4f sek.;", (float) End_Sort-Start_Sort / CLOCKS_PER_SEC );
	/* Ausdrucksanweisung Messwerte */    
	   printf(" PLZ Sortiert  : %.4f  Sekunden",
	   (float)(End_Ausg-Start_Ausg) / CLOCKS_PER_SEC);
   	/* Ausdrucksanweisung Prozent */
	   printf("\t%.2f  %%\n\n ", iErg_Ausg);
    /* Schreiben */
       fprintf(FPTime, "%.4f sek.;\n", (float) End_Ausg-Start_Ausg / CLOCKS_PER_SEC );
    /* Dateien wieder schließen */
	   fclose(FPUnsort);
       fclose(FPSort);
       fclose(FPTime);
     /*warte auf Taste */
	   system("pause");
	   return 0;
}

/** Steuerprogramm                                                          
  */
  int iController( int argc, char *argv[] )
  {
	  iSortieren( argc, argv );
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
