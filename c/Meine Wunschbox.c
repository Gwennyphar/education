/** Programmname : meine_wunschbox.c
  * Version      : 2.1 stable
  * Autor        : Nico Anders
  * Status       : in Arbeit
  * Datum        : 01.05.2011
  * ToDo         : Funktion Abbrechen mit ESC in Menues
  *		           Funktion Auxilary zum Datensatz aus Txt loeschen schreiben
  *                Funktion zum anlegen, oeffnen und loeschen von Logfiles
  *				   forSchleife zum verkuerzen des ASCII
  *				   Funktionen Entfernen und Archivieren verbessern
  *               \x81 \x84 \x94 \x8E \x99 \x9A \xE1");//ü ä ö Ä Ö Ü ß
  */
 
/** Praeprozessor Anweisung
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>                          /*Headerdatei fuer DatenarrNAME*/
  #include <time.h>                  /*Headerdatei fuer difftime() und clock()*/
  #include <conio.h>                                /*Headerdatei fuer getch()*/
  #include <windows.h>                       /*Headerdatei fuer Befehl Sleep()*/
  #define  FILE_MAX 160                               /*maximale Zeichenlaenge*/
  #define  NAME 10                                         /*fuer Benutzername*/
  #define  cls() system("cls")                /*cls() Alias fuer system("cls")*/
  #define  AUTOR   "Nico Anders"
  #define  VERSION "2.1 stable"
  #define  DATUM   "01.05.2011"
  #define  PATENT  "2010-2012"
  #define  DATEI   "Wunschbuch.bin"
  #define  BACKUP  "Wunscharchiv.bin"
  #define  HILFE   "Hilfe"
  #define  TITEL   "Meine Wunschbox"

/** Funktion : Globale Anweisung
  * Status   : Fertig
  */
  int iEingabe = 0;
  int  iASCII  = 0;
  char sName[NAME];

/** Funktion : switch-case Ja Nein Funktion  
  * Status   : Fertig                                               
  */
  int iJa_Nein()
  {
 	switch( getch() )
 	{
		case 'j':
			 return 1;     /* positives Verhalten; beendet das Programm */
	    break;
	    case 'n':
			 return 0;     /* negatives Verhalten; kehrt zum Programm zurueck */
	    break;
	    default:
			iJa_Nein();	
		break;
    }
  }

