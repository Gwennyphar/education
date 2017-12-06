/*******************************************************************************
* Programm        : Taschenrechner                                             *
* Autor           : Nico Anders                                                *
* Version         : 1.2  stable                                                *
* Datum           : 01.09.2010                                                 *
* aktueller Stand : 25.02.2011                                                 *
* Status          : in Arbeit                                                  *
* ToDo            : Modulo % Operator verbessern                               *
*                 : Potenzrechnung einbauen                                    *
*                 : Dau Handling gegen versehentliches Beenden                 *
*******************************************************************************/

/*******************************************************************************
* PRAEPROZESSOR                                                                *
*******************************************************************************/
#include <stdio.h>                                    /* Standard Input Output*/
#include <stdlib.h>                                         /* Standard Libary*/
#include <conio.h>                                     /* Console Input Output*/
#include <windows.h>                                     /* windows Bibliothek*/
#include <math.h>                       /* Bibliothek mathematische Funktionen*/
#define  cls() system("cls")                 /* definiere cls() lösche Ausagbe*/

/*******************************************************************************
* Potenzen                                                                     *
*******************************************************************************/
int iPotenzen()
{
    double dBasis = 0;
    double dExpo  = 0;

    cls();                                   
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tRechenoperation Potenzen\t|\n");
    printf("\t\t+---------------------------------------+\n"); 
    printf("\n\t\t\tBitte Grundzahl eingeben: ");
    scanf("%lf",&dBasis);
    printf("\n\t\t\tBitte Exponenten eingeben: ");
    scanf("%lf",&dExpo);
     
    printf("\n\t\t\tDas Ergebnis lautet: %G ^ %G = %G\n",
    dBasis, dExpo, pow (dBasis,dExpo) );                                                                          
    printf("\n\t\t\tweiter mit <Enter>");
    while(getch() != 0x0d);                           
    return 0;
}

/*******************************************************************************
* Prozenrechnung => Prozentwert(W)                                             *
*******************************************************************************/
int iProzentwert()
{
    double dProzentwert = 0;
    double dProzentsatz = 0;
    double dProzent     = 100;
    double dGrundwert   = 0;
    
    cls();                                   
    printf("\n\n\t\t+---------------------------------------+");
    printf("\n\t\t|   Formel Prozentwert(W)               |\n");
    printf("\t\t+---------------------------------------+\n");                                
    printf("\n\t\t    Bitte Prozentsatz(p%%) eingeben: ");
    fflush(stdin);                        
    scanf("%lf", &dProzentsatz);                     
    printf("\n\t\t    Bitte Grundwert(G) eingeben: ");                
    fflush(stdin);                      
    scanf("%lf", &dGrundwert);
    dProzentwert = dProzentsatz / dProzent * dGrundwert;               
    printf("\n\t\t    Das Ergebnis lautet: %G%% / %G%% * %G = %G\n\n",
    dProzentsatz, dProzent, dGrundwert, dProzentwert);                                                
    printf("\t\t    weiter mit <Enter>");
    while(getch() != 0x0d);                           
    return 0;
}

/*******************************************************************************
* Prozentrechnung => Prozentsatz(p%)                                           *
*******************************************************************************/
int iProzentsatz()
{
    double dProzentsatz = 0;
    double dProzentwert = 0;
    double dGrundwert   = 0;
    double dProzent     = 100;
    
    cls();                                   
    printf("\n\n\t\t+---------------------------------------+");
    printf("\n\t\t|   Formel Prozentsatz(p%%)              |\n");
    printf("\t\t+---------------------------------------+\n");                              
    printf("\n\t\t    Bitte Prozentwert(W) eingeben: ");
    fflush(stdin);                        
    scanf("%lf", &dProzentwert);                     
    printf("\n\t\t    Bitte Grundwert(G) eingeben: ");                
    fflush(stdin);                      
    scanf("%lf", &dGrundwert);
    dProzentsatz = dProzentwert / dGrundwert * dProzent;               
    printf("\n\t\t    Das Ergebnis lautet: %G / %G * %G%% = %G%%\n",
    dProzentwert, dGrundwert, dProzent, dProzentsatz);                                                
    printf("\n\t\t    weiter mit <Enter>");
    while(getch() != 0x0d);                           
    return 0;
}

