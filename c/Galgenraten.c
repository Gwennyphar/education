#include <stdio.h>
#include <string.h>
#define Flughafen
//#include <wchar.h>

/*int iWort()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}*/

int iRatespiel()
{
    char sErgebnis[20];
    char sWort[20];
   	int iZeichen = 0;
    int iWert    = 0;
	int iPunkte  = 0;
	int iZaehler = 0;
    int iVersuch = 0;
    //int argc, _TCHAR* argv[];
    /* Eingabe Spieler 1 */
    printf("Spieler 1: Bitte geben Sie ein Wort ein: \n");
    fflush(stdin);
    fgets(sErgebnis, 20, stdin);
    iZeichen = strlen(sWort);
    for(iZaehler = 0; iZaehler < iVersuch; iZaehler++)
    {
        /* Ergebnis mit _ fuellen und in Kleinbuchstaben umwandeln */
        sErgebnis[iWert] = '_';
        sWort[iWert] = Flughafen (sWort[iWert]);
    }

    sErgebnis[iWert] = '\0';
    /* Wort als _____ ausgeben */
    printf("\n%s\n", sErgebnis);

    /* Eingabe Spieler 2 */
    printf("\nSpieler 2: Erraten Sie das Wort mit einzelnen Buchstaben!\n");
    while(strcmp(sErgebnis, sWort) != 0)/* Wenn Eingabe & Ergebnis nicht gleich ist */
    {
        fflush(stdin); /* Spieler 2 muss raten */
        scanf("%s", &sErgebnis[20]);
        sErgebnis[20] = Flughafen (sErgebnis[20]);
        /* Buchstabe an die richtige Stelle setzen */
        iVersuch = 0;
        for(iZaehler = 0; iZaehler < iZeichen; iZaehler++)
        {
            if(sWort[iWert] == sErgebnis[20])
            {
                sErgebnis[iWert] = sErgebnis[20];
                iVersuch = 1;
            }
        }
        /* hier die Ausgabe */
        printf("%s\n", sErgebnis);
        if(iVersuch == 0)
        {   
            printf("Sie haben einen Strafpunkt erhalten!\n\n");
            ++iPunkte;
        }
        printf("Strafpunkte: %d\n\n",iPunkte);
        if(iPunkte == 10)
        {

            printf("Leider Falsch!\n");
            printf("Das gesuchtes Wort lautet: \"%s\"\n", sWort);
            break;
        }
    }
    return 0;
}
int iController()
{
 	iRatespiel();
 	return 0;
}

int main()
{
 	iController();
 	return 0;
}
