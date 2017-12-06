// kap011/listing003_2.c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *iptr = NULL;  // Zeiger mit NULL initialisiert

  // Überprüfung vor der Verwendung
  if( iptr == NULL ) {
    printf("Zeiger hat keine gültige Adresse\n");
    return EXIT_FAILURE;
  }
  // iptr hat eine gültige Adresse ...
  return EXIT_SUCCESS;
}
