/** Programm	:	klassenbuch.c
  * Autor		:	Nico Anders
  * Version     :	1.0
  * Datum		:	02.02.2011
  * Status		:	in Arbeit
  * ToDo        :
  */


/** Praeprozessor
  */  
  #include	<stdio.h>
  #include	<stdlib.h>


/** Funktion : struct st Schueler
  * Status   : in Arbeit
  */
  typedef struct stSchueler
  {
          char sName		[15];
	      char sVorname  	[15];
	      char sAdresse		[50];
	      char sAusbildung	[15];
	      char sKlasse		[10];
  }

/** Funktion : Klassenliste Ausgeben
  * Status   : in Arbeit
  */  
  int iSchueler_Ausgabe()
  {
      stSchueler;
      
      printf("\t******************************\n");
      printf("\t* Klasse %s                  *\n");
      printf("\t******************************\n");
      printf("\t  Name         	:	%s", sName );
      printf("\t  Vorname		:	%s", sNachname);
      printf("\t  Adresse		:	%s", sAdresse);
      printf("\t  Ausbildung	:	%s", sAusbildung);
      printf("\t  Klasse		:	%s", sKlasse);
      printf("\t******************************\n");
      printf("\t* 	Klassenbuch\t     *\n");
      printf("\t******************************\n");
      return 0;
}


/** Funktion : Schueler Eingeben
  * Status   : in Arbeit
  */
  int iSchueler_Eingabe()
  {
      stSchueler;				     /*definiere Strukturvariable "stSchueler"*/
      int iAuswahl = 0;
      FILE *FPSchueler;                                    
      FPSchueler = fopen("Klassenbuch", "a+");
      
      fprintf(FPSchueler, "******************************\n");
      fprintf(FPSchueler, "* Gespeicherte Schueler: *\n");
      fprintf(FPSchueler, "******************************\n");
      do
      {
                          printf("\t******************************\n");
                          printf("\t* Neuen Schueler eingeben:   *\n");
                          printf("\t******************************\n");
                          printf("\t  Name:	");
	                      fgets(sName, 16, stdin);
                          printf("\t  Nachname:	");
	                      fgets(sNachnname, 16, stdin);
                          printf("\t  Adresse:	");
	                      fgets(sAdresse, 16, stdin);
                          printf("\t  Ausbildung:	");
	                      fgets(sAusbildung, 16, stdin);
                          printf("\t  Klasse	:	");
	                      fgets(sKlasse, 16, stdin);
                          
                     
              /** Daten der Struktur ausgeben
                * Struktur als call-by-value an Funktion
                */
                stSchueler_Ausgabe;
                fclose(FPSchueler);
                printf("\t\tNeuer Tag mit Taste <1>: ");
                scanf("%i", &iAuswahl);
                
                switch(iAuswahl)
                {
                                case 1:
                                     {
                                          iSchueler_Eingabe();
                                          break;
                                     }
                                                  
                                case 2:
                                     {
                                          iSchueler_Ausgabe();
                                          break;
                                     }
                                                  
                                default:
                                     {
                                          printf("Falsche Taste");
                                          break;
                                     }
                }
      }while(iAuswahl != 0);
      return EXIT_SUCCESS;
 }

/** Funktion : Steuerfunktion
  * Status   : in Arbeit
  */
  int iController()
  {
      iSchueler_Eingabe();
      return 0;
  }

/** Funktion : main() Schnittstelle
  * Status   : in Arbeit
  */
  int main()
  {
      iController();
      return 0;
  }

/** Programmende
  * Klassenbuch.c
  */
