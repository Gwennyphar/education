/** Programm : mini_calc.c
  * Autor    : nico anders
  * Version  : 0.1
  * Datum    : TT.MM.JJ
  */

/** Praeprozessor
  * Bibliothek-Einbindung fuer Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>                          /* Standard-I/O             */
  #include <stdlib.h>                         /* Nützliche Funktionen     */
  #include <math.h>                           /* Mathematische Funktionen */

/** Funktion : schlanker Taschenrechner für Grundrechenarten zweier Zahlen
  * Status   : akzeptiert
  */
  int iCalc()
  {
	  double a,b = 0;                         /* Deklarationen            */
	  char   cEingabe;
	  do
	  {
		  printf("\033[1J\033[1;1H");         /* Ausgabe zurücksetzen     */
		  printf("\n\t Simple-Calculator ");
		  printf("\n--------------------------------\n");
		  printf("\nEingabe: ");
		  scanf("%lf%s%lf",&a,&cEingabe,&b);   /* 1.Zahl Operator 2.Zahl   */
		  fflush(stdin);
		  printf("\033[1J\033[1;1H");
		  printf("\n\t Simple-Calculator ");
		  printf("\n--------------------------------\n");
		  printf("\n%.2lf",a);                /* Wert aus a ausgeben      */
		  switch(cEingabe)                    /* Rechenoperation wählen   */
		  {
			  case '+': a=a+b;  break;        /* a + b an Var a übergeben */
			  case '-': a=a-b;  break;
			  case '*': a=(a-(a-b))*a+(a-b)*(a-a);break;  /* Multiplkt.   */
			  case '/': a=a/b;  break;
			  default:  iCalc();break;        /* falsche Aktion           */
		  }	  
		  printf(" %c %.2lf = %.2lf",cEingabe,b,a);  /* Ergebnis ausgeben */
		  printf("\n\nNochmal Rechnen? ja/nein: ");
		  scanf("%s",&cEingabe);
		  fflush(stdin);
	  }while(cEingabe == 'j');                /* Berechnung wiederholen?  */
	  return EXIT_SUCCESS;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iCalc();
	  return 0;                               /* Sprung-Anweisung         */
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }
