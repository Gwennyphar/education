#include <stdio.h>
#include <math.h>

int main ()
{
	int x = 2;
	int a = 2;
	printf("Bitte Zahl eingeben: ");
	scanf("%d", &x);
	fflush(stdin);
	/*Primfaktorzerlegung*/
	printf("%d = ", x);
	if (x == 2 || x == 1)
	{
		printf("%d", x);
	}
	else
	{
		while (x%a != 0)
		{
			a++;
		}
		while (x%a == 0)
		{
			x = x/a;
			printf("%d * ", a);
			while (x%a != 0)
			{
				a++;
			}
			if(x == a)
			{
				printf("%d\n", x);
				break;
			}
		}
	}
	return 0;
} 
