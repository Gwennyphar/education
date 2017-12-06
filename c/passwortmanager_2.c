/** Programm : passwortgenerator.c
  * Autor	 : Nico Anders
  * Version  : 1.0 stable
  * Datum    : 02.05.2011
  * Stand    : 02.05.2011
  * Status   : Fertig
  * ToDo     : erweitern
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define ZAHLEN 100
  #define DATEI "save.bin"
  #define ZEICHEN "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwiyz!$&=?*#"

int iPasswort_erzeugen();

struct
{
	char sName[45];
	char sPass[12];
	char sFeld[12];
}stEingaben[5];


/** Funktion : Speichern
  * Status   : in Arbeit
  */
  int iSchluessel_speichern()
  {
	  FILE *FPZeiger;
	  FPZeiger = fopen(DATEI, "ab");
	  fclose(FPZeiger);
	  return 0;
  }

/** Funktion : Eingabe
  * Status   : in Arbeit
  */
  int iSchluessel_eingeben()
  {
	  int i = 0;
	  int iDurchlauf = 0;
	  char cEingabe = 0;
	  printf("Durchlauf: ");
	  scanf("%i", &iDurchlauf);
	  for(i = 0; i < iDurchlauf; i++)
	  {
		  printf("Benutzername..: ");
		  scanf("%s", &stEingaben[1].sName[45]);
		  printf("automatisches Passwort? ja/nein ");
		  scanf("%s", &cEingabe);
		  if(cEingabe == 'j' || 'J')
		  {
			  iPasswort_erzeugen();
		  }
		  else if(cEingabe == 'n' || 'N')
		  {
			  printf("Passwort......: ");
			  scanf("%s", &stEingaben[2].sPass[12]);
		  }
		  else
		  {
			  printf("Keine Funktion!");
			  getchar();
		  }
	  }
	  printf("Eingaben speichern? ja/nein ");
	  scanf("%s", &cEingabe);
	  if(cEingabe == 'j' || 'J')
	  {
		  iSchluessel_speichern();
	  }
	  else if(cEingabe == 'n' || 'N')
	  {
		  return EXIT_SUCCESS;
	  }
	  else
	  {
		  printf("Keine Funktion!");
		  getchar();
	  }
	  return 0;
  }

/** Funktion : Passwort erzeugen
  * Status   : in Arbeit
  */
  int iPasswort_erzeugen()
  {
	  int  i = 0;
   	  char sBuchstaben[69] = ZEICHEN;
   	  srand(time(NULL));   	  
   	  for(i = 0; i < 12; i++)
   	  {
		  stEingaben[3].sFeld[i] = sBuchstaben[(rand() % 69+1)];
	  }
	  printf("Passwort......: %s", stEingaben[3].sFeld);
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iSchluessel_eingeben();
	  return 0; /* Sprung-Anweisung */
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }

/** Programmende
  */
