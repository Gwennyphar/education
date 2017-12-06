/** programm : poseidon.c
  * autor    : nico anders
  * datum	 : 03.05.2011
  * stand	 : 11.08.2011
  * version	 : 1.3 stable
  * status	 : in Arbeit 	 
  */ 

/** Praeprozessor
  */ 
  #include <stdio.h>                  /* Standard input output              */
  #include <stdlib.h>                 /* Standard Bibliothek                */
  #include <sys/types.h>              /* Linux/UNIX                         */
  #include <sys/stat.h>               /* für den Befehl mkdir und Attribute */
  #include <unistd.h>                 /* für den Befehl chdir               */
  #include <termios.h>                /* Terminal I/O Interface             */
  #define  DATEI ".ecryptfs"          /* vordefinierte Textdatei            */
  #define  F_MAX FILENAME_MAX         /* maximale Dateilänge                */
  #define  MODUS ,0711)               /* vordefinierte Zugriffsrechte       */
  #define  clear_Screen() printf("\033[1J\033[1;1H") /* Ansi Steuersequenz; */
  #define  HILFE ".readme"
  #define  AUTOR "Nico Anders"
  #define  VERSION "1.3 stable"
  #define  DATUM "11.08.2011"
  #define  PATENT "GPL ©2011-2012"

/** global Anweisung
  */
  FILE *FPStream;                  /* deklarierter Dateizeiger              */
  unsigned long size;              /* nicht festgelegte Zeichenlänge        */
  char sPfad[F_MAX];               /* öffne und lösche existierende Dateien */
  char sDatei[F_MAX];              /* schreibe und kopiere neue Textdateien */
  char sEingabe;                   /* Variable sEingabe für scanf           */
  int  x = 0;
  
/** Prototypen
  */
  int iDatei_erstellen();
  int iDatei_oeffnen();
  int iDatei_umbenennen();
  int iDatei_wipen();
  int iHilfe_anzeigen();
  int iInfo_anzeigen();
  int iMenue();
  int iRoot();
  int iController();

/** Eigene Funktion als Ersatz fuer getch() mit tcsetattr()
  */
  int c() 
  {
	  static int get = -1, fd = 0;
	  struct termios neu, alt;
	  fd = fileno(stdin);
	  tcgetattr(fd, &alt);
	  neu = alt;
	  neu.c_lflag &= ~(ICANON|ECHO);
	  tcsetattr(fd, TCSANOW, &neu);
	  get = getchar();
	  tcsetattr(fd, TCSANOW, &alt);
	  return get;
  }

/** Ausgabeanweisung für Programmkopf
  */
  int iScreen()
  {
	  printf(" ______________________________________________________________________________");
	  printf("\n(                              Poseidon PassPhraser                            )");
	  printf("\n| __<Q>___<Esc>___________________for_GNU/Linux_______________________________ |");
	  printf("\n||                                                                            ||");
	  printf("\n||______   _______   _______   _______  _________  ______    _______   _      ||");
	  printf("\n(  ____ ) (  ___  ) (  ____ \\ (  ____ \\ \\__   __/ (  __  \\  (  ___  ) ( (    /||");
	  printf("\n| (    )| | (   ) | | (    \\/ | (    \\/    ) (    | (  \\  ) | (   ) | |  \\  ( ||");
	  printf("\n| (____)| | |   | | | (_____  | (__        | |    | |   ) | | |   | | |   \\ | ||");
	  printf("\n|  _____) | |   | | (_____  ) |  __)       | |    | |   | | | |   | | | (\\ \\) ||");
	  printf("\n| (       | |   | |       ) | | (          | |    | |   ) | | |   | | | | \\   ||");
	  printf("\n| )       | (___) | /\\____) | | (____/\\ ___) (___ | (__/  ) | (___) | | )  \\  ||");
	  printf("\n|/        (_______) \\_______) (_______/ \\_______/ (______/  (_______) |/    )_)|");
	  printf("\n||                                                                            ||");
	  printf("\n||____________________________________________________________________________||");
	  printf("\n| ____________________________________________________________________________ |");
	  printf("\n||           )\\ )               )\\ )    )                                     ||");
	  printf("\n||           /(_))( /(  (   (   /(_)))\\()) )(   ( /(  (    ))\\  )(            ||");
	  printf("\n||          (_))  )(_)) )\\  )\\ (_)) ((_)\\ (()\\  )(_)) )\\  /((_)(()\\           ||");
	  printf("\n||          | _ \\((_)_ ((_)((_)| _ \\| |(_) ((_)((_)_ ((_)(_))   ((_)          ||");
	  printf("\n||          |  _// _` |(_-<(_-<|  _/| ' \\ | '_|/ _` |(_-</ -_) | '_|          ||");
	  printf("\n||          |_|  \\__,_|/__//__/|_|  |_||_||_|  \\__,_|/__/\\___| |_|            ||");
	  printf("\n||____________________________________________________________________________||");
	  return EXIT_SUCCESS;
  }

