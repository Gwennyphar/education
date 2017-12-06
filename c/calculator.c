/******************************************************************************/
/*Programm	:	Calculator													  */
/*Autor		:	Nico Anders													  */
/*Version	:	0.1	beta													  */
/*Datum		:	01.09.2010													  */
/*ToDo		:	Code ergaenzen,Funktionen erweitern,Coding Style,getch()	  */
/*Status	:	in Arbeit													  */
/******************************************************************************/

/******************************************************************************/
/*                        Praeprozessoranweisung                              */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define cls() system("pause") /*lösche Bildschirm                             */
/******************************************************************************/

/******************************************************************************/
/*Funktion : Funktion Addition                                                */
/*Status   : fertig                                                           */
/******************************************************************************/
double dAddition()
{
        double dSummand1 = 0;
        double dSummand2 = 0;
        double dSumme    = 0;
    
        cls();
        
        printf("\r\n\t\tIch bin die Funktion zum Addieren \r\n");/*n New Line */
        printf("\r\n\t\tGeben Sie hier den Summand 1 ein: ");
        fflush(stdin);/*stdin steht für die Tastatur als Standardeingabegeraet*/
        scanf("%lf", &dSummand1);
        printf("\r\n\t\tGeben Sie hier den Summand 2 ein: ");
        fflush(stdin);
        scanf("%lf", &dSummand2);
        dSumme = dSummand1 + dSummand2;/*linksrekursive Grammatik! Bedeutet:
                 eine Berechnung findet stets rechts vom = statt und das
                 Ergebnis wird an die links vom = stehende Variable uebergeben*/
     
        printf("\t\n\t\t %G + %G = %G\n\n", dSummand1, dSummand2, dSumme);
        return 0;
}
/******************************************************************************/
/*Funktion : Funktion Subtraktion                                             */
/*Status   : fertig                                                           */
/******************************************************************************/
double dSubtraktion()
{
        double dMinuend     = 0;
        double dSubtrahend  = 0;
        double dDifferenz   = 0;
        
            cls();
              
        printf("\r\n\t\tIch bin die Funktion zum Subtrahieren rechnen\r\n");
        printf("\r\n\t\tGeben Sie hier den Minuend ein: ");/*printf Ausgabe   */
        fflush(stdin);
        scanf("%lf", &dMinuend);
        printf("\r\n\t\tGeben Sie hier den Subtrahend ein: ");/*\t Tabulator  */
        fflush(stdin);
        scanf("%lf", &dSubtrahend);/*& liefert die Adresse einer Variable      */
        dDifferenz = dMinuend - dSubtrahend;
        
        printf("\t\n\t\t %G - %G = %G\n\n", dMinuend, dSubtrahend, dDifferenz);
        return 0;  
}
/******************************************************************************/
/*Funktion : Funktion Multiplikation                                          */
/*Status   : fertig                                                           */
/******************************************************************************/
double dMultiplikation()
{
        double dFaktor1  = 0;
        double dFaktor2  = 0;
        double dProdukt  = 0;
        
            cls();
        
        printf("\r\n\t\tIch bin die Funktion zum Multiplizieren\r\n");
        printf("\r\n\t\tGeben sie hier den Faktor 1 ein: ");
        fflush(stdin);
        scanf("%lf", &dFaktor1);/*%i Platzhalter für Ganze Zahlen              */
        printf("\r\n\t\tGeben Sie hier den Faktor 2 ein: ");
        fflush(stdin);
        scanf("%lf", &dFaktor2);
        dProdukt = dFaktor1 * dFaktor2;
        
        printf("\t\n\t\t %G * %G = %G\n\n", dFaktor1, dFaktor2, dProdukt);
        return 0;
}
/******************************************************************************/
/*Funktion : Funktion Division                                                */
/*Status   : fertig                                                           */
/******************************************************************************/

