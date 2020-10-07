//Include standard librarys
#include <stdio.h>
#include <cs50.h>

/*
    TYPENUMWANDLUNG
%d	vorzeichenbehafteter Integer als Dezimalwert
%i	vorzeichenbehafteter Integer als Dezimal-,Hexadezimal oder Oktalwert
%e, %f, %g	Fließkommazahl
%o	int als Oktalzahl einlesen
%s	Zeichenkette einlesen
%x	Hexadezimalwert
%%	erkennt das Prozentzeichen
*/


int main(void)
{
    //declaration and initialisation of the varible x
    int x = 0;

    //asks the user for an input
    printf("Enter a Number: ");

    //gets the userinput from the console
    scanf("%i", &x);

    //prints the new value of x
    printf("x = %i", x);
}
