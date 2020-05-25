#include <stdio.h>

//define Constants
#define LEN 20

//definition of structures it can hold various types of variables
//the first letter is written in Caps for better recognition
struct Books
{
  //declaration of the struct variables
  int pages;
  char name[LEN];
  char author[LEN];
  int year;
};

int main(void)
{
    //creating a new variable "Book" structure and giving it values directly
    //struct Books is the variable type
    //book1 is the variable name.
    struct Books book1 = {10, "Steine", "Fabian", 2019};

    //printing the values of the structur
    //to acess the structure the "." operator is needet between the struct variable name and the inner variables
    printf("%i\n", book1.pages);
    printf("%s\n", book1.name);
    printf("%s\n", book1.author);
    printf("%i\n", book1.year);
}