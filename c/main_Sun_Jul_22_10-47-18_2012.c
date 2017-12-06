/** Programm....: main.c
  * Entwickler..: 
  * Version.....: 0.1
  * Datum.......: Sun Jul 22 10:47:18 2012
  * Status......: in Arbeit
  * ToDo........:
  * 
  * A l
  * B m
  * C n
  * D o
  * E p
  * F q
  * G r
  * H s
  * I t
  * J u
  * K v
  * L w
  * M x
  * N y
  * O z
  * P a
  * Q b
  * R c
  * S d
  * T e
  * U f
  * V g
  * W h
  * X i
  * Y j
  * Z k
  * 
  * 
  * a L
  * b M
  * c N
  * d O
  * e P
  * f Q
  * g R
  * h S
  * i T
  * j U
  * k V
  * l W
  * m X
  * n Y
  * o Z
  * p A
  * q B
  * r C
  * s D
  * t E
  * u F
  * v G
  * w H
  * x I
  * y J
  * z K
  * 
  * 1 5
  * 2 6
  * 3 7
  * 4 8
  * 5 9
  * 6 0
  * 7 1
  * 8 2
  * 9 3
  * 0 4
  * 
  * ! @
  * # .
  * ? %
  * * =
  * $ +
  * @ !
  * . #
  * % ?
  * = *
  * + $
  */

/** Praeprozessor
  */
  #include <stdio.h>                     /* Standard-I/O */
  #include <stdlib.h>                    /* Nuetzliche Funktionen */
  #include <string.h>                    /* Zeichenketten */
  #ifdef __unix__
  #define TASTE "D"
  #else
  #define TASTE "Z"
  #endif
   