/** Funktion : Passwortabfrage
  * Status   : in Arbeit
  */
  int iLogin()
  {
    int        iUser;
    int    iPasswort;

    while(iPasswort)
    {
	  cls();
      printf("\n\t\t");
      for( iASCII = 0; iASCII < 49; iASCII++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\n\t\t*\t     Meine Wunschbox\t\t        *");
      printf("\n\t\t");
      for( iASCII = 0; iASCII < 49; iASCII++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\n\t\t*\t  => Bitte Ihren Namen eingeben\t        *");
	  printf("\n\t\t*\t  => Bitte Ihr Kennwort eingeben\t*");
      printf("\n\t\t");
      for( iASCII = 0; iASCII < 49; iASCII++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\t\t\t\t\t     Login-Name: ");
   	  fflush(stdin);
  	  fgets(sName, NAME+2, stdin);
  	  sName[strlen(sName)-1] = '\0';
	  printf("\t\t\t     Passwort  : ");
      fflush(stdin);
 	  scanf( "%d", &iPasswort);
	  if(iPasswort == 2323)
	  {
	    printf("\n\t\t\t     Willkommen in der Wunschbox, %s\r", sName);
	    sleep(1000);
     	iMenue();
 	    break;
	  }
	  else
	  {
	    printf("\n\t\t\t     ZUGRIFF VERWEIGERT!\r");
      	sleep(1000);   	    
  	  }
    }
	return 0;
  }

/** Funktion : Hilfeseite aufrufen
  * Status   : in Arbeit
  */
  int iHilfe()
  {
      FILE                  *FPWunsch;                
      char           sZeichen[FILE_MAX];                        
      FPWunsch    = fopen(HILFE,"r");
      
      cls();
      printf("\n\t\t");
      for( iASCII = 0; iASCII < 49; iASCII++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\n\t\t*\t     Wunschbox Hilfe\t\t        *");                            
      printf("\n\t\t");
      for( iASCII = 0; iASCII < 49; iASCII++ )
      {
	   	   printf("\xC4");
	  }
	  if(!FPWunsch)                              /*Fehlerausgabe der Datei*/
	  {
	   	printf("\n\t\t\t     Keine Hilfedatei gefunden!\r");
        sleep(1000);
	    printf("\n\t\t\t     Zur\x81 \bck zum Hauptmen\x81 mit <Enter>");
      }
	  else                                                  
	  {
	   	fgets(sZeichen,FILE_MAX,FPWunsch);                     /*Ausgabe Datei*/
     	fflush(stdin);
             do
             {
               printf("\t\t %s",sZeichen);                /*Ausgabe Inhalt Txt*/   
               fgets(sZeichen,FILE_MAX,FPWunsch);
               fflush(stdin);
             }while(!feof(FPWunsch)); 
          fclose(FPWunsch);
          Sleep(1000);                              /*warte 1000 Millisekunden*/
          printf("\n\t\t\t     Zur\x81 \bck zum Hauptmen\x81 mit <Enter>");      
         }while(getch() != 0x0d);           /*Programm wartet auf Eingabetaste*/
          return 0;
  }

/** Funktion : Ueber Wunschprogramm
  * Status   : Fertig                                                    
  */
  int iInfo()
  {
    cls();
    printf("\n\t\t");
    for( iASCII = 0; iASCII < 49; iASCII++ )
    {
	 	 printf("\xC4");
    }
    printf("\n\t\t*\t     \x9A \bber Wunschbox\t\t        *");
    printf("\n\t\t");
    for( iASCII = 0; iASCII < 49; iASCII++ )
    {
	 	 printf("\xC4");
    }
    printf("\n");
    printf("\t\t*\t     Autor     : %s\t\t*\n", AUTOR);
    printf("\t\t*\t     Version   : %s\t\t*\n", VERSION);
    printf("\t\t*\t     Datum     : %s\t\t*\n", DATUM);    
    printf("\t\t*\t     Copyright : %s\t\t*\n", PATENT);
    printf("\t\t");
    for( iASCII = 0; iASCII < 49; iASCII++ )
    {
	 	 printf("\xC4");
    }
    printf("\n\t\t\t     Zur\x81 \bck zum Hauptmen\x81 mit <Enter>");
    fflush(stdin);
    while(getch() != 13);
    return 0;
  }
  
/** Funktion : BIN Datei umbenennen 
  * Status   : in Arbeit
  */
  int iArchivieren()
  {
      cls();
      printf("\n\t\t");
      for( iASCII = 0; iASCII < 49; iASCII++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\n\t\t*\t     %s\t\t        *",TITEL);
      printf("\n\t\t");
      for( iASCII = 0; iASCII < 49; iASCII++ )
      {
	   	   printf("\xC4");
	  }                                        
      printf("\n\t\t   M\x94 \bchten Sie ihre W\x81nsche archivieren? Ja/Nein\r");
      if( iJa_Nein() )
      {
   	     rename(DATEI, BACKUP);
   	     printf("\t\t\t     Ihre W\x81nsche werden archiviert!\t");
  	   	 sleep(1000);
	  }
	  else
	  {
   	     printf("\t\t\t     Ihre W\x81nsche werden nicht archiviert!\t");
  	   	 sleep(1000);
  	   	 iWunschprogramm();
	  }
	  return 0;
  }
  
/** Funktion : BIN Datei loeschen
  * Status   : in Arbeit
  */
  int iEntfernen()
  {
   	  unsigned long size;
      FILE *FPWunsch;
      cls();
      printf("\n\t\t");
      for( iASCII = 0; iASCII < 49; iASCII++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\n\t\t*\t     %s\t\t        *",TITEL);
      printf("\n\t\t");
      for( iASCII = 0; iASCII < 49; iASCII++ )
      {
	   	   printf("\xC4");
	  }                                       
      printf("\n\t\t   M\x94 \bchten Sie Ihre W\x81nsche l\x94schen? Ja/Nein\r");
      if( iJa_Nein() )
      {
 	     FPWunsch = fopen(DATEI, "wb"); /* setzt Zeiger auf Anfang zum Nullen */
         fseek(FPWunsch, 0L, SEEK_END);            /* Stream an das Dateiende */
         size=ftell(FPWunsch);                   /* Grösse in Bytes ermitteln */
         /* Kompletten Inhalt mit \0 überschreiben */
         fwrite((char *)'\0', 1, size, FPWunsch);
         /* damit die Datei gelöscht werden kann, schliessen */
         fclose(FPWunsch);
         remove(DATEI);                                    /* Jetzt weg damit */
 	     printf("\t\t\t     Ihre W\x81nsche werden gel\x94scht!\t");
         sleep(1000);
	  }
	  else
	  {
	   	  printf("\t\t\t     Ihre W\x81nsche werden nicht gel\x94scht!\t");
	   	  sleep(1000);
	   	  iWunschprogramm();
	  }  
      return 0;
  }

/** Funktion : Wunschtext Schreiben in Binaerdatei
  * Status   : in Abreit
  */
  int iSchreiben()                      
  {
     FILE               *FPWunsch;                            
     char      sZeichen[FILE_MAX];                      
     int              iZeilen = 1;
     FPWunsch = fopen(DATEI,"wb");
     
     cls();                     /*zum Loeschen der aktuellen Bildschirmausgabe*/
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }
	  printf("\n\t\t*\t     %s\t\t        *",TITEL);
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }
     printf("\n\t\t   Wie viele W\x81nsche m\x94 \bchten Sie anlegen? ");
     fflush(stdin);
     scanf("%i", &iEingabe);
     cls();
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }
     printf("\n\t\t*\t %3i W\x81nsche in meinem Leben\t        *", iEingabe);
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }                                            
     printf("\n\t\t*  Bitte maximal %i Zeichen pro Zeile eingeben *",FILE_MAX);                                               
     printf("\n\t\t*  Sie d\x81rfen bis zu %3i Zeilen eingeben\t*", iEingabe);                                 
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }
	 printf("\n");  
	 for(iZeilen = 1; iZeilen <= iEingabe; iZeilen++)     
	 {
        printf("\t\t\t %3d.Wunsch: ",iZeilen); 
  		fflush(stdin);      
    	fgets(sZeichen,(FILE_MAX+2),stdin);
     	sZeichen[(strlen(sZeichen)-1)] = '\0';
      	fwrite(sZeichen, 1,FILE_MAX, FPWunsch);
  	 }    
	 fclose(FPWunsch);
	 printf("\n\n\t\t\t     Wunscheingabe beendet!\r");
	 Sleep(1000);
	 printf("\t\t\t     Zur\x81 \bck zum Hauptmen\x81 mit <Enter>");
	 while(getch() != 0x0d);                /*Programm wartet auf Einagbetaste*/
	 return 0;
  }

/** Funktion : Wunschtext Fortsetzen Binaerformat
  * Status   : in Abreit
  */
  int iFortsetzen()                    
  {
     FILE               *FPWunsch;                            
     char      sZeichen[FILE_MAX];                       
     int              iZeilen = 1;                
     FPWunsch = fopen(DATEI,"ab");
     
     cls();                     /*zum Loeschen der aktuellen Bildschirmausgabe*/
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }
	  printf("\n\t\t*\t     %s\t\t        *",TITEL);
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }
     printf("\n\t\t   Wie viele W\x81nsche m\x94 \bchten Sie fortsetzen? ");
     fflush(stdin);
     scanf("%i", &iEingabe);
     cls();
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }
     printf("\n\t\t*\t %3i weitere W\x81nsche in meinem Leben\t*", iEingabe);
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }                                            
     printf("\n\t\t*  Bitte maximal %i Zeichen pro Zeile eingeben *",FILE_MAX);                                               
     printf("\n\t\t*  Sie d\x81rfen bis zu %3i Zeilen eingeben\t*", iEingabe);                                 
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }
	 printf("\n");  
	 for(iZeilen = 1; iZeilen <= iEingabe; iZeilen++)     
	 {
        printf("\t\t\t %3d.Wunsch: ",iZeilen); 
  		fflush(stdin);      
    	fgets(sZeichen,(FILE_MAX+2),stdin);
     	sZeichen[(strlen(sZeichen)-1)] = '\0';
      	fwrite(sZeichen, 1,FILE_MAX, FPWunsch);
  	 }    
	 fclose(FPWunsch);
	 printf("\n\n\t\t\t     Wunscheingabe beendet!\r");
	 Sleep(1000);
	 printf("\t\t\t     Zur\x81 \bck zum Hauptmen\x81 mit <Enter>");
	 while(getch() != 0x0d);                /*Programm wartet auf Einagbetaste*/
	 return 0;
  }

