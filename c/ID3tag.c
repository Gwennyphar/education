/*******************************************************************************
 Programm	:	ID3Tag-Editor
 Autor		:	Nico Anders
 Version	:	0.1
 Datum		:	13.11.2010
 Status		:	in Arbeit
 ToDo		:	fprintf(), puts()
				anhübschen
				usability													  */
/*******************************************************************************
 Praeprozessor
*******************************************************************************/  
#include	<stdio.h>
#include	<stdlib.h>
/*******************************************************************************
 Funktion : ID3Tag
 Status   : in Arbeit
*******************************************************************************/  
typedef struct Id3_tag
{
	char sTitel		[FILENAME_MAX];
	char sKuenstler	[FILENAME_MAX];
	char sAlbum		[FILENAME_MAX];
	char sJahr		[FILENAME_MAX];
	char sGenre		[FILENAME_MAX];
	char sKommentar	[FILENAME_MAX];
}
/*******************************************************************************
 Funktion : ID3Tag Ausgeben
 Status   : in Arbeit
*******************************************************************************/  
Id3_tag;

int iId3_tag_Ausgabe(Id3_tag song)
{
		

		printf("\t******************************\n");
		printf("\t* Der Song den Sie eingaben: *\n");
		printf("\t******************************\n");
		printf("\t  Kuenstler	:	%s", song.sKuenstler);
		printf("\t  Titel		:	%s", song.sTitel);
		printf("\t  Album		:	%s", song.sAlbum);
		printf("\t  Jahr		:	%s", song.sJahr);
		printf("\t  Genre		:	%s", song.sGenre);
		printf("\t  Kommentar	:	%s", song.sKommentar);
		printf("\t******************************\n");
		printf("\t* 	ID3Tag-Editor\t     *\n");
		printf("\t******************************\n");
		return 0;
}

/*******************************************************************************
 Funktion : ID3Tag eingeben
 Status   : in Arbeit
*******************************************************************************/  
int iId3_tag_Eingabe()
{
	Id3_tag song;					//definiere Strukturvariable "song"

	int iAuswahl = 0;

	FILE *FPTag;                                    
    FPTag = fopen("ID3.txt", "a+");

	fprintf(FPTag, "******************************\n");
	fprintf(FPTag, "* Gespeicherte Song ID3Tags: *\n");
	fprintf(FPTag, "******************************\n");

   do	   
   {   
	
	printf("\t******************************\n");
	printf("\t* Bitte einen Song eingeben: *\n");
	printf("\t******************************\n");
	printf("\t  Kuenstler	:	");//Zeile 30-45 Elemente einlesen Punktoperator
	fgets(song.sKuenstler, FILENAME_MAX, stdin); /*holt Zeichen von Tastatur*/
	fprintf(FPTag,"Kuenstler	: "); /* schreibt Stream von FP in Datei*/     
	fputs(song.sKuenstler, FPTag); 	/* holt Zeichen von Stream FPTag*/
	
	printf("\t  Titel		:	");
	fgets(song.sTitel, FILENAME_MAX, stdin);
	fprintf(FPTag,"Titel		: ");      
	fputs(song.sTitel, FPTag); 	
	
	printf("\t  Album		:	");
	fgets(song.sAlbum, FILENAME_MAX, stdin);
	fprintf(FPTag,"Album		: ");      
	fputs(song.sAlbum, FPTag);
	 	
	printf("\t  Jahr		:	");
	fgets(song.sJahr, FILENAME_MAX, stdin);
	fprintf(FPTag,"Jahr		: ");     
	fputs(song.sJahr, FPTag);
  
	printf("\t  Genre		:	");
	fgets(song.sGenre, FILENAME_MAX, stdin);
	fprintf(FPTag,"Genre		: ");      
	fputs(song.sGenre, FPTag); 	
	              
	printf("\t  Kommentar	:	");
	fgets(song.sKommentar, FILENAME_MAX, stdin);
	fprintf(FPTag,"Kommentar	: ");      
	fputs(song.sKommentar, FPTag);
	              
	//Daten der Struktur ausgeben
	iId3_tag_Ausgabe(song);//Struktur als call-by-value an Funktion
	fclose(FPTag);

	printf("\t\tNeuer Tag mit Taste <1>: ");
	fflush(stdin);
    scanf("%i", &iAuswahl);
	switch(iAuswahl)
	{
		case 1:
		{
			iId3_tag_Eingabe();
			break;
		}

		default:
		{
			printf("Falsche Taste");
			break;
		}
	}
   }while(iAuswahl != 0);
    return EXIT_SUCCESS;
}

/*******************************************************************************
 Funktion : Steuerfunktion
 Status   : in Arbeit
*******************************************************************************/  
int iController()
{
	iId3_tag_Eingabe();
	return 0;
}

/*******************************************************************************
 Funktion : main() Schnittstelle
 Status   : in Arbeit
*******************************************************************************/  
int main()
{
	iController();
	return 0;
}
/*******************************************************************************
 Ende
*******************************************************************************/
