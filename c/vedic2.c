/** Programm : Karazuba.c
  * Autor	 : 
  * Version  : 0.1
  * Datum    : TT.MM.JJ
  * Stand    : TT.MM.JJ
  * Status   : in Planung
  * ToDo     :
u   = p·r,
v   = (q - p)·(s - r),
w   = q·s.
p=7 r=2 q=8 s=1              
u   = 7·2 = 14,
v   = (8 - 7)·(1 - 2) = -1,
w   = 8·1 = 8.
u + w - v = p·r + q·s - (q - p)·(s - r) = p·s + q·r #Gleichung
ergebnis
78·21	=	 14·100 + (14 + 8 - (-1))·10 + 8
=	1400 + 230 + 8
=	1638
*/

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>
  #define ZAHLEN 1


/** Funktion : Beschreibung der Funktion
  * Status   : in Planung
  */
  int iVedic()
  {

	  int a[ZAHLEN];
	  int b[ZAHLEN];
	  int c[ZAHLEN];
	  int d[ZAHLEN];
	  int u[ZAHLEN];
	  int x[ZAHLEN];
	  
	  srand(time(NULL));
	  a[ZAHLEN] = ( rand() % 9 + 1 );
	  b[ZAHLEN] = ( rand() % 9 + 1 );
	  c[ZAHLEN] = ( rand() % 9 + 1 );
	  d[ZAHLEN] = ( rand() % 9 + 1 );

	  printf("\t  AB\n");
	  printf("\t-----\n");
	  printf("\t  %i%i\n",a[ZAHLEN], b[ZAHLEN]);
	  printf("\t* %i%i\n",c[ZAHLEN], d[ZAHLEN]);
	  printf("\t-----\n");
	  x[ZAHLEN] = d[ZAHLEN]*b[ZAHLEN]; /* letzte reihe von unten nach oben */
	  d[ZAHLEN] = d[ZAHLEN]*a[ZAHLEN]; /* von rechts nach links */
	  b[ZAHLEN] = c[ZAHLEN]*b[ZAHLEN]; /* von links nach rechts */
	  u[ZAHLEN] = d[ZAHLEN]+b[ZAHLEN]; /* Zwischenergbenisse addieren */
	  a[ZAHLEN] = c[ZAHLEN]*a[ZAHLEN]; /* erste reihe von unten nach oben */
	  printf("\t= %i %i %i\n", a[ZAHLEN], u[ZAHLEN], x[ZAHLEN]); /* Ausgabe */
	  return 0;
  }

  /*
 *  ab
 *  cd
 * ----
 * vrlh
 *  bdx
 * */

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iVedic();
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
