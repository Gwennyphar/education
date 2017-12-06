#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	system("sudo lshw -html > ~/System.html");
	printf("System.html liegt jetzt in deinem Home Verzeichnis :)");
	getchar();
	return 0;
}

