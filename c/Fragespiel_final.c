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

int iAntworten()
{
  srand(time(0));
  
  char Worte[40][50][900];
  int rel1[100];
  int i;
  system("clear");
  strcpy(Worte[0][0],"tropfweise");
  strcpy(Worte[0][1],"langsame");
  strcpy(Worte[0][2],"überflüssige");
  strcpy(Worte[0][3],"meilenweite");
  strcpy(Worte[0][4],"unendliche");
  strcpy(Worte[0][5],"warme");
  strcpy(Worte[0][6],"hitzige");
  strcpy(Worte[0][7],"kreischende");
  strcpy(Worte[0][8],"starke");
  strcpy(Worte[0][9],"stoßhafte");
  strcpy(Worte[0][10],"furchtbare");
  strcpy(Worte[0][11],"beklemmende"); 
  strcpy(Worte[0][12],"feuchte");
  strcpy(Worte[0][13],"glühende");
  strcpy(Worte[0][14],"wütende");
  strcpy(Worte[0][15],"brüllende");
  strcpy(Worte[0][16],"zweiköpfige");
  strcpy(Worte[0][17],"hilflose");
  strcpy(Worte[0][18],"ausgehungernde");
  strcpy(Worte[0][19],"brennende");
  strcpy(Worte[0][20],"hoffnungslose");
  strcpy(Worte[0][21],"erschreckende"); 
  strcpy(Worte[0][22],"einäugige");
  strcpy(Worte[0][23],"würgende");
  strcpy(Worte[0][24],"fürchterliche");
  strcpy(Worte[0][25],"schnaufende");
  strcpy(Worte[0][26],"bösartige"); 
  strcpy(Worte[0][27],"kalte");
  strcpy(Worte[0][28],"riesige");
  strcpy(Worte[0][29],"dunkle");
  strcpy(Worte[0][30],"staubige");
  strcpy(Worte[0][31],"stumme"); 
  strcpy(Worte[0][32],"schwärmende");
  strcpy(Worte[0][33],"alte");
  strcpy(Worte[0][34],"harte");
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
  strcpy(Worte[0][46],"breite");
  
  strcpy(Worte[1][0],"Finsternis"); 
  strcpy(Worte[1][1],"Dunkelheit");
  strcpy(Worte[1][2],"Erscheinungen");
  strcpy(Worte[1][3],"Stille");
  strcpy(Worte[1][4],"Diele");
  strcpy(Worte[1][5],"Gestalt");
  strcpy(Worte[1][6],"Atmung");
  strcpy(Worte[1][7],"Schatten");
  strcpy(Worte[1][8],"Versuchung");
  strcpy(Worte[1][9],"Erfrischung");
  strcpy(Worte[1][10],"Angstzustände");
  strcpy(Worte[1][11],"Plasphemie");
  strcpy(Worte[1][12],"Monster");
  strcpy(Worte[1][13],"Dekadenz");
  strcpy(Worte[1][14],"Jugend");
  strcpy(Worte[1][15],"Fesseln");
  strcpy(Worte[1][16],"Vampire");
  
  strcpy(Worte[2][0],"in Räumen"); 
  strcpy(Worte[2][1],"in den Kellern");
  strcpy(Worte[2][2],"im Nirgendwo");
  strcpy(Worte[2][3],"in der Küche");
  strcpy(Worte[2][4],"im Flur");
  strcpy(Worte[2][4],"in der Ecke");
  strcpy(Worte[2][4],"am Anfang");
  strcpy(Worte[2][4],"in Gängen");
  
  for(i=0;i<50;i++) strcpy(Worte[3][i],Worte[0][i]);
  
  strcpy(Worte[4][0],"Haarausfall"); 
  strcpy(Worte[4][1],"Mut");
  strcpy(Worte[4][2],"Wahnsinn");
  strcpy(Worte[4][3],"Horizont");
  strcpy(Worte[4][4],"Ehrgeiz");
  strcpy(Worte[4][5],"Tag");
  strcpy(Worte[4][6],"Ausfall");
  
  strcpy(Worte[5][0],"vor dem Monster"); 
  strcpy(Worte[5][1],"am Ausgang");
  strcpy(Worte[5][2],"vor den Ferien");
  strcpy(Worte[5][3],"vor dem Nichts");
  strcpy(Worte[5][4],"vor dem Ende der Welt");
  strcpy(Worte[5][5],"in der Nacht");
  strcpy(Worte[5][6],"vor dem Angriff");
  
  for(i=0;i<50;i++) strcpy(Worte[6][i],Worte[0][i]);
  
  strcpy(Worte[7][0],"Fluchtversuche"); 
  strcpy(Worte[7][1],"Fälschungen");
  strcpy(Worte[7][2],"Zahlungsbefehle");
  strcpy(Worte[7][3],"Schritte");
  strcpy(Worte[7][4],"Zähne");
  strcpy(Worte[7][5],"Stunden");
  strcpy(Worte[7][6],"Ängste");
  
  strcpy(Worte[8][0],"Zugegeben"); 
  strcpy(Worte[8][1],"Schleierhaft");
  strcpy(Worte[8][2],"Hilfe");
  strcpy(Worte[8][3],"Schrecklich");
  strcpy(Worte[8][4],"Hässliche");
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
    
  strcpy(Worte[10][0],"verhinderst du"); 
  strcpy(Worte[10][1],"erträgst du");
  strcpy(Worte[10][2],"langweilt dich");
  strcpy(Worte[10][3],"arbeitest du");
  strcpy(Worte[10][4],"genießt du");
  strcpy(Worte[10][5],"vergessist du");
  strcpy(Worte[10][6],"zerstörst du");
  strcpy(Worte[10][7],"verdrängst du");
  strcpy(Worte[10][8],"erlaubst du");
  
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
  strcpy(Worte[13][1],"auf Anschlag");
  strcpy(Worte[13][2],"lediglich");
  strcpy(Worte[13][3],"höchstens");
  strcpy(Worte[13][4],"\b, wenn es dich nicht hört");
  
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
  
  strcpy(Worte[18][0],"Gebete"); 
  strcpy(Worte[18][1],"Fixe Ideen");
  strcpy(Worte[18][2],"Einflüsterungen");
  strcpy(Worte[18][3],"Hirngespinste");
  strcpy(Worte[18][4],"Gedanken im Unterbewusstsein");
  strcpy(Worte[18][5],"Waffe");
  strcpy(Worte[18][6],"Wände");
  
  strcpy(Worte[19][0],"Du bist"); 
  strcpy(Worte[19][1],"Dieses Biester ist");
  strcpy(Worte[19][2],"Deine Hände sind");
  strcpy(Worte[19][3],"Diese Bestie ist");
  strcpy(Worte[19][4],"Du bist");
  strcpy(Worte[19][5],"Monster sind");
  strcpy(Worte[19][6],"Die Fenster sind");
  
  strcpy(Worte[20][0],"nämlich"); 
  strcpy(Worte[20][1],"aber");
  strcpy(Worte[20][2],"wieder");
  strcpy(Worte[20][3],"ja");
  strcpy(Worte[20][4],"wie immer");
  
  for(i=0;i<50;i++) strcpy(Worte[21][i],Worte[0][i]);
  
  strcpy(Worte[22][0],"Letzten Endes"); 
  strcpy(Worte[22][1],"Im Treppenhaus");
  strcpy(Worte[22][2],"Im Hinterkopf");
  strcpy(Worte[22][3],"Auf dem Dachboden");
  strcpy(Worte[22][4],"Im Keller");
  
  strcpy(Worte[23][0],"Scheingefechte"); 
  strcpy(Worte[23][1],"Schreie");
  strcpy(Worte[23][2],"Kämpfe");
  strcpy(Worte[23][3],"Gedankenblitze");
  strcpy(Worte[23][4],"Hilfe suchen");
  strcpy(Worte[23][5],"Angstzustände");
  
  for(i=0;i<50;i++) strcpy(Worte[24][i],Worte[0][i]);
  
  strcpy(Worte[25][0],"Gegenstand");                  rel1[0]=1;
  strcpy(Worte[25][1],"Schnaufen");                   rel1[1]=3;
  strcpy(Worte[25][2],"Gebete");                      rel1[2]=2;
  strcpy(Worte[25][3],"östliche Wand");               rel1[3]=2;
  strcpy(Worte[25][4],"südliche Wand");               rel1[4]=3;
  
  strcpy(Worte[26][0],"versüßt dir nur das Elend"); 
  strcpy(Worte[26][1],"rächt sich");
  strcpy(Worte[26][2],"sagt mehr über dich als das Elend");
  strcpy(Worte[26][3],"verschlingt das Gesicht");
  strcpy(Worte[26][4],"begreift sich im Tiefgang");
  
  strcpy(Worte[27][0],"das Ende"); 
  strcpy(Worte[27][1],"der Regen");
  strcpy(Worte[27][2],"die Waage der Gerechtigkeit");
  strcpy(Worte[27][3],"der grausame Org");
  strcpy(Worte[27][4],"die Schneide deines Messers");
  
  strcpy(Worte[28][0],"Vorsichtshalber"); 
  strcpy(Worte[28][1],"Letzten Endes");
  strcpy(Worte[28][2],"Trotzdem");
  strcpy(Worte[28][3],"Zum Schluß");
  strcpy(Worte[28][4],"Zu Beginn");
  
  strcpy(Worte[29][0],"rennst"); 
  strcpy(Worte[29][1],"stirbst");
  strcpy(Worte[29][2],"riechst");
  strcpy(Worte[29][3],"kriechst");
  strcpy(Worte[29][4],"schleichst");
  
  strcpy(Worte[30][0],"ganz allein"); 
  strcpy(Worte[30][1],"doch");
  strcpy(Worte[30][2],"niemals");
  strcpy(Worte[30][3],"immerzu");
  strcpy(Worte[30][4],"besser");
  
  strcpy(Worte[31][0],"Überreste"); 
  strcpy(Worte[31][1],"Speisereste");
  strcpy(Worte[31][2],"Knochenbrüche");
  strcpy(Worte[31][3],"Schreie");
  strcpy(Worte[31][4],"Anschläge");
  strcpy(Worte[31][5],"Kontrollen");
  strcpy(Worte[31][6],"Zombies");
  strcpy(Worte[31][7],"Kontrollen");
  strcpy(Worte[31][8],"Exekutionen");
  
  strcpy(Worte[32][0],"Ratlosigkeit"); 
  strcpy(Worte[32][1],"Blindgänger");
  strcpy(Worte[32][2],"Tränengas");
  strcpy(Worte[32][3],"Angstzustand");
  strcpy(Worte[32][4],"Hoffnungslosigkeit");
  strcpy(Worte[32][5],"Wehrpflicht");
  strcpy(Worte[32][6],"Krankheit");
  strcpy(Worte[32][7],"Euthanasie");
    
  for(i=0;i<50;i++) strcpy(Worte[33][i],Worte[0][i]);
  
  strcpy(Worte[34][0],"Ketten"); 
  strcpy(Worte[34][1],"Nebel");
  strcpy(Worte[34][2],"Wolkendecken");
  strcpy(Worte[34][3],"Türen");
  strcpy(Worte[34][4],"Versuche");
  strcpy(Worte[34][5],"Fenster");
  strcpy(Worte[34][5],"Wände");
  
  strcpy(Worte[35][0],"Letzten Endes"); 
  strcpy(Worte[35][1],"Selbstverständlich");
  strcpy(Worte[35][2],"Am Ende");
  strcpy(Worte[35][3],"Hoffentlich");
  strcpy(Worte[35][4],"Im Grunde");
  
  strcpy(Worte[36][0],"geht alles so weiter"); 
  strcpy(Worte[36][1],"bist du dagegen");
  strcpy(Worte[36][2],"wird alles gut");
  strcpy(Worte[36][3],"fliehst du schnell");
  strcpy(Worte[36][4],"grenzt du dich ab");
  strcpy(Worte[36][5],"begreifst du nie");
  
  char rel[4][5];
  strcpy(rel[1],"Der");
  strcpy(rel[2],"Die");
  strcpy(rel[3],"Das");
  
  int Zufall[100];
  
  int o=0;
  char Zwischen[900];
  int Anzahl[100];
  
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
          printf("So wie %s. %s %s du %s.\n",Worte[27][Zufall[27]],Worte[28][Zufall[28]],Worte[29][Zufall[29]],Worte[30][Zufall[30]]);
          printf("%s. %s. %s %s.\n",Worte[31][Zufall[31]],Worte[32][Zufall[32]],Zwischen,Worte[34][Zufall[34]]);
          printf("%s %s.\n\n",Worte[35][Zufall[35]],Worte[36][Zufall[36]]);
          
          printf("\n");
          getchar();
          getchar();
          iFragen();	
 }
  return 0;
}