double dDivision()
{
        double dDivident = 0;
        double dDivisor  = 0;
        double dQuotient = 0;
    
            cls();
    
    printf("\r\n\t\tIch bin die Funktion zum Dividieren\r\n");
    printf("Geben sie hier den Divident ein: ");
    fflush(stdin);
    scanf("%lf", &dDivident);
    printf("Geben sie hier den Divisor ein: ");
    fflush(stdin);
    scanf("%lf", &dDivisor);
    dQuotient = dDivident / dDivisor;
    
    printf("\t\n\t\t %G / %G = %G\n\n", dDivident, dDivisor, dQuotient);
    return 0;
}
/******************************************************************************/
/*Funktion : Funktion Arrays                                                  */
/*Status   : fertig                                                           */
/******************************************************************************/
int iArrays(void)
{
	int md[2][3];
	int i, j;/*Array mit Werten initalisieren								  */
	md[0][0] = 1;
	md[0][1] = 2;
	md[0][2] = 3;
	md[1][0] = 4;
	md[1][1] = 5;
	md[1][2] = 6;/*Inhalt ausgeben											  */

     
	for(i=0; i < 2; i++)
	{
		for(j=0; j < 2; j++)
		{
			printf("[%d][%d] = %d\n", i, j, md[i][j]);
		}
	}
	return 0;
}
/******************************************************************************/
/*Funktion : Organisation der Menüauswahl						              */
/*Status   : fertig                                                           */
/******************************************************************************/
int iMenue()
{
/******************************************************************************/	
/*Variable definieren -> int fuer integer, also ganze Zahl             		  */
/*Variable deklarieren(bekannt machen)->Variablenname muss eindeutig sein	  */
/*Variable initalisieren -> Startwert der Variablen setzen					  */
/******************************************************************************/
int iAuswahl = 0; /*Startwert                                                 */
	
 do
 {
	 cls();
    
    printf("\t***********************************************************\r\n");
    printf("\t***             Taschenrechner-Programm                 ***\r\n");
    printf("\t***********************************************************\r\n");
    
    printf("\t+---------------------------------------------------------+\r\n");
    printf("\t|\t<1>     Addition\t\t\t\t  |\r\n");/* zum addieren			  */
    printf("\t|\t<2>     Subtraktion\t\t\t\t  |\r\n");/* zum subtrahieren	  */
    printf("\t|\t<3>     Multiplikation\t\t\t\t  |\r\n");/*zum mutliplizieren */
    printf("\t|\t<4>     Division\t\t\t\t  |\r\n");/*zum dividieren			  */
	printf("\t|\t<5>     Matrizen\t\t\t\t  |\r\n");/*Dimension berechnen	  */
    printf("\t|\t<0>     Beenden\t\t\t\t\t  |\r\n");/*zum beenden des Programm*/
    printf("\t+---------------------------------------------------------+\r\n");
    printf("\t\t\tBitte waehlen Sie eine Option: ");

    scanf("%i", &iAuswahl); /*Adressoprator & weil int elementarer Datentyp   */
    
    printf("\r\n\t\t Sie haben die %i ausgewaehlt \r\n", iAuswahl);


    switch(iAuswahl) /*schalte abhängig vom Wert in der Variablen iAuswahl    */
    {

                     case 1:/*case-Anweisung wird mit switch-Anweisung benutzt*/
                          {
                               dAddition();
                               break;/*breake verlässt eine switch-Anweisung  */
                               
                          }
                     case 2:
                          {    dSubtraktion();
                               break;
                               
                          }
                     case 3:
                          {    dMultiplikation();
                               break;
                               
                          }
                     case 4:
                          {    dDivision();
                               break;
                          }
                     case 5:
                          {    iArrays();
                               break;
                          }
                  
    }
   }while(iAuswahl);
    return 0;/*erzwingt einen Rückgabewert einer Funktion                     */
}
/******************************************************************************/
/*Funktion : Organistaion der Programmsteuerung                               */
/*Status   : in Arbeit                                                        */
/******************************************************************************/
int iController()
{
    iMenue();
    cls();
    return 0;
}
/******************************************************************************/
/*Funktion : main() Funktion                                                  */
/*Status   : in Arbeit                                                        */
/******************************************************************************/
int main()
{
	system("color 1F");
    iController();
    return 0;
}
/******************************************************************************/
/*									  END									  */
/******************************************************************************/