/** Datei erstellen
  */
  int iDatei_erstellen()
  {
	  clear_Screen();
	  iScreen();
   /* Textdatei im Verzeichnis erstellen */
   	  printf("\n(_______Wie_soll_die_Datei_heißen?_____________________________________________)");
	  printf("\n\t");
	  fflush(stdin);
	  scanf("%s",sPfad);
	  FPStream = fopen(sPfad, "w+b");
	  if( FPStream == NULL )
	  {

		  fprintf(stderr, "\tFehler beim Erstellen von '%s'!", sPfad);
		  sEingabe = c();
		  usleep(1000000);
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  printf("\tAnlegen von '%s' erfolgreich!", sPfad);
		  printf("\n\t");
		  printf("Bitte geben Sie unten ihr User-Passwort ein.");
		  printf("\n");
	   /* Systembefehl für ecryptfs */
		  system("ecryptfs-unwrap-passphrase");
		  printf("\tBitte tragen Sie ihre Passphrase hier ein: ");
		  fflush(stdin);
		  scanf("%s", sDatei);
		  fwrite(sDatei, 1, F_MAX, FPStream);
		  fclose(FPStream);
	  }
	  sEingabe = c();
	  return EXIT_SUCCESS;
  }
  
/** Datei öffnen und lesen
  */
  int iDatei_oeffnen() 
  {
	  clear_Screen();
	  iScreen();
	  printf("\n(_______Welche_Datei_möchten_Sie öffnen?_______________________________________)");
	  printf("\n\t");
	  fflush(stdin);
	  scanf("%s", sPfad);
	  FPStream = fopen( sPfad, "rb" );
	  if( FPStream == NULL )
	  {
		  fprintf(stderr, "\tFehler beim Öffnen von '%s'!", sPfad);
		  sEingabe = c();
		  usleep(1000000);
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  fread(sDatei, 1, F_MAX, FPStream);
		  printf("\tIhre Passphrase lautet: %s", sDatei);
		  fclose(FPStream);
		  sEingabe = c();
	  }
	  sEingabe = c();
	  return EXIT_SUCCESS;
  }

/** Datei öffnen und umbenennen
  */ 
  int iDatei_umbenennen()
  {
	  clear_Screen();
	  iScreen();
	  printf("\n(_______Welche_Datei_möchten_Sie_umbenennnen?__________________________________)");
	  printf("\n\t");
	  fflush(stdin);
	  scanf("%s",sPfad);
	  printf("\tWie soll die Datei heißen? ");
	  fflush(stdin);
	  scanf("%s",sDatei);
	  if( rename(sPfad,sDatei) != 0 )
	  {
		  fprintf(stderr, "\tFehler beim Umbenennen von '%s'!", sPfad);
		  sEingabe = c();
		  usleep(1000000);
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  printf("\tUmbenennen von '%s' in '%s' erfolgreich!", sPfad, sDatei);
		  sEingabe = c();
	  }
	  sEingabe = c();
	  return EXIT_SUCCESS;
  }
  
