#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *FPointer;

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
   /*char nichts[]={"\">"};*/

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
    /*else
    {
    fputs(nichts, FPointer);
    }*/   
}
    

int main(int argc, char *argv[])
{
    
    char file_name[265];
    char Anfang[]={"<html>\n<head>\n<title>"};
    char Titelname[100];
    char Titel[]={"</title>\n</head>\n<body>\n"};
    int Ueber;
    char Pixel[50];
    char Groesse[]={"<div style=\"font-size:"};
    char Ende1[]={"px;\">"};
    char ueber2[200];
    //char Ende2[]={"</div>"};
    char Farbe[20];
    char Farbe1[]={"<font color=\""};
    char ende3[]={"\">"};
    char Back[20];
    char back1[]={"<body bgcolor=\""};
    //char leer[]={"\n"};
    int Zeilen;
    char leer2[]={"<br>"};
    int i;
    int Stellung;
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
    int ja;
    char Farbe10[100];
    //char Schrift[100];
    //char Schriftart[]={"<font face=\""};
    int a;
    int Zeilen1;
    char Linkpfad[255];
    char Link1[]={"<a href=\""};
    int Zeilen2;
    int b;
    char Linkname[100];
    char Ende[]={"</a>"};
    char Pixel1[100];
    char bende[]={"</body>\n</html>"};
    char Links[]={"<div style=\"text-align:left;\">"};
    char Quelltext[500];
    //char Name[300];
    //char HTML[]={".html"};
    
    Ueber=0;  
    
      
    
    printf("Wie soll die Datei heissen :\n");
    scanf("%s",file_name);
    fflush(stdin);
    
    FPointer = fopen(file_name, "w+");
    
    if(FPointer == NULL)
    {
         printf("Konnte Datei %s nicht erstellen!\n",file_name);
         exit(0);
    }
    
    printf("Wie soll der Titel der Website lauten : ");
    fgets(Titelname, sizeof(Titelname),stdin);
    printf("Welche Farbe soll die Schrift haben(bitte in Englisch) : ");
    fgets(Farbe,sizeof(Farbe),stdin);
        
    printf("Welche Farbe soll der Hintergrund haben(bitte in Englisch) : ");
    fgets(Back, sizeof(Back),stdin);
    
    system("clear");
    
    printf("Was wollen Sie noch hinzufuegen? Geben Sie jeweils die Zahl ein:\n<1>Ueberschrift oder Text erstellen\n<2>ein Bild einfuegen\n<3>einen Link einfuegen\n<4>eigenen Quelltext einfuegen\n<5>Ende\n");
    printf("Ihre Eingabe ist ");
    scanf("%d",&Ueber);
    fflush(stdin);
    system("clear");  
       
    fputs(Anfang, FPointer);
    fputs(Titelname, FPointer);
    fputs(Titel, FPointer);
    fputs(Farbe1, FPointer);
    Farben(Farbe);
    fprintf(FPointer,"\n");
    fputs(back1, FPointer);
    Farben(Back);
    fprintf(FPointer,"\n");
     
    while(Ueber!=5)
    {   
                   if(Ueber==1)
                   {
                               /*printf("In welcher Schriftart soll der Text geschrieben werden:");
                               fgets(Schrift, sizeof(Schrift),stdin);*/
                               printf("Soll der Text eine andere Schriftfarbe haben? Wenn ja geben Sie 1 ein, \nwenn nicht 2:");
                               scanf("%d",&ja);
                               fflush(stdin);
                               if(ja==1)
                               {
                                        fprintf(FPointer,"\n</font>\n");
                                        printf("Welche Farbe soll die Schrift haben(bitte in Englisch) : ");
                                        fgets(Farbe10,sizeof(Farbe10),stdin);
                               }
                               printf("Wie viele Pixel soll die Ueberschrift oder der Text haben : ");
                               scanf("%s",Pixel);
                               getchar();
                               printf("Welche Stellung soll die Ueberschrift oder Text haben? Fuer lingsbuendig\ndruecken Sie die 1, fuer zentriert die 2 und fuer rechtsbuendig die 3 : ");
                               scanf("%d",&Stellung);
                               fflush(stdin);
                               printf("Geben Sie hier den Text oder die Ueberschrift ein :\n");
                               fgets(ueber2, sizeof(ueber2),stdin);
                               printf("Wie viele Zeilen Abstand sollen bis zum naechsten Text oder Bild sein: ");
                               scanf("%d",&Zeilen);
                               fflush(stdin);
    
                               /*fputs(Schriftart, FPointer);
                               fputs(Schrift, FPointer);
                               fputs(ende3, FPointer);*/
    
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
                               
                               
                               
                 }

                 if(Ueber==2)
                 {
                                printf("Geben Sie hier bitte den Pfad des Bildes ein :\n");
                                fgets(Pfad, sizeof(Pfad),stdin);
                                printf("Geben Sie hier die Breite des Bildes an :");
                                fgets(Breite, sizeof(Breite),stdin);
                                printf("Wie hoch soll das Bild sein :");
                                fgets(Hoehe, sizeof(Hoehe),stdin);
                                printf("Wie breit soll der Rahmen sein (Zahl) :");
                                fgets(Rand, sizeof(Rand),stdin);
                                printf("Beschreibung des Bildes:\n");
                                fgets(Schreib, sizeof(Schreib),stdin);
                                printf("Wie viele Zeilen Abstand sollen bis zum naechsten Text oder Bild sein: ");
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
                                
                                for(a=0;a<Zeilen1;a++)
                                {                     
                                                      fputs(leer2, FPointer);
                                                      fprintf(FPointer,"\n");
                                }
                  }
                  if(Ueber==3)
                  {
                                printf("Geben Sie hier bitte den Pfad der Datei ein, mit der Sie ihre Seite verlinken\nmoechten:\n");
                                fgets(Linkpfad, sizeof(Linkpfad),stdin);
                                printf("Wie viele Pixel soll die Ueberschrift oder der Text haben : ");
                                //fgets(Pixel1, sizeof(Pixel1),stdin);
                                scanf("%s",Pixel1);
                                getchar();
                                printf("Wie soll der Link heissen :\n");
                                fgets(Linkname, sizeof(Linkname),stdin);
                                printf("Wie viele Zeilen Abstand sollen bis zum naechsten Text oder Bild sein: ");
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
                                
                   }
                   if(Ueber==4)
                   {
                                printf("Geben Sie hier ihren Quelltext ein :\n");
                                fgets(Quelltext, sizeof(Quelltext),stdin);

                                fputs(Quelltext, FPointer);

                   }
                   system("clear"); 
                   printf("Was wollen Sie noch hinzufuegen? Geben Sie jeweils die Zahl ein:\n<1>Ueberschrift oder Text erstellen\n<2>ein Bild einfuegen\n<3>einen Link einfuegen\n<4>eigenen Quelltext einfuegen\n<5>Ende\n");
                   printf("Ihre Eingabe ist ");
                   scanf("%d",&Ueber);
                   fflush(stdin);
                   system("clear");
    }
    fprintf(FPointer,"\n</font>\n");
    fputs(bende, FPointer);
    fclose(FPointer);
    system(file_name);
    system("clear");
       
  return 0;
}
