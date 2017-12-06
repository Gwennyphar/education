/** Nico Anders
  * tamagotchi v.1
  * Grundmenge an Salz pro Gewicht steigen lassen
  */
  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
//#include "mylib.h"

void clr()
{
	printf("\033[1J\033[1;1H");
}

void flush()
{
	int c;
	while( ((c = getchar()) != EOF) && (c != '\n') );
}

int ctrl() 
{
	static int ch = -1, fd = 0;
	struct termios neu, alt;
	fd = fileno(stdin);
	tcgetattr(fd, &alt);
	neu = alt;
	neu.c_lflag &= ~(ICANON|ECHO);
	tcsetattr(fd, TCSANOW, &neu);
	ch = getchar();
	tcsetattr(fd, TCSANOW, &alt);
	return ch;
}

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

void Anzeigen();
int iController();
int counter = 1;
int leben   = 3;
int Auswahl = 1;

struct
{
	/*Eigenschaften des Tamagotchis*/
	double Koerpergewicht;
	double totmenge;
	double gegessenesSalz;
	double salzmenge;
	double futter;
	double runden;
	double Hunger;
	double Happyness;
	double reinigen;
}Tamagotchi;

void csr( unsigned int y , unsigned int x )
{
	printf("\033[%i;%iH" , ( y + 1 ) , ( x + 1 ) );
}

void Tot()
{
	if(Auswahl == 1)
	{
		csr(7,55);
		printf("()__()");
		csr(8,55);
		printf("= x_x)=");
		csr(9,55);
		printf("(\")(\")");
	}
	else if(Auswahl == 2 && leben >= 8)
	{
		csr(6,55);
		printf("  ///");
		csr(7,55);
		printf("<(x )___");
		csr(8,55);
		printf(" ( ._> /");
		csr(9,55);
		printf("  `---'");		
	}
	else if(Auswahl == 3 && leben >= 12)
	{
		csr(6,55);
		printf(" __");
		csr(7,55);
		printf("(_x\\.-.");
		csr(8,55);
		printf("  \\/___\\_");
		csr(9,55);
		printf("    u u");
	}
    getchar();	
}

