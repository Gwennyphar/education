/** Programmname : Zensurenrechner.c
  * Autor        : Nico Anders
  * Version      : 1.2
  * Datum        : 30.01.2011
  * Status       : fertig
  * ToDo         :
  */

/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <conio.h>
  #include <windows.h>
  #define  cls(); system("cls")
  #define  Feld 15

/** Funktion : Notenverwaltung
  * Status   : fertig
  */
  int iNotenverwaltung()
  {
      char   sFach               [Feld];
      int    iQuersumme           = 0.0;
      double dAnzahl              = 0.0;
      double dGesamt              = 0.0;
      double dDurchschnitt        = 0.0;
      
      cls();
      
      printf("\n\t\tBitte gebe dein Fach ein: ");
      fflush(stdin);
      gets(sFach);                        /* Eingabe fuer das Unterrichtsfach */
      printf("\n\n\t\tWie viele Noten sind sehr gut (1)? ");
      scanf("%lf", &dAnzahl);              /* Eingabe fuer Anzahl der Noten 1 */
      dGesamt = dAnzahl * 1;
      printf("\n\t\tWie viele Noten sind gut (2)? ");
      scanf("%lf", &dAnzahl);
      dGesamt = dAnzahl * 2 + dGesamt ;
                 /** 2 => (dAnzahl) * 1 => (dNote) = 2 (dGesamt)
                   * 2 => (dAnzahl * 2 (Note) + 2 (dGesamt) = 6 => (dGesamt)
                   * 6 => (dGesamt) / 4 => (dQuersumme) = 1.5 => (dDurchschnitt)
                   */                                                       
      printf("\n\t\tWie viele Noten sind befriedigend (3)? ");
      scanf("%lf", &dAnzahl);
      dGesamt = dAnzahl * 3 + dGesamt ;            /** Formel zur Berechnung der 
                                                     * uebergebenen Gesamtnote 
                                                     * mit Anzahl der Noten
                                                     * multipliziert mit der
                                                     * Einzelnote addiert mit der
                                                     * Gesamtnote
                                                     */
                                                     
      printf("\n\t\tWie viele Noten sind ausreichend (4)? ");
      scanf("%lf", &dAnzahl);
      dGesamt = dAnzahl * 4 + dGesamt ;
      printf("\n\t\tWie viele Noten sind mangelhaft (5)? ");
      scanf("%lf", &dAnzahl);
      dGesamt = dAnzahl * 5 + dGesamt ;
      printf("\n\t\tWie viele Noten sind ungenuegend (6)? ");
      scanf("%lf", &dAnzahl);
      dGesamt = dAnzahl * 6 + dGesamt ; 
      printf("\n\t\tQuersumme bitte eingeben: ");
      scanf("%i",&iQuersumme);                                                                                               
      dDurchschnitt = dGesamt / iQuersumme;        /** Formel zur Berechnung des
                                                     * Notendurchschnitt mit
                                                     * Gesamtnote dividiert
                                                     * durch die Quersumme
                                                     * der Einzelnoten
                                                     */
                                                                                                     
      printf("\n\t\tDein Notendurchschnitt in %s betragt: %.2lf\n",sFach 
                                                                ,dDurchschnitt);
      
      if(dDurchschnitt > 4.30)
      {
                printf("\n\t\t%.2lf = Versetzungsgef\x84hrdet!", dDurchschnitt);
      }
      
      else
      {
                printf("\n\t\t%.2lf = Bestanden!", dDurchschnitt);
      }
      
      
      printf("\n\n\t\tZurueck in's Menue mit <Enter>");
      while(getch() != 0x0d);
      return 0;
  }

/** Funktion : Hilfe
  * Status   : fertig
  */
  int iHilfe()
  {
      char sZeichen[160];
      FILE *FPHilfe;
      FPHilfe = fopen("readme", "r");
      
      if(!FPHilfe)
      {
                  cls();
                  printf("\n\t\t\tKeine Hilfedatei gefunden!");
                  printf("\n\t\tZurueck in's Menue mit <Enter>");
      }
      
      else                                                  
      {
                  cls();
                  fgets(sZeichen,160,FPHilfe);
                  
                  do
                  {
                                              printf("\t\t%s",sZeichen);
                                              fgets(sZeichen,160,FPHilfe);
                  }while(!feof(FPHilfe));
                  fclose(FPHilfe);
                  printf("\t\t Zurueck in's Menue mit <Enter>");      
      }while(getch() != 0x0d);
       return 0;
  }

/** Funktion : Auswahlmenue
  * Status   : fertig
  */
  int iMenue()
  {
      /*    |*\_/*|_________
	       ||_/-\_|_______ ||
	       ||	           ||
	       ||     0    0   ||
	       ||	    -      ||
	       ||     \___/    ||
	       ||______________||
	       ||_______________|
	             |_____|_
	           /*********\
	          /***********\
	         /-------------\ */
             
             int iWahl = 0;
             
             do
             {
                 cls();
                 printf("\n\t\t|*\\_/*|_________\n");
                 printf("\t\t|*/ \\*|________ |\n");
                 printf("\t\t ||            ||\n");
                 printf("\t\t ||  0     0   ||\n");
                 printf("\t\t ||     *      ||\n");
                 printf("\t\t ||   \\___/    ||\n");
                 printf("\t\t ||____________||\n");
                 printf("\t\t    _|_____|_    \n");
                 printf("\t\t   /<1> Noten\\  \n");
                 printf("\t\t  / <2> Hilfe \\ \n");
                 printf("\t\t /  <0> Ende   \\ \n");
                 printf("\t\t/---------------\\\n");
                 printf("\t\t --> Auswahl: ");
                 fflush(stdin);
                 scanf("%d", &iWahl);
                 
                 switch(iWahl)
                 {
                              case 1:
                                   {
                                            printf("\n\t\t     Willkommen!");
                                            sleep(500);
                                            iNotenverwaltung();
                                            break;
                                   }
                                   
                              case 2:
                                   {
                                            printf("\n\t\t     Starte Hilfe!");
                                            sleep(500);
                                            iHilfe();
                                            break;
                                   }
                                   
                              case 0:
                                   {
                                            printf("\n\t\t     Tschuess!");
                                            sleep(500);
                                            exit(0);
                                            break;
                                   }
                                   
                              case 9:
                                   {
                                            iInfo();
                                            break;
                                   }
                                   
                              default:
                                      {
                                            printf("\n\t\t     Falsche Taste!");
                                            sleep(500);
                                            break;
                                      }
                 }
             }while(iWahl);
              return 0;
  }

/** Funktion : Info
  * Status   : fertig
  */
  int iInfo()
  {
      printf("\n\t\t Zensurenrechner©");
      printf("\n\t\t Version 1.2");
      printf("\n\t\t 28.01.2011");
      printf("\n\t\t Nico Anders");
      sleep(5000);
  }


/** Steuerfunktion
  */
  int iController()
  {
      iMenue();
      return 0;
  }

/**Schnittstelle main()
  */
  int main()
  {
      iController();
      return 0;
  }

/** Programmende
  * Zensurenrechner.c
  */
