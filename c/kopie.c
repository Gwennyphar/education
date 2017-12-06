/** Programm :
  * Autor	 :
  * Version  :
  * Datum    :
  * Stand    :
  * Status   :
  * ToDo     :
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>

/** Funktion :
  * Status   : in Arbeit
  */
  int iKopie()
  {
	  FILE *FPEingabe, *FPAusgabe;    /* Filepointer */
	  char sPuffer[FILENAME_MAX];     /* Zeilenpuffer */
	  char sPfad[FILENAME_MAX];
   /* Eingabedatei öffnen */
      FPEingabe = fopen("test.txt", "r");

   /* Ausgabedatei öffnen */
      printf("Datei anlegen: ");
      fflush(stdin);
      scanf("%s", sPfad);
      FPAusgabe = fopen(sPfad, "w");

   /* Zeilenweise lesen und schreiben */
      while (fgets(sPuffer, sizeof(sPuffer), FPEingabe))
      fputs(sPuffer, FPAusgabe);

   /* Files schliessen und Ende */
      fclose(FPEingabe);
      fclose(FPAusgabe);
      return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iKopie();
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
