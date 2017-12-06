/** Programm        : Taschenrechner
  * Autor           : Nico Anders                                                
  * Version         : 2.5 stable                                                
  * Datum           : 01.09.2010                                                
  * aktueller Stand : 10.05.2011                                                 
  * Status          : in Arbeit                                                  
  * ToDo            : Modulo % Operator verbessern                               
  *		            : \x81 \x84 \x94 \x8E \x99 \x9A \xE1");//ü ä ö Ä Ö Ü ß       
  *		            : \b loesche letzten Buchstaben
  */

/** PRAEPROZESSOR                                                               
  */
  #include <stdio.h>                                  /* Standard Input Output*/
  #include <stdlib.h>                                       /* Standard Libary*/
  #include <conio.h>                                   /* Console Input Output*/
  #include <windows.h>                                   /* windows Bibliothek*/
  #include <math.h>                     /* Bibliothek mathematische Funktionen*/
  #define  cls() system("cls")               /* definiere cls() lösche Ausagbe*/
  #define AUTOR   "Nico Anders"
  #define VERSION "2.5 stable"
  #define DATUM   "09.05.2011"
  #define PATENT  "2010-2012"
  #define PI 3.1415f  

/** Funktion : switch-case Ja Nein Funktion  
  * Status   : Fertig                                               
  */
  int iJaNein()
  {
 	switch( getch() )
 	{
		case 'j':
			 return 1;
	    break;
		case 'y':
			 return 1;	 
	    break;
	    case 'n':
			 return 0;
	    break;
	    default:
			iJaNein();	
		break;
    }
  }

/** Funktion : Flaechen berechnen
  * Status   : in Arbeit                        
  */
  int iPI()
  {
      float fDurchmesser = 0;
      float fFlaeche     = 0;
      float fUmfang      = 0;
      cls();
      printf("\n\n\t\t+---------------------------------------+\n\t\t");
      printf("|\tFl\x84 \bchenberechnung\t\t|\n");
      printf("\t\t+---------------------------------------+\n");
	  printf("\n\t\t\tBitte Durchmesser eingeben: ");
      fflush(stdin);
      scanf("%f", &fDurchmesser);
      fFlaeche = fDurchmesser * fDurchmesser * PI / 4; /* Formel Flaeche */
      fUmfang  = fDurchmesser * PI;                     /* Formel Kreisumfang */
	  printf("\n\t\t\tKreisfl\x84 \bche von %.2lf = %.2lf", fDurchmesser, fFlaeche);
	  printf("\n\t\t\tKreisumfang von %.2lf = %.2lf\n", fDurchmesser, fUmfang);
      printf("\n\t\t\tM\x94 \bchten Sie erneut PI berechnen?\n\n\t\t\tJa/Nein");
      if( iJaNein() )
      {
          iPI();
      }
      return 0;
  }
  
/** Funktion : Temperatur umrechnen
  * Status   : in Arbeit                        
  */ 
  int iTemp()
  {
      double dCel;
      cls();
      printf("\n\n\t\t+---------------------------------------+\n\t\t");
      printf("|\tTemperaturumrechner\t\t|\n");
      printf("\t\t+---------------------------------------+\n");
	  printf("\n\t\t\tBitte Grad Celsius eingeben: ");
	  fflush(stdin);
	  scanf("%lf", &dCel);
      printf("\n\t\t\t%.2lf  Grad Celsius sind:", dCel);
   /* °F = °C × 1,8 + 32 */
      printf("\n\t\t\t%.2lf  Fahrenheit", ((dCel * 9) / 5 + 32));
   /* K = C° + 273,15 */
      printf("\n\t\t\t%.2lf Kelvin", dCel + 273.15);
   /* °Ra = °C × 1,8 + 32 + 459,67 */
      printf("\n\t\t\t%.2lf Rankine", (dCel * 1.8) + 32 + 459.67);
   /* °R = °C × 0,8 */
      printf("\n\t\t\t%.2lf  Rèaumur\n", dCel * 0.8);
      printf("\n\t\t\tM\x94 \bchten Sie erneut temperieren?\n\n\t\t\tJa/Nein");
      if( iJaNein() )
      {
          iTemp();
      }
	  return 0;
}

