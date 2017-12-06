/*******************************************************************************
* Programm : Taschenrechner                                                    *
* Autor    : Nico Anders                                                       *
* Version  : 0.1                                                               *
* Datum	   : 01.09.2010                                                        *
* Status   : in Arbeit                                                         *
*******************************************************************************/

/*******************************************************************************
* PRAEPROZESSOR                                                                *
*******************************************************************************/
#include <stdio.h>                                    /* Standard Input Output*/
#include <stdlib.h>                                         /* Standard Libary*/
#include <conio.h>                                     /* Console Input Output*/
#include <windows.h>                                     /* windows Bibliothek*/
#include <math.h>                       /* Bibliothek mathematische Funktionen*/
#define  pause() system("pause")                            /* definiere pause*/
#define  cls() system("cls")                 /* definiere cls() lösche Ausagbe*/

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
    printf("\n\t\t\tGebe Summand A ein: ");
    fflush(stdin);                        
    scanf("%lf", &dSummandA);                      /* scanf(); Eingabefunktion*/
    
    printf("\n\t\t\tGebe Summand B ein: ");                
    fflush(stdin);                       /* fflush(stdin) Eingabe Input Output*/
    scanf("%lf", &dSummandB);

    dSumme = dSummandA + dSummandB;               /* Formel fuer die Operation*/

    printf("\n\t\t\t%G + %G = %G\n\n", dSummandA, dSummandB, dSumme);
                                                      
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
    
    printf("\n\t\t\tGebe Minuend ein: ");
    fflush(stdin);
    scanf("%lf", &dMinuend);      /* % dient als Platzhalter für eine Variable*/
    
    printf("\n\t\t\tGebe Subtrahend ein: ");      /* \n springe  in neue Zeile*/
    fflush(stdin);
    scanf("%lf", &dSubtrahend);/*& ist der Ambesand Operator fuer die Funktion*/

    dDifferenz = dMinuend - dSubtrahend;
    
    printf("\n\t\t\t%G - %G = %G\n\n", dMinuend, dSubtrahend, dDifferenz);
    
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
    
    printf("\n\t\t\tGebe Faktor A ein: ");
    fflush(stdin);
    scanf("%lf", &dFaktorA);
    
    printf("\n\t\t\tGebe Faktor B ein: ");
    fflush(stdin);
    scanf("%lf", &dFaktorB);

    dProdukt = dFaktorA * dFaktorB;
    
    printf("\n\t\t\t%G * %G = %G\n\n", dFaktorA, dFaktorB, dProdukt);
    
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
    
    cls();
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tRechenoperation Division\t|\n");
    printf("\t\t+---------------------------------------+\n");
    
    printf("\n\t\t\tGebe Dividenden ein: ");
    fflush(stdin);
    scanf("%lf", &dDividend);
    
    printf("\n\t\t\tGebe Divisor ein: ");
    fflush(stdin);
    scanf("%lf", &dDivisor);

    dQuotient = dDividend / dDivisor;
    
    printf("\n\t\t\t%G / %G = %G\n\n", dDividend, dDivisor, dQuotient);
    
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
    FPHilfe = fopen("readme","r");
      
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
* MENUE                                                                        *
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
    printf("\t\t| <1> Auswahl Addition\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <2> Auswahl Subtraktion\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <3> Auswahl Multiplikation\t|\n\t\t|\t\t\t\t|\n");    
    printf("\t\t| <4> Auswahl Division\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <5> Auswahl Hilfe   \t\t|\n\t\t|\t\t\t\t|\n");    
    printf("\t\t| <0> Auswahl Beenden\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t+-------------------------------+\n");
    printf("\n\t\t  Bitte waehle eine Rechenart: ");
    fflush(stdin);
    scanf("%i", &iAuswahl);
    
    switch(iAuswahl)                         /* switch Anweisung für das Menue*/
    {
                    case 1:                           /* switch case Anweisung*/
                           printf("\n\t\t  Sie haben die Addition gewaehlt!");
                           Sleep(1000); 
                           iAddition();                               
                    break;
                    
                    case 2:
                           printf("\n\t\t  Sie haben die Subtraktion gewaehlt!");
                           Sleep(1000);  
                           iSubtraktion();                   
                    break;
                    
                    case 3:
                           printf("\n\t\t");  
                           printf("  Sie haben die Multiplikation gewaehlt!");
                           Sleep(1000); 
                           iMultiplikation(); 
                    break;
                    
                    case 4:
                           printf("\n\t\t  Sie haben die Division gewaehlt!");
                           Sleep(1000);  
                           iDivision();                             
                    break;
                    
                    case 5:
                           printf("\n\t\t  Sie haben die Hilfe gewaehlt!");
                           Sleep(1000); 
                           iHilfe();                             
                    break;
                    
                    case 0:
                           printf("\n\t\t  Bis Bald!");
                           Sleep(1000);  
                           exit(0);
                    break;
                    
                    default:       /* Standard Rückgabefunktion wenn definiert*/
                           printf("\n\t\t  Hoppla, Falsche Eingabe!");
                           sleep(1000);
                    break;
                    
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
