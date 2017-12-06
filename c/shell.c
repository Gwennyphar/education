#include <windows.h>
#include <stdio.h>
#include <string.h>
 
int main ()
{
	char adresse[20];
	int SH_SHOW;
	strcat(adresse, "http://google.com");
	ShellExecute(NULL, "open", "http://google.com", NULL, NULL, SW_SHOW);
	return 0;
}
