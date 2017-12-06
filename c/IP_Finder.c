/** Praeprozessor
  *
  */
  #include <stdio.h>
  #include <string.h>
  #include <arpa/inet.h>
  #include <netdb.h>
  
/** Funktion : struct
  * Status   : fertig
  */
  struct
  {
	  char *h_name;            /* offizieller Name des Host */
	  char **h_alias;          /* Auflistung von Alias */
	  int  h_addrtype;          /* Host Adressen Typ */
	  int  h_length;           /* Länge der Adresse */
	  char **h_addr_list; /* Auflistunng von Adressen */
  }hostent;

/** Funktion : ermitteln von IP und Hostadressen
  * Status   : in Arbeit
  */
  int iNetzwerk()
  {
	  int argc = 2;
	  char *argv[1];
	  struct hostent *host;
	  struct in_addr *host_ip;
	  if( (argc != 2 ) || (strcmp (argv[1], "-h") == 0) )
	  {
		  fprintf(stderr, "Verwendung: IP auf Domain-Namen prüfen");
		  return 1;
	  }
	  host = gethostbyname( argv[1] );
	  if( host == NULL )
	  {
		  herror("Verbindung 2: IP holen fehlgeschlagen");
		  return 1;
	  }
	  host_ip = (struct in_addr *) host->h_addr;
	  printf("Hostname:\t%s\n", host->h_name);
	  printf("IP-Adresse:\t%s\n", inet_ntoa( *host_ip ) );
	  return 0;
  }
  
/** Steuerprogramm
  *
  */
  int iController()
  {
	  iNetzwerk();
	  return 0;
  }
  
/** Hauptprogramm
  *
  */
  int main()
  {
	  int iController();
	  return 0;
  }	  
	  


