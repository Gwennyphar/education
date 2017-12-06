/** Programm             : testszenario.c
  * Version              : 0.1 alpha
  * Autor                : Nico Anders
  * Datum                : 03.12.2010
  * Status               : in Arbeit
  * fertige Funktionen   : Datensaetze werden gespeichert und ausgelesen
                           Zugriffszeiten mit time werden ermittelt
                           Hilfefunktion steht zur Verfügung
  * ToDO                 : Usability verfeinern, anhuebschen, kommentieren,
                           Datensaetze auf 80 Zeichen splitten oder in .txt
                           exportieren
                           Umlaute in ASCII aendern
  */

/** Praeprozessor
  * Anweisungen
  */
#include  <stdio.h>
#include  <stdlib.h>
#include  <time.h>                   /*Headerdatei fuer difftime() und clock()*/
#include  <conio.h>                                 /*Haederdatei fuer getch()*/
#define   TEXT    "Eine wunderbare Heiterkeit hat meine ganze Seele eingenommen, gleich den süßen Frühlingsmorgen, die ich mit ganzem Herzen genieße. Ich bin allein und freue mich"
#define   ADRESSE "Name Vorname, Strasse, PLZ, Ort"
#define   PRODUKT "Die Linux Box LB1 ist ein Embedded PC mit vorinstalliertem LINUX für den industriellen Einsatz, der ohne zeitraubende Software-Installationen sofort einsatzbereit ist. Das LINUX Betriebssystem und umfangreiche Netzwerkdienste wie Web- Server HTTP, SSH, FTP und Telnet sind bereits vorinstalliert. Die Linux Box arbeitet mit der 32 Bit CPU ETRAX 100LX der Firma Axis Communications, dem Marktführer im Bereich von Netzwerkkameras. Für eigene Softwareentwicklungen ist die LB1 die geeignete Plattform. Im Internet stehen dem Entwickler zahlreiche Dokumentationen so wie eine Mailingliste für dieser Plattform zur Verfügung."

/** Funktion : Testszenario Hilfe
  * Status   : in Arbeit
  * ToDO     : getch() hier in Zeile 35, ASCII fuer Einngabetatse definieren
  */

int iHilfe()
{
	FILE *FPDatei;                               /*Filepointer fuer readme.txt*/
	char sHilfe[1000];
	
	FPFile= fopen("readme.txt", "r");/*"r" Stream readme.txt zum Lesen oeffnen*/
	fread(sHilfe, 1000, 1, FPDatei);
	printf("%s", sHilfe);
	fclose(FPDatei);                   /*fclose() zum schließen der readme.txt*/
	printf("\t\t\t\tHilfe beenden <Enter>");
	getch();                       /*zum Zurückkehren ins Hauptmenue mit Taste*/
	return 0;
}
    
/** Funktion : Datensatz Produktinfo Binaer
  * Status   : in Arbeit
  * ToDO     : hier fuer genauere Zeitangabe Funktion time_t in clock() ersetzen
  */
