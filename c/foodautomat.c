/** Programm : foodautomat.c
  * Autor    : Nico Anders
  * Version  : 0.1
  * Datum    : 20.12.2010
  * Status   : in Arbei
  * ToDO     : Programm schreiben, Code ergaenzen, Zahlung, Rueckgeld und Mengen
             : -analyse integrieren
             : Problem mit Dezimaleingabe darum vorerst mit Ganzzahlen
             : Druckeransteuerung
  */


/** Praeprozessor
  * Bibliotheken
  */
  #include    <stdio.h>                            /*Heasderdatei Input Output*/
  #include    <stdlib.h>
  #include    <string.h>
  #include    <windows.h>                    /*Headerdatei fuer Befehl sleep()*/
  #include    <conio.h>      /*Headerdatei fuer getch() als Ersatz von getchar*/
  #define     String 160  /*zum speichern der Zeichenlaenge String in sZeichen*/
  #define     cls(); system("cls")       /*cls() ALias fuer system clearscreen*/
  #define     Eistee          0.80
  #define     Limonade        0.40
  #define     Mineralwasser   0.50
  #define     Kaffee          0.60
  #define     Cappuccino      1.00
  #define     Kakao           0.75
  #define     PkEistee        100
  #define     FlLimonade      100
  #define     GlMineralwasser 100
  #define     TasKaffee       100
  #define     TasCappuccino   100
  #define     BchKakao        100
  #define     Erdnuesse       0.30
  #define     Waffeln         0.25
  #define     Kekse           0.45
  #define     Schokoriegel    0.50
  #define     Gummibaerchen   0.90
  #define     Kaugummis       0.15
  #define     TtErdnuesse     100
  #define     SchtlWaffeln    100
  #define     DosKekse        100
  #define     StSchokoriegel  100
  #define     BtGummibaerchen 100
  #define     BdKaugummis     100


/** Funktion : Auswahl
  * Status   : in Planung
  */
  int iHauptmenue()
  {
      int iEingabe = 0;                    /*deklarierte Variable fuer scanf()*/
    do   
    { 
      cls();
      
      printf("\n\t\t+------------------------------+");
      printf("\n\t\t|     Multilingual-Automat     |");
      printf("\n\t\t+------------------------------+");
      printf("\n\t\t| <1> Heisse & Kalte Getraenke |");
      printf("\n\t\t| <2> Snacks & Suesswaren      |");
      printf("\n\t\t| <3> Bedienung                |");
      printf("\n\t\t| <0> Beenden                  |");
      printf("\n\t\t|     Druecken zum Auswaehlen  |");
      printf("\n\t\t|     die Tasten  <1> oder <2> |");
      printf("\n\t\t|     Fuer Hilfe die Taste <3> |");
      printf("\n\t\t+------------------------------+");
      printf("\n\t\t| --> Auswahl: ");
      scanf("%d", &iEingabe);  /*Variable "&iEingabe" Uebergabe an switch-case*/
      
      switch(iEingabe)       /*switch-case Anweisung zum auswaehlen der Menues*/
      {
                       case 1:             /*Eingabe fuer die Getraenkeauswahl*/
                            {
                                   printf("\n\t\t      Drinks werden gelistet");
                                   sleep(1500);/*Verzoegrung der Ausgabe in ms*/
                                   iGetraenkeauswahl();
                                   break;
                            }
                       
                       case 2:            /*Eingabe fuer die Suesswarenauswahl*/
                            {
                                   printf("\n\t\t      Snacks werden gelistet");
                                   sleep(1500);
                                   iSuesswarenauswahl();
                                   break;
                            }
                                   
                       case 3:           /*Eingabe fuer die Automatenbedienung*/
                            {
                                   printf("\n\t\t      Anleitung wird" 
                                                       " aufgerufen\r");
                                   sleep(1500);
                                   iBedienung();
                                   break;
                            }
                            
                       case 0:                           /*Eingabe zum Beenden*/
                            {
                                   printf("\n\t\t      Automat faehrt"
                                                       " herunter!");
                                   sleep(1500);
                                   exit(0);
                                   break;
                            }
                            
                       default:               /*Warnhinweis fuer Fehlbedienung*/
                            {
                                   printf("\n\t\t      %i steht nicht zur"
                                                       " Auswahl!",iEingabe);
                                   sleep(1500);
                                   break;
                            }
      }
     }while(iEingabe);  
      return 0;
  }
  

