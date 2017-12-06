#include <stdio.h>
#include <string.h>




int main(){


	int i = 0;
	int laenge = 0;
	char string [255];
	char encode [255];
	char decode [255];

	printf("\n\tInput....: ");
	fgets(string, sizeof(string), stdin);
	fflush(stdin);


	//Länge des Strings ermitteln!
	
	laenge = strlen(string);
	
	//Verschlüsseln des Strings
		
	for (i=0; i<laenge; i++){
		if(string[i]=='z' || string[i]=='Z'){
			string[i] = 'A';
			string[i] = string[i]-1;
		}
		decode[i] = string [i] + 4;
		encode[i] = decode [i] - 4;
	}
	
	//Ausgabe des verschlüsselten Strings

	printf("\tEncrypted: %s\n" , decode);
	printf("\tDecrypted: %s\n" , encode);
	fgetc(stdin);
	return 0;
}
