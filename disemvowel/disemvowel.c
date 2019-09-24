#include <stdlib.h>
#include <string.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
   char* newName;
   int len;
   int nameCount;
   int i;
   nameCount = 0;
   len = strlen(str);
   newName = (char*) calloc(len+1, sizeof(char));


   for (i=0; i<len; ++i) {
      if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
      {
      //do nothing
      }
      //add consonants to new char* newName
      else{
      newName[nameCount] = str[i];
      nameCount++;
      }
   }

   newName[len] = '\0';

  return (char*) newName;
}