int iSchreibeUndLeseInfoBin(int iZaehler)
{
  int iWert   = 0;
  char String[625];                     /*String zum Schreiben von 625 zeichen*/
  char sBlock[625];                        /*String zum Lesen von 625 Zeichen */
  FILE *FPDatei;
  FILE *FPCalc;
  
  FPDatei = fopen("logfile.bin","wb");      /*"wb" zum Anlegen der logfile.bin*/
  FPCalc = fopen("logfile.csv","a");        

  time_t tStartSchreibeBinary;     /*Startwert fuer Schreibzugriff in Sekunden*/
  time_t tEndeSchreibeBinary;        /*Endwert fuer Schreibzugriff in Sekunden*/
  time_t tStartLeseBinary;            /*Startwert fuer Lesezugriff in Sekunden*/
  time_t tEndeLeseBinary;               /*Endwert fuer Lesezugriff in Sekunden*/
  double tDifferenzSchreibeBinary;             /*Differenz fuer Schreibzugriff*/
  double tDifferenzLeseBinary; 					  /*Differenz fuer Lesezugriff*/
  double dBinGroesse;                /*zum ermitteln von Dateigroessen in Byte*/
  
  /** Binary Produktinfo
    * Schreiben
   **/
  time(&tStartSchreibeBinary);   /*zum starten von Messungen mit Funktion time*/
  
  for(iWert=1;iWert<=iZaehler;iWert++)
  {
    sprintf(String,"%s\n",PRODUKT); /*sprintf zum schreiben aus String Produkt*/
    fwrite(String,625,1,FPDatei);  /*fwrite zum Schreiben in Datei logfile.bin*/
  }
  time(&tEndeSchreibeBinary);
  fclose(FPDatei);                             /*zum schließen der logfile.bin*/
  
              /*tEnde...,tStart... zum berechnen der Zugriffszeiten; Schreiben*/
  tDifferenzSchreibeBinary = difftime(tEndeSchreibeBinary,tStartSchreibeBinary);
                                                  /*.2 fuer 2 Nachkommastellen*/
  fprintf(FPCalc,"%.2lf;",tDifferenzSchreibeBinary);
  
  /** Binary Poduktinfo
    * Lesen
   **/
  FPDatei = fopen("logfile.bin","rb");              /*"rb" fuer binaeres Lesen*/
  time(&tStartLeseBinary);
  
  for(iWert=1;iWert<=iZaehler;iWert++)
  {
    fread(sBlock,625,1,FPDatei);  /*zum Lesen eines Datenarray in den Speicher*/
  }
  time(&tEndeLeseBinary);
  
                  /*tEnde...,tStart... zum berechnen der Zugriffszeiten; Lesen*/
  tDifferenzLeseBinary = difftime(tEndeLeseBinary,tStartLeseBinary);
  fprintf(FPCalc,"%.2lf;",tDifferenzLeseBinary);
  
  /** Binary Produktinfo
    * Groesse
   **/ 
  fseek(FPDatei,0,SEEK_END);   /*zum neu setzen der Position eines Bezugspunkt*/
  dBinGroesse = ftell(FPDatei);   /*zum ermitteln aktueller Position im Stream*/
  rewind(FPDatei);           /*zum setzen der Position an den Anfang im Stream*/
  fprintf(FPCalc,"%.2lf;",dBinGroesse);
  fclose(FPDatei);
  fclose(FPCalc);                     /*fclose() zum schließen der logfile.csv*/
  return 0;
}

/** Funktion : Datensatz Produkt Klartext
  * Status   : in Arbeit
  * ToDO     : hier fuer genauere Zeitangabe Funktion time_t in clock() ersetzen
  */
int iSchreibeUndLeseInfoTxt(int iZaehler)
{
  int iWert    = 0;
  char sBlock[625];
  FILE *FPDatei;                        /*FPDatei Filepointer fuer logfile.txt*/
  FILE *FPCalc;                          /*FPCalc Filepointer fuer logfile.csv*/
  
  FPDatei = fopen("logfile.txt","w"); /*"w" zum Anlegen des Stream logfile.txt*/
  FPCalc  = fopen("logfile.csv","a");

  time_t tStartSchreibeText;
  time_t tEndeSchreibeText;			 
  time_t tStartLeseText;
  time_t tEndeLeseText;
  double tDifferenzSchreibeText;           /*hier double fuer Fließkommazahlen*/
  double tDifferenzLeseText;
  double dTxtGroesse;
	
  /** Text Produktinfo
    * Schreiben
   **/
  time(&tStartSchreibeText);
  
  for(iWert=1;iWert<=iZaehler;iWert++)/*for() Zaehlerschleife fuer Durchlaeufe*/
  {
    fprintf(FPDatei,"%s\n",PRODUKT);/*PRODUKT; hier definert in Praeprozessor
									  Anweisung zur Uebergabe an fprintf*/
  }
  time(&tEndeSchreibeText);
  fclose(FPDatei);
  tDifferenzSchreibeText = difftime(tEndeSchreibeText,tStartSchreibeText);
                          /*; fuer Trennung zwischen Zellen in der logfile.csv*/
  fprintf(FPCalc,"\nProduktinfo;%i;%.2lf;",iZaehler,tDifferenzSchreibeText);
  
  /** Text Produktinfo
    * Lesen
   **/
  FPDatei = fopen("logfile.txt","r");
  time(&tStartLeseText);           /*Deklaration zum starten der Funktion time*/
  
  for(iWert=1;iWert<=iZaehler;iWert++)
  {
    fgets(sBlock,625,FPDatei); /*fgets fuer ein Zeichen vom übergebenen Stream*/
  }
  time(&tEndeLeseText);            /*Deklaration zum beenden der Funktion time*/
  tDifferenzLeseText = difftime(tEndeLeseText,tStartLeseText);
  fprintf(FPCalc,"%.2lf;",tDifferenzLeseText);

  /** Text Produktinfo
    * Groesse
   **/
  fseek(FPDatei,0,SEEK_END);
  dTxtGroesse = ftell(FPDatei);
  rewind(FPDatei);
  fprintf(FPCalc,"%.2lf;",dTxtGroesse);
  fclose(FPDatei);
  fclose(FPCalc);
  return 0;
}

