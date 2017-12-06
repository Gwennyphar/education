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
  #include <string.h>
  #include <time.h>
  #define ZAHLEN 100
  #define DATEI "Code.txt"
  #define CODE "pin.txt"
  #define ZEICHEN "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwiyz!$&=?*#%-+()/\[]~.,\""
  #define PIN "0123456789"
  #ifdef __linux__
	#define clr(); system("clear");
  #else
	#define clr(); system("cls");
  #endif

/** Funktion : Zufallszahlen erzeugen
  * Status   : in Arbeit
  */
  int iPasswort_erzeugen()
  {
	  int  i = 0;
	  int  x = 0;
	  int  y = 0;
	  char sAnzahl[255];
   	  int  iAnzahl  = 0;
   	  char sFeld[8];
   	  char sPin[8];
   	  char sZeichen[81] = ZEICHEN;
   	  char sZusatz[11] = PIN;
   	  srand(time(NULL));
   	  FILE *FPasswort;
   	  do {
		  clr();
		  printf("\t__________Passwortgenerator________\n\n");
		  printf("\tWie viele Codes generieren? ");
		  // Puffer leeren
		  sAnzahl[0] = '\0';
		  fgets(sAnzahl, sizeof(sAnzahl), stdin);
		  sscanf(sAnzahl, "%i", &iAnzahl);
		  printf("\n");
		  if( iAnzahl > 0 ) {
			  FPasswort = fopen(DATEI, "w+");
			  for( i = 1; i <= iAnzahl; i++ )
			  {
				  //Passphrase generieren
				  for( x = 0; x < 8; x++ )
				  {
					  sFeld[x] = sZeichen[(rand() % 81)];
				  }

				  //Geheimzahl generieren
				  for( y = 0; y < 4; y++ )
				  {
					  sPin[y] = sZusatz[(rand() % 10)];
				  }
				  
				  printf("\t%4i.Code: %s-%s\n", i, sFeld, sPin);
				  fprintf( FPasswort, "%4i.Code: %s-%s\n", i, sFeld, sPin);
				 
			  }
			  fclose(FPasswort);
		  } else {
			  printf("\tGenerierung fehlgeschlagen!");
		  }
		  printf("\n\tNochmal generieren? J/N ");
		  fgets(sAnzahl, sizeof(sAnzahl), stdin);
	  }while( sAnzahl[0] != 'n' && sAnzahl[0] != 'N' );
	  return EXIT_SUCCESS;
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
