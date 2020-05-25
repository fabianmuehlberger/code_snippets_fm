#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

char inputString (char *name);
int inputInt(int *value);
char *dynamicCharString();

int main (void)
{
    char name[LEN];
    int value = 0;

    inputString(name);
    inputInt(&value);

    char *anotherName;
    anotherName = dynamicCharString();

    printf("%s \n", name);
    printf("%i \n", value);

    free(anotherName);
}


char inputString(char *name)
{
        char buffer[LEN];

        printf("enter name:");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            size_t len = strlen(buffer);
            if ((len > 0 && buffer[len-1] == '\n') || buffer[len-1 == '\r'])
            {
                buffer[--len] = '\0';
                sscanf(buffer, "%s", name);
            }
        }
        return *name;
}

int inputInt(int *value)
{
        char buffer[LEN];

        printf("enter value:");

        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            size_t len = strlen(buffer);
            if ((len > 0 && buffer[len-1] == '\n') || buffer[len-1 == '\r'])
            {
                buffer[--len] = '\0';
                sscanf(buffer, "%i", value);
            }
        }
        return *value;
}

char *dynamicCharString()
{
char *str, c;
int i;
str = (char*)malloc(1*sizeof(char));

while(c = getc(stdin),c!='\n')
{
    str[i] = c;
    i++;
    realloc(str,i*sizeof(char));
}
str[i] = '\0';
return str;
}

