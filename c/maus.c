#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h> 
int main(int argc, char *argv[])
{
int i;

int x_Zufall;
int y_Zufall;

int x_Bildschirm = GetSystemMetrics(SM_CXSCREEN);//Groesse des Bildschirms nach links(in Pixel)
int y_Bildschirm = GetSystemMetrics(SM_CYSCREEN);//Groesse des Bildschirms nach unten(in Pixel)

srand(time(0));

printf("Ein kleines Scherzprogramm!\n\n"); 

for(i=0;i<20;i++)
{
sleep(100);
x_Zufall=(rand() % x_Bildschirm + 1);
y_Zufall=(rand() % y_Bildschirm + 1);
SetCursorPos(x_Zufall,y_Zufall); 
}

system("PAUSE");
return 0;
}
