/** Programname: cyclebook.c
  * Autor      : Nico Anders
  * Version    : 1.1
  * Datum      : 30.01.2012
  * Stand      : 30.01.2012
  * Status     : in Arbeit
  * ToDo       :
  */

/**Praeprozessor für printf() und scanf()
  */ 
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "mylib_cb.h"

/** Funktion: struct fuer Datenerfassung
  * Status  : fertig 
  */
  struct daten
  {
	  char   sName[22];
	  int    iAlter;
	  double dGewicht;
	  int    iDay;
	  int    iMon;
	  int    iYear;
	  char   sDisziplin[255];
	  char   sStrecke[255];
	  char   sWetter[255];
	  char   sGA[255];
	  double dZeit;
	  double dKM;
	  double dHM;
	  int    iBorg; 
	  int    iRitzel;
	  double dSpeed;
	  double dTF;
	  double dHF;
	  double dWatt;
	  double dKcal;
	  int    iPunkte;
};

int iCounter = 0;

/** Funktion: Training löschen
  * Status  : in Arbeit 
  */
  int iDaten_Entf()
  {
	  char sDateiname[255];
	  Header();
	  csr(9,2);
	  printf("Dokument löschen: ");
	  scanf("%s", sDateiname);
	  flush();
	  strcat(sDateiname, ".csv");
	  if(remove(sDateiname) != 0)
	  {
		  csr(9,2);
		  printf("Sorry, kein Training vorhanden!");
		  getchar();
		  return EXIT_FAILURE;		  
	  }
	  else
	  {
		  remove("cyclebook.txt");
		  csr(9,2);
		  printf("Training gelöscht!");
		  getchar();
		  return EXIT_SUCCESS;
	  }
	  return EXIT_SUCCESS;
  }

/** Funktion: Eintragn suchen
  * Status  : in Arbeit 
  */
  int iDaten_Suchen()
  {
	  FILE *FPDatei;
	  char sDateiname[255];
	  char cZeile = 0;
	  int  iPos   = 0;
	  Header();
	  csr(9,2);
	  printf("Dokument öffnen: ");
	  scanf("%s", sDateiname);
	  flush();
	  csr(9,2);
	  strcat(sDateiname, ".csv");
	  FPDatei=fopen(sDateiname, "r");
	  if(FPDatei != NULL)
	  {
		  printf("Zeile suchen: ");
		  scanf("%i",&iPos);
		  flush();
		  fseek(FPDatei, 0L, SEEK_SET);
		  fseek(FPDatei, iPos,SEEK_CUR);
		  while( (cZeile=getc(FPDatei)) != EOF)
		  {
			  printf("  %c", cZeile);
		  }
	  }
	  else
	  {
		  csr(9,2);
		  printf("Sorry, kein Training vorhanden!");
		  getchar();
		  return EXIT_FAILURE;
	  }
	  fclose(FPDatei);
	  getchar();
	  return EXIT_SUCCESS;
  }

/** Funktion: Eintragn anzeigen
  * Status  : in Arbeit 
  */
  int iDaten_Ausgabe()
  {
	  FILE *FPDatei;
	  char sDateiname[FILENAME_MAX];
	  Header();
	  csr(9,2);
	  printf("Dokument öffnen: ");
	  scanf("%s",sDateiname);
	  flush();
	  strcat(sDateiname, ".csv");
	  FPDatei=fopen(sDateiname, "r");
	  if(FPDatei != NULL)
	  {
		  Header();
		  csr(9,0);
		  while(!feof(FPDatei))
		  {
			  fgets(sDateiname, FILENAME_MAX, FPDatei);
			  printf("  %s", sDateiname);
		  }
	  }
	  else
	  {
		  csr(9,2);
		  printf("Sorry, kein Training vorhanden!");
		  getchar();
		  return EXIT_FAILURE;
	  }
	  fclose(FPDatei);
	  getchar();
	  return EXIT_SUCCESS;
  }

