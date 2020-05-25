
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

//insertion sort the linked List
void insertionSort(Node **head);

//insert the the Node sorted into the List
void sortedInsert(Node **head, Node *new);

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
    int numberArray[5] = {10, 3, 4, 1, 9};

    //generates new Wagen with types and numbers from the array
    for (int i = 0; i < 5; i++)
    {
        push(&head, typArray[i], numberArray[i]);
    }

    printf("Unsorted linkled List:\n");
    printList(head);

    printf("\n\ninsertionSort linkled List:\n");
    insertionSort(&head);
    printList(head);

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

void insertionSort(Node **head)
{
    Node *sorted = NULL;
    Node *current = *head;

    while (current != NULL)
    {
        Node *next = current->next;

        sortedInsert(&sorted, current);

        current = next;
    }
    *head = sorted;
}

void sortedInsert(Node **head, Node *new)
{
    Node *current;
    /* Special case for the head end */
    if (*head == NULL || (*head)->typ >= new->typ)
    {
        new->next = *head;
        *head = new;
    }
    else
    {
        /* Locate the node before the point of insertion */
        current = *head;
        while (current->next != NULL && current->next->typ < new->typ)
        {
            current = current->next;
        }
        new->next = current->next;
        current->next = new;
    }
}

void printList(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        printf("Typ: %d   Nummer: %d\n", tmp->typ, tmp->number);
        tmp = tmp->next;
    }
}