void ASCII()
{
	if(Auswahl == 1 || Auswahl == 0)
	{
		if(Tamagotchi.Koerpergewicht <= 100.00 || Tamagotchi.Happyness <= 50.00 )
		{
			csr(7,55);
			printf("()__()");
			csr(8,55);
			printf("= -,-)=");
			csr(9,55);
			printf("(\")(\")");		
		}
		if(Tamagotchi.Koerpergewicht >= 100.00 && Tamagotchi.Koerpergewicht <= 900.00)
		{
			csr(7,55);
			printf("()__()");
			csr(8,55);
			printf("= 0.0)=");
			csr(9,55);
			printf("(\")(\")");
		
		}	
		if(Tamagotchi.Happyness <= 15.00)
		{
			csr(7,55);
			printf("()__()");
			csr(8,55);
			printf("= ;.;)=");
			csr(9,55);
			printf("(\")(\")");
			if(Tamagotchi.Happyness <= 10.00)
			{
				csr(7,62);
				printf("  (");
				csr(8,62);
				printf(" (_)");
				csr(9,62);
				printf("(___)");
				csr(8,55);
				printf("= >=_<=)=");
			}		
		}
		else if(Tamagotchi.Happyness >= 50.00)
		{
			csr(7,55);
			printf("()__()");
			csr(8,55);
			printf("= ^.^)=");
			csr(9,55);
			printf("(\")(\")");	
		}
		else if(Tamagotchi.Hunger >= 75.00)
		{
			csr(7,55);
			printf("()__()");
			csr(8,55);
			printf("= ';')=");
			csr(9,55);
			printf("(\")(\")");	
		}
	}
	if(leben >= 8 && leben <= 12)
	{
		if(Auswahl == 2 || Auswahl == 0)
		{
			if(Tamagotchi.Koerpergewicht <= 100.00 || Tamagotchi.Happyness <= 50.00 )
			{
				csr(6,55);
				printf("  ///");
				csr(7,55);
				printf("<(' )___");
				csr(8,55);
				printf(" ( ._> /");
				csr(9,55);
				printf("  `---'");	
			}
			if(Tamagotchi.Koerpergewicht >= 100.00 && Tamagotchi.Koerpergewicht <= 900.00)
			{
				csr(6,55);
				printf("  ///");
				csr(7,55);
				printf("<(0 )___");
				csr(8,55);
				printf(" ( ._> /");
				csr(9,55);
				printf("  `---'");		
			}	
			if(Tamagotchi.Happyness <= 15.00)
			{
				csr(6,55);
				printf("  ///");
				csr(7,55);
				printf("=(; )___");
				csr(8,55);
				printf(" ( ._> /");
				csr(9,55);
				printf("  `---'");	
				if(Tamagotchi.Happyness <= 10.00)
				{
					csr(6,62);
					printf("  (");
					csr(7,62);
					printf(" (_)");
					csr(8,62);
					printf("(___)");
					csr(7,55);
					printf("=(- )___");
				}		
			}
			else if(Tamagotchi.Happyness >= 50.00)
			{
				csr(6,55);
				printf("  ///");
				csr(7,55);
				printf(">=(^ )___");
				csr(8,55);
				printf(" ( ._> /");
				csr(9,55);
				printf("  `---'");	
			}
			else if(Tamagotchi.Hunger >= 75.00)
			{
				csr(6,55);
				printf("  ///");
				csr(7,55);
				printf(">=(0 )___");
				csr(8,55);
				printf(" ( ._> /");
				csr(9,55);
				printf("  `---'");	
			}
		}
	}
	if(leben >= 12)
	{
		if(Auswahl == 3 || Auswahl == 0)
		{
			if(Tamagotchi.Koerpergewicht <= 100.00 || Tamagotchi.Happyness <= 50.00 )
			{
				csr(6,55);
				printf(" __");
				csr(7,55);
				printf("(_'\\.-.");
				csr(8,55);
				printf("  \\/___\\_");
				csr(9,55);
				printf("    u u");		
			}
			if(Tamagotchi.Koerpergewicht >= 100.00 && Tamagotchi.Koerpergewicht <= 900.00)
			{
				csr(6,55);
				printf(" __");
				csr(7,55);
				printf("(_*\\.-.");
				csr(8,55);
				printf("  \\/___\\_");
				csr(9,55);
				printf("    u u");			
			}	
			if(Tamagotchi.Happyness <= 15.00)
			{
				csr(6,55);
				printf(" __");
				csr(7,55);
				printf("(_;\\.-.");
				csr(8,55);
				printf("  \\/___\\_");
				csr(9,55);
				printf("    u u");		
				if(Tamagotchi.Happyness <= 10.00)
				{
					csr(6,62);
					printf("  (");
					csr(7,62);
					printf(" (_)");
					csr(8,62);
					printf("(___)");
					csr(7,55);
					printf("(_-\\.-.");
				}		
			}
			else if(Tamagotchi.Happyness >= 50.00)
			{
				csr(6,55);
				printf(" __");
				csr(7,55);
				printf("(_^\\.-.");
				csr(8,55);
				printf("  \\/___\\_");
				csr(9,55);
				printf("    u u");		
			}
			else if(Tamagotchi.Hunger >= 75.00)
			{
				csr(6,55);
				printf(" __");
				csr(7,55);
				printf(")_0\\.-.");
				csr(8,55);
				printf("  \\/___\\_");
				csr(9,55);
				printf("    u u");	
			}		
		}
	}
}

