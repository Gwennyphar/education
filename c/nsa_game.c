#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __linux__
       #define clr(); system("clear");
#else
     #define clr(); system("cls");
#endif

int main(){


	int i = 0;
	int count = 0;
	int true = 0;
	int laenge = 0;
	int shift = 0;
	char string [13] = {"FuckTheNSA\r"};
	char input[11];
	char encode [11];
	char decode [11];

	do
	{
		//Länge des Strings ermitteln!
		laenge = strlen(string);

		//Verschlüsseln des Strings
		for (i = 0; i < laenge; i++)
		{
			if(string[i]=='z' || string[i]=='Z'){
				string[i] = 'A';
				string[i] = string[i]-1;
			}
			decode[i] = string [i] + 4;
		}
		clr();
		//Ausgabe des verschlüsselten Strings
		printf("\n\t\t\t\t\t\tattempt: %i\n\n\tEncrypted string....: %s", count, decode);

		printf("\n\tEnter encryption key: ");
		fgets(input, sizeof(input), stdin);
		fflush(stdin);
		sscanf(input, "%i", &shift);
		
		//Verschlüsseln des Strings
		for (i = 0; i < laenge; i++)
		{
			if(string[i]=='z' || string[i]=='Z'){
				string[i] = 'A';
				string[i] = string[i]-1;
			}
			decode[i] = string [i] + 4;
			encode[i] = decode [i] - shift;
		}
		
		//Ausgabe des entschlüsselten Strings
		if( strcmp(string, encode ) == 0 )
		{
			printf("\tcorrect string......: %s\n" , encode);
			true = 1;
		} else {
			printf("\tbad string..........: %s\n" , encode);
			count++;
		}
		fgetc(stdin);
	}while(true != 1 && count != 4);
	return 0;
}
