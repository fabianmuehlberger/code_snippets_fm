#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

#define LEN 20

struct Geburtstag
{
    int tag;
    int monat;
    int jahr;
};

struct Person
{
    char vname[LEN];
    char nname[LEN];
    struct Geburtstag date;
};

void help();

void eingabe(int nr, struct Person neu[]);

void ausgabe(int nr, struct Person person[]);

void alleAusgeben(int nr, struct Person all[]);

int main (void)
{
    static int x;
    int y;
    int running = 1;
    int auswahl = 5;

    struct Person personen[100];

    do
    {
        help();
        do
        {
            scanf("%d",&auswahl);
        }while(getchar() != '\n');

        switch(auswahl)
        {
            case 1:
                eingabe(x++, personen);
                break;
            case 2:
                printf("gib die array position ein die du anzeigen willst: ");
                do
                {
                    scanf("%d", &y);
                }while(getchar() != '\n');
                ausgabe(y, personen);
                break;
            case 3:
                alleAusgeben(x, personen);
                break;
            case 4:
                running = 0;
                break;
            case 5:
                help();
                break;
            default: printf("Falsche Eingabe\n");
        }
    }while(running == 1);
}

void help()
{

    printf("\n-1- Neue Person eingeben\n");
    printf("-2- Bestimmte Person ausgeben\n");
    printf("-3- Alle Personen ausgeben\n");
    printf("-4- Programm beenden\n");
    printf("-5- Hilfe anzeigen\n");
    printf("\nIhre Auswahl : ");

}

void eingabe(int nr, struct Person *neu)
{
    printf("Vorname : ");
    fgets(neu[nr].vname, LEN, stdin);

    printf("Nachname : ");
    fgets(neu[nr].nname, LEN, stdin);

    printf("jahr: ");
    do
    {
        scanf("%5d",&neu[nr].date.jahr);
    } while(getchar()!= '\n');

    printf("monat : ");
    do
    {
        scanf("%4d",&neu[nr].date.monat);
    }while(getchar()!= '\n');

    printf("tag : ");
    do
    {
        scanf("%4d",&neu[nr].date.tag);
    }while(getchar()!= '\n');
}
void ausgabe(int nr, struct Person person[])
{
    printf("Vorname: %s\n", person[nr].vname);
    printf("Nachname: %s\n", person[nr].nname);
    printf("Geburtstag: %d.", person[nr].date.jahr);
    printf("%d.", person[nr].date.monat);
    printf("%d\n", person[nr].date.tag);
}

void alleAusgeben(int nr, struct Person all[])
{
    for (int i = 0; i < nr; i++)
    {
        ausgabe(nr, all);
    }
}