/** Programmname : wunschprogramm.c
  * Version      : 1.0 beta
  * Autor        : Nico Anders
  * Status       : in Arbeit
  * Datum        : 24.02.2011
  * ToDo         : Funktion Abbrechen mit ESC in Menues schreiben
  *                Bug beheben => zusaetzliche Eingabe entfernen
  *		           Funktion Auxilary zum Datensatz aus Txt loeschen schreiben
  *                Funktion zum anlegen persönlicher Logfiles
  */
 

/** Praeprozessor Anweisung
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>                           /*Headerdatei fuer Datenarrarray*/
#include <time.h>                    /*Headerdatei fuer difftime() und clock()*/
#include <conio.h>                                  /*Headerdatei fuer getch()*/
#include <windows.h>                         /*Headerdatei fuer Befehl Sleep()*/
#define  LAENGE 160
#define  ZEILEN 100
#define  ARRAY  20                                      /*aktuelle Wunschzahl*/
#define  cls(); system("cls")                 /*cls() Alias fuer system("cls")*/


/** Funtkion : TXT Datei loeschen
  * Status   : in Arbeit
  */
  int iTxt_loeschen()
  {
      cls();
      printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
      printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");                                              
      printf("\t\t*     Soll die Wunschliste geloescht werden?    *\n");                              
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");
      getch();
      remove("copy.txt");
      return 0;
  }
  
/** Funtkion : BIN Datei loeschen
  * Status   : in Arbeit
  */
  int iBin_loeschen()
  {
      cls();
      printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
      printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");                                              
      printf("\t\t*     Soll die Wunschliste geloescht werden?    *\n");                               
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");
      getch();
      remove("copy.bin");
      return 0;
  }
  
/** Funtkion : TXT Datei umbenennen 
  * Status   : in Arbeit
  */
  int iTxt_umbenennen()
  {
      cls();
      printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
      printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");                                              
      printf("\t\t*     Soll die Wunschliste umbenannt werden?    *\n");                                
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");
      getch();
      rename("logfile.txt", "copy.txt");
      return 0;
  }

/** Funtkion : BIN Datei umbenennen 
  * Status   : in Arbeit
  */
  int iBin_umbenennen()
  {
      cls();
      printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
      printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");                                              
      printf("\t\t*     Soll die Wunschliste umbenannt werden?    *\n");                                
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      getch();
      rename("logfile.bin", "copy.bin");
      return 0;
  }

/** Funtkion : Passwortabfrage
  * Status   : in Arbeit
  */
int iLogin()
{
    int         iUser;
    int     iPasswort;
    char sName[ARRAY];

    while(iPasswort)
    {
       cls();
    
       printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
       printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
       printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
       printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
       printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
       printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
       printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
       printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
       printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n"); 
       printf("\t\t*\t  => Bitte gebe einen Benutzernamen ein\t*\n");
       printf("\t\t*\t  => Bitte gebe deinen Key ein\t\t*\n");
       printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
       printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
       printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
       printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
    
         printf("\t\t\t     Login-Name: ");
         fflush(stdin);
         fgets(sName,ARRAY,stdin);
         fflush(stdin);
         printf("\t\t\t     Bitte Passwort eingeben: ");
         fflush(stdin);
      	 scanf( "%d", &iPasswort);

      	if(iPasswort == 2323)
      	{
      	    printf("\n\t\t\t     Willkommen im System, %s\r", sName);
      	    sleep(1000);
      	    break;                 
      	}
      	
      	else
      	{
      	    printf("\n\t\t\t     Zugriff verweigert!\r");
      	    sleep(1000);   	    
      	}
    }
   return 0;
}


/** Funtkion : Hilfeseite aufrufen
  * Status   : in Arbeit
  */
int iHilfe()
{
      FILE                  *FPWunsch;                
      char           sZeichen[LAENGE];                        
      FPWunsch    = fopen("help","r");
      
      cls();
      
      printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
      printf("\t\t*\t      %3i Wuensche Hilfe\t        *\n",ZEILEN);                            
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");
     
          if(!FPWunsch)                              /*Fehlerausgabe der Datei*/
          {
                printf("\t\t\t      Keine Hilfedatei gefunden!\r");
                sleep(1000);
                printf("\t\t\t      Zurueck zum Hauptmenue mit <Enter>");
          }
            
          else                                                  
          { 
                fgets(sZeichen,LAENGE,FPWunsch);               /*Ausgabe Datei*/
                fflush(stdin);
             do
             {

                             printf("\t\t %s",sZeichen);  /*Ausgabe Inhalt Txt*/   
                             fgets(sZeichen,LAENGE,FPWunsch);
                             fflush(stdin);

             }while(!feof(FPWunsch));
             
          fclose(FPWunsch);
          printf("\n\t\t\t      Ende der Datei!\r");
          Sleep(1000);                              /*warte 1000 Millisekunden*/
          printf("\t\t\t      Zurueck zum Hauptmenue mit <Enter>");      
         }while(getch() != 0x0d);           /*Programm wartet auf Eingabetaste*/
          return 0;
}

