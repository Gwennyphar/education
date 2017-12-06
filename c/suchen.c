#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
FILE *f;
int c;
long Position = 0;
f=fopen("1Test.txt","a+");

printf("Die letzten 10 Zeichen:\n");
fseek(f, -10L, SEEK_END);
while( (c=getc(f)) != EOF) printf("%c",c);

printf("\n\nDer gesamte Inhalt der Datei lautet:\n");
fseek(f, 0L, SEEK_SET);
while( (c=getc(f)) != EOF) printf("%c",c);

printf("\n\nAb welcher Position wollen Sie die Datei ausgeben: ");
scanf("%ld",&Position);
getchar();
fseek(f, 0L, SEEK_SET);
fseek(f, Position,SEEK_CUR);
while( (c=getc(f)) != EOF) printf("%c",c);

printf("\n\nDie Dateigroesse: %ld\n\n",ftell(f));
fclose(f);

system("PAUSE");
return 0;
}
