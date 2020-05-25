
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringCompare(char s1[], char s2[]) {
   int ret = strcmp (s1, s2);
   if(ret == 0)
      printf("%s == %s\n", s1, s2);
   else
      printf("%s %c %s\n",s1,( (ret < 0) ?'<' :'>'), s2);
}

int main(void) {
   char str1[] = "aaa";
   char str2[] = "aab";
   char str3[] = "abb";

   stringCompare(str1, str2);
   stringCompare(str1, str3);
   stringCompare(str3, str2);
   stringCompare(str1, str1);
   return 0;
}