void Avatar()
{
	do
	{
		clr();
		printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
		csr(5,8);
		printf("()__()");
		csr(6,8);
		printf("= '.')=");
		csr(7,5);
		printf(",;,(\")(\"),,,;,,,,;,,,,;,,,,,,,;,,,,;,");
		if(leben >= 8 && leben <= 12)
		{
			csr(4,30);
			printf("  ///");
			csr(5,30);
			printf("<(' )___");
			csr(6,31);
			printf("( ._> /");
			csr(7,32);
			printf("`---'");
		}
		if(leben >= 12)
		{
			csr(4,19);
			printf("__");
			csr(5,18);
			printf("(_'\\.-.");
			csr(6,20);
			printf("\\/___\\_");
			csr(7,22);
			printf("u u");
		}
	
		
		printf("\n\n     Welches Tamagotchi möchten Sie wählen?\n");
		printf("\n     -1- Maus");
		if(leben >= 8 && leben <= 12)
		{
			printf("\n     -2- Ente");
		}
		if(leben >= 12)
		{
			printf("\n     -3- Schildkröte");
		}
		printf("\n\n     Mit 0 Auswahl abbrechen: ");
		scanf("%i", &Auswahl);
		flush();
		if(Auswahl == 1)
		{
			break;
		}
		if(leben >= 8 && leben <= 12)
		{
			if(Auswahl == 2)
			{
				break;
			}
		}
		if(leben >= 12)
		{
			if(Auswahl == 3)
			{
				break;
			}
		}
		
	}while(Auswahl != 0);
		clr();
		printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
		csr(5,8);
		printf("()__()");
		csr(6,8);
		printf("= '.')=");
		csr(7,5);
		printf(",;,(\")(\"),,,;,,,,;,,,,;,,,,,,,;,,,,;,");
		if(leben >= 8 && leben <= 12)
		{
			csr(4,30);
			printf("  ///");
			csr(5,30);
			printf("<(' )___");
			csr(6,31);
			printf("( ._> /");
			csr(7,32);
			printf("`---'");
		}
		if(leben >= 12)
		{
			csr(4,19);
			printf("__");
			csr(5,18);
			printf("(_'\\.-.");
			csr(6,20);
			printf("\\/___\\_");
			csr(7,22);
			printf("u u");
		}
		printf("\n");
}