/** Funktion: Training eingeben
  * Status  : in Arbeit 
  */
  int iDaten_Eingabe()
  {
	  struct daten stDat[50];
	  char cEingabe;
	  char sDateiname[255];
	  int k = 1;
	  FILE *FPDatei;
	  if(iCounter == 0)
	  {
		  Header();
		  Ausgabe_1();
		  csr(9,13);
		  scanf("%[^\n]", stDat[0].sName);
		  flush();
		  csr(11,13);
		  scanf("%i", &stDat[1].iAlter);
		  flush();
		  if(stDat[1].iAlter <= 0)
		  {
			  stDat[1].iAlter = 0;
		  }
		  csr(13,13);
		  scanf("%lf", &stDat[2].dGewicht);
		  flush();
		  if(stDat[2].dGewicht <= 0)
		  {
			  stDat[2].dGewicht = 0;
		  }
	  }
	  do
	  {
		  Header();
		  csr(1,31);
		  printf("%i.Trainingseinheit", k);
		  Ausgabe_2(); 
		  csr(9,20);
		  scanf("%i %*c %i %*c %i", &stDat[3].iDay, &stDat[4].iMon, &stDat[5].iYear);
		  flush();
		  if(stDat[3].iDay <= 0 || stDat[4].iMon <= 0 || stDat[5].iYear <= 0)
		  {
			  stDat[3].iDay  = 0;
			  stDat[4].iMon  = 0;
			  stDat[5].iYear = 0;
		  }
		  csr(11,20);
		  scanf("%[^\n]", stDat[6].sDisziplin);
		  flush();
		  csr(13,20);
		  scanf("%[^\n]", stDat[7].sStrecke);
		  flush();
		  csr(15,20);
		  scanf("%[^\n]", stDat[8].sWetter);
		  flush();
		  csr(17,20);
		  scanf("%lf", &stDat[9].dKM);
		  flush();
		  if(stDat[9].dKM <= 0)
		  {
			  stDat[9].dKM = 0.00;
		  }
		  csr(19,20);
		  scanf("%lf", &stDat[10].dZeit);
		  flush();
		  /* Fitnesspunkte */
		  if(stDat[10].dZeit <= 0.00)
		  {
			  stDat[10].dZeit = 0.00;
			  stDat[18].iPunkte = stDat[10].dZeit * 0;
		  }
		  if(stDat[10].dZeit >= 1.00 && stDat[10].dZeit <= 3.00 && stDat[10].dZeit != 0.00 )
		  {
			  stDat[18].iPunkte = stDat[10].dZeit * 4;
		  }
		  if(stDat[10].dZeit >= 3.00 && stDat[10].dZeit <= 6.00 && stDat[10].dZeit != 0.00 )
		  {
			  stDat[18].iPunkte = stDat[10].dZeit * 8;
		  }
		  if(stDat[10].dZeit >= 6.00 && stDat[10].dZeit <= 9.00 && stDat[10].dZeit != 0.00 )
		  {
			  stDat[18].iPunkte = stDat[10].dZeit * 20;
		  }
		  if(stDat[10].dZeit >= 9.00 && stDat[10].dZeit <= 12.00 && stDat[10].dZeit != 0.00 )
		  {
			  if(stDat[10].dZeit >= 12.00)
			  {
				  stDat[18].iPunkte = stDat[10].dZeit * 36;
			  }
		  }
		  csr(21,20);
		  scanf("%i", &stDat[11].iBorg);
		  flush();
		  if(stDat[11].iBorg == 5 || stDat[11].iBorg <= 5 || stDat[11].iBorg == 6)
		  {
			  if(stDat[11].iBorg != 6)
			  {
				  stDat[11].iBorg = 5;
			  }
			  strcpy(stDat[17].sGA, "Keine Anstrengung");
		  }
		  else if(stDat[11].iBorg == 7 || stDat[11].iBorg == 8 )
		  {
			  stDat[11].iBorg = 5;
			  strcpy(stDat[17].sGA, "Extrem Leicht");
		  }
		  else if(stDat[11].iBorg == 9 || stDat[11].iBorg == 10 )
		  {
			  stDat[11].iBorg = 5;
			  strcpy(stDat[17].sGA, "Sehr leicht");
		  }
		  else if(stDat[11].iBorg == 11 || stDat[11].iBorg == 12 )
		  {
			  stDat[11].iBorg = 5;
			  strcpy(stDat[17].sGA, "Leicht");
		  }
		  else if(stDat[11].iBorg == 13 || stDat[11].iBorg == 14 )
		  {
			  stDat[11].iBorg = 5;
			  strcpy(stDat[17].sGA, "Etwas Schwer");
		  }
		  else if(stDat[11].iBorg == 15 || stDat[11].iBorg == 16 )
		  {
			  stDat[11].iBorg = 5;
			  strcpy(stDat[17].sGA, "Schwer");
		  }
		  else if(stDat[11].iBorg == 17 || stDat[11].iBorg == 18 )
		  {
			  stDat[11].iBorg = 5;
			  strcpy(stDat[17].sGA, "Sehr Schwer");
		  }
		  else if(stDat[11].iBorg == 19 || stDat[11].iBorg == 20 || stDat[11].iBorg >= 20 )
		  {
			  if(stDat[11].iBorg != 19)
			  {
				  stDat[11].iBorg = 20;
			  }
			  strcpy(stDat[17].sGA, "Extrem Schwer");
		  }
		  Header();
		  csr(1,31);
		  printf("%i.Trainingseinheit", k);
		  csr(9,2);
		  printf("Training speichern? (j)a/(n)ein: ");
		  scanf("%c", &cEingabe);
		  flush();
		  if(cEingabe == 'j' && 'J')
		  {
			  Header();
			  csr(1,31);
			  printf("%i.Trainingseinheit", k);
			  csr(9,2);
			  printf("In Dokument speichern: ");
			  scanf("%s",sDateiname);
			  flush();
			  strcat(sDateiname, ".csv");
			  FPDatei=fopen(sDateiname, "a");
			  if(FPDatei != NULL)
			  {
				  fprintf(FPDatei,"Name..........: %s", stDat[0].sName);
				  fprintf(FPDatei,"\nAlter.........: %i", stDat[1].iAlter);
				  fprintf(FPDatei,"\nGewicht.......: %.2lf Kg", stDat[2].dGewicht);
				  fprintf(FPDatei,"\n\nTrainingseinheit vom %i.%i.%i\n", 
				  stDat[3].iDay, stDat[4].iMon, stDat[5].iYear);
				  fprintf(FPDatei,"\nDisziplin.....: %s", stDat[6].sDisziplin);
				  fprintf(FPDatei,"\nStrecke.......: %s", stDat[7].sStrecke);
				  fprintf(FPDatei,"\nWetter........: %s", stDat[8].sWetter);
				  fprintf(FPDatei,"\nDistanz.......: %.2lf Km", stDat[9].dKM);
				  fprintf(FPDatei,"\nHöhenmeter....: %.2lf %%", stDat[19].dHM=stDat[9].dKM*stDat[11].iBorg*10/100 );
				  fprintf(FPDatei,"\nFahrtzeit.....: %.2lf Std.", stDat[10].dZeit);
				  /* Berechnungen anhand der eingbn. Werte */
				  fprintf(FPDatei,"\nDurchschnitt..: %.2lf Km/h", stDat[12].dSpeed=stDat[9].dKM/stDat[10].dZeit);
				  fprintf(FPDatei,"\nTrittfrequenz.: %.2lf U/min", stDat[13].dTF=stDat[12].dSpeed*20.71);
				  fprintf(FPDatei,"\nLeistung......: %.2lf W", stDat[14].dWatt=stDat[13].dTF*(stDat[12].dSpeed/stDat[10].dZeit));
				  fprintf(FPDatei,"\nHerzfrequenz..: %.2lf/%.2lf BPM", stDat[15].dHF=stDat[11].iBorg*10, 207-0.7*stDat[1].iAlter);
				  fprintf(FPDatei,"\nKcal Verbr....: %.2lf", stDat[16].dKcal=stDat[2].dGewicht*stDat[12].dSpeed/stDat[10].dZeit);
				  fprintf(FPDatei,"\nAusdauer......: %s", stDat[17].sGA);
				  fprintf(FPDatei,"\nFitnesspunkte.: %i$", stDat[18].iPunkte);
				  fprintf(FPDatei, "\n\n");
				  fclose(FPDatei);
				  Header();
				  csr(9,2);
				  printf("Speichern erfolgreich");
				  getchar();
			  }
			  else
			  {
				  csr(9,2);
				  printf("Speichern fehlgeschlagen");
				  getchar();
			  }
		  }
		  csr(9,2);
		  printf("Neues Training hinzufügen? (j)a/(n)ein: ");
		  scanf("%c", &cEingabe);
		  flush();
		  k++;
	  }while(cEingabe != 'n' && 'n');
	  return EXIT_SUCCESS;
  }

