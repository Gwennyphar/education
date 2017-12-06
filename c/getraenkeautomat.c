/** Programm : Getraenkeautomat.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    : 20.12.2010
  * Stand    : 20.12.2010
  * Status   : in Arbeit
  * ToDo     : erweitern
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define  cls() system("cls")

/** Funktion :
  * Status   : in Arbeit
  */
  int iAutomat()
  {
   /* Deklarationen */
	  int i;
	  int    iSorte   = 0;
	  double dPreis   = 0;
	  int    iMenge   = 1;
	  double dBetrag  = 0;
	  double dEinwurf = 0;
   /* Auswahl der Getraenke */
      cls();
	  printf("|    Mein Getr\x84nkeautomat   |\n");
	  printf("|___________________________|\n");
	  printf("|  1) Wasser   : 0,50 Euro  |\n");
	  printf("|  2) Limonade : 1,00 Euro  |\n");
	  printf("|  3) Bier     : 2,00 Euro  |\n");
	  printf("|___________________________|\n");
	  printf("  W\x84hlen sie ihr Getr\x84nk: ");
	  scanf("%i", &iSorte);
   /* lege den zu zahlenden Betrag fest */
	  switch(iSorte)
	  {
		  case 1:
		  {
			  dPreis = 0.5;
			  break;
		  }
		  case 2:
		  {
			  dPreis = 1.0;
			  break;
		  }
		  case 3:
		  {
			  dPreis = 2.0;
			  break;
		  }
	  }
   /* Eingabe der Menge */
	  printf("\n  Geben sie die gew\x81nschte Menge ein: ");
	  scanf("%i", &iMenge);
   /* Bezahlvorgang */
	  dBetrag = dPreis * iMenge;
	  do
	  {
      cls();
	  printf("|       Bezahlvorgang       |\n");
	  printf("|___________________________|\n");
	  printf("|  1) Wasser   : 0,50 Euro  |\n");
	  printf("|  2) Limonade : 1,00 Euro  |\n");
	  printf("|  3) Bier     : 2,00 Euro  |\n");
	  printf("|___________________________|\n");
		  printf("  Zu Bezahlen: %.2f Euro.", dBetrag);
		  printf("\n\n  Bitte werfen sie eine M\x81nze ein: ");
		  scanf("%lf", &dEinwurf);
		  /* eingeworfenen Betrag anrechnen */
		  dBetrag -= dEinwurf;
	  }
	  while( dBetrag > 0.0);
   /* Ausgabe der Getraenke */
      cls();
	  printf("|      Getr\x84nkeausgabe      |\n");
	  printf("|___________________________|\n");
	  printf("|  1) Wasser   : 0,50 Euro  |\n");
	  printf("|  2) Limonade : 1,00 Euro  |\n");
	  printf("|  3) Bier     : 2,00 Euro  |\n");
	  printf("|___________________________|\n");
	  for( i = 0; i < iMenge; i++ )
	  {
		  printf("  Flasche %i von %i wurde ausgegeben.\n", i +1, iMenge);
	  }
	  printf("\n  Vielen Dank, bitte entnehmen sie ihre Getr\x84nke.\n\n  ");
	  system("pause");
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
