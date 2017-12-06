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

/** Funktion : Zufallsdaten generieren, sortieren speichern und messen
  * Status   : in Arbeit
  */
  int iProg( int argc, char *argv[] )
  {
	  int i            =   0;
	  int iWechsel[10] = {0};
	  int iDaten[10]   = {0};
	  int iFlag        =   0;
	  do
      {
		  while( --argc )
		  {
			  **argv++;
			  iDaten[i] = atoi( *argv );
		  }
		  if( iDaten[i] > iDaten[i +1])
		  {
			  iWechsel[i]   = iDaten[i];
			  iDaten[i]     = iDaten[i +1];
			  iDaten[i+1]   = iWechsel[i];
			  iFlag = 1;
			  printf("%i", iDaten[i]);
		  }
		  else
		  {
			  printf("%s", *argv);
		  }
		  i++;
	  }while( iFlag == 1 );
	  getchar();
	  return 0;
  }


/** Steuerprogramm                                                          
  */
  int iController( int argc, char *argv[] )
  {
	  iProg( argc, argv );
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
