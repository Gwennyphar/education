/** Aufgaben:
 *  1. Schreiben Sie ein Programm, das eine Zaehlerschleife
 *     INT_MAX mal durchlaeuft und jeweils 1 zum Schleifenindex
 *     addiert.
 *  2. Instrumentieren Sie das Programm durch eine Zeitmessung der
 *     verbrauchten CPU-Zeit.
 *  3. Geben Sie am Programmende die verbrauchte CPU-Zeit in
 *     Sekunden als Einheit aus!
 */
 
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <stdio.h>

 void zaehle()
 {
	 long i, j, k;
	double a = 0.0, b = 0.0, c = 0.0;
	k = 1000;
	for(i=0;i<k;i++){
          for(j=0;j<k;j++){
          a += 1.0/c;
          b = pow(0.22,2.5);
          b = pow(0.22,2.5);
          c += b;
        }
    }
 }
 
int main()
{
	unsigned int begin = time(NULL) ;
	unsigned int end = 0 ;
	unsigned int clbegin = clock() ;
	unsigned int clend = 0 ;
	printf("Aktuelle Zeit beim Programmstart: %u\n", begin) ;
	printf("Wert von clock() beim Programmstart: %u\n", clbegin) ;
	zaehle() ;
	end = time(NULL) ;
	clend = clock() ;
	printf("Aktuelle Zeit beim Programmende: %u\n", end) ;
	printf("Wert von clock() beim Programmende: %u\n", clend) ;
	printf("Die Laufzeit des Programms ist: %u [sec].\n", end-begin) ;
	printf("Die Laufzeit des Programms gemessen mit clock()\n") ;
	printf("ist %.2f [sec].\n", (float) (clend-clbegin)/CLOCKS_PER_SEC) ;

	return EXIT_SUCCESS ;
}
