#include <stdio.h>
#include <stdlib.h>
int iKonverter()
{

 	char cZahl;
	printf("Bitte eine Zahl oder Buchstaben eingeben: ");
	scanf("%c", &cZahl);
	printf("Dezimale Darstellung : %i \n",cZahl);
	printf("Hexadezimale Darstellung : %X \n", cZahl);
	printf("Oktale Darstellung : %o \n",cZahl);
	printf("ASCII-Darstellung : %c \n",cZahl);
	getchar();
	return 0;
}

int iController()
{
 	iKonverter();
 	return 0;
}

int main()
{
 	iController();
 	return 0;
}
