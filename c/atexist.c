#include <stdio.h>
  #include <stdlib.h>
  void exit_fn1(void)
  {
     printf("Exit function #1 called\n");
  }
  void exit_fn2(void)
  {
     printf("Exit function #2 called\n");
  }
  int main(void)
  {
     /* Exit-Funktion 1 registrieren */
     atexit(exit_fn1);
     /* Exit-Funktion 2 registrieren */
     atexit(exit_fn2);
     return 0;
  }
