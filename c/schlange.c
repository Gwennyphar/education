#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define Schwanz 0
#define Kopf 1
#define Rumpf 2
#define FUtter 9
#define Taste_hoch 72
#define Taste_runter 80
#define Taste_links 75
#define Taste_rechts 77
#define Breite 77
#define Hoehe 22

void iCsr( unsigned int y , unsigned int x )
{
      COORD Position;
	  Position.X = x;
	  Position.Y = y;
	  SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ) , Position );
}

int i=0;
int j=0;
int y=0;
int x=0;
int iTaste = 0;

struct Position
{
	int x;
	int y;
}stPos;

int iFeld[Breite][Hoehe];
void setItem(int, int, int);

void iBewegen()
{
	setItem(stPos.x, stPos.y, Rumpf);
	iTaste = getch();
	switch(iTaste)
    {
		case Taste_hoch:
        {
            stPos.y--;
            break;
        }
		case Taste_links:
        {
             stPos.x--;
             break;
        }
		case Taste_runter:
        {
             stPos.y++;
             break;
        }
		case Taste_rechts:
        {
             stPos.x++;
             break;
        }
	}
	if(stPos.y > Hoehe) stPos.y=0;
	if(stPos.y < 0) stPos.y=Hoehe-1;
	if(stPos.x > Breite) stPos.x=0;
	if(stPos.x < 0) stPos.x=Breite-1;
	setItem(stPos.x, stPos.y, Kopf);
}

void setItem(int x, int y, int item)
{
	iFeld[x][y] = item;
}

void iAusgabe_vergessen()
{
	for(i=0;i<Hoehe;i++)
    {
		for(j=0;j<Breite;j++)
        {
			iFeld[i][j] = Schwanz;
		}
	}
}

void iSnake()
{
	iCsr(y,x);

	int i,j,x;
	for(i=0;i<Hoehe+2;i++)
    {
		printf("\n");
		printf("|");
		for(j=0;j<Breite;j++)
        {
			if(i==0 || i==Hoehe+1)
            {
				printf("_");
			}
			else
            {
				x = iFeld[j][i];
				switch(x)
                {
                    case Schwanz: printf(" "); break;
				    case Rumpf: printf("*"); break;
			      	case Kopf: printf("O"); break;
			    }
		    }
    	}
        printf("|");
	}
}

int iGame()
{
	while(iTaste!='x')
    {
		iSnake();
		iBewegen();
	}
	printf("\n\n");
}

int main ()
{
    iGame();
	return 0;
}