/** Funktion : Datensatz Adresse Binaer
  * Status   : in Arbeit
  * ToDO     : hier fuer genauere Zeitangabe Funktion time_t in clock() ersetzen
  */
int iSchreibeUndLeseAdresseBin(int iZaehler)
{
  int iWert   = 0;
  char String[31];                          
  char sBlock[31];
  FILE *FPDatei;                   /*FPDatei hier Filepointer fuer logfile.bin*/
  FILE *FPCalc;
  
  FPDatei = fopen("logfile.bin","wb");     
  FPCalc = fopen("logfile.csv","a");      /*"a"zum Anfuegen in der logfile.csv*/       

  time_t tStartSchreibeBinary;     
  time_t tEndeSchreibeBinary;        
  time_t tStartLeseBinary;            
  time_t tEndeLeseBinary;               
  double tDifferenzSchreibeBinary;              
  double tDifferenzLeseBinary;
  double dBinGroesse;
  
  /** Binary Adresse
    * Schreiben
   **/
  time(&tStartSchreibeBinary);   
  
  for(iWert=1;iWert<=iZaehler;iWert++)		 /*Variable iWert fuer Startwert 1*/
  {                          
    sprintf(String,"%s\n",ADRESSE);               /*%s Platzhalter fuer String*/
    fwrite(String,31,1,FPDatei);
  }
  time(&tEndeSchreibeBinary);
  fclose(FPDatei);
  tDifferenzSchreibeBinary = difftime(tEndeSchreibeBinary,tStartSchreibeBinary);
  fprintf(FPCalc,"%.2lf;",tDifferenzSchreibeBinary);
  
  /** Binary Adresse
    * Lesen
   **/
  FPDatei = fopen("logfile.bin","rb");
  time(&tStartLeseBinary);
  
  for(iWert=1;iWert<=iZaehler;iWert++)/*iZaehler zur Uebergabe aus switch case*/
  {
    fread(sBlock,31,1,FPDatei);
  }
  time(&tEndeLeseBinary);
  tDifferenzLeseBinary = difftime(tEndeLeseBinary,tStartLeseBinary);
  fprintf(FPCalc,"%.2lf;",tDifferenzLeseBinary);
  
  /** Binary Adresse
    * Groesse
   **/ 
  fseek(FPDatei,0,SEEK_END);
  dBinGroesse = ftell(FPDatei);
  rewind(FPDatei);
  fprintf(FPCalc,"%.2lf;",dBinGroesse);/*fprintf zum Schreiben der Byte in csv*/
  fclose(FPDatei);
  fclose(FPCalc);
  return 0;
}

/** Funktion : Datensatz Adresse Klartext
  * Status   : in Arbeit
  * ToDO     : hier fuer genauere Zeitangabe Funktion time_t in clock() ersetzen
  */
int iSchreibeUndLeseAdresseTxt(int iZaehler)
{
  int iWert   = 0;
  char sBlock[31];
  FILE *FPDatei;
  FILE *FPCalc;
  
  FPDatei = fopen("logfile.txt","w");
  FPCalc  = fopen("logfile.csv","a");

  time_t tStartSchreibeText;
  time_t tEndeSchreibeText;
  time_t tStartLeseText;
  time_t tEndeLeseText;
  double tDifferenzSchreibeText;
  double tDifferenzLeseText;
  double dTxtGroesse;
	
  /** Text Adresse
    * Schreiben
    */
  time(&tStartSchreibeText);
  
  for(iWert=1;iWert<=iZaehler;iWert++)
  {
    fprintf(FPDatei,"%s\n",ADRESSE);
  }
  time(&tEndeSchreibeText);
  fclose(FPDatei);
  tDifferenzSchreibeText = difftime(tEndeSchreibeText,tStartSchreibeText);
         /*%i Platzhalter fuer iZaehler Uebergabe zum speichern in logfile.csv*/
  fprintf(FPCalc,"\nAdresse;%i;%.2lf;",iZaehler,tDifferenzSchreibeText);
  
  /** Text Adresse
    * Lesen
    */
  FPDatei = fopen("logfile.txt","r");
  time(&tStartLeseText);
  
  for(iWert=1;iWert<=iZaehler;iWert++)
  {
    fgets(sBlock,31,FPDatei);
  }
  time(&tEndeLeseText);
  tDifferenzLeseText = difftime(tEndeLeseText,tStartLeseText);
  fprintf(FPCalc,"%.2lf;",tDifferenzLeseText);

  /** Text Adresse
    * Groesse
    */
  fseek(FPDatei,0,SEEK_END);
  dTxtGroesse = ftell(FPDatei);
  rewind(FPDatei);
  fprintf(FPCalc,"%.2lf;",dTxtGroesse);
  fclose(FPDatei);
  fclose(FPCalc);
  return 0;
}

