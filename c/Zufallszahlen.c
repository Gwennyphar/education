/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #define ZAHLEN 100
/** Zufallszahlen
  */
  int iZufallszahlen_erzeugen()
  {
   	  int iZaehler = 0;
   	  int iAnzahl = 0;
   	  int iFeld[ZAHLEN];
   	  srand(time(NULL));
   	  FILE *FPZeiger;
   	  FPZeiger = fopen("Codes.txt", "a+");
   	  printf("\t___________________________________\n");
   	  printf("\t            Keygenerator\n");
   	  printf("\t___________________________________\n");
   	  printf("\t    Wie viele Codes generieren? ");
   	  fflush(stdin);
   	  scanf("%i", &iAnzahl);
   	  printf("\n");
   	  for( iZaehler = 1; iZaehler <= iAnzahl; iZaehler++ )
   	  {
	   	   iFeld[ZAHLEN] = ( rand() % 1000 + 1 );
	   	   printf("\t %4i.Zahl: %i\n", iZaehler, iFeld[iZaehler]);
	   	  
	   	   fprintf( FPZeiger, "%4i.Zahl: %i\n", iZaehler, iFeld[iZaehler] );
  	  }
  	  fclose(FPZeiger);
  	  fflush(stdin);
  	  getchar();
  	  return 0;
  }

/** Steuerprogramm
  */
  int iController()
  {
   	  system("color 9");
   	  iZufallszahlen_erzeugen();
   	  return 0;
  }

/** Schnittstelle
  */
  int main()
  {
   	  iController();
   	  return 0;
  }
