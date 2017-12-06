/******************************************************************************
 *	Programm     : performance-check.c									      *
 *	Autor		 : Nico Anders												  *
 *	Version		 : 0.1 beta												      *
 *	Erstelldatum : 02.12.2010												  *
 *	Status		 : in Arbeit												  *
 *	ToDo		 : anhuebschen, Usability									  * 
 ******************************************************************************/

/******************************************************************************
 *	Praeprozessor															  * 
 ******************************************************************************/
#include	<stdio.h>                                  /*standard Input Output*/
#include	<stdlib.h>                                       /*Standard Libary*/
#include	<time.h>                     /*Header fuer Zeit und Byteermittlung*/
#define     cls() system("cls") /*zum ersetzen der aktuellen Bildschirmausgabe*/
                            /*m Schreiben des Textes mit fwrite in logfile.bin*/
#define		INPUT "Wunsch: Ich bin ein Fliesstext\n"

/******************************************************************************
 *	Funktion : Klartext 1.000000 Datensaetze								  *
 *	Status   : in Arbeit										              * 
 ******************************************************************************/
int iText6()
{
	int iZahl		  = 0;
	FILE *FPFile;               /*FPFile Filepointer fuer logfile.txt und .bin*/
	FILE *FPData;                        /*FPData Filepointer fuer logfile.csv*/
	FILE *FPLogs;           /*FPLogs Filepointer zum Lesen aus logtemp.txt.bin*/ 
	char sTextOutput[160];
	
	time_t tStartST;       /*StartST Startwert fuer das Schreiben von Klartext*/
	time_t tEndeST;      /*EndeSt fuer Endwert fuer das Schreiben von klartext*/
	time_t tStartLT;        /*StartLT Startwert fuer die Lesezeit von Klartext*/
	time_t tEndeLT;           /*EndeLT Endewert fuer die Lesezeit von Klartext*/
	double tDiffST;/*DiffST Differenz fuer das Schreiben von Klartext in Datei*/
	double tDiffLT;   /*DiffLT Differenz fuer das Lesen von Klartext aus Datei*/  
	unsigned long int txt_groesse; /*Deklaration fuer die Dateigroesse in Byte*/
	
	FPFile= fopen("logfile.txt", "w+");  /*Filepointer zum anlegen logfile.txt*/
	FPData= fopen("logfile.csv", "a");/*Filepointer zum fortsetzen logfile.csv*/
    FPLogs= fopen("logtemp.txt", "a"); 
	
    time( &tStartST );                         /*hier Startwert für Zeitangabe*/
	for(iZahl = 1; iZahl <= 1000000; iZahl++)	
	{
                /*fprintf zum schreiben von festen Datensaetzen in logfile.txt*/
                               /*%2d zum schreiben einer Variable in Textdatei*/
		fprintf(FPFile,"%2d.Wunsch: Ich bin ein Fliesstext\n", iZahl); 
	}
	
    time( &tEndeST );                            /*hier Endwert für Zeitangabe*/
    
/******************************************************************************
 *	Datensatz Schreibezugriff    											  * 
 ******************************************************************************/
                                      /*fuer Differenz zwischen Start und Ende*/
    tDiffST = difftime(tEndeST, tStartST);
               /*mit fprintf zum Schreiben der Zeit in Sekunden in logfile.csv*/
    fprintf(FPData, "1.Schreibzugriff: %lf;\n", tDiffST);
    fprintf(FPLogs, "\t\t*1.Schreibzugriff: %lf;*\n", tDiffST);
	printf("\t\t*\tgespeichert in logfile.csv*\n");
	
/******************************************************************************
 *	Datensatz Lesezugriff        											  * 
 ******************************************************************************/	
	tDiffLT = difftime(tEndeLT, tStartLT);
    fprintf(FPData, "1.Lesezugriff: %lf;\n", tDiffST);
    fprintf(FPLogs, "\t\t*1.Lesezugriff: %lf;*\n", tDiffST);
	printf("\t\t*\tgespeichert in logfile.csv*\n");
	
/******************************************************************************
 *	Datensatz Groesse		            									  * 
 ******************************************************************************/
    rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    txt_groesse = ftell(FPFile);
            /*mit fprintf zum Scheiben der Dateigroesse in Byte in logfile.csv*/
    fprintf(FPData, "1.Groesse: %li Byte\n", txt_groesse);
    fprintf(FPLogs, "\t\t*1.Groesse: %li Byte*\n", txt_groesse);
   	fclose(FPFile);                      /*zum schließen der Datei logfile.txt*/
    fclose(FPData);                      /*zum schließen der Datei logfile.csv*/
    fclose(FPLogs);
    
/******************************************************************************
 *	Performance Ausgabe														  * 
 ******************************************************************************/	
	FPLogs= fopen("logtemp.txt", "r");   /*"r" zum Lesen aus Datei logfile.csv*/
                                     /*zum Lesen 1x, 160 Zeichen aus Textdatei*/
    fgets(sTextOutput, 160, FPFile);
    printf( "%s", sTextOutput);   /*zur Ausgabe auf Bildschirm aus logfile.csv*/
	fclose(FPLogs);             /*zum entfernen des Filepointer aus logtemp.txt*/
	
	return 0;
}