/*******************************************************************************
* Prozentrechnung => Grundwert(G)                                              *
*******************************************************************************/
int iGrundwert()
{
    double dGrundwert   = 0;
    double dProzentwert = 0;
    double dProzentsatz = 0;
    double dProzent     = 100;
    
    cls();                                   
    printf("\n\n\t\t+---------------------------------------+");
    printf("\n\t\t|   Formel Grundwert(G)                 |\n");
    printf("\t\t+---------------------------------------+\n");                        
    printf("\n\t\t    Bitte Prozentwert(w) eingeben: ");
    fflush(stdin);                        
    scanf("%lf", &dProzentwert);                     
    printf("\n\t\t    Bitte Prozentsatz(p%%) eingeben: ");                
    fflush(stdin);                      
    scanf("%lf", &dProzentsatz);
    dGrundwert = dProzentwert / dProzentsatz * dProzent;               
    printf("\n\t\t    Das Ergebnis lautet: %G / %G%% * %G%% = %G\n",
    dProzentwert, dProzentsatz, dProzent, dGrundwert);                                                
    printf("\n\t\t    weiter mit <Enter>");
    while(getch() != 0x0d);                           
    return 0;
}  

/*******************************************************************************
* Prozentrechnung => Formeln                                                   *
*******************************************************************************/
int iProzentrechnung()
{
    int iAuswahl = 0;                         /* iAuswahl(); ist die Anweisung*/
    int iJa = 0;
    
  do
  {
    
    cls();
    printf("\n\n\t\t+-------------------------------+");
    printf("\n\t\t|     Prozentrechnung           |");
    printf("\n\t\t+-------------------------------+\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <1> Auswahl Prozentwert (W)\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <2> Auswahl Prozentsatz (p%%)\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <3> Auswahl Grundwert   (G)\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <4> Auswahl Mathematik\t|\n\t\t|\t\t\t\t|\n");  
    printf("\t\t| <5> Auswahl Hauptmenue\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <0> Auswahl Beenden\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t+-------------------------------+\n");
    printf("\n\t\t  Bitte waehle eine Rechenart: ");
    fflush(stdin);
    scanf("%i", &iAuswahl);  
    switch(iAuswahl)                         /* switch Anweisung für das Menue*/
    {
                    case 1:
                         {                           /* switch case Anweisung*/
                           printf("\n\t\t  Sie haben den Prozentwert gewaehlt!");
                           Sleep(1000); 
                           iProzentwert();                               
                           break;
                         }
                         
                    case 2:
                         {
                           printf("\n\t\t");  
                           printf("  Sie haben den Prozentsatz gewaehlt!");
                           Sleep(1000); 
                           iProzentsatz(); 
                           break;
                         }
                    
                    case 3:
                         {
                           printf("\n\t\t  Sie haben den Grundwert gewaehlt!");
                           Sleep(1000);  
                           iGrundwert();                   
                           break;
                         }
                         
                    case 4:
                         {
                           printf("\n\t\t");  
                           printf("  Sie haben Mathematik gewaehlt!");
                           Sleep(1000); 
                           iMathematik(); 
                           break;
                         }
                    
                    case 5:
                         {
                           printf("\n\t\t  Willkommen im Hauptmenue!");
                           Sleep(1000);  
                           iMenue();                             
                           break;
                         }
                         
                    case 0:
                         {
                           printf("\n\t\t  Bis Bald!");
                           Sleep(1000);
                           exit(0);
                           break;
                         }
                    
                    default:       /* Standard Rückgabefunktion wenn definiert*/
                    {
                           printf("\n\t\t  Hoppla, Falsche Eingabe!");
                           sleep(1000);
                           break;
                    }                  
    }
   }while(iAuswahl);
    Sleep(1000);
    return 0;
}

