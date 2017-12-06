/** Programm             : testszenario.c
  * Version              : 1.0 testing
  * Autor                : Nico Anders
  * Datum                : 16.12.2010
  * Status               : in Arbeit
  * fertige Funktionen   : Datensaetze werden gespeichert und ausgelesen
                           Zugriffszeiten mit time werden ermittelt
                           Hilfefunktion steht zur Verfügung
  * ToDO                 : Usability verfeinern, anhuebschen, kommentieren,
                           Datensaetze auf 80 Zeichen splitten oder in .txt
                           exportieren
                           Umlaute in ASCII aendern
                           Erstellte Datei loeschen
  */

/** Praeprozessor
  * Anweisungen
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>          /*Headerdatei fuer difftime() und clock()*/
  #include <conio.h>                        /*Haederdatei fuer getch()*/
  #include <windows.h>                      /*Headerdatei fuer sleep()*/
  #include <windef.h>
  #define  TITEL "Eine wunderbare Heiterkeit hat meine ganze Seele eingenommen, gleich den süßen Frühlingsmorgen, die ich mit ganzem Herzen genieße. Ich bin allein und freue mich"
  #define  ADRESSE "Name Vorname, Strasse, PLZ, Ort"
  #define  PRODUKT "Die Linux Box LB1 ist ein Embedded PC mit vorinstalliertem LINUX für den industriellen Einsatz, der ohne zeitraubende Software-Installationen sofort einsatzbereit ist. Das LINUX Betriebssystem und umfangreiche Netzwerkdienste wie Web- Server HTTP, SSH, FTP und Telnet sind bereits vorinstalliert. Die Linux Box arbeitet mit der 32 Bit CPU ETRAX 100LX der Firma Axis Communications, dem Marktführer im Bereich von Netzwerkkameras. Für eigene Softwareentwicklungen ist die LB1 die geeignete Plattform. Im Internet stehen dem Entwickler zahlreiche Dokumentationen so wie eine Mailingliste für dieser Plattform zur Verfügung."

/** Anzahl Datensaetze
  *
  */
  int iEingabe = 0;
  int i   = 0;

/** Funktion : Datensatz Produktinfo Binaer
  * Status   : in Arbeit
  * ToDO     : hier fuer genauere Zeitangabe Funktion time_t in clock() ersetzen
  */
  int iBenchmark()
  {
      FILE *FPCalc;
      FPCalc = fopen("logfile.csv","a");
      system("cls");
      printf("\n\t\t_______________________________________\n");
      printf("\n\t\t*              Benchmark              *");
      printf("\n\t\t______Nico_Anders_(c)_version_1.2______\n");
      printf("\n\t\t Wieviel Datens\x84tze m\x94 \bchten Sie testen?");
      printf("\n\t\t ");
      fflush(stdin);
      scanf("%i", &iEingabe);
      printf("\t\t Bitte haben Sie etwas Geduld\r");
      return 0;
  }