/******************************************************************************
 *	Funktion : Klartext 100.000 Datensaetze							     	  *
 *	Status   : in Arbeit										              * 
 ******************************************************************************/
int iText5()
{
	int iZahl		  = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sTextOutput[160];
	
	time_t tStartST;
	time_t tEndeST;
	time_t tStartLT;
	time_t tEndeLT;
	double tDiffST;
	double tDiffLT;
	unsigned long int txt_groesse;
	
	FPFile= fopen("logfile.txt", "w+");
	FPData= fopen("logfile.csv", "a");
	FPLogs= fopen("logtemp.txt", "a");
	
    time( &tStartST );
	for(iZahl = 1; iZahl <= 100000; iZahl++)	
	{
		fprintf(FPFile,"%2d.Wunsch: Ich bin ein Fliesstext\n", iZahl);
	}
    time( &tEndeST );
    
/******************************************************************************
 *	Datensatz Schreibezugriff    											  * 
 ******************************************************************************/
    tDiffST = difftime( tEndeST , tStartST );
    fprintf(FPData, "Klartext Datensatz 100.000: %lf;\n", tDiffST);
    fprintf(FPLogs, "\t\t*  Klartext 100.000: %lf;\n", tDiffST);
	printf("\t\t*\tgespeichert in logfile.csv*\n");

/******************************************************************************
 *	Datensatz Lesezugriff    			     								  * 
 ******************************************************************************/
	tDiffLT = difftime(tEndeLT, tStartLT);
    fprintf(FPData, "Lesezugriff 100.000: %lf;\n", tDiffLT);
    fprintf(FPLogs, "\t\t*Lesezugriff 100.000: %lf;*\n", tDiffLT);
	printf("\t\t*\tgespeichert in logfile.csv*\n");
	
/******************************************************************************
 *	Datensatz Groesse   		         									  * 
 ******************************************************************************/	
    rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    txt_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 100.000: %li Byte\n", txt_groesse);
    fprintf(FPLogs, "\t\t* Groesse Klartext 100.000: %li Byte*\n", txt_groesse);
   	fclose(FPFile);
    fclose(FPData);
    fclose(FPLogs);
    
/******************************************************************************
 *	Performance Ausgabe														  * 
 ******************************************************************************/	
	FPLogs= fopen("logtemp.txt", "r");
								   //zum Lesen 1x, 160 Zeichen aus Textdatei
    fgets(sTextOutput, 160, FPFile);
    printf( "%s" , sTextOutput);
	fclose(FPLogs);
	
	return 0;
}

/******************************************************************************
 *	Funktion : Klartext 10.000 Datensaetze	    							  *
 *	Status   : in Arbeit										              * 
 ******************************************************************************/
int iText4()
{
	int iZahl		  = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sTextOutput[160];
	
	time_t tStartST;
	time_t tEndeST;
	time_t tStartLT;
	time_t tEndeLT;
	double tDiffST;
	double tDiffLT;
	unsigned long int txt_groesse;
	
	FPFile= fopen("logfile.txt", "w+");
	FPData= fopen("logfile.csv", "a");
	FPLogs= fopen("logtemp.txt", "a");
	
    time( &tStartST );
	for(iZahl = 1; iZahl <= 10000; iZahl++)	
	{
		fprintf(FPFile,"%2d.Wunsch: Ich bin ein Fliesstext\n", iZahl);
	}
    time( &tEndeST );
 
/******************************************************************************
 *	Datensatz Schreibezugriff    											  * 
 ******************************************************************************/
    tDiffST = difftime( tEndeST , tStartST );
    fprintf(FPData, "Klartext Datensatz 10.000: %lf;\n", tDiffST);
    fprintf(FPLogs, "\t\t*  Klartext 10.000: %lf;\n", tDiffST);
	printf("\t\t*\tgespeichert in logfile.csv*\n");

/******************************************************************************
 *	Datensatz Lesezugriff    								    			  * 
 ******************************************************************************/	
	tDiffLT = difftime(tEndeLT, tStartLT);
    fprintf(FPData, "Lesezugriff 100.000: %lf;\n", tDiffLT);
    fprintf(FPLogs, "\t\t*Lesezugriff 100.000: %lf;*\n", tDiffLT);
	printf("\t\t*\tgespeichert in logfile.csv*\n")
	
/******************************************************************************
 *	Datensatz Groesse           											  * 
 ******************************************************************************/
    /*rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    txt_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 10.000: %li Byte\n", txt_groesse);
    fprintf(FPLogs, "\t\t*  Groesse Klartext 10.000: %li Byte*\n", txt_groesse);
   	fclose(FPFile);
    fclose(FPData);
    fclose(FPLogs);*/
    
/******************************************************************************
 *	Performance Ausgabe														  * 
 ******************************************************************************/	
	FPLogs= fopen("logtemp.txt", "r");
    fgets(sTextOutput, 160, FPFile);
    printf( "%s" , sTextOutput);
	fclose(FPLogs);
	return 0;
}

