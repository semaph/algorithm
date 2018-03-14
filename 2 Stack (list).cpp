#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Data;

typedef struct ListStack
{
	Data data;
	struct ListStack *next;
} ListStack;

ListStack *head;

void StackInit()
{
	head = NULL;
}

bool SIsEmpty()
{
	return head == NULL;
}

void SPush(Data data)
{
	ListStack *newNode = (ListStack*)malloc(sizeof(ListStack));
	newNode->data = data;
	newNode->next = head;

	head = newNode;
}

Data SPop()
{
	if (SIsEmpty())
	{
		printf("Stack Memory Error!\n");
		exit(-1);
	}

	ListStack *rpos = head;
	Data rdata = head->data;

	head = head->next;
	free(rpos);
	
	return rdata;
}

Data SPeek()
{
	if (SIsEmpty())
	{
		printf("Stack Memory Error!\n");
		exit(-1);
	}

	return head->data;
}

int main()
{
	StackInit();
	for (int i = 1; i <= 5; i++)
		SPush(i);

	while (!SIsEmpty())
		printf("%d ", SPop());

	printf("\n");
	return 0;
}