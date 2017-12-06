#include <stdio.h>
#include <stdlib.h>
#include <time.h>                    /* Headerdatei für Zeitmessungen */
#define  BATCH "Batch.txt"                /* Definition für Textdatei */
#define  TEST  "Datenbank.csv"            /* Definition für Testdatei */

/** Argumente
  */
  int iArgument( int argc, char *argv[] ) /* Übergabe von iController */
  {
   /* Deklarationen */
	  int iZahlen[10] = {0};
	  int iErgebnis  = 0;
	  int i = 0;
	  int x = 0;
   /* Datezeiger */
	  FILE *FPSchreiben, *FPTesten;
   /* Erzeugen von Textateien */
	  FPSchreiben = fopen( BATCH, "a+");
	  FPTesten = fopen( TEST, "a+");
   /* Zeitmessung für Schreibezugriff */
      time_t tStart_Schreiben;
      time_t tEnde_Schreiben;
      double tDiff_Schreiben;
   /* Zeitmessung für Lesezugriff */
   /* time_t tStart_Lesen;
      time_t tEnde_Lesen;
      double tDiff_Lesen; */
	  while( --argc )
	  {
		  **argv++;
		  iZahlen[i] = atoi( *argv );
		  i++;
	  }
   /* iErgebnis mit Werten von iZahlen füllen */
	  iErgebnis = iZahlen[0];
	  
	  for( x = 1; x < i; x++ )
	  {
	   /* Anfangswert für Zeitmessung */
		  time( &tStart_Schreiben );
		  iErgebnis *= iZahlen[x];
		  if( x == 1)
		  {
		   /* Ausdrucksanweisung */
			  printf(" %i * %i", iZahlen[0] , iZahlen[x] );
			  fprintf(FPSchreiben, "%i * %i", iZahlen[0], iZahlen[x] );
		  }
		  else
		  {
			   printf(" * %i", iZahlen[x] );
			   fprintf(FPSchreiben, " * %i", iZahlen[x] );
		  }
	  } 
	  printf( " = %i\n" , iErgebnis );
	  fprintf(FPSchreiben, " = %i\n", iErgebnis );
   /* Endwert für Zeitmessung */
	  time( &tEnde_Schreiben );
   /* hier Datei schließen */
	  fclose(FPSchreiben);
   /* tEnde, tStart zum berechnen der Zugriffszeiten; Schreiben */
	  tDiff_Schreiben = /* ==> */
	  difftime(tEnde_Schreiben, tStart_Schreiben);
   /* Schreibe Testwerte in Datei */
	  fprintf(FPTesten,"%.2lf;",tDiff_Schreiben);
	  fclose(FPTesten);
   /* Sprung-Anweisung */
	  return 0;  
}

/** Steuerprogramm
  */
  int iController( int argc, char *argv[] )      /* Übergabe von main */
  {
	  iArgument( argc, argv );  /* ...hier iArguemente an iController */
	  return 0;
  }

/** Hauptprogramm
  */
  int main( int argc, char *argv[] )           /* Arguemetenuebergabe */
  {
	  iController( argc, argv );  /* ...und Argumente aus iController */
	  return 0;
  }
