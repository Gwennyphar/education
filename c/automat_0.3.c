/** Programm : Getränkeautomat.c
  * Autor	 : Nico Anders
  * Version  : 0.3 alpha6
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
  #include <termios.h>
  #define  clr() system("clear")
  #define  MAX FILENAME_MAX
  #define  DISPLAY "./data/display"

/** Funktion : Setzt den Cursor an Position x;y
  * Status   : akzeptiert
  */   
  void iCursor( unsigned int y , unsigned int x )
  {
	  printf( "\033[%i;%iH" , ( y + 1 ) , ( x + 1 ) );
  }

/** Funktion : Eigene Funktion fuer getche und tcsetattr ohne Zeilenvorschub
  * Status   : aktzeptiert
  */
  int iTaste() 
  {
	/* Anzahl der gelesenen Bytes, -1 bei einem Fehler und 0,
	 * wenn die Pipe mit Dateideskripto am Schreibende geschlossen wurde */
       static int get = -1,fdskr = 0;
	   struct termios pipe;
    /* Zustand holen */
	   tcgetattr(fdskr, &pipe);
    /* bei jedem Zeichen die Bits der lokalen Flags zur Ausgabe
     * und den kanonischen Modus ICANON zurueckgeben */
       pipe.c_lflag&=~ICANON;
    /* Signale nicht auswerten */
	   tcsetattr(fdskr, TCSANOW, &pipe);
	   get=getchar();
	   return get;
   }

/** Funktion :
  * Status   : in Arbeit
  */
  int iAutomat()
  {
   /* Deklarationen */
	  int i = 0;
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
		  fgets(sDisplay, MAX, FPZeiger);
		  do
		  {
			  printf("%s", sDisplay);
			  fgets(sDisplay, MAX, FPZeiger);
		  }while(!feof(FPZeiger) );
		/* Fie schliessen */
		   fclose(FPZeiger);
		   iCursor( 8, 16 );
		   printf("Guten Tag!");
		   printf("\n\n\t\tBitte Enter drücken");
		   iCursor( 18, 16 );
		   getchar();
		   iCursor( 8, 15 );
		   printf("<1> Kaffee   = 0,50€");
		   iCursor( 9, 15 );
		   printf("<2> Wasser   = 0,80€");
		   iCursor( 10, 15 );
		   printf("<3> Limonade = 0,65€ ");
		   iCursor( 11, 15 );
		   printf("<4> Bier     = 1,10€");
		   iCursor( 18, 16 );
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
				   iCursor( 7, 56 );
				   printf("_");
				   iCursor( 8, 15 );
				   printf("Kaffe wurde gewählt  ");
				   iCursor( 9, 15 );
				   printf("Bitte Anzahl eingeben ");
				   dPreis = 0.50;
				   break;
			   }
			   case 2:
			   {
				   iCursor( 9, 56 );
				   printf("_");
				   iCursor( 8, 15 );
				   printf("Wasser wurde gewählt  ");
				   dPreis = 0.80;
				   break;
			   }
			   case 3:
			   {
				   iCursor( 11, 56 );
				   printf("_");
				   iCursor( 8, 15 );
				   printf("Limonade wurde gewählt");
				   dPreis = 0.65;
				   break;
			   }
			   case 4:
			   {
				   iCursor( 13, 56 );
				   printf("_");
				   iCursor( 8, 15 );
				   printf("Bier wurde gewählt  ");
				   dPreis = 1.10;
				   break;
			   }
			   default:
			   {
				   iCursor( 8, 15 );
				   printf(" %i habe ich leider\n\t\tnicht im Angebot", iSorte);
				   iCursor( 18, 65 );
				   iTaste();
				   if( iTaste() == 'a' )
				   {
					   iAutomat();
					   break;
				   }
			   }
		   }
	    /* Eingabe der Menge */
	       iCursor( 9, 15 );
	       printf("Bitte Anzahl eingeben ");
	       iCursor( 18, 28 );
	       fflush(stdin);
	       scanf("%i", &iMenge);
	    /* Bezahlvorgang */
	       dBetrag = dPreis * iMenge;
	       do
	       {
			   iCursor( 10, 15 );
			   printf("Bitte %.2lf€ einwerfen", dBetrag);
			   if(dBetrag <= 10.00 )
			   {
				   iCursor( 18, 42 );
				   fflush(stdin);
				   scanf("%lf", &dEinwurf);
			   }
			   else
			   {
				   iCursor( 18, 41 );
				   fflush(stdin);
				   scanf("%lf", &dEinwurf);
			   }
		    /* eingeworfenen Betrag anrechnen */
		       dBetrag -= dEinwurf;
		   }while( dBetrag > 0.0);
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
		   iCursor( 18, 55 );
		   iTaste();
		   if( iTaste() == 'o' )
		   {
			   iAutomat();
		   }
		   else
		   {
			   exit(0);
		   }
	   }
	   iTaste();
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
