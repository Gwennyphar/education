#include <stdio.h>
#include <stdlib.h>
int main()
{

  FILE *handle = fopen("system.c", "rt");
  char *buffer, *linestart, *lineend;
  long size;

  if(!handle)
    return 0;

  fseek(handle, 0, SEEK_END);
  size = ftell(handle);
  fseek(handle, 0, SEEK_SET);

  buffer = (char *) malloc(size + 1);
  buffer[size] = 0;

  if(fread(buffer, 1, size, handle) < size)
  {
    free(buffer);
    fclose(handle);
    return 0;
  }

  fclose(handle);

  linestart = buffer;
  lineend = strchr(buffer, '\n');

  while(lineend)
  {
    *lineend = 0;

    processLine(linestart);
    linestart = lineend + 1;
    lineend = strchr(linestart, '\n');
  }

  if(*linestart)
    processLine(linestart);

  free(buffer);
  return 1;
}
