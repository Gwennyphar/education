/** Programm: menue.c
  * Autor   : nico anders
  * Version : 1.2
  * Datum   :
  */

/** Praeprozessor
  */
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <termios.h>
  #include <unistd.h>
  #include <fcntl.h>


/** Funktion : Steuerung fuer Hauptmenue
  * Status   : fertig
  */
  int iMenue()
  {
	  char cTaste = 0;
	  do
	  {
		  scanf("%c", &cTaste);
		  /*Hier sieht man, welche Aktivitäten zur Verfuegung stehen */
		  if(cTaste == '0')
		  {
                          /* das Menue aufklappen
			               * wiederholt die Schleife, um das Menue von
			               * allen Funktionen aus aufrufen zu koennen */
			  continue;
		  }
		  else if(cTaste == '1')
		  {
			  break;
		  }
		  else if(cTaste == '2')
		  {
			  break;
		  }
		  else if(cTaste == '3')
		  {
			  break;
		  }
		  else if(cTaste == '4')
		  {
			  break;
		  }
		  else if(cTaste == '5')
		  {
			  break;
		  }
		  else if(cTaste != '0'||cTaste != '1'||cTaste != '2' 
		  ||cTaste != '3'||cTaste != '4'||cTaste != '5')
		  {
			  break;
		  }
		  /* Es wird geprüft, ob die Eingabe keine 99 war */
	  }while(cTaste != 99); 
	  /*Ende der Schleife*/
	  return EXIT_SUCCESS; 
  } 

/** Funktion : Steuerfunktion
  * Status   : fertig
  */
  int iController()
  {
	  iMenue();
	  return EXIT_SUCCESS;
  }

/** Funktion : Hauptprogramm
  * Status   : fertig
  */
  int main()
  {
	  iController();
	  return EXIT_SUCCESS;
  }
