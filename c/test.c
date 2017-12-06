#include <stdio.h>

int main(void)
{
	int iZahl = 0;
	int iZaehler = 0;
	int iDurchlauf =0;
	    printf("Hier eingeben: ");
	    scanf("%i", &iDurchlauf);
        for(iZaehler = 1; iZaehler <= iDurchlauf; iZaehler++) 
	{
        printf("%i.Zahl eingeben: ", iZaehler);
		scanf("%i", &iZahl);
	}
	system("pause");
	return 0;
}
