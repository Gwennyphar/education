#include <stdio.h>

int main (void)
{
	int a[100], i, j ;
	for ( i =0; i <100; i ++) a [ i ]= i ;
	{
		printf("\nDie Ersten Primzahlen ...\n ");
		for ( i =2; i <100; i ++)
		{
			if ( a [ i ] >0)
			{
				printf("%i", a[i]);
				for (j=2*i;j<100;j+=i)
				{
					a[j]=0;
				}
			}
		}
	}
	return 0;
}

