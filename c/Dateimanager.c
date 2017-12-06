/** dateimanager.c
  * v.1.0
  * Nico Anders
  * 24.02.2011
  */

/** Präprozessor
  */
  #include	<stdio.h>
  #include	<stdlib.h>
  #include	<string.h>

/** Auswahl Menue
  */
  int iAuswahl()
  {
	  int iEingabe = 0;
	  do
	  {
          system("cls");
		  printf("\n\n\t+------------------+\n");
		  printf("\t|   Dateimanager   |\n");
		  printf("\t+------------------+\n");
		  printf("\t| <1> File anlegen |\n");
		  printf("\t| <2> File oeffnen |\n");
		  printf("\t| <3> File aendern |\n");
		  printf("\t| <4> File loeschen|\n");
		  printf("\t| <0> Prog beenden |\n");
		  printf("\t+------------------+\n");
		  printf("\t  Option waehlen: ");
		  scanf("%i", &iEingabe);
		  fflush(stdin);
		  switch(iEingabe)
		  {
			  case 1:
			  {
				  iDatei_Erzeugen();
				  break;
			  }
			  
			  case 2:
			  {
				  iDatei_aufrufen();
				  break;
			  }
			  case 0:
			  {
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

/** Textdatei erzeugen
  */
  int iDatei_Erzeugen()
  {
      system("cls");
	  char sDateiname[FILENAME_MAX];
	  size_t Laenge;
	  FILE *FPZeiger;
	  printf("\n\n\t  Einen Dateinamen eingeben: ");
	  fgets(sDateiname, FILENAME_MAX, stdin);
	  Laenge = strlen(sDateiname);
	  sDateiname[Laenge -1] = '\0';
	  FPZeiger = fopen(sDateiname, "w");
	  if(FPZeiger != NULL)
	  {
		  printf("\n\t  Datei erfolgreich angelegt\n");
		  freopen(sDateiname, "a+", stdout);
		  fgets(sDateiname, FILENAME_MAX, stdin);
		  fclose(FPZeiger);
	  }
	  else
	  {
		  printf("\n\t  Die Datei konnte nicht angelegt werden\n");
	  }
	  getchar();
	  return EXIT_SUCCESS;
  }
		
/** Textdatei oeffnen
  */
  int iDatei_aufrufen()
  {
      system("cls");
	  char sDateiname[FILENAME_MAX];
	  size_t Laenge;
	  FILE *FPZeiger;
	  printf("\n\n\t  Welche Datei soll geoeffnet werden? ");
	  fgets(sDateiname, FILENAME_MAX, stdin);
	  Laenge = strlen(sDateiname);
	  sDateiname[Laenge -1] = '\0';
	  FPZeiger = fopen(sDateiname, "r");
	  if(FPZeiger != NULL)
	  {
		  printf("\n\t  Datei zum Lesen geoeffnet\n");
		  freopen(sDateiname, "a+", stdout);
		  fgets(sDateiname, FILENAME_MAX, stdin);
		  fclose(FPZeiger);
	  }
	  else
	  {
		  printf("\n\t  Die Datei konnte nicht geoffnet werden\n");
	  }
	  getchar();
	  return EXIT_SUCCESS;
  }	

/** iController
  */
  int iController()
  {
	  iAuswahl();
	  return 0;
  }

/** main()
  */
  int main()
  {
	  iController();
	  return 0;
  }
	  