/** Funktion : Getraenkeauswahl
  * Status   : in Planung
  */
  int iGetraenkeauswahl()
  {
      int iEingabe = 0;
    do 
    { 
      cls();
      
      printf("\n\t\t+------------------------------+");
      printf("\n\t\t|     Multilingual-Automat     |");
      printf("\n\t\t+------------------------------+");
      printf("\n\t\t| <1> Eis-Tee        |  0.80,- |");
      printf("\n\t\t| <2> Limonade       |  0.40,- |");
      printf("\n\t\t| <3> Mineralwasser  |  0.55,- |");
      printf("\n\t\t| <4> Kaffee         |  0.60,- |");
      printf("\n\t\t| <5> Cappuccino     |  1.00,- |");
      printf("\n\t\t| <6> Kakao          |  0.75,- |");
      printf("\n\t\t| <0> Abbrechen                |");
      printf("\n\t\t+------------------------------+");
      printf("\n\t\t| --> Getraenk: ");
      scanf("%d", &iEingabe);
      
      switch(iEingabe)
      {
                       case 1:                 /*Eingabe fuer Getraenk Eis-Tee*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iEistee();
                                   break;
                            }
                       
                       case 2:                /*Eingabe fuer Getraenk Limonade*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iLimonade();
                                   break;
                            }
                                   
                       case 3:           /*Eingabe fuer Getraenk Mineralwasser*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iMineralwasser();
                                   break;
                            }
                            
                       case 4:                  /*Eingabe fuer Getraenk Kaffee*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iKaffee();
                                   break;
                            }
                            
                       case 5:              /*Eingabe fuer Getraenk Cappuccino*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iCappuccino();
                                   break;
                            }
                            
                       case 6:                   /*Eingabe fuer Getraenk Kakao*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iKakao();
                                   break;
                            }
                            
                       case 0:      /*Eingabe zum zurueckkehren ins Hauptmenue*/
                            {
                                   printf("\n\t\t      Vorgang wird abgebrochen"
                                                       "!");
                                   sleep(1500);
                                   iHauptmenue;
                                   break;
                            }
                            
                       default:               /*Warnhinweis fuer Fehlbedienung*/
                            {
                                   printf("\n\t\t      %i steht nicht zur"
                                                       " Auswahl!",iEingabe);
                                   sleep(1500);
                                   break;
                            }
      }
     }while(iEingabe); 
      return 0;
  }
 
 
