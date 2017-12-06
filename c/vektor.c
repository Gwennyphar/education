#include <stdio.h>
 
#define ANZAHL 50
 
int main()
{
  int eingaben[ANZAHL], i;
  for (i = 0; i < ANZAHL; i++)
  {
	  eingaben[i] = 0;  /* jedes Element mit 0 initialisieren */
  }
  for (i = 0; i < ANZAHL; i++) /* Werte einlesen */
  {
	  printf ("%d. Element: ", i);
	  scanf ("%d", &eingaben[i]);
	  if (eingaben[i] == 0)
	  {
		  printf ("\n--------- Ihre Eingabe: ---------\n");  /* dann schaut es übersichtlicher aus */
		  break; /* bei 0 die Schleife abbrechen */
	  }
  }
  for (i = 0; i < ANZAHL; i++) /* Werte ausgeben */
  {
	  if (eingaben[i] != 0)  /* nur dann, wenn der Wert nicht Null ist, diesen ausgeben */
      printf ("%d. Element: %d\n", i, eingaben [i]);
      else   /* ansonsten Schleife abbrechen */
      break;
  }
  return 0;
}
