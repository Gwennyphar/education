/******************************************************************************/
/* Programmname : Matrizen                                                    */
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
#include <unistd.h>
/******************************************************************************/
/* Funktion : Ausgabe Matrizen                                                */
/* Status   : in Arbeit                                                       */
/******************************************************************************/
int iMatrizen()
{
 	int iMatrix[10][10];
	int iSpalte = 0;
	int iZeile  = 0;
	
	for( iSpalte = 0; iSpalte < 10; iSpalte++ )
	{
	 	for( iZeile = 0; iZeile < 10; iZeile++ )
		{
		 	iMatrix[iSpalte][iZeile] = iSpalte * 10 + iZeile + 1;
	 	}
	}
	for( iSpalte = 0; iSpalte < 10; iSpalte++ )
	{
	 	for( iZeile = 0; iZeile < 10; iZeile++ )
		 {
		  	printf("%3d \x07", iMatrix[iSpalte][iZeile]);
		  	usleep(100000);
		 }
		 printf("\n");
	}
	getchar();
	return 0;
}

/******************************************************************************/
/* Steuerprogramm                                                             */
/******************************************************************************/
int iController()
{
 	system("color CA");
 	iMatrizen();
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
