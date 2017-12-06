/** Programm :
  * Autor	 :
  * Version  :
  * Datum    :
  * Stand    :
  * Status   :
  * ToDo     :
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define  DATEI "Adressen.txt"

/** Funktion : Kommandozeilenargumente
  * Status   : in Arbeit
  */
  int iArgument( int argc, char *argv[10000] )
  {
   /* Deklarationen */
	  int i = 0;
	  int iRandom = 99999;
	  int iWert[argc];
	  int iTausch[argc];
	  int iMarker = 0;
   /* Dateizeiger */
	  FILE *FPStream;
	  FPStream = fopen(DATEI, "a+");
   /* Zufallszahlen von Systemzeit */
	  srand(time(NULL) );
   /* Anzahl mit argc an Schleife übergeben */
	  for( i = 1; i <= argc; i++ )
      {
		  iWert[argc] = rand() %iRandom +99999; /* Zahlen generieren */
	   /* Ausdrucksanweisung */
		  printf("PLZ[%i]: %5i ", i, iWert[argc]);
		  printf("\n");
		  fprintf(FPStream, "PLZ[%i]: %5i\n",i, iWert[argc]);
	  }
   /* Sortieren */
      do
      {
		  iMarker = 0;
		  i     = 0;
		  while( i <= argc -2)
		  {
			  if( iWert[i] > iWert[i +1])
			  {
				  iTausch[i]   = iWert[i];
				  iWert[i]     = iWert[i +1];
				  iTausch[i+1]   = iTausch[i];
				  iMarker = 1;
			  }
			  i++;
		  }
	  }while( iMarker == 1 );
   /* Datei schließen */
	  fclose(FPStream);
   /* Rücksprung-Anweisunng */
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController( int argc, char *argv[10000] )
  {
	  iArgument( argc, argv );
	  return 0; /* Sprung-Anweisung */
  }

/** Hauptprogramm
  */
  int main( int argc, char *argv[10000] )
  {
	  iController( argc, argv );
	  return 0;
  }

/** Programmende
  */
