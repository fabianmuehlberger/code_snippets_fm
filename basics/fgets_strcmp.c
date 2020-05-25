#include <stdio.h>
#include <string.h>

int main(void)
{
    char userInput[64];

    printf("enter something: ");

    //fgets is used to get a userinput that is max 64 chars long
    while(fgets(userInput, 64, stdin))
    {
        printf("you entered: %s \n", userInput);

        //strncmp is used to break out of the while loop when the user inputs "quit"
        if(strncmp(userInput, "quit", 4) == 0)
        {
            printf("Breaking... \n");
            break;
        }
    }
}