#include <stdio.h>

/* notwendig, wenn I/O - Funktionen verwendet werden */

int main(void)
{
	char cKeyPressed; 
	/* Variable, die eingelesenes Zeichen aufnimmt */
	
	printf("Geben Sie ein Zeichen ein!\n");
	cKeyPressed = (char) getchar();
	/*---------> explizite Typumwandlung zu char!! <---------*/
	getchar(); /* ein dummy-Aufruf, um den Zeilenvorschub
	              aus dem Tastaturpuffer auszulesen */
	 printf("Sie habe folgendes Zeichen eingegeben:\n");
	 putchar(cKeyPressed);
	 return 0;
}
