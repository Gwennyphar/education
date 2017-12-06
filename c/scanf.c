#include	<stdio.h>
#include	<stdlib.h>

int main()
{
	int iVar = 0;								  //iVar hier fuer die Variablen

	printf("Bitte eine Zahl eingeben: ");			   //Ausgabe fragt nach Zahl
	scanf("%d", &iVar);						 //wartet auf die Eingabe einer Zahl
	printf("Die Zahl lautet %d\n", iVar);// eingelesene Variable wird ausgegeben
	return 0;
}
