/** Programm.: main.c
  * Version..: 0.1
  * Autor....: Nico Anders 
  * Datum....: Sat Jul  7 00:01:03 2012
  * Status...: in Arbeit
  * ToDo.....: HTML Assistenten implementieren 
  */

/** Praeprozessor
  */
  #include <stdio.h>                     /* Standard-I/O */
  #include <stdlib.h>                    /* Nuetzliche Funktionen */
  #include <string.h>                    /* Zeichenkettenoperationen */
  #include <math.h>                      /* Mathematische Funktionen */
  #include <time.h>                      /* Datum und Uhrzeit */

/** Funktion.....: Global
  * Beschreibung.: 
  * Status.......: in Arbeit
  */
  void iClear()
  {
	  printf("\033[1J\033[1;1H");
	  printf("\n\n\t");
  }
  
/** Funktion.....: Global
  * Beschreibung.: 
  * Status.......: in Arbeit
  */
  int a;
  int b;
  int i;
  int Ueber;
  int ja;
  int Stellung;
  int Zeilen;
  int Zeilen1;
  int Zeilen2;
  char cGruen[]={"green\">"};
  char cSchwarz[]={"black\">"};
  char cGelb[]={"yellow\">"};
  char cWeiss[]={"white\">"};
  char cGru[]={"green\">"};
  char cBraun[]={"brown\">"};
  char cGrau[]={"grey\">"};
  char cMagenta[]={"pink\">"};
  char cRot[]={"red\">"};
  char cBlau[]={"blue\">"};
  char nichts[]={"\">"};
  	  char file_name[265];
	  char Anfang[]={"<html>\n<head>\n<title>"};
	  char Titelname[100];
	  char Titel[]={"</title>\n</head>\n<body>\n"};
	  char Pixel[50];
	  char Groesse[]={"<div style=\"font-size:"};
	  char Ende1[]={"px;\">"};
	  char ueber2[200];
	  char Farbe[20];
	  char Farbe1[]={"<font color=\""};
	  char ende3[]={"\">"};
	  char Back[20];
	  char back1[]={"<body bgcolor=\""};
	  char leer2[]={"<br>"};
	  char Mitte[]={"<center>"};
	  char Rechts[]={"<div style=\"text-align:right;\">"};
	  char Bild1[]={"<img src=\""};
	  char Pfad[255];
	  char end[]={"\" "};
	  char an[]={"width=\""};
	  char Breite[20];
	  char an1[]={"height=\""};
	  char Hoehe[20];
	  char an2[]={"border=\""};
	  char Rand[20];
	  char an3[]={"alt=\""};
	  char Schreib[100];
	  char Klam[]={">"};
	  char Farbe10[100];
	  char Schrift[100];
	  char Schriftart[]={"<font face=\""};
	  char Linkpfad[255];
	  char Link1[]={"<a href=\""};
	  char Linkname[100];
	  char Ende[]={"</a>"};
	  char Pixel1[100];
	  char bende[]={"</body>\n</html>"};
	  char Links[]={"<div style=\"text-align:left;\">"};
	  char Quelltext[500];
	  int Ueber=0;
	  FILE *FPointer;

/** Funktion.....: 
  * Beschreibung.: 
  * Status.......: in Arbeit
  */
  void Farben(char d[30])
  {
	  if(d[0]=='g' && d[3]=='e')
	  {
		  fputs(cGru, FPointer);
	  }
	  if(d[0]=='b' && d[2]=='a')
	  {
		  fputs(cSchwarz, FPointer);
	  }
	  if(d[0]=='r')
	  {
		  fputs(cRot, FPointer);
	  }
	  if(d[0]=='y')
	  {
		  fputs(cGelb, FPointer);
	  }
	  if(d[0]=='w')
	  {
		  fputs(cWeiss, FPointer);
	  }
	  if(d[0]=='g' && d[3]=='y')
	  {
		  fputs(cGrau, FPointer);
	  }
	  if(d[0]=='b' && d[2]=='u')
	  {
		  fputs(cBlau, FPointer);
	  }
	  if(d[0]=='b' && d[2]=='r')
	  {
		  fputs(cBraun, FPointer);
	  }
	  if(d[0]=='p')
	  {
		  fputs(cMagenta, FPointer);
	  }
	  else
	  {
		  fputs(nichts, FPointer);
	  }
  } 

/** Funktion.....: 
  * Beschreibung.: 
  * Status.......: in Arbeit
  */
  int iQuelltext_einfuegen()
  {
	  iClear();
	  printf("Geben Sie hier ihren Quelltext ein:\n\n");
	  fgets(Quelltext, sizeof(Quelltext),stdin);
	  fputs(Quelltext, FPointer);
	  fprintf(FPointer,"\n</font>\n");
	  fputs(bende, FPointer);
	  fclose(FPointer);
	  system(file_name);
	  return EXIT_SUCCESS;
  }

