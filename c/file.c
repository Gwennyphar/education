#include	<stdio.h>
#include	<stdlib.h>

int iLogfile()
{
									  
    char sLogfile [160]; 							
	int iAbruch;
    FILE *FPFile;                                    
    FPFile = fopen("logfile.txt", "a");

    while(1)
    {         
          printf("Eine Nachricht eingeben: ");  	     
          fflush(stdin); 
          fgets(sLogfile, 160, stdin); 				   
          fprintf(FPFile,"\n");      
          fputs(sLogfile, FPFile); 		   
		printf("Raus geht es mit 1 : ");
		scanf("%d", &iAbruch);
		if(iAbruch == 1)
	  {
		break;
	  }
   }
   printf("Programmende");
    return 0;
}

int main()
{
	iLogfile();
	return 0;
}
