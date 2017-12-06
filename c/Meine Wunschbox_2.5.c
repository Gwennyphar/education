/** Programmname : meine_wunschbox.c
  * Version      : 2.5 stable
  * Autor        : Nico Anders
  * Status       : in Arbeit
  * Datum        : 20.05.2011
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
  #define  VERSION "2.5 stable"
  #define  DATUM   "20.05.2011"
  #define  PATENT  "2010-2012"
  #define  DATEI   "Wunschbuch.bin"
  #define  BACKUP  "Archiv.bin"
  #define  HILFE   "Hilfe"
  #define  TITEL   "Wunschbox"

/** Funktion : Globale Anweisung
  * Status   : Fertig
  */
  int iEingabe = 0;
  int i        = 1;
  char sName[NAME];
  char sPfad[FILENAME_MAX];

/** Funktion : switch-case Ja Nein Funktion  
  * Status   : Fertig                                               
  */
  int iJa_Nein()
  {
 	switch( getch() )
 	{
		case 'j':
			 {
			  	 return 1;  /* positives Verhalten; beendet das Programm */
				 break;
			 }
	    case 'n':
			 {
			  	 return 0; /* negatives Verhalten; kehrt zum Programm zurueck */
				 break;
			 }
	    default:
			 {
				 //printf("\t\t\t     Diese Funktion ist mir nicht bekannt\r");
				 iJa_Nein();
				 break;
			 }
    }
  }

