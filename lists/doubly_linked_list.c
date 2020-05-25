//DEFINES
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct S_RacingCar
{
	char name[12];
	int speed;
	struct S_RacingCar *next;
	struct S_RacingCar *previous;

} RacingCar;

//FUNCTION PROTOTYPES
void printList(RacingCar *start);
RacingCar *makeNewCar();
void cleanUp(RacingCar *start);
RacingCar *addToStart(RacingCar *startPtr);
RacingCar *addToEnd(RacingCar *startPtr);
RacingCar *delete (RacingCar *startPtr);
RacingCar *insert(RacingCar *startPtr);

int main()
{
	char command[16];
	char input[16];

	RacingCar *start = NULL;
	RacingCar *end = NULL;

	while (fgets(input, 15, stdin))
	{

		sscanf(input, "%s", command);

		if (strncmp(command, "quit", 4) == 0)
		{
			printf("\n\nBreaking...\n");
			break;
		}
		else if (strncmp(command, "print", 5) == 0)
		{
			printList(start);
		}
		else if (strncmp(command, "addStart", 8) == 0)
		{
			start = addToStart(start);
			printList(start);
		}
		else if (strncmp(command, "add", 3) == 0)
		{
			start = addToEnd(start);
			printList(start);
		}
		else if (strncmp(command, "delete", 6) == 0)
		{
			start = delete (start);
			printList(start);
		}
		else if (strncmp(command, "insert", 5) == 0)
		{
			start = delete (start);
			printList(start);
		}
	}

	cleanUp(start);

	return 0;
}

void printList(RacingCar *start)
{
	RacingCar *currentCar = start;
	int count = 0;

	RacingCar *ahead = NULL;
	RacingCar *behind = NULL;

	while (currentCar != NULL)
	{
		count++;

		ahead = currentCar->next;
		behind = currentCar->previous;

		printf("Car:%d Name:%s Speed:%d Ahead:%s Behind:%s\n", count,
			   currentCar->name,
			   currentCar->speed,
			   (ahead == NULL) ? "None" : ahead->name,
			   (behind == NULL) ? "None" : behind->name);
		currentCar = currentCar->next;
		ahead = NULL;
		behind = NULL;
	}
	printf("Total Cars:%d\n", count);
}

RacingCar *makeNewCar()
{

	printf("Enter Name And Speed: ");
	char input[16];
	fgets(input, 15, stdin);

	RacingCar *newCar = malloc(sizeof(RacingCar));
	sscanf(input, "%s %d", newCar->name, &newCar->speed);
	printf("Added:%s Speed:%d\n\n", newCar->name, newCar->speed);

	newCar->next = NULL;
	newCar->previous = NULL;

	return newCar;
}

RacingCar *addToStart(RacingCar *startPtr)
{
	RacingCar *newCar = makeNewCar();
	if (startPtr != NULL)
	{
		startPtr->previous = newCar;
		newCar->next = startPtr;
	}

	return newCar;
}

RacingCar *addToEnd(RacingCar *startPtr)
{
	RacingCar *returnPtr = startPtr;
	RacingCar *newCar = NULL;

	if (startPtr == NULL)
	{
		newCar = addToStart(startPtr);
		returnPtr = newCar;
	}
	else
	{
		RacingCar *indexCar = startPtr;
		while (indexCar->next != NULL)
		{
			indexCar = indexCar->next;
		}
		newCar = makeNewCar();
		indexCar->next = newCar;
		newCar->next = NULL;
		newCar->previous = indexCar;
	}
	return returnPtr;
}

RacingCar *delete (RacingCar *startPtr)
{
	printf("Enter Name To Delete:");
	char input[16];
	fgets(input, 15, stdin);

	RacingCar *carRef = startPtr;
	RacingCar *carToDelete = NULL;

	while (carRef != NULL)
	{

		if (strncmp(input, carRef->name, strlen(carRef->name)) == 0)
		{
			carToDelete = carRef;
			break;
		}

		carRef = carRef->next;
	}

	if (startPtr != NULL && carToDelete == startPtr)
	{
		if (carToDelete->next != NULL)
		{
			carToDelete->next->previous = NULL;
			startPtr = carToDelete->next;
		}
		else
		{
			startPtr = NULL;
		}
	}
	else
	{
		if (carToDelete != NULL)
		{
			if (carToDelete->previous != NULL)
			{
				carToDelete->previous->next = carToDelete->next;
			}

			if (carToDelete->next != NULL)
			{
				carToDelete->next->previous = carToDelete->previous;
			}
		}
	}

	if (carToDelete != NULL)
	{
		carToDelete = NULL;
		free(carToDelete);
	}

	return startPtr;
}

RacingCar *insert(RacingCar *startPtr)
{
	printf("insert new car after car:");
	char input[16];
	fgets(input, 15, stdin);

	RacingCar *afterCar = startPtr;
	RacingCar *newCar = NULL;

	if (strncmp(input, afterCar->name, strlen(afterCar->name)) == 0)
	{
		newCar = makeNewCar();
	}
	else
	{
		while (afterCar->next != NULL)
		{
			afterCar = afterCar->next;
		}
		if (strncmp(input, afterCar->name, strlen(afterCar->name)) == 0)
		{
			newCar = makeNewCar();
			break;
		}
	}
	if (newCar != NULL)
	{
		newCar->next = afterCar->next;
		if (newCar->next != NULL)
		{
			newCar->next->previous = newCar;
		}
		afterCar->next = newCar;
		newCar->next = afterCar;
	}
	else
	{
		printf("car not found");
	}
	return startPtr;
}

void cleanUp(RacingCar *start)
{
	RacingCar *freeMe = start;
	RacingCar *holdMe = NULL;
	while (freeMe != NULL)
	{
		printf("Free Name:%s Speed:%d\n",
			   freeMe->name,
			   freeMe->speed);
		holdMe = freeMe->next;
		free(freeMe);
		freeMe = holdMe;
	}
}