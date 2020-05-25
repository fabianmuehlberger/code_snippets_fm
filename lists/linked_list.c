//IN THIS EXAMPLE
// 1. Create a linked list
//      a. allocate memory & check for NULL
//      b. initialize value and next field
//      c. return a pointer

// 2. insert a new Node
// 3. delete a element from the list
// 4. delete the entire list 

//INCLUDES
#include <stdio.h>
#include <stdlib.h>

//DECLARATIONS
typedef struct S_Node
{
    int value;
    struct _Node *next;
}Node;



//FUNCTION PROTOTYPES
Node *newNode();

int main(void)
{
    


    return 0;
}

Node *newNode()
{
    Node *new = create(6);

    return new;
}
