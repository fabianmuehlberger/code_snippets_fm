
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int main(void) {
   char str1[LEN];
   char str2[] = "Ein Teststring, der laenger" " als 20 Zeichen ist";

   /* LEN-Zeichen in str1 kopieren */
   strncpy(str1, str2, LEN-1);


   //Wichtig, String am Ende terminieren 
   str1[LEN-1] = '\0';
   printf("%s\n",str1);
   return 0;
}