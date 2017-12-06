#include <time.h>
#include <stdio.h>
int main()
{
char dateiname[256]="";
struct tm *LokalZeit;
time_t Zeit;
time(&Zeit);
LokalZeit = localtime(&Zeit);
sprintf(dateiname, "test%02d%02d%d.txt",
LokalZeit->tm_mday,
LokalZeit->tm_mon+1,
LokalZeit->tm_year+1900);
return 0;
}
