// kap003/listing010.c
#include <stdio.h>

int main(void) {
   // Als dezimaler Wert
   printf("Eine M%cglichkeit\n", 148);
   // Als Escape-Sequenz (hexadezimal)
   printf("Ein zweite M\x94glichkeit\n");
   // Als Escape-Sequenz (hexadezimal)
   printf("Fl\x84 \bche geht nur so\n");
   // Als Escape-Sequenz (oktal)
   printf("\216hnlich als Oktalwert\n");
   printf("Alle zusammen: ");
   // Alle Umlaute mit hex. Escapesequenzen
   printf("\x8e, \x84, \x99, \x94, \x9a, \x81, \xe1\n");
   return 0;
}
