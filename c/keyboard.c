  #include <stdio.h>
  #include <stdlib.h>
  #include <windows.h>
  #include <conio.h>

  void csr( unsigned int y, unsigned int x )
  {
      COORD Position;
      Position.X = x;
      Position.Y = y;
      SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), Position );
  }
  
  int iScreen()
  {
	  char sDisp[FILENAME_MAX];
	  int i = 0;
	  FILE *Fp;
      Fp = fopen("screen.txt", "r");
      fgets(sDisp, FILENAME_MAX, Fp);
	  do
	  {
		  printf("%s", sDisp);
		  fgets(sDisp, FILENAME_MAX, Fp);
	  }while(!feof(Fp));
	  fclose(Fp);
      csr(22,66);
      printf("Nico Anders");
      Beep(196,111);
      Beep(233,111);
      Beep(293,111);
      Beep(311,111);
      Beep(196,111);
      Beep(233,111);
      Beep(293,111);
      Beep(311,111);
      Beep(196,111);
      Beep(233,111);
      Beep(293,111);
      Beep(311,111);
      Beep(196,111);
      Beep(233,111);
      Beep(293,111);
      Beep(311,111);
      Beep(185,111);
      Beep(220,111);
      Beep(293,111);
      Beep(311,111);
      Beep(185,111);
      Beep(220,111);
      Beep(261,111);
      Beep(293,111);
      Beep(130,111);
      Beep(185,111);
      Beep(220,111);
      Beep(261,111);
      Beep(185,111);
      Beep(220,111);
      Beep(261,111);
      Beep(311,111);
      Beep(220,111);
      Beep(261,111);
      Beep(311,111);
      Beep(261,111);
      Beep(311,111);
      Beep(369,111);
      Beep(311,111);
      Beep(369,111);
      Beep(440,111);
      Beep(369,111);
      Beep(440,111);
      Beep(523,111);
      return 0;
  }
  
  int iKey()
  {
    char cEingabe;
    int iCount = 0;
    iScreen();
    csr(0,16);
    printf("%i", iCount);
    csr(11,6);                     
    while (1)
    {
          cEingabe=getch();
          switch(cEingabe)
          {
              case 'q':
              {
                  csr(11,6);
                  beep(264,200); /*c*/
                  iCount++;
                  csr(0,16);
                  printf("%i", iCount);
                  csr(11,6);
                  break;
              }
              case '1': 
              {
                  csr(8,8);
                  beep(275,200); /*cis, des*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(8,8);
                  break;
              }
              case 'w':
              {
                  csr(11,10);
                  beep(297,200); /*d*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(11,10);
                  break;
              }
              case '2': 
              {
                  csr(8,12);
				  beep(317,200); /*dis, es*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(8,12);
                  break;
              }
              case 'e':
              { 
                  csr(11,14);
                  beep(330,200); /*e*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(11,14);
                  break;
              }
              case 'r':
              {
                  csr(11,18);
                  beep(352,200); /*f*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(11,18);
                  break;
              }
              case '3': 
              {
                   csr(8,20);
                   beep(367,200); /*fis, gis*/
                   iCount++;                          
                   csr(0,16);
                   printf("%i", iCount);
                   csr(8,20);
                   break;
              }
              case 't':
              {
                  csr(11,22);
                  beep(396,200); /*g*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(11,22);
                  break;
              }
              case '4':
              {
                  csr(8,24);
                  beep(422,200); /*gis, as*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(8,24);
                  break;
              }
              case 'z': 
              {
                  csr(11,26);
                  beep(440,200); /*a*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(11,26);
                  break;
              }
              case '5':
              { 
                  csr(8,28);
                  beep(457,200); /*ais, b*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(8,28);
                  break;
              }
              case 'u': 
              {
                  csr(11,30);
                  beep(495,200); /*h*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(11,30);
                  break;
              }
              case 'i': 
              {
                  csr(11,34);
                  beep(528,200); /*c*/
                  iCount++;                          
                  csr(0,16);
                  printf("%i", iCount);
                  csr(11,34);
                  break;
              }
              case '0':
              {
				  Beep(196,111);
                  Beep(233,111);
                  Beep(293,111);
                  Beep(311,111);
                  Beep(196,111);
                  Beep(233,111);
                  Beep(293,111);
                  Beep(311,111);
                  Beep(196,111);
                  Beep(233,111);
                  Beep(293,111);
                  Beep(311,111);
                  Beep(196,111);
                  Beep(233,111);
                  Beep(293,111);
                  Beep(311,111);
                  Beep(185,111);
                  Beep(220,111);
                  Beep(293,111);
                  Beep(311,111);
                  Beep(185,111);
                  Beep(220,111);
                  Beep(261,111);
                  Beep(293,111);
                  Beep(130,111);
                  Beep(185,111);
                  Beep(220,111);
                  Beep(261,111);
                  Beep(185,111);
                  Beep(220,111);
                  Beep(261,111);
                  Beep(311,111);
                  Beep(220,111);
                  Beep(261,111);
                  Beep(311,111);
                  Beep(261,111);
                  Beep(311,111);
                  Beep(369,111);
                  Beep(311,111);
                  Beep(369,111);
                  Beep(440,111);
                  Beep(369,111);
                  Beep(440,111);
                  Beep(523,111);
              }
              case 'x':
              {
                   break;
              }
          }
    }
    system("PAUSE");
    return 0;
}


  int iController()
  {
      iKey();
      return 0;
  }
  int main()
  {
      iController();
      return 0;
  } 