/** Funktion : Waehrung umrechnen
  * Status   : in Arbeit                        
  */  
  int iWechsel()
  {
      double dKurs   = 1.4906;
      double dBetrag = 0;
      double dSumme  = 0;
      cls();
      printf("\n\n\t\t+---------------------------------------+\n\t\t");
      printf("|\tW\x84hrungsrechner\t\t\t|\n");
      printf("\t\t+---------------------------------------+\n");
	  printf("\n\t\t\tBitte Geldbetrag eingeben: ");
      fflush(stdin);
      scanf("%lf", &dBetrag);
      dSumme = dBetrag / dKurs;
      printf("\n\t\t\t%lf Euro = %lf Dollar\n", dBetrag, dSumme);
      printf("\n\t\t\tM\x94 \bchten Sie erneut kursieren?\n\n\t\t\tJa/Nein");
      if( iJaNein() )
      {
          iWechsel();
      }
      return 0;
  }

/** Funktion : Menue Umrechnungen
  * Status   : in Arbeit                        
  */
  int iUmrechner()
  {
    int iAuswahl = 0;                         /* iAuswahl(); ist die Anweisung*/
    do
	{
    
    cls();
    printf("\n\n\t\t+-------------------------------+\n\t\t");
    printf("|     Einnheiten umrechnen      |");
    printf("\n\t\t+-------------------------------+\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <1> Auswahl W\x84hrungsrechner\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <2> Auswahl Temperaturen\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <3> Auswahl Zeichenkonverter\t|\n\t\t|\t\t\t\t|\n");     
    printf("\t\t| <0> Auswahl Hauptmen\x81\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <X> Auswahl Beenden\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t+-------------------------------+\n");  
    switch(iAuswahl = getch() )              /* switch Anweisung für das Menue*/
    {
                    case '1':
                         {                           /* switch case Anweisung*/
                           printf("\n\t\t  Sie haben W\x84hrung gew\x84hlt!");
                           Sleep(1000); 
                           iWechsel();                               
                           break;
                         }
                    
                    case '2':
                         {
                           printf("\n\t\t  Sie haben Temperaturen gew\x84hlt!");
                           Sleep(1000);  
                           iTemp();                   
                           break;
                         }
                    
                    case '3':
                         {
                           printf("\n\t\t");  
                           printf("  Sie haben Konverter gew\x84hlt!");
                           Sleep(1000); 
                           iKonverter(); 
                           break;
                         }
                         
                    case '0':
                         {
                           printf("\n\t\t  Willkommen im Hauptmen\x81");
                           Sleep(1000);  
                           iMenue();
                           break;
                         }
                         
                    case 'x':
                         {
                           printf("\n\t\t  Sie haben Beenden gew\x84hlt!\r");
                           sleep(1000);
                           printf("\t\t  Sind Sie sich sicher? Ja/Nein\r ");
                           if( iJaNein() )
                           {
							   printf("\t\t      Bis Bald...\t\t\r");
	   					 	   Sleep(1000);
						   	   exit(0);
	                       }
	                       else
	                       {
						   	   printf("\t\t  Ihre Auswahl wurde abgebrochen!\r");
   					 	       Sleep(1000);
	                           iAuswahl = 0;
						   }
                           break;
                         }
						                      
                    default:       /* Standard Rückgabefunktion wenn definiert*/
                    {
                           printf("\n\t\t  Hoppla, Falsche Eingabe!");
                           sleep(1000);
                           break;
                    }                  
    }
   }while(iAuswahl != 0);
    Sleep(1000);
    return 0;
  }

