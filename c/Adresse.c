#include    <stdio.h>
#include    <stdlib.h>
#include     <conio.h>

int iAdressen()
{
    struct iMeineAdresse
    {
           char sName[15];
    };
    
    struct iMeineAdresse stMeineAdresse;
    struct stMeineAdresse *PstMeineAdresse;
    
    PstMeineAdresse = &stMeineAdresse;
    printf("PstMeineAdresse ist: %p\n", PstMeineAdresse);
    printf("PstMeineAdresse ist noch: %p\n", &stMeineAdresse);

    getch();
    return 0;
}

int iController()
{
    int iAdressen();
    getch();
    return 0;
}
    

int main()
{
    iController();
    return 0;
}
    