/** Funktion : Datensatz Wunschtext Binaer
  * Status   : in Arbeit
  * ToDO     : hier fuer genauere Zeitangabe Funktion time_t in clock() ersetzen
  */
int iSchreibeUndLeseBin(int iZaehler)
{
  int iWert   = 0;
  char String[160];                         
  char sBlock[160];
  FILE *FPDatei;
  FILE *FPCalc;
  
  FPDatei = fopen("logfile.bin","wb");     
  FPCalc = fopen("logfile.csv","a");

  time_t tStartSchreibeBinary;     
  time_t tEndeSchreibeBinary;        
  time_t tStartLeseBinary;            
  time_t tEndeLeseBinary;               
  double tDifferenzSchreibeBinary;              
  double tDifferenzLeseBinary;
  double dBinGroesse;
  
  /** Binary Wunschtext
    * Schreiben
    */
  time(&tStartSchreibeBinary);   
  
  for(iWert=1;iWert<=iZaehler;iWert++)
  {                          
    sprintf(String,"%s\n",TEXT);
    fwrite(String,160,1,FPDatei);
  }
  time(&tEndeSchreibeBinary);
  fclose(FPDatei);
  tDifferenzSchreibeBinary = difftime(tEndeSchreibeBinary,tStartSchreibeBinary);
  fprintf(FPCalc,"%.2lf;",tDifferenzSchreibeBinary);
  
  /** Binary Wunschtext
    * Lesen
    */
  FPDatei = fopen("logfile.bin","rb");   
  time(&tStartLeseBinary);
  
  for(iWert=1;iWert<=iZaehler;iWert++)  /*iWert++ inkrement fuer naechste Zahl*/
  {
    fread(sBlock,160,1,FPDatei);  /*zum Lesen von 160 Zeichen aus einem Stream*/
  }
  time(&tEndeLeseBinary);
  tDifferenzLeseBinary = difftime(tEndeLeseBinary,tStartLeseBinary);
  fprintf(FPCalc,"%.2lf;",tDifferenzLeseBinary);
  
  /** Binary Wunschtext
    * Groesse
    */
  fseek(FPDatei,0,SEEK_END);
  dBinGroesse = ftell(FPDatei);
  rewind(FPDatei);
  fprintf(FPCalc,"%.2lf;",dBinGroesse);
  fclose(FPDatei);
  fclose(FPCalc);
  return 0;
}

/** Funktion : Datensatz Wunschtext Klarext
  * Status   : in Arbeit
  * ToDO     : hier fuer genauere Zeitangabe Funktion time_t in clock() ersetzen
  */