/** Funktion : Zeichenkonverter
  * Status   : in Arbeit                           
  */
  int iKonverter()
  {
 	int         argc;
 	char   *argv[10];
 	int    iZahl = 0;
 	int            i;
 	int iEingabe = 0;
  	cls();                                   
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tZeichenkonverter\t\t|\n");
    printf("\t\t+---------------------------------------+\n");
	printf("\n\t\t\tBitte eine Zahl eingeben: ");
	fflush(stdin);
	scanf("%i", &iZahl);
	printf("\n\t\t\tDezimale Darstellung    : %i",iZahl);
	printf("\n\t\t\tHexadezimale Darstellung: %x",iZahl);
	printf("\n\t\t\tOktale Darstellung      : %o",iZahl);
	printf("\n\t\t\tBin\x84 \bre Darstellung      : ");
 /* sizeof ermittelt die maximale Anzahl der Bytes x 2 ergibt 4Bit */
	for(i = ( sizeof(iZahl) * 2) -1; i >= 0; i-- )
    {
	 	printf("%d",(iZahl & (0x01 << i)) > 0);
 	}/* hole 1, schiebe sie i Positionen nach links;
	  * Bilde ein logisches & AND mit der Zahl
	  * ergibt > 2^i, falls das Bit gesetzt, sonst 0 */
	printf("\n\t\t\tASCII Darstellung       : %c\n",iZahl);
    printf("\n\t\t\tM\x94 \bchten Sie erneut umwandeln?\n\n\t\t\tJa/Nein");
    
    if( iJaNein() )
    {
        iKonverter();
    }
    return 0;
  }

/** Funktion : Potenzen
  * Status   : in Arbeit                                                             
  */
  int iPotenzen()
  {
    double dBasis   = 0;
    double dExpo    = 0;

    cls();                                   
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tRechenoperation Potenzen\t|\n");
    printf("\t\t+---------------------------------------+\n"); 
    printf("\n\t\t\tBitte Grundzahl eingeben: ");
   	fflush(stdin);
    scanf("%lf",&dBasis);
    printf("\n\t\t\tBitte Hochzahl eingeben: ");
   	fflush(stdin);
    scanf("%lf",&dExpo);
     
    printf("\n\t\t\tDas Ergebnis lautet:\n\n\t\t\t%G ^ %G = %G\n",
    dBasis, dExpo, pow (dBasis,dExpo) );                                                                          
    printf("\n\t\t\tM\x94 \bchten Sie erneut potenzieren?\n\n\t\t\tJa/Nein");
    
    if( iJaNein() )
    {
        iPotenzen();
    }                          
    return 0;
  }

/** Funktion : Prozenrechnung
  * Status   : in Arbeit                                        
  */
  int iProzent()
  {
      double dProzent   = 100;
	  double dProzentwert = 0;
	  double dProzentsatz = 0;
	  double dGrundwert   = 0;
	  double dZahl1       = 0;
	  double dZahl2       = 0;
	  double dZahl3       = 0;
	  
	  cls();
	  printf("\n\n\t\t+---------------------------------------+");
	  printf("\n\t\t|   Prozentrechnung               \t|\n");
	  printf("\t\t+---------------------------------------+\n");
	  printf("\n\t\t    Bitte Prozentwert(W)  eingeben: ");
	  fflush(stdin);
	  scanf("%lf", &dZahl1); 
	  printf("\n\t\t    Bitte Prozentsatz(p%%) eingeben: ");
	  fflush(stdin);
	  scanf("%lf", &dZahl2);
	  printf("\n\t\t    Bitte Grundwert  (G)  eingeben: ");
	  fflush(stdin);
	  scanf("%lf", &dZahl3);
   /* Formeln */
	  dProzentwert = dZahl2 / dProzent * dZahl3;
	  dProzentsatz = dZahl1 / dZahl3 * dProzent;
	  dGrundwert   = dZahl1 / dZahl2 * dProzent;
   /* Ausgabe */ 
	  printf("\n\t\t    Der Prozentwert lautet:\n\t\t    %G%% / %G%% * %G = %G\n",
	  dZahl2, dProzent, dZahl3, dProzentwert);
	  printf("\n\t\t    Der Prozentsatz lautet:\n\t\t    %G / %G * %G%% = %G%%\n",
	  dZahl1, dZahl3, dProzent, dProzentsatz);
	  printf("\n\t\t    Der Grundwert lautet:\n\t\t    %G / %G%% * %G%% = %G\n",
	  dZahl1, dZahl2, dProzent, dGrundwert); 
      printf("\n\t\t    M\x94 \bchten Sie erneut prozentuieren?\n\n\t\t    Ja/Nein");
      if( iJaNein() )
      {
          iProzent();
      }                           
      return 0;
  }  