/*******************************************************************************
* Ueber mich                                                                   *
*******************************************************************************/
int iInfo()
{
    cls();
    printf("\n\n\t\t+-------------------------------+\n\t\t");
    printf("|    Taschenrechner Programm    |");
    printf("\n\t\t+-------------------------------+\n\t\t|\t\t\t\t|\n");
    printf("\t\t| Autor     : Nico Anders\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| Version   : 1.2 stable\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| Datum     : 25.02.2011\t|\n\t\t|\t\t\t\t|\n");    
    printf("\t\t| Copyright : 2010-2012\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t+-------------------------------+\n");
    printf("\n\t\t     weiter mit <Enter>");
    while(getch() != 0x0d);
    return 0;
}
    

/*******************************************************************************
* Zinsenberechnunng                                                            *
*******************************************************************************/
  int iZinsrechnung()
  {
	  float fGeld 	  = 0;
	  float fZins_tmp = 0;
	  float fZinsen	  = 0;
	  int   iJahre	  = 0;
	  int 	iLaufzeit = 0;
	  
	  cls();
      printf("\n\n\t\t+---------------------------------------+\n\t\t");
      printf("|\tZinsrechnung\t\t\t|\n");
      printf("\t\t+---------------------------------------+\n");
	  printf("\n\t\t\tBitte Geldbetrag eingeben: ");
	  scanf("%f", &fGeld);
	  printf("\n\t\t\tBitte Zinssatz (%%) eingeben: ");
	  scanf("%f", &fZins_tmp);
	  fZinsen = (fZins_tmp / 100) + 1.0f;
	  printf("\n\t\t\tBitte Laufzeit eingeben: ");
	  scanf("%i", &iJahre);
      cls();
      printf("\n\n\t\t+---------------------------------------+\n\t\t");
      printf("|\tRechenoperation Zinsen\t\t|\n");
      printf("\t\t+---------------------------------------+\n");
      printf("\n\t\t\tDas Guthaben betraegt:\n");
      for(iLaufzeit = 0; iLaufzeit < iJahre; fGeld = fGeld * fZinsen, iLaufzeit++)
	  {
		  printf("\n\t\t\t%3d. Jahr: %.3f\n", iLaufzeit+1, fGeld);
	  }
      printf("\n\t\t\tweiter mit <Enter>");
      while(getch() != 0x0d); 
	  return 0;
  }

/*******************************************************************************
* Funktionen Sinus & Tangens                                                   *
*******************************************************************************/
int iFunktionen()
{
    double dCount = 0, max=2*M_PI;
    while(dCount <= max)
    {                  
                  printf("\n\tsin(%.1f) = %.3f", dCount, sin(dCount));
                  printf("\tcos(%.1f) = %.3f",   dCount, cos(dCount));
                  printf("\ttan(%.1f) = %.3f\n", dCount, tan(dCount));
                  dCount += 0.1;
	}
    printf("\n\tweiter mit <Enter>");
    while(getch() != 0x0d);
	return 0;
}





/*******************************************************************************
* ADDITION                                                                     *
*******************************************************************************/
int iAddition()
{
    double dSummandA  = 0;          /* double ist die Variable für Kommazahlen*/
    double dSummandB  = 0;
    double dSumme     = 0;                         /* dSumme ist die Anweisung*/

    cls();                                   /* cls(); lösche aktuelle Ausgabe*/
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tRechenoperation Addition\t|\n");
    printf("\t\t+---------------------------------------+\n");
                                      /* Funktion printf() Ausdruck auf Screen*/
    printf("\n\t\t\tBitte Summand A eingeben: ");
    fflush(stdin);                        
    scanf("%lf", &dSummandA);                      /* scanf(); Eingabefunktion*/
    printf("\n\t\t\tBitte Summand B eingeben: ");                
    fflush(stdin);                       /* fflush(stdin) Eingabe Input Output*/
    scanf("%lf", &dSummandB);
    dSumme = dSummandA + dSummandB;               /* Formel fuer die Operation*/
    printf("\n\t\t\tDas Ergebnis lautet: %G + %G = %G\n\n",
    dSummandA, dSummandB, dSumme);                                                
    printf("\t\t\tweiter mit <Enter>");
    while(getch() != 0x0d);                         /* warte auf Eingabe Taste*/   
    return 0;
}