int iSchreibeUndLeseTxt(int iZaehler)
{
  int iWert   = 0;
  char sBlock[160];
  FILE *FPDatei;
  FILE *FPCalc;
  
  FPDatei = fopen("logfile.txt","w");
  FPCalc  = fopen("logfile.csv","a");

  time_t tStartSchreibeText;
  time_t tEndeSchreibeText;
  time_t tStartLeseText;
  time_t tEndeLeseText;
  double tDifferenzSchreibeText;
  double tDifferenzLeseText;
  double dTxtGroesse;
	
  /** Wunschtext
    * Schreiben
    */
  time(&tStartSchreibeText);
  
  for(iWert=1;iWert<=iZaehler;iWert++)
  {
    fprintf(FPDatei,"%s\n",TEXT);
  }
  time(&tEndeSchreibeText);
  fclose(FPDatei);
  tDifferenzSchreibeText = difftime(tEndeSchreibeText,tStartSchreibeText);
                                 /*\nWunschtext; fuer Zuordnung in logfile.csv*/
  fprintf(FPCalc,"\nWunschtext;%i;%.2lf;",iZaehler,tDifferenzSchreibeText);
  
  /** Wunschtext
    * Lesen
    */
  FPDatei = fopen("logfile.txt","r");
  time(&tStartLeseText);
  
  for(iWert=1;iWert<=iZaehler;iWert++)
  {
    fgets(sBlock,160,FPDatei);
  }
  time(&tEndeLeseText);
  tDifferenzLeseText = difftime(tEndeLeseText,tStartLeseText);
  fprintf(FPCalc,"%.2lf;",tDifferenzLeseText);

  /** Wunschtext
    * Groesse
    */
  fseek(FPDatei,0,SEEK_END);
  dTxtGroesse = ftell(FPDatei);
  rewind(FPDatei);
  fprintf(FPCalc,"%.2lf;",dTxtGroesse);  /*fprintf fuer formatiertes Schreiben*/
  fclose(FPDatei);
  fclose(FPCalc);
  return 0;
}

/** Funktion : Hauptmenue
  * Status   : in Arbeit
  * ToDO     : in Zeile 452 "schließen" Umlaut ß in ASCII aendern
  */
