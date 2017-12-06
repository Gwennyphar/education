/** Programm : adressenverwaltung.c
  * Autor    : Nico Anders
  * Version  : 0.1
  * Datum    : 20.02.2011
  * Status   : in Arbeit
  * ToDO     : Code schreiben fuer Datei anlegen
  */
  
/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #define cls(); system("cls");
  
/** Funktion : struct
  * Status   : in Arbeit
  */
  struct adressenverwaltung
  {
         char      sName[20];
         char   sVorname[20];
         char   sStrasse[50];
         char sHausnummer[5];
         char        sPLZ[5];
         char       sOrt[20];
  }adressen[5];


/** Funktion : Hilfe
  * Status   : in Arbeit
  */
  int iHilfe_anzeigen()
  {
      return 0;
  }
  
/** Funktion : Hauptmenue
  * Status   : in Arbeit
  */
  int iMenue()
  {
      int iEingabe = 0;
      do
      {
          cls();
          printf("\n\n\t<1> Adressen abrufen");
          printf("\n\t<2> Adressen erfassen");
          printf("\n\t<3> Hilfe anzeigen");
          printf("\n\t<0> Programm beenden");
          switch(iEingabe)
          {
                          case 1:
                               {
                                   iAdressen_auslesen();
                                   break;
                               }
                          
                          case 2:
                               {
                                   iAdressen_eingeben();
                                   break;
                               }
                          
                          case 3:
                               {
                                   iHilfe_anzeigen();
                                   break;
                               }
                          
                          case 0:
                               {
                                   exit(0);
                                   break;
                               }
                               
                          default:
                                  {
                                         break;
                                  }
          }
      }while(iEingabe);
      return 0;
  }
  
/** Funktion : Adressen_auslesen
  * Status   : in Arbeit
  */
  int iAdressen_auslesen()
  {
      int iID = 0;
      FILE *FPLesen;
      FPLesen = fopen("liste", "rb"); 
      
      printf("\n\n Welche Adresse?\n\n");
      scanf("%i", &iID);
      fflush (stdin);
      printf("Name      : %s\n", adressen[iID].sName);
      printf("Vorname   : %s\n", adressen[iID].sVorname);
      printf("Strasse   : %s\n", adressen[iID].sStrasse);
      printf("Hausnummer: %s\n", adressen[iID].sHausnummer);
      printf("PLZ       : %s\n", adressen[iID].sPLZ);
      printf("Ort       : %s\n", adressen[iID].sOrt);
      fflush(stdin);
      fclose(FPLesen);
      getchar();
      return 0;
  }
  
/** Funktion : Adressen_eingeben
  * Status   : in Arbeit
  */
  int iAdressen_eingeben()
  {
      int iZahl = 1;
      FILE *FPSchreiben;
      FPSchreiben = fopen("liste", "ab"); 
      
      for ( iZahl = 1; iZahl < 2; iZahl++ )
      {
          printf("\nAdresse Nr. %i eingeben\n\n", iZahl);
          printf("Name: ");
          fscanf(FPSchreiben, "%s", &adressen[iZahl].sName);
          fflush(stdin);
          printf("Vorname: ");
          fscanf(FPSchreiben, "%s", &adressen[iZahl].sVorname);
          fflush(stdin);
          printf("Strasse: ");
          fscanf(FPSchreiben, "%s", &adressen[iZahl].sStrasse);
          fflush(stdin);
          printf("Hausnummer: ");
          fscanf(FPSchreiben, "%s", &adressen[iZahl].sHausnummer);
          fflush(stdin);
          printf("PLZ: ");
          fscanf(FPSchreiben, "%s", &adressen[iZahl].sPLZ);
          fflush(stdin);
          printf("Ort: ");
          fscanf(FPSchreiben, "%s", &adressen[iZahl].sOrt);
          fflush(stdin);
      }
      fclose(FPSchreiben);
      iAdressen_auslesen();
      return 0;
  }
  
/** Programmsteuerung
  * iController()
  */
  int iController()
  {
      iMenue();
      return 0;
  }
  
/** Programmschnittstelle
  * main()
  */
  int main()
  {
      iController();
      return 0;
  }

/** Programmende
  * adressenverwaltung.c
  */
