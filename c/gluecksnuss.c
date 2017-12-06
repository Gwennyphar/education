/** Programm : gluecksnuss.c
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
  int iNuss()
  {
	  int i             = 0;
	  int iZufall       = 0;
	  int iSek          = 0;
	  char sEingabe     = 0;
	  char sInhalt[500][FILENAME_MAX];
	  FILE *FPTip;
	  FPTip = fopen(TIP, "r");
	  for( i = 0; i < 50; i++ )
	  {
		  system("clear");
	  }
	  while( fgets(sInhalt[i], FILENAME_MAX, FPTip) )
	  {
		  i = i + 1;
	  }
	  fclose(FPTip);
	  srand( time(NULL) );
	  iZufall = rand() %i;
	  printf("__Meine_Glücksnuss__<ESC>\n");
	  printf("Glücksnuss jetzt knacken j/n\n");
	  do
	  {
		  scanf("%c", &sEingabe);
		  fflush(stdin);
		  switch( sEingabe )
		  {
			  case 'j': /* Glücksnuss wird ausgelesen */
			  {
				  while( iSek < 1 )
				  {
					  printf("Spruch des Tages %i:\n\n", iZufall + 1);
					  printf("%s", sInhalt[iZufall]);
					  iSek = iSek + 1;
				  };
				  break;
			  }
			  case 'n':
			  {
				  printf("Glücksnuss bleibt ungeknackt!\n");
				  iNuss(); /* frage nach neuer Glücksnuss */
				  break;
			  }
			  case 27: /* Glücksnuss wird beendet */
			  {
				  printf("Glücksnuss weg geworfen!\n");
				  break;
			  }
			  default:
			  {
				  iNuss();
				  break;
			  }
		  }
	  }while( sEingabe == 'n');
	  return 0;
  }
	  
/** Steuerprogramm                                                          
  */
  int iController()
  {
      iNuss();
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
