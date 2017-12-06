/* 
 * Die verwendete Formel:
 * Ergebnis = Faktor * Eingabewert
 * res = factor * eingabe
 * 1 zu 5875156800000 US-Meilen
 * 1 zu 9453127291200 km
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
 class Lichtjahre
 {
	 private:
		float lichtjahr;
	 public:
		float lichtjahr_eingeben();
		float berechne_km();
		float berechne_meilen();
 };

/**
 * EIngabe
 */
 float Lichtjahre::lichtjahr_eingeben() {
	 cout << "\nBitte das Lichtjahr eingeben: ";
	 cin >> lichtjahr;
	 return 0;
 }

/**
 * Berechnung US Meilen
 */
 float Lichtjahre::berechne_meilen() {
	 return  5875156800000 * lichtjahr;
 }

/**
 * Berechnung Kilometer
 */
 float Lichtjahre::berechne_km() {
	 return  9453127291200 * lichtjahr;
 }

/**
 * Steuerprogramm
 */
 int iController()
 {
	 Lichtjahre Entfernung;
	 Entfernung.lichtjahr_eingeben();
	 cout << "\nEnternung in US Meilen: " << Entfernung.berechne_meilen();
	 cout << "\nEnternung in Kilometer: " << Entfernung.berechne_km();
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
