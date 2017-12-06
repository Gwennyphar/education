/******************************************************************************/
/*                         Quicky Eraser                                      */
/******************************************************************************/
/*Programm : Quicky Eraser                                                    */
/*Autor    : Nico Anders                                                      */
/*Version  : 1.0 stable                                                       */
/*Datum    : 14.09.2010                                                       */
/*Status   : Fertig                                                           */
/******************************************************************************/
/*FUNKTION :              PRAEZESSORANWEISUNG                                 */
/*STATUS   :              FERTIG                                              */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define  DATEI "log"
/******************************************************************************/
/*FUNKTION :              PROGRAMM                                            */
/*STATUS   :              FERTIG                                              */
/******************************************************************************/
int iEraser()
{
	int i;
	int j;
	FILE *FPStream;
	FPStream = fopen(DATEI, "a+");
	printf("\n\n\t\t***************************\n");
	printf("\t\t*  \tQuick Eraser\t  *\n");
	printf("\t\t***************************\n");
	printf("\n\t\t  Formatiere Laufwerk C:\\\n\n");
	for(i = 0; i <= 100; i++)
	{
		printf("\t\t  %d%% abgeschlossen\r", i);
		for( j = 0; j <= 1000000; j++ )
		{
			fprintf(FPStream, "%d%% abgeschlossen\n", j);
			fflush(stdout);
		}
	}
	fclose(FPStream);
	printf("\t\tLinux wurde erfolgreich installiert\r\n");
	getchar();
	return 0;
}
/******************************************************************************/
/*FUNKTION :              CONTROLLER                                          */
/*STATUS   :              FERTIG                                              */
/******************************************************************************/
int iController()
{
    iEraser();
    return 0;
}
/******************************************************************************/
/*FUNKTION :              MAIN                                                */
/*STATUS   :              IN ARBEIT                                           */
/******************************************************************************/
int main()
{
    iController();
    return 0;
}
/******************************************************************************/
/*                       END                                                  */
/******************************************************************************/