/** Funtkion : Wunschtext Schreiben Klartext
  * Status   : in Abreit
  *            in Planung Funktion Abbrechen mit Taste Esc
  */
int iSchreibenTxt()                      /*Funktion zum Schreiben der Txt File*/
{
     FILE        *FPWunsch;                         /*Definition des Filetypen*/
     char sZeichen[LAENGE];                    /*zum speichern von 160 Zeichen*/
     int      iZaehler = 1;               /*hier Startwert 0 für Wunscheingabe*/ 
     FPWunsch          = fopen("logfile.txt","w");   /*Txt File wird geöffnet!*/
     
     cls();                     /*zum Loeschen der aktuellen Bildschirmausgabe*/                             
         
     printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
     printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
     printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");                                              
     printf("\t\t* Bitte maximal %i Zeichen pro Zeile eingeben. *\n",LAENGE);                                               
     printf("\t\t* Es duerfen nur %3i Zeilen eingegeben werden\t*\n",ZEILEN);                                           
     printf("\t\t* Eingabe mit Taste <ESC> abbrechen.\t\t*\n");                                 
     printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");
     
          for(iZaehler = 1; iZaehler <= ZEILEN; iZaehler++)     
          {
                printf("\t\t %2d.Wunsch: ",iZaehler); 
                fflush(stdin);      
                fgets(sZeichen,LAENGE,stdin);
                fflush(stdin); 
                fprintf(FPWunsch, "%3d.Wunsch: ",iZaehler);
                fputs(sZeichen, FPWunsch);
          }
          
    fclose(FPWunsch);
    printf("\n\n\t\t Wunscheingabe beendet!\r");/*"r"ersetze alte Zeile*/
    Sleep(1000);
    printf("\t\t Zurueck zum Textmenue mit <Enter>");
    while(getch() != 0x0d);                 /*Programm wartet auf Einagbetaste*/
    return 0;
}

/** Funtkion : Wunschtext Fortesetzen Klartext
  * Status   : in Abreit
  *          : in Planung Funktion Abbrechen mit Taste ESC
  */
int iFortsetzenTxt()                     /*Funktion zum anhaengen der Txt File*/
{
     FILE        *FPWunsch;                         /*Definition des Filetypen*/
     char sZeichen[LAENGE];
     int     iZaehler =  1;
     FPWunsch         = fopen("logfile.txt","a");    /*Txt file wird geöffnet!*/
     
     cls();                     /*zum Loeschen der aktuellen Bildschirmausgabe*/                         
         
     printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
     printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
     printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
     printf("\t\t* Bitte maximale %i Zeichen pro Zeile eingeben.*\n",LAENGE);                                        
     printf("\t\t* Es duerfen nur %3i Zeilen eingegeben werden\t*\n",ZEILEN);                                    
     printf("\t\t* Eingabe mit Taste <ESC> abbrechen.\t\t*\n");                                 
     printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");
     
          for(iZaehler = 1; iZaehler <= ZEILEN; iZaehler++)     
          {
                printf("\t\t %2d.Wunsch: ",iZaehler);         
                fflush(stdin); 
                fgets(sZeichen,LAENGE,stdin);
                fprintf(FPWunsch, "%3d.Wunsch: ",iZaehler);
                fputs(sZeichen, FPWunsch);     
          }
          
     fclose(FPWunsch);
     printf("\n\n\t\t Wunscheingabe beendet!\r");
     Sleep(1000);
     printf("\t\t Zurueck zum Textmenue mit <Enter>");
     while(getch() != 0x0d);
     return 0;
}

/** Funtkion : Wunschtext Lesen Klartext
  * Status   : in Abreit
  */                   
