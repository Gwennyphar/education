#include	<stdio.h>
#include	<stdlib.h>
#include	<float.h>							  //Header fuer Fließkommazahlen

int main(void)
{	 
	printf("float Genauigkeit		:	%d\n", FLT_DIG);
	printf("double Genauigkeit		:	%d\n", DBL_DIG);
	printf("long double Genauigkeit		:	%d\n", LDBL_DIG);
	return 0;
}
