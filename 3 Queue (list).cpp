#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Data;

typedef struct LQueue
{
	Data data;
	struct LQueue *next;
} LQueue;

LQueue *front, *rear;

void QueueInit()
{
	front = NULL;
	rear = NULL;
}

bool QIsEmpty()
{
	return front == NULL;
}

void Enqueue(Data data)
{
	LQueue *newNode = (LQueue*)malloc(sizeof(LQueue));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty())
	{
		front = newNode;
		rear = newNode;
	}

	else
	{
		rear->next = newNode;
		rear = newNode;
	}
}

Data Dequeue()
{
	if (QIsEmpty())
	{
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	LQueue *rpos = front;
	Data rdata = rpos->data;
	
	front = front->next;
	free(rpos);
	
	return rdata;
}

Data QPeek()
{
	if (QIsEmpty())
	{
		printf("Queue Memory Error!\n");
		exit(-1);
	}

	return front->data;
}

int main()
{
	QueueInit();
	for (int i = 1; i <= 5; i++)
		Enqueue(i);

	while (!QIsEmpty())
		printf("%d ", Dequeue());

	printf("\n");
	return 0;
}