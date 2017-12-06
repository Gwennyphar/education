/** Programmname : Matrizen
  * Autor        : Nico Anders
  * Version      : 0.1
  * Datum        : 11.09.2010
  * Status       : in Arbeit
  */

/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>

/** Matrix
  */
  int iMatrix()
  {
	  int i        = 0;
	  int j        = 0;
	  int iZeilen   = 0;
	  int iSpalten = 0;
	  int **matrix;
	  printf("Wie viele Zeilen? ");
	  fflush(stdin);
	  scanf("%i", &iZeilen);
	  printf("Wie viele Spalten? ");
	  fflush(stdin);
	  scanf("%i", &iSpalten);
	  /* Speicher für Zeilen reservieren */
	  matrix = malloc(iZeilen * sizeof(int) );
	  if( NULL == matrix )
	  {
		  printf("Kein virtueller RAM mehr vorhanden...!");
		  return EXIT_FAILURE;
	  }
	  /* Speicher für die einzelnen Spalten reservieren */
	  for( i = 0; i < iZeilen; i++ )
	  {
		  matrix[i] = malloc(iSpalten * sizeof(int) );
		  if( NULL == matrix[i] )
		  {
			  printf("Kein Speicher mehr für Zeile %i\n", i);
			  return EXIT_FAILURE;
		  }
	  }
	  /* Mit beliebigen Wert initialisieren */
	  for( i = 0; i < iZeilen; i++ )
	  {
		  for( j = 0; j < iSpalten; j++ )
		  {
			  matrix[i][j] = i + j;
			  /* Inhalt ausgeben */
			  for( j = 0; j < iSpalten; j++)
			  {
				  printf("%i", matrix[i][j]);
				  printf("\n");
			  }
		  }
	  }
	  /* Speicherplatz wieder freigeben, in umgekehrter Reihenfolge */
	  for( i = 0; i < iZeilen; i++ )
	  {
		  free(matrix[i]);
		  free(matrix);
	  }
	  return EXIT_SUCCESS;
  }

/** Steuerprogramm
  */
  int iController()
  {
	  iMatrix();
	  return 0;
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  } 

	  
    