/** Funktion....: Daten Lesen
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iLesen()
  {
	  char sText[255];
	  char *cZeichen;
	  FILE *FPLesen;
	  FPLesen = fopen("saved.txt", "r");
	  if(FPLesen == NULL)
	  {
		  fprintf(stderr, "\n\tFehler: Datei konnte nicht gelesen werden!"
		  "\n\tPuffer wird geleert -Versuchen Sie es erneut\n\n");
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  while(fgets(sText, sizeof(sText), FPLesen))
		  {
			  /* Großbuchstaben codieren */
			  while((cZeichen = strchr(sText, 'l'))!=NULL)
			  {
				  *cZeichen = 'A';
			  }
			  while((cZeichen = strchr(sText, 'm'))!=NULL)
			  {
				  *cZeichen = 'B';
			  }
			  while((cZeichen = strchr(sText, 'n'))!=NULL)
			  {
				  *cZeichen = 'C';
			  }
			  while((cZeichen = strchr(sText, 'o'))!=NULL)
			  {
				  *cZeichen = 'D';
			  }
			  while((cZeichen = strchr(sText, 'p'))!=NULL)
			  {
				  *cZeichen = 'E';
			  }
			  while((cZeichen = strchr(sText, 'q'))!=NULL)
			  {
				  *cZeichen = 'F';
			  }
			  while((cZeichen = strchr(sText, 'r'))!=NULL)
			  {
				  *cZeichen = 'G';
			  }
			  while((cZeichen = strchr(sText, 's'))!=NULL)
			  {
				  *cZeichen = 'H';
			  }
			  while((cZeichen = strchr(sText, 't'))!=NULL)
			  {
				  *cZeichen = 'I';
			  }
			  while((cZeichen = strchr(sText, 'u'))!=NULL)
			  {
				  *cZeichen = 'J';
			  }
			  while((cZeichen = strchr(sText, 'v'))!=NULL)
			  {
				  *cZeichen = 'K';
			  }
			  while((cZeichen = strchr(sText, 'w'))!=NULL)
			  {
				  *cZeichen = 'L';
			  }
			  while((cZeichen = strchr(sText, 'x'))!=NULL)
			  {
				  *cZeichen = 'M';
			  }
			  while((cZeichen = strchr(sText, 'y'))!=NULL)
			  {
				  *cZeichen = 'N';
			  }
			  while((cZeichen = strchr(sText, 'z'))!=NULL)
			  {
				  *cZeichen = 'O';
			  }
			  while((cZeichen = strchr(sText, 'a'))!=NULL)
			  {
				  *cZeichen = 'P';
			  }
			  while((cZeichen = strchr(sText, 'b'))!=NULL)
			  {
				  *cZeichen = 'Q';
			  }
			  while((cZeichen = strchr(sText, 'c'))!=NULL)
			  {
				  *cZeichen = 'R';
			  }
			  while((cZeichen = strchr(sText, 'd'))!=NULL)
			  {
				  *cZeichen = 'S';
			  }
			  while((cZeichen = strchr(sText, 'e'))!=NULL)
			  {
				  *cZeichen = 'T';
			  }
			  while((cZeichen = strchr(sText, 'f'))!=NULL)
			  {
				  *cZeichen = 'U';
			  }
			  while((cZeichen = strchr(sText, 'g'))!=NULL)
			  {
				  *cZeichen = 'V';
			  }
			  while((cZeichen = strchr(sText, 'h'))!=NULL)
			  {
				  *cZeichen = 'W';
			  }
			  while((cZeichen = strchr(sText, 'i'))!=NULL)
			  {
				  *cZeichen = 'X';
			  }
			  while((cZeichen = strchr(sText, 'j'))!=NULL)
			  {
				  *cZeichen = 'Y';
			  }
			  while((cZeichen = strchr(sText, 'k'))!=NULL)
			  {
				  *cZeichen = 'Z';
			  }
			  /* Kleinbuchstaben codieren */
			  while((cZeichen = strchr(sText, 'L'))!=NULL)
			  {
				  *cZeichen = 'A';
			  }
			  while((cZeichen = strchr(sText, 'M'))!=NULL)
			  {
				  *cZeichen = 'B';
			  }
			  while((cZeichen = strchr(sText, 'N'))!=NULL)
			  {
				  *cZeichen = 'C';
			  }
			  while((cZeichen = strchr(sText, 'O'))!=NULL)
			  {
				  *cZeichen = 'D';
			  }
			  while((cZeichen = strchr(sText, 'P'))!=NULL)
			  {
				  *cZeichen = 'E';
			  }
			  while((cZeichen = strchr(sText, 'Q'))!=NULL)
			  {
				  *cZeichen = 'F';
			  }
			  while((cZeichen = strchr(sText, 'R'))!=NULL)
			  {
				  *cZeichen = 'G';
			  }
			  while((cZeichen = strchr(sText, 'S'))!=NULL)
			  {
				  *cZeichen = 'H';
			  }
			  while((cZeichen = strchr(sText, 'T'))!=NULL)
			  {
				  *cZeichen = 'I';
			  }
			  while((cZeichen = strchr(sText, 'U'))!=NULL)
			  {
				  *cZeichen = 'J';
			  }
			  while((cZeichen = strchr(sText, 'V'))!=NULL)
			  {
				  *cZeichen = 'K';
			  }
			  while((cZeichen = strchr(sText, 'W'))!=NULL)
			  {
				  *cZeichen = 'L';
			  }
			  while((cZeichen = strchr(sText, 'X'))!=NULL)
			  {
				  *cZeichen = 'M';
			  }
			  while((cZeichen = strchr(sText, 'Y'))!=NULL)
			  {
				  *cZeichen = 'N';
			  }
			  while((cZeichen = strchr(sText, 'Z'))!=NULL)
			  {
				  *cZeichen = 'O';
			  }
			  while((cZeichen = strchr(sText, 'A'))!=NULL)
			  {
				  *cZeichen = 'P';
			  }
			  while((cZeichen = strchr(sText, 'B'))!=NULL)
			  {
				  *cZeichen = 'Q';
			  }
			  while((cZeichen = strchr(sText, 'C'))!=NULL)
			  {
				  *cZeichen = 'R';
			  }
			  while((cZeichen = strchr(sText, 'D'))!=NULL)
			  {
				  *cZeichen = 'S';
			  }
			  while((cZeichen = strchr(sText, 'E'))!=NULL)
			  {
				  *cZeichen = 'T';
			  }
			  while((cZeichen = strchr(sText, 'F'))!=NULL)
			  {
				  *cZeichen = 'U';
			  }
			  while((cZeichen = strchr(sText, 'G'))!=NULL)
			  {
				  *cZeichen = 'V';
			  }
			  while((cZeichen = strchr(sText, 'H'))!=NULL)
			  {
				  *cZeichen = 'W';
			  }
			  while((cZeichen = strchr(sText, 'I'))!=NULL)
			  {
				  *cZeichen = 'X';
			  }
			  while((cZeichen = strchr(sText, 'J'))!=NULL)
			  {
				  *cZeichen = 'Y';
			  }
			  while((cZeichen = strchr(sText, 'K'))!=NULL)
			  {
				  *cZeichen = 'Z';
			  }
			  /* Zahlen codieren */
			  while((cZeichen = strchr(sText, '5'))!=NULL)
			  {
				  *cZeichen = '1';
			  }
			  while((cZeichen = strchr(sText, '6'))!=NULL)
			  {
				  *cZeichen = '2';
			  }
			  while((cZeichen = strchr(sText, '7'))!=NULL)
			  {
				  *cZeichen = '3';
			  }
			  while((cZeichen = strchr(sText, '8'))!=NULL)
			  {
				  *cZeichen = '4';
			  }
			  while((cZeichen = strchr(sText, '9'))!=NULL)
			  {
				  *cZeichen = '5';
			  }
			  while((cZeichen = strchr(sText, '0'))!=NULL)
			  {
				  *cZeichen = '6';
			  }
			  while((cZeichen = strchr(sText, '1'))!=NULL)
			  {
				  *cZeichen = '7';
			  }
			  while((cZeichen = strchr(sText, '2'))!=NULL)
			  {
				  *cZeichen = '8';
			  }
			  while((cZeichen = strchr(sText, '3'))!=NULL)
			  {
				  *cZeichen = '9';
			  }
			  while((cZeichen = strchr(sText, '4'))!=NULL)
			  {
				  *cZeichen = '0';
			  }
			  /* Sonderzeichen codieren */
			  while((cZeichen = strchr(sText, '@'))!=NULL)
			  {
				  *cZeichen = '!';
			  }
			  while((cZeichen = strchr(sText, '.'))!=NULL)
			  {
				  *cZeichen = '#';
			  }
			  while((cZeichen = strchr(sText, '%'))!=NULL)
			  {
				  *cZeichen = '?';
			  }
			  while((cZeichen = strchr(sText, '='))!=NULL)
			  {
				  *cZeichen = '*';
			  }
			  while((cZeichen = strchr(sText, '+'))!=NULL)
			  {
				  *cZeichen = '$';
			  }
			  while((cZeichen = strchr(sText, '!'))!=NULL)
			  {
				  *cZeichen = '@';
			  }
			  while((cZeichen = strchr(sText, '#'))!=NULL)
			  {
				  *cZeichen = '.';
			  }
			  while((cZeichen = strchr(sText, '?'))!=NULL)
			  {
				  *cZeichen = '%';
			  }
			  while((cZeichen = strchr(sText, '*'))!=NULL)
			  {
				  *cZeichen = '=';
			  }
			  while((cZeichen = strchr(sText, '$'))!=NULL)
			  {
				  *cZeichen = '+';
			  }
			  puts(sText);
		  }
	  }
	  fclose(FPLesen);
	  return EXIT_SUCCESS;
  }

