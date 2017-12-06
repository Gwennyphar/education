#include <stdio.h>
#include <stdlib.h>
#define MAX 3


int i;

void iArray_lesen( int Arr[], int n )
{
	for( i = 0; i < n; i++ )
	{
		printf("[%d] = %d\n", i, Arr[i]);
	}
}

void iArray( int Arr[], int n )
{
	for( i = 0; i < n; i++ )
	{
		Arr[i] = i+i;
	}
}

int main()
{
	int iArr[MAX];
	iArray( iArr, MAX );
	iArray_lesen( &iArr[0], MAX );
	
	return EXIT_SUCCESS;
	return 0;
}