/** Funktion : Datensatz Produktinfo Binaer
  * Status   : in Arbeit
  * ToDO     : hier fuer genauere Zeitangabe Funktion time_t in clock() ersetzen
  */
  int iSchreibeUndLeseInfoBin()
  {
	  char String[625];         /*String zum Schreiben von 625 zeichen*/
	  char sBlock[625];            /*String zum Lesen von 625 Zeichen */
	  FILE *FPDatei;
	  FILE *FPCalc;
	  FPDatei = fopen("logfile.bin","wb"); /*"wb" zum Anlegen der logfile.bin*/
	  FPCalc = fopen("logfile.csv","a");
	  time_t tStartSchreibeBinary;/*Startwert fuer Schreibzugriff in Sekunden*/
	  time_t tEndeSchreibeBinary;/*Endwert fuer Schreibzugriff in Sekunden*/
	  time_t tStartLeseBinary;/*Startwert fuer Lesezugriff in Sekunden*/
	  time_t tEndeLeseBinary;   /*Endwert fuer Lesezugriff in Sekunden*/
	  double tDifferenzSchreibeBinary;/*Differenz fuer Schreibzugriff*/
	  double tDifferenzLeseBinary;/*Differenz fuer Lesezugriff*/
	  double dBinGroesse;/*zum ermitteln von Dateigroessen in Byte*/
  /** Binary Produktinfo
    * Schreiben
    */
    time(&tStartSchreibeBinary);/*zum starten von Messungen mit Funktion time*/
    for(i=1;i<=iEingabe;i++)
    {
		sprintf(String,"%s\n",PRODUKT);/*sprintf zum schreiben aus String Produkt*/
		fwrite(String,625,1,FPDatei);/*fwrite zum Schreiben in Datei logfile.bin*/
	}
	time(&tEndeSchreibeBinary);
	fclose(FPDatei);                   /*zum schließen der logfile.bin*/
      /*tEnde...,tStart... zum berechnen der Zugriffszeiten; Schreiben*/
    tDifferenzSchreibeBinary = difftime(tEndeSchreibeBinary,tStartSchreibeBinary);
                                          /*.2 fuer 2 Nachkommastellen*/
    fprintf(FPCalc,"%.2lf;",tDifferenzSchreibeBinary);
/** Binary Poduktinfo
  * Lesen
  */
      FPDatei = fopen("logfile.bin","rb");  /*"rb" fuer binaeres Lesen*/
      time(&tStartLeseBinary);
      for(i=1;i<=iEingabe;i++)
      {
		  fread(sBlock,625,1,FPDatei);  /*zum Lesen eines Datenarray in den Speicher*/
	  }
	  time(&tEndeLeseBinary);
          /*tEnde...,tStart... zum berechnen der Zugriffszeiten; Lesen*/
      tDifferenzLeseBinary = difftime(tEndeLeseBinary,tStartLeseBinary);
      fprintf(FPCalc,"%.2lf;",tDifferenzLeseBinary);
  /** Binary Produktinfo
    * Groesse
    */
    fseek(FPDatei,0,SEEK_END);/*zum neu setzen der Position eines Bezugspunkt*/
    dBinGroesse = ftell(FPDatei);/*zum ermitteln aktueller Position im Stream*/
    rewind(FPDatei);   /*zum setzen der Position an den Anfang im Stream*/
    fprintf(FPCalc,"%.2lf;",dBinGroesse);
    fclose(FPDatei);
    fclose(FPCalc);       /*fclose() zum schließen der logfile.csv*/
    return 0;
}