void Tier()
{
	clr();
	srand(time(NULL));
	Tamagotchi.Koerpergewicht = rand() %100+1;
	Tamagotchi.Happyness = rand() %100+1;
	Tamagotchi.Hunger = rand() %100+1;
	if(Tamagotchi.Koerpergewicht <= 45.00)
	{
		Tamagotchi.Koerpergewicht = 47.00;
	}
	if(Tamagotchi.Koerpergewicht >= 65.00)
	{
		Tamagotchi.Koerpergewicht = 65.00;
	}
	if(Tamagotchi.Happyness <= 10.00)
	{
		Tamagotchi.Happyness = 16.00;
	}
	if(Tamagotchi.Happyness >= 25.00)
	{
		Tamagotchi.Happyness = 25.00;
	}
	if(Tamagotchi.Hunger >= 75.00)
	{
		Tamagotchi.Hunger = 70.00;
	}
	/*menge die umbringt wird errechnet*/
	Tamagotchi.totmenge       = Tamagotchi.Koerpergewicht * 0.003;
	Anzeigen();
}
/*mit Salz behandeln*/
void Salz()
{
	clr();
	printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
	printf("     Wie viel Salz soll ihr Tamagotchi essen?\n");
	printf("     Mit 0 Handlung abbrechen: ");
	scanf("%lf", &Tamagotchi.salzmenge);
	flush();
	if(Tamagotchi.salzmenge <= 0.00)
	{
	}
	else
	{
		Tamagotchi.gegessenesSalz = Tamagotchi.gegessenesSalz + Tamagotchi.salzmenge;
		if(Tamagotchi.gegessenesSalz >= 0.500)
		{
			Tamagotchi.Happyness      = Tamagotchi.Happyness - 10.00;
			if(Tamagotchi.gegessenesSalz >= 1.00)
			{
				leben--;
				if(leben == 0)
				{
					leben = 1;
				}
			}
		}
		clr();
		printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
		printf("     Tamagotchi hat nun %.2lf Gramm Salz im Blut\n", Tamagotchi.gegessenesSalz);
	}
}
/*Futter geben*/
void Fuettern()
{
	clr();
	printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
	printf("     Wie viel Gramm soll ihr Tamagotchi essen?\n");
	printf("     Mit 0 Handlung abbrechen: ");
	scanf("%lf", &Tamagotchi.futter);
	flush();
	if(Tamagotchi.futter <= 0.00 || Tamagotchi.Hunger <= 25.00 || Tamagotchi.Koerpergewicht >= 860.00)
	{
	}
	else
	{
		Tamagotchi.Koerpergewicht = Tamagotchi.Koerpergewicht + Tamagotchi.futter;
		Tamagotchi.futter         = Tamagotchi.Hunger * Tamagotchi.futter / 100.00;    
		Tamagotchi.totmenge       = Tamagotchi.Koerpergewicht * 0.003;

		if(Tamagotchi.futter >= 900.00)
		{
			Tamagotchi.Koerpergewicht = 545.00;
		}
		if(Tamagotchi.Koerpergewicht >= 860.00)
		{
			leben--;
			if(leben == 0)
			{
				leben = 1;
			}
		}
		Tamagotchi.Hunger = Tamagotchi.Hunger - Tamagotchi.futter;
		if(Tamagotchi.Hunger <= 0.00)
		{
			Tamagotchi.Hunger = 0.00;
			Tamagotchi.Happyness = Tamagotchi.Happyness + 10.00;
			if(Tamagotchi.Happyness >= 100.00)
			{
				Tamagotchi.Happyness = 100.00;
			}
		}
		clr();
		printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
		printf("     Tamagotchi wiegt nun: %.2lf g\n", Tamagotchi.Koerpergewicht);
	}	
}
/*Ist noch nicht drin*/
void Trainieren()
{
	clr();
	printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
	printf("     Wie viele Runden soll ihr Tamagotchi laufen?\n");
	printf("     Mit 0 Handlung abbrechen: ");
	scanf("%lf", &Tamagotchi.runden);
	flush();
	if(Tamagotchi.runden <= 0.00 || Tamagotchi.Koerpergewicht <= 150.00)
	{
	}
	else 
	{
		if(Tamagotchi.runden >= 50)
		{
			Tamagotchi.Hunger = Tamagotchi.Hunger + 5.00;
			Tamagotchi.Happyness = Tamagotchi.Happyness + 10.00;
			if(Tamagotchi.Hunger >= 100.00)
			{
				Tamagotchi.Hunger = 100.00;
			}
			if(Tamagotchi.Happyness >= 100.00)
			{
				Tamagotchi.Happyness = 100.00;
			}
		}
		Tamagotchi.Koerpergewicht = Tamagotchi.Koerpergewicht - Tamagotchi.runden;
		Tamagotchi.totmenge       = Tamagotchi.Koerpergewicht * 0.003;
		if(Tamagotchi.Koerpergewicht <= 45.00)
		{
			Tamagotchi.Koerpergewicht = 47.00;
		}
		if(Tamagotchi.Happyness >= 90.00 && Tamagotchi.Hunger <= 25.00)
		{
			leben++;
			if(leben >= 15)
			{
				leben = 15;
			}
		}
		clr();
		printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
		printf("     Tamagotchi hat nun: %i/15 Lebenspunkte\n", leben);
	}
}
/* Tier sauber halten */
void Hygiene()
{
	clr();
	printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
	printf("     Wie oft soll ihr Tamagotchi gereinigt werden?\n");
	printf("     Mit 0 Handlung abbrechen: ");
	scanf("%lf", &Tamagotchi.reinigen);
	flush();
	if(Tamagotchi.reinigen <= 0.00 || Tamagotchi.Happyness >= 50.00)
	{
	}
	else
	{
		if(Tamagotchi.reinigen >= 100.00)
		{
			Tamagotchi.reinigen = 75.00;
		}
		Tamagotchi.reinigen  = Tamagotchi.Happyness * Tamagotchi.reinigen / 100.00;
		Tamagotchi.Happyness = Tamagotchi.Happyness + Tamagotchi.reinigen;
		if(Tamagotchi.Happyness >= 100.00)
		{
			Tamagotchi.Happyness = 100.00;
		}
		clr();
		printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
		printf("     Tamagotchi ist nun zu %.2lf%% gluecklich\n", Tamagotchi.Happyness);
	}
}
void Anzeigen()
{
	FILE *FP;
	while(1)
	{
		clr();
		printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
		ASCII();
		csr(4,0);
		printf("     Ihr Tamagotchi      : %i/15 Lebenspunkte\n\n",leben );
		printf("     wiegt zur Zeit......: %.2lf g\n",Tamagotchi.Koerpergewicht);
		printf("     mit einem Hunger von: %.2lf %%\n",Tamagotchi.Hunger);
		printf("     Hat zur Zeit........: %.2lf g Salz im Blut\n", Tamagotchi.gegessenesSalz);
		printf("     und ist zur Zeit zu.: %.2lf %% glücklich\n", Tamagotchi.Happyness);
		printf("\n     Was möchten Sie mit ihrem Tamagotchi machen?\n     Mit 0 Handlungen anzeigen lassen: ");
		csr(23,0);
        printf("     (c)2012 Nico Anders v.1.2");
        csr(12,39);
        Tamagotchi.Hunger = Tamagotchi.Hunger + 0.00005;
		Tamagotchi.Happyness = Tamagotchi.Happyness - 0.00002;
		if(Tamagotchi.Happyness <= 0.00)
		{
			Tamagotchi.Happyness = 0.00;
		}
		if(Tamagotchi.Hunger >= 75.00 || Tamagotchi.Happyness <= 15.00)
		{
            Tamagotchi.Koerpergewicht = Tamagotchi.Koerpergewicht - 0.00006;
            if(Tamagotchi.Hunger >= 75.00)
			{
				printf("\n\n     Ihr Tamagotchi hat Hunger\n");
			}
			else if(Tamagotchi.Happyness <= 15.00)
			{
				printf("\n\n     Ihr Tamagotchi fühlt sich unwohl\n");
			}
			printf("\a");
			csr(12,39);
		}
		if(Tamagotchi.Happyness <= 5.00 || Tamagotchi.Hunger >= 95.00 || Tamagotchi.Koerpergewicht <= 45.00)
		{
			leben = 1;
		}
        if(Tamagotchi.Koerpergewicht <= 46.00)
        {
			printf("\n\n     Ihr Tamagotchi wird bald sterben\n");
			printf("\a");
			csr(12,39);
        }
		if(Tamagotchi.Hunger == 100.00 || Tamagotchi.Koerpergewicht == 44.00 || Tamagotchi.Happyness
		== 00.00)
		{
			clr();
			printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
			printf("     Tamagotchi ist gestorben\n");
			Tot();
			FP = fopen("lock", "w");
			fclose(FP);
			exit(1);
		}
		if(kbhit())
		{
			break;
		}
		usleep(120000);
	}
}