int iLesenTxt()                              /*Funktion zum Lesen der Txt File*/
{
      FILE        *FPWunsch;                        /*Definition des Filetypen*/
      char sZeichen[LAENGE];           /*Max Zeichenlänge wird beruecksichtigt*/
      int      iZaehler = 1;               /*Variable iZaehler wird festgelegt*/                 
      FPWunsch          = fopen("logfile.txt","r"); /*Txt File wird geoeffnet!*/
      
      cls();
      
      printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
      printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);                             
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");
     
          if(!FPWunsch)                              /*Fehlerausgabe der Datei*/
          {
                printf("\t\t\t      Keine Wuensche vorhanden!\r");
                sleep(1000);
                printf("\t\t\t      Zurueck zum Textmenue mit <Enter>");
          }
            
          else                                                  
          { 
                fgets(sZeichen,LAENGE,FPWunsch);               /*Ausgabe Datei*/
             do
             {
                for(iZaehler = 1; iZaehler <= ZEILEN; iZaehler++)
                {
                             printf("\t\t %s",sZeichen);  /*Ausgabe Inhalt Txt*/   
                             fgets(sZeichen,LAENGE,FPWunsch);
                }
             }while(!feof(FPWunsch));
          
          fclose(FPWunsch);
          printf("\n\n\t\t Ende der Datei!\r");
          Sleep(1000);                              /*warte 1000 Millisekunden*/
          printf("\t\t Zurueck zum Textmenue mit <Enter>");      
         }while(getch() != 0x0d);           /*Programm wartet auf Eingabetaste*/
          return 0;
}

/** Funtkion : Wusnchtext Schreiben Binaerformat
  * Status   : in Abreit
  *            in Planung Funktion Abbrechen mit Taste Esc
  */
int iSchreibenBin()                      
{
     FILE        *FPWunsch;                            
     char sZeichen[LAENGE];                      
     int      iZaehler = 1;                   
     FPWunsch          = fopen("logfile.bin","wb");
     
     cls();                                      
         
     printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
     printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
     printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");                                              
     printf("\t\t* Bitte maximal %i Zeichen pro Zeile eingeben. *\n", LAENGE);                                                                                      
     printf("\t\t* Es duerfen nur %3i Zeilen eingegeben werden\t*\n", ZEILEN);                                                                              
     printf("\t\t* Eingabe mit Taste <ESC> abbrechen.\t\t*\n");                                 
     printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");
     
          for(iZaehler = 1; iZaehler <= ZEILEN; iZaehler++)     
          {
                printf("\t\t %2d.Wunsch: ",iZaehler); 
                fflush(stdin);      
                fgets(sZeichen,LAENGE,stdin);
                
                //fwrite(sZeichen,1,LAENGE,FPWunsch);
                fputs(sZeichen, FPWunsch);
          }
          
    fclose(FPWunsch);
    printf("\n\n\t\t Wunscheingabe beendet!\r");/*"r"ersetze alte Zeile*/
    Sleep(1000);
    printf("\t\t Zurueck zum Binaermenue mit <Enter>");
    while(getch() != 0x0d);                 /*Programm wartet auf Einagbetaste*/
    return 0;
}

/** Funtkion : Wunschtext Fortsetzen Binaerformat
  * Status   : in Abreit
  *          : in Planung Funktion Abbrechen mit Taste ESC
  */
int iFortsetzenBin()                    
{
     FILE        *FPWunsch;                            
     char sZeichen[LAENGE];                       
     int      iZaehler = 1;                
     FPWunsch          = fopen("logfile.txt","a");
     
     cls();                                     
         
     printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
     printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
     printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");                                              
     printf("\t\t* Bitte maximal %i Zeichen pro Zeile eingeben. *\n", LAENGE);                                                                                     
     printf("\t\t* Es duerfen nur %3i Zeilen eingegeben werden\t*\n", ZEILEN);                                                                      
     printf("\t\t* Eingabe mit Taste <ESC> abbrechen.\t\t*\n");                                 
     printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
     printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");
           for(iZaehler = 1; iZaehler <= ZEILEN; iZaehler++)     
          {
                printf("\t\t %2d.Wunsch: ",iZaehler); 
                fflush(stdin);      
                fgets(sZeichen,LAENGE,stdin);
                fflush(stdin); 
                fprintf(FPWunsch, "%3d.Wunsch: ",iZaehler);
                fputs(sZeichen, FPWunsch);
          }
          
    fclose(FPWunsch);
    printf("\n\n\t\t Wunscheingabe beendet!\r");/*"r"ersetze alte Zeile*/
    Sleep(1000);
    printf("\t\t Zurueck zum Binaermenue mit <Enter>");
    while(getch() != 0x0d);                 /*Programm wartet auf Einagbetaste*/
    return 0;
}

