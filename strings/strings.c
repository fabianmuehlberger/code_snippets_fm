#include <stdio.h>
#include <string.h>

int main(void)
{
    char name1[100] = {"fabian"};
    char name2[100] = {"hans"};
    char name3[100] = {""};

    printf("%s \n", name1);
    printf("%s \n", name2);
    printf("%s \n", name3);

    if(strcmp(name1, name2) == 0)
    {
        printf("name1 and name2 are the same\n");
    }
    else
    {
        printf("name1 nad name2 are different\n");
    }
}