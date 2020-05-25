#include <stdio.h>
#include <stdlib.h>

#define FILENAME_BUFFER_SIZE 128

//Zeichenweises lesen mit fgetc bis EOF erreicht ist, zeichenweise ausgabe auf stdout mithilfe von putchar
void Test_1();

//einlesen von einzelnen int`s mithilfe von scanf(nicht sicher)
//schreiben in die Datei mithilfe von fprintf
void Test_2();

//Zeichenweises lesen einer Datei mithilfe von fgetc, zeichenweises schreiben in eine andere Datei mithilfe von fputc 
void Test_3();

//formatiertes einlesen mit fscanf (wichtig sind die trennzeichen, in diesem Fall ";")
//Zeichenweises ausgeben der eingelesen daten mit fprintf auf stdout
void Test_4();

//noch nicht erledigt
void Test_5();

int main()
{
    /* Input */
    int num;

    /* List of all available tests */
    void (*tests[])() =
        {
            Test_1,
            Test_2,
            Test_3,
            Test_4,
            Test_5,
        };
    int num_of_tests = (int)(sizeof(tests) / sizeof(void (*)()));

    /* Read test number */
    printf("Test #: ");
    scanf("%d", &num);

    /* Check valid range */
    if (num >= 1 && num <= num_of_tests)
    {
        /* Call the selected test */
        tests[num - 1]();
    }
    else
    {
        /* Print error */
        printf("Invalid test number!");
    }

    return 0;
}

void Test_1()
{
    int c;
    FILE *datei;

    datei = fopen("data\\test1.txt", "r");
    if (datei != NULL)
    {
        while ((c = fgetc(datei)) != EOF)
            putchar(c);
    }
    else
    {
        printf("ERROR\n");
        exit(-1);
    }
    fclose(datei);
}

void Test_2()
{
    int num = 1;
    FILE *datei2 = fopen("data\\test4.txt", "a");
    if (datei2 != NULL)
    {
        while (num != 0)
        {
            scanf("%i", &num);
            fprintf(datei2, "%i\n", num);
        }
    }
    else
    {
        printf("ERROR");
        exit(-1);
    }
    fclose(datei2);
}

void Test_3()
{
    char c;
    FILE *pSource, *pDestination;

    pSource = fopen("data\\test6.txt", "r");
    pDestination = fopen("data\\test_out_6", "w");
    if (pSource != NULL)
    {
        while ((c = fgetc(pSource)) != EOF)
            fputc(c, pDestination);
    }
    else
    {
        printf("ERROR\n");
        exit(-1);
    }
    fclose(pSource);
    fclose(pDestination);
}

void Test_4()
{
    FILE *pFile = fopen("data\\test9.txt", "r");
    int timestamp, x, y, z;
    if (pFile != NULL)
    {   
        while ((fscanf(pFile, "%d;%d;%d;%d\n", &timestamp, &x, &y, &z)) != EOF)
        {
            fprintf(stdout, "timestamp = %d, X = %d, Y = %d, Z = %d\n", timestamp, x, y, z);
        }
    }
    else
    {
        printf("ERROR");
        exit(-1);
    }
    
}

void Test_5()
{
    int date, numTests, succeeded, failed, credits;
    FILE *pFile = fopen("data\\test13", "w");

    if (pFile != NULL)
    {
        /* code */
    }
    

}
