
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

int main(void) {
   char ziel_str[LEN];
   char str1[] = "Das ist ";
   char str2[] = "ein ";
   char str3[] = "Teststring";

   strcpy(ziel_str, str1);
   /* Ein umständliches Negativbeispiel */
   strcpy(&ziel_str[8], str2);
   /* So ist es einfacher und sicherer */
   strcat(ziel_str, str3);
   printf("%s\n",ziel_str);
   return 0;
}
