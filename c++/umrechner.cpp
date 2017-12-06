/* 
 * Die verwendete Formel:
 * summe = betrag / faktor * ausgangswaehrung;
 */
/**
 * Praeprozessor
 */
 #include <iostream>
 #include <cmath>
 using namespace std;

/**
 * Klasse
 */
 class Waehrung
 {
	 private:
		float betrag;
		float faktor;
	public:
		float speicher_betrag();
		float zeige_betrag();
		float berechne_betrag();
 };
 
/**
 * Eingabe Betrag
 */
 float Waehrung::speicher_betrag() {
	 cout << "Bitte Betrag eingeben: ";
	 cin >> betrag;
	 cout << "Bitte Faktor eingeben: ";
	 cin >> faktor;
	 return 0;
 }

/**
 * Rueckgabe Betrag
 */
 float Waehrung::zeige_betrag() {
	 return betrag;
 }

/**
 */
 float Waehrung::berechne_betrag() {
	 
	 return betrag / faktor * 1.00;
 }

/**
 * Steuerprogramm
 */
 int iController()
 {
	 Waehrung summe;
	 summe.speicher_betrag();
	 cout << "Ihre Eingabe war: " << summe.zeige_betrag() << ",-" << endl;
	 cout << "Das Ergebnis ist: " << summe.berechne_betrag() << ",-" << endl;
	 return 0;
 }

/**
 * Hauptprogramm
 */
 int main()
 {
	 iController();
	 return 0;
 }
