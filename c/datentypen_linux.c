/** uebung datentypen.c
  *
  */
  
/** Preaprozessor
  *
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

/** Funktion: Zeichnekette Eingabe und Ausgabe
  *
  */
  int iZeichenkette()
  {
      char sText[10];           /* Datentyp zum speichern eingelesener Zeichen*/
      
      printf("\n\tBitte gebe hier einen Text ein: ");
      fflush(stdin);
 	  fgets(sText, 10, stdin);    /* uebrgabe von 10 Zeichen an Vaibale sText */
      printf("\tIhre Ausgabe lautet: %s", sText);/* Ausgabe des Zeichen aus
                                                  uebergebenen Variable sText */
      fflush(stdin);                         /* zum leeren des Pufferspeicher */
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
      return 0;
  }

/** Funktion: Felder Ausgabe
  *
  */
  int iFelder()
  {
      float fZahl = 0.00;      /* Datentyp zum speichern von Gleitkommazahlen */
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
      return 0;
  }
 
/** struct
  *
  */
  struct Adressen
  {
         char sVorname[15];
         char sNachname[15];
         char sStrasse[15];
         char sPLZ[5];
         char sOrt[15];
  }stAdressen[10];
 
/** Funktion: Adressen
  *
  */
  
  int iAdressen()
  {
      int iDurchlauf = 0;                /* Variable fuer Anzahl der Adressen */
      int iZaehler = 1;       /* Variable zum hochzaehlen auf naechsten Index */
      FILE *FPZeiger_schreiben;
      FPZeiger_schreiben = fopen("Datenbank.bin", "wb");
      printf("\n\t           Adressen          ");
      printf("\n\t_____________________________");
      printf("\n\tAnzahl der Adressen: ");
      fflush(stdin);
      scanf("%i", &iDurchlauf);                    /*zum uebergeben des Werts in
                                                iDurchlauf an Zaehlerschleife */
      for( iZaehler = 1; iZaehler <= iDurchlauf; iZaehler++ )
      {
           printf("\n\tGeben Sie die %i.Adresse ein!", iZaehler);
           printf("\n\t_____________________________\n");
           printf("\n\tVorname     : ");
           fflush(stdin);
           fgets(stAdressen[10].sVorname, 15, stdin);
           printf("\tNachname    : ");
           fflush(stdin);
           fgets(stAdressen[10].sNachname, 15, stdin);
           printf("\tStrasse     : ");
           fflush(stdin);
           fgets(stAdressen[10].sStrasse, 15, stdin);
           printf("\tPostleitzahl: ");
           fflush(stdin);
           fgets(stAdressen[10].sPLZ, 6, stdin);
           printf("\tWohnort     : ");
           fflush(stdin);
           fgets(stAdressen[10].sOrt, 15, stdin);      
      }
      for( iZaehler = 1; iZaehler <= iDurchlauf; iZaehler++ )
      {
           printf("\n\tIhre %i.erfasste Adresse!", iZaehler);
           printf("\n\t_____________________________\n");
           printf("\tVorname     : %s", stAdressen[10].sVorname);
           printf("\tNachname    : %s", stAdressen[10].sNachname);
           printf("\tStrasse     : %s", stAdressen[10].sStrasse);
           printf("\tPostleitzahl: %s", stAdressen[10].sPLZ);
           printf("\tWohnort     : %s", stAdressen[10].sOrt);
      }
      for( iZaehler = 1; iZaehler <= iDurchlauf; iZaehler++ )
      {
           fprintf(FPZeiger_schreiben, "\n\tIhre %i.erfasste Adresse!", iZaehler);
           fprintf(FPZeiger_schreiben,  "\n\t_____________________________\n");
           fwrite(stAdressen[10].sVorname, 1, 15, FPZeiger_schreiben);
           fwrite(stAdressen[10].sNachname, 1, 15, FPZeiger_schreiben);
           fwrite(stAdressen[10].sStrasse, 1, 15, FPZeiger_schreiben);
           fwrite(stAdressen[10].sPLZ, 1, 6, FPZeiger_schreiben);
           fwrite(stAdressen[10].sOrt, 1, 15, FPZeiger_schreiben);
      }
      fclose(FPZeiger_schreiben);
      printf("\n\tZurueck zur Auswahl");
      return 0;
  }
/** Funktion: Ausgabe Datenbank.bin
  *
  */
  int iDatenbank()
  {
   	  char sLesen[500];
      FILE *FPZeiger_lesen;
      FPZeiger_lesen = fopen("Datenbank.bin", "rb");
      printf("\n\t          Datenbank          ");
      printf("\n\t_____________________________");
 	  fread(sLesen, 1, 500, FPZeiger_lesen);
	  printf("%s", sLesen);
	  fclose(FPZeiger_lesen);
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
      printf("\n\t          Datentypen         ");
      printf("\n\t_____________________________");
      printf("\n\t<1> char");
      printf("\n\t<2> integer");
      printf("\n\t<3> float");
      printf("\n\t<4> Ausgabe");
      printf("\n\t<5> Struct");
      printf("\n\t<6> Datenbank lesen");
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
                      case 5:
                           {
                                iAdressen();
                                break;
                           }
                      
                      case 6:
					  	   {
						   	 	iDatenbank();
						   	 	break;
						   }
                      
                      default:
                              {
                                      printf("\n\tFalsche Taste!\n");
                              }
      }
      }while(iEingabe);
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
