/** Programm : Getränkeautomat.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    : 20.12.2010
  * Stand    : 10.09.2011
  * Status   : in Arbeit
  * ToDo     : Rückgeld Funktion
  *            Flaschen auffüllen
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define  clr() system("clear")
  #define  MAX FILENAME_MAX
  #define  DISPLAY "./data/display_auswahl"


/** Funktion : Setzt den Cursor an Position x;y
  * Status   : akzeptiert
  */   
  void iCursor( unsigned int y , unsigned int x )
  {
	  printf( "\033[%i;%iH" , ( y + 1 ) , ( x + 1 ) );
  }

/** Funktion :
  * Status   : in Arbeit
  */
  int iAutomat()
  {
   /* Deklarationen */
	  int i = 0;
	  char sEingabe = 0;
	  int    iSorte   = 0;
	  double dPreis   = 0;
	  int    iMenge   = 1;
	  double dBetrag  = 0;
	  double dEinwurf = 0;
	  char sDisplay[MAX];
	  FILE *FPZeiger;  
   /* Auswahl der Getränke */
   while(1)
   {
      clr();
      FPZeiger = fopen(DISPLAY, "r");
      do
      {
		  printf("%s", sDisplay);
		  fgets(sDisplay, MAX, FPZeiger);
	  }while(!feof(FPZeiger) );
   /* Fie schliessen */
	  fclose(FPZeiger);
	  iCursor( 8, 16 );
	  printf("Guten Tag");
	  iCursor( 10, 16 );
	  printf("Bitte Enter drücken ");
	  getchar();
	  iCursor( 8, 15 );
	  printf("<1> Kaffee   = 0,50€");
	  iCursor( 9, 15 );
	  printf("<2> Wasser   = 0,80€");
	  iCursor( 10, 15 );
	  printf("<3> Limonade = 0,65€ ");
	  iCursor( 11, 15 );
	  printf("<4> Bier     = 1,10€");
	  iCursor( 18, 25 );
	  fflush(stdin);
	  scanf("%i", &iSorte);
	  iCursor( 8, 15 );
	  printf("                      ");
	  iCursor( 9, 15 );
	  printf("                      ");
	  iCursor( 10, 15 );
	  printf("                      ");
	  iCursor( 11, 15 );
	  printf("                      ");

   /* lege den zu zahlenden Betrag fest */
	  switch(iSorte)
	  {
		  case 1:
		  {
			  iCursor( 8, 15 );
			  printf("Kaffe wurde gewählt  ");
			  iCursor( 9, 15 );
			  printf("Bitte Anzahl eingeben ");
			  dPreis = 0.50;
			  break;
		  }
		  case 2:
		  {
			  iCursor( 8, 15 );
			  printf("Wasser wurde gewählt  ");
			  iCursor( 9, 15 );
			  printf("Bitte Anzahl eingeben ");
			  dPreis = 0.80;
			  break;
		  }
		  case 3:
		  {
			  iCursor( 8, 15 );
			  printf("Limonade wurde gewählt");
			  iCursor( 9, 15 );
			  printf("Bitte Anzahl eingeben ");
			  dPreis = 0.65;
			  break;
		  }
		  case 4:
		  {
			  iCursor( 8, 15 );
			  printf("Bier wurde gewählt  ");
			  iCursor( 9, 15 );
			  printf("Bitte Anzahl eingeben ");
			  dPreis = 1.10;
			  break;
		  }
		  default:
		  {
			  iCursor( 8, 15 );
			  printf(" %i habe ich leider\n\t\tnicht im Angebot", iSorte);
			  iCursor( 18, 61 );
			  scanf("%s", &sEingabe);
			  if( sEingabe == 'o' )
			  {
				  iAutomat();
				  break;
			  }
		  }
	  }
   /* Eingabe der Menge */
   	  iCursor( 18, 37 );
   	  fflush(stdin);
	  scanf("%i", &iMenge);
   /* Bezahlvorgang */
	  dBetrag = dPreis * iMenge;
	  do
	  {
		  iCursor( 10, 15 );
		  printf("Bitte %.2f€ einwerfen", dBetrag);
		  if(dBetrag <= 10.00 )
		  {
			  iCursor( 18, 51 );
			  scanf("%lf", &dEinwurf);
		  }
		  else
		  {
			  iCursor( 18, 50 );
			  scanf("%lf", &dEinwurf);
		  }
		  /* eingeworfenen Betrag anrechnen */
		  dBetrag -= dEinwurf;
	  }
	  while( dBetrag > 0.0);
   /* Ausgabe der Getränke */
   	  iCursor( 8, 15 );
	  printf("Einen Moment bitte...");
	  iCursor( 9, 15 );
	  for( i = 0; i < iMenge; i++ )
	  {
		  iCursor( 9, 15 );
		  printf("Getränk %d von %d kommt\r", i +1, iMenge);
	  }
	  iCursor( 10, 15 );
	  printf("Bitte Getränk entnehmen");
	  iCursor( 11, 15 );
	  printf("Vielen Dank\n");
	  iCursor( 18, 69 );
	  scanf("%s", &sEingabe);
	  if( sEingabe == 'o' )
	  {
		iAutomat();
	  }
	  else
	  {
		  break;
	  }
   }
	  getchar();
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
	  iAutomat();
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
