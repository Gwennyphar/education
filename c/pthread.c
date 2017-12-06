/*
** Einfaches Beispiel für die Thread-Erzeugung mit PThreads.
**
** Compilieren mit:
**    gcc -Wall -o hello -lpthread hello.c
*/

#include <stdio.h>
#include <pthread.h>

void * SayHello(void *arg)
{
  printf("Hello World!\n");
  return NULL;
}

int main(int argc, char **argv)
{
  pthread_t t;

  /* Erzeugen des Threads */
  if (pthread_create(&t, NULL, SayHello, NULL) != 0) {
    /* FEHLER: Meldung ausgeben und Programmende */
	printf("Can't create thread\n");
    return 1;
  }

  /* Warten auf Beendigung des Threads */
  pthread_join(t, NULL);

  return 0;
}