int iMenue()
{
  int iWahl = 0;             /*Deklarierte Variable fuer switch-case Anweisung*/
  do
  {
    system("cls");              /*zum Ersetzen der aktuellen Bildschirmausgabe*/
    
    printf("\n\t\t***************************************\n");
    printf("\t\t*         Performance-Tester          *\n");
    printf("\t\t***************************************\n");
    printf("\t\t*                             \t      *\n");
    printf("\t\t* <1>         1 Datensaetze schreiben *\n");
    printf("\t\t* <2>        10 Datensaetze schreiben *\n");
    printf("\t\t* <3>       100 Datensaetze schreiben *\n");
    printf("\t\t* <4>     1.000 Datensaetze schreiben *\n");
    printf("\t\t* <5>    10.000 Datensaetze schreiben *\n");
    printf("\t\t* <6>   100.000 Datensaetze schreiben *\n");
    printf("\t\t* <7> 1.000.000 Datensaetze schreiben *\n");
    printf("\t\t* <8> >>>>>>>>> Automatisch schreiben *\n");
    printf("\t\t* <9> >>>>>>>>> Information anzeigen  *\n");
    printf("\t\t* <0> >>>>>>>>> Testprozess schließen *\n");
    printf("\t\t*                             \t      *\n");
    printf("\t\t***************************************\n");
    printf("\t\t\t\tAuswahl: ");
    scanf("%i",&iWahl);
    printf("\t\t***************************************\n");
    printf("\t\t*\t\tSchreibe %i. Datensatz *\n", iWahl);
    printf("\t\t***************************************\n");
    
    switch(iWahl)
    {
      case 0:
        exit(0);    /*case Anweisung als Ersatz fuer optionale Beendenfunktion*/
        printf("");
      break;                     /*break zum herausspringen aus case Anweisung*/
      
      case 1:
        iSchreibeUndLeseTxt(1);           /*(1) Uebergabewert fuer int iZahler*/
        iSchreibeUndLeseBin(1);
        iSchreibeUndLeseAdresseTxt(1);
        iSchreibeUndLeseAdresseBin(1);
        iSchreibeUndLeseInfoTxt(1);
        iSchreibeUndLeseInfoBin(1);
      break;
      
      case 2:
        iSchreibeUndLeseTxt(10);
        iSchreibeUndLeseBin(10);
        iSchreibeUndLeseAdresseTxt(10);
        iSchreibeUndLeseAdresseBin(10);
        iSchreibeUndLeseInfoTxt(10);
        iSchreibeUndLeseInfoBin(10);

      break;
      
      case 3:
        iSchreibeUndLeseTxt(100);
        iSchreibeUndLeseBin(100);
        iSchreibeUndLeseAdresseTxt(100);
        iSchreibeUndLeseAdresseBin(100);
        iSchreibeUndLeseInfoTxt(100);
        iSchreibeUndLeseInfoBin(100);

      break;
      
      case 4:
        iSchreibeUndLeseTxt(1000);
        iSchreibeUndLeseBin(1000);
        iSchreibeUndLeseAdresseTxt(1000);
        iSchreibeUndLeseAdresseBin(1000);
        iSchreibeUndLeseInfoTxt(1000);
        iSchreibeUndLeseInfoBin(1000);

      break;
      
      case 5:
        iSchreibeUndLeseTxt(10000);
        iSchreibeUndLeseBin(10000);
        iSchreibeUndLeseAdresseTxt(10000);
        iSchreibeUndLeseAdresseBin(10000);
        iSchreibeUndLeseInfoTxt(10000);
        iSchreibeUndLeseInfoBin(10000);

      break;
      
      case 6:
        iSchreibeUndLeseTxt(100000);
        iSchreibeUndLeseBin(100000);
        iSchreibeUndLeseAdresseTxt(100000);
        iSchreibeUndLeseAdresseBin(100000);
        iSchreibeUndLeseInfoTxt(100000);
        iSchreibeUndLeseInfoBin(100000);

      break;
      
      case 7:
        iSchreibeUndLeseTxt(1000000);
        iSchreibeUndLeseBin(1000000);
        iSchreibeUndLeseAdresseTxt(1000000);
        iSchreibeUndLeseAdresseBin(1000000);
        iSchreibeUndLeseInfoTxt(1000000);
        iSchreibeUndLeseInfoBin(1000000);
     break;
     
/** Funktion : automatisches Schtreiben und Lesen aller Datensaetze
  * Status   : in Arbeit
  * ToDO	 : 
  */
     case 8:
        iSchreibeUndLeseTxt(1);
        iSchreibeUndLeseBin(1);
        iSchreibeUndLeseAdresseTxt(1);
        iSchreibeUndLeseAdresseBin(1);
        iSchreibeUndLeseInfoTxt(1);
        iSchreibeUndLeseInfoBin(1);
        
        iSchreibeUndLeseTxt(10);
        iSchreibeUndLeseBin(10);
        iSchreibeUndLeseAdresseTxt(10);
        iSchreibeUndLeseAdresseBin(10);
        iSchreibeUndLeseInfoTxt(10);
        iSchreibeUndLeseInfoBin(10);
        
        iSchreibeUndLeseTxt(100);
        iSchreibeUndLeseBin(100);
        iSchreibeUndLeseAdresseTxt(100);
        iSchreibeUndLeseAdresseBin(100);
        iSchreibeUndLeseInfoTxt(100);
        iSchreibeUndLeseInfoBin(100);
        
        iSchreibeUndLeseTxt(1000);
        iSchreibeUndLeseBin(1000);
        iSchreibeUndLeseAdresseTxt(100);
        iSchreibeUndLeseAdresseBin(1000);
        iSchreibeUndLeseInfoTxt(1000);
        iSchreibeUndLeseInfoBin(1000);
        
        iSchreibeUndLeseTxt(10000);
        iSchreibeUndLeseBin(10000);
        iSchreibeUndLeseAdresseTxt(10000);
        iSchreibeUndLeseAdresseBin(10000);
        iSchreibeUndLeseInfoTxt(10000);
        iSchreibeUndLeseInfoBin(10000);
        
        iSchreibeUndLeseTxt(100000);
        iSchreibeUndLeseBin(100000);
        iSchreibeUndLeseAdresseTxt(100000);
        iSchreibeUndLeseAdresseBin(100000);
        iSchreibeUndLeseInfoTxt(100000);
        iSchreibeUndLeseInfoBin(100000);
        
        iSchreibeUndLeseTxt(1000000);
        iSchreibeUndLeseBin(1000000);
        iSchreibeUndLeseAdresseTxt(1000000);
        iSchreibeUndLeseAdresseBin(1000000);
        iSchreibeUndLeseInfoTxt(1000000);
        iSchreibeUndLeseInfoBin(1000000);    
     break;
     
     
     case 9:
        iHilfe();                            /*case Anweisung fuer Hilfeoption*/
      break;
    }
  }while(iWahl > 0 );
  system("pause");                   /*warte hier auf beliebigen Eingabebefehl*/
  return 0;
}

/** Steuerfunktion
  * Navigation durch die Funktionen
  */
int iController()
{
  iMenue();
  return 0;
}
/** Schnittstelle
  * main()
  */
int main()
{
  iController();
  return 0;
}
/** Ende
  * testszenario.c
  */