/******************************************************************************
 *	Funktion : Klartext 1.000 Datensaetze		     						  *
 *	Status   : in Arbeit										              * 
 ******************************************************************************/
int iText3()
{
	int iZahl		  = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sTextOutput[160];
	
	time_t tStartST;
	time_t tEndeST;
	time_t tStartLT;
	time_t tEndeLT;
	double tDiffST;
	double tDiffLT;
	unsigned long int txt_groesse;
	
	FPFile= fopen("logfile.txt", "w+");
	FPData= fopen("logfile.csv", "a");
	FPLogs= fopen("logtemp.txt", "a");
	
    time( &tStartST );
	for(iZahl = 1; iZahl <= 1000; iZahl++)	
	{
		fprintf(FPFile,"%2d.Wunsch: Ich bin ein Fliesstext\n", iZahl);
	}
    time( &tEndeST );
    
/******************************************************************************
 *	Datensatz Schreibezugriff    											  * 
 ******************************************************************************/
    tDiffST = difftime( tEndeST , tStartST );
    fprintf(FPData, "Klartext Datensatz 1.000: %lf;\n", tDiffST);
    fprintf(FPLogs, "\t\t*  Klartext 1.000: %lf;\n", tDiffST);
	printf("\t\t*\tgespeichert in logfile.csv*\n");

/******************************************************************************
 *	Datensatz Lesezugriff    										    	  * 
 ******************************************************************************/	
	tDiffLT = difftime(tEndeLT, tStartLT);
    fprintf(FPData, "Lesezugriff 100.000: %lf;\n", tDiffLT);
    fprintf(FPLogs, "\t\t*Lesezugriff 100.000: %lf;*\n", tDiffLT);
	printf("\t\t*\tgespeichert in logfile.csv*\n")
	
    rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    txt_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 1.000: %li Byte\n", txt_groesse);
    fprintf(FPLogs, "\t\t*  Groesse Klartext 1.000: %li Byte*\n", txt_groesse);
   	fclose(FPFile);
    fclose(FPData);
    fclose(FPLogs);
    
/******************************************************************************
 *	Performance Ausgabe														  * 
 ******************************************************************************/	
	FPLogs= fopen("logtemp.txt", "r");
    fgets(sTextOutput, 160, FPFile);
    printf( "%s" , sTextOutput);
	fclose(FPLogs);
	return 0;
}

/******************************************************************************
 *	Funktion : Klartext 100 Datensaetze				        				  *
 *	Klartext : in Arbeit										              * 
 ******************************************************************************/
int iText2()
{
	int iZahl		  = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sTextOutput[160];
	
	time_t tStartST;
	time_t tEndeST;
	time_t tStartLT;
	time_t tEndeLT;
	double tDiffST;
	double tDiffLT;
	unsigned long int txt_groesse;
	
	FPFile= fopen("logfile.txt", "w+");
	FPData= fopen("logfile.csv", "a");
	FPLogs= fopen("logtemp.txt", "a");
	
    time( &tStartST );
	for(iZahl = 1; iZahl <= 100; iZahl++)	
	{
		fprintf(FPFile,"%2d.Wunsch: Ich bin ein Fliesstext\n", iZahl);
	}
    time( &tEndeST );
    
/******************************************************************************
 *	Datensatz Schreibezugriff    											  * 
 ******************************************************************************/
    tDiffST = difftime( tEndeST , tStartST );
    fprintf(FPData, "Klartext Datensatz 100: %lf;\n", tDiffST);
    fprintf(FPLogs, "\t\t*  Klartext 100: %lf;\n", tDiffST);
	printf("\t\t*\tgespeichert in logfile.csv*\n");
	
/******************************************************************************
 *	Datensatz Lesezugriff    		     									  * 
 ******************************************************************************/	
	tDiffLT = difftime(tEndeLT, tStartLT);
    fprintf(FPData, "Lesezugriff 100.000: %lf;\n", tDiffLT);
    fprintf(FPLogs, "\t\t*Lesezugriff 100.000: %lf;*\n", tDiffLT);
	printf("\t\t*\tgespeichert in logfile.csv*\n")
	
/******************************************************************************
 *	Datensatz Groesse           											  * 
 ******************************************************************************/	
    rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    txt_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 100: %li Byte\n", txt_groesse);
    fprintf(FPLogs, "\t\t*  Groesse Klartext 100: %li Byte*\n", txt_groesse);
   	fclose(FPFile);
    fclose(FPData);
    fclose(FPLogs);
    
/******************************************************************************
 *	Performance Ausgabe														  * 
 ******************************************************************************/	
	FPLogs= fopen("logtemp.txt", "r");
    fgets(sTextOutput, 160, FPFile);
    printf( "%s" , sTextOutput);
	fclose(FPLogs);
	return 0;
}

