/* Studienarbeit 3, 3. Aufgabe */
#include <stdio.h>
#include <string.h>

/*Funktionenprototypen */
int menue (void);
int berechne (int isbn);

/* Hauptprogramm */
int main (void)
{
char lang[100], pblsh[100], pruefziffer[4];
int titelnr, isbn, int_pruefziffer;

switch (menue())
  {
  case 1 : /* Angabe von Sprache, Verlag und Titelnummer*/
  printf("Geben Sie die Sprache des Buches ein: ");
  scanf("%s",lang);
  printf("Geben Sie den Verlag des Buches ein: ");
  scanf("%s",pblsh);
  printf("Geben Sie die Titelnummer des Buches ein: ");
  scanf("%d",&titelnr);
  printf("Sie haben eingegeben:\n Sprache: %s\n Verlag: %s\n Titelnummer: %d\n",lang,pblsh,titelnr);
  break;
  
  case 2 : /* Überprüfen einer ISBN mit Prüfziffer*/
  printf("Geben sie die ersten 9 Stellen der ISBN-Nummer ein: ");
  scanf("%d",&isbn);
  printf("\n");
  printf("Geben sie die Prüfziffer (letzte Ziffer) ein: ");
  scanf("%s",pruefziffer);
  if (pruefziffer[0]=='X' || pruefziffer[0]=='x')
   {
    int_pruefziffer=10;
   }
  else
   {
    int_pruefziffer=pruefziffer[0]-48;
   }
  if (int_pruefziffer==berechne(isbn))
   {
     printf("Die Überprüfung der ISBN war erfolgreich. Die Prüfziffer ist korrekt.\n");
   }
  else
   {
    printf("Die Überprüfung der ISBN ist fehlgeschlagen!\n");
    if (berechne(isbn)==10) /* "Prüfziffer" 'X' */
     {
      printf("Die korrekte Prüfziffer lautet: X\n");
     }
    else  /* Prüfziffern von 0-9 */
     {
      printf("Die korrekte Prüfziffer lautet: %d\n",berechne(isbn));
     }
   } 
  break;
   
  case 3 : /* Programmende */
  printf("Programm wird beendet...\n");
  break;
  
  default     : /* Fehlerhafte Eingaben*/
  printf("Unzulässige Eingabe!\n");
  }
return 0;
}

/* Funktion menue */
/* Gibt das Steuermenue auf dem Bildschirm aus */

int menue (void)
{
int var;

printf("ISBN-Prüfprogramm\n\n");
printf("1  Ermittlung der Prüfziffer Nach Eingabe von Sprache, Verlag und Titelnummer\n\n");
printf("2  Überprüfung einer vollständigen ISBN\n\n");
printf("3  Programmende\n");
printf("Auswahl: ");
scanf("%d",&var);
return var;
}


/* Funktion berechne */
/* Errechnet aus der ISBN ohne Prüfziffer die korrekte Prüfziffer */

int berechne (int isbn)
{
int i, pruef, pruefz;

  pruef=0;
  i=9;
  while (isbn!=0)
  {
	pruef=pruef+(isbn%10)*i;
	isbn=isbn/10;
	i=i-1;
  }
  pruefz=pruef%11;
return pruefz;
}