/** Funktion : Wunschtext Lesen Binaerformat
  * Status   : in Abreit
  */  
  int iLesen()                              
  {
   	 FILE               *FPWunsch;                       
     char      sZeichen[FILE_MAX];              
     int              iZeilen = 1;                        
     int                  iLaenge;
  	 FPWunsch = fopen(DATEI,"rb");          
     cls();
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }
     printf("\n\t\t*\t     %s\t\t        *",TITEL);
     printf("\n\t\t");
     for( iASCII = 0; iASCII < 49; iASCII++ )
     {
	  	  printf("\xC4");
     }
     if(!FPWunsch)                              /*Fehlerausgabe der Datei*/
     {
	   	printf("\n\t\t\t     Keine W\x81nsche vorhanden!\r");
        sleep(1000);
	    printf("\t\t\t     Zur\x81 \bck zum Hauptmen\x81 mit <Enter>");
     } 
     else                                                  
     {
	   do
	   {
        printf("\n\t\t   Wie viele W\x81nsche m\x94 \bchten Sie lesen? ");
 	  	fflush(stdin);
  	  	scanf("%i", &iEingabe);
   	  	cls();
	 	printf("\n\t\t");
     	for( iASCII = 0; iASCII < 49; iASCII++ )
     	{
	  	  printf("\xC4");
   	    }
 	    printf("\n\t\t*\t %3i W\x81nsche in meinem Leben\t        *", iEingabe);
     	printf("\n\t\t");
     	for( iASCII = 0; iASCII < 49; iASCII++ )
     	{
	  	  printf("\xC4");
		}
		printf("\n");
   		fseek(FPWunsch,0,SEEK_END);
  	 	iLaenge = ftell(FPWunsch)/FILE_MAX;
     	rewind(FPWunsch);
                for(iZeilen = 1; iZeilen <= iEingabe; iZeilen++)
                {
	 			    if(iLaenge > 0 )
	 			    {
					  fread(sZeichen, FILE_MAX, 1, FPWunsch);
        			  printf("\t\t\t %3d.Wunsch: ",iZeilen); 
					  printf("%s\n", sZeichen);           /*Ausgabe Inhalt BIN*/
					  iLaenge--;                     /*iLaenge minus 1 setzen */
					}   
                }
             }while(iLaenge > 0);
          fclose(FPWunsch);
		  printf("\n\t\t\t     Vielen Dank!\r");
          Sleep(1000);                              /*warte 1000 Millisekunden*/
		  printf("\t\t\t     Zur\x81 \bck zum Hauptmen\x81 mit <Enter>");    
         }while(getch() != 0x0d);           /*Programm wartet auf Eingabetaste*/
          return 0;
  }
       
