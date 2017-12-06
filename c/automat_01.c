/* Getraenke Automat Version 0.5 */

#include <stdio.h>

// --- Funktions-Prototypen ---------------------------
int iAuswahl_Getraenke();
int iAuswahl_Anzahl();
float iBerechne_Preis(int iSorte);
float iBetrag(float iBezahlen);
int iPruefe_Muenze(float iMuenze);
void iAusgabe_Getraenke(int iSorte, int iMenge);

// --- Hauptprogramm ----------------------------------
int main() {
	printf("Getraenke Automat v0.5\n\n");

	int iSorte, iMenge;
	float iPreis, iBezahlen, iGezahlt;
	
	iSorte = iAuswahl_Getraenke();
	iPreis = iBerechne_Preis(iSorte);
	iMenge = iAuswahl_Anzahl();
	iBezahlen = iPreis * iMenge;
	iGezahlt = iBetrag(iBezahlen);
	
	if(iGezahlt >= iBezahlen) {
		iAusgabe_Getraenke(iSorte, iMenge);
		printf("\n\nVielen Dank, bitte entnehmen sie ihre Getraenke.\n");
	}else {
		printf("\n\nBezahlvorgang abgebrochen.\n");
		printf("Ausgabe von %.2f Euro.\n", iGezahlt);
	}
	
	return 0;
}

// --- Funktionen -------------------------------------
int iAuswahl_Getraenke() {
	int iSorte;
	printf("Waehlen sie ihr Getraenk aus:\n");
	printf("1) Wasser (0,50 Euro)\n");
	printf("2) Limonade (1,00 Euro)\n");
	printf("3) Bier (2,00 Euro)\n\n");
	printf("Geben sie 1, 2 oder 3 ein: ");
	scanf("%d", &iSorte);
	return iSorte;
}

int iAuswahl_Anzahl() {
	int iMenge=1;
	printf("\nGeben sie die gewuenschte Menge ein: ");
	scanf("%d", &iMenge);
	return iMenge;
}

/*	ermittelt den Preis zu einer Sorte
	Parameter:	iSorte, Nummer der Sorte
	Return-Value:	Preis
*/
float iBerechne_Preis(int iSorte) {
	float iPreis=0;
	switch(iSorte) {
		case 1: iPreis = 0.5; break;
		case 2: iPreis = 1.0; break;
		case 3: iPreis = 2.0; break;
	}
	return iPreis;
}

/*	Startet Bezahlvorgang
	Parameter:  	iBezahlen, zu zahlender Betrag
	Return-Value:	iGezahlter Betrag
*/
float iBetrag(float iBezahlen) {
	printf("\n--- Bezahlvorgang ---\n");
	printf("\nBezahlvorgang abbrechen mit 0\n");
	float einwurf, iGezahlt=0;
	do {
		printf("\nEs fehlen noch %.2f Euro.", iBezahlen-iGezahlt);
		printf("\nBitte werfen sie ein Geldstueck ein: ");
		scanf("%f", &einwurf);

		// Abbruch pruefen
		if(einwurf == 0) {
			break;
		}
		
		// eingeworfenen Betrag anrechnen
		if(iPruefe_Muenze(einwurf))  {
			iGezahlt += einwurf;
		}else {
			printf("\nIhr Geldstueck ist ungueltig.");
		}
		
	} while(iGezahlt < iBezahlen);

	return iGezahlt;
}

/*	prueft Geldstueck auf Gueltigkeit
	Parameter:  	iMuenze, entpricht eingeworfenem Geldstueck
	Return-Value:	1, gueltige Muenze
			0, falsche Muenze
*/
int iPruefe_Muenze(float iMuenze) {	
	// Muenzwert in ganze Zahl umrechnen, also in Cent.
	// Da die case Anweisung nicht mit floats arbeiten kann.
	int cent = iMuenze * 100;
	switch(cent) {
		case 5:		return 1;
		case 10:	return 1;
		case 20:	return 1;
		case 50:	return 1;
		case 100:	return 1;
		case 200:	return 1;
		default:	return 0;
	}
}

void iAusgabe_Getraenke(int iSorte, int iMenge) {
	printf("\n--- Getraenkeausgabe ---\n");
	int i;
	for(i=0; i < iMenge; i++)  {
		printf("\nFlasche %d von %d der Sorte %d wurde ausgegeben.",
			i+1, iMenge, iSorte);
	}
}
