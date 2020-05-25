#include <stdio.h>
//#include <cs50.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

int main(void)
{
    // get a int from the user
    int number = 0;
    char string1[LEN];
    char string2[LEN];

    printf("enter a number: ");
    do
    {
        scanf("%i", &number);
    }while(getchar() != '\n');

/*
    printf("enter a string: ");
    do
    {
        fgets(string1, LEN, stdin);

    }while(getchar() != '\n');
*/
    printf("enter a string: ");
    fgets(string2, LEN, stdin);

    printf("you entered:\n");
    printf("the number you entered is: %i\n", number);
    printf("the string you entered is: %s\n", string1);
    printf("the string you entered is: %s\n", string2);
}