/** Funktion....: Daten Schreiben
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iSchreiben()
  {
	  char sEingabe[20][160];
	  int  iZeilen = 0;
	  char *cZeichen;
	  FILE *FPSchreiben;
	  printf("\n\tBenutzername und Passwort eingeben:"
	  "\n\tEingabe mit [STRG]+[%s] beenden\n"
	  "\n\t", TASTE);
	  FPSchreiben = fopen("saved.txt", "a");
	  if(FPSchreiben == NULL)
	  {
		  fprintf(stderr, "\n\tFehler: Datei konnte nicht angelegt werden!"
		  "\n\tPuffer wird geleert -Versuchen Sie es erneut\n\n");
		  return EXIT_FAILURE;
	  }
	  else
	  {
		  while(fgets(sEingabe[iZeilen], sizeof(sEingabe[iZeilen]), stdin))
		  {
			  printf("\t");
			  /* Großbuchstaben codieren */
			  while((cZeichen = strchr(sEingabe[iZeilen], 'A'))!=NULL)
			  {
				  *cZeichen = 'l';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'B'))!=NULL)
			  {
				  *cZeichen = 'm';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'C'))!=NULL)
			  {
				  *cZeichen = 'n';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'D'))!=NULL)
			  {
				  *cZeichen = 'o';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'E'))!=NULL)
			  {
				  *cZeichen = 'p';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'F'))!=NULL)
			  {
				  *cZeichen = 'q';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'G'))!=NULL)
			  {
				  *cZeichen = 'r';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'H'))!=NULL)
			  {
				  *cZeichen = 's';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'I'))!=NULL)
			  {
				  *cZeichen = 't';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'J'))!=NULL)
			  {
				  *cZeichen = 'u';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'K'))!=NULL)
			  {
				  *cZeichen = 'v';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'L'))!=NULL)
			  {
				  *cZeichen = 'w';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'M'))!=NULL)
			  {
				  *cZeichen = 'x';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'N'))!=NULL)
			  {
				  *cZeichen = 'y';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'O'))!=NULL)
			  {
				  *cZeichen = 'z';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'P'))!=NULL)
			  {
				  *cZeichen = 'a';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'Q'))!=NULL)
			  {
				  *cZeichen = 'b';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'R'))!=NULL)
			  {
				  *cZeichen = 'c';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'S'))!=NULL)
			  {
				  *cZeichen = 'd';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'T'))!=NULL)
			  {
				  *cZeichen = 'e';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'U'))!=NULL)
			  {
				  *cZeichen = 'f';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'V'))!=NULL)
			  {
				  *cZeichen = 'g';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'W'))!=NULL)
			  {
				  *cZeichen = 'h';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'X'))!=NULL)
			  {
				  *cZeichen = 'i';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'Y'))!=NULL)
			  {
				  *cZeichen = 'j';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'Z'))!=NULL)
			  {
				  *cZeichen = 'k';
			  }
			  /* Kleinbuchstaben codieren */
			  while((cZeichen = strchr(sEingabe[iZeilen], 'a'))!=NULL)
			  {
				  *cZeichen = 'L';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'b'))!=NULL)
			  {
				  *cZeichen = 'M';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'c'))!=NULL)
			  {
				  *cZeichen = 'N';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'd'))!=NULL)
			  {
				  *cZeichen = 'O';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'e'))!=NULL)
			  {
				  *cZeichen = 'P';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'f'))!=NULL)
			  {
				  *cZeichen = 'Q';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'g'))!=NULL)
			  {
				  *cZeichen = 'R';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'h'))!=NULL)
			  {
				  *cZeichen = 'S';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'i'))!=NULL)
			  {
				  *cZeichen = 'T';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'j'))!=NULL)
			  {
				  *cZeichen = 'U';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'k'))!=NULL)
			  {
				  *cZeichen = 'V';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'l'))!=NULL)
			  {
				  *cZeichen = 'W';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'M'))!=NULL)
			  {
				  *cZeichen = 'X';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'n'))!=NULL)
			  {
				  *cZeichen = 'Y';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'o'))!=NULL)
			  {
				  *cZeichen = 'Z';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'p'))!=NULL)
			  {
				  *cZeichen = 'A';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'q'))!=NULL)
			  {
				  *cZeichen = 'B';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'r'))!=NULL)
			  {
				  *cZeichen = 'C';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 's'))!=NULL)
			  {
				  *cZeichen = 'D';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 't'))!=NULL)
			  {
				  *cZeichen = 'E';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'u'))!=NULL)
			  {
				  *cZeichen = 'F';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'v'))!=NULL)
			  {
				  *cZeichen = 'G';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'w'))!=NULL)
			  {
				  *cZeichen = 'H';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'x'))!=NULL)
			  {
				  *cZeichen = 'I';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'y'))!=NULL)
			  {
				  *cZeichen = 'J';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], 'z'))!=NULL)
			  {
				  *cZeichen = 'K';
			  }
			  /* Zahlen codieren */
			  while((cZeichen = strchr(sEingabe[iZeilen], '1'))!=NULL)
			  {
				  *cZeichen = '5';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '2'))!=NULL)
			  {
				  *cZeichen = '6';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '3'))!=NULL)
			  {
				  *cZeichen = '7';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '4'))!=NULL)
			  {
				  *cZeichen = '8';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '5'))!=NULL)
			  {
				  *cZeichen = '9';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '6'))!=NULL)
			  {
				  *cZeichen = '0';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '7'))!=NULL)
			  {
				  *cZeichen = '1';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '8'))!=NULL)
			  {
				  *cZeichen = '2';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '9'))!=NULL)
			  {
				  *cZeichen = '3';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '0'))!=NULL)
			  {
				  *cZeichen = '4';
			  }
			  /* Sonderzeichen codieren */
			  while((cZeichen = strchr(sEingabe[iZeilen], '!'))!=NULL)
			  {
				  *cZeichen = '@';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '#'))!=NULL)
			  {
				  *cZeichen = '.';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '?'))!=NULL)
			  {
				  *cZeichen = '%';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '*'))!=NULL)
			  {
				  *cZeichen = '=';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '$'))!=NULL)
			  {
				  *cZeichen = '+';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '@'))!=NULL)
			  {
				  *cZeichen = '!';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '.'))!=NULL)
			  {
				  *cZeichen = '#';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '%'))!=NULL)
			  {
				  *cZeichen = '?';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '='))!=NULL)
			  {
				  *cZeichen = '*';
			  }
			  while((cZeichen = strchr(sEingabe[iZeilen], '+'))!=NULL)
			  {
				  *cZeichen = '$';
			  }
			  fputs(sEingabe[iZeilen], FPSchreiben);
			  iZeilen++;
		  }
	  }
	  fclose(FPSchreiben);
	  return EXIT_SUCCESS;
  }

