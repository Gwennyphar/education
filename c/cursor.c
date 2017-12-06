#include <windows.h>

void Gotoxy(int x, int y)
{
   COORD coord;
   coord.X = x;
   coord.Y = y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

main (void)
{ 
  printf("Ich bin ein Blindtext");
  getchar();
  Gotoxy(0,0);
  printf("Ich bin der neue Blindtext");
  getchar();
  Gotoxy(10,10);
  printf("springe hier hin");
  getchar();
}
 