int iController()
{
	char Aktion;
	FILE *FP;
	FP = fopen("lock", "r");
	if(FP != NULL)
	{
		printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
		printf("     Ihr Tamagotchi ist bereits gestorben\n     Mit 0 Reseten: ");
		scanf("%c", &Aktion);
		flush();
		if(Aktion == '0')
		{
			remove("lock");
			Tier();
		}
		else
		{
			return 0;
		}
	}
	clr();
	printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
	/*Tamagotchi wird erstellt*/
	Tier();
	do
	{
		printf("\n     Was möchten Sie mit ihrem Tamagotchi machen?\n     Mit 0 Handlungen anzeigen lassen: ");
		Aktion = ctrl();
		/*Hier schaut es nun, welche Aktivität man eingegeben hat und sucht danach die Funktion*/
		clr();
		if(Aktion == '0')
		{
			printf("\n\n     T A M A G O T C H I  S A L Z - M O R D\n\n");
			printf("     -0- Handlungen Anzeigen\n");
			printf("     -1- Tamagotchi Versalzen\n");
			printf("     -2- Tamagotchi Füttern\n");
			printf("     -3- Tamagotchi Trainieren\n");
			printf("     -4- Tamagotchi Reinigen\n");
			printf("     -5- Tamagotchi Anzeigen\n");
			printf("     -6- Tamagotchi Auswählen\n");
			//bringt die Schleife wieder zum Start zurück
			continue;
		}
		else if(Aktion == '1')
		{
			Salz();
			/*Hier läuft die Abfrage, ob die Salzmenge im Blut des Tamagotchis mehr ist, als die menge die es umbringt*/
			if(Tamagotchi.gegessenesSalz >= Tamagotchi.totmenge)
			{
				printf("     Sie sind ein Mörder!\n");
				Tot();
				//wenn das der fall ist, endet die schleife
				FP = fopen("lock", "w");
				fclose(FP);
				break;
			}
		}
		else if(Aktion == '2')
		{
			Fuettern();
		}
		else if(Aktion == '3')
		{
			Trainieren();	 
		}
		else if(Aktion == '4')
		{
			Hygiene();
		}
		else if(Aktion == '5')
		{
			Anzeigen();
		}
		else if(Aktion == '6')
		{
			Avatar();
		}
	/*nun wird geprüft, ob die eingabe eine 99 war*/
	}while(Aktion != 99);
	/*ende der schleife*/
	return EXIT_SUCCESS;
}

int main()
{
	iController();
	return EXIT_SUCCESS;
}
