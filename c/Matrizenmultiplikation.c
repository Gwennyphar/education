/******************************************************************************/
/* Programmname : Matrizenmultiplikation                                      */
/* Autor        : Nico Anders                                                 */
/* Version      : 0.1                                                         */
/* Datum        : 11.09.2010                                                  */
/* Status       : in Arbeit                                                   */
/******************************************************************************/

/******************************************************************************/
/* Praeprozessor                                                              */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

/******************************************************************************/
/* Funktion : Eingabe Matrizen                                                */
/* Status   : in Arbeit                                                       */
/******************************************************************************/
int iMatrix[3][3];
int iMatA[3][3];
int iMatB[3][3];
int iMatC[3][3];

int iMatrizen_eingeben()
{
    int iFeld    = 0;
    int iZaehler = 0;
    
    for( iFeld = 0; iFeld < 3; iFeld++)
    {
         for( iZaehler = 0; iZaehler < 3; iZaehler++)
         {
              printf("\tFeld [%i][%i]: ", iFeld + 1, iZaehler + 1);
              scanf("%i", &iMatrix);
         }
    }
}

/******************************************************************************/
/* Funktion : Matrizenmultipliaktion                                          */
/* Status   : in Arbeit                                                       */
/******************************************************************************/
int iMatrizenmultiplikation()
{
    int iFeld    = 0;
    int iZaehler = 0;
    int iA       = 1;
    int iB       = 2;
    int iEingabe = 0;
    int iMatrix1[3][3];
    int iMatrix2[3][3];
    
    switch(iEingabe)
    {
      case 1:
           {
             for( iFeld = 0; iFeld < 3; iFeld++)
             {
               for( iZaehler = 0; iZaehler < 3; iZaehler++)
               {
                  iMatC[iZaehler][iFeld] = (iMatrix1[0][iFeld] * iMatrix2[iZaehler][0]);
                  iMatC[iZaehler][iFeld] = iMatC[iZaehler][iFeld] + iMatrix1[1][iFeld] * iMatrix2[iZaehler][1];
                  iMatC[iZaehler][iFeld] = iMatC[iZaehler][iFeld] + iMatrix1[2][iFeld] * iMatrix2[iZaehler][2];
               }
             }
             break;
           }
             
             case 2:
                  {
                     for( iFeld = 0; iFeld < 3; iFeld++)
                     {
                        for(iZaehler = 0; iZaehler < 3; iZaehler++)
                        {
                          iMatC[iFeld][iZaehler] = (iMatrix1[iFeld][0] * iMatrix2[0][iZaehler]);
                          iMatC[iFeld][iZaehler] = iMatC[iFeld][iZaehler] + iMatrix1[iFeld][1] * iMatrix2[1][iZaehler];
                          iMatC[iFeld][iZaehler] = iMatC[iFeld][iZaehler] + iMatrix1[iFeld][2] * iMatrix2[2][iZaehler];
                        }
                     }
                     break;
                  }
    }
}

/******************************************************************************/
/* Funktion : AUsgabe Matrix C                                                */
/* Status   : in Arbeit                                                       */
/******************************************************************************/
int iAusgabe()
{
    int iZaehler = 0;
    int iEingabe = 0;
    
    printf("\n\tEinlesen Matrix A\n\n");
    iMatrizen_eingeben(iMatA);
    printf("\n\tEinlesen Matrix B\n\n");
    iMatrizen_eingeben(iMatB);
    printf("%i",&iEingabe);
    printf("\n\tAusgabe Matrix C:\n\n");
    iMatrizenmultiplikation();
    
    for( iZaehler = 0; iZaehler < 3; iZaehler++)
    {
         printf("[%i]\t", iMatC[iZaehler][0]);
         printf("[%i]\t", iMatC[iZaehler][1]);
         printf("[%i]\t\n", iMatC[iZaehler][2]);
    }
    getch();
    return 0;
}

/******************************************************************************/
/* Steuerprogramm                                                             */
/******************************************************************************/
int iController()
{
    iAusgabe();
    return 0;
}

/******************************************************************************/
/* Programmschnittstelle                                                      */
/******************************************************************************/
int main()
{
    iController();
    return 0;
}          
                                                
    
    
    