/******************************************************************************
 *	Funktion : Klartext 10 Datensaetze		        						  *
 *	Klartext : in Arbeit										              * 
 ******************************************************************************/
int iText1()
{
	int iZahl		  = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sTextOutput[160];
	
	time_t tStartST;
	time_t tEndeST;
	time_t tStartLT;
	time_t tEndeLT;
	double tDiffST;
	double tDiffLT;
	unsigned long int txt_groesse;
	
	FPFile= fopen("logfile.txt", "w+");
	FPData= fopen("logfile.csv", "a");
	FPLogs= fopen("logtemp.txt", "a");
	
    time( &tStartST );
	for(iZahl = 1; iZahl <= 10; iZahl++)	
	{
		fprintf(FPFile,"%2d.Wunsch: Ich bin ein Fliesstext\n", iZahl);
	}
    time( &tEndeST );
    
/******************************************************************************
 *	Datensatz Schreibezugriff    											  * 
 ******************************************************************************/    
    tDiffST = difftime( tEndeST , tStartST );
    fprintf(FPData, "Klartext Datensatz 10: %lf;\n", tDiffST);
    fprintf(FPLogs, "\t\t*  Klartext 10: %lf;\n", tDiffST);
	printf("\t\t*\tgespeichert in logfile.csv*\n");
    rewind(FPFile);

/******************************************************************************
 *	Datensatz Lesezugriff       											  * 
 ******************************************************************************/    
   	tDiffLT = difftime(tEndeLT, tStartLT);
    fprintf(FPData, "Lesezugriff 10: %lf;\n", tDiffLT);
    fprintf(FPLogs, "\t\t*Lesezugriff 10: %lf;*\n", tDiffLT);
	printf("\t\t*\tgespeichert in logfile.csv*\n")
	
/******************************************************************************
 *	Datensatz Groesse           											  * 
 ******************************************************************************/
    rewind(FPFile);  
    fseek( FPFile, 0, SEEK_END);
    txt_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 10: %li Byte\n", txt_groesse);
    fprintf(FPLogs, "\t\t*  Groesse Klartext 10: %li Byte*\n", txt_groesse);
   	fclose(FPFile);
    fclose(FPData);
    fclose(FPLogs);
    
/******************************************************************************
 *	Performance Ausgabe														  * 
 ******************************************************************************/	
	FPLogs= fopen("logtemp.txt", "r");
    fgets(sTextOutput, 160, FPFile);
    printf( "%s" , sTextOutput);
	fclose(FPLogs);
	return 0;
}

/******************************************************************************
 *	Funktion : Binaertext 1.0000000 Datensaetze								  *
 *	Status   : in Arbeit			            							  *  
 ******************************************************************************/
int iBinary6()
{
    int iZahl           = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sBinaryOutput[160];
	
	time_t tStartSB;    /*tStartSB Startwert fuer das Schreiben von Binaertext*/
	time_t tEndeSB;        /*tEndeSB Endwert fuer das Schreiben von Binaertext*/
	time_t tStartLB;        /*tStartLB Startwert fuer das Lesen von Binaertext*/
	time_t tEndeLB;            /*tEndeLB Endwert fuer das Lesen von Binaertext*/
	double tDiffSB;      /*tDiffSB Differenz fuer das Schreiben von Binaertext*/
	double tDiffLB;          /*tDiffLB Differenz fuer das Lesen von Binaertext*/
	unsigned long int bin_groesse;
	
	FPFile= fopen("logfile.bin", "wb");
	FPData= fopen("logfile.csv", "ab");
	FPLogs= fopen("logtemp.bin", "ab");
	
	time(&tStartSB);
	for(iZahl = 1; iZahl <=1000000; iZahl++)
	{                           /*fwrite zum binaeren Schreiben in logfile.bin*/
	          fwrite(INPUT, 1, 160, FPFile);    /*INPUT zum speichern von Text*/
    }	          
    time( &tEndeSB );
    
/******************************************************************************
 *	Bin.Datensatz Schreibezugriff    										  * 
 ******************************************************************************/    
    tDiffSB = difftime( tEndeSB , tStartSB );
    fprintf(FPData, "Bin.text Datensatz 1.Mio: %lf;\n", tDiffSB);
    fprintf(FPLogs, "\t\t*Bin.text Datensatz 1.Mio: %lf;*\n", tDiffSB);
	printf("\t\t*\tgespeichert in logfile.csv*\n");

/******************************************************************************
 *	Bin.Datensatz Lesezugriffzugriff    									  * 
 ******************************************************************************/	
	tDiffLB = difftime(tEndeLB, tStartLB);
    fprintf(FPData, "Lesezugriff 100.000: %lf;\n", tDiffLB);
    fprintf(FPLogs, "\t\t*Lesezugriff 100.000: %lf;*\n", tDiffLB);
	printf("\t\t*\tgespeichert in logfile.csv*\n")

/******************************************************************************
 *	Bin.Datensatz Groesse   					    						  * 
 ******************************************************************************/	
    rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    bin_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 1.Mio.: %li Byte\n", bin_groesse);
    fprintf(FPLogs, "\t\t*Groesse Datensatz 1.Mio.: %li Byte*\n", bin_groesse);
    fclose(FPFile);
    fclose(FPData);
    fclose(FPLogs);
    
/******************************************************************************
 *	Bin.Performance Ausgabe													  * 
 ******************************************************************************/	
	FPLogs= fopen("logtemp.bin", "rb");
									 //zum Lesen 1x, 160 Zeichen aus Binaerdatei
	fread(sBinaryOutput, 1, 160, FPFile);
    printf("%s", sBinaryOutput);
    fclose(FPLogs);
	return 0;
}

