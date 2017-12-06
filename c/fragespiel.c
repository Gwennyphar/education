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
  #define DATEI "antworten.txt"

/** Funktion : Tipps zufällig auslesen
  * Status   : in Arbeit
  */
  int iAusgabe()
  {
	  int i             = 0;
	  int iZufall       = 0;
	  int iSek          = 0;
	  int iEingabe      = 0;
	  char FPAntwort[500][FILENAME_MAX];
	  FILE *FPDatei;
	  FPDatei = fopen(DATEI, "r");
	  while( fgets(FPAntwort[i], FILENAME_MAX, FPDatei) )
	  {
		  i = i + 1;
	  }
	  fclose(FPDatei);
	  srand( time(NULL) );
	  iZufall = rand() %i;
      printf("""Du stehts nun in einem dunklen Raum.\nDu kannst nichts sehen, aber die Luft ist sehr warm und feucht,\nund du hörst ein rhythmisches tiefdröhnendes Schnaufen \nund dir stehen die Nackenhaare zu Berge.\nWas willst du tun?""\n");
      printf("\n1.zurück gehen"); 
      printf("\n2.direkt auf das Schnaufen zu"); 
      printf("\n3.An der östlichen Wand entlangschleichen"); 
      printf("\n4.An der südlichen Wand entlang schleichen");
      printf("\n5.Etwas in den Raum rufen wie ""Hallo""");
      printf("\n6.Auf den Boden hocken und warten");
      printf("\n7.Einen Gegenstand aus dem Rucksack benutzen"); 
      printf("\n8.beten\n\n");
      printf("Eingabe: ");
	  scanf("%i", &iEingabe);
	  switch( iEingabe )
	  {
		  case 1:
		  case 2:
		  case 3:
		  case 4:
		  case 5:
		  case 6:
		  case 7:
		  case 8:
		  {
			  while( iSek < 1 )
			  {
				  printf("%s", FPAntwort[iZufall]);
				  iSek = iSek + 1;
			  };
			  break;
		  }
		  default:
		  {
			  iAusgabe();
		  }
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
