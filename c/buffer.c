#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <signal.h>
#include <curses.h>

struct termios term_attr;
int old_flags;

void restore()
{
    term_attr.c_lflag = old_flags;
    tcsetattr(0 /* STDIN */, TCSAFLUSH, &term_attr);
    exit(100);
}

int main()
{
    char passwd[20];
    if(tcgetattr(0, &term_attr) != 0)
        return 1;
    old_flags = term_attr.c_lflag;
    term_attr.c_lflag &= ~ECHO;
    if(tcsetattr(0, TCSAFLUSH, &term_attr) != 0)
        return 2;
    printf("Password: ");
    printf("%s", fgets(passwd, 20, stdin));
    signal(SIGINT, restore);
    while(1)
        sleep(2);
    return EXIT_SUCCESS;
}