/******************************************************************************
 *	Funktion : Binaertext 100.000 Datensaetze								  *
 *	Status   : in Arbeit			            							  *  
 ******************************************************************************/
int iBinary5()
{
    int iZahl           = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sBinaryOutput[160];
	
	time_t tStartSB;
	time_t tEndeSB;
	time_t tStartLB;
	time_t tEndeLB;
	double tDiffSB;
	double tDiffLB;
	unsigned long int bin_groesse;
	
	FPFile= fopen("logfile.bin", "wb");
	FPData= fopen("logfile.csv", "ab");
	FPLogs= fopen("logtemp.bin", "ab");
	
	time(&tStartSB);
	for(iZahl = 1; iZahl <=100000; iZahl++)
	{                                     //zum Schreiben 1x, 160 in Binaerdatei
	          fwrite(INPUT, 1, 160, FPFile);
    }          
    time( &tEndeSB );

/******************************************************************************
 *	Bin.Datensatz Schreibezugriff    										  * 
 ******************************************************************************/
    tDiffSB = difftime( tEndeSB , tStartSB );
    fprintf(FPData, "Bin.text Datensatz 100.000: %lf;\n", tDiffSB);
    fprintf(FPLogs, "\t\t*Bin.text Datensatz 100.000: %lf;*\n", tDiffSB);
	printf("\t\t*\tgespeichert in logfile.csv*\n");

/******************************************************************************
 *	Bin.Datensatz Lesezugriff    											  * 
 ******************************************************************************/	
	tDiffLB = difftime(tEndeLB, tStartLB);
    fprintf(FPData, "Lesezugriff 100.000: %lf;\n", tDiffLB);
    fprintf(FPLogs, "\t\t*Lesezugriff 100.000: %lf;*\n", tDiffLB);
	printf("\t\t*\tgespeichert in logfile.csv*\n")

/******************************************************************************
 *	Bin.Datensatz Groesse    				    							  * 
 ******************************************************************************/	
    /*rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    bin_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 100.000: %li Byte\n", bin_groesse);
    fprintf(FPLogs, "\t\t*Groesse Datensatz 100.000: %li Byte*\n", bin_groesse);
    fclose(FPFile);
    fclose(FPData);
    fclose(FPLogs);
    
/******************************************************************************
 *	Bin.Performance Ausgabe													  * 
 ******************************************************************************/	
	/*FPLogs= fopen("logtemp.bin", "rb");
									 //zum Lesen 1x, 160 Zeichen aus Binaerdatei
	fread(sBinaryOutput, 1, 160, FPFile);
    printf("%s", sBinaryOutput);
    fclose(FPLogs);
	return 0;
}*/

/******************************************************************************
 *	Funktion : Binaertext 10.000 Datensaetze								  *
 *	Status   : in Arbeit			            							  *  
 ******************************************************************************/
/*int iBinary4()
{
    int iZahl           = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sBinaryOutput[160];
	
	time_t tStartSB;
	time_t tEndeSB;
	time_t tStartLB;
	time_t tEndeLB;
	double tDiffSB;
	double tDiffLB;
	unsigned long int bin_groesse;
	
	FPFile= fopen("logfile.bin", "wb");
	FPData= fopen("logfile.csv", "ab");
	FPLogs= fopen("logtemp.bin", "ab");
	
	time(&tStartSB);
	for(iZahl = 1; iZahl <=10000; iZahl++)
	{                                     //zum Schreiben 1x, 160 in Binaerdatei
	          fwrite(INPUT, 1, 160, FPFile);
    }          
    time( &tEndeSB );*/
    
/******************************************************************************
 *	Bin.Datensatz Schreibezugriff    										  * 
 ******************************************************************************/
    /*tDiffSB = difftime( tEndeSB , tStartSB );
    fprintf(FPData, "Bin.text Datensatz 10.000: %lf;\n", tDiffSB);
    fprintf(FPLogs, "\t\t*Bin.text Datensatz 10.000: %lf;*\n", tDiffSB);
	printf("\t\t*\tgespeichert in logfile.csv*\n");*/

/******************************************************************************
 *	Bin.Datensatz Lesezugriff    											  * 
 ******************************************************************************/	
	tDiffLB = difftime(tEndeLB, tStartLB);
    fprintf(FPData, "Lesezugriff 10.000: %lf;\n", tDiffLB);
    fprintf(FPLogs, "\t\t*Lesezugriff 10.000: %lf;*\n", tDiffLB);
	printf("\t\t*\tgespeichert in logfile.csv*\n")

/******************************************************************************
 *	Bin.Datensatz Groesse           										  * 
 ******************************************************************************/	
    rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    bin_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 10.000: %li Byte\n", bin_groesse);
    fprintf(FPLogs, "\t\t*Groesse Datensatz 10.000: %li Byte*\n", bin_groesse);
    fclose(FPFile);
    fclose(FPData);
    fclose(FPLogs);
    
/******************************************************************************
 *	Bin.Performance Ausgabe													  * 
 ******************************************************************************/	
	FPLogs= fopen("logtemp.bin", "rb");
									 //zum Lesen 1x, 160 Zeichen aus Binaerdatei
	fread(sBinaryOutput, 1, 160, FPFile);
    printf("%s", sBinaryOutput);
    fclose(FPLogs);
	return 0;
}

