/** Programm : diff.c
  * Autor	 : Nico Anders
  * Version  : 0.1
  * Datum    : 08.10.2011
  * Stand    : 08.10.2011
  * Status   : in Arbeit
  * ToDo     :
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>

/** Funktion : Vergleichen auf Inhalt zweier Dateien
  * Status   : in Arbeit
  */
  int main( int argc, char *argv[])
  {
	  FILE *FPEins, *FPZwei; /* Vergleiche 2 Dateien */
	  unsigned long int iPosition; /* akt. Pos. i.d. Datei */
	  int iErstes, iZweites; /* Zeichen aus 1. und 2. Datei */
	  if( argc !=3 )
	  {
		  printf("\nFalsche Anzahl Parameter!");
		  printf("\nBitte zu vergleichende Dateien angeben");
		  exit(1);
	  }
	  if(( FPEins = fopen(argv[1], "rb") ) == NULL)
	  {
		  printf("\nDatei %s nicht gefunden!", argv[1]);
		  exit(2);
	  }
	  if(( FPZwei = fopen(argv[2], "rb") ) == NULL)
	  {
		  printf("\nDatei %s nicht gefunden!", argv[2]);
		  exit(3);
	  }
	  printf("\n\nVerglichen wird '%s' mit '%s'.", argv[1], argv[2]);
	  iPosition = 1;
	  iErstes = fgetc(FPEins);
	  iZweites = fgetc(FPZwei);
	  while( iErstes == iZweites && !feof(FPEins) && !feof(FPZwei))
	  {
		  iPosition++;
		  iErstes = fgetc(FPEins);
		  iZweites = fgetc(FPZwei);
	  }
	  if(iErstes != iZweites)
	  {
		  printf("\nUnterschied beim %li Zeichen.\a", iPosition);
	  }
	  else
	  {
		  printf("\nVergleich ok!\a");
	  }
	  fclose(FPEins);
	  return 0;
  }



/** Programmende
  */
