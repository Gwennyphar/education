/**
 * Praeprozessor
 */
 #include <iostream>
 #include <cmath>
 using namespace std;

/**
 * Klasse
 */
 class Rechner
 {
	 private:
		int zahl1;
		int zahl2;
	public:
	
		int speicher_zahl1();
		int speicher_zahl2();
		int zeige_zahl1();
		int zeige_zahl2();
		int rechne_addition();
		int rechne_subtraktion();
		int rechne_multiplaktion();
		int rechne_division();
		int berechne_rest();
 };
 
/**
 */
 int Rechner::speicher_zahl1() {
	 cout << "Bitte 1. Zahl eingeben: ";
	 cin >> zahl1;
	 return 0;
 }

/**
 */
 int Rechner::speicher_zahl2() {
	 cout << "Bitte 2. Zahl eingeben: ";
	 cin >> zahl2;
	 return 0;
 }

/**
 * Erste Eingabe
 */
 int Rechner::zeige_zahl1() {
	 return zahl1;
 }

/**
 * Zweite Eingabe
 */
 int Rechner::zeige_zahl2() {
	 return zahl2;
 }

/**
 * Additionverfahren
 */
 int Rechner::rechne_addition() {
	 return zahl1 + zahl2;
 }

/**
 * Subtraktionverfahren
 */
 int Rechner::rechne_subtraktion() {
	 return zahl1 - zahl2;
 }

/**
 * Multiplikationsverfahren
 */
 int Rechner::rechne_multiplaktion() {
	 return zahl1 * zahl2;
 }

/**
 * Divisionsverfahren
 */
 int Rechner::rechne_division() {
	 return zahl1 / zahl2;;
 }
 
/**
 * Restwert
 */
 int Rechner::berechne_rest() {
	 return zahl1 %zahl2;
 }

/**
 * Steuerprogramm
 */
 int iController()
 {
	 Rechner erg;
	 erg.speicher_zahl1();
	 erg.speicher_zahl2();
	 cout <<  erg.zeige_zahl1() << " + " << erg.zeige_zahl2() << " = " << erg.rechne_addition() << endl;
	 cout <<  erg.zeige_zahl1() << " - " << erg.zeige_zahl2() << " = " << erg.rechne_subtraktion() << endl;
	 cout <<  erg.zeige_zahl1() << " * " << erg.zeige_zahl2() << " = " << erg.rechne_multiplaktion() << endl;
	 cout <<  erg.zeige_zahl1() << " / " << erg.zeige_zahl2() << " = " << erg.rechne_division() << " Rest " << erg.berechne_rest() << endl;
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
