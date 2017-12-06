/** programm : ubuntu-passwortmanager.c
  * autor    : nico anders
  * datum	 : 03.05.2011
  * version	 : 1.1 stable
  * status	 : in arbeit 	 
  */ 

/** Praeprozessor
  */ 
  #include <stdio.h>            /* Standard input output              */
  #include <stdlib.h>           /* Standard Bibliothek                */
  #include <sys/types.h>        /* Linux/UNIX                         */
  #include <sys/stat.h>         /* für den Befehl mkdir und Attribute */
  #include <unistd.h>           /* für den Befehl chdir               */
  #define  DATEI ".ecryptfs"    /* vordefinierte Textdatei            */
  #define  F_MAX FILENAME_MAX   /* maximale Dateilänge                */
  #define  MODUS ,0711)         /* vordefinierte Zugriffsrechte       */
  #define  clr() system("clear")  

/** global Anweisung
  */
  FILE *FPStream;            /* deklarierter Dateizeiger              */
  unsigned long size;        /* nicht festgelegte Zeichenlänge        */
  char sPfad[F_MAX];         /* öffne und lösche existierende Dateien */
  char sDatei[F_MAX];        /* schreibe und kopiere neue Textdateien */
  char sEingabe;             /* Variable sEingabe für scanf           */
  int i;                     /* Schleifenvariable zur Ausgabe löschen */
  
/** Prototypen
  */
  int iDatei_erstellen();
  int iDatei_oeffnen();
  int iDatei_umbenennen();
  int iDatei_wipen();
  int iMenue();
  int iRoot();
  int iController();

/** Datei erstellen
  */
  int iDatei_erstellen()
  {
	  for( i = 0; i < 50; i++ )
	  {
		  clr();
	  }
   /* Textdatei im Verzeichnis erstellen */
	  printf("\nWie soll die Datei heissen? ");
	  fflush(stdin);
	  scanf("%s",sPfad);
	  FPStream = fopen(sPfad, "w+b");
	  if( FPStream == NULL )
	  {
		  fprintf(stderr, "Kann neue Datei '%s' nicht erstellen\n", sPfad);
		  usleep(1000000);
	  }
	  else
	  {
		  printf("Neue Datei %s erstellt", sPfad);
		  printf("\n");
		  printf("ecryptfs-unwrap-passphrase  \n");
		  printf("____________________________\n");
		  printf("Geben Sie die Passphrase ein: ");
		  fflush(stdin);
		  scanf("%s", sDatei);
		  fwrite(sDatei, 1, F_MAX, FPStream);
		  fclose(FPStream);
	  }
	  fflush(stdin);
	  getchar();
	  return EXIT_SUCCESS;
  }
  
/** Datei öffnen und lesen
  */
  int iDatei_oeffnen() 
  {
	  for( i = 0; i < 50; i++ )
	  {
		  clr();
	  }
	  printf("\nWelche Datei möchten Sie öffnen? ");
	  fflush(stdin);
	  scanf("%s", sPfad);
	  FPStream = fopen( sPfad, "rb" );
	  if( FPStream == NULL )
	  {
		  fprintf(stderr, "Fehler beim Öffnen von '%s'", sPfad);
		  usleep(1000000);
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  fread(sDatei, 1, F_MAX, FPStream);
		  printf("Die Passphrase ist: %s", sDatei);
		  fclose(FPStream);
	  }
	  fflush(stdin);
	  getchar();
	  return EXIT_SUCCESS;
  }

/** Datei öffnen und umbenennen
  */ 
  int iDatei_umbenennen()
  {
	  for( i = 0; i < 50; i++ )
	  {
		  clr();
	  }
	  system("clear");
	  printf("\n");
	  printf("Welche Datei möchten Sie umbenennen : ");
	  fflush(stdin);
	  scanf("%s",sPfad);
	  printf("Wie soll die Datei heissen: ");
	  fflush(stdin);
	  scanf("%s",sDatei);
	  if( rename(sPfad,sDatei) != 0 )
	  {
		  fprintf(stderr, "Fehler beim Umbenennen von '%s'", sPfad);
		  usleep(1000000);
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  printf("Datei wurde von '%s' in '%s' umbenannt", sPfad, sDatei);
	  }
	  fflush(stdin);
	  getchar();
	  return EXIT_SUCCESS;
  }
  
/** Datei wipen und restlos entfernen
  */
  int iDatei_wipen()
  {
	  for( i = 0; i < 50; i++ )
	  {
		  clr();
	  }
	  printf("\nWelche Datei möchten Sie löschen? ");
	  fflush(stdin);
	  scanf("%s",sPfad);
	  if( remove(sPfad) != 0 )
	  {
		  fprintf(stderr, "Fehler beim Löschen von '%s'", sPfad);
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
		   /* Grösse in Bytes ermitteln */
			  fwrite((char *) "\0", 1, size, FPStream);
		   /* Kompletten Inhalt mit Nullen überschreiben */
			  fclose(FPStream);
		   /* damit die Datei gelöscht werden kann, schliessen */
			  remove(sPfad);                         /* weg damit */
			  printf("'%s' ist gelöscht", sPfad);

		  }
	  }
	  fflush(stdin);
	  getchar();
	  return EXIT_SUCCESS;
  }

/** Menüauswahl
  */ 
  int iMenue()
  {
	  do
	  {
		  for( i = 0; i < 50; i++ )
		  {
			  clr();
		  }
		  printf("\n\n");
		  printf("___Passwortmanager_1.1__\n");
		  printf("_____for_GNU/Linux______\n");
		  printf("<1> Passphrase speichern\n");
		  printf("<2> Passphrase anzeigen \n");
		  printf("<3> Passphrase ändern   \n");
		  printf("<W> Passphrase löschen  \n");
		  printf("<k> Benutzer   Abmelden \n");
		  printf("<q> Programm   Beenden  \n");
		  printf("==> Ihre Auswahl: ");
		  fflush(stdin);
		  scanf("%c", &sEingabe);
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
			  case 'q':
			  {
				  system("exit");
				  break;
			  }
			  case 'k':
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
	fflush(stdin);
	getchar();
	return 0;
}

/** Root
  */
  int iRoot()
  {
	  for( i = 0; i < 50; i++ )
	  {
		  clr();
	  }
	  printf("\n\n");
	  printf("___Passwortmanager_1.1__\n");
	  printf("_____for_GNU/Linux______\n");
	  system("sudo -v");   /* Systembefehl für Superuser */
	  if("sudo -v" != 0)
	  {
		  iMenue();
	  }
	  else
	  {
		  printf("ZUGRIFF VERWEIGERT!\n");
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
