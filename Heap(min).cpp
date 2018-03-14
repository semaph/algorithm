#include <iostream>
#include <algorithm>

using namespace std;

int hn;
int heap[11];

void push(int x)
{
	heap[++hn] = x;
	for (int p = hn; p / 2 >= 1; p /= 2)
	{
		if (heap[p] < heap[p / 2])
			swap(heap[p], heap[p / 2]);
		else break;
	}
}

int pop()
{
	int ret = heap[1];
	heap[1] = heap[hn--];

	for (int i = 1; i <= hn;)
	{
		int l = i * 2;
		int r = i * 2 + 1;
		int nxt = 0;

		if (l <= hn) nxt = l;
		if (r <= hn && heap[r] < heap[nxt]) nxt = r;
		if (nxt == 0 || heap[i] <= heap[nxt])break;
		swap(heap[i], heap[nxt]);
		i = nxt;
	}
	return ret;
}

int main()
{
	int arr[11];
	for (int i = 0; i < 10; i++)
		push(10 - i);

	for (int i = 0; i < 10; i++)
		cout << pop() << " ";
	return 0;
}