/** Funktion....: Steuerfunktion fuer das Hauptmenue
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iMenue()
  {
      char cTaste = 0;
      char sEingabe[3];
      do
      {
          printf("\tWas moechten Sie machen?\n"
          "\tMit '0' Auswahl anzeigen: ");
          /* abgesicherte Eingabe */
          fgets(sEingabe, sizeof(sEingabe), stdin);
          sscanf(sEingabe, "%c", &cTaste);
          switch(cTaste)
          {
              case '0':
              {
                  printf("\n\t_________________"
                  "\n\t-0- Auswahl"
                  "\n\t-1- Schreiben"
                  "\n\t-2- Lesen"
                  "\n\t-3- Suchen"
                  "\n\t-4- Abmelden"
                  "\n\t_________________\n\n");
                  continue;
              }
              case '1':
              {
                  iSchreiben();
                  break;
              }
              case '2':
              {
                  iLesen();
                  break;
              }
              case '3':
              {
                  //suchen
                  break;
              }
              case '4':
              {
                  /* beende hier */
                  printf("\n\tVom System erfolgreich abgemeldet\n\n");
                 break;
              }
              default:
              {
                  fprintf(stderr, "\n\tFehler: Ungueltige Eingabe\n\n");
                  break;
              }
          }
      }while(cTaste != '4');             /* Ende der Schleife */
      return EXIT_SUCCESS;
  }

