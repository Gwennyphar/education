/***************************************************************/
/* Prof. Dr. Carsten Vogt                                      */
/* FH Koeln, Fak. 07 / Nachrichtentechnik                      */
/* http://www.nt.fh-koeln.de/vogt                              */
/*                                                             */
/* Beispielprogramm p08030000.c                                */
/* aus "C fuer Java-Programmierer", Hanser-Verlag              */
/*                                                             */
/* Demonstriert wird der Umgang mit Hashtabellen.              */
/***************************************************************/

#define TABELLENGROESSE 16

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct eintrag {
  char name[30];
  unsigned int alter;
  float gewicht;
  struct eintrag  *prev;
  struct eintrag  *next;
} eintrag;

int hashcode(char *s) {
  // s[0]*31^(n-1) + s[1]*31^(n-2) + ... + s[n-1]
 unsigned int i, len, hashwert=0;
 len = strlen(s);
 for (i=0;i<len;i++)
  hashwert = hashwert*31 + s[i];
 return hashwert%TABELLENGROESSE;
}

int einfuegen(eintrag **kopf, eintrag *einzufueg) {
 if ((einzufueg==NULL)||(kopf==NULL)) return -1;
 if (*kopf==NULL) {
    *kopf = einzufueg;
    (*kopf)->next = (*kopf)->prev = *kopf;
   }
  else {
    einzufueg->next = *kopf;
    einzufueg->prev = (*kopf)->prev;
    einzufueg->prev->next = einzufueg;
    einzufueg->next->prev = einzufueg;
    *kopf = einzufueg;
   }
 return 0;
}

void entfernen(eintrag **kopf, eintrag *auszufueg) {
 if ((kopf==NULL)||(auszufueg==NULL)||(*kopf==NULL)) return;
 if (auszufueg->next==auszufueg) {
  *kopf=NULL;
  return;
 }
 if (*kopf==auszufueg)
  *kopf=(*kopf)->next;
 auszufueg->next->prev = auszufueg->prev;
 auszufueg->prev->next = auszufueg->next;
}

void ausgeben(eintrag *kopf) {
 eintrag *laufzeiger;
 if (kopf==NULL)
  return;
 laufzeiger = kopf;
 do {
  printf("%s ",laufzeiger->name);
  laufzeiger = laufzeiger->next;
 }
 while (laufzeiger!=kopf);
}

eintrag *suchen(eintrag *kopf, char *gesuchter_string) {
 eintrag *laufzeiger;
 if (kopf==NULL)
  return NULL;
 laufzeiger = kopf;
 while (laufzeiger->next!=kopf&&strcmp(laufzeiger->name,gesuchter_string)!=0)
  laufzeiger = laufzeiger->next;
 if (strcmp(laufzeiger->name,gesuchter_string)==0)
   return laufzeiger;
  else
   return NULL;
}

int main(void) {

 eintrag *tabelle[TABELLENGROESSE];

 int i, wahl;
 char string[100];
 eintrag *neuer_eintrag, *gesuchter_eintrag;
 unsigned int hashwert;

 for (i=0;i<TABELLENGROESSE;i++)
  tabelle[i] = NULL;

 do {

  do {

   printf("\nBitte Funktion auswaehlen:\n\n");
   printf("( 1 )  Eintrag in Tabelle einfuegen\n");
   printf("( 2 )  Eintrag aus Tabelle loeschen\n");
   printf("( 3 )  Eintrag suchen\n");
   printf("( 4 )  Alle Eintraege ausgeben\n");
   printf("( 5 )  Hashcode eines Strings berechnen\n");
   printf("( 0 )  Programmende\n");

   scanf("%d",&wahl);

  } while (wahl<0 || wahl>5);

  printf("\n");

  switch(wahl) {

   case 1:

    neuer_eintrag = (eintrag *) malloc(sizeof(eintrag));
    if (neuer_eintrag==NULL) {
     printf("Fehler bei malloc()");
     break;
    }
    printf("Neuer Eintrag:\n");
    printf("  Name: ");
    scanf("%s",neuer_eintrag->name);
    printf("  Alter: ");
    scanf("%u",&(neuer_eintrag->alter));
    printf("  Gewicht: ");
    scanf("%f",&(neuer_eintrag->gewicht));
    hashwert = hashcode(neuer_eintrag->name);
    if (suchen(tabelle[hashwert],neuer_eintrag->name)==NULL)
      einfuegen(&tabelle[hashwert],neuer_eintrag);
     else
      printf("Bereits vorhanden!\n");
    break;

  case 2:

    printf("Bitte Namen des zu loeschenden Eintrags eingeben: ");
    scanf("%s",string);
    hashwert = hashcode(string);
    gesuchter_eintrag = suchen(tabelle[hashwert],string);
    if (gesuchter_eintrag!=NULL) { 
       entfernen(&tabelle[hashwert],gesuchter_eintrag);
       printf("\nEintrag geloescht\n");
      }
     else
       printf("\nKein passender Eintrag gefunden\n");
    break;

  case 3:

    printf("Bitte gesuchten Namen eingeben: ");
    scanf("%s",string);
    hashwert = hashcode(string);
    gesuchter_eintrag = suchen(tabelle[hashwert],string);
    if (gesuchter_eintrag!=NULL) { 
      printf("\ngefunden:\n");
      printf(" Name:    %s\n",gesuchter_eintrag->name);
      printf(" Alter:   %u\n",gesuchter_eintrag->alter);
      printf(" Gewicht: %.2f\n",gesuchter_eintrag->gewicht);
      }
     else
       printf("\nKein passender Eintrag gefunden\n");
    break;

   case 4:

    for (i=0;i<TABELLENGROESSE;i++) {
      printf("\n%d: ",i);
      ausgeben(tabelle[i]);
     }
    printf("\n");
    break;

   case 5:

    printf("Bitte String eingeben: ");
    scanf("%s",string);
    printf("\nHashcode: %d\n\n",hashcode(string));
    break;

  }

 } while (wahl!=0);

 return 0;

}