/** Funtkion : Wunschtext Lesen Binaerformat
  * Status   : in Abreit
  */  
int iLesenBin()                              
{
      FILE        *FPWunsch;                       
      char sZeichen[LAENGE];              
      int      iZaehler = 1;                        
      FPWunsch          = fopen("logfile.bin","rb");          
      
      cls();
      
      printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
      printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);                             
      printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
      printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n\n");
      
          if(!FPWunsch)                              /*Fehlerausgabe der Datei*/
          {
                printf("\t\t\t      Keine Wuensche vorhanden!\r");
                sleep(1000);
                printf("\t\t\t      Zurueck zum Binaermenue mit <Enter>");
          }
            
          else                                                  
          { 
                fgets(sZeichen,LAENGE,FPWunsch);               /*Ausgabe Datei*/
             do
             {
                for(iZaehler = 1; iZaehler <= ZEILEN; iZaehler++)
                {
                              printf("\t\t %3i.Wunsch: %s",iZaehler, sZeichen);  /*Ausgabe Inhalt Txt*/   
                             fgets(sZeichen,LAENGE,FPWunsch);
                }
             }while(!feof(FPWunsch));
          
          fclose(FPWunsch);
          printf("\n\n\t\t Ende der Datei!\r");
          Sleep(1000);                              /*warte 1000 Millisekunden*/
          printf("\t\t Zurueck zum Binaermenue mit <Enter>");      
         }while(getch() != 0x0d);           /*Programm wartet auf Eingabetaste*/
          return 0;
}
       
/** Hauptmenue
  * Status : in Arbeit
  */
int iMenue()
{
    int iEingabe = 0;
    
  do
  {
    cls();
      
    printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
    printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
    printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n"); 
    printf("\t\t*\t <1> Hauptmenue Klartext\t\t*\n");
    printf("\t\t*\t <2> Hauptmenue Binaertext\t\t*\n");
    printf("\t\t*\t <3> Hilfeseite Anzeigen\t\t*\n");
    printf("\t\t*\t <0> Programm   Beenden\t\t\t*\n");
    printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
    printf("\t\t\t     Waehlen Sie eine Eingabe: ");
    fflush(stdin);
    scanf("%i",&iEingabe);
  
        switch(iEingabe)
        {
                                           
         case 0:                                      /*Eingabeauswahl Beenden*/
         {
                printf("\n\t\t\t     Auf Wiedersehen!\t");
                sleep(1000);
                exit(0);
                break;
         }
         
         case 1:
         { 
                printf("\n\t\t\t     Willkommen im Textmodus\t");
                sleep(1000);
                iKlartext();                        /*Eingabeauswahl Textmenue*/
                break;
         }
         
         case 2:
         { 
                printf("\n\t\t\t     Willkommen im Binaermodus\t");
                sleep(1000);
                iBinaerformat();                  /*Eingabeauswahl Binaermenue*/
                break;
         }
         
         case 3:
         {
                printf("\n\t\t\t     Hilfe wird gestartet\t");
                sleep(1000); 
                iHilfe();                               /*Eingabeauswahl Hilfe*/
                break;
         }
         
         default:
         { 
                printf("\n\t\t\t     Upps Falsche Eingabe!");    /*Warnhinweis*/
                sleep(1000);
                break;
         }
        
        }
     
    }while(iEingabe);
    return 0;
}


/** Untermenue Klartext
  * Status : in Arbeit
  */