/** Funktion : Eistee
  * Status   : in Planung
  */
  int iEistee()
  {
      int    iMenge  = PkEistee;                /*Variable iMenge fuer Packung*/
      int    iStueck = 0;
   	  double dPreis  = Eistee;                  /*Variable dPreis fuer Eis-Tee*/
   	  double dBetrag = 0;
 	  int    iStatus = 0;
	  FILE  *FPStream;
	  char   sZeichen[String];
      FILE  *FPPack;
      FPPack         = fopen("pack", "r");
      int iZahl = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = PkEistee - iStueck;       /*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Eistee ist ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Packungen vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Packung Eis-Tee kommt...\t\t\t\r");   
              sleep(1500); 
                                
      /** Warenausgang
        */                             
      if(!FPPack)                              
      {
              printf("\n\t\t\tKeine Packung gefunden!\r");
              sleep(1000);
              printf("\t\t\tweiter mit <Enter>\t  ");
      }
            
          else                                                  
          { 
                fgets(sZeichen,160,FPPack);               
             do
             {

                             printf("\t\t%s",sZeichen);   
                             fgets(sZeichen,160,FPPack);

             }while(!feof(FPPack));
             
          fclose(FPPack);
          printf("\t\t      Vielen Dank!\r");
          sleep(2000);                          
          printf("\t\t      weiter geht's mit <Enter>\r");      
         }while(getch() != 0x0d);

              sleep(1500); 
              
              
              /** popen() Aufruf des Programm "lpr"
                * -P Zusatz fuer Ausgabegeraet
                */
	              if ((FPStream = popen ("lpr", "w")) == NULL)
	              {
                     perror("printer: popen() fehlgeschlagen");
		             return (1);
                  }

              /** Zeile 268 bis 275
                * Postscript Sequenz an Standardeingabekanal "lpr"
                */	
                  fprintf(FPStream, "%%!PS\n%%%%BoundingBox: 30 30 565 810\n"
                  "%%%%Orientation: Portrait\n%%%%EndProlog\n"
                  "100 700 moveto\n"
                  "/Time-Roman 24 selectfont\n"
                  "(Vielen Dank für Ihren Kauf) show\n)"
                  "currentpoint pop 100 add 2 div\n"
                  "newpath 708 65 0 360 arc stroke\n"
                  "showpage\n");

                  iStatus = pclose (FPStream);
                  printf("print: lpr returned %d.\n", iStatus);
                  printf("\t\tweiter geht's mit <Enter>");  
                  while(getch() != 0x0d);             /*warte auf Eingabetaste*/
      }
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }

/** Funktion : Limonade
  * Status   : in Planung
  */
  int iLimonade()
  {
      int    iMenge  = FlLimonade;             /*Variable iMenge fuer Flaschen*/
      int    iStueck = 0;
   	  double dPreis  = Limonade;                /*Variable Preis fuer Limonade*/
   	  double dBetrag = 0;
      char   sZeichen[String];
      FILE  *FPFlasche;
      FPFlasche      = fopen("bottle", "r");

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = FlLimonade - iStueck;     /*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Limonade ist ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Flaschen vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Flasche Limonade kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   
       /** Warenausgang
         */
         if(!FPFlasche)                              
         {
              printf("\n\t\t\tKeine Flasche gefunden!\r");
              sleep(1000);
              printf("\t\t\tweiter mit <Enter>\t  ");
         }
            
          else                                                  
          { 
                fgets(sZeichen,160,FPFlasche);               
             do
             {

                             printf("\t\t%s",sZeichen);   
                             fgets(sZeichen,160,FPFlasche);

             }while(!feof(FPFlasche));
             
          fclose(FPFlasche);                           
          printf("\t\tweiter geht's mit <Enter>");      
         }while(getch() != 0x0d);

          sleep(1500); 
   
   
   return 0;
  }


