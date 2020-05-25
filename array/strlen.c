#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

int main(void)
{
    int stringLength = 0;
    char name[LEN] = "fabian";
    stringLength = strlen(name);
    printf("the name is: %s\n", name);
    printf("the length of name is: %i\n", stringLength);

    return 0;
}