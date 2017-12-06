  #include <stdio.h>
  #include <time.h>

  int main(void)
  {
    time_t t;

    time(&t);
    printf("%s", ctime(&t));
    //sprintf(stAbfragen.sDatum, "%s", ctime(&t));
    return 0;
  }

