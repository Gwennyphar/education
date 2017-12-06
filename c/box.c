#include <stdio.h>
#include <windows.h>
int main (void)
{
   if (MessageBox(0,"Hallo Welt, ich grüße dich!","Ein erstes Programm",MB_OKCANCEL) == IDOK)
      {
         printf("echo: Hallo Welt");
         system ("pause");
      }
      else
      {
         printf("echo: ich grüße dich");
         system ("pause");
      }
}
