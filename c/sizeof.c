/** sizeof.c
  */

/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

/** Byte eines Array mit sizeof ermitteln (defekt)
  */
  int main(void)
  {
	  int    iArray[] = { 2, 4, 6, 4, 2, 4, 5, 6, 7 };
	  double dArray[] = { 3.3, 4.4, 2.3, 5.8, 7.7 };
	  char   str[]    = { "Hello World" };

	  printf("Ganzzahl-Array        : %d Byte's\n", sizeof(iArray) );
	  printf("Ganzzahl-Array        : %d Elemente\n", sizeof(iArray)/sizeof(int) );
	  printf("Gleitpunktzahl-Array  : %d Bytes\n", sizeof(dArray);
	  printf("Gleitpunktzahl-Array  : %d Elemente\n", sizeof(dArray)/sizeof(double) );
	  printf("Stringlänge           : %d Byte's\n", sizeof(str) );
	  printf("Stringlänge           : %d Elemente (Groeße)\n", sizeof(str)/sizeof(char) );
	  printf("Stringlänge           : %d Elemente (strlen)", strlen(str) +1);
	  return EXIT_SUCCESS;
  }
