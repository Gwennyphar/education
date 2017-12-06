/** uebung datentypen.c
  *
  */
  
/** Preaprozessor
  *
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <conio.h>


/** Funktion: Zeichnekette Eingabe und Ausgabe
  *
  */
  int iZeichenkette()
  {
      char sText[10];           /* Datentyp zum speichern eingelesener Zeichen*/
      
      printf("\n\tBitte gebe hier einen Text ein: ");
      fflush(stdin);
 	  fgets(sText, 10, stdin);               /* zur uebergabe von 10 Zeichen an Vaibale sText */
      printf("\tIhre Ausgabe lautet: %s", sText);/* Ausgabe des Zeichen aus
                                                  uebergebenen Variable sText */
      fflush(stdin);                         /* zum leeren des Pufferspeicher */
      getch();
      return 0;
  }
  
/** Funktion: Ganzzahlen Eingabe und Ausgabe
  *
  */
  int iGanzzahlen()
  {
      int iZahl = 0;                 /* Datentyp zum speichern von Ganzzahlen */
      
      printf("\n\tBitte gebe hier eine Ganzzahl ein: ");
      fflush(stdin);
      scanf("%i",&iZahl);
      printf("\n\tIhre Ausgabe lautet: %i", iZahl);     /* Ausgabe fuer Ganzzahl
                                                           aus Variable iZahl */
      fflush(stdin);
      getch();
      return 0;
  }

/** Funktion: Ganzzahlen Eingabe und Ausgabe
  *
  */
  int iGleitkommazahlen()
  {
      float fZahl = 0.00;      /* Datentyp zum speichern von Gleitkommazahlen */
      
      printf("\n\tBitte gebe hier eine Dezimalzahl ein: ");
      fflush(stdin);
      scanf("%f", &fZahl);
      printf("\n\tIhre Ausgabe lautet: %.2f", fZahl);
      fflush(stdin);
      getch();
      return 0;
  }

/** Funktion: Felder Ausgabe
  *
  */
  int iFelder()
  {
      float fZahl = 0.00;      /* Datentyp zum speichern von Gleitkommazahlen */
      float  fFeld[5][5];
      int    iSpalte = 0;
      int     iZeile = 0;
	  int   iZaehler_Spalte = 0;
	  int   iZaehler_Zeile = 0;      
      
      printf("\n\t     Tabelle erstellen       ");
      printf("\n\t_____________________________");
      printf("\n\tBitte gebe hier Spaltenanzahl ein: ");
      fflush(stdin);
      scanf("%i", &iZaehler_Spalte);
      printf("\n\tBitte gebe hier Zeilenanzahl ein: ");
      fflush(stdin);
      scanf("%i", &iZaehler_Zeile);
      
      printf("\n\t           Spalten           ");
      printf("\n\t_____________________________");
      for( iSpalte = 1; iSpalte <= iZaehler_Spalte; iSpalte++ )
      {
           printf("\n\tBitte gebe hier die %i.Dezimalzahl ein: ", iSpalte);
           fflush(stdin);
           scanf("%f", &fZahl);
      }
      
      printf("\n\t           Zeilen            ");
      printf("\n\t_____________________________");
	  for(iZeile = 1; iZeile <= iZaehler_Zeile; iZeile++)
	  {
	   	   printf("\n\tBitte gebe hier die %i.Dezimalzahl ein: ", iZeile);
 		   fflush(stdin);
 		   scanf("%f", &fZahl);
	  }
      printf("\n\t          Ihr Array          ");
      printf("\n\t_____________________________");
      for( iSpalte = 1; iSpalte <= iZaehler_Spalte; iSpalte++ )
      {
          for(iZeile = 1; iZeile <= iZaehler_Zeile; iZeile++)
          {
		   	printf("\n\tIhre [%i][%i] Feldausgabe lautet: %.2f",iSpalte, iZeile, fZahl );
          }
      }
      fflush(stdin);
      getch();
      return 0;
  }

/** Funktion: Menueauswahl
  *
  */
  int iMenue()
  {
      int iEingabe = 0;
     do
     {
      system("cls");
      printf("\n\t          Datentypen         ");
      printf("\n\t_____________________________");
      printf("\n\t<1> char");
      printf("\n\t<2> integer");
      printf("\n\t<3> float");
      printf("\n\t<4> Ausgabe");
      printf("\n\t_____________________________");
      printf("\n\tBitte eine Auswahl treffen: ");
      fflush(stdin);
      scanf("%i", &iEingabe);
      switch(iEingabe)
      {
                      case 1:
                           {
                                iZeichenkette();
                                break;
                           }
                           
                      case 2:
                           {
                                iGanzzahlen();
                                break;
                           }
                      case 3:
                           {
                                iGleitkommazahlen();
                                break;
                           }
                      case 4:
                           {
                                iFelder();
                                break;
                           }
                      
                      default:
                              {
                                      printf("\n\tFalsche Taste!\n");
                              }
      }
      }while(iEingabe);
      system("pause");
      fflush(stdin);
      getch();
      return 0;
  }
  
/** Steuerfunktion
  *
  */
  int iController()
  {
      iMenue();
      return 0;
  }

/** Programmschnittstelle
  *
  */
  int main()
  {
      iController();
      return 0;
  }
    
  