/** Funktion : Hauptmenue
  * Status   : in Arbeit
  */
  int iMenue()
  {
    do
	{
	  cls();
	  printf("\n\t\t");
	  for( iASCII = 0; iASCII < 49; iASCII++ )
	  {
	  	  printf("\xC4");
	  }
	  printf("\n\t\t*\t     %s\t\t        *",TITEL);
	  printf("\n\t\t");
	  for( iASCII = 0; iASCII < 49; iASCII++ )
	  {
	 	 printf("\xC4");
      }
	  printf("\n\t\t*\t <1> Wunschmen\x81 \x99 \bffnen\t\t        *");
	  printf("\n\t\t*\t <2> %10s Abmelden\t\t*", sName);
	  printf("\n\t\t*\t <H> Hilfeseite Anzeigen\t\t*");
	  printf("\n\t\t*\t <I> \x9A \bber diese Version\t\t        *");  
	  printf("\n\t\t*\t <X> Wunschbox  Beenden\t\t        *");
      printf("\n\t\t");
      for( iASCII = 0; iASCII < 49; iASCII++ )
	  {
	  	 printf("\xC4");
      }
	  printf("\n\t\t\t     W\x84hlen Sie eine Option:\r ");
	  switch(iEingabe = getch() )
      {
   		 case 'x':                                    /*Eingabeauswahl Beenden*/
	  	 {
    	  	    printf("\t\t\t     Sie haben Beenden gew\x84hlt!\r");
        		sleep(1000);
    	  	    printf("\t\t\t     Sind Sie sich sicher? Ja/Nein\r ");
            	if( iJa_Nein() )
             	{
  	     			   printf("\t\t\t     Auf Wiedersehen!\t\t  ");
			 	   	   Sleep(1000);
	   	   			   exit(0);
       		    }
             	else
              	{
  	     			   printf("\t\t\t     Sie haben ihre Auswahl abgebrochen!\r");
			 	       Sleep(1000);
            		   iMenue();
  			    }
	     }
         case '1':
         { 
	            printf("\t\t\t     Willkommen im Wunschmen\x81\t");
                sleep(1000);
                iWunschprogramm();                  /*Eingabeauswahl Textmenue*/
                break;
         }
         case 'h':
         {
	            printf("\t\t\t     Hilfe wird ge\x94 \bffnet\t");
                sleep(1000); 
                iHilfe();                               /*Eingabeauswahl Hilfe*/
                break;
         }
         case '2':
         {
	            printf("\t\t\t     %s wird abgemeldet\t    ", sName);
                sleep(1000); 
                iLogin();                              /*Eingabeauswahl Logout*/
                break;
         }
         case 'i':
         {
	            printf("\t\t\t     \x9A \bber Wunschbox\t\t");
                sleep(1000); 
                iInfo();                               /*Eingabeauswahl Logout*/
                break;
         }
         default:
         { 
	            printf("\t\t\t     Upps Falsche Eingabe!\t");    /*Warnhinweis*/
                sleep(1000);
                break;
         }
      }
    }while(iEingabe != '0');
    return 0;
  }

