// kap011/listing003_2.c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *iptr = NULL;  // Zeiger mit NULL initialisiert

  // �berpr�fung vor der Verwendung
  if( iptr == NULL ) {
    printf("Zeiger hat keine g�ltige Adresse\n");
    return EXIT_FAILURE;
  }
  // iptr hat eine g�ltige Adresse ...
  return EXIT_SUCCESS;
}
