#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //declaring an a array with 10 storing spaces
    //initialising the new array with 0
    int array[10] = {0};

    //prints the first index of the array
    printf("index 1 of the array is %i", array[0]);

    //sets the first index of the array to 10
    array[0] = 10;

    //prints the first index of the array
    printf("index 1 of the array is %i", array[0]);

    //prints the whole array
    for(int i = 0; i < 10; i++)
    {
        //uses the variable i to acess the index of the array
        printf("index [%i] of arrry is %i\n", i, array[i]);
    }
}