/*******************************************************************************
* SUBTRAKTION                                                                  *
*******************************************************************************/
int iSubtraktion()
{
    double dMinuend     = 0;
    double dSubtrahend  = 0;
    double dDifferenz   = 0;
    
    cls();
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tRechenoperation Subtraktion\t|\n");
    printf("\t\t+---------------------------------------+\n");
    
    printf("\n\t\t\tBitte Minuend eingeben: ");
    fflush(stdin);
    scanf("%lf", &dMinuend);      /* % dient als Platzhalter für eine Variable*/
    
    printf("\n\t\t\tBitte Subtrahend eingeben: ");      /* \n springe  in neue Zeile*/
    fflush(stdin);
    scanf("%lf", &dSubtrahend);/*& ist der Ambesand Operator fuer die Funktion*/

    dDifferenz = dMinuend - dSubtrahend;
    
    printf("\n\t\t\tDas Ergebnis lautet: %G - %G = %G\n\n",
    dMinuend, dSubtrahend, dDifferenz);
    
    printf("\t\t\tweiter mit <Enter>");                  /* \t setze Tabulator*/
    while(getch() != 0x0d);
    return 0;
}

/*******************************************************************************
* MULTIPLIKATION                                                               *
*******************************************************************************/
int iMultiplikation()
{
    double dFaktorA = 0;
    double dFaktorB = 0;
    double dProdukt = 0;
    
    cls();
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tRechenoperation Multiplikation\t|\n");
    printf("\t\t+---------------------------------------+\n");
    
    printf("\n\t\t\tBitte Faktor A eingeben: ");
    fflush(stdin);
    scanf("%lf", &dFaktorA);
    
    printf("\n\t\t\tBitte Faktor B eingeben: ");
    fflush(stdin);
    scanf("%lf", &dFaktorB);

    dProdukt = dFaktorA * dFaktorB;
    
    printf("\n\t\t\tDas Ergebnis lautet: %G * %G = %G\n\n",
    dFaktorA, dFaktorB, dProdukt);
    
    printf("\t\t\tweiter mit <Enter>");
    while(getch() != 0x0d);
    return 0;
}

/*******************************************************************************
* DIVISION                                                                     *
*******************************************************************************/
int iDivision()
{
    double dDividend = 0;
    double dDivisor  = 0;
    double dQuotient = 0;
    double dRest;
    
    cls();
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tRechenoperation Division\t|\n");
    printf("\t\t+---------------------------------------+\n");
    
    printf("\n\t\t\tBitte Dividenden eingeben: ");
    fflush(stdin);
    scanf("%lf", &dDividend);
    
    printf("\n\t\t\tBitte Divisor eingeben: ");
    fflush(stdin);
    scanf("%lf", &dDivisor);

    dQuotient = dDividend / dDivisor;
                                      /*Formel als Ersatz fuer Modulo Operator*/
    dRest = (dQuotient * dDivisor) - dDividend;
    
    printf("\n\t\t\tDas Ergebnis lautet: %G / %G = %G Rest:%.2G\n\n",
    dDividend, dDivisor, dQuotient, dRest);
    
    printf("\t\t\tweiter mit <Enter>");
    while(getch() != 0x0d);
    return 0;
}

/*******************************************************************************
* HILFE                                                                        *
*******************************************************************************/
int iHilfe()
{
    FILE                 *FPHilfe;                
    char            sZeichen[160];                        
    FPHilfe = fopen("Hilfe","r");
      
    cls();
    
    cls();
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tTaschenrechner Hilfeseite\t|\n");
    printf("\t\t+---------------------------------------+\n");
    
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
          printf("\t\tweiter mit <Enter>");      
         }while(getch() != 0x0d);
          return 0;
}