/** Funktion : Tipps zufällig auslesen
  * Status   : in Arbeit
  */
  int iFragen()
  {
	  system("clear");
	  int iEingabe = 0;
      printf("""Du stehts nun in einem dunklen Raum.\nDu kannst nichts sehen, aber die Luft ist sehr warm und feucht,\nund du hörst ein rhythmisches tiefdröhnendes Schnaufen \nund dir stehen die Nackenhaare zu Berge.\nWas willst du tun?""\n");
      printf("\n1. Zurück gehen"); 
      printf("\n2. Direkt auf das Schnaufen zu"); 
      printf("\n3. An der östlichen Wand entlangschleichen"); 
      printf("\n4. An der südlichen Wand entlang schleichen");
      printf("\n5. Etwas in den Raum rufen wie ""Hallo""");
      printf("\n6. Auf den Boden hocken und warten");
      printf("\n7. Einen Gegenstand aus dem Rucksack benutzen"); 
      printf("\n8. Beten\n\n");
      printf("Eingabe: ");
	  scanf("%i", &iEingabe);
	  switch( iEingabe )
	  {
		  case 1:
		  case 2:
		  case 3:
		  case 4:
		  case 5:
		  case 6:
		  case 7:
		  case 8:
		  {
			  iAntworten();
			  break;
		  }
		  default:
		  {
			  iFragen();
			  break;
		  }
	  }
	  return 0;
  }

/** Steuerprogramm                                                          
  */
  int iController()
  {
      iFragen();
	  return 0; /* Sprung-Anweisung */
  }

/** Hauptprogramm
  */
  int main()
  {
	  iController();
	  return 0;
  }

/** Programmende
  */