/******************************************************************************
 *	Funktion : Binaertext 1.000 Datensaetze		    						  *
 *	Status   : in Arbeit			            							  *  
 ******************************************************************************/
int iBinary3()
{
    int iZahl           = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sBinaryOutput[160];
	
	time_t tStartSB;
	time_t tEndeSB;
	time_t tStartLB;
	time_t tEndeLB;
	double tDiffSB;
	double tDiffLB;
	unsigned long int bin_groesse;
	
	FPFile= fopen("logfile.bin", "wb");
	FPData= fopen("logfile.csv", "ab");
	FPLogs= fopen("logtemp.bin", "ab");
	
	time(&tStartSB);
	for(iZahl = 1; iZahl <=1000; iZahl++)
	{                                     //zum Schreiben 1x, 160 in Binaerdatei
	          fwrite(INPUT, 1, 160, FPFile);
    }          
    time( &tEndeSB );
    
 /******************************************************************************
 *	Bin.Datensatz Schreibezugriff    										  * 
 ******************************************************************************/
    tDiffSB = difftime( tEndeSB , tStartSB );
    fprintf(FPData, "Bin.text Datensatz 1.000: %lf;\n", tDiffSB);
    fprintf(FPLogs, "\t\t*Bin.text Datensatz 1.000: %lf;*\n", tDiffSB);
	printf("\t\t*\tgespeichert in logfile.csv*\n");

/******************************************************************************
 *	Bin.Datensatz Lesezugriff    	    									  * 
 ******************************************************************************/	
	tDiffLB = difftime(tEndeLB, tStartLB);
    fprintf(FPData, "Lesezugriff 1.000: %lf;\n", tDiffLB);
    fprintf(FPLogs, "\t\t*Lesezugriff 1.000: %lf;*\n", tDiffLB);
	printf("\t\t*\tgespeichert in logfile.csv*\n")

/******************************************************************************
 *	Bin.Datensatz Groesse           										  * 
 ******************************************************************************/	
    rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    bin_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 1.000: %li Byte\n", bin_groesse);
    fprintf(FPLogs, "\t\t*Groesse Datensatz 1.000: %li Byte*\n", bin_groesse);
    fclose(FPFile);
    fclose(FPData);
    fclose(FPLogs);
/******************************************************************************
 *	Bin.Performance Ausgabe													  * 
 ******************************************************************************/	
	FPLogs= fopen("logtemp.bin", "rb");
	fread(sBinaryOutput, 1, 160, FPFile);
    printf("%s", sBinaryOutput);
    fclose(FPLogs);
	return 0;
}

/******************************************************************************
 *	Funktion : Binaertext 100 Datensaetze	    							  *
 *	Status   : in Arbeit			            							  *  
 ******************************************************************************/
