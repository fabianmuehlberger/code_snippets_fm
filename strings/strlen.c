
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
   char string[] = "Das ist ein String";
   size_t laenge;

   laenge = strlen(string);
   printf("Der String \"%s\" hat %d Zeichen\n",string, laenge);
   return 0;
}
