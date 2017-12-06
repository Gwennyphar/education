// kap010/listing006.c
#include <stdio.h>
#include <stdlib.h>
#define WOCHE 2
#define TAGE  7

void durchschnitt( int arr[][TAGE] ) {
  int durchs=0, i, j;
  for( i=0; i < WOCHE; i++) {
    for( j=0; j < TAGE; j++) {
       durchs+=arr[i][j];
    }
  }
  printf("Besucher in %d Tagen\n", WOCHE*TAGE);
  printf("Gesamt       : %d\n", durchs);
  printf("Tagesschnitt : %d\n", durchs /(WOCHE*TAGE));
}

int main(void) {
  int besucher[WOCHE][TAGE];
  int i, j;

  printf("Besucherzahlen eingeben\n\n");
  for( i=0; i < WOCHE; i++) {
    for( j=0; j < TAGE; j++) {
      printf("Woche %d, Tag %d: ", i+1, j+1);
      scanf("%d", &besucher[i][j]);
    }
  }
  durchschnitt( besucher );
  return EXIT_SUCCESS;
}
