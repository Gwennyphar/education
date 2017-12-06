/** Programm : hello_world.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  */

/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>

/** Funktion : Ausgabe mit Scanf()
  * Status	 : in Arbeit 
  */
  int iScanf_Ausgabe()
  {
	  char sAusgabe[50];
	  system("cls");
	  printf("* Scanf() *\n\n");
	  printf("1. Bitte gebe \"Hello World, ich gruesse dich!\" ein...\n");
	  scanf("%s", &sAusgabe);
	  fflush(stdin);
	  printf("\nDie Eingabe mit Scanf:\n%s\n", sAusgabe);
	  return 0;
  }

/** Funktion : Ausgabe mit puts()
  * Status	 : in Arbeit 
  */
  int iPuts_Ausgabe()
  {
	  char sAusgabe[50] = "Hello World, ich gruesse dich!";
	  system("cls");
	  printf("* puts() *\n\n");
	  puts(sAusgabe);
	  printf("\nDie Eingabe mit puts: %s\n\n", sAusgabe);
	  printf("\n");
	  return 0;
  }

/** Funktion : Ausgabe mit gets()
  * Status	 : in Arbeit 
  */
  int iGets_Ausgabe()
  {
	  char sAusgabe[50];
	  system("cls");
	  printf("* gets() *\n\n");
	  printf("Bitte gebe \"Hello World, ich gruesse dich!\" ein...\n");
	  gets(sAusgabe);
	  fflush(stdin);
	  printf("\nDie Eingabe mit gets: %s\n\n", sAusgabe);
	  return 0;
  }

/** Funktion : Ausgabe mit fgets()
  * Status	 : in Arbeit 
  */
  int iFgets_Ausgabe()
  {
	  char sAusgabe[50];
	  system("cls");
	  printf("* fgets() *\n\n");
	  printf("Bitte gebe \"Hello World, ich gruesse dich!\" ein...\n");
	  fgets(sAusgabe, 10, stdin);
	  fflush(stdin);
	  printf("\nDie Eingabe mit fgets: %s\n\n", sAusgabe);
	  return 0;
  }

/** Funktion : Auswahlmenue
  * Status	 : in Arbeit 
  */
  int iMenue()
  {
	  int iAuswahl = 0;
	  do
	  {
          system("cls");
		  printf("Hello World Ausgabe Programm\n\n");
		  printf("<1> Ausgabe mit Scanf\n");
		  printf("<2> Ausgabe mit puts\n");
		  printf("<3> Ausgabe mit gets\n");
		  printf("<4> Ausgabe mit fgets\n");
		  printf("<0> Hello World Beenden\n");
		  scanf("%i", &iAuswahl);
		  fflush(stdin);
		  switch(iAuswahl)
		  {
			  case 1:
			  {
				  iScanf_Ausgabe();
				  system("pause");
				  break;
			  }
			  case 2:
			  {
				  iPuts_Ausgabe();
				  system("pause");
				  break;
			  }
			  case 3:
			  {
				  iGets_Ausgabe();
				  system("pause");
				  break;
			  }
			  case 4:
			  {
				  iFgets_Ausgabe();
				  system("pause");
				  break;
			  }
			  case 0:
			  {
				  printf("\nAuf Wiedersehen!");
				  system("pause");
				  break;
			  }
			  default:
			  {
				  break;
			  }
		  }
	  }while(iAuswahl != 0);
	  return 0;
  }
  
/** Programmsteuerung
  * iController
  */
  int iController()
  {
	  iMenue();
	  return 0;
  }

/** Prgrammschnittstelle
  * Smain()
  */
  int main()
  {
	  iController();
	  return 0;
  }
