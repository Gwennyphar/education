#include    <stdio.h>

int iAdressen()
{
    int iZeiger          =           0;
    int iZahl            =           5;
    int *iZeigerAufiZahl  =      &iZahl;
    
    int iArray[5]        = {1,2,3,4,5};
    int *iZeigerAufiArray =     iArray;
    
    printf("\tVarName\t\tAdresse\t\tWert(e)\n");
    printf("\tiZahl\t\t%p\t%d\n", &iZahl, iZahl);
    
    for( iZeiger=0; iZeiger < 5; iZeiger++)
    {
         printf("\tiArray[%d]\t%p\t%d\n", iZeiger, &iArray[iZeiger], iArray[iZeiger]);
    }
    printf("*******************************************\n");
    
    printf("\t\t\tAdresse\t\tWert nach Dereferenzierung\n");
    printf("iZeigerAufiZahl\t\t%p\t%d\n", iZeigerAufiZahl, *iZeigerAufiZahl);
    
    for( iZeiger=0; iZeiger < 5; iZeiger++)
    {
         printf("iZeigerAufiArray[%iZeiger]\t%p\t%d\n", iZeiger, &iZeigerAufiArray, *iZeigerAufiArray );
         iZeigerAufiArray = ++iZeigerAufiArray;
    }
    system("pause");
    return 0;
}

int iController()
{
    iAdressen();
    return 0;
}

int main()
{
    iController();
    return 0;
}
         
    
