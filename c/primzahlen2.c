#include <stdio.h>

int main (void)
{
	int zahl, teiler , limit ;
	printf(" Obergrenze eingeben : ");
	scanf("%i", &limit);
	printf("\nPrimzahlen bis %i\n", limit);
	for(zahl=2; zahl < limit; zahl++)
	{
		teiler = 2;
		while ( zahl % teiler != 0) teiler ++;
		{
			if(teiler == zahl)
			{
				printf("%i\n",zahl);
			}
		}
	}
	return 0;
}