/** Datei wipen und restlos entfernen
  */
  int iDatei_wipen()
  {
	  clear_Screen();
	  iScreen();
	  printf("\n(_______Welche_Datei_möchten_Sie_löschen?______________________________________)");
	  printf("\n\t");
	  fflush(stdin);
	  scanf("%s",sPfad);
	  if( remove(sPfad) != 0 )
	  {
		  fprintf(stderr, "\tFehler beim Löschen von '%s'!", sPfad);
		  sEingabe = c();
		  usleep(1000000);
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  FPStream = fopen(sPfad, "w+b");
		  if( FPStream != NULL )
		  {
			  fseek(FPStream, 0L, SEEK_END);
		   /* Stream an das Dateiende */
			  size=ftell(FPStream);
		   /* Größe in Bytes ermitteln */
			  fwrite((char *) "\0", 1, size, FPStream);
		   /* Kompletten Inhalt mit Nullen überschreiben */
			  fclose(FPStream);
		   /* damit die Datei gelöscht werden kann, schließen */
			  remove(sPfad);                     /* weg damit */
			  printf("\tLöschen von '%s' erfolgreich!", sPfad);
			  sEingabe = c();

		  }
	  }
	  sEingabe = c();
	  return EXIT_SUCCESS;
  }

/** Funktion : Hilfe und Progamminformationen anzeigen                                                                      
  */
  int iHilfe_anzeigen()
  {
	  FPStream = fopen(HILFE, "r");
	  clear_Screen();
	  if(!FPStream)
	  {
		  clear_Screen();
		  iScreen();
		  printf("\n(_______Tut_uns_leid, keine Hilfe vorhanden!___________________________________)");
		  fprintf(stderr, "\tFehler beim Öffnen von %s!\r", HILFE);
          sEingabe = c();
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  fgets(sDatei, F_MAX, FPStream);
		  do
		  {
			  printf("%s", sDatei);
			  fgets(sDatei, F_MAX, FPStream);
		  }while(!feof(FPStream));
	  }
	  fclose(FPStream);
	  sEingabe = c();
	  return EXIT_SUCCESS;
  }
  
/** Über das Programm
  */
  int iInfo_anzeigen()
  {
	  clear_Screen();
	  printf(" ______________________________________________________________________________");
	  printf("\n(                              Poseidon PassPhraser                            )");
	  printf("\n| __<Q>___<Esc>___________________for_GNU/Linux_______________________________ |");;
	  printf("\n||                                                                            ||");
	  printf("\n||                                                                            ||");
	  printf("\n||\t\t\t\tAutor     : %s                       ||", AUTOR);
	  printf("\n||                                                                            ||");
	  printf("\n||\t\t\t\tVersion   : %s                        ||", VERSION);
	  printf("\n||                                                                            ||");
	  printf("\n||\t\t\t\tDatum     : %s                        ||", DATUM );
	  printf("\n||                                                                            ||");
	  printf("\n||\t\t\t\tCopyright : %s                    ||", PATENT);
	  printf("\n||                                                                            ||");
	  printf("\n||____________________________________________________________________________||");
	  printf("\n| ____________________________________________________________________________ |");
	  printf("\n||           )\\ )               )\\ )    )                                     ||");
	  printf("\n||           /(_))( /(  (   (   /(_)))\\()) )(   ( /(  (    ))\\  )(            ||");
	  printf("\n||          (_))  )(_)) )\\  )\\ (_)) ((_)\\ (()\\  )(_)) )\\  /((_)(()\\           ||");
	  printf("\n||          | _ \\((_)_ ((_)((_)| _ \\| |(_) ((_)((_)_ ((_)(_))   ((_)          ||");
	  printf("\n||          |  _// _` |(_-<(_-<|  _/| ' \\ | '_|/ _` |(_-</ -_) | '_|          ||");
	  printf("\n||          |_|  \\__,_|/__//__/|_|  |_||_||_|  \\__,_|/__/\\___| |_|            ||");
	  printf("\n||____________________________________________________________________________||");
	  printf("\n(_______________________Weiter_mit_beliebiger_Taste!___________________________)");
	  sEingabe = c();
	  return EXIT_SUCCESS;
  }