/*******************************************************************************
* HAUPTMENUE                                                                   *
*******************************************************************************/
int iMenue()
{
    int iAuswahl = 0;                         /* iAuswahl(); ist die Anweisung*/
    
  do
  {
    
    cls();
    printf("\n\n\t\t+-------------------------------+\n\t\t");
    printf("|   Taschenrechner Hauptmenue   |");
    printf("\n\t\t+-------------------------------+\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <1> Auswahl Grundrechenarten\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <2> Auswahl Mathematik\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <3> Auswahl Hilfe   \t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <4> Auswahl Ueber Mich\t|\n\t\t|\t\t\t\t|\n");    
    printf("\t\t| <0> Auswahl Beenden\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t+-------------------------------+\n");
    printf("\n\t\t  Bitte waehle eine Option: ");
    fflush(stdin);
    scanf("%i", &iAuswahl);  
    switch(iAuswahl)                         /* switch Anweisung für das Menue*/
    {
                    case 1:
                         {                           /* switch case Anweisung*/
                           printf("\n\t\t  Sie haben Rechenarten gewaehlt!");
                           Sleep(1000); 
                           iGrundrechenarten();                               
                           break;
                         }
                    
                    case 2:
                         {
                           printf("\n\t\t  Sie haben Mathematik gewaehlt!");
                           Sleep(1000);  
                           iMathematik();                   
                           break;
                         }
                    
                    case 3:
                         {
                           printf("\n\t\t  Sie haben die Hilfe gewaehlt!");
                           Sleep(1000); 
                           iHilfe();
                           break;
                         }
                         
                    case 4:
                         {
                           printf("\n\t\t  Ueber mich!");
                           Sleep(1000);  
                           iInfo();
                           break;
                         }
                    
                    case 0:
                         {
                           printf("\n\t\t  Bis Bald!");
                           Sleep(1000);  
                           exit(0);
                           break;
                         }
                    
                    default:       /* Standard Rückgabefunktion wenn definiert*/
                    {
                           printf("\n\t\t  Hoppla, Falsche Eingabe!");
                           sleep(1000);
                           break;
                    }                  
    }
   }while(iAuswahl);
    Sleep(1000);
    return 0;
}

/*******************************************************************************
* MENUE Grundrechenarten                                                       *
*******************************************************************************/
int iGrundrechenarten()
{
    int iAuswahl = 0;                         /* iAuswahl(); ist die Anweisung*/
    
  do
  {
    
    cls();
    printf("\n\n\t\t+-------------------------------+\n\t\t");
    printf("|     Grundrechenarten          |");
    printf("\n\t\t+-------------------------------+\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <1> Auswahl Addition\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <2> Auswahl Subtraktion\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <3> Auswahl Multiplikation\t|\n\t\t|\t\t\t\t|\n");    
    printf("\t\t| <4> Auswahl Division\t\t|\n\t\t|\t\t\t\t|\n");  
    printf("\t\t| <5> Auswahl Hauptmenue\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <0> Auswahl Beenden\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t+-------------------------------+\n");
    printf("\n\t\t  Bitte waehle eine Rechenart: ");
    fflush(stdin);
    scanf("%i", &iAuswahl);  
    switch(iAuswahl)                         /* switch Anweisung für das Menue*/
    {
                    case 1:
                         {                           /* switch case Anweisung*/
                           printf("\n\t\t  Sie haben die Addition gewaehlt!");
                           Sleep(1000); 
                           iAddition();                               
                           break;
                         }
                    
                    case 2:
                         {
                           printf("\n\t\t  Sie haben die Subtraktion gewaehlt!");
                           Sleep(1000);  
                           iSubtraktion();                   
                           break;
                         }
                    
                    case 3:
                         {
                           printf("\n\t\t");  
                           printf("  Sie haben die Multiplikation gewaehlt!");
                           Sleep(1000); 
                           iMultiplikation(); 
                           break;
                         }
                    
                    case 4:
                         {
                           printf("\n\t\t  Sie haben die Division gewaehlt!");
                           Sleep(1000);  
                           iDivision();                             
                           break;
                         }
                         
                    case 5:
                         {
                           printf("\n\t\t  Willkommen im Hauptmenue");
                           Sleep(1000);  
                           iMenue();
                           break;
                         }
                         
                    case 0:
                         {
                           printf("\n\t\t  Bis Bald!");
                           Sleep(1000);  
                           exit(0);
                           break;
                         }
                    
                    default:       /* Standard Rückgabefunktion wenn definiert*/
                    {
                           printf("\n\t\t  Hoppla, Falsche Eingabe!");
                           sleep(1000);
                           break;
                    }                  
    }
   }while(iAuswahl);
    Sleep(1000);
    return 0;
}

