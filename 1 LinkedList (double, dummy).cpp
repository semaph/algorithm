#include <iostream>
#include <cstdlib>

using namespace std;

typedef int Data;

typedef struct LinkedList
{
	Data data;
	struct LinkedList *next, *prev;
} LinkedList;

LinkedList *head, *tail, *cur;

void LInit()
{
	head = (LinkedList*)malloc(sizeof(LinkedList));
	tail = (LinkedList*)malloc(sizeof(LinkedList));
	
	head->prev = NULL;
	head->next = tail;

	tail->prev = head;
	tail->next = NULL;
}

void LInsert(Data data)
{
	LinkedList *newNode = (LinkedList*)malloc(sizeof(LinkedList));
	newNode->data = data;

	newNode->prev = tail->prev;
	tail->prev->next = newNode;

	newNode->next = tail;
	tail->prev = newNode;
}

int LFirst(Data *data)
{
	if (head->next == tail)
		return false;

	cur = head->next;
	*data = cur->data;
	return true;
}

int LNext(Data *data)
{
	if (cur->next == tail)
		return false;

	cur = cur->next;
	*data = cur->data;
	return true;
}

Data LRemove()
{
	LinkedList *rpos = cur;
	Data rdata = rpos->data;

	cur->prev->next = cur->next;
	cur->next->prev = cur->prev;

	cur = cur->prev;
	free(rpos);
	return rdata;
}

int main()
{
	int data;
	LInit();

	for (int i = 1; i <= 8; i++)
		LInsert(i);

	if (LFirst(&data))
	{
		printf("%d ", data);
		while (LNext(&data))
			printf("%d ", data);
		printf("\n");
	}

	// 2�� ��� ���� ���� ///////
	if (LFirst(&data))
	{
		if (data % 2 == 0)
			LRemove();

		while (LNext(&data))
		{
			if (data % 2 == 0)
				LRemove();
		}
	}

	if (LFirst(&data))
	{
		printf("%d ", data);
		while (LNext(&data))
			printf("%d ", data);
		printf("\n");
	}
	return 0;
}

// ���� LFirst, LNext, &data �̷��� ���ϰ� cur������ �� �����ذ��鼭 ��ȸ ���� ����
// Init, Insert, Remove �׸� �׷����鼭 ���� ���ش� �Ǵµ� �ٷ� © �� ���� ������ �ܿ��