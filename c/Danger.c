/** Programm : Syslogger Achtung: Bitte nicht ausführen!!!
  * Autor	 : Nico Anders
  * Version  : 0.1
  * Datum    : 12.06.2011
  * Stand    : 12.06.2011
  * Status   : Fertig
  * ToDo     : Nicht ausführen Schleife müllt /var zu
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <math.h>
  #include <time.h>
  #include <syslog.h>

/** Funktion : füllt das Verzeichnis mit Protokollen
  * Status   : in Arbeit
  */
  int iSys( int argc, char* argv[] )
  {
	  int i;
	  while (1)
	  {
		  if( i++ >= 1 )
		  {
			  i = 0;
			  syslog(LOG_ALERT, "..:: we are flooding the log, attempt #%i ::..", i);
		  }
	  }
	  return 0;
  }

/** Funktion : füllt das Verzeichnis mit Protokollen
  * Status   : in Arbeit
  */
  int iLogin(int argc, char *argv[])
  {
	  char buffer_password_insert[34];
	  char buffer_password_correct[34] = "$ecr3t";
	  strcpy(buffer_password_insert, argv[1]);
	  if(strcmp(buffer_password_insert,buffer_password_correct))
	  {
		  printf("Falsches Passwort\n");
		  printf("Programm wird beendet\n");
		  printf("---------------------\n\n");
	  }
	  else
	  {
		  printf("Richtiges Passwort\n");
		  printf("Programm startet sensiblen Aktion\n");
		  printf("---------------------\n\n");
		  iSys(argc, argv);
	  }
	  fgetc(stdin);
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController(  int argc, char* argv[]  )
  {
      iLogin(argc, argv);
	  return 0; /* Sprung-Anweisung */
  }

/** Hauptprogramm
  */
  int main( int argc, char* argv[] )
  {
	  iController( argc, argv );
	  return 0;
  }

/** Programmende
  */
