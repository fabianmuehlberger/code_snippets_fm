#include <stdio.h>

int main(void)
{
    //declaration of a variable x
    int x = 1;

    //prints the value of x
    printf("value of x =   %i \n", x);
    //prints the adress of x.
    printf("adress of x =  %p \n", &x);

    //the "%p" tells the printf that we are awaiting a adress.
    //the "&" operator tell printf to print the adress and not the variable

    //declaration of a pointer.
    //it is needet to point it somewhere, therefor it is pointet at NULL to prevent bad behavor;
    int *pX = NULL;

    //the pointer is pointing to the adress of "x"
    // the "&" operator is needet to and store the adress of x and not the value
    pX = &x;

    //prints the value and adress of the pointer pX.
    //notice the different dereference to the previous printf lines above
    //the adresses of pX and x are the same.
    printf("value of pX  = %i \n", *pX);
    printf("Adress of pX = %p \n", pX);

}