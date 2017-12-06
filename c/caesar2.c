#include <iostream>
using namespace std;

int main () {
	
	int zaehler1=1, zaehler2=1,ver_zahle,ver_zahlr;
	char eingabe[200], ausgabe[200],alphabet[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabzdefghijklmnopqrstuvwxyz";
	
	cout << "Bitte die Zahl eingeben um die verschoben werden soll: ";
	cin >> ver_zahle;
	
	cout << "Bitte die Nachricht eingeben (max. 200 Zeichen) \n";
	cin >> eingabe;

	while (zaehler1<200) {

		while (zaehler2<53) {

			ver_zahlr=zaehler2+ver_zahle;

			if (eingabe[zaehler1]==alphabet[zaehler2]) {
				
				ausgabe[zaehler1]=alphabet[ver_zahlr];}
			
			zaehler2++;

		}

		zaehler1++;
	}
	cout << ausgabe;
	return 0;
}