/** Funktion : Ueber mich
  * Status   : Fertig                                                    
  */
  int iInfo()
  {
    cls();
    printf("\n\n\t\t+-------------------------------+\n\t\t");
    printf("|    Taschenrechner Programm    |");
    printf("\n\t\t+-------------------------------+\n\t\t|\t\t\t\t|\n");
    printf("\t\t| Autor     : %s\t|\n\t\t|\t\t\t\t|\n", AUTOR);
    printf("\t\t| Version   : %s\t|\n\t\t|\t\t\t\t|\n", VERSION);
    printf("\t\t| Datum     : %s\t|\n\t\t|\t\t\t\t|\n", DATUM);    
    printf("\t\t| Copyright : %s\t\t|\n\t\t|\t\t\t\t|\n", PATENT);
    printf("\t\t+-------------------------------+\n");
    printf("\n\t\t     Weiter geht's mit <Enter>");
    fflush(stdin);
    while(getch() != 13);
    return 0;
  }

/** Funktion : Zinsenberechnunng fortsetzen
  * Status   : in Arbeit                                  
  */
  int iZinsen_fortsetzen()
  {
	float fGeld     = 0;
	float fZins_tmp = 0;
	float fZinsen   = 0;
	int   iJahre    = 0;
	int   iLaufzeit = 0;
	int   iEingabe  = 0;
	FILE *FPZeiger;
	FPZeiger = fopen("Beleg.log", "a");
	cls();
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tZinsrechnung\t\t\t|\n");
    printf("\t\t+---------------------------------------+\n");
	printf("\n\t\t\tBitte Geldbetrag eingeben: ");
	fflush(stdin);
	scanf("%f", &fGeld);
	printf("\n\t\t\tBitte Zinssatz (%%) eingeben: ");
	fflush(stdin);
	scanf("%f", &fZins_tmp);
	fZinsen = (fZins_tmp / 100) + 1.0f;
	printf("\n\t\t\tBitte Laufzeit (Jahr) eingeben: ");
	fflush(stdin);
	scanf("%i", &iJahre);
	
    cls();
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tRechenoperation Zinsen\t\t|\n");
    printf("\t\t+---------------------------------------+\n");
    printf("\n\t\t\tIhr Guthaben betr\x84gt im:\n");
	fprintf(FPZeiger, "\n\t+---------------------------------------+\n\t");
	fprintf(FPZeiger, "|\tIhr Guthaben mit Zinsen\t\t|\n");
	fprintf(FPZeiger, "\t+---------------------------------------+");
	fprintf(FPZeiger, "\n\tIhr aktuelles Guthaben  : %.2f,- Euro", fGeld);
	fprintf(FPZeiger, "\n\tIhr aktueller Jahreszins: %.2f %%", fZins_tmp);
	fprintf(FPZeiger, "\n\tIhre aktuelle Laufzeit  : %i Jahre", iJahre);
	fprintf(FPZeiger, "\n\tIhr Guthaben beträgt im:\n");
    for(iLaufzeit = 0; iLaufzeit < iJahre; fGeld = fGeld * fZinsen, iLaufzeit++)
    {
		printf("\n\t\t\t%i. Jahr: %.2f,- Euro\n", iLaufzeit+1, fGeld);
		fprintf(FPZeiger, "\t%i. Jahr: %.2f,- Euro\n", iLaufzeit+1, fGeld);
	}
	fclose(FPZeiger);
	printf("\n\t\t\tM\x94 \bchten Sie erneut konjugieren?\n\n\t\t\tJa/Nein");

    if( iJaNein() )
    {
        iZinsen_fortsetzen();
    }
	return 0;
  }    

