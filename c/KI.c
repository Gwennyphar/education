/** Programm.: 
  * Autor....:
  * Version..:
  * Datum....:
  * Stand....:
  * Status...:
  * ToDo.....:
  */

/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

/** Funktion.:
  * Status...:
  */
  struct struktur
  {
	  char sInput[255];
	  int iZahlen;
  }stInteraktion;

/** Funktion.:
  * Status...:
  */
  int iKI()
  {
	  int iLoop = 0;
	  char sHallo[255] = "Hallo";
	  char sVersion[255] = "Ich bin das neue Industrix 2030";
	  printf("Input: ");
	  fgets(stInteraktion.sInput, sizeof(stInteraktion.sInput), stdin);
	  stInteraktion.sInput[strlen(stInteraktion.sInput)-1] = '\0';
	  for(iLoop = 0; iLoop < 80; iLoop++)
	  {
		  printf("=");
	  }
	  printf("\n\n");
	  printf("%s %s. %s", sHallo, stInteraktion.sInput, sVersion);
	  return EXIT_SUCCESS;
  }

/** Hauptprogramm
  */
  int iController()
  {
	  iKI();
	  return EXIT_SUCCESS;
  }
 
/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return EXIT_SUCCESS;
  }