/** Funktion....: Anmelden
  * Beschreibung: 
  * Status......: in Arbeit
  */
  int iLogin()
  {
	  int iCounter = 4;
	  char sEingabe[21];
	  char sEingabe_User[21];
	  char sEingabe_Pwd[21];
	  char sUser[21] = {"nico"};
	  char sPwd[21] = {"test"};
	  printf("\n\tProgramm mit 'x' beenden.\n"
	  "\tBitte am System anmelden:\n"
	  "\t_________________________\n");
	  do
	  {
		  sEingabe_User[strlen(sEingabe_User)-1] = '\0';
		  printf("\n\tBenutzername eingeben: ");
		  fgets(sEingabe, sizeof(sEingabe), stdin);
		  sscanf(sEingabe, "%s", sEingabe_User);
		  if(strcmp(sEingabe_User, sUser) == 0)
		  {
			  do
			  {
				  /* Nach Abmelden od. falscher Eing. wir der Puffer geleert */
				  sEingabe_Pwd[strlen(sEingabe_Pwd)-1] = '\0';
				  printf("\tPasswort eingeben....: ");
				  fgets(sEingabe, sizeof(sEingabe), stdin);
				  sscanf(sEingabe, "%s", sEingabe_Pwd);
				  if(strcmp(sPwd, sEingabe_Pwd) ==0)
				  {
					  printf("\n\tAm System erfolgreich angemeldet!\n\n");
					  iMenue();
				  }
				  else if(strcmp(sEingabe_Pwd, "x") == 0 
				  || strcmp(sEingabe_Pwd, "X") == 0)
				  {
					  printf("\n\tVielen Dank und Auf Wiedersehen!");
					  return EXIT_SUCCESS;
				  }
				  else
				  {
					  fprintf(stderr, "\n\tFehler: ungueltiges Passwort\n"
					  "\tNoch %i Versuche verbleiben\n\n", iCounter-1);
					  iCounter--;
				  }
			  }while(iCounter != 0);
		  }
		  else if(strcmp(sEingabe_User, "x") == 0 
		  || strcmp(sEingabe_User, "X") == 0 )
		  {
			  printf("\n\tVielen Dank und Auf Wiedersehen!");
			  return EXIT_SUCCESS;
		  }
		  else
		  {
			  if(iCounter != 1)
			  {
				  fprintf(stderr, "\n\tFehler: ungueltiger Benutzer\n"
				  "\tNoch %i Versuche verbleiben\n\n", iCounter-1);
			  }
			  iCounter--;
		  }
	  }while(iCounter != 0);
	  fprintf(stderr, "\n\tFehler: Zugriff verweigert!");
	  return EXIT_SUCCESS;
  }

/** Steuerprogramm
  */
  int iController()
  {
      iLogin();                          /* Funktion an OS-Ebene uebergeben */
      return EXIT_SUCCESS;
  }

/** Hauptprogramm
  */
  int main()
  {
      iController();                     /* Rueckgabe aus iController() */
      return EXIT_SUCCESS;
  }

/** Programmende
  */
