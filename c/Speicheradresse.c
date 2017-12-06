#include	<stdio.h>
#include	<stdlib.h>

int iSpeicheradresse_auslesen()
{
	int iAdresse;						  /* iAdresse hier fuer die Variablen */
 	system("cls");
  	printf("\n\t    Feste Speicheradresse    ");
   	printf("\n\t_____________________________\n");
	printf("\n\tDie Adresse lautet: %p\n", &iAdresse);/*%p fuer die Adresse im Speicher*/
    fflush(stdin);
    printf("\n\tZur Auswahl mit <Enter>");
    getchar();
	return 0;
}

int iSpeicheradresse_ermitteln()
{
	int iAdresse;							/*iAdresse hier fuer die Variablen*/
	
	system("cls");
  	printf("\n\t      Speicheradresse        ");
   	printf("\n\t_____________________________\n");
	printf("\n\tGeben Sie eine Zahl ein: ");
	fflush(stdin);
	scanf("%i", &iAdresse);
	printf("\n\tDie Adresse lautet: %p\n", &iAdresse);/*%p fuer eine Adresse im Speicher*/
    fflush(stdin);
    printf("\n\tZur Auswahl mit <Enter>");
    getchar();
	return 0;
}

int iAuswahl()
{
   int iEingabe = 0;
   do
   {
 	system("cls");
	printf("\n\t       Speicheradressen      ");
 	printf("\n\t_____________________________\n");
  	printf("\n\t<1> Festen Speicher auslesen ");
   	printf("\n\t<2> flexib. Speicher auslesen");
    printf("\n\t<0> Beenden");
    printf("\n\t_____________________________");
    printf("\n\tBitte eine Option eingeben: ");
    fflush(stdin);
    scanf("%i", &iEingabe);
    switch(iEingabe)
    {
		case 1:
			 {
			   		iSpeicheradresse_auslesen();
					break;
			 }
 		case 2:
			 {
			   		iSpeicheradresse_ermitteln();
					break;
     		 }
  		case 0:
			 {
			   		exit(0);
					break;
     		 }
                      
        default:
             {
			  	   printf("\n\tFalsche Taste!\n");
             }
      }
      }while(iEingabe);
      system("pause");
      fflush(stdin);
      getchar();
      return 0;
  }

int iController()
{
 	iAuswahl();
 	return 0;
}

int main()
{
 	iController();
 	return 0;
}
