#include <stdio.h>

//prototype of the function
void swap(int *a, int *b);

int main(void)
{
    //declaration and initialisation of the variables
    int x = 10;
    int y = 5;

    //show the initial values of x and y
    printf("value of x = %i \n", x);
    printf("value of y = %i \n", y);

    //calling the funktion and handing over the adresses of x and y
    //the "&" operator is importend in the argument with normal variables
    swap(&x, &y);

    //print the new values of x and y
    printf("values of x and y after change:\n");
    printf("value of x = %i \n", x);
    printf("value of y = %i \n", y);
}

//function to swap the values of x and y.
//a and b are declared as pointer in the parameter of the swap funktion to accept the adress given by the main function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}