/** Funktion : Datensatz Produkt Klartext
  * Status   : in Arbeit
  * ToDO     : hier fuer genauere Zeitangabe Funktion time_t in clock() ersetzen
  */
  int iSchreibeUndLeseInfoTxt()
  {
	  char sBlock[625];
	  FILE *FPDatei;            /*FPDatei Filepointer fuer logfile.txt*/
	  FILE *FPCalc;              /*FPCalc Filepointer fuer logfile.csv*/
	  FPDatei = fopen("logfile.txt","w"); /*"w" zum Anlegen des Stream logfile.txt*/
	  FPCalc  = fopen("logfile.csv","a");
	  time_t tStartSchreibeText;
	  time_t tEndeSchreibeText;
	  time_t tStartLeseText;
	  time_t tEndeLeseText;
	  double tDifferenzSchreibeText/*hier double fuer Fließkommazahlen*/
	  double tDifferenzLeseText;
	  double dTxtGroesse;
  /** Text Produktinfo
    * Schreiben
    */
    time(&tStartSchreibeText);
    for(i=1;i<=iEingabe;i++)/*for() Zaehlerschleife fuer Durchlaeufe*/
    {
		fprintf(FPDatei,"%s\n",PRODUKT);/*PRODUKT; hier definert in Praeprozessor
									      Anweisung zur Uebergabe an fprintf*/
	}
	time(&tEndeSchreibeText);
	fclose(FPDatei);
	tDifferenzSchreibeText = difftime(tEndeSchreibeText,tStartSchreibeText);
                          /*; fuer Trennung zwischen Zellen in der logfile.csv*/
  fprintf(FPCalc,"\nProduktinfo;%i;%.2lf;",iEingabe,tDifferenzSchreibeText);
  
  /** Text Produktinfo
    * Lesen
   **/
  FPDatei = fopen("logfile.txt","r");
  time(&tStartLeseText);           /*Deklaration zum starten der Funktion time*/
  
  for(i=1;i<=iEingabe;i++)
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
int iSchreibeUndLeseAdresseBin()
{
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
  
  for(i=1;i<=iEingabe;i++)		 /*Variable i fuer Startwert 1*/
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
  
  for(i=1;i<=iEingabe;i++)/*iEingabe zur Uebergabe aus switch case*/
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
int iSchreibeUndLeseAdresseTxt()
{
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
  
  for(i=1;i<=iEingabe;i++)
  {
    fprintf(FPDatei,"%s\n",ADRESSE);
  }
  time(&tEndeSchreibeText);
  fclose(FPDatei);
  tDifferenzSchreibeText = difftime(tEndeSchreibeText,tStartSchreibeText);
         /*%i Platzhalter fuer iEingabe Uebergabe zum speichern in logfile.csv*/
  fprintf(FPCalc,"\nAdresse;%i;%.2lf;",iEingabe,tDifferenzSchreibeText);
  
  /** Text Adresse
    * Lesen
    */
  FPDatei = fopen("logfile.txt","r");
  time(&tStartLeseText);
  
  for(i=1;i<=iEingabe;i++)
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
int iSchreibeUndLeseBin()
{
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
  
  for(i=1;i<=iEingabe;i++)
  {                          
    sprintf(String,"%s\n",TITEL);
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
  
  for(i=1;i<=iEingabe;i++)  /*i++ inkrement fuer naechste Zahl*/
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
int iSchreibeUndLeseTxt()
{
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
  
  for(i=1;i<=iEingabe;i++)
  {
    fprintf(FPDatei,"%s\n",TITEL);
  }
  time(&tEndeSchreibeText);
  fclose(FPDatei);
  tDifferenzSchreibeText = difftime(tEndeSchreibeText,tStartSchreibeText);
                                 /*\nWunschtext; fuer Zuordnung in logfile.csv*/
  fprintf(FPCalc,"\nWunschtext;%i;%.2lf;",iEingabe,tDifferenzSchreibeText);
  
  /** Wunschtext
    * Lesen
    */
  FPDatei = fopen("logfile.txt","r");
  time(&tStartLeseText);
  
  for(i=1;i<=iEingabe;i++)
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
  * Status   : fertig
  * ToDO     :
  */
int iMenue()
{
  do
  {

          system("cls");              /*zum Ersetzen der aktuellen Bildschirmausgabe*/
          printf("\n\t\t_______________________________________\n");
          printf("\n\t\t*              Benchmark              *");
          printf("\n\t\t______Nico_Anders_(c)_version_1.2______\n");
          printf("\n\t\t* <A> Benchmark Starten               *");
          printf("\n\t\t__<Q>_Benchmark_Beenden________________\n");
          printf("\t\t\t\tAuswahl: ");
          switch(iEingabe = getch() )
    {
      case 'q':
           {
             exit(0);    /*case Anweisung als Ersatz fuer optionale Beendenfunktion*/
             printf("");
             break;                     /*break zum herausspringen aus case Anweisung*/
           }
  
/** Funktion : automatisches Schtreiben und Lesen aller Datensaetze
  * Status   : fertig
  * ToDO	 : 
  */
     case 'a':
          {
               iBenchmark();
               iSchreibeUndLeseTxt();
               iSchreibeUndLeseBin();
               iSchreibeUndLeseAdresseTxt();
               iSchreibeUndLeseAdresseBin();
               iSchreibeUndLeseInfoTxt();
               iSchreibeUndLeseInfoBin();
               printf("\t\t Test erfolgreich abgeschlossen\r");  
               sleep(1000);
               break;
          }
     }
  }while(iEingabe != '0');
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
