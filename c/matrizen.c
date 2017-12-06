/******************************************************************************/
/*Programm	:	matrizen.c													  */
/*Version	:	1.0															  */
/*Autor		:	Nico Anders													  */
/*Datum		:	20.09.2010													  */
/******************************************************************************/

/******************************************************************************/
/*Praeprozessor																  */
/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
/******************************************************************************/
/*MAIN																		  */
/******************************************************************************/
int main(void)
{
	int md[2][3];
	int i, j;/*Array mit Werten initalisieren								  */
	md[0][0] = 1;
	md[0][1] = 2;
	md[0][2] = 3;
	md[1][0] = 4;
	md[1][1] = 5;
	md[1][2] = 6;/*Inhalt ausgeben											  */

	md[0][0] = (md[0][0]*md[0][0]+md[0][0]*md[0][1]+md[0][0]*md[0][2]); 
    md[0][1] = (md[0][1]*md[1][0]+md[0][1]*md[1][1]+md[0][1]*md[1][2]);  
    md[0][2] = (md[0][2]*md[2][0]+md[0][2]*md[2][1]+md[0][2]*md[2][2]);
    md[1][0] = (md[1][0]*md[1][0]+md[0][1]*md[1][1]+md[0][1]*md[1][2]);
    md[1][1] = (md[1][1]*md[0][1]+md[1][1]*md[1][1]+md[1][1]*md[2][1]);   
    md[1][2] = (md[1][2]*md[0][2]+md[1][2]*md[1][2]+md[1][1]*md[2][2]);
     
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
/*END																		  */
/******************************************************************************/
