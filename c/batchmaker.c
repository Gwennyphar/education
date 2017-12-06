/** Programm : Bench
  * Autor	 : Nico Anders
  * Version  : 1.0 stable
  * Datum    : 13.05.2011
  * Stand    : 15.05.2011
  * Status   : in Arbeit
  * ToDo     : verbessern
  */
  
  /** Präprozessor
  * Bibliothek-Einbindung fÃ¼r Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define  DATEI "running.bat"
  #

/** Funktion : bat Datei anlegen zur Automatisierung
  * Status   : in Arbeit
  */
  int iBatcher()
  {
	  int i        = 0;
	  int j        = 0;
	  int iZahl    = 0;
	  int iEingabe = 0;
	  FILE *FPStream;
	  FPStream = fopen(DATEI, "w");
      fprintf(FPStream, "echo off");
	  printf("Eingabe>> ");
	  fflush(stdin);
	  scanf("%i", &iEingabe);
	  for( i = 1; i <= iEingabe; i++ )
	  {
  		fprintf(FPStream, "\nstart Benchmarker.exe");
		  printf("%i.Zahl>> ", i);
		  fflush(stdin);
		  scanf("%i", &iZahl);
		  for( j = 0; j <= iZahl ; j++ )
		  {
			  fprintf(FPStream, " 1 ");
		  }
	  }
	  fprintf(FPStream, "\nexit");
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
	  iBatcher();
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
