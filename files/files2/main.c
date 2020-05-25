//INCLUDES
#include <stdio.h>
#include <stdlib.h>

//DECLARATIONS
#define LEN 256

//FUNCTION PROTOTYPES
void readLine(char *string);
void printToFile(char *string);
void readLineWithChar(char *string);

int main()
{
    char string[LEN];

    readLine(string);
    printToFile(string);

    return 0;
}

void readLine(char *string)
{
    printf("gib etwas ein !!!!!: ");
    fgets(string, LEN, stdin);
}

void printToFile(char *string)
{
    FILE *pFile = fopen("text.txt", "a");
    if (pFile == NULL)
    {
        printf("error");
        exit(-1);
    }
    fputs(string, pFile);
    fclose(pFile);
}

void readLineWithChar(char *string)
{
    char *buffer = malloc(1 * sizeof(char));
    char c;
    while ((c = fgetc(stdin)) != '\n')
    {
        buffer = realloc(buffer, 1 * sizeof(char));
        buffer = c;
    }
    
}