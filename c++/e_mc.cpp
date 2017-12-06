/* 
 * Die verwendete Formel:
 * E = Engergie;
 * m = Masse;
 * c = Weg;
 * e = m * c * c;
 */
 
/**
 * Praeprozessor
 */
 #include <iostream>
 #include <math.h>
 using namespace std;

/**
 * Klasse
 */
 class emc {
	 private:
		double gewicht;
	 public:
		double speicher_gewicht();
		double berechne_joule();
 };

/**
 * Eingabe
 */
 double emc::speicher_gewicht() {
	 cout << "\nBitte das Gewicht eingeben: ";
	 cin >> gewicht;
	 return 0;
 }

/**
 * Berechnung
 */
 double emc::berechne_joule() {
	 return  gewicht * 3.0 * 3.0;
 }

/** Steuerprogramm
  */
  int iController()
  {
	  emc Joule;
	  Joule.speicher_gewicht();
	  Joule.berechne_joule();
	  cout << "\nDas Objekt hat " << Joule.berechne_joule() << " Joule";
	  return 0;
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }
