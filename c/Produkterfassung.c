/** Uebung-datenerfassung.c
  * Nico Anders
  * Version 0.1 testing
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
        char   sKonfektion[3];
        char   sHersteller[16];
        char   sPreis[6];
        char   sKommentar[140];
  }stProdukt;

/** Funktion: Daten ausgeben
  * Status  : in Arbeit
  */
  int iDaten_ausgeben()
  {
   	  system("cls");
      printf("\t******************************\n");
	  printf("\t* Meine Produkteingabe       *\n");
	  printf("\t******************************\n");
	  printf("\t  Artikel    :   %s", stProdukt.sArtikel);
	  printf("\t  Modell     :   %s", stProdukt.sModell);
	  printf("\t  Konfektion :   %s", stProdukt.sKonfektion);
	  printf("\t  Hersteller :   %s", stProdukt.sHersteller);
	  printf("\t  Preis      :   %s", stProdukt.sPreis);
	  printf("\t  Kommentar  :   %s", stProdukt.sKommentar);
	  printf("\t******************************\n");
	  printf("\t* Meine Produkterfassung     *\n");
	  printf("\t******************************\n");
	  getch();
	  return 0;
}

/** Funktion: Daten eingeben
  * Status: in Arbeit
  */ 
  int iDaten_eingeben()
  {
	stProdukt;
	
	system("cls");
	FILE *FPZeiger_schreiben;                                    
    FPZeiger_schreiben = fopen("logfile.log", "wb");

	fprintf(FPZeiger_schreiben, "******************************\n");
	fprintf(FPZeiger_schreiben, "* Gespeichertes Produkt *\n");
	fprintf(FPZeiger_schreiben, "******************************\n");
  
	printf("\t******************************\n");
	printf("\t* Bitte Ihr Produkt eingeben *\n");
	printf("\t******************************\n");
	printf("\t  Artikel 	:	");
	fflush(stdin);
	fgets(stProdukt.sArtikel, 16, stdin);
	fprintf(FPZeiger_schreiben,"Artikel 	: ");      	
	
	printf("\t  Modell 	:	");
	fflush(stdin);
	fgets(stProdukt.sModell, 20, stdin);
	fprintf(FPZeiger_schreiben,"Modell 	: ");       	
	
	printf("\t  Konfektion	:	");
	fflush(stdin);
	fgets(stProdukt.sKonfektion, 3, stdin);
	fprintf(FPZeiger_schreiben,"Konfektion	: ");      
	 	
	printf("\t  Hersteller	:	");
	fflush(stdin);
	fgets(stProdukt.sHersteller, 16, stdin);
	fprintf(FPZeiger_schreiben,"Hersteller	: ");     
  
	printf("\t  Preis		:	");
	fflush(stdin);
	fgets(stProdukt.sPreis, 6, stdin);
	fprintf(FPZeiger_schreiben,"Preis		: ");
	              
	printf("\t  Kommentar	:	");
	fflush(stdin);
	fgets(stProdukt.sKommentar, 16, stdin);
	fprintf(FPZeiger_schreiben,"Kommentar	: ");      
	system("cls");
	printf("\t******************************\n");
	printf("\t* Ihre Produkteingabe        *\n");
	printf("\t******************************\n");
	printf("\t  Artikel    :   %s", stProdukt.sArtikel);
	printf("\t  Modell     :   %s", stProdukt.sModell);
	printf("\t  Konfektion :   %s", stProdukt.sKonfektion);
	printf("\t  Hersteller :   %s", stProdukt.sHersteller);
	printf("\t  Preis      :   %s", stProdukt.sPreis);
	printf("\t  Kommentar  :   %s", stProdukt.sKommentar);
	printf("\t******************************\n");
	printf("\t* Meine Produkterfassung     *\n");
	printf("\t******************************\n");
	printf("\n\tWollen sie speichern?");
	getch();
    fwrite(stProdukt.sArtikel, 1, 20, FPZeiger_schreiben);
    fwrite(stProdukt.sModell, 1, 20, FPZeiger_schreiben);
	fwrite(stProdukt.sKonfektion, 1, 3, FPZeiger_schreiben);
    fwrite(stProdukt.sHersteller, 1, 16, FPZeiger_schreiben);
    fwrite(stProdukt.sPreis, 1, 6, FPZeiger_schreiben);	
    fwrite(stProdukt.sKommentar, 1, 140, FPZeiger_schreiben);
    fclose(FPZeiger_schreiben);
    return 0;
  }
	
/** Funktion: Daten fortsetzen
  * Status: in Arbeit
  */
  int iDaten_fortsetzen()
  {
   	  return 0;
  }
	              
/** Funktion: Menue
  * Status  : in Arbeit
  */
  int iMenue()
  {
      int iEingabe = 0;
   do
   { 
      system("cls");
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

/** Steuerfunktion
  */  
  int iController()
  {
	iMenue();
	return 0;
  }

/** Programmschnittstelle main()
  */ 
  int main()
  {
	iController();
	return 0;
  }
/** Programmende
  */