/** Funktion : Zinsenberechnunng
  * Status   : in Arbeit                            
  */
  int iZinsen()
  {
	float fGeld     = 0;
	float fZins_tmp = 0;
	float fZinsen   = 0;
	int   iJahre    = 0;
	int   iLaufzeit = 0;
	int   iEingabe  = 0;
	FILE *FPZeiger;
	FPZeiger = fopen("Beleg.log", "w");
	cls();
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tZinsrechnung\t\t\t|\n");
    printf("\t\t+---------------------------------------+\n");
	printf("\n\t\t\tBitte Geldbetrag eingeben: ");
	fflush(stdin);
	scanf("%f", &fGeld);
	printf("\n\t\t\tBitte Zinssatz (%%) eingeben: ");
	fflush(stdin);
	scanf("%f", &fZins_tmp);
	fZinsen = (fZins_tmp / 100) + 1.0f;
	printf("\n\t\t\tBitte Laufzeit (Jahr) eingeben: ");
	fflush(stdin);
	scanf("%i", &iJahre);
	
    cls();
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tRechenoperation Zinsen\t\t|\n");
    printf("\t\t+---------------------------------------+\n");
    printf("\n\t\t\tIhr Guthaben betr\x84gt im:\n");
	fprintf(FPZeiger, "\n\t+---------------------------------------+\n\t");
	fprintf(FPZeiger, "|\tIhr Guthaben mit Zinsen\t\t|\n");
	fprintf(FPZeiger, "\t+---------------------------------------+");
	fprintf(FPZeiger, "\n\tIhr aktuelles Guthaben  : %.2f,- Euro", fGeld);
	fprintf(FPZeiger, "\n\tIhr aktueller Jahreszins: %.2f %%", fZins_tmp);
	fprintf(FPZeiger, "\n\tIhre aktuelle Laufzeit  : %i Jahre", iJahre);
	fprintf(FPZeiger, "\n\tIhr Guthaben beträgt im:\n");
    for(iLaufzeit = 0; iLaufzeit < iJahre; fGeld = fGeld * fZinsen, iLaufzeit++)
    {
		printf("\n\t\t\t%i. Jahr: %.2f,- Euro\n", iLaufzeit+1, fGeld);
		fprintf(FPZeiger, "\t%i. Jahr: %.2f,- Euro\n", iLaufzeit+1, fGeld);
	}
	fclose(FPZeiger);
	printf("\n\t\t\tM\x94 \bchten Sie erneut konjugieren?\n\n\t\t\tJa/Nein");

    if( iJaNein() )
    {
        iZinsen_fortsetzen();
    }
	return 0;
  }

/** Funktion : Trigonometrie
  * Status   : in Arbeit                                                       
  */
  int iTrigonometrie()
  {
    double dCount = 0, max=2*M_PI;
    
    cls();
    printf("\n\n\t+--------------------------------------------------------------+\n");
    printf("\t|\t\t\tTrigonometrie\t\t\t       |\n");
    printf("\t+--------------------------------------------------------------+\n");
    while(dCount <= max)
    {                  
                  printf("\n\tsin(%.1f) = %.3f", dCount, sin(dCount));
                  printf("\tcos(%.1f) = %.3f",   dCount, cos(dCount));
                  printf("\ttan(%.1f) = %.3f\n", dCount, tan(dCount));
                  dCount += 0.1;
	}
    printf("\n\tWeiter geht's mit <Enter>");
    fflush(stdin);
    while(getch() != 13);
	return 0;
  }

/** Funktion : Grundrechenarten
  * Status   : in Arbeit                                         
  */
  int iRechnen()
  {
    double dZahl1     = 0;
    double dZahl2     = 0;
    double dSumme     = 0;
    double dDifferenz = 0;
    double dProdukt   = 0;
    double dQuotient  = 0;
    double dRest      = 0;

    cls();                              
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tGrundrechenarten\t\t|\n");
    printf("\t\t+---------------------------------------+\n");
                                                                    
    printf("\n\t\t\tBitte 1.Zahl eingeben: ");
    fflush(stdin);                        
    scanf("%lf", &dZahl1);                     
    printf("\n\t\t\tBitte 2.Zahl eingeben: ");                
    fflush(stdin);                      
    scanf("%lf", &dZahl2);

    dSumme = dZahl1 + dZahl2;                             /* Addition */
    printf("\n\t\t\tDie Ergebnisse lauten:\n");
    printf("\n\t\t\t%G + %G = %G",
    dZahl1, dZahl2, dSumme);
    
    dDifferenz = dZahl1 - dZahl2;                      /* Subtraktion */
    printf("\n\t\t\t%G - %G = %G",
    dZahl1, dZahl2, dDifferenz);
    
    dProdukt = dZahl1 * dZahl2;                     /* Multiplikation */
    printf("\n\t\t\t%G * %G = %G",
    dZahl1, dZahl2, dProdukt);
    
    dQuotient = dZahl1 / dZahl2;                          /* Division */
    dRest = (dQuotient * dZahl2) - dZahl1;
    printf("\n\t\t\t%G / %G = %G Rest: %.2G",
    dZahl1, dZahl2, dQuotient, dRest);
    printf("\n\n\t\t\tM\x94 \bchten Sie erneut rechnen?\n\n\t\t\tJa/Nein");    
    if( iJaNein() )
    {
        iRechnen();
    }
    return 0;
  }

