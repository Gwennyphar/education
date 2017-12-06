/** Programm : passwortgenerator.c
  * Autor	 : Nico Anders
  * Version  : 1.0 stable
  * Datum    : 02.05.2011
  * Stand    : 02.05.2011
  * Status   : Fertig
  * ToDo     : erweitern
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define ZAHLEN 100
  #define DATEI "Code.txt"
  #define ZEICHEN "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"

/** Funktion : Zufallszahlen erzeugen
  * Status   : in Arbeit
  */
  int iPasswort_erzeugen()
  {
	  int  i = 0;
	  int  x = 0;
   	  int  iAnzahl  = 0;
   	  char sFeld[16];
   	  char sBuchstaben[62] = ZEICHEN;
   	  srand(time(NULL));
   	  FILE *FPZeiger;
   	  FPZeiger = fopen(DATEI, "a");
   	  printf("\t__________Mein_Passwortgenerator________\n\n");
   	  printf("\t    Wie viele Codes generieren? ");
   	  scanf("%i", &iAnzahl);
   	  fflush(stdin);
   	  printf("\n");
   	  for( i = 1; i <= iAnzahl; i++ )
   	  {
		  for( x = 0; x < 16; x++ )
		  {
			  sFeld[x] = sBuchstaben[(rand() % 61)];
		  }
		  printf("\t %4i.Code: %s\n", i, sFeld);
		  fprintf( FPZeiger, "%4i.Code: %s\n", i, sFeld );
  	  }
  	  fclose(FPZeiger);
  	  getchar();
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iPasswort_erzeugen();
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
