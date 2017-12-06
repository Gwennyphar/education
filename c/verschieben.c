#include <stdio.h>
#include <stdlib.h>

char decToEnc[256], encToDec[256]; 
int encodeString(char *str)
{
	int i;
	for(i=0; i<strlen(str); i++)
	{
		printf("%c", decToEnc[str[i]]);
	}
	return EXIT_SUCCESS;
}

int decodeString(char *str)
{
	int i;
	for(i=0; i<strlen(str); i++)
	{
		printf("%c", encToDec[str[i]]);
	}
	return EXIT_SUCCESS;   
}

int main()
{
	char *str1="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *str2="EPSTIWKNUVGCLRYBWHMDOFXQAGeptswxnkvucgrlbyhwdmfoqagi";
	unsigned char i;
	/* Arrays vorinitialisieren */
	for(i=0; i<255; i++)
	{
		decToEnc[i]=encToDec[i]=i;
	}
	/* Uebersetzungstabellen erstellen */
	for(i=0; i<strlen(str1); i++)
	{
		decToEnc[str1[i]]=str2[i];
		encToDec[str2[i]]=str1[i];  
	}
	encodeString("HeLLO WORLD\n");
	decodeString("NICCY XYHCT\n");
	return EXIT_SUCCESS;
} 
