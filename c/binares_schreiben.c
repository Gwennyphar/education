#include	<stdio.h>
#include	<stdlib.h>

int main(void)
{
	FILE *FPFile;
	FILE *FPDisp;
	FILE *FPHeader;
	FPFile   = fopen("template.bin", "wb");
	FPHeader = fopen("include.bin", "wb");
	FPDisp   = fopen("screen.bin", "wb");
	  
	char sTemplate[] = { 	  
	"\n  * Status......: in Arbeit\n"
	"  */\n"
	"  int iMenue()\n"
	"  {\n"
	"      char cTaste = 0;\n"
	"      char sEingabe[21];\n"
	"      do\n"
	"      {\n"
	"          printf(\"\\tWas moechten Sie machen?\\n\"\n"
	"          \"\\tMit Taste '3' Beenden: \");\n"
	"          /* abgesicherte Eingabe */\n"
	"          fgets(sEingabe, sizeof(sEingabe), stdin);\n"
	"          sscanf(sEingabe, \"%c\", &cTaste);\n"
	"          switch(cTaste)\n"
	"          {\n"
	"              case '0':\n"
	"              {\n"
	"                  /* setze hier fort */\n"
	"                  continue;\n"
	"              }\n"
	"              case '1':\n"
	"              {\n"
	"                  /* mache etwas */\n"
	"                  break;\n"
	"              }\n"
	"              case '2':\n"
	"              {\n"
	"                  /* mache etwas */\n"
	"                  break;\n"  
	"              }\n"
	"              case '3':\n"
	"              {\n"
	"                  /* beende hier */\n"
	"                  break;\n"
	"              }\n"
	"              default:\n"
	"              {\n"
	"                  /* gebe etwas aus */\n"
	"                  break;\n"
	"              }\n"
	"          }\n"
	"      }while(cTaste != '3');             /* Ende der Schleife */\n" 
	"      return EXIT_SUCCESS;\n"
	"  }\n\n"
	"/** Steuerprogramm\n"
	"  */\n"
	"  int iController()\n"
	"  {\n"
	"      iMenue();                          /* Funktion an OS-Ebene uebergeben */\n"
	"      return EXIT_SUCCESS;\n"
	"  }\n\n"
	"/** Hauptprogramm\n"
	"  */\n"
	"  int main()\n"
	"  {\n"
	"      iController();                     /* Rueckgabe aus iController() */\n"
	"      return EXIT_SUCCESS;\n"
	"  }\n\n"
	"/** Programmende\n"
	"  */"};
	  
	  char sHeader[] = {
	  "  #include <string.h>"
	  "                    /* Zeichenkettenoperationen */\n"
	  "  #include <math.h>"
	  "                      /* Mathematische Funktionen */\n"
	  "  #include <time.h>"
	  "                      /* Datum und Uhrzeit */\n"
	  "  #include <ctype.h>"
	  "                     /* Zeichenkonvertierung */\n"
	  "  #include <signal.h>"
	  "                    /* Signale behandeln */\n"};
	  
	  char sDisplay[] = {
	  "\n\n                   H E R Z L I C H  W I L L K O M M E N  I N                   \n"
	  "                                                                                \n"
	  "                                          .       .                            \n"
	  "                                        .-')    .-') _                         \n"
	  "           .                           ( 00 ). (  00) )                        \n"
	  "         .-')___            _         (_`--_ )/ `-- '.__,-._  _                \n"
	  "        ( 00/ __\\ ___    __| |  ___   / _\\| |_  _   _   __| |(_)  ___          \n"
	  "        /`-/ /   / _ \\  / _` | / _ \\  \\ \\ | __|| | | | / _` || | / _ \\         \n"
	  "        \\_) /___| (_) || (_| ||  __/  _\\ \\| |_ | |_| || (_| || || (_) |        \n"
	  "          \\____/ \\___/  \\____| \\___|  \\__/ \\__| \\____| \\____||_| \\___/\n\n"};
	fwrite(sTemplate, 1, sizeof(sTemplate), FPFile);
	fwrite(sHeader, 1, sizeof(sHeader), FPHeader);
	fwrite(sDisplay, 1, sizeof(sDisplay), FPDisp);
	fclose(FPFile);
	fclose(FPHeader);
	fclose(FPDisp);
	printf("Schreiben erfolgreich");
	getchar();
	return 0;
}