/** Funktion : Hilfe
  * Status   : in Arbeit                                                                       
  */
  int iHilfe()
  {
    FILE                 *FPHilfe;                
    char            sZeichen[160];                        
    FPHilfe = fopen("Hilfe","r");
      
    cls();
    
    cls();
    printf("\n\n\t\t+---------------------------------------+\n\t\t");
    printf("|\tTaschenrechner Hilfeseite\t|\n");
    printf("\t\t+---------------------------------------+\n");
    
    if(!FPHilfe)                              
          {
                printf("\n\t\t\t Keine Hilfedatei gefunden!\r");
                sleep(1000);
                printf("\t\t\t Weiter geht's mit <Enter>\t  ");
          }
            
          else                                                  
          { 
                fgets(sZeichen,160,FPHilfe);               
             do
             {
                             printf("\t\t%s",sZeichen);   
                             fgets(sZeichen,160,FPHilfe);

             }while(!feof(FPHilfe));
		  }
		  fclose(FPHilfe);                           
          printf("\t\t Weiter geht's mit <Enter>");
          fflush(stdin);    
    	  while(getch() != 13);
          return 0;
  }

/** Funktion . Hauptmenue
  * Status   : in Arbeit                                    
  */
  int iMenue()
  {
    int iAuswahl = 0;                         /* iAuswahl(); ist die Anweisung*/
    
	do
	{
    
    cls();
    printf("\n\n\t\t+-------------------------------+\n\t\t");
    printf("|     Taschenrechner Hauptmen\x81  |");
    printf("\n\t\t+-------------------------------+\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <1> Auswahl Grundrechenarten\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <2> Auswahl Mathematik\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <3> Auswahl Umrechnungen\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <H> Auswahl Hilfe   \t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <I> Auswahl \x9A \bber Mich\t\t|\n\t\t|\t\t\t\t|\n");    
    printf("\t\t| <X> Auswahl Beenden\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t+-------------------------------+\n");  
    switch(iAuswahl = getch() )              /* switch Anweisung für das Menue*/
    {
                    case '1':
                         {                            /* switch case Anweisung*/
                           printf("\n\t\t  Sie haben Grundrechen gew\x84hlt!");
                           Sleep(1000); 
                           iRechnen();                               
                           break;
                         }
                    
                    case '2':
                         {
                           printf("\n\t\t  Sie haben Mathematik gew\x84hlt!");
                           Sleep(1000);  
                           iMathematik();                   
                           break;
                         }
                    case '3':
                         {
                           printf("\n\t\t  Sie haben Umrechnungen gew\x84hlt!");
                           Sleep(1000);  
                           iUmrechner();
                           break;
                         }
                    
                    case 'h':
                         {
                           printf("\n\t\t  Sie haben die Hilfe gew\x84hlt!");
                           Sleep(1000); 
                           iHilfe();
                           break;
                         }
                         
                    case 'i':
                         {
                           printf("\n\t\t      \x9A \bber mich!");
                           Sleep(1000);  
                           iInfo();
                           break;
                         }
                    
                    case 'x':
                         {
                           printf("\n\t\t  Sie haben Beenden gew\x84hlt!\r");
                           sleep(1000);
                           printf("\t\t  Sind Sie sich sicher? Ja/Nein\r ");
                           if( iJaNein() )
                           {
							   printf("\t\t      Bis Bald...\t\t\r");
	   					 	   Sleep(1000);
						   	   exit(0);
	                       }
	                       else
	                       {
						   	   printf("\t\t  Ihre Auswahl wurde abgebrochen!\r");
   					 	       Sleep(1000);
	                           iAuswahl = 0;
						   }
                           break;
                         }
                    
                    default:       /* Standard Rückgabefunktion wenn definiert*/
                    {
                           printf("\n\t\t  Hoppla, Falsche Eingabe!");
                           sleep(1000);
                           break;
                    }                  
    }
   }while(iAuswahl != '0');
    Sleep(1000);
    return 0;
  }

