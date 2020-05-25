
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int typ;
    int number;
    struct Node *next;
} Node;

//create a new new "Node", place add it to the front of the list
void push(Node **head, int typ, int number);

//Bubble sort the linked List
void bubbleSort(Node **head);
void swap(Node **first, Node **second);

//print all elements of the List
void printList(Node *head);

//free the list
void freeList();

int main()
{
    Node *head = NULL;

    //temporary array for Wagen generierung
    int typArray[5] = {1, 0, 2, 1, 2};

    //temporary array for Wagen generierung
    int numberArray[5] = {1, 2, 3, 4, 5};

    //generates new Wagen with types and numbers from the array
    for (int i = 0; i < 5; i++)
    {
        push(&head, typArray[i], numberArray[i]);
    }

    printf("Unsorted linkled List:\n");
    printList(head);

    printf("BubbleSort linkled List:\n");
    bubbleSort(&head);

    printList(head);

    printf("Free the memory :)....");
    freeList(head);
}

void freeList(Node *head)
{
    Node *tmp = NULL;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void push(Node **head, int typ, int number)
{
    Node *new = (Node *)malloc(sizeof(Node));

    new->typ = typ;
    new->number = number;
    new->next = *head;
    *head = new;
}

void bubbleSort(struct Node **head)
{
    printf("Start of Sort\n");

    if (head == NULL)
    {
        printf("ERROR\n");
        exit(-1);
    }

    Node *current;
    current = *head;

    printf("current Node = %s\n", current->number);

    /* Checking for empty list */
}

void swap(Node **first, Node **second)
{

    printf("Swapping node...\n");
    Node *tmp = *first;
    *first = *second;
    *second = tmp;
}

void printList(Node *head)
{
    Node *tmp = head;
    printf("\n");
    while (tmp != NULL)
    {
        printf("Typ: %d   Nummer: %d\n", tmp->typ, tmp->number);
        tmp = tmp->next;
    }
}
