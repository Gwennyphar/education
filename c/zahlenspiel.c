/** Programm : Zahlenspiel.c
  * Autor	 : Nico Anders
  * Version  : 0.5
  * Datum    : 01.06.2011
  * Stand    : 01.06.2011
  * Status   : in Arbeit
  * ToDo     : Spiel ausbauen
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion :
  * Status   : in Arbeit
  */
  int iSpiel()
  {
	  int iZahl    = 1;
	  int iZaehler = 0;
	  int iRichtig = 0;
	  int iZufall  = 0;
	  int i = 0;
	  int iEingabe = 0;
	  srand((int)time(0));
	  
	  printf("__Mein_Zahlenspiel__\n\n");
	  printf("'Erraten Sie die gesuchte Zahl'\n\n");
	  printf("Bereich festlegen: ");
	  scanf("%i", &iEingabe);
	  for( i = 1; i < iEingabe; i++ )
	  {
		  iZufall  = rand() % iEingabe; /* Zufallszahl von 1-10 */
	  }
	  do
	  {
		  printf("Zahleingabe bitte (1-%i): ", iEingabe);
		  scanf("%i", &iZahl);
		  if(iZahl == iZufall)   /* Zahl richtig geraten ... ? */
		  {
			  iRichtig = 1;      /* die Zahl ist richtig */
			  iZaehler++;
			  printf("%i ist richtig! \n", iZufall);
		  }
		  else
		  {
			  if(iZahl > iZufall)
			  {
				  printf("Die Zahl ist kleiner\n");
				  iZaehler++;
			  }
			  else
			  {
				  printf("Die Zahl ist größer\n");
				  iZaehler++;
			  }
		  }
	  }while( (iRichtig != 1) && (iZaehler != 10) );
	  if(iRichtig == 0)
	  {
		  printf("Sie haben 10 Versuche vertan ;( \n");
		  printf("Die Zahl gesuchte war %i gewesen. \n", iZufall);
	  }
	  else
	  {
		  printf("Sie benötigten %i Versuche!\n",iZaehler);
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iSpiel();
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