/** Funktion : Mineralwasser
  * Status   : in Planung
  */
  int iMineralwasser()
  {
      int    iMenge  = GlMineralwasser;         /*Variable iMenge fuer Glaeser*/
      int    iStueck = 0;
   	  double dPreis  = Mineralwasser;      /*Variable Preis fuer Mineralwasser*/
   	  double dBetrag = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = GlMineralwasser - iStueck;/*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Mineralwasser ist ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Glaeser vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Glas Mineralwasser kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }

  
/** Funktion : Kaffee
  * Status   : in Planung
  */
  int iKaffee()
  {
      int    iMenge  = TasKaffee;                /*Variable iMenge fuer Tassen*/
      int    iStueck = 0;
   	  double dPreis  = Kaffee;                    /*Variable Preis fuer Kaffee*/
   	  double dBetrag = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = TasKaffee - iStueck;      /*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Kaffe ist ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Tassen vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Tasse Kaffee kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }


/** Funktion : Cappuccino
  * Status   : in Planung
  */
  int iCappuccino()
  {
      int    iMenge  = TasCappuccino;            /*Variable iMenge fuer Tassen*/
      int    iStueck = 0;
   	  double dPreis  = Cappuccino;            /*Variable Preis fuer Cappuccino*/
   	  double dBetrag = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = TasCappuccino - iStueck;  /*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Cappuccino ist ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Tassen vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Tasse Cappuccino kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }


/** Funktion : Kakao
  * Status   : in Planung
  */
  int iKakao()
  {
      int    iMenge  = BchKakao;                 /*Variable iMenge fuer Becher*/
      int    iStueck = 0;
   	  double dPreis  = Kakao;                      /*Variable Preis fuer Kakao*/
   	  double dBetrag = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = BchKakao - iStueck;       /*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Kakao ist ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Becher vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Becher Kakao kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }

  
/** Funktion : Suesswarenauswahl
  * Status   : in Planung
  */
  int iSuesswarenauswahl()
  {
            int iEingabe = 0;
    do 
    { 
      cls();
      
      printf("\n\t\t+------------------------------+");
      printf("\n\t\t|     Multilingual-Automat     |");
      printf("\n\t\t+------------------------------+");
      printf("\n\t\t| <1> Erdnuesse      |  0.30,- |");
      printf("\n\t\t| <2> Waffeln        |  0.25,- |");
      printf("\n\t\t| <3> Kekse          |  0.45,- |");
      printf("\n\t\t| <4> Schokoriegel   |  0.50,- |");
      printf("\n\t\t| <5> Gummibaerchen  |  0.90,- |");
      printf("\n\t\t| <6> Kaugummis      |  0.15,- |");
      printf("\n\t\t| <0> Abbrechen                |");
      printf("\n\t\t+------------------------------+");
      printf("\n\t\t| --> Suesswaren: ");
      scanf("%d", &iEingabe);
      
      switch(iEingabe)
      {
                       case 1:              /*Eingabe fuer Suessware Erdnuesse*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iErdnuesse();
                                   break;
                            }
                       
                       case 2:                /*Eingabe fuer Suessware Waffeln*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iWaffeln();
                                   break;
                            }
                                   
                       case 3:                  /*Eingabe fuer Suessware Kekse*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iKekse();
                                   break;
                            }
                            
                       case 4:           /*Eingabe fuer Suessware Schokoriegel*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iSchokoriegel();
                                   break;
                            }
                            
                       case 5:          /*Eingabe fuer Suessware Gummibaerchen*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iGummibaerchen();
                                   break;
                            }
                            
                       case 6:               /*Eingabe fuer Suessware Kaugummi*/
                            {
                                   printf("\n\t\t      Bitte warten...\r");
                                   sleep(1500);
                                   iKaugummis();
                                   break;
                            }
                            
                       case 0:      /*Eingabe zum zurueckkehren ins Hauptmenue*/
                            {
                                   printf("\n\t\t      Vorgang wird abgebrochen"
                                                       "!");
                                   sleep(1500);
                                   iHauptmenue;
                                   break;
                            }
                            
                       default:               /*Warnhinweis fuer Fehlbedienung*/
                            {
                                   printf("\n\t\t      %i steht nicht zur"
                                                       " Auswahl!",iEingabe);
                                   sleep(1500);
                                   break;
                            }
      }
     }while(iEingabe);
      return 0;
  }
  
  
/** Funktion : Erdnuesse
  * Status   : in Planung
  */
  int iErdnuesse()
  {
      int    iMenge  = TtErdnuesse;              /*Variable iMenge fuer Tueten*/
      int    iStueck = 0;
   	  double dPreis  = Erdnuesse;              /*Variable Preis fuer Erdnuesse*/
   	  double dBetrag = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = TtErdnuesse - iStueck;    /*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Erdnuesse sind ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Tueten vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Tuete Erdnuesse kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }


/** Funktion : Waffeln
  * Status   : in Planung
  */
  int iWaffeln()
  {
      int    iMenge  = SchtlWaffeln;        /*Variable iMenge fuer Schachteln*/
      int    iStueck = 0;
   	  double dPreis  = Waffeln;                  /*Variable Preis fuer Waffeln*/
   	  double dBetrag = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = SchtlWaffeln - iStueck;  /*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Waffeln sind ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Packungen vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Packung Waffel kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }


/** Funktion : Kekse
  * Status   : in Planung
  */
  int iKekse()
  {
      int    iMenge  = DosKekse;                  /*Variable iMenge fuer Dosen*/
      int    iStueck = 0;
   	  double dPreis  = Kekse;                      /*Variable Preis fuer Kekse*/
   	  double dBetrag = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = DosKekse - iStueck;       /*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Kekse sind ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Dosen vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Dose Kekse kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }

 
/** Funktion : Schokoriegel
  * Status   : in Planung
  */
  int iSchokoriegel()
  {
      int    iMenge  = StSchokoriegel;          /*Variable iMenge fuer Stangen*/
      int    iStueck = 0;
   	  double dPreis  = Schokoriegel;        /*Variable Preis fuer Schokoriegel*/
   	  double dBetrag = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = StSchokoriegel - iStueck; /*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Schokoriegel sind ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Stangen vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Schokoriegel kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }
  
  
/** Funktion : Gummibaerchen
  * Status   : in Planung
  */
  int iGummibaerchen()
  {
      int    iMenge  = BtGummibaerchen;          /*Variable iMenge fuer Beutel*/
      int    iStueck = 0;
   	  double dPreis  = Gummibaerchen;      /*Variable Preis fuer Gummibaerchen*/
   	  double dBetrag = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = BtGummibaerchen - iStueck;/*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Gummibaerchen sind ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Beutel vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Beutel Gummibaerchen kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }


/** Funktion : Kaugummis
  * Status   : in Planung
  */
  int iKaugummis()
  {
      int    iMenge  = BdKaugummis;               /*Variable iMenge fuer Bunde*/
      int    iStueck = 0;
   	  double dPreis  = Kaugummis;              /*Variable Preis fuer Kaugummis*/
   	  double dBetrag = 0;

      /*while(1)           /*Endlosschleife auskommentiert,Konflikt mit double*/
	  //{
              printf("\t\t      Bitte Anzahl eingeben: ");
              fflush(stdin);                        
              scanf("%i", &iStueck);
              
              dBetrag = iStueck * dPreis;        /*Berechnung fuer Gesamtpreis*/   
              iMenge  = BdKaugummis - iStueck;    /*Differenz fuer Absatzmenge*/
                                    
      if(iMenge <= 0)                  /*Vergleicher zwischen Menge X und NULL*/
      {
              printf("\n\t\t      Kaugummis sind ausverkauft!\r");
              sleep(1000);
      }
      
      else
      {
              printf("\n\t\t      Bitte %.2lf,- einwerfen: ", dBetrag);                
              fflush(stdin);                       
              scanf("%G", &dPreis);
              printf("\n\t\t      Es sind noch %3d Bund vorhanden\r"
                                  , iMenge);
              sleep(1500);
              printf("\t\t      Bund Kaugummi kommt...\t\t \r"
                                "\n\t\t      Vielen Dank!\r");
              sleep(1500); 
      }
      
      
      /*if(dPreis == dBetrag) /*Vergleicher auskommentiert,Konflikt mit double*/
  	  /*{
              break;
  	  }
   }*/
   return 0;
  }
  
  
/** Funktion : Automatenbedienung
  * Status   : in Planung
  */
  int iBedienung()
  {
      char            sZeichen[String];
      FILE                *FPHilfe;
      FPHilfe = fopen("readme", "r");
      
    if(!FPHilfe)                              
          {
                printf("\n\t\t\tKeine Hilfedatei gefunden!\r");
                sleep(1000);
                printf("\t\t\tweiter mit <Enter>\t  ");
          }
            
          else                                                  
          { 
                fgets(sZeichen,160,FPHilfe);               
             do
             {

                             printf("\t\t%s",sZeichen);   
                             fgets(sZeichen,160,FPHilfe);

             }while(!feof(FPHilfe));
             
             fclose(FPHilfe);                           
             printf("\t\tweiter geht's mit <Enter>");      
          }while(getch() != 0x0d);
          return 0;
  }    
  

/** Steuerfunktion
  * iController()
  */
  int iController()
  {
      iHauptmenue();
      return 0;
  }


/** Schnittstelle
  * main()
  */
  int main()
  {
      iController();
      return 0;
  }
  
/** Programmende
  *
  */
