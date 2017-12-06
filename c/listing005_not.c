// kap005/listing005.c
#include <stdio.h>

int main(void) {
  int geheimnummer;

  printf("Geheimnummer eingeben: ");
  scanf("%d", &geheimnummer);

  if( ! (geheimnummer == 123456) ) {
    printf("Geheimnummer ist falsch!\n");
  }
  else {
    printf("Geheimnummer ist richtig!\n");
  }
  return 0;
}
