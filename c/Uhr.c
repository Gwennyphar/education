#include <stdio.h>
#include <time.h>

int main()
{
	struct tm *myTm;
	clock_t finish;
	time_t now;
	time(&now);
	now = time(0);
	myTm = localtime(&now);
	printf("Sekunden seit 01.01.1970 00:00:00 Uhr: %d\n", now);
	printf("%s\n", ctime(&now));
	printf("%02d:%02d:%02d Uhr\n", myTm->tm_hour, myTm->tm_min, myTm->tm_sec);
	printf("%s\n", asctime(myTm));

	finish = clock();
	printf ("Dauer: %d Ticks\n", finish);
	return 0;
}