/** Funktion : Wunschprogramm
  * Status   : in Arbeit
  */
  int iWunschprogramm()
  {
	do
	{
	  cls(); 
	  printf("\n\t\t");
	  for( iASCII = 0; iASCII < 49; iASCII++ )
	  {
	  	  printf("\xC4");
	  }
	  printf("\n\t\t*\t     %s\t\t        *",TITEL);
	  printf("\n\t\t");
	  for( iASCII = 0; iASCII < 49; iASCII++ )
	  {
	  	  printf("\xC4");
	  }
	  printf("\n");
	  printf("\t\t*\t <1> Meine W\x81nsche Schreiben  \t\t*\n");
	  printf("\t\t*\t <2> Meine W\x81nsche Fortsetzen  \t\t*\n");
	  printf("\t\t*\t <3> Meine W\x81nsche Lesen \t\t*\n");
	  printf("\t\t*\t <4> Meine W\x81nsche Archivieren \t\t*\n");
	  printf("\t\t*\t <5> Meine W\x81nsche L\x94schen  \t\t*\n");
	  printf("\t\t*\t <0> Meine W\x81nsche Verlassen\t\t*\n");
	  printf("\t\t*\t <X> Meine Wunschbox Beenden\t\t*");
	  printf("\n\t\t");
	  for( iASCII = 0; iASCII < 49; iASCII++ )
	  {
	  	  printf("\xC4");
	  }
	  printf("\n\t\t\t     W\x84hlen Sie eine Option:\r ");
	  switch(iEingabe = getch() )
	  {                                
         case '0':                                 /*Eingabeauswahl Hauptmenue*/
         {
    	  	    printf("\t\t\t     Willkommen im Hauptmen\x81\t");
                sleep(1500); 
                iMenue();
                break;
         }
         case '1':
         { 
    	  	    printf("\t\t\t     Meine W\x81nsche Schreiben\t");
                sleep(1500);
                iSchreiben();                   /*Eingabeauswahl Bin Schreiben*/
                break;
         }
         case '2':
         { 
    	  	    printf("\t\t\t     Meine W\x81nsche Fortsetzen\t");
                sleep(1500);
                iFortsetzen();                 /*Eingabeauswahl Bin Fortsetzen*/
                break;
         }
         case '3':
         { 
    	  	    printf("\t\t\t     Meine W\x81nsche Ansehen\t");
                sleep(1500);
                iLesen();                           /*Eingabeauswahl Bin Lesen*/
                break;
         }
         case '4':
         { 
    	  	    printf("\t\t\t     Meine W\x81nsche Archivieren\t");
                sleep(1000);
                iArchivieren();                    /*Eingabeauswahl Bin aendern*/
                break;
         }
         case '5':
         { 
    	  	    printf("\t\t\t     Meine W\x81nsche L\x94schen\t");
                sleep(1000);
                iEntfernen();                    /*Eingabeauswahl Bin Loeschen*/
                break;
         }
   		 case 'x':                                    /*Eingabeauswahl Beenden*/
	  	 {
    	  	    printf("\t\t\t     Sie haben Beenden gew\x84hlt!\r");
        		sleep(1000);
    	  	    printf("\t\t\t     Sind Sie sich sicher? Ja/Nein\r ");
            	if( iJa_Nein() )
             	{
  	     			   printf("\t\t\t     Auf Wiedersehen!\t\t  ");
			 	   	   Sleep(1000);
	   	   			   exit(0);
       		    }
             	else
              	{
  	     			   printf("\t\t\t     Sie haben ihren Vorgang abgebrochen!\r");
			 	       Sleep(1000);
            		   iWunschprogramm();
  			    }
	     }
         default:
         { 
    	  	    printf("\t\t\t     Falsche Eingabe!\t\t");       /*Warnhinweis*/
                sleep(1500);
                break;
         }
        }
    }while(iEingabe != '0');
    return 0;
  }

/** Steuerfunktion
  * iController
  */
  int iController()
  {
    system("color 1f");
    iLogin();
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
  
/** Programmende
  */
