/** Programm : Glückskeks.c
  * Autor	 : Nico Anders
  * Version  : 0.1
  * Datum    : 29.05.2011
  * Stand    : 29.05.2011
  * Status   : in Arbeit
  * ToDo     : bauen
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>
  #define TIP ".zitate"

/** Funktion : Tipps zufällig auslesen
  * Status   : in Arbeit
  */
  int iAusgabe()
  {
	  int i             = 0;
	  int iZufall       = 0;
	  int iSek          = 0;
	  char sInhalt[500][FILENAME_MAX];
	  FILE *FPTip;
	  FPTip = fopen(TIP, "r");
	  while( fgets(sInhalt[i], FILENAME_MAX, FPTip) )
	  {
		  i = i + 1;
	  }
	  fclose(FPTip);
	  srand( time(NULL) );
	  iZufall = rand() %i;
	  printf("__Meine_Glücksnuss__\n");
	  printf("Glücksnuss jetzt knacken");
	  if( getchar() )
	  {
		  while( iSek < 1 )
		  {
			  printf("Spruch des Tages %i:\n\n", iZufall + 1);
			  printf("%s", sInhalt[iZufall]);
			  iSek = iSek + 1;
		  };
	  }
	  else
	  {
		  iAusgabe();
	  }  
	  return 0;
  }
	  
/** Steuerprogramm                                                          
  */
  int iController()
  {
      iAusgabe();
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
