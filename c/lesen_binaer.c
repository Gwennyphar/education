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
  void iKopf()
  {
	  system("clear");
	  printf("\n\t\t Lesen Sie ihren Text\n");
	  printf("\t\t________________________\n\n\t\t");  
  }

/** Funktion.:
  * Status...:
  */
  int iText_lesen()
  {
	  char sText[FILENAME_MAX];
	  FILE *FPDatei;
	  FPDatei = fopen("./screen.bin", "rb");
	  iKopf();
	  if(FPDatei != NULL)
	  {
		  iKopf();
		  while(!feof(FPDatei))
		  {
			  fread(sText, 1, FILENAME_MAX, FPDatei);
			  printf("%s", sText);
		  }	  
	  }
	  else
	  {
		  iKopf();
		  printf("Datei ist fehlerhaft");
		  getchar();
		  return EXIT_SUCCESS;
	  }
	  fclose(FPDatei);
	  getchar();
	  return 0;
  }

/** Hauptprogramm
  */
  int iController()
  {
	  iText_lesen();
	  return 0;
  }
 
/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }
