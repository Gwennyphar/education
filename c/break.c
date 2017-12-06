/** break.c
  * Switch case ohne break Anweisung;  
  */

 /** Praeprozessor
   */
   #include <stdio.h>

/** Funktion : Switch-case Anweisung
  * Status	 : fertig
  */ 
   int iAnweisung()
   {
	   char cOpt = 0;
	   printf("-a- Option A\n");
	   printf("-b- Option B\n");
	   printf("-c- Option C\n");
	   printf("Waehle Option: ");
	   scanf("%c", &cOpt);

	   switch(cOpt)
	   {
		   case 'a': printf("Option A benoetigt auch ");
		   case 'b': printf("Option B ");
					 break;
		   case 'c': 
		   case 'C': printf("und Option C\n");
					 break;
		   default : printf("Fehler bei der Eingabe!?\n");
	   }
	   return 0;
   }

/** Programmsteuerung
  * iController
  */
  int iController()
  {
	  iAnweisung();
	  return 0;
  }

/** Programmschnittstelle
  * main()
  */
  int main()
  {
	  iController();
	  return 0;
  }   
	   
