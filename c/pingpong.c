/** Programm : .c
  * Autor	 : 
  * Version  : 0.1
  * Datum    : TT.MM.JJ
  * Stand    : TT.MM.JJ
  * Status   : in Planung
  * ToDo     :
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>
  #include <windows.h>
  #define FELD "./feld"
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
  int iScreen()
  {
	  char sDisp[FILENAME_MAX];
	  int i = 0;
	  FILE *Fp;
	  Fp = fopen(FELD, "r");
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
	  fclose(Fp);
	  return 0;
  }

/** Funktion : Beschreibung der Funktion
  * Status   : in Planung
  */
  int iPong()
  {
	  int y = 1;
	  int x = 1;
	  int iBall_y = 0;
	  int iBall_x = 0;
	  srand(time(NULL));
	  iBall_y = rand() % 23 +1;
	  iBall_x = rand() % 79 +1;	  
	  y=iBall_y;
 	  x=iBall_x;
      if(y!=1 && x!=1)
      {  
          do
          {
              Cls();
              iScreen();
              iCsr(y,x);
              printf("O");
              y++;
              x++;
          }while(y != 23 && x < 79);
      }
      else
      {
          iPong();
      }
      do
      {
	      if(y<=23 && x<=1)
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          --y;
		          x++;    
              }while(y != 1 && x < 79);
          }
   	      if(y==1)
	      {          
              do
	          {
                  Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          y++;
		          x++;    
              }while(y != 23 && x < 79);
          }
   	      if(y==23)
	      {          
              do
	          {
                  Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          --y;
		          x++;    
              }while(y != 1 && x < 79);
          }
   	      if(x==79)
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          --y;
		          --x;    
              }while(y!=1 && x!=1);
          }
   	      if(y==1)
	      {          
              do
              {
                  Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          y++;
		          --x;    
              }while(y!=23);
          }
   	      if(y==23)
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
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
		          --y;
		          --x;    
              }while(y!=1 && x!=1);
          }
   	      if(y==1)
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          y++;
		          --x;    
              }while(y!=23 && x!=1);
          }
   	      if(y==23)
	      {          
              do
	          {
		          Cls();
		          iScreen();
 	              iCsr(y,x);
		          printf("O");
		          --y;
		          x++;    
              }while(y != 1 && x < 79);
          }
      }while(y!=0 && x!=0);
      iPong();
	  return 0;
  }
 
/** Steuerprogramm                                                          
  */
  int iController()
  {
      iPong();
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
