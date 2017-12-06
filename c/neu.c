#include <stdio.h>
 
int main()
{
	int i=0;
	char alpha[2][26]={{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'},{'a','b','c','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}};
	for(i=0;i<52;i++)
	{
		printf("%c",alpha[0][i]);
	}
	return 0;
}
