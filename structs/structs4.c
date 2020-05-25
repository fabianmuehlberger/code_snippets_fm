#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define LEN 10

// student structure
struct student {
  int id;
  char firstname[LEN];
  char lastname[LEN];
  float points;
};

//function declaration
void getDetail(struct student *ptr, int pos);
void display(struct student *ptr, int pos);
void getPosition();

int main(void)
{
    int position = 0;

    // student structure array
    struct student std[3];
    // pointer to student arry

    getPosition(&position);

    //get userinput
    getDetail(std, position);

    getPosition(&position);

    //display user
    display(std, position);

}

void getPosition(int *x)
{
    int y;
    printf("Enter array position: ");
    do
    {
        scanf("%d", x);
    }while(getchar()!= '\n');

}

void getDetail(struct student *ptr, int pos)
{
    printf("Enter ID: ");
    do
    {
        scanf("%5d", &ptr[pos].id);
    }while(getchar() != '\n');

    printf("Enter first name: ");
    fgets(ptr[pos].firstname, LEN, stdin);

    printf("Enter last name: ");
    fgets(ptr[pos].lastname, LEN, stdin);

    printf("Enter points: ");
    do
    {
        scanf("%f", &ptr[pos].points);
    }while(getchar() != '\n');
}


void display(struct student *ptr, int pos)
{
    printf("ID = %d\n", ptr[pos].id);
    printf("First name = %s\n", ptr[pos].firstname);
    printf("Last name = %s\n", ptr[pos].lastname);
    printf("Points = %f\n", ptr[pos].points);

}