/** Funktion.....: 
  * Beschreibung.: 
  * Status.......: in Arbeit
  */
  int iLink_einfuegen()
  {
	  iClear();
	  printf("Geben Sie hier bitte den Pfad der Datei ein, mit der Sie ihre"
	  " Seite verlinken\nmoechten:\n\n");
	  fgets(Linkpfad, sizeof(Linkpfad),stdin);
	  iClear();
	  printf("Wie viele Pixel soll die Ueberschrift oder der Text haben:\n\n");
	  fgets(Pixel1, sizeof(Pixel1),stdin);
	  scanf("%s",Pixel1);
	  getchar();
	  iClear();
	  printf("Wie soll der Link heissen :\n");
	  fgets(Linkname, sizeof(Linkname),stdin);
	  iClear();
	  printf("Wie viele Zeilen Abstand sollen bis zum naechsten"
	  " Text oder Bild sein:\n\n");
	  scanf("%d",&Zeilen2);
	  fflush(stdin);
	  fputs(Groesse, FPointer);
	  fputs(Pixel1, FPointer);
	  fputs(Ende1, FPointer);
	  fprintf(FPointer,"\n");
	  fputs(Link1, FPointer);
	  fputs(Linkpfad, FPointer);
	  fputs(ende3, FPointer);
	  fputs(Linkname, FPointer);
	  fputs(Ende, FPointer);
	  fprintf(FPointer,"\n");
	  for(b=0;b<Zeilen2;b++)
	  {
		  fputs(leer2, FPointer);
		  fprintf(FPointer,"\n");
	  }
	  fprintf(FPointer,"</div>\n");
	  return EXIT_SUCCESS;
  }


/** Funktion.....: 
  * Beschreibung.: 
  * Status.......: in Arbeit
  */
  int iBild_einfuegen()
  {
	  iClear();
	  printf("Geben Sie hier bitte den Pfad des Bildes ein:\n\n");
	  fgets(Pfad, sizeof(Pfad),stdin);
	  iClear();
	  printf("Geben Sie hier die Breite des Bildes an:\n\n");
	  fgets(Breite, sizeof(Breite),stdin);
	  iClear();
	  printf("Wie hoch soll das Bild sein:\n\n");
	  fgets(Hoehe, sizeof(Hoehe),stdin);
	  iClear();
	  printf("Wie breit soll der Rahmen sein (Zahl):\n\n");
	  fgets(Rand, sizeof(Rand),stdin);
	  iClear();
	  printf("Beschreibung des Bildes:\n\n");
	  fgets(Schreib, sizeof(Schreib),stdin);
	  iClear();
	  printf("Wie viele Zeilen Abstand sollen bis zum naechsten Text oder Bild sein:\n\n");
	  scanf("%d",&Zeilen1);
	  fflush(stdin);
	  fputs(Bild1, FPointer);
	  fputs(Pfad, FPointer);
	  fputs(end, FPointer);
	  fputs(an, FPointer);
	  fputs(Breite, FPointer);
	  fputs(end, FPointer);
	  fputs(an1, FPointer);
	  fputs(Hoehe, FPointer);
	  fputs(end, FPointer);
	  fputs(an2, FPointer);
	  fputs(Rand, FPointer);
	  fputs(end, FPointer);
	  fputs(an3, FPointer);
	  fputs(Schreib, FPointer);
	  fputs(end, FPointer);
	  fputs(Klam, FPointer);
	  fprintf(FPointer,"\n");
	  for(a = 0; a < Zeilen1; a++)
	  {
		  fputs(leer2, FPointer);
		  fprintf(FPointer,"\n");
	  }
	  return EXIT_SUCCESS;
  }

/** Funktion.....: 
  * Beschreibung.: 
  * Status.......: in Arbeit
  */
  int iUeberschrift_erstellen()
  {
	  iClear();
	  printf("In welcher Schriftart soll der Text geschrieben werden:\n\n");
	  fgets(Schrift, sizeof(Schrift),stdin);
	  iClear();
	  printf("Soll der Text eine andere Schriftfarbe haben?\nWenn ja geben Sie 1 ein,\n"
	  " wenn nicht 2:");
	  scanf("%d",&ja);
	  fflush(stdin);
	  if(ja==1)
	  {
		  fprintf(FPointer,"\n</font>\n");
		  iClear();
		  printf("Welche Farbe soll die Schrift haben(bitte in Englisch):\n\n");
		  fgets(Farbe10,sizeof(Farbe10),stdin);
	  }
	  iClear();
	  printf("Wie viele Pixel soll die Ueberschrift oder der Text haben:\n\n");
	  scanf("%s",Pixel);
	  getchar();
	  iClear();
	  printf("Welche Stellung soll die Ueberschrift oder Text haben? Fuer lingsbuendig\n"
	  "druecken Sie die 1, fuer zentriert die 2 und fuer rechtsbuendig die 3:\n\n");
	  scanf("%d",&Stellung);
	  fflush(stdin);
	  iClear();
	  printf("Geben Sie hier den Text oder die Ueberschrift ein:\n\n");
	  fgets(ueber2, sizeof(ueber2),stdin);
	  iClear();
	  printf("Wie viele Zeilen Abstand sollen bis zum naechsten Text oder Bild sein?\n\n");
	  scanf("%d",&Zeilen);
	  fflush(stdin);
	  fputs(Schriftart, FPointer);
	  fputs(Schrift, FPointer);
	  fputs(ende3, FPointer);
	  if(ja==1)
	  {
		  fputs(Farbe1, FPointer);
		  Farben(Farbe10);
		  fprintf(FPointer,"\n");
	  }
	  fprintf(FPointer,"%s%s%s",Groesse,Pixel,Ende1);
	  fprintf(FPointer,"\n");
	  if(Stellung==1)
	  {
		  fputs(Links, FPointer);
	  }
	  if(Stellung==2)
	  {
		  fputs(Mitte, FPointer);
	  }
	  if(Stellung==3)
	  {
		  fputs(Rechts, FPointer);
	  }
	  fprintf(FPointer,"\n");
	  fputs(ueber2, FPointer);
	  fprintf(FPointer,"\n");
	  for(i=0;i<Zeilen;i++)
	  {
		  fputs(leer2, FPointer);
		  fprintf(FPointer,"\n");
	  }
	  if(Stellung==2)
	  {
		  fprintf(FPointer,"</center>\n");
	  }
	  else
	  {
		  fprintf(FPointer,"</div>\n");
	  }
	  fprintf(FPointer,"</div>\n");
	  return EXIT_SUCCESS;
  }

