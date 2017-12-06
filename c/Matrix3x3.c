/** Programm : Matrizenmultiplikation
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum	 : 20.10.2010
  * Status   : in Arbeit
  * ToDo	 : Ausgabe anhuebschen
  */

/** Preaprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>

/** Prorgramm zum multiplizieren von 3x3 Arrays
  */
  int iMatrizen()
  {
	  int i; /* Spalte */
	  int j; /* Zeile */
	  int k; /* Schleife zum mutlipilzieren von Matrix A mit Matrix B */
	  /** Statische Alloziierung zweier gegebener
	    * 3x3-Matrizen mit expliziten Werten und
	    * einer mit Nullen initalisierten Loesungs-Matrix
	    */
	    int iMatA[3][3]={ {1,2,4,},{6,8,10},{12,14,16} };
	    int iMatB[3][3]={ {1,3,6,},{9,12,15},{18,21,24} };
	    int iMatC[3][3]={ {0,0,0,},{0,0,0},{0,0,0} };
     /* for-Schleifen-Zähler */
        printf("__Matrix_A__\n");
        for( i = 0; i <= 2; i++ )
        {
			for( j = 0; j <= 2; j++ )
			{
				printf("%d ", iMatA[i][j]); /* j-nte Zeile ausgeben */
			}
			printf("\n");                   /* Zeilenvorschub */
		}
		printf("\n\n");
		printf("__Matrix_B__\n");
		for( i = 0; i <= 2; i++ )
        {
			for( j = 0; j <= 2; j++ )
			{
				printf("%d ", iMatB[i][j]); /* j-nte Zeile ausgeben */
			}
			printf("\n");                   /* Zeilenvorschub */
		}
		printf("\n\n");
		printf("__Matrix_C__\n");
     /* for-Schleifen, Komponenten werden nach */
     /* Matrizen-Multiplikationsregel berechnet */
     /* c1,1 =a1,1 * b1,1 + a1,2*b2,1+ a1,3*b3,1 + a1,4 * b4.1 */
        for( i = 0; i <= 2; i++ )
        {
			for( j = 0; j <= 2; j++ )
			{
				for( k = 0; k <= 2; k++ )
				{
					iMatC[i][j] += iMatA[i][k] * iMatB[k][j];
				}
				printf("%d ", iMatC[i][j]); /* j-nte Zeile ausgeben */
			}
			printf("\n");                   /* Zeilenvorschub */
		}
		return 0; 	                        /* Rücksprung / Ende */
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
	  iMatrizen();
	  return 0;
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }

/*

Optional: Eingabe int iEingabe;
printf("\n Geben Sie Werte der Matrix A ein:");
for( i = 1; i <= 3; i++ )
{
	for( j = 1; j <= 3; j++ )
	{
		printf("\n%d.te Zeile und %d.te Spalte: ", i, j);
		scanf("%d",&iEingabe);
		iMatA[i][j] = iEingabe;
	}
}
printf("\n Geben Sie Werte der Matrix B ein:");
for( i = 1; i <= 3; i++ )
{
	for( j = 1; j <= 3; j++ )
	{
		printf("\n %d.te Zeile und %d.te Spalte : ", i, j);
		scanf("%d",&iEingabe);
		iMatB[i][j] = iEingabe;
	}
}

*/
 
