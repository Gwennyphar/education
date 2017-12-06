/** Programmname : Schulnotenverwaltung.c
  * Autor        : Nico Anders
  * Version      : 1.1
  * Datum        : 28.01.2011
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

/** Funktion : Notenverwaltung
  * Status   : fertig
  */
  int iNotenverwaltung()
  {
      int    iSchueler            =   0;
      double dGesamtnoten         = 0.0;
      double dNotenanzahl         = 0.0;
      double dNotendurchschnitt   = 0.0;
      
      cls();
      printf("\n\t\tWie viele Schueler haben teil genommen? ");
      scanf("%i",&iSchueler);                  /* Einagbe fuer Schueleranzahl */
      printf("\n\t\tWie viele haben sehr gut? ");
      scanf("%lf",&dNotenanzahl);          /* Eingabe fuer Anzahl der Noten 1 */
      dGesamtnoten=dNotenanzahl*1;
      printf("\n\t\tWie viele haben gut? ");
      scanf("%lf",&dNotenanzahl);
      dGesamtnoten=dGesamtnoten+dNotenanzahl*2;    /** Formel zur Berechnung der 
                                                     * uebergebenen Gesamtnote 
                                                     * plus der Notenanzahl 
                                                     * multipliziert mit der 
                                                     * Einzelnote
                                                     */
      printf("\n\t\tWie viele haben befriedigent? ");
      scanf("%lf",&dNotenanzahl);
      dGesamtnoten=dGesamtnoten+dNotenanzahl*3;
      printf("\n\t\tWie viele haben ausreichend? ");
      scanf("%lf",&dNotenanzahl);
      dGesamtnoten=dGesamtnoten+dNotenanzahl*4;
      printf("\n\t\tWie viele haben mangelhaft? ");
      scanf("%lf",&dNotenanzahl);
      dGesamtnoten=dGesamtnoten+dNotenanzahl*5;
      printf("\n\t\tWie viele haben ungenuegend? ");
      scanf("%lf",&dNotenanzahl);
      dGesamtnoten=dGesamtnoten+dNotenanzahl*6;
      dNotendurchschnitt=dGesamtnoten/iSchueler;   /** Formel zur Berechnung des
                                                     * Notendurchschnitt mit
                                                     * Gesamtnoten dividiert
                                                     * durch Schueleranzahl
                                                     */
                                                      
      printf("\n\t\tDer Notendurchschnitt betraegt: %.2lf",dNotendurchschnitt);
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
      printf("\n\t\t Notenverwaltung©");
      printf("\n\t\t Version 1.1");
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
  * Schulnotenverwaltung.c
  */
