//INCLUDES
#include <stdio.h>
#include <stdlib.h>

//DECLARATIONS

//FUNCTION PROTOTYPES


int main(void)
{
    FILE *fPointer = fopen("data.txt", "w+");
    fputc("this is a test", fPointer);
    if (fPointer == NULL)
    {
        return 1;
    }
    
    fseek(fPointer, 10, SEEK_SET);
    fputs("error", fPointer);

    fseek(fPointer, );

    fclose(fPointer);
    return 0;
}


