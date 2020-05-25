#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10

struct Member
{
    int age;
    char name[LEN];
};

struct Member newMember();

void newMember2(struct Member *tmpMem);

void display(struct Member member);

void display2(struct Member *member);

int main(void)
{
    struct Member list[2];

    //Weg 1: Funktion wird aufgerufen und der neu erstellte Member zurückgegeben und in
    //List[0] gespeichert.
    //danach wird wird liste[0] and die funktion display übergeben und ausgegeben.
    list[0] = newMember();
    display(list[0]);

    //Weg 2: funktion wird aufgerufen und der Pointer Liste[1] übergeben. der neue Member wird
    //direkt in liste[1] geschrieben
    //danach wird der Pointer and die Display funktion weitergegeben
    newMember2(&list[1]);
    display2(&list[1]);
}

struct Member newMember()
{
    struct Member tmpMem;
    printf("Enter name: ");
    scanf(" %s", tmpMem.name);

    printf("Enter age: ");
    scanf("%i", &tmpMem.age);

    return tmpMem;
}

void newMember2(struct Member *tmpMem)
{
    printf("Enter name: ");
    scanf(" %s", tmpMem->name);

    printf("Enter age: ");
    scanf("%i", &tmpMem->age);
}

void display(struct Member member)
{
    printf("your name is: %s\n", member.name);
    printf("your age is: %i\n", member.age);
}

void display2(struct Member *member)
{
    printf("your name is: %s\n", member->name);
    printf("your age is: %i\n", member->age);
}