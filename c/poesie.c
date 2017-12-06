#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* Plusumlaut(char umlautwort[900])
{
      int g;
      for(g=0;g<strlen(umlautwort);g++)
      {
        if(umlautwort[g]==-4)  umlautwort[g]='\x81';
        if(umlautwort[g]==-28) umlautwort[g]='\x84';
        if(umlautwort[g]==-10) umlautwort[g]='\x94';
        if(umlautwort[g]==-60) umlautwort[g]='\x8E';
        if(umlautwort[g]==-42) umlautwort[g]='\x99';
        if(umlautwort[g]==-36) umlautwort[g]='\x9A';
        if(umlautwort[g]==-33) umlautwort[g]='\xE1';                      
      }
      return umlautwort;
}

int main(int argc, char *argv[])
{
  srand(time(0));
  
  char Worte[40][50][900];
  int rel1[100];
  int i;
  
  strcpy(Worte[0][0],"tropfweise");
  strcpy(Worte[0][1],"langsame");
  strcpy(Worte[0][2],"überflüssige");
  strcpy(Worte[0][3],"meilenweite");
  strcpy(Worte[0][4],"unendliche");
  strcpy(Worte[0][5],"goldene");
  strcpy(Worte[0][6],"hitzige");
  strcpy(Worte[0][7],"klärende");
  strcpy(Worte[0][8],"geniale");
  strcpy(Worte[0][9],"stoßhafte");
  strcpy(Worte[0][10],"sinnlose");
  strcpy(Worte[0][11],"beklommene"); 
  strcpy(Worte[0][12],"sonnige");
  strcpy(Worte[0][13],"glühende");
  strcpy(Worte[0][14],"wütende");
  strcpy(Worte[0][15],"siegende");
  strcpy(Worte[0][16],"zweideutige");
  strcpy(Worte[0][17],"hilflose");
  strcpy(Worte[0][18],"vorgedruckte");
  strcpy(Worte[0][19],"brennende");
  strcpy(Worte[0][20],"hoffnungslose");
  strcpy(Worte[0][21],"scheinheilige"); 
  strcpy(Worte[0][22],"einsilbrige");
  strcpy(Worte[0][23],"würgende");
  strcpy(Worte[0][24],"lächerliche");
  strcpy(Worte[0][25],"schniefende");
  strcpy(Worte[0][26],"glückliche"); 
  strcpy(Worte[0][27],"kalte");
  strcpy(Worte[0][28],"spießige");
  strcpy(Worte[0][29],"intelligente");
  strcpy(Worte[0][30],"arrogante");
  strcpy(Worte[0][31],"stumme"); 
  strcpy(Worte[0][32],"schwärmende");
  strcpy(Worte[0][33],"teigige");
  strcpy(Worte[0][34],"silberne");
  strcpy(Worte[0][35],"kritische");
  strcpy(Worte[0][36],"fossile"); 
  strcpy(Worte[0][37],"endlose");
  strcpy(Worte[0][38],"wuchernde");
  strcpy(Worte[0][39],"anstrengende");
  strcpy(Worte[0][40],"komplizierte");
  strcpy(Worte[0][41],"leichte");
  strcpy(Worte[0][42],"verworrene");
  strcpy(Worte[0][43],"schreckliche");
  strcpy(Worte[0][44],"großartige");
  strcpy(Worte[0][45],"unglaubliche");
  strcpy(Worte[0][46],"reiche");
  
  strcpy(Worte[1][0],"Melancholie"); 
  strcpy(Worte[1][1],"Ambivalenz");
  strcpy(Worte[1][2],"Erpressungen");
  strcpy(Worte[1][3],"Stille");
  strcpy(Worte[1][4],"Miene");
  strcpy(Worte[1][5],"Einstellung");
  strcpy(Worte[1][6],"Atmung");
  strcpy(Worte[1][7],"Bürokratie");
  strcpy(Worte[1][8],"Versuchung");
  strcpy(Worte[1][9],"Erfrischung");
  strcpy(Worte[1][10],"Angstzustände");
  strcpy(Worte[1][11],"Plasphemie");
  strcpy(Worte[1][12],"Wissenschaft");
  strcpy(Worte[1][13],"Dekadenz");
  strcpy(Worte[1][14],"Jugend");
  strcpy(Worte[1][15],"Informatik");
  strcpy(Worte[1][16],"Euphorie");
  
  strcpy(Worte[2][0],"in Gänsefüßchen"); 
  strcpy(Worte[2][1],"in den Gremien");
  strcpy(Worte[2][2],"im Nirgendwo");
  strcpy(Worte[2][3],"in der Schule");
  strcpy(Worte[2][4],"im Bundestag");
  strcpy(Worte[2][4],"in der Schule");
  strcpy(Worte[2][4],"am Anfang");
  strcpy(Worte[2][4],"in Europa");
  
  for(i=0;i<50;i++) strcpy(Worte[3][i],Worte[0][i]);
  
  strcpy(Worte[4][0],"Haarausfall"); 
  strcpy(Worte[4][1],"Edelmut");
  strcpy(Worte[4][2],"Kunstgenuss");
  strcpy(Worte[4][3],"Horizont");
  strcpy(Worte[4][4],"Ehrgeiz");
  strcpy(Worte[4][5],"Tag");
  strcpy(Worte[4][6],"Ausfall");
  
  strcpy(Worte[5][0],"vor dem Sturm"); 
  strcpy(Worte[5][1],"am Wochenende");
  strcpy(Worte[5][2],"vor den Ferien");
  strcpy(Worte[5][3],"vor dem Nichts");
  strcpy(Worte[5][4],"vor dem Ende der Welt");
  strcpy(Worte[5][5],"in der Nacht");
  strcpy(Worte[5][6],"vor dem Angriff");
  
  for(i=0;i<50;i++) strcpy(Worte[6][i],Worte[0][i]);
  
  strcpy(Worte[7][0],"Fluchtversuche"); 
  strcpy(Worte[7][1],"Fälschungen");
  strcpy(Worte[7][2],"Zahlungsbefehle");
  strcpy(Worte[7][3],"Spaziergänge");
  strcpy(Worte[7][4],"Fußballspiele");
  strcpy(Worte[7][5],"Stunden");
  strcpy(Worte[7][6],"Ängste");
  
  strcpy(Worte[8][0],"Zugegeben"); 
  strcpy(Worte[8][1],"Schleierhaft");
  strcpy(Worte[8][2],"Hilfe");
  strcpy(Worte[8][3],"Schrecklich");
  strcpy(Worte[8][4],"Herrlich");
  strcpy(Worte[8][5],"Verschwendet");
  strcpy(Worte[8][6],"Plötzlich");
  strcpy(Worte[8][7],"Wahrlich");
  strcpy(Worte[8][7],"Grausam");
  
  strcpy(Worte[9][0],"Ansonsten"); 
  strcpy(Worte[9][1],"Im Grunde");
  strcpy(Worte[9][2],"Schließlich");
  strcpy(Worte[9][3],"Selbstverständlich");
  strcpy(Worte[9][4],"Keineswegs");
  strcpy(Worte[9][5],"Dennoch");
  strcpy(Worte[9][6],"Dabei");
    
  strcpy(Worte[10][0],"verhindern wir"); 
  strcpy(Worte[10][1],"ertragen wir");
  strcpy(Worte[10][2],"langweilt uns");
  strcpy(Worte[10][3],"arbeiten wir");
  strcpy(Worte[10][4],"genießen wir");
  strcpy(Worte[10][5],"vergessen wir");
  strcpy(Worte[10][6],"zerstören wir");
  strcpy(Worte[10][7],"verdrängen wir");
  strcpy(Worte[10][8],"erlauben wir");
  
  strcpy(Worte[11][0],"einfach zu viel"); 
  strcpy(Worte[11][1],"doch manches");
  strcpy(Worte[11][2],"vieles");
  strcpy(Worte[11][3],"zu wenig");
  strcpy(Worte[11][4],"genug und mehr als das");
  strcpy(Worte[11][5],"doch alles");
  strcpy(Worte[11][6],"dies und das");
  
  strcpy(Worte[12][0],"Danach"); 
  strcpy(Worte[12][1],"Im Abseits");
  strcpy(Worte[12][2],"Einstweilen");
  strcpy(Worte[12][3],"Plötzlich");
  strcpy(Worte[12][4],"Schließlich");
  
  strcpy(Worte[13][0],"allerlei"); 
  strcpy(Worte[13][1],"auf Antrag");
  strcpy(Worte[13][2],"lediglich");
  strcpy(Worte[13][3],"höchstens");
  strcpy(Worte[13][4],"\b, wenn es niemand stört");
  
  for(i=0;i<50;i++) strcpy(Worte[14][i],Worte[0][i]);
  
  strcpy(Worte[15][0],"Fortschritte"); 
  strcpy(Worte[15][1],"Schlussrunden");
  strcpy(Worte[15][2],"Lügen");
  strcpy(Worte[15][3],"Demonstrationen");
  strcpy(Worte[15][4],"Vorurteile");
  
  strcpy(Worte[16][0],"Ununterbrochen"); 
  strcpy(Worte[16][1],"Pünktlich");
  strcpy(Worte[16][2],"Zu spät");
  strcpy(Worte[16][3],"Täglich");
  strcpy(Worte[16][4],"Manchmal");
  
  strcpy(Worte[17][0],"ausflippen"); 
  strcpy(Worte[17][1],"daran denken");
  strcpy(Worte[17][2],"darauf aufpassen");
  strcpy(Worte[17][3],"einschrumpfen");
  strcpy(Worte[17][4],"bejubeln");
  
  strcpy(Worte[18][0],"Hörspiele"); 
  strcpy(Worte[18][1],"Fixe Ideen");
  strcpy(Worte[18][2],"Einflüsterungen");
  strcpy(Worte[18][3],"Hirngespinste");
  strcpy(Worte[18][4],"Gedanken im Unterbewusstsein");
  strcpy(Worte[18][5],"Musik");
  strcpy(Worte[18][6],"Videos");
  
  strcpy(Worte[19][0],"Ihr seid"); 
  strcpy(Worte[19][1],"Dieses Schwein ist");
  strcpy(Worte[19][2],"Deine Freunde sind");
  strcpy(Worte[19][3],"Diese Frau Merkel ist");
  strcpy(Worte[19][4],"Ich bin");
  strcpy(Worte[19][5],"Menschen sind");
  strcpy(Worte[19][6],"Die Kirchen sind");
  
  strcpy(Worte[20][0],"nämlich"); 
  strcpy(Worte[20][1],"aber");
  strcpy(Worte[20][2],"wieder");
  strcpy(Worte[20][3],"ja");
  strcpy(Worte[20][4],"wie immer");
  
  for(i=0;i<50;i++) strcpy(Worte[21][i],Worte[0][i]);
  
  strcpy(Worte[22][0],"Letzten Endes"); 
  strcpy(Worte[22][1],"Im Treppenhaus");
  strcpy(Worte[22][2],"Im Hinterkopf");
  strcpy(Worte[22][3],"Auf der Toilette");
  strcpy(Worte[22][4],"Im Bett");
  
  strcpy(Worte[23][0],"Scheingefechte"); 
  strcpy(Worte[23][1],"Zukunftsmusik");
  strcpy(Worte[23][2],"Nullsummenspiele");
  strcpy(Worte[23][3],"Gedankenblitze");
  strcpy(Worte[23][4],"Schäfchen zählen");
  strcpy(Worte[23][5],"Angstzustände");
  
  for(i=0;i<50;i++) strcpy(Worte[24][i],Worte[0][i]);
  
  strcpy(Worte[25][0],"Zahnersatz");                  rel1[0]=1;
  strcpy(Worte[25][1],"Andenken");                    rel1[1]=3;
  strcpy(Worte[25][2],"Tagesschau");                  rel1[2]=2;
  strcpy(Worte[25][3],"Plombe");                      rel1[3]=2;
  strcpy(Worte[25][4],"Theaterstück");                rel1[4]=3;
  
  strcpy(Worte[26][0],"versüßt uns nur das Elend"); 
  strcpy(Worte[26][1],"rächt sich");
  strcpy(Worte[26][2],"sagt mehr über uns als das Elend");
  strcpy(Worte[26][3],"verschönert das Lächeln");
  strcpy(Worte[26][4],"begreift sich im Tiefgang");
  
  strcpy(Worte[27][0],"das Ende"); 
  strcpy(Worte[27][1],"der Regen");
  strcpy(Worte[27][2],"die Waage der Gerechtigkeit");
  strcpy(Worte[27][3],"der grausame Diktator");
  strcpy(Worte[27][4],"die Verse des Archil");
  
  strcpy(Worte[28][0],"Anstandshalber"); 
  strcpy(Worte[28][1],"Letzten Endes");
  strcpy(Worte[28][2],"Trotzdem");
  strcpy(Worte[28][3],"Zum Schluß");
  strcpy(Worte[28][4],"Zu Beginn");
  
  strcpy(Worte[29][0],"streiken"); 
  strcpy(Worte[29][1],"sterben");
  strcpy(Worte[29][2],"lesen");
  strcpy(Worte[29][3],"denken");
  strcpy(Worte[29][4],"rechnen");
  
  strcpy(Worte[30][0],"ganz allein"); 
  strcpy(Worte[30][1],"doch");
  strcpy(Worte[30][2],"niemals");
  strcpy(Worte[30][3],"immerzu");
  strcpy(Worte[30][4],"täglich");
  
  strcpy(Worte[31][0],"Überstunden"); 
  strcpy(Worte[31][1],"Speisereste");
  strcpy(Worte[31][2],"Ausbrüche");
  strcpy(Worte[31][3],"Unfälle");
  strcpy(Worte[31][4],"Anschläge");
  strcpy(Worte[31][5],"Kontrollen");
  strcpy(Worte[31][6],"Hungersnöte");
  strcpy(Worte[31][7],"Kontrollen");
  strcpy(Worte[31][8],"Exekutionen");
  
  strcpy(Worte[32][0],"Ratlosigkeit"); 
  strcpy(Worte[32][1],"Blindgänger");
  strcpy(Worte[32][2],"Tränengas");
  strcpy(Worte[32][3],"Notstandsgesetz");
  strcpy(Worte[32][4],"Hoffnungslosigkeit");
  strcpy(Worte[32][5],"Wehrpflicht");
  strcpy(Worte[32][6],"Krankheit");
  strcpy(Worte[32][7],"Euthanasie");
    
  for(i=0;i<50;i++) strcpy(Worte[33][i],Worte[0][i]);
  
  strcpy(Worte[34][0],"Wahnsysteme"); 
  strcpy(Worte[34][1],"Weichbilder");
  strcpy(Worte[34][2],"Wolkendecken");
  strcpy(Worte[34][3],"Operationen");
  strcpy(Worte[34][4],"Versuche");
  strcpy(Worte[34][5],"Paragraphen");
  strcpy(Worte[34][5],"Bomben");
  
  strcpy(Worte[35][0],"Letzten Endes"); 
  strcpy(Worte[35][1],"Selbstverständlich");
  strcpy(Worte[35][2],"Am Ende");
  strcpy(Worte[35][3],"Hoffentlich");
  strcpy(Worte[35][4],"Im Grunde");
  
  strcpy(Worte[36][0],"geht alles so weiter"); 
  strcpy(Worte[36][1],"sind wir dagegen");
  strcpy(Worte[36][2],"wird alles gut");
  strcpy(Worte[36][3],"fliegen wir gern");
  strcpy(Worte[36][4],"grenzen wir uns ab");
  strcpy(Worte[36][5],"begreifen wir nie");
  
  char rel[4][5];
  strcpy(rel[1],"Der");
  strcpy(rel[2],"Die");
  strcpy(rel[3],"Das");
  
  int Zufall[100];
  
  int o=0;
  char Zwischen[900];
  int Anzahl[100];
  int zu;
  
  while(1)
  {
          for(i=0;i<100;i++) Anzahl[i]=5;
          
          for(o=0;o<37;o++)
          {
                  for(i=0;i<50;i++) 
                  {
                                    if(strcmp(Worte[o][i],"")==0)
                                    {
                                                                     Anzahl[o]=i;
                                                                     break;                                                             
                                    }
                                    else sprintf(Worte[o][i],"%s",Plusumlaut(Worte[o][i]));                           
                  }
          }
          
          for(i=0;i<37;i++) Zufall[i]=(rand() % Anzahl[i]);
          
          strcpy(Zwischen,Worte[0][Zufall[0]]);                   
          Zwischen[0]=toupper(Worte[0][Zufall[0]][0]);
          
          printf("%s %s %s\n",Zwischen,Worte[1][Zufall[1]],Worte[2][Zufall[2]]);
          printf("Dieser %s %s %s.\n",Worte[3][Zufall[3]],Worte[4][Zufall[4]],Worte[5][Zufall[5]]);
          printf("Und diese %sn %s:\n",Worte[6][Zufall[6]],Worte[7][Zufall[7]]);
          printf("%s! %s %s %s.\n\n",Worte[8][Zufall[8]],Worte[9][Zufall[9]],Worte[10][Zufall[10]],Worte[11][Zufall[11]]);
          
          strcpy(Zwischen,Worte[21][Zufall[21]]);
          Zwischen[strlen(Zwischen)-1]='\0';
          
          printf("%s %s %s %s.\n",Worte[12][Zufall[12]],Worte[13][Zufall[13]],Worte[14][Zufall[14]],Worte[15][Zufall[15]]);
          printf("%s %s!\n",Worte[16][Zufall[16]],Worte[17][Zufall[17]]);
          printf("%s. (\"%s %s %s.\")\n",Worte[18][Zufall[18]],Worte[19][Zufall[19]],Worte[20][Zufall[20]],Zwischen);
          printf("%s %s.\n\n",Worte[22][Zufall[22]],Worte[23][Zufall[23]]);
          
          strcpy(Zwischen,Worte[33][Zufall[33]]);                   
          Zwischen[0]=toupper(Worte[33][Zufall[33]][0]);
          
          printf("%s %s %s %s.\n",rel[rel1[Zufall[25]]],Worte[24][Zufall[24]],Worte[25][Zufall[25]],Worte[26][Zufall[26]]);
          printf("So wie %s. %s %s wir %s.\n",Worte[27][Zufall[27]],Worte[28][Zufall[28]],Worte[29][Zufall[29]],Worte[30][Zufall[30]]);
          printf("%s. %s. %s %s.\n",Worte[31][Zufall[31]],Worte[32][Zufall[32]],Zwischen,Worte[34][Zufall[34]]);
          printf("%s %s.\n\n",Worte[35][Zufall[35]],Worte[36][Zufall[36]]);
          
          printf("\n");
          
          system("PAUSE");	
          system("CLS");
 }
  return 0;
}