int iKlartext()
{
    int iEingabe = 0;
    
  do
  {
    cls();
     
    printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
    printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
    printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n"); 
    printf("\t\t*\t <1> Wunschtext Schreiben\t\t*\n");
    printf("\t\t*\t <2> Wunschtext Fortsetzen\t\t*\n");
    printf("\t\t*\t <3> Wunschtext Lesen\t\t\t*\n");
    printf("\t\t*\t <4> Wunschtext Sichern\t\t\t*\n");
    printf("\t\t*\t <5> Wunschtext Loeschen\t\t*\n");
    printf("\t\t*\t <0> Textmenue  Verlassen\t\t*\n");
    printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
    printf("\t\t\t     Waehlen Sie eine Eingabe: ");
    fflush(stdin);
    scanf("%i",&iEingabe);
    
        switch(iEingabe)
        {
                                           
         case 0:                                   /*Eingabeauswahl Hauptmenue*/
         { 
                printf("\n\t\t\t     Willkommen im Hauptmenue\t");
                sleep(1000);
                iMenue();
                break;
         }
         
         case 1:
         { 
                printf("\n\t\t\t     Meine Wuensche Schreiben\t");
                sleep(1000);
                iSchreibenTxt();                /*Eingabeauswahl Txt Schreiben*/
                break;
         }
         
         case 2:
         { 
                printf("\n\t\t\t     Meine Wuensche Fortsetzen\t");
                sleep(1000);
                iFortsetzenTxt();              /*Eingabeauswahl Txt Fortsetzen*/
                break;
         }
         
         case 3:
         { 
                printf("\n\t\t\t     Meine Wuensche Ansehen\t");
                sleep(1000);
                iLesenTxt();                        /*Eingabeauswahl Txt Lesen*/
                break;
         }
         
         case 4:
         { 
                printf("\n\t\t\t     Meine Wunschliste Sichern\t");
                sleep(1000);
                iTxt_umbenennen();                /*Eingabeauswahl Txt aendern*/
                break;
         }
         
         case 5:
         { 
                printf("\n\t\t\t     Meine Wunschliste Loeschen\t");
                sleep(1000);
                iTxt_loeschen();                 /*Eingabeauswahl Txt Loeschen*/
                break;
         }
         
         default:
         { 
                printf("\n\t\t\t     Upps Falsche Eingabe!");    /*Warnhinweis*/
                sleep(1000);
                break;
         }
        
        }
     
    }while(iEingabe);
    return 0;
}


/** Untermenue Binaertext
  * Status : in Arbeit
  */
int iBinaerformat()
{    
    int iEingabe = 0;
    
  do
  {
    cls();
      
    printf("\n\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
    printf("\t\t*\t %3i Wuensche in meinem Leben\t        *\n", ZEILEN);
    printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
    printf("\t\t*\t <1> Wunschtext Schreiben\t\t*\n");
    printf("\t\t*\t <2> Wunschtext Fortsetzen\t\t*\n");
    printf("\t\t*\t <3> Wunschtext Lesen\t\t\t*\n");
    printf("\t\t*\t <4> Wunschtext Sichern\t\t\t*\n");
    printf("\t\t*\t <5> Wunschtext Loeschen\t\t*\n");
    printf("\t\t*\t <0> Textmenue  Verlassen\t\t*\n");
    printf("\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4");
    printf("\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
    printf("\t\t\t     Waehlen Sie eine Eingabe: ");
    fflush(stdin);
    scanf("%i",&iEingabe);
  
        switch(iEingabe)
        {
                                           
         case 0:                                   /*Eingabeauswahl Hauptmenue*/
         {
                printf("\n\t\t\t     Willkommen im Hauptmenue\t");
                sleep(1500); 
                iMenue();
                break;
         }
         
         case 1:
         { 
                printf("\n\t\t\t     Meine Wuensche Schreiben\t");
                sleep(1500);
                iSchreibenBin();                /*Eingabeauswahl Bin Schreiben*/
                break;
         }
         
         case 2:
         { 
                printf("\n\t\t\t     Meine Wuensche Fortsetzen\t");
                sleep(1500);
                iFortsetzenBin();              /*Eingabeauswahl Bin Fortsetzen*/
                break;
         }
         
         case 3:
         { 
                printf("\n\t\t\t     Meine Wuensche Ansehen\t");
                sleep(1500);
                iLesenBin();                        /*Eingabeauswahl Bin Lesen*/
                break;
         }
         
         case 4:
         { 
                printf("\n\t\t\t     Meine Wunschliste Sichern\t");
                sleep(1000);
                iBin_umbenennen();                /*Eingabeauswahl Bin aendern*/
                break;
         }
         
         case 5:
         { 
                printf("\n\t\t\t     Meine Wunschliste Loeschen\t");
                sleep(1000);
                iBin_loeschen();                 /*Eingabeauswahl Bin Loeschen*/
                break;
         }
         
         default:
         { 
                printf("\n\t\t\t     Falsche Eingabe!");         /*Warnhinweis*/
                sleep(1500);
                break;
         }
        
        }
     
    }while(iEingabe);
    return 0;
}


/** Steuerfunktion
  * iController
  */
int iController()
{
    system("color 1f");
    iLogin();
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
/** Programmende
  *
  */