int iBinary2()
{
    int iZahl           = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sBinaryOutput[160];
	
	time_t tStartSB;
	time_t tEndeSB;
	time_t tStartLB;
	time_t tEndeLB;
	double tDiffSB;
	double tDiffLB;
	unsigned long int bin_groesse;
	
	FPFile= fopen("logfile.bin", "wb");
	FPData= fopen("logfile.csv", "ab");
	FPLogs= fopen("logtemp.bin", "ab");
	
	time(&tStartSB);
	for(iZahl = 1; iZahl <=100; iZahl++)
	{
	          fwrite(INPUT, 1, 160, FPFile);
    }          
    time( &tEndeSB );
    
/******************************************************************************
 *	Bin.Datensatz Schreibezugriff    										  * 
 ******************************************************************************/   
    tDiffSB = difftime( tEndeSB , tStartSB );
    fprintf(FPData, "Bin.text Datensatz 100.000: %lf;\n", tDiffSB);
    fprintf(FPLogs, "\t\t*Bin.text Datensatz 100.000: %lf;*\n", tDiffSB);
	printf("\t\t*\tgespeichert in logfile.csv*\n");

/******************************************************************************
 *	Bin.Datensatz Lesezugriff    		    								  * 
 ******************************************************************************/	
	tDiffLB = difftime(tEndeLB, tStartLB);
    fprintf(FPData, "Lesezugriff 100: %lf;\n", tDiffLB);
    fprintf(FPLogs, "\t\t*Lesezugriff 100: %lf;*\n", tDiffLB);
	printf("\t\t*\tgespeichert in logfile.csv*\n")
	
/******************************************************************************
 *	Bin.Datensatz Groesse           										  * 
 ******************************************************************************/	
    rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    bin_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 100: %li Byte\n", bin_groesse);
    fprintf(FPLogs, "\t\t*Groesse Datensatz 100: %li Byte*\n", bin_groesse);
    fclose(FPFile);
    fclose(FPData);
    fclose(FPLogs);
    
/******************************************************************************
 *	Bin.Performance Ausgabe													  * 
 ******************************************************************************/	
	FPLogs= fopen("logtemp.bin", "rb");
	fread(sBinaryOutput, 1, 160, FPFile);
    printf("%s", sBinaryOutput);
    fclose(FPLogs);
	return 0;
}

/******************************************************************************
 *	Funktion : Binaertext 10 Datensaetze		    						  *
 *	Status   : in Arbeit			            							  *  
 ******************************************************************************/
