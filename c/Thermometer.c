/** Programm : Thermometer.c
  * Autor	 : Nico Anders
  * Version  : 1.0
  * Datum    :
  * Stand    :
  * Status   : in Arbeit
  * ToDo     :
  */

/** Praeprozessor
  * Bibliothek-Einbindung für Ein- und Ausgaben (scanf, printf)
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <math.h>
  #include <time.h>
  #include <ctype.h>

/** Funktion : Temperaturen umwandeln
  * Status   : in Arbeit
  */
  int iTemp()
  {
	  float fTemp = 0;
	  char sEingabe =0;
	  
	  printf("\n\tTemperaturrechner\n");
	  printf("\n\t1 Fahrenheit\n");
	  printf("\n\t2 Reamur\n");
	  printf("\n\t3 Kelvin\n");
	  printf("\n\t4 Rankine\n");
	  printf("\n\t0 Beenden\n");
	  sEingabe = getchar();
	  switch( sEingabe )
	  {
		  case '0':
		  break;
		  case '1':
		  break;
		  case '2':
		  break;
		  case '3':
		  break;
		  case '4':
		  break;
		  printf("\n\tBitte Grad Celsius eingeben: ");
		  scanf("%f", &fTemp);
		  if( fTemp >= 273.15 )
		  switch( sEingabe )
		  {
			  case '1':
			  printf("\n\t%.2f °C = %.2f °F",fTemp, 9.0 / 5.0 * fTemp + 32.0);
			  break;
			  case '2':
			  printf("\n\t%.2f °C = %.2f °F", fTemp, 4.0 / 5.0 * fTemp);
			  break;
			  case '3':
			  printf("\n\t%.2f °C = %.2f °F", fTemp, fTemp + 273.15);
			  break;
			  case '4':
			  printf("\n\t%.2f °C = %.2f °F", fTemp, 9.0 / 5.0 *(fTemp + 273.15));
			  break;
		  }
		  else
		  {
			  printf("\n\tDiese Temperatur gibt es nicht!");
		  }
		  default:
		  {
			  printf("Ungueltige Option");
		  }
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iTemp();
	  return 0; /* Sprung-Anweisung */
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }

/** Programmende
  */
