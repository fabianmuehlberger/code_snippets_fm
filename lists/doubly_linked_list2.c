//INCLUDES
#include <stdio.h>
#include <stdlib.h>

//DEFINITIONS
#define LEN 255

//DECLARATIONS
typedef struct node
{
    int num;
    char *name;
    int key;

    node_t *prev;
    node_t *next;
} node_t;

//FUNCTION PROTOTYPES

//creates new list Element
node_t *getNewNode();

//adding a new element using the head of the List
node_t addWithHead(node_t *head);

//adding a new element using the tail of the List
node_t addWithTail(node_t *tail);

//delete the nth element of a List Using the Head
node_t deletWithHead(node_t *head);

//delete the nth element of a List Using the tail
node_t deletWithTail(node_t *tail);

void pushHead(node_t *head);

//gets a line pointer to read one line From a file
void readFile();

int main(void)
{

    node_t *next = NULL;
    node_t *prev = NULL;
    node_t *target = NULL;

    node_t *head = NULL;
    node_t *tail = NULL;

    if (head == NULL)
    {
        head = getNewNode();
    }

    addWithHead(head);

    return 0;
}


node_t *getNewNode()
{
    node_t *ptr = NULL;

    if (ptr = malloc(sizeof(node_t)) == NULL)
    {
        fprintf(stderr, "ERROR, no memory left :(");
        return 1;
    }
    else
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        return ptr;
    }
}

void pushHead(node_t *head)
{
    node_t *newNode = getNewNode();
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void pushTail(node_t *head)
{
    node_t *temp = head;
    node_t *newNode = getNewNode();
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