int iBinary1()
{
    int iZahl           = 0;
	FILE *FPFile;
	FILE *FPData;
	FILE *FPLogs;
	char sBinaryOutput[160];
	
	time_t tStartSB;
	time_t tEndeSB;
	time_t tStartLB;
	time_t tEndeLB;
	double tDiffSB;
	double tDiffLB;
	unsigned long int bin_groesse;
	
	FPFile= fopen("logfile.bin", "wb");
	FPData= fopen("logfile.csv", "ab");
    FPLogs= fopen("logtemp.txt", "a");
	
	time(&tStartSB);
	for(iZahl = 1; iZahl <=10; iZahl++)
	{                                     //zum Schreiben 1x, 160 in Binaerdatei
	          fwrite(INPUT, 1, 160, FPFile);
    }         
    time( &tEndeSB );
    
/******************************************************************************
 *	Bin.Datensatz Schreibezugriff    										  * 
 ******************************************************************************/   
    tDiffSB = difftime( tEndeSB , tStartSB );
    fprintf(FPData, "Bin.text Datensatz 10: %lf;\n", tDiffSB);
    fprintf(FPLogs, "\t\tBin.text Datensatz 10; %lf;\n", tDiffSB);
	printf("\t\t*\tgespeichert in logfile.csv*\n");

/******************************************************************************
 *	Bin.Datensatz Lesezugriff    			     							  * 
 ******************************************************************************/	
	tDiffLB = difftime(tEndeLB, tStartLB);
    fprintf(FPData, "Lesezugriff 10: %lf;\n", tDiffLB);
    fprintf(FPLogs, "\t\t*Lesezugriff 10: %lf;*\n", tDiffLB);
	printf("\t\t*\tgespeichert in logfile.csv*\n")

/******************************************************************************
 *	Bin.Datensatz Groesse           										  * 
 ******************************************************************************/	
    /*rewind(FPFile);
    fseek( FPFile, 0, SEEK_END);
    bin_groesse = ftell(FPFile);
    fprintf(FPData, "Groesse Datensatz 10: %li Byte\n", bin_groesse);
    fprintf(FPLogs, "\t\tGroesse Datensatz 10: %li Byte\n", bin_groesse);
    fclose(FPFile);
    fclose(FPData);

/******************************************************************************
 *	Bin.Performance Ausgabe													  * 
 ******************************************************************************/	
	/*FPLogs= fopen("logtemp.txt", "r");
	fread(sBinaryOutput, 1, 160, FPFile);
    printf("%s", sBinaryOutput);
    fclose(FPLogs);
	return 0;
}

/******************************************************************************
 *	Funktion : Hauptmenue													  *
 *	Status   : in Arbeit													  *  
 ******************************************************************************/
/*int iMenue()
{
    
	int iWahl = 0;
	printf("\t\t***********************************\n");
	printf("\t\t*  \tPerformance-Checker\t  *\n");
	printf("\t\t***********************************\n");
	printf("\t\t*  \t<1> Klartext              *\n");
	printf("\t\t*  \t<2> Bin.text              *\n");
	printf("\t\t***********************************\n");
	printf("\t\t*\tAuswahl: ");
	scanf("%d", &iWahl);
	printf("\t\t*\tSie haben die %d gewaehlt  *\n", iWahl);
	printf("\t\t***********************************\n");
	
		switch(iWahl)    /*switch-case Anweisung zum Auswählen der Menuepunkte*/
		/*{
			case 1:
				{ 
					iTextMenue();
					break;
				}
		 
			case 2:
				{ 
					iBinaryMenue();
					break;
				}
		}
        return 0;}*/

/******************************************************************************
 *	Funktion : Text Menue													  *
 *	Status   : in Arbeit													  *  
 ******************************************************************************/
int iTextMenue()
{
    cls();
    
	int iWahl = 0;
	printf("\t\t***********************************\n");
	printf("\t\t*  \tPerformance-Checker\t  *\n");
	printf("\t\t***********************************\n");
	printf("\t\t*  \t<1>       10 Datensaetze  *\n");
	printf("\t\t*  \t<2>      100 Datensaetze  *\n");
	printf("\t\t*  \t<3>    1.000 Datensaetze  *\n");
	printf("\t\t*  \t<4>   10.000 Datensaetze  *\n");
	printf("\t\t*  \t<5>  100.000 Datensaetze  *\n");
	printf("\t\t*  \t<6> 1.000000 Datensaetze  *\n");
	printf("\t\t***********************************\n");
	printf("\t\t*\tAuswahl: ");
	scanf("%d", &iWahl);
	printf("\t\t*\tSie haben die %d gewaehlt  *\n", iWahl);
	printf("\t\t***********************************\n");
	
		switch(iWahl)
		{
			case 1:
				{ 
					iText1();
					break;
				}
		 
			case 2:
				{ 
					iText2();
					break;
				}
		    case 3:
				{ 
					iText3();
					break;
				}
		 
			case 4:
				{ 
					iText4();
					break;
				}
			case 5:
				{ 
					iText5();
					break;
				}
		 
			case 6:
				{ 
					iText6();
					break;
				}				
		}
    	printf("\t\t*  \tweiter geht's mit <ENTER> *\n");
   		printf("\t\t***********************************");
        return 0;
}

/******************************************************************************
 *	Funktion : Binaer Menue													  *
 *	Status   : in Arbeit													  *  
 ******************************************************************************/
int iBinaryMenue()
{
    cls();
    
	int iWahl = 0;
	printf("\t\t***********************************\n");
	printf("\t\t*  \tPerformance-Checker\t  *\n");
	printf("\t\t***********************************\n");
	printf("\t\t*  \t<1>       10 Datensaetze  *\n");
	printf("\t\t*  \t<2>      100 Datensaetze  *\n");
	printf("\t\t*  \t<3>    1.000 Datensaetze  *\n");
	printf("\t\t*  \t<4>   10.000 Datensaetze  *\n");
	printf("\t\t*  \t<5>  100.000 Datensaetze  *\n");
	printf("\t\t*  \t<6> 1.000000 Datensaetze  *\n");
	printf("\t\t***********************************\n");
	printf("\t\t*\tAuswahl: ");
	scanf("%d", &iWahl);
	printf("\t\t*\tSie haben die %d gewaehlt  *\n", iWahl);
	printf("\t\t***********************************\n");
	
		switch(iWahl)
		{
            case 1:
				{ 
					iBinary1();
					break;
				}
		 
			case 2:
				{ 
					iBinary2();
					break;
				}
		    case 3:
				{ 
					iBinary3();
					break;
				}
		 
			case 4:
				{ 
					iBinary4();
					break;
				}
			case 5:
				{ 
					iBinary5();
					break;
				}
		 
			case 6:
				{ 
					iBinary6();
					break;
				}	
		}
    	printf("\t\t*  \tweiter geht's mit <ENTER> *\n");
   		printf("\t\t***********************************");
	    return 0;
}

/******************************************************************************
 *	Steuerfunktion															  * 
 ******************************************************************************/
int iController()
{
	//iMenue();
	return 0;
}

/******************************************************************************
 *	Schnittstelle main() 													  * 
 ******************************************************************************/
int main()
{
	iController();
	return 0;
}
/******************************************************************************
 *	Ende															   		  * 
 ******************************************************************************/
