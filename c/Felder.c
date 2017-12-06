#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

/* Typ FLoat; Strings angelegt mit Anfangswert*/

int iSchleifen()
{
    int iZaehler             = 0;
    float fArgument[10]      = {0.0};                           /* 10 x-Werte */
    float fFunktionswert[10] = {0.0};                           /* 10 y-Werte */
    
    srand(time(NULL) );   /* startet Zufallsgenerator mit aktuellem Timerwert */
    
    /* Arguemntevektor mit Startwerten fuellen und ausgeben */
    for( iZaehler = 0; iZaehler < 10; iZaehler++ ) /*iZaehler auf naechsten Index setzen*/
    {
     fArgument[iZaehler]      = rand() ;
     fFunktionswert[iZaehler] = fArgument[iZaehler] * 3.0;
     
     printf("fFunktionswert[%i] = Argument von [%i] * 3.00 ", iZaehler, iZaehler);
     printf("%5.2f = %5.2f * 3.00 \n", fFunktionswert[iZaehler], fArgument[iZaehler]);
    }
    printf("\n");
    printf("x Werte \t| y Werte\n\n");
    for( iZaehler = 0; iZaehler < 10; iZaehler++ )
    {
       printf("%5.2f\t|%5.2f\n", fArgument[iZaehler], fFunktionswert[iZaehler]);
    }
    
    fflush(stdin);
    getch();
}
         

int iController()
{
    iSchleifen();
    return 0;
}

int main()
{
    iController();
    return 0;
}
