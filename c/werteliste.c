/** werteliste.c
  */
  
/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
   
/** Funktion : Werteliste von Kommandozeile uebrnehmen und auswerten
  * Status   : in Arbeit 
  */
  int main( int argc, char *argv[] )         /* main uebernimmt Argument
										        aus Kommandozeile */
  {
	  int iWert = 0;
	  for( iWert = 0; iWert < argc; iWert++)
	  {
		  printf("%s\n", argv[iWert]);   /* und gibt diese wieder aus */
	  }
	  return 0;
  }

