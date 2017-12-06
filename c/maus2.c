#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[])
{
int Startbuttonx=20;//nach links
int Startbuttony=GetSystemMetrics(SM_CYSCREEN)-20;//nach unten

SetCursorPos(Startbuttonx,Startbuttony);//setzt die Position der Maus
mouse_event(MOUSEEVENTF_LEFTDOWN,Startbuttonx,Startbuttony,0,0);//Mausklick starten
mouse_event(MOUSEEVENTF_LEFTUP,Startbuttonx,Startbuttony,0,0);//Mausklick beenden

system("PAUSE");
return 0;
}