/** Funktion: Hauptmenu
  * Status  : in Arbeit 
  */
  int iMenu()
  {
	  int iEingabe = 0;
	  char cZeile;
	  FILE *FPSCR;
	  clr();
	  FPSCR=fopen("screen", "r");
	  if(FPSCR != NULL)
	  {	  
		  fseek(FPSCR, 1,SEEK_CUR);
		  while( (cZeile=getc(FPSCR)) != '#')
		  {
			  printf("%c", cZeile);
		  }
	  }
	  fclose(FPSCR);
	  csr(15,19);
	  getchar();
	  do
	  {
		  clr();
		  FPSCR=fopen("screen", "r");
		  if(FPSCR != NULL)
		  {	  
			  fseek(FPSCR, 1042,SEEK_CUR);
			  while( (cZeile=getc(FPSCR)) != '#')
			  {
				  printf("%c", cZeile);
			  }
		  }
		  else
		  {
			  csr(9,2);
			  printf("Sorry, keine Datei vorhanden!");
			  getchar();
			  return EXIT_FAILURE;
		  }
		  fclose(FPSCR);
		  csr(19,14);
		  scanf("%i", &iEingabe);
		  flush();
		  switch(iEingabe)
		  {
			  case 1:
			  {
				  iDaten_Eingabe();
				  break;
			  }
			  case 2:
			  {
				  iDaten_Ausgabe();
				  break;
			  }
			  case 3:
			  {
				  iDaten_Suchen();
				  break;
			  }
			  case 4:
			  {
				  iDaten_Entf();
				  break;
			  }
			  case 0:
			  {
				  clr();
				  printf("\n\n\t\t      Danke für die Nutzung."
				         "\n\n\t\t      Aufwiedersehen!");
				  getchar();
				  return EXIT_SUCCESS;
				  break;
			  }
			  default:
			  {
				  clr();
				  printf("\n\n\t\t      Falsche Eingabe!");
				  getchar();
				  break;
			  }
		  }
	  }while(iEingabe != 0);
	  return EXIT_SUCCESS;
  }

/** Steuerprogramm
  */
  int iController()
  {
	  iMenu();
	  return 0;
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }
