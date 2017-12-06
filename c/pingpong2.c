/** Programm : pong.c
  * Autor	 : 
  * Version  : 0.1
  * Datum    : TT.MM.JJ
  * Stand    : TT.MM.JJ
  * Status   : in Arbeit
  * ToDo     : Bugs im Algorithmus beheben; linke untere Kante, rechte obere Kante
  *            Paddles manuell bewegen(kbhit), Speedfunktion programmieren,
  *            Bildsch.flackern beseitigen (Ausgabe in Arrays speichern)
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>
  #include <windows.h>
  #define FELD "./frame"
  #define HELP "./help"
  #define Cls(); system("cls");

/** Funktion : Setzt den Cursor an Position x;y
  * Status   : vorgelegt
  */   
  void iCsr( unsigned int y , unsigned int x )
  {
      COORD Position;
	  Position.X = x;
	  Position.Y = y;
	  SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ) , Position );
  }

/** Funktion : Beschreibung der Funktion
  * Status   : in Planung
  */  
  struct stMerken
  {
      char cAuswahl;          /* merken welche Taste im Menue gedrueckt wurde */
  }stFlag;

/** Funktion : Rahmen und Hilfe auf Bildsch. ausgeben
  * Status   : vorgelegt
  */
  int iScreen()
  {
	  char sDisp[FILENAME_MAX];
	  int i = 0;
	  FILE *Fp;
	  if(stFlag.cAuswahl=='h' && 'H')  /* wenn H gedrueckt, dann oeffne Hilfe */
	  {
          Fp = fopen(HELP, "r");                 /* wir oeffnen die Datei help*/
      }
      else
      {
          Fp = fopen(FELD, "r");                     /* sonst Spielfeld frame */
      }
      fgets(sDisp, FILENAME_MAX, Fp);
	  do
	  {
		  printf("%s", sDisp);
		  fgets(sDisp, FILENAME_MAX, Fp);
		  i = strlen(sDisp) -1;
		  if(sDisp[i] == '\n')
		  {
			  sDisp[i] = '\0';
		  }
	  }while(!feof(Fp));
	  fclose(Fp);          /* wir schliessen das File aus Sicherheitsgruenden */
	  return 0;
  }
  
/** Funktion : Hauptmenue fuer die Auswahl des Spiels
  * Status   : vorgelegt
  */
  int iMenu()
  {
      char cAuswahl;             /* Deklaration fuer char ohne Initialsierung */
      do
      {
           Cls();
           printf("\n\t__________________________________\n");
           printf("\n\t             Pong                 \n");
           printf("\n\t__________________________________\n");
           printf("\n\t < S > Spiel Starten              \n");
           printf("\n\t < H > Hilfe Anzeigen             \n");
           printf("\n\t < B > Spiel Beenden              \n");
           printf("\n\t Eingabe: ");
           stFlag.cAuswahl = getch();               /* gibt echo zurueck
                                                      * benoetigt kein zz. Enter
                                                      */
           fflush(stdin);                            /* leere Tastaturpuffer */
           switch(stFlag.cAuswahl)
           {
               case 's':                       /* beide Schreibweisen erlaubt */
               case 'S':                      /* gilt fuer dieselbe Anweisung */
               {
                   iPong();
                   break;
               }
               case 'h':
               case 'H':
               {
                   iHilf();
                   break;
               }
               case 'b':
               case 'B':
               {
                   return 0;
               }
               default:
               {
                   printf("\n\t Falsche Taste, versuchen Sie es erneut");
                   getchar();
                   break;
               }
           }         
      }
      while(cAuswahl != 'b' && 'B');                 /* User beendet Programm */
      return 0;
  }  

