#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Funktion : Bidlschirm und Cursor zuruecksetzen
  * Status   : fertig
  */
  void clr()
  {
	  printf("\033[1J\033[1;1H");;
  }

/** Funktion : Tastaturpuffer leeren
  * Status   : fertig
  */
  void flush()
  {
	  int c;
	  while( ((c = getchar()) != EOF) && (c != '\n') );
  }

void Error()
{
	clr();
	printf("Stein, Schere, Papier\n");
	printf("---------------------\n\n");
	printf("Du hast eine falsche Taste gedrückt");
}

int iBattle();
int iAuswahl();

int iIntro()
{
	clr();
	printf("Stein, Schere, Papier\n");
	printf("---------------------\n\n");
	printf("Stein gewinnt..: Die Klingen der Schere gehen am Stein kaputt\n");
	printf("Schere gewinnt.: Die Schere zerschneidet das Papier\n");
	printf("Papier gewinnt.: Das Papier umwickelt den Stein\n");
	printf("Unentschieden..: Sowohl der PC als auch du haben das Gleiche gewählt\n\n");
	iAuswahl();
	return EXIT_SUCCESS;	
}

int iAuswahl()
{
	char cEingabe[5];
	char cTaste;
	do
	{
		printf("\n\nNeues Spiel? ja/nein ");
		fgets(cEingabe, sizeof(cEingabe), stdin);
		sscanf(cEingabe, "%c", &cTaste);
		switch(cTaste)
		{
			case 'j':
			case 'J':
			{
				iBattle();
				break;
			}
			case 'n':
			case 'N':
			{
				return EXIT_SUCCESS;
			}
			default:
			{
				Error();
				break;
			}
		}
	}while(cTaste != 'n' || 'N');
	return EXIT_SUCCESS;
}

int iBattle()
{
	int iZaehler = 1;
	int iPC      = 0;
	int iSpieler = 0;
	int iRunden = 0;
	int iSpPkt  = 0;
	int iPCPkt  = 0;
	char cEingabe[5];
	clr();
	printf("Stein, Schere, Papier\n");
	printf("---------------------\n\n");
	printf("Wieviele Runden? ");
	fgets(cEingabe, sizeof(cEingabe), stdin);
	sscanf(cEingabe, "%i", &iRunden);
	if(iRunden == 0)
	{
		printf("0 Runden sind nicht möglich!");
		iAuswahl();
		return EXIT_SUCCESS;
	}
	else if(iRunden < 0)
	{
		printf("Cheaten ist nicht erlaubt!");
		iAuswahl();
		return EXIT_FAILURE;
	}
	else
	{
		iRunden = iRunden + 1;
	}
	do
	{
		srand(time(NULL));
		clr();
		printf("Stein, Schere, Papier\n");
		printf("---------------------\n\n");
		printf("Du bist in der ");
		if (iZaehler == iRunden -1)
		{
			printf("letzten Runde!\n\n");
		}
		else
		{
			printf("%i. Runde!\tSpieler: %i | Computer: %i\n\n", iZaehler, iSpPkt, iPCPkt);
		}
		printf("-1- Stein\n");
		printf("-2- Schere\n");
		printf("-3- Papier\n\n");
		printf("Wähle deine Waffe: ");
		iPC = rand() %3+1;
		scanf("%i", &iSpieler);
		flush();
		clr();
		printf("Stein, Schere, Papier\n");
		printf("---------------------\n\n");
		if(iSpieler == 1 && iPC == 1)
		{
			printf("Stein vs. Stein!\tSpieler: %i | Computer: %i", iSpPkt, iPCPkt);
			printf("\n\nUnentschieden!");
		}
		else if(iSpieler == 2 && iPC == 2)
		{
			printf("Schere vs. Schere!\tSpieler: %i | Computer: %i", iSpPkt, iPCPkt);
			printf("\n\nUnentschieden!");
		}
		else if(iSpieler == 3 && iPC == 3)
		{
			printf("Papier vs. Papier!\tSpieler: %i | Computer: %i", iSpPkt, iPCPkt);
			printf("\n\nUnentschieden!");
		}	
		else if(iSpieler == 1 && iPC == 2)
		{
			iSpPkt++;
			printf("Stein vs. Schere!\tSpieler: %i | Computer: %i", iSpPkt, iPCPkt);
			printf("\n\nStein gewinnt!");
		}
		else if(iSpieler== 1 && iPC == 3)
		{
			iPCPkt++;
			printf("Stein vs. Papier!\tSpieler: %i | Computer: %i", iSpPkt, iPCPkt);
			printf("\n\nStein verliert!");
		}
		else if(iSpieler == 2 && iPC == 1)
		{
			iPCPkt++;
			printf("Schere vs. Stein!\tSpieler: %i | Computer: %i", iSpPkt, iPCPkt);
			printf("\n\nSchere verliert!");
		}
		else if(iSpieler == 3 && iPC == 1)
		{
			iSpPkt++;
			printf("Papier vs. Stein!\tSpieler: %i | Computer: %i", iSpPkt, iPCPkt);
			printf("\n\nPapier gewinnt!");
		}
		else if(iSpieler == 2 && iPC == 3)
		{
			iSpPkt++;
			printf("Schere vs. Papier!\tSpieler: %i | Computer: %i", iSpPkt, iPCPkt);
			printf("\n\nSchere gewinnt!");
		}
		else if(iSpieler == 3 && iPC == 2)
		{
			iPCPkt++;
			printf("Papier vs. Schere!\tSpieler: %i | Computer: %i", iSpPkt, iPCPkt);
			printf("\n\nPapier verliert!");
		}
		else if(iSpieler != 1 || iSpieler != 2 || iSpieler != 3)
		{
			Error();
			iZaehler--;			
		}
		iZaehler++;
		getchar();
	}while(iZaehler != iRunden);
	clr();
	printf("Stein, Schere, Papier\n");
	printf("---------------------\n\n");
	printf("Punktestand: Spieler: %i | Computer: %i\n\n", iSpPkt, iPCPkt);
	printf("Du hast ");
    if (iSpPkt <= 0.5 * iRunden && iSpPkt != 0)
    {
		printf("%i von %i Spielen gewonnen.", iSpPkt, iRunden-1);
    }
    else if (iSpPkt == 0)
    {
		printf("kein einziges Spiel gewonnen!");
    }
    else if (iSpPkt > 0.5 * iRunden && iSpPkt != iRunden)
    {
         printf("%i von %i Spielen gewonnen.", iSpPkt, iRunden-1);
    }
    else if (iSpPkt == iRunden)
    {
         printf("alle Spiele gewonnen!");
    }
    else if (iSpPkt == iRunden * 0.5)
    {
         printf("%i von %i Spielen gewonnen.", iSpPkt, iRunden-1);
    }
    else if (iSpPkt == iPCPkt)
    {
		printf("\n\nDu hast dich gut geschlagen");
    }
    else
    {
        printf("\n\nIrgendwas ist falsch gelaufen");
    }
    iAuswahl();
	return EXIT_SUCCESS;
}

int iController()
{
	iIntro();
	return EXIT_SUCCESS;
}

int main()
{
	iController();
	return EXIT_SUCCESS;
}
