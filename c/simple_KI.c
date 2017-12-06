/** Programm : gluecksnuss.c
  * Autor	 : Nico Anders
  * Version  : 0.1
  * Datum    : 29.05.2011
  * Stand    : 29.05.2011
  * Status   : in Arbeit
  * ToDo     : bauen
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include <time.h>
  #define GEN "generator.txt"

/** Funktion : Tipps zufällig auslesen
  * Status   : in Arbeit
  */
  int iOntologie()
  {
	  int i      = 0;
	  int iSek   = 0;
	  char sEingabe[100];
	  char sInhalt[500][FILENAME_MAX];
	  FILE *FPLesen;
	  FILE *FPSchreiben;
	  FPLesen = fopen(GEN, "r");
	  FPSchreiben = fopen(GEN, "a");
	  printf("\n\tSuchen: ");
	  fgets(sEingabe, sizeof(sEingabe), stdin );
	  sEingabe[strlen(sEingabe)-1] = '\0';
	  printf("\n\t");
	  do
	  {
		  fgets(sInhalt[i], FILENAME_MAX, FPLesen);
		  sInhalt[i][strlen(sInhalt[i])-1] = '\0';
		  if(strcmp(sEingabe, sInhalt[i]) == 0)
		  {
			  printf("-%s", sInhalt[i]);
			  i++;
		  }
		  else if(!strcmp(sEingabe, sInhalt[i]) == 0)
		  {
			  i++;
			  srand( time(NULL) );
			  i = rand() %i;
			  while( iSek < 1 )
			  {
				  printf("%s", sInhalt[i]);
				  iSek++;
			  };
		  }
		  else
		  {
			  fseek(FPSchreiben, 0 * sizeof (sEingabe), SEEK_SET);
			  fprintf(FPSchreiben, "%s\n", sEingabe);
				  
		  }
	  }while( !feof(FPLesen) );
	  fclose(FPSchreiben);
	  fclose(FPLesen);
	  return 0;
  }
	  
/** Steuerprogramm                                                          
  */
  int iController()
  {
      iOntologie();
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