/** Funktion : Algorithmus fuer das Verhalten des Tennisball
  * Status   : in Arbeit
  */
  int iPong()
  {
	  int y = 1;
	  int x = 1;
	  int iBall_y = 0;
	  int iBall_x = 0;
	  srand(time(NULL));                  /* Zeitfunktion erzeugt Zufallszahl */
	  iBall_y = rand() % 23 +1;       /* Ball zufaellig positionieren y-Achse */
	  iBall_x = rand() % 77 +1;	      /* Ball zufaellig positionieren x-Achse */ 
	  y=iBall_y;
 	  x=iBall_x;
      if(y!=1 && x!=1 && y!=23 && x!=77)/* Ball muss innerh. des Spielf. sein */
      {  
          do
          {
              Cls();
              iScreen();
              iCsr(y,x);
              printf("O");
              iPad_L(y,x);
              iPad_R(y,x);
              y++;                       /* Inkrement; Index um Eins erhoehen */
              x++;
          }while(y != 23 && x < 77);
      }
      else
      {
          iPong();
      }
      do
      {
	      if(y<=23 && x<=3)      /* linkes  Paddle prallt Ball in Spalte 3 ab */
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
                  iPad_L(y,x);
                  iPad_R(y,x);
		          --y;                 /* dekrement; Index um Eins verringern */
		          x++;    
              }while(y != 1 && x < 77);
          }
   	      if(y==1)
	      {          
              do
	          {
                  Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
	              iPad_L(y,x);
                  iPad_R(y,x);
		          y++;
		          x++;    
              }while(y != 23 && x < 77); /* recht. Pad. prallt Ball in Sp. 77 ab */
          }
   	      if(y==23)                        /* Ball an unterer Bande abprallen */
	      {          
              do
	          {
                  Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          iPad_L(y,x);
                  iPad_R(y,x);
		          --y;
		          x++;    
              }while(y != 1 && x < 77);
          }
   	      if(x==77)                        /* Ball an rechter Bande abprallen */
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          iPad_L(y,x);
                  iPad_R(y,x);
		          --y;
		          --x;    
              }while(y!=1 && x!=3);
          }
   	      if(y==1)                          /* Ball an oberer Bande abprallen */
	      {          
              do
              {
                  Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          iPad_L(y,x);
                  iPad_R(y,x);
		          y++;
		          --x;    
              }while(y!=23);       /* Durchl. wiederh. bis Bande erreicht ist */
          }
   	      if(y==23)
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          iPad_L(y,x);
                  iPad_R(y,x);
		          --y;
		          --x;    
              }while(y!=1);
          }
   	      if(y==23)
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          iPad_L(y,x);
                  iPad_R(y,x);
		          --y;
		          --x;    
              }while(y!=1 && x!=3);
          }
   	      if(y==1)
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          iPad_L(y,x);
                  iPad_R(y,x);
		          y++;
		          --x;    
              }while(y!=23 && x!=3);
          }
   	      if(y==23)
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          iPad_L(y,x);
                  iPad_R(y,x);
		          --y;
		          x++;    
              }while(y != 1 && x < 77);
          }
      }while(y!=0 && x!=0); /* wenn Ball Spielf. verlaesst, neu positionieren */
      iPong();
	  return 0;
  }
 
/** Funktion : Paddles zum manuellen bewegen (Parallelfunktion)
  * Status   : in Planung
  */
  int iPaddles(int y, int x)
  {
      int cEingabe;
      do
      {
          cEingabe = getch();
          switch(cEingabe)
          {
              case 'a': 
              case 'A':
              {
                  iCsr(y,x); printf("||"); cEingabe++; break;
              }
              case 'd':
              case 'D':
              {
                  iCsr(y,x); printf("||"); cEingabe++; break;
              }
              case 'w':
              case 'W':
              {
                  iCsr(y,x); printf("||"); cEingabe++; break;
              }
              case 's':
              case 'S':
              {
                  iCsr(y,x); printf("||"); cEingabe++; break;
              }
          }
      }while(cEingabe != 'b' && 'B');
      return 0;
  } 

/** Funktion : Hilfe anzeigen
  * Status   : vorgelegt
  */
  int iHilf()
  {
      Cls();
      iScreen();
      iCsr(8,46);
      getchar();
      fflush(stdin);
      return 0;
  }
  
/** Funktion : Linkes Paddle
  * Status   : in Arebit
  */
  int iPad_L(int y, int x)
  {  
      iCsr(y, 1);
      printf("||");
      return 0;
  }
  
/** Funktion : Rechtes Paddle
  * Status   : in Arebit
  */ 
  int iPad_R(int y, int x)
  {  
      iCsr(y, 77);
      printf("||");
      return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iMenu();
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
