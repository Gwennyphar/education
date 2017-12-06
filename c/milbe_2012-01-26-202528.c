/** automatically generate with c-generator
  * Programm: milbe.c
  * Autor   : nico
  * Version : 0.1
  * Datum   : 2012-01-26-202528
  * Stand   : 2012-01-26-202528
  * Status  : in Arbeit
  * ToDo's  :
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>                          /* Standard-I/O */
  #include <stdlib.h>                         /* Nuetzliche Funktionen */
  #include <string.h> 		                  /* Zeichenkettenoperationen */
  #include <math.h>   		                  /* Mathematische Funktionen */  
  #ifdef __linux__
  #include <termios.h>
  #include <unistd.h>
  #elif __WIN32__ || _MSC_VER__
  #include <windows.h>
  #include <conio.h>
  #endif

/** Funktion : Bildschirmausgabe unter Linux und Windows stoppen
  * Status   : vorgelegt
  */
  void wait()
  {
      #ifdef __linux__
      getchar();
      #elif __WIN32__ || _MSC_VER__
      getch();
      #endif
  }

/** Funktion : vorherige Bildschirmausgabe unter Linux und Windows loeschen
  * Status   : vorgelegt
  */
  void cls()
  {
      #ifdef __linux__
      printf("\033[1J\033[1;1H");            /* Ausgabe loeschen und Cursor
                                              * auf 1.Zeile oben links setzen */
      #elif __WIN32__ || _MSC_VER__
      system("cls");
      #endif
  }

/** Funktion : Setzt den Cursor an Position x;y
  * Status   : vorgelegt
  */
  void csr( unsigned int y , unsigned int x )
  {
      #ifdef __linux__
      printf("\033[%i;%iH" , ( y + 1 ) , ( x + 1 ) );
      #else
      COORD Position;
      Position.X = x;
      Position.Y = y;
      SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), Position );
      #endif
  } 

/** Funktion : Beschreibung der Funktion milbe
  * Status   : in Arbeit
  */
  int iMilbe()
  {
     cls();
     int iSpalte  = 0;
     int iZeile   = 0;
     int iTeilchen = 0;
     /* Array 10x10 mit nem Wechseltierchen drin  */
     int iArray[10][10]={{' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
						 {' ',' ',' ',' ',' ','*','*',' ',' ',' '},
		                 {' ',' ',' ',' ','*',' ',' ','*',' ',' '},
		                 {' ',' ',' ','*',' ',' ',' ',' ','*',' '},
		                 {' ',' ',' ','*',' ',' ',' ',' ','*',' '},
		                 {' ',' ','*',' ',' ',' ','*','*',' ',' '},
		                 {' ',' ','*',' ',' ','*',' ',' ',' ',' '},
		                 {' ',' ',' ','*','*',' ',' ',' ',' ',' '},
		                 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
		                 {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
	 for(iSpalte = 0; iSpalte <= 9; iSpalte++)
	 {
		 for(iZeile = 0; iZeile <= 9; iZeile++)
		 {
			 /* Teilchen aus Feld holen */
			 printf("%c|", iArray[iSpalte][iZeile]);/* wechseltierchen zeigen */
			 if(iArray[iSpalte][iZeile] == '*')
			 {
				 iTeilchen++; /* Teilchen zaehlen */
				 //iSpalte++;
			 }
			 else
			 {
				 iTeilchen = iArray[iSpalte][iZeile]; /* Spalte nach rechts */
			 }
		 }
		 printf("\n");
	 }
	 printf("\n %i Milbenteilchen von %i", iTeilchen, iArray[iSpalte][iZeile]);
	 wait();
	 return 0;
 }

/** Steuerprogramm
  */
  int iController()
  {
      iMilbe();
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
