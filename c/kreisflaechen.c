#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Kreisberechnungsprogramm
//Funktionen

void Kreisflaeche (float d)
	{
    float Flaeche, pi;
	pi = 3.1459;
	Flaeche=d*d+pi/4;
	printf("Flaeche des Kreises betraegt: %.2f\n",Flaeche);
	}
void Kreisdurchmesser (float Flaeche)
	{
	float d, pi;
    pi = 3.1459;
    d = 4*Flaeche/pi;
    printf("Durchmesser des Kreises betraegt: %.2f\n",d);
    }
void Kreisumfang (float d)
	{
    float Umfang, pi;
    pi = 3,1459;
    Umfang = pi*d;
    printf("Umfang des Kreises betraegt: %2f\n",Umfang);
    }    
        
        
int main()
{
    float Eingabe;
	int Abfrage;
do{

 printf ("Welche Berechnung wollen sie durchfuehren?\n");
 printf ("<1> KreisFlaeche\n");
 printf ("<2> Kreisdurchmesser\n");
 printf ("<3> Kreiszumfang\n");
 printf ("<4> Programm beenden\n");
   
        
    scanf ("%d", &Abfrage);
    
switch (Abfrage)
{
    case 1: printf("Durchmesser:  ");
    		scanf("%f", &Eingabe);
    //Funktionsaufruf
    		Kreisflaeche(Eingabe);
    		break;
    
    case 2: printf("Flaeche:  ");
    		scanf("%f",&Eingabe);
    //Funktionsaufruf
    		Kreisdurchmesser(Eingabe);
    		break;
    
    case 3: printf("Durchmesser:  ");
    		scanf("%f", &Eingabe);
    //Funktionsaufruf
    		Kreisumfang(Eingabe);
    		break;
    
    case 4: printf("Programmende \n");
    		break;
    
    default: printf("Unbekannte Eingabe \n");
   
}    
}while (Abfrage != 4);    
    return 0;
}
