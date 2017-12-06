/**********************************************************************/
/*Programm	:	primzahlen.c										  */
/*Version	:	1.0													  */
/*Autor		:	Nico Anders											  */
/*Datum		:	16.09.2010											  */
/**********************************************************************/
																  
/**********************************************************************/
/*Funtkion	:	Praeprozessor										  */
/*Status	:	in Arbeit											  */
/**********************************************************************/
#include <stdio.h>
#include <unistd.h> 
/**********************************************************************/
/*Funtkion	:	Primzahl											  */
/*Status	:	in Arbeit											  */
/**********************************************************************/
int iIst_primzahl(int iZahl)
{
	int iTeiler=2;
	while (iTeiler*iTeiler <= iZahl)
	{
		if (iZahl % iTeiler == 0)
		return 0;/* Zahl ist keine Primzahl							  */
		iTeiler++;
	}
	return(1);/* Zahl ist eine Primzahl								  */
}
/**********************************************************************/
/*Funtkion	:	Zahl												  */
/*Status	:	in Arbeit											  */
/**********************************************************************/
int iZahl()
{
	int iZahl;
	int iEingabe;
	printf("\n\t\t*************************\n");
	printf("\t\t*\tPrimzahlen\t*");
	printf("\n\t\t*************************");
	printf("\n\t\tWieviel Primzahlen möchten Sie ausgeben? ");
	fflush(stdin);
	scanf("%i", &iEingabe);
	for (iZahl=1; iZahl <= iEingabe; iZahl++)
	{
		if (iIst_primzahl (iZahl))
		{
			printf("\t\t*\t%5d\t\t*\n", iZahl);
			usleep(100000);
		}
	}
	printf("\t\t*************************");
	printf("\n\t\t\tBeenden");
	getchar();
	return 0;
}
/**********************************************************************/
/*Funtkion	:	Steuerprogramm                                        */
/*Status	:	in Arbeit											  */
/**********************************************************************/
int iController()
{
	iZahl();
	return 0;
}
/**********************************************************************/
/*Funtkion	:	Main												  */
/*Status	:	in Arbeit											  */
/**********************************************************************/
int main()
{
	iController();
	return 0;
}
/**********************************************************************/
/*Funtkion	:	Ende											 	 */
/**********************************************************************/