/** Funktion : Passwortabfrage
  * Status   : in Arbeit
  */
  int iLogin()
  {
    int        iUser;
    int    iPasswort;
	struct tm *myTm;
	time_t now;
	time(&now);
	now = time(0);
	myTm = localtime(&now);
   	
    while(iPasswort)
    {
	  cls();
      printf("\n\t\t");
      for( i = 0; i < 49; i++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\n\t\t*\t     Meine Wunschbox\t   %02d:%02d:%02d Uhr *", myTm->tm_hour, myTm->tm_min, myTm->tm_sec);
      printf("\n\t\t");
      for( i = 0; i < 49; i++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\n\t\t*\t  => Bitte Ihren Namen eingeben\t        *");
	  printf("\n\t\t*\t  => Bitte Ihr Kennwort eingeben\t*");
      printf("\n\t\t");
      for( i = 0; i < 49; i++ )
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
      for( i = 0; i < 49; i++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\n\t\t*\t     Wunschbox Hilfe\t\t        *");                            
      printf("\n\t\t");
      for( i = 0; i < 49; i++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\t\t");
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
               printf("\t\t%s",sZeichen);                /*Ausgabe Inhalt Txt*/   
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
    for( i = 0; i < 49; i++ )
    {
	 	 printf("\xC4");
    }
    printf("\n\t\t*\t     \x9A \bber Wunschbox\t\t        *");
    printf("\n\t\t");
    for( i = 0; i < 49; i++ )
    {
	 	 printf("\xC4");
    }
    printf("\n");
    printf("\t\t*\t     Autor     : %s\t\t*\n", AUTOR);
    printf("\t\t*\t     Version   : %s\t\t*\n", VERSION);
    printf("\t\t*\t     Datum     : %s\t\t*\n", DATUM);    
    printf("\t\t*\t     Copyright : %s\t\t*\n", PATENT);
    printf("\t\t");
    for( i = 0; i < 49; i++ )
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
  int iUmbennenen()
  {
	  FILE *FPEingabe, *FPAusgabe;    /* Filepointer */
	  char sZeichen[FILE_MAX];     /* Zeilenpuffer */
      cls();
      printf("\n\t\t");
      for( i = 0; i < 49; i++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\n\t\t*\t   %10s's %s\t\t*",sName, TITEL);
      printf("\n\t\t");
      for( i = 0; i < 49; i++ )
      {
	   	   printf("\xC4");
	  }
   /* Eingabedatei öffnen */
      FPEingabe = fopen(DATEI, "r");                          
      if( !FPEingabe )/* wenn Datei nicht gefunden, dann abbrechen */
      {
          printf("\n\t\t   %s wurde nicht gefunden\t\t\r", DATEI);
		  sleep(1000);
          printf("\t\t   M\x94 \bchten Sie Ihre W\x81nsche hinzuf\x81gen? Ja/Nein \r");
          if( iJa_Nein() )
          {
              iFortsetzen();
		  }
      }
	  else         /* ... sonst wird hier die Datei erfolgreich umbenannt */
	  {
        /* Ausgabedatei öffnen */
           printf("\n\t\t   Wie soll die Kopie hei\xE1 \ben? ");
           fflush(stdin);
           scanf("%s", sPfad);
           FPAusgabe = fopen(sPfad, "w");
        /* Zeilenweise lesen und schreiben */
           while (fgets(sZeichen, sizeof(sZeichen), FPEingabe))
           fwrite(sZeichen, 1,FILE_MAX, FPAusgabe);
        /* Files schliessen und Ende */
           fclose(FPEingabe);
           fclose(FPAusgabe); 
		   printf("\t\t   %s wird in %s ge\x84ndert!\t\r", DATEI, sPfad);
	       sleep(1000);
		   iWunschprogramm();         /* und springe zurueck ins Menue */
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
      for( i = 0; i < 49; i++ )
      {
	   	   printf("\xC4");
	  }
	  printf("\n\t\t*\t   %10s's %s\t\t*",sName, TITEL);
      printf("\n\t\t");
      for( i = 0; i < 49; i++ )
      {
	   	   printf("\xC4");
  	}                                       
	  printf("\n\t\t   Welche Datei m\x94 \bchten Sie l\x94schen? ");
      fflush(stdin);
      scanf("%s", sPfad);
          if( remove(sPfad)!= NULL )/* wenn Datei nicht gefunden, dann abbrechen */
          {
              printf("\t\t   %s wurde nicht gefunden\t\t\r", sPfad);
              sleep(1000);
              printf("\t\t   M\x94 \bchten Sie weitere W\x81nsche l\x94schen? Ja/Nein\r");
              if( iJa_Nein() )
              {
                  iEntfernen();             /* bleibe zur Fehlersuche in Funktion */
              }
          }
          else                       /* ...sonst Datei zum loeschen vormerken */
          {
              FPWunsch = fopen(DATEI, "wb");/* setzt Zeiger auf Anfang zum Nullen */
              fseek(FPWunsch, 0L, SEEK_END);       /* Stream an das Dateiende */
              size=ftell(FPWunsch);              /* Grösse in Bytes ermitteln */
              /* Kompletten Inhalt mit \0 überschreiben */
              fwrite((char *)'\0', 1, size, FPWunsch);
              /* damit die Datei gelöscht werden kann, schliessen */
              fclose(FPWunsch);
              remove(sPfad);                               /* Jetzt weg damit */
              printf("\t\t   %s wird gel\x94scht!\t\t\r", sPfad);
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
     FPWunsch = fopen(DATEI,"wb");
     
     cls();                     /*zum Loeschen der aktuellen Bildschirmausgabe*/
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }
	 printf("\n\t\t*\t   %10s's %s\t\t*",sName, TITEL);
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }
     printf("\n\t\t   Wie viele W\x81nsche m\x94 \bchten Sie verfassen? ");
     fflush(stdin);
     scanf("%i", &iEingabe);
     cls();
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }
     printf("\n\t\t*\t %3i W\x81nsche in meinem Leben\t        *", iEingabe);
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }                                            
     printf("\n\t\t*  Bitte maximal %i Zeichen pro Zeile eingeben *",FILE_MAX);                                               
     printf("\n\t\t*  Sie k\x94 \bnnen bis zu %3i Zeilen eingeben\t*", iEingabe);                                 
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }
	 printf("\n");  
	 for(i = 1; i <= iEingabe; i++)     
	 {
        printf("\t\t\t %3d.Wunsch: ",i); 
  		fflush(stdin);      
    	fgets(sZeichen,(FILE_MAX+2),stdin);
     	sZeichen[(strlen(sZeichen)-1)] = '\0';
      	fwrite(sZeichen, 1,FILE_MAX, FPWunsch);
  	 }    
	 fclose(FPWunsch);
	 printf("\n\n\t\t\t     Wunscheingabe beendet!\r");
	 Sleep(1000);
	 printf("\t\t\t     Zur\x81 \bck zum Men\x81 mit <Enter>");
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
     FPWunsch = fopen(DATEI,"ab");
     
     cls();                     /*zum Loeschen der aktuellen Bildschirmausgabe*/
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }
	 printf("\n\t\t*\t   %10s's %s\t\t*",sName, TITEL);
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }
     printf("\n\t\t   Wie viele W\x81nsche m\x94 \bchten Sie hinzuf\x81gen? ");
     fflush(stdin);
     scanf("%i", &iEingabe);
     cls();
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }
     printf("\n\t\t*\t %3i weitere W\x81nsche in meinem Leben\t*", iEingabe);
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }                                            
     printf("\n\t\t*  Bitte maximal %i Zeichen pro Zeile eingeben *",FILE_MAX);                                               
     printf("\n\t\t*  Sie k\x94 \bnnen bis zu %3i Zeilen eingeben\t*", iEingabe);                                 
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }
	 printf("\n");  
	 for(i = 1; i <= iEingabe; i++)     
	 {
        printf("\t\t\t %3d.Wunsch: ",i); 
  		fflush(stdin);      
    	fgets(sZeichen,(FILE_MAX+2),stdin);
     	sZeichen[(strlen(sZeichen)-1)] = '\0';
      	fwrite(sZeichen, 1,FILE_MAX, FPWunsch);
  	 }    
	 fclose(FPWunsch);
	 printf("\n\n\t\t\t     Wunscheingabe beendet!\r");
	 Sleep(1000);
	 printf("\t\t\t     Zur\x81 \bck zum Men\x81 mit <Enter>");
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
     int                  iLaenge;
  	 FPWunsch = fopen(DATEI,"rb");          
     cls();
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }
	 printf("\n\t\t*\t   %10s's %s\t\t*",sName, TITEL);
     printf("\n\t\t");
     for( i = 0; i < 49; i++ )
     {
	  	  printf("\xC4");
     }
     if(!FPWunsch)                              /*Fehlerausgabe der Datei*/
     {
        printf("\n\t\t   Sie haben noch keine W\x81nsche verfasst!\r");
        sleep(1000);
        printf("\t\t   M\x94 \bchten Sie Ihre W\x81nsche hinzuf\x81gen? Ja/Nein \r");
   	   	if( iJa_Nein() )
   	   	{
		 	iFortsetzen();
		}
		else
		{
		 	iWunschprogramm();
		}
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
     	for( i = 0; i < 49; i++ )
     	{
	  	  printf("\xC4");
   	    }
 	    printf("\n\t\t*\t %i W\x81nsche in meinem Leben\t        *", iEingabe);
     	printf("\n\t\t");
     	for( i = 0; i < 49; i++ )
     	{
	  	  printf("\xC4");
		}
		printf("\n");
   		fseek(FPWunsch,0,SEEK_END);
  	 	iLaenge = ftell(FPWunsch)/FILE_MAX;
     	rewind(FPWunsch);
                for(i = 1; i <= iEingabe; i++)
                {
	 			    if(iLaenge > 0 )
	 			    {
					  fread(sZeichen, FILE_MAX, 1, FPWunsch);
        			  printf("\t\t\t %3d.Wunsch: ",i); 
					  printf("%s\n", sZeichen);           /*Ausgabe Inhalt BIN*/
					  iLaenge--;                     /*iLaenge minus 1 setzen */
					}   
                }
             }while(iLaenge > 0);
          fclose(FPWunsch);
		  printf("\n\t\t\t     Vielen Dank!\r");
          Sleep(1000);                              /*warte 1000 Millisekunden*/
		  printf("\t\t\t     Zur\x81 \bck zum Men\x81 mit <Enter>");    
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
	  for( i = 0; i < 49; i++ )
	  {
	  	  printf("\xC4");
	  }

	  printf("\n\t\t*\t   %10s's %s\t\t*",sName, TITEL);
	  printf("\n\t\t");
	  for( i = 0; i < 49; i++ )
	  {
	 	 printf("\xC4");
      }
	  printf("\n\t\t*        <1> Wunschbuch \x99 \bffnen\t\t        *");
	  printf("\n\t\t*        <H> Hilfeseite Anzeigen\t\t*");
	  printf("\n\t\t*        <I> \x9A \bber diese Version\t\t        *");  
	  printf("\n\t\t*        <X> Wunschbox  Beenden\t\t        *");
	  printf("\n\t\t*      <ESC> %10s Abmelden\t\t*", sName);
      printf("\n\t\t");
      for( i = 0; i < 49; i++ )
	  {
	  	 printf("\xC4");
      }
	  printf("\n\t\t\t     W\x84hlen Sie eine Option:\r ");
	  switch(iEingabe = getch() )
      {
   		 case 'x':                                    /*Eingabeauswahl Beenden*/
	  	 {
    	  	    printf("\t\t\t     M\x94 \bchten Sie beenden? Ja/Nein\r ");
          		sleep(1000);
            	if( iJa_Nein() )
             	{
  	     			   printf("\t\t\t     Auf Wiedersehen, %s\t\t  ", sName);
			 	   	   Sleep(1000);
	   	   			   exit(0);
       		    }
             	else
              	{
                       iMenue();
  			    }
	     }
         case 27:
	     {
 	          printf("\t\t\t     M\x94 \bchten Sie sich abmelden? Ja/Nein\r");
    		  sleep(1000);
		  	  if( iJa_Nein() )
		  	  {
	            printf("\t\t\t     %s wird abgemeldet\t\t       ", sName);
                Sleep(1000);
  	   	  	    iLogin();
			  }
			  else
			  {
			   	  iMenue();
			  }
		 }
         case '1':
         { 
	            printf("\t\t\t     Wunschbuch wird ge\x94 \bffnet");
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
         case 'i':
         {
	            printf("\t\t\t     \x9A \bber Wunschbox\t\t");
                sleep(1000); 
                iInfo();                               /*Eingabeauswahl Logout*/
                break;
         }
         default:
         { 
	            printf("\t\t\t     Upps, Diese Funktion kenne ich nicht!\t");   /*Warnhinweis*/
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
	  for( i = 0; i < 49; i++ )
	  {
	  	  printf("\xC4");
	  }
	  printf("\n\t\t* <ESC>  <X>  %10s's %s\t\t*",sName, TITEL);
	  printf("\n\t\t");
	  for( i = 0; i < 49; i++ )
	  {
	  	  printf("\xC4");
	  }
	  printf("\n");
	  printf("\t\t*\t <1> Meine W\x81nsche Verfassen  \t\t*\n");
	  printf("\t\t*\t <2> Meine W\x81nsche Hinzuf\x81gen\t\t*\n");
	  printf("\t\t*\t <3> Meine W\x81nsche Lesen \t\t*\n");
	  printf("\t\t*\t <4> Meine W\x81nsche Archivieren \t\t*\n");
	  printf("\t\t*\t <5> Meine W\x81nsche L\x94schen  \t\t*\n");
	  printf("\t\t*\t <0> Meine W\x81nsche Verlegen\t\t*\n");
	  printf("\t\t");
	  for( i = 0; i < 49; i++ )
	  {
	  	  printf("\xC4");
	  }
	  printf("\n\t\t\t     W\x84hlen Sie eine Option:\r ");
	  switch(iEingabe = getch() )
	  {                                
         case '0':                                 /*Eingabeauswahl Hauptmenue*/
         {
    	  	    printf("\t\t\t     Hauptmen\x81 wird ge\x94 \bffnet");
                sleep(1500); 
                iMenue();
                break;
         }
         case '1':
         { 
    	  	    printf("\t\t\t     Meine W\x81nsche Verfassen\t");
                sleep(1500);
                iSchreiben();                   /*Eingabeauswahl Bin Schreiben*/
                break;
         }
         case '2':
         { 
    	  	    printf("\t\t\t     Meine W\x81nsche hinzuf\x81gen\t");
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
                iUmbennenen();                   /*Eingabeauswahl Bin aendern*/
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
    	  	    printf("\t\t\t     M\x94 \bchten Sie beenden? Ja/Nein\r ");
          		sleep(1000);
            	if( iJa_Nein() )
             	{
  	     			   printf("\t\t\t     Auf Wiedersehen, %s\t\t  ", sName);
			 	   	   Sleep(1000);
	   	   			   exit(0);
       		    }
             	else
              	{
            		   iWunschprogramm();
  			    }
	     }
	     case 27:  /* 27 ASCII Zeichen fuer ESC Taste; Funktion zum Abmelden  */
	     {
 	          printf("\t\t\t     M\x94 \bchten Sie sich abmelden? Ja/Nein\r");
    		  sleep(1000);
		  	  if( iJa_Nein() )
		  	  {
	            printf("\t\t\t     %s wird abgemeldet\t\t       ", sName);
                Sleep(1000);
  	   	  	    iLogin();
			  }
			  else
			  {
			   	  iWunschprogramm();
			  }
		 }
         default:
         { 
    	  	    printf("\t\t\t     Upps, Diese Funktion kenne ich nicht!\t\t"); /*Warnhinweis*/
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
