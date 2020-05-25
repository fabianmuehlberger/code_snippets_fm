#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    //create 3 char arrays 
    char string1[] = "hallo";
    char string2[] = "hallo";
    char string3[] = "a";
    char string4[] = "b";


    //compare string 1 with string 2: 
    //if the are equal strcmp() returns 0, therefore the statement is true
    if(strcmp(string1, string2) == 0)
    {
        printf("strings are equal\n");
    }

    //compare string 1 with string 3 
    //if the the ASCII value of the first unmatched character is less than second.
    if(strcmp(string3, string4) < 0)
    {
        printf("strings are different\n");
    }

    //compare string 1 with string 3 
    //if the ASCII value of the first unmatched character is greater than second.
    if(strcmp(string4, string3) > 0)
    {
        printf("strings are different\n");
    }
}