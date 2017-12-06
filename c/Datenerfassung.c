/** Uebung-datenerfassung.c
  */

/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <conio.h>
  
/**Funktion: global struct
  */
  struct Produkt
  {
        char   sArtikel[20];
        char   sModell[20];
        char   sGroesse[3];
        char   sHersteller[15];
        char   sPreis[6];
        char   sAnmerkung[140];
  }stProdukt;

/** Funktion: Menue
  */
  int iMenue()
  {
      int iEingabe = 0;
      system("cls");
   do
   { 
      printf("\n\tMeine Prouktdatenerfassung");
      printf("\n\t__________________________");
      printf("\n\t<1> Artikel  eingeben");
      printf("\n\t<2> Artikel  fortsetzen");
      printf("\n\t<3> Artikel  ausgeben");
      printf("\n\t<0> Programm beenden");
      printf("\n\t==> Auswahl  treffen: ");
      fflush(stdin);
      scanf("%i", &iEingabe);
      switch(iEingabe)
      {
             case 1:
                  {
                       iDaten_eingeben();
                       break;
                  }
                  
             case 2:
                  {
                       iDaten_fortsetzen();
                       break;
                  }
                  
             case 3:
                  {
                       iDaten_ausgeben();
                       break;
                  }
                  
             case 0:
                  {
                       exit(0);
                       break;
                  }
                  
                  default:
                  {
                         printf("\n\tFalsche Taste!");
                         break;
                  }
      }
    }while(iEingabe);
    return 0;
  }

/** Funktion: Daten eingeben
  */
  int iDaten_eingeben()
  {
      stProdukt;
      FILE *FPZeiger_schreiben;
      FPZeiger_schreiben = fopen("logfile.bin", "wb");
      system("cls");
      printf("\n\tBitte Ihre Produkte eingeben\n");
      /* Artikel erfassen */
      printf("\n\tArtikel eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sArtikel, 20, stdin);      
      /* Modell erfassen */
      printf("\tModell eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sModell, 20, stdin);      
       /* Groesse erfassen */
      printf("\tGroesse eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sGroesse, 3, stdin);
      /* Hersteller erfassen */
      printf("\tHersteller eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sHersteller, 15, stdin);   
      /* Preis erfassen*/
      printf("\tPreis eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sPreis, 6, stdin);
      /* Anmerkung erfassen */
      printf("\tAnmerkung eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sAnmerkung, 140, stdin);
      fflush(stdin);
      getch();
      
      /* Produktdaten in Datei schreiben */
      fwrite(stProdukt.sArtikel, 1, 20, FPZeiger_schreiben);
      fwrite(stProdukt.sModell, 1, 20, FPZeiger_schreiben);
      fwrite(stProdukt.sGroesse, 1, 3, FPZeiger_schreiben);
      fwrite(stProdukt.sHersteller, 1, 15, FPZeiger_schreiben);
      fwrite(stProdukt.sPreis, 1, 6, FPZeiger_schreiben);
      fwrite(stProdukt.sAnmerkung, 1, 140, FPZeiger_schreiben);
      fclose(FPZeiger_schreiben);
      return 0;
  }

/** Funktion: Daten fortsetzen
  */
  int iDaten_fortsetzen()
  {
      stProdukt;
      FILE *FPZeiger_fortsetzen;
      FPZeiger_fortsetzen = fopen("logfile.bin", "ab");
      system("cls");
      printf("\tBitte Ihre Produkte eingeben\n");
      /* Artikel fortsetzen */
      printf("\tArtikel eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sArtikel, 20, stdin);   
      /* Modell fortsetzen */
      printf("\tModell eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sModell, 20, stdin); 
       /* Groesse fortsetzen */
      printf("\tGroesse eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sGroesse, 3, stdin); 
      /* Hersteller fortsetzen */
      printf("\tHersteller eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sHersteller, 15, stdin);
      /* Preis fortsetzen*/
      printf("\tPreis eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sGroesse, 6, stdin);
      /* Anmerkung fortsetzen */
      printf("\tAnmerkung eingeben: ");
      fflush(stdin);
      fgets(stProdukt.sAnmerkung, 140, stdin);
      fflush(stdin);
      getch();
      /* fortgestzte Produktdaten in Datei schreiben */
      fwrite(stProdukt.sArtikel, 1, 20, FPZeiger_fortsetzen);
      fwrite(stProdukt.sModell, 1, 20, FPZeiger_fortsetzen);
      fwrite(stProdukt.sGroesse, 1, 3, FPZeiger_fortsetzen);
      fwrite(stProdukt.sHersteller, 1, 15, FPZeiger_fortsetzen);
      fwrite(stProdukt.sPreis, 1, 6, FPZeiger_fortsetzen);
      fwrite(stProdukt.sAnmerkung, 1, 140, FPZeiger_fortsetzen);
      fclose(FPZeiger_fortsetzen);
      return 0;
  }

/** Funktion: Daten ausgeben
  */
  int iDaten_ausgeben()
  {
      FILE *FPZeiger_lesen;
      FPZeiger_lesen = fopen("logfile.bin", "rb");
      system("cls");
      /* Artikel ausgeben */
      fread(stProdukt.sArtikel, 1, 20, FPZeiger_lesen);
      printf("\n\t%s", stProdukt.sArtikel);
      /* Modell ausgeben */
      fread(stProdukt.sArtikel, 1, 20, FPZeiger_lesen);
      printf("\t%s", stProdukt.sModell);
      /* Groesse ausgeben */
      fread(stProdukt.sGroesse, 1, 3, FPZeiger_lesen);
      printf("\t%i", stProdukt.sGroesse);
      /* Hersteller ausgeben */
      fread(stProdukt.sHersteller, 1, 15, FPZeiger_lesen);
      printf("\t%s", stProdukt.sHersteller);
      /* Preis ausgeben */
      fread(stProdukt.sPreis, 1, 6, FPZeiger_lesen);
      printf("\t%s", stProdukt.sPreis);
      /* Anmerkung ausgeben */
      fread(stProdukt.sAnmerkung, 1, 140, FPZeiger_lesen);
      printf("\t%s", stProdukt.sAnmerkung);
      return 0;
  }

/** Steuerfunktion
  *
  */
  int iController()
  {
      iMenue();
      return 0;
  }

/** Programmschnittstelle main()
  *
  */
  int main()
  {
      iController();
      return 0;
  }
