#include <stdio.h>
#ifdef __linux__
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#elif __WIN32__ || _MSC_VER__
#include <conio.h>
#include <windows.h>
#endif

/** Funktion : Threadfunktion fuer parallelen Ablauf
  * Status   : fertig
  */
  #ifdef __linux__
  int kbhit(void)
  {
	struct termios oldt, newt;
	int ch;
	int oldf;
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if(ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}
	return 0;
}
#endif

int main()
{
	int i = 0;
	while(1)
	{
		printf("%i",i);
		i++;
	}
	while(1)
	{
		if(kbhit())
		{
			printf("Programmende");
			break;
		}
	}
	return 0;
}
