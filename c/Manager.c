/** Proramm : adressbuch.c
  * Autor   : Nico Anders
  * Version : 1.0 stable
  * Status  : in Arbeit
  */

/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include "./mylib.h"

/** Prototyp
  */
  int iEingabe();
  int iMenu();

/** struct
  */
  struct container
  {
	  char sBez[255];
      char sPass[255];
   }stTresor;

/** Funktion: Passwörter löschen
  * Status  : in Arbeit 
  */
  int iDelete()
  {
	  int iPin;
	  int iLock = 63483;
	  int iCount = 3;
	  clr();
	  InOut();
	  while(1)
	  {
		  csr(15,20);
		  printf("                                             ");
		  csr(15,20);
		  printf("Geben Sie bitte ihre Pin ein. ");
		  csr(12,20);
		  printf("Eingabe.......: ");
		  csr(12,36);
		  scanf( "%i", &iPin);
		  flush();
		  if(iPin == iLock)
		  {
			  if(remove("safe.bin") != 0)
			  {
				  csr(15,20);
				  printf("Sorry, keine Passwörter vorhanden!");
				  wait();
				  return EXIT_FAILURE;
			  }
			  else
			  {
				  remove("safe.bin");
				  csr(15,20);
				  printf("Passwörter erfolgreich gelöscht!");
				  wait();
				  return EXIT_SUCCESS;
			  }
		  }
		  else if(iPin != iLock)
		  {
			  iCount--;
			  csr(15,20);
			  printf("Falsche Pin. Sie haben noch %i Versuche.", iCount);
			  wait();
			  if(iCount == 0)
			  {
				  iMenu();
			  }
		  }
	  }  
	  return EXIT_SUCCESS;
  }

/** Funktion : Eingaben wiederholen
  * Status   : in Arbeit
  */
  int iReverse()
  {
	  char cEingabe = 0;
	  do
      {
		  
		  csr(15,20);
		  printf("Möchten Sie Weitere eingeben? (j)a/(n)ein.");
		  csr(12,20);
		  printf("Eingabe.......:");
		  csr(12,36);
		  scanf("%c", &cEingabe);
		  flush();
		  switch(cEingabe)
		  {
			  case 'J':
			  case 'j':
			  {
				  iEingabe();
				  break;
			  }
			  case 'N':
			  case 'n':
			  {
				  iMenu();
				  break;
			  }
			  default:
			  {
				  csr(15,20);
				  printf("Upps, falsche Taste! Versuchen Sie es erneut.");
				  wait();
				  break;
			  }
		  }
	  }while(cEingabe != 'N' && 'n');
	  wait();
	  return EXIT_SUCCESS;
  }  


/** erfasste Eingaben speichern
  */
  int iSpeichern()
  {
	  char cEingabe = 0;
	  FILE *FPSpeichern;
	  do
	  {
		  csr(15,20);
		  printf("                                            ");
		  csr(15,20);
		  printf("Möchten Sie Speichern? (j)a/(n)ein.");
		  csr(12,20);
		  printf("Eingabe.......: ");
		  csr(12,36);
		  scanf("%c", &cEingabe);
		  flush();
		  switch(cEingabe)
		  {
			  case 'J':
			  case 'j':
			  {
				  FPSpeichern=fopen("safe.bin","r+b");
				  if( NULL == FPSpeichern)
				  {
					  FPSpeichern = fopen("safe.bin","w+b");
					  if( NULL == FPSpeichern )
					  {
						  fprintf(stderr, "Kann \"safe.bin\" nicht oeffnen!\n");
						  exit (0);
					  }
				  }
				  /* Datei-Zeiger FPSpeichern auf das Ende der Datei setzen */
				  fseek(FPSpeichern, 0, SEEK_END);
				  /* Wir schreiben eine Adresse ans Ende von "safe.bin" */
				  if(fwrite(&stTresor, sizeof(stTresor), 1, FPSpeichern) != 1)
				  {
					  fprintf(stderr,"Fehler bei fwrite...!!!\n");
					  exit (1);
				  }
				  /* Wir geben unseren Datei-Zeiger wieder frei */
				  fclose(FPSpeichern);
			  }
			  case 'N':
			  case 'n':
			  {
				  //iReverse();
			  }
			  default:
			  {
				  csr(15,20);
				  printf("Upps, falsche Taste! Versuchen Sie es erneut.");
				  wait();
				  break;
			  }
		  }
	  }while(cEingabe != 'N' && 'n');
	  return 0;
  }
  
