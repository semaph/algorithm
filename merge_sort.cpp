#include <iostream>
using namespace std;

int arr[101];
int tmp[101];

void merge(int left, int right)
{
	int mid = (left + right) / 2;
	int i = left, idx = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
			tmp[idx++] = arr[i++];
		else
			tmp[idx++] = arr[j++];
	}

	while (i <= mid) tmp[idx++] = arr[i++];
	while (j <= right) tmp[idx++] = arr[j++];

	for (int i = left; i <= right; i++)
		arr[i] = tmp[i];
}

void merge_sort(int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, right);
	}
}

int main()
{
	int N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	merge_sort(0, N - 1);
}