/*******************************************************************************
* Menue Erweiterte Mathematik                                                  *
*******************************************************************************/
int iMathematik()
{
    int iAuswahl = 0;                         /* iAuswahl(); ist die Anweisung*/
    
  do
  {
    
    cls();
    printf("\n\n\t\t+-------------------------------+\n\t\t");
    printf("|     Erweiterte Mathematik     |");
    printf("\n\t\t+-------------------------------+\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <1> Auswahl Prozentrechnung\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <2> Auswahl Potenzen\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <3> Auswahl Zinsrechnung\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <4> Auswahl Trigonometrie\t|\n\t\t|\t\t\t\t|\n");   
    printf("\t\t| <5> Auswahl Hauptmenue\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <0> Auswahl Beenden\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t+-------------------------------+\n");
    printf("\n\t\t  Bitte waehlen eine Funktion: ");
    fflush(stdin);
    scanf("%i", &iAuswahl);  
    switch(iAuswahl)                         /* switch Anweisung für das Menue*/
    {                
                    case 1:
                         {
                           printf("\n\t\t  Sie haben Prozente gewaehlt!");
                           Sleep(1000);  
                           iProzentrechnung();
                           break;
                         }
                    case 2:
                         {
                           printf("\n\t\t  Sie haben Potenzen gewaehlt!");
                           Sleep(1000); 
                           iPotenzen();                             
                           break;
                         }
                         
                    case 3:
                         {
                           printf("\n\t\t  Sie haben Zinsen gewaehlt!");
                           Sleep(1000); 
                           iZinsrechnung();                             
                           break;
                         }
                     
                    case  4:
                         {
                           printf("\n\t\t  Sie haben Trigonometrie gewaehlt!");
                           Sleep(1000); 
                           iFunktionen();                             
                           break;
                         }
                    
                         
                    case 5:
                         {
                           printf("\n\t\t  Willkommen im Hauptmenue!");
                           Sleep(1000);  
                           iMenue();
                           break;
                         }
                         
                    case 0:
                         {
                           printf("\n\t\t  Bis Bald!");
                           Sleep(1000);  
                           exit(0);
                           break;
                         }
                    
                    default:       /* Standard Rückgabefunktion wenn definiert*/
                    {
                           printf("\n\t\t  Hoppla, Falsche Eingabe!");
                           sleep(1000);
                           break;
                    }                  
    }
   }while(iAuswahl);
    Sleep(1000);
    return 0;
}


/*******************************************************************************
* STEUERFUNKTION                                                               *
*******************************************************************************/
int iController()                      /* iController() ist die Steuerfunktion*/
{
    system("color 1F");                       /* setze Systemfarbe für Konsole*/
    iMenue();                                  /* gibt iMenue Anweisung zurück*/
    return 0;
}

/*******************************************************************************
* HAUPTPROGRAMM                                                                *
*******************************************************************************/
int main()                                  /* main() ist die Programmfunktion*/
{                                             /* {} fasst einen Block zusammen*/
      iController();
      return 0;             /* return 0; springt zur letzten Anweisung zurueck*/
}

/*******************************************************************************
* ENDE                                                                         *
*******************************************************************************/