/** Daten erfassen
  */
  int iEingabe()
  { 
      clr();
      InOut();
	  //printf("Bezeichnung....: ");
	  csr(6,36);
	  fgets(stTresor.sBez, sizeof(stTresor.sBez), stdin);
	  //printf("Passwort.......: ");
	  csr(8,36);
	  fgets(stTresor.sPass, sizeof(stTresor.sPass),stdin);
	  iSpeichern();
	  return 0;
  }
  
/** Daten aus Datei lesen
  */
  int iAusgabe()
  {
	  FILE *FPLesen;
      FPLesen = fopen("safe.bin","r+b");
      if( NULL == FPLesen )
      {
		  csr(15,20);
		  fprintf(stderr, "Sorry, keine Passwörter vorhanden!");
          wait();
          return EXIT_FAILURE;
      }
    /*Wir lesen alle Adressen aus "adressen.dat"*/
      while( fread(&stTresor, sizeof(stTresor), 1, FPLesen) ==1)
      {
		  printf("Bezeichnung....: %s", stTresor.sBez);
          printf("Passwort.......: %s", stTresor.sPass);
          printf("\n\n");
      }
      fclose(FPLesen);
      return 0;
  }

/** Hauptmenue
  */
  int iMenu()
  {
	  char iWahl = 0;
	  do
	  {
          clr();
          Screen();
          csr(15,20);
          printf("Was möchten Sie tun? Wählen Sie ihre Option.");
          csr(12,31);
		  scanf("%c",&iWahl);
		  flush();
		  switch(iWahl)
		  {
			  case '1':
			  {
				  iEingabe();
                  break;
			  }
              case '2':
              {
				  iAusgabe();
				  break;
			  }
			  case '3':
              {
				  printf("...Programm wird beendet\n");
                  break;
			  }
			  case '0':
              {
                 return EXIT_SUCCESS;
                 break;
              }
              default:
              {
				  csr(15,20);
                  printf("Upps, falsche Taste! Versuchen Sie es erneut.");
                  csr(12,31);
                  wait();
			  }
           }
      }while(iWahl != 3);
      return 0;
  }

/** Funktion: Login
  * Status  : in Arbeit 
  */
  int iLogin()
  {
	  int iPin;
	  int iLock = 3214;
	  int iCount = 3;
	  clr();
	  Screen();
	  while(1)
	  {
		  csr(4,16);
		  printf("   ");
		  csr(6,16);
		  printf("   ");
		  csr(8,16);
		  printf("   ");
		  csr(15,20);
		  printf("   ");
		  csr(15,20);
		  printf("Geben Sie bitte Ihr Kennwort ein.");
		  csr(12,29);
		  scanf( "%i", &iPin);
		  flush();
		  if(iPin == 0)
		  {
			  csr(15,20);
			  printf("Vielen Dank, Auf Wiedersehen!                  ");
			  csr(15,49);
			  wait();
			  return EXIT_SUCCESS;
		  }
		  
		  if(iPin == iLock)
		  {
			  iMenu();
		  }
		  else if(iPin != iLock)
		  {
			  iCount--;
			  csr(15,20);
			  printf("Falsches Kennwort. Sie haben noch %i Versuche.", iCount);
			  wait();
			  if(iCount == 0)
			  {
				  return EXIT_SUCCESS;
			  }
			  else if(iPin == 0)
			  {
				  csr(15,20);
				  printf("Vielen Dank, Auf Wiedersehen!");
			  } 
		  }
	  }  
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
