#include <stdio.h>
#include <stdlib.h>
#define max 10

int main(void)
{
	int iArray[max];
	int i;

	for(i = 0; i < max; i++)
	{
		iArray[i]=i*i;
	}
	for(i = 0; i < max; i++)
	{
		printf("Array[%d] = %d\n", i, iArray[1]);
	}
	return EXIT_SUCCESS;
}
