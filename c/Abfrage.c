/*******************************************************************************
 Praeprozessor
*******************************************************************************/
#include	<stdio.h>
#include	<stdlib.h>
#define		WIDTH 160
/*******************************************************************************
 Funktion : Binaerdatei Schreiben
 Status   : in Arbeit
*******************************************************************************/
int iTextInput()
{
	int iZahl	= 0;
	FILE *FPFile;
	char sInput[160];			 		//zum speichern der 160 Zeichen im Array
	
	FPFile= fopen("logfile.txt", "w");
	
	for(iZahl = 1; iZahl <= 5; iZahl++)	
	{
		printf("%2d.Wunsch: ", iZahl);
		fflush(stdin);
		fgets(sInput, 160, stdin);	   //Ersatz fuer gets() zur Pufferbegrenzung
									//zum Schreiben 1x, 160 Zeichen in Textdatei
		fprintf(FPFile,"%2d.Wunsch: %s", iZahl, sInput);
														//schreibe Wert in Datei 
	}
	fclose(FPFile);
	return 0;
}

/*******************************************************************************
 Funktion : Binaerdatei Lesen
 Status   : in Arbeit
*******************************************************************************/
int iTextOutput()
{
	int iZahl	  = 0;
	FILE *FPFile;
	char sOutput[160];		          //[]zum speichern der 160 Zeichen im Array

	FPFile= fopen("logfile.txt", "r");
	
	for(iZahl = 1; iZahl <= 5; iZahl++)
	{								   //zum Lesen 1x, 160 Zeichen aus Textdatei
              fgets(sOutput, 160, FPFile);
              printf( "%s" , sOutput);
	}
	fclose(FPFile);
	return 0;
}

/*******************************************************************************
 Steuerfunktion
*******************************************************************************/
int iController()
{
	iTextInput();
	iTextOutput();
	return 0;
}

/*******************************************************************************
 Schnittstelle main()
*******************************************************************************/
int main()
{
	iController();
	return 0;
}