/** Funktion.....: 
  * Beschreibung.: 
  * Status.......: in Arbeit
  */
  int iUebersicht()
  {
	  iClear();
	  printf("Was moechten Sie Hinzufuegen?\n\n"
	  "\t<1> Ueberschrift oder Text erstellen\n"
	  "\t<2> Bild einfuegen\n"
	  "\t<3> Link einfuegen\n"
	  "\t<4> Quelltext einfuegen\n"
	  "\t<5> Beenden\n\n");
	  return EXIT_SUCCESS;
  }


/** Funktion.....: Steuerung fuer das Hauptmenue
  * Beschreibung.: HTML Assistent generiert Grundaufbau der HTML-Seiten 
  * Status.......: in Arbeit
  */
  int iHauptmenue()
  {
      char cTaste = 0;
      char sEingabe[21];
      iClear();
      printf("H T M L - A s s i s t e n t\n\n");
      printf("\n\n\tWie soll die Datei heissen : ");
	  scanf("%s",file_name);
	  fflush(stdin);
	  FPointer = fopen(file_name, "a");
	  if(FPointer == NULL)
	  {
		  iClear();
		  printf("Konnte Datei %s nicht erstellen!\n",file_name);
		  exit(0);
	  }
	  iClear();
	  printf("Wie soll der Titel der Website lauten : ");
	  fgets(Titelname, sizeof(Titelname),stdin);
	  iClear();
	  printf("Welche Farbe soll die Schrift haben(bitte in Englisch) : ");
	  fgets(Farbe,sizeof(Farbe),stdin);
	  iClear();
	  printf("Welche Farbe soll der Hintergrund haben(bitte in Englisch) : ");
	  fgets(Back, sizeof(Back),stdin); 
	  fputs(Anfang, FPointer);
	  fputs(Titelname, FPointer);
	  fputs(Titel, FPointer);
	  fputs(Farbe1, FPointer);
	  Farben(Farbe);
	  fprintf(FPointer,"\n");
	  fputs(back1, FPointer);
	  Farben(Back);
	  fprintf(FPointer,"\n");
      do
      {
          printf("\tWas moechten Sie machen?\n"
          "\tMit '0' Auswahl anzeigen: ");
          /* abgesicherte Eingabe */
          fgets(sEingabe, sizeof(sEingabe), stdin);
          sscanf(sEingabe, "%c", &cTaste);
          if(cTaste == '0')
          {
			  iUebersicht();
              continue;
          }
          else if(cTaste == '1')
          {
              iUeberschrift_erstellen();
              break;
          }
          else if(cTaste == '2')
          {
              iBild_einfuegen();
              break;
          }
          else if(cTaste == '3')
          {
              iLink_einfuegen();
              return EXIT_SUCCESS;
          }
          else if(cTaste == '4')
          {
              iQuelltext_einfuegen();
              return EXIT_SUCCESS;
          }
          else if(cTaste == '5')
          {
              return EXIT_SUCCESS;
          }
          else if(cTaste != '0'||cTaste != '1'||cTaste != '2'||cTaste != '3' 
          ||cTaste != '4' ||cTaste != '5')
          {
			  iClear();
              printf("Diese Funktion steht leider nicht zur Auswhahl");
              fgetc(stdin);
              break;
          }
      }while(cTaste != 99);              /* Ende der Schleife */
      return EXIT_SUCCESS;
  }

/** Steuerprogramm
  */
  int iController()
  {
      iHauptmenue();
      return EXIT_SUCCESS;               /* Sprunganweisung */
  }

/** Hauptprogramm
  */
  int main()
  {
      iController();                     /* Funktionsaufruf aus iController() */
      return EXIT_SUCCESS;
  }

/** Programmende
  */
