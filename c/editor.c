#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int main() {
unsigned char*cptr;
unsigned int count = 0;
unsigned char*tptr;
unsigned int size = 2;
unsigned int startpt = 1;
FILE*fptr;


clrscr();
fflush(stdin);
cptr = (char*)calloc(sizeof(char),10);


if((fptr = fopen("c:\\Shekhar\\C\\myTextInEditor.txt","w")) ==
NULL) {
printf("File Cannot be created!!\n");
exit(EXIT_FAILURE);
}


while((*cptr = getchar()) != '\n') {


fprintf(fptr,"%c",*(cptr));
cptr++;
if(++count < 10);
else {

if((tptr =(char*)calloc(size*10,sizeof(char)))
== NULL) {
printf("Program Terminating!!");
exit(EXIT_FAILURE);
}


memcpy(tptr,cptr,startpt*10);
free(cptr);
cptr = tptr;
cptr = cptr + count*startpt;
count = 0;
size++;startpt++;
}
}

free(tptr);
fclose(fptr);
getch();
return(0);



}

