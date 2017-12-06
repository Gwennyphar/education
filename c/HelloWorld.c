/******************************************************************************/
/*                         HELLO WORLD                                        */
/******************************************************************************/
/*Programm : HelloWorld.c                                                     */
/*Autor    : Nico Anders                                                      */
/*Version  : 1.0                                                              */
/*Datum    : 01.09.2010                                                       */
/*Status   : Fertig                                                           */
/******************************************************************************/

/*******************************************************************************
* Praeprozessor                                                                *
*******************************************************************************/
/* #include ermoeglicht Praeprozessor in den Quellcode einzubinden            */
#include <stdio.h>               /* Headerdatei fuer Deklaration von printf() */
#include <stdlib.h>                /* Headerdatei fuer Defintion von return 0 */

/******************************************************************************/
/*Funktion : Hello World auf dem Bildschirm ausgeben                          */
/*Status   : vorgelegt                                                        */
/******************************************************************************/
int iHelloWorld()                            /* iHelloWorld ist die Anweisung */
{
    printf("\n\n\n\t*********************************\n\t*\t\t\t\t*\n");

    printf("\t*\tHello World,\t\t*\n\t*\t\t\t\t*\n");/* hier ersteinmal printf()
                                                        zur Bildschirmausgabe */   

    printf("\t*\tich gruesse dich!\t*\n\t*\t\t\t\t*\n");

    printf("\t*********************************\n\n");
    system("pause");                             /* Programm wartet solange, bis
                                                    ein Tastendruck erfolgt */
    return 0;
}

/*******************************************************************************
* Steuerfunktion                                                               *
*******************************************************************************/
int iController()                     
{                                   /* {} fasst einen Funktionsblock zusammen */
    system("color 1F");         /* Systembefehl "color" legt Systemfarbe fest */
    iHelloWorld();              /* hier wird die Anweisung iHelloWorld zum
                                   ausführen an die Steuerfunktion uebergeben */
    return 0;
}

/*******************************************************************************
* Hauptprogramm                                                                *
*******************************************************************************/
int main()
{
      iController();
      return 0;                   /* return 0; gibt bei erfoglreicher Ausführung
                                     den Rückgabewert 0 zurueckt */
}

/*******************************************************************************
* Programmende HelloWorld.c                                                    *
*******************************************************************************/
