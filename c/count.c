#include<stdio.h>
#include<string.h>

int countToken(char *string, char token) {
	int i, c=0, len = strlen(string);
	for(i=0; i<len; i++) {
		if(string[i]==token) {
		c++;
		}
	}
	return c;
}


int main() {
	// Test
	char string[20] = { "111;222;333;444" };
	printf("%d\n", countToken(string, ';'));
	system("pause");
	return 0;
}
