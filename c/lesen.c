#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	FILE *proc;
	char buf[256];
	if ((proc = popen("/bin/ls", "r")) == NULL)
	{
		fprintf(stderr, "Fehler\n");
		while ( !feof(proc) );
    }
    fgets(buf, 255, proc);
    printf("ls output: %s", buf);
    pclose(proc);
    return 0;
}
