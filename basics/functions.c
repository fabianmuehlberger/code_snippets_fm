#include <stdio.h>
#include <cs50.h>


//prototype of function
//specified the returntype, name and the parameter of the funktions
int add(int a, int b);

int main(void)
{
    //declaration of same type of variables in one line
    int x = 1 , y = 2;

    //call function, passes the two variables as arguments for the funktion
    //stores the returned value in z
    int z = add(x, y);

    //prints the new value
    printf("%i \n", z);
}

//Function body
//has the same returntype name and parameters as the prototype funktion.
int add(int a, int b)
{
    //adds the values of a and b
    int c = a + b;

    //return the value of c to the main funktion
    return c;

}

