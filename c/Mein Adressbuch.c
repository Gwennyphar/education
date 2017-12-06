#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct {
          char vorname[20];
          char nachname[30];
          char strasse[30];
          char hausnummer[5];
          char plz[7];
          char ort[30];
          char sternzeichen[30];
          char alter[3];
         }adressen;

int iSpeichern()
{
   FILE *FPSpeichern;
   FPSpeichern=fopen("Adressbuch.bin","r+b");
   if( NULL == FPSpeichern)
      {
         FPSpeichern = fopen("Adressbuch.bin","w+b");
         if( NULL == FPSpeichern )
            {
               fprintf(stderr,
                       "Kann \"Adressbuch.bin\" nicht oeffnen!\n");
               exit (0);
            }
      }

   /*FILE-Zeiger FPSpeichern auf das Ende der Datei setzen*/
   fseek(FPSpeichern, 0, SEEK_END);

   /*Wir schreiben eine Adresse ans Ende von "Adressbuch.bin"*/
   if(fwrite(&adressen, sizeof(adressen), 1, FPSpeichern) != 1)
      {
         fprintf(stderr,"Fehler bei fwrite...!!!\n");
         exit (1);
      }

   /*Wir geben unseren FILE-Zeiger wieder frei*/
   fclose(FPSpeichern);
   getch();
   return 0;
}

int iEingabe()
{
    system("pause");
   printf("Vorname...........:");
   fgets(adressen.vorname, sizeof(adressen.vorname), stdin);
   printf("Nachname..........:");
   fgets(adressen.nachname, sizeof(adressen.nachname),stdin);
   printf("Strasse...........:");
   fgets(adressen.strasse, sizeof(adressen.strasse), stdin);
   printf("Hausnummer........:");
   fgets(adressen.hausnummer,sizeof(adressen.hausnummer),stdin);
   printf("Postleitzahl......:");
   fgets(adressen.plz, sizeof(adressen.plz), stdin);
   printf("Ort...............:");
   fgets(adressen.ort, sizeof(adressen.ort), stdin);
   printf("Sternzeichen......:");
   fgets(adressen.sternzeichen,sizeof(adressen.sternzeichen),stdin);
   printf("Alter.............:");
   fgets(adressen.alter, sizeof(adressen.alter), stdin);
   iSpeichern();
   getch();
   return 0;
}

int  iAusgabe()
{
   FILE *output;
   output=fopen("Adressbuch.bin","r+b");
   if( NULL == output )
      {
         fprintf(stderr,
                      "Konnte \"Adressbuch.bin\" nicht oeffnen\n");
         exit (2);
      }

   /*Wir lesen alle Adressen aus "adressen.dat"*/
   while(fread(&adressen, sizeof(adressen), 1, output) ==1)
      {
         system("pause");
         printf("Vorname...........: %s",adressen.vorname);
         printf("Nachname..........: %s",adressen.nachname);
         printf("Strasse...........: %s",adressen.strasse);
         printf("Hausnummer........: %s",adressen.hausnummer);
         printf("Postleitzahl......: %s",adressen.plz);
         printf("Ort...............: %s",adressen.ort);
         printf("Sternzeichen......: %s",adressen.sternzeichen);
         printf("Alter.............: %s",adressen.alter);
         printf("\n\n");
      }
   fclose(output);
   system("pause");
   return 0;
}

int iMenue()
{
   int iWahl = 0;

   do
   {
       system("cls");
	   printf("_________Mein_Adressbuch____________\n\n");
       printf("Was möchten Sie machen?\n\n");
       printf("-1- Neuen Datensatz hinzufuegen\n");
       printf("-2- Alle Datensaetze ausgeben\n");
       printf("-3- Programm beenden\n\n");
       printf("Ihre Auswahl : ");
       do
       {
		   scanf("%i",&iWahl);
       }while(getchar() != '\n');
        switch(iWahl)
           {
              case 1 :
              {
				  iEingabe();
                  break;
			  }
              case 2 :
              {
				   iAusgabe();
                   break;
			   }
              case 3 :
              {
				  printf("...Programm wird beendet\n");
                  break;
			  }
              default:
              {
				  printf(">%d< ???\n",iWahl);
			  }
           }
      }while(iWahl != 3);
   return 0;
}

int iController()
{
	iMenue();
	return 0;
}

int main()
{
	iController();
	return 0;
}
