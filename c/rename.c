/* renamer.c */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
   char alt[20],neu[20];

   printf("Welche Datei wollen Sie umbenennen : ");
   scanf("%19s",alt);
   printf("Wie soll die Datei heissen: ");
   scanf("%19s",neu);
   if( (rename(alt,neu)) < 0) {
      fprintf(stderr, "Fehler beim Umbenennen von %s", alt);
      return EXIT_FAILURE;
   }
   else
   {
	   printf("Datei wurde von %s in %s umbenannt", alt, neu);
   }
   return EXIT_SUCCESS;
}
