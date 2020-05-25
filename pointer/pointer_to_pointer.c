#include <stdio.h>
#include <stdlib.h>

//prints the value of a pointer
void printNum(int p1, int p2);

//swaps the addresses of two pointers
void swapPointers(int **a, int **b);

int main(void)
{
    int num1 = 10;
    int *pNum1 = &num1;

    //calls funktion and hands over the adress of a pointer

    int num2 = 5;
    int *pNum2 = &num2;

    printf("num 1 and num 2 before swapping pointers:\n");
    //printNum(num1, num2);

    printf("pNum1 = %i, pAdress = %i\n", num1, &num1);
    printf("pNum2 = %i, pAdress = %i\n", num2, &num2);

    // calls funnction and hand over the adresses of 2 pointers
    swapPointers(&pNum1, &pNum2);

    printf("pNum1 = %i, pAdress = %i\n", num1, &num1);
    printf("pNum2 = %i, pAdress = %i\n", num2, &num2);

    printf("\nnum 1 and num 2 after swapping pointers\n");
    //printNum(num1, num2);

    return 0;
}

void printNum(int p1, int p2)
{
    printf("pNum1 = %i, pAdress = %i\n", &p1, p1);
    printf("pNum2 = %i, pAdress = %i\n", &p2, p2);
}

void swapPointers(int **a, int **b)
{
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}