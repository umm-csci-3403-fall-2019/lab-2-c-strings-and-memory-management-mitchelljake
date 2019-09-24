#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char *argv[]) {
  char *line;
  size_t size;
  char* str;
  size = 100;
  line = (char*) malloc (size + 1);


  while (getline(&line, &size, stdin) > 0) {
    str = disemvowel(line);
    printf("%s\n", str);
    free(str);
  }
  free(line);
}
