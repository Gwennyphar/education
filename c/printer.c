/** printer.c
  * Druckausgabe mit popen()
  */

/** Praeprozessor
  *
  */

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

/** Druckauftrag
  * iPrinter()
  */

int iPrinter()
{
	int iStatus = 0;
	FILE  *FPStream;

	
/** popen() Aufruf des Programm "lpr"
  * -P Zusatz fuer Ausagbegeraet
  */
	if ((FPStream = popen ("lpr", "w")) == NULL)
	{
		perror("printer: popen() fehlgeschlagen");
		return (1);
	}

/** Zeile 24 bis 31
  * Postscript Sequenz an Standardeingabekanal "lpr"
  */	
    fprintf(FPStream, "%%!PS\n%%%%BoundingBox: 30 30 565 810\n"
					  "%%%%Orientation: Portrait\n%%%%EndProlog\n"
					  "100 700 moveto\n"
					  "/Time-Roman 24 selectfont\n"
					  "(Hello World, ich grüße dich!) show\n)"
					  "currentpoint pop 100 add 2 div\n"
					  "newpath 708 65 0 360 arc stroke\n"
					  "showpage\n");

	iStatus = pclose (FPStream);
	printf("print: lpr returned %d.\n", iStatus);
	system("pause");
	return (0);
}

/** Steuerfunktion
  * iController
  */
	int iController()
	{
		iPrinter();
		return 0;
	}

/** Schnittstelle
  * main()
  */
	int main()
	{
		iController();
		return 0;
	}

/** Programmende
  * printer.c
  */
