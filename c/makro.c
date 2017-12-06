#include	<stdio.h>
#include	<stdlib.h>

#if  		defined (__STDC_VERSION__)&&__STDC_VERSION >= 199901L
void funktion(void)
{
	printf("Name der Funktion: %s\n", __func__)
}

#else
void funktion(void)
{
	printf("Kein C99 Standard Compiler\n");
}

#endif
int main(void)
{
	//#ifdef __STDC__
	printf("Ein ANSI-C-Compiler ist im Einsatz\n");
	printf("Datum der Übersetzung: %s\n", __DATE__);
	printf("Zeit der Übersetzung : %s\n", __TIME__);
	printf("Zeile: %3d | Datei: %s\n"	, __LINE__, __FILE__);
	
	#line 99 "datei.c"
	printf("Zeile: %3d | Datei: %s\n"	, __LINE__, __FILE__);
	funktion();
	return EXIT_SUCCESS;
}