/** Programm : Bildschirm_loeschen.c
  * Autor	 : Nico Anders
  * Version  : 0.1
  * Datum    : 04.07.2011
  * Stand    : 04.07.2011
  * Status   : Fertig
  * ToDo     : ______
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>  /* Standard-I/O */
  #include <time.h>   /* Datum und Uhrzeit */


/** Funktion :
  * Status   :
  */
  void iSequenz()
  {
	  printf("\x1B[2J");
  }
  
/** Funktion :
  * Status   :
  */
  void iGoto( int x, int y )
  {
	  printf("\x1B[%iH;%iH", y, x);
  }
 
/** Funktion :
  * Status   :
  */
  int main(void)
  {
	  int i = 0;
	  time_t start;
	  iSequenz();
	  for( i = 80; i >= 1; i-- )
	  {
		  iGoto( i, 12 );
		  printf("%c", '*');
		  time(&start);
		  while(difftime(time(NULL), start) < 1 );
		  iGoto( i, 12 );
		  printf("%c", ' ');
	  }
	  return 0;
  }

/** Programmende
  */
