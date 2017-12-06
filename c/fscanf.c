/** Programm : .c
  * Autor	 : 
  * Version  : 0.1
  * Datum    : TT.MM.JJ
  * Stand    : TT.MM.JJ
  * Status   : in Planung
  * ToDo     :
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion : Text suchen finden ersetzen ud in neue Datei schreiben
  * Status   : in Arbeit
  */
  int iFunktion()
  {
	  int i = 0;
	  char string[80];
	  FILE* datei;
	  datei = fopen("system.c","rt");
	  if (datei==NULL)
	  {
		  printf("Datei nicht vorhanden\n");
		  exit(1);
	  }
	  for (i=0;i<6;i++) fscanf (datei,"%s",string);/* für die ersten 4 Zeilen */
	  {
		  fscanf (datei,"%79[^\n]",string); /* das wäre dann die 5.te Zeile der Datei. */
		  printf("%s", string);
	  }
	  return 0;
  }
 
/** Steuerprogramm                                                          
  */
  int iController()
  {
      iFunktion();
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
