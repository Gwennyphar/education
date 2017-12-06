/**
 * Praeprozessor
 */
 #include <iostream>
 using namespace std;

/**
 * Klasse
 */
 class Namen
 {
	 private:
		char name[50];
	 public:
		int speichere_name();
		int zeige_name();
 };

/**
 * Speichere Vorname
 */
 int Namen::speichere_name() {
	 cout << "Wie ist Dein Name ? ";
	 cin >> name;
	 return 0;
 }

/**
 * Gebe Vorname aus
 */
 int Namen::zeige_name() {
	  cout << "Hallo, " << name << endl;
	 return 0;
 }

/**
 * Steuerprogramm
 */
 int iController()
 {
	 Namen Vorname;
	 Vorname.speichere_name();
	 Vorname.zeige_name();
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