/** Funktion Menue Erweiterte Mathematik
  * Status   : in Arbeit                                                
  */
  int iMathematik()
  {
    int iAuswahl = 0;                         /* iAuswahl(); ist die Anweisung*/
	do
  	{
    cls();
    printf("\n\n\t\t+-------------------------------+\n\t\t");
    printf("|     Erweiterte Mathematik     |");
    printf("\n\t\t+-------------------------------+\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <1> Auswahl Prozentrechnung\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <2> Auswahl Potenzen\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <3> Auswahl Zinsrechnung\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <5> Auswahl Fl\x84 \bchenberechnung\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <4> Auswahl Trigonometrie\t|\n\t\t|\t\t\t\t|\n");   
    printf("\t\t| <0> Auswahl Hauptmen\x81\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t| <X> Auswahl Beenden\t\t|\n\t\t|\t\t\t\t|\n");
    printf("\t\t+-------------------------------+\n"); 
    switch(iAuswahl = getch() )              /* switch Anweisung für das Menue*/
    {                
                    case '1':
                         {
                           printf("\n\t\t  Sie haben Prozente gew\x84hlt!");
                           Sleep(1000);  
                           iProzent();
                           break;
                         }
                    case '2':
                         {
                           printf("\n\t\t  Sie haben Potenzen gew\x84hlt!");
                           Sleep(1000); 
                           iPotenzen();                             
                           break;
                         }
                         
                    case '3':
                         {
                           printf("\n\t\t  Sie haben Zinsen gew\x84hlt!");
                           Sleep(1000); 
                           iZinsen();                             
                           break;
                         }
                     
                    case  '4':
                         {
                           printf("\n\t\t  Sie haben Trigonometrie gew\x84hlt!");
                           Sleep(1000); 
                           iTrigonometrie();                             
                           break;
                         }
                    case '5':
                         {
                           printf("\n\t\t  Sie haben Kreisberechnung gew\x84hlt!");
                           Sleep(1000); 
                           iPI();                              
                           break;
                         }    
                         
                    case '0':
                         {
                           printf("\n\t\t  Willkommen im Hauptmen\x81!");
                           Sleep(1000);  
                           iMenue();
                           break;
                         }
                         
                    case 'x':
                         {
                           printf("\n\t\t  Sie haben Beenden gew\x84hlt!\r");
                           sleep(1000);
                           printf("\t\t  Sind Sie sich sicher? Ja/Nein\r ");
                           if( iJaNein() )
                           {
							   printf("\t\t      Bis Bald...\t\t\r");
	   					 	   Sleep(1000);
						   	   exit(0);
	                       }
	                       else
	                       {
						   	   printf("\t\t  Ihre Auswahl wurde abgebrochen!\r");
   					 	       Sleep(1000);
	                           iAuswahl = 0;
						   }
                           break;
                         }
						                    
                    default:       /* Standard Rückgabefunktion wenn definiert*/
                    {
                           printf("\n\t\t  Hoppla, Falsche Eingabe!");
                           sleep(1000);
                           break;
                    }                  
    }
   }while(iAuswahl != '0');
    Sleep(1000);
    return 0;
  }

/** Steuerprogramm                                                           
  */
  int iController()                    /* iController() ist die Steuerfunktion*/
  {
    int iEingabe = 0;
    system("color 1F");                       /* setze Systemfarbe für Konsole*/
    iMenue();                                  /* gibt iMenue Anweisung zurück*/
    return 0;
  }

/**Funktion : Hauptprogramm                                                
  */
  int main()                                /* main() ist die Programmfunktion*/
  {                                           /* {} fasst einen Block zusammen*/
      iController();
      return 0;             /* return 0; springt zur letzten Anweisung zurueck*/
  }

/** Programmende                                                                     
  */