/** Menüauswahl
  */ 
  int iMenue()
  {
	  do
	  {
		  clear_Screen();
		  printf(" ______________________________________________________________________________");
		  printf("\n(                              Poseidon PassPhraser                            )");
		  printf("\n| __<Q>___<Esc>___________________for_GNU/Linux_______________________________ |");
		  printf("\n||                                                                            ||");
		  printf("\n||                                                                            ||");
		  printf("\n||\t\t\t\t<1> Passphrase Speichern                      ||");
		  printf("\n||                                                                            ||");
		  printf("\n||\t\t\t\t<2> Passphrase Öffnen                         ||");
		  printf("\n||                                                                            ||");
		  printf("\n||\t\t\t\t<3> Passphrase Sichern                        ||");
		  printf("\n||                                                                            ||");
		  printf("\n||\t\t\t\t<W> Passphrase Löschen                        ||");
		  printf("\n||                                                                            ||");
		  printf("\n||____________________________________________________________________________||");
		  printf("\n| ____________________________________________________________________________ |");
		  printf("\n||                                                                            ||");
		  printf("\n||                                                                            ||");
		  printf("\n||\t\t\t\t<H> Hilfeseite Lesen                          ||");
		  printf("\n||                                                                            ||");
		  printf("\n||\t\t\t\t<I> Poseidon - Version                        ||");
		  printf("\n||                                                                            ||");
		  printf("\n||____________________________________________________________________________||");
		  printf("\n(_______________________________<<__Ihre_Auswahl:___>>_________________________)");
	  /*  Ansi Steuersequenz zum Cursor links einrücken*/  
		  while( x < 30 )
		  {
			  x++;
			  printf("\033[D");
		  }  
		  sEingabe = c();
		  switch( sEingabe )
		  {
			  case '1':
			  {
				  iDatei_erstellen();
				  break;
			  }
			  case '2':
			  {
				  iDatei_oeffnen();
				  break;
			  }
			  case '3':
			  {
				  iDatei_umbenennen();
				  break;
			  }
			  case 'w':
			  {
				  iDatei_wipen();
				  break;
			  }
			  case 'h':
			  {
				  iHilfe_anzeigen();
				  break;
			  }
			  case 'i':
			  {
				  iInfo_anzeigen();
				  break;
			  }
			  case 'q':
			  {
				  system("exit");
				  break;
			  }
			  case 27:
			  {
				  system("sudo -k");
				  iRoot();
				  break;
			  }
			  default:
			  {
				  break;
			  }
		}
	}while( sEingabe != 'q' );
	return 0;
}

/** Root
  */
  int iRoot()
  {
	  clear_Screen();
	  iScreen();
	  printf("\n(_______________________Bitte_melden_Sie_sich_mit_ihrem_User-Passwort_an!______)");                       ; 
	  printf("\n");
	  system("sudo -v");   /* Systembefehl für Superuser */
	  if("sudo -v" != NULL )
	  {
		  iMenue();
		  return EXIT_SUCCESS;
	  }
	  else
	  {
		  printf("\tZUGRIFF VERWEIGERT!\n");
		  return EXIT_FAILURE;
	  }
	  return EXIT_SUCCESS;
  }

/** Steuerprogramm
  */
  int iController()
  {
	  iRoot();
	  return 0;
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }
