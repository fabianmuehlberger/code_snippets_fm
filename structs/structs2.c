#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100
#define TRUE 1
#define FALSE 0
#define VariableName(name)  #name

//defining the first structure Birthdate
struct Birthdate
{
    int year;
    int month;
    int day;
};

//defining the second structure Member
struct Member
{
    //define of two string variables
    char firstName[LEN];
    char lastName[LEN];

    //the struct Birthdate is used inside the Member structure and is given the variable name date
    struct Birthdate date;
};



//prototype of functions

//prints useroptions
void help();

//creates a new member
//gets userinput with fgets to ensure corret input via command prompt
struct Member newMember(struct Member tempMem);

//choose the array position for input or output of an struct
int chooseArrayPos();

void printMember(struct Member member);

//get a string input from the user
char inputString(char *name);

//get a int input from the user
int inputInt(int *value);

int main(void)
{
    //creating running variable to control programm loop
    int running = TRUE;

    char userInput = {0};
    int arrayPos = 0;

    //creating a array with type struct Member
    struct Member memberList[10];



    while (running)
    {
        help();
        scanf(" %c", &userInput);

        switch(userInput)
        {
            //make or change a entry
            case 'n':
            arrayPos = chooseArrayPos();
//            memberList[arrayPos] = newMember(memberList[1]);
            memberList[arrayPos] = newMember(memberList[arrayPos]);
            break;

            //show a entry
            case 'p':
            arrayPos = chooseArrayPos();
            printMember(memberList[arrayPos]);
            break;

            //show help
            case 'h':
            help();
            break;

            //close the Programm
            case 'x':
            running = FALSE;
            break;
        }
    }
}

void help()
{
    printf("************************\n");
    printf("n: for new Member \n");
    printf("p: to show Member \n");
    printf("h: to show help \n");
    printf("x: to close porgramm \n");
    printf("************************\n");
}

int chooseArrayPos()
{
    int tmp;
    do
    {
        printf("enter an array positon\n");
        scanf("%i", &tmp);
        getchar();

    }
    while(/*tmp < 0 && */tmp > 10);

    return tmp;
}


void printMember(struct Member member)
{
    printf("%s \n", member.firstName);
    printf("%s \n", member.lastName);
    printf("%i.", member.date.year);
    printf("%i.", member.date.month);
    printf("%i\n", member.date.day);
}

struct Member newMember(struct Member tempMem)
{
    char tempString[LEN] = {0};
    int tempInt = 0;

    printf("Please enter the first name: \n");
    inputString(tempString);
    strcpy(tempMem.firstName, tempString);

    printf("Please enter the year of birth: \n");
    inputInt(&tempInt);
    tempMem.date.year = tempInt;

    printf("Please enter the month of birth: \n");
    inputInt(&tempInt);
    tempMem.date.month = tempInt;

    printf("Please enter the day of birth: \n");
    inputInt(&tempInt);
    tempMem.date.day = tempInt;

    return tempMem;
}

char inputString(char *name)
{
    char buffer[LEN];
    do
    {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            size_t len = strlen(buffer);
            if ((len > 0 && buffer[len-1] == '\n') || buffer[len-1 == '\r'])
            {
                buffer[--len] = '\0';
                sscanf(buffer, "%s", name);
            }
        }
    }
    while(strlen(name) < 1);

    return *name;
}

int inputInt(int *value)
{
        char buffer[LEN];

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

