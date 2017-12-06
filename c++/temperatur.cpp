/**
 * Praeprozessor
 */
 #include <iostream>
 using namespace std;

/**
 * Klasse
 */
 class Temperatur {
	 private:
		double dWaerme;
	 public:
		double lese_Celsius();
		double lese_Fahrenheit();
		int speicher_Celsius();
		int speicher_Fahrenheit();
 };

/**
 * Eingabe Celsius
 */
 int Temperatur::speicher_Celsius() {
	 cout << "\nBitte Celsius eingeben: ";
	 cin >> dWaerme;
	 return 0;
 }

/**
 * Eingabe Fahrenheit
 */
 int Temperatur::speicher_Fahrenheit() {
	 cout << "\nBitte Fahrenheit eingeben: ";
	 cin >> dWaerme;
	 dWaerme = 5.0 / 9.0 * (dWaerme - 32.0);
	 return 0;
 }

/**
 * Rueckgabe Celsius
 */
 double Temperatur::lese_Celsius() {
	 return dWaerme;
 }

/**
 * Berechnung Fahrenheit
 */
 double Temperatur::lese_Fahrenheit() {
	 return  9.0 / 5.0 * dWaerme + 32.0;
 }

/**
 * Steuerprogramm
 */
 int iController() {
	 Temperatur temp;
	 temp.speicher_Celsius();
	 cout << "\nWert in Celsius   : " << temp.lese_Celsius();
	 cout << "\nWert in Fahrenheit: " << temp.lese_Fahrenheit();
	 return 0;
}

/**
 * Hauptprogramm
 */
 int main() {
	 iController();
	 return 0;
 }
