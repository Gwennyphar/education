#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int Matrix[10][10];
int x,y;

for(y=0;y<10;y++)
{
for(x=0;x<10;x++)
{
Matrix[y][x]=y*10+x+1;
}
}

for(y=0;y<10;y++)
{
for(x=0;x<10;x++)
{
printf("%3d ",Matrix[y][x]);
}
printf("\n");
}
return 0;
} 
