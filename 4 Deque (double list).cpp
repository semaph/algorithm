#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Data;

typedef struct LDeque
{
	Data data;
	struct LDeque *next, *prev;
} LDeque;

LDeque *head, *tail;

void DequeInit()
{
	head = NULL;
	tail = NULL;
}

bool DQIsEmpty()
{
	return head == NULL;
}

void DQPushFront(Data data)
{
	LDeque *newNode = (LDeque*)malloc(sizeof(LDeque));
	newNode->data = data;
	newNode->next = head;

	if (DQIsEmpty())
		tail = newNode;
	else
		head->prev = newNode;

	newNode->prev = NULL;
	head = newNode;
}

void DQPushRear(Data data)
{
	LDeque *newNode = (LDeque*)malloc(sizeof(LDeque));
	newNode->data = data;
	newNode->prev = tail;

	if (DQIsEmpty())
		head = newNode;
	else
		tail->next = newNode;

	newNode->next = NULL;
	tail = newNode;
}

Data DQPopFront()
{
	if (DQIsEmpty())
	{
		printf("Deque Memory Error!\n");
		exit(-1);
	}

	LDeque *rpos = head;
	Data rdata = rpos->data;
	
	head = head->next;
	free(rpos);

	if (head == NULL)
		tail = NULL;
	else
		head->prev = NULL;

	return rdata;
}

Data DQPopRear()
{
	if (DQIsEmpty())
	{
		printf("Deque Memory Error!\n");
		exit(-1);
	}

	LDeque *rpos = tail;
	Data rdata = rpos->data;

	tail = tail->prev;
	free(rpos);

	if (tail == NULL)
		head = NULL;
	else
		tail->next = NULL;

	return rdata;
}

Data DQGetFront()
{
	if (DQIsEmpty())
	{
		printf("Deque Memory Error!\n");
		exit(-1);
	}
	return head->data;
}

Data DQGetRear()
{
	if (DQIsEmpty())
	{
		printf("Deque Memory Error!\n");
		exit(-1);
	}
	return tail->data;
}

int main()
{
	DequeInit();
	for (int i = 3; i >= 1; i--)
		DQPushFront(i);

	for (int i = 4; i <= 6; i++)
		DQPushRear(i);

	while (!DQIsEmpty())
		printf("%d ", DQPopFront());

	printf("\n");

	for (int i = 3; i >= 1; i--)
		DQPushFront(i);

	for (int i = 4; i <= 6; i++)
		DQPushRear(i);

	while (!DQIsEmpty())
		printf("%d ", DQPopRear());

	printf("\n");
	return 0;
}