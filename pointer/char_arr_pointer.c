#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //declaring an array of chars as a pointer and giving it a value.
    char *array = "Fabian";

    //printing the whole array
    printf("Your name is: %s\n", array);

    //prints the first char of the array
    //"*" is dereferencing the pointer and gives back the value of the pointer
    printf("the first letter of your name is: %c\n", *array);

    //the pointer is incremented to print the second char of the array
    printf("the second letter of your name is: %c\n", *(array +1));

}