#include <iostream>

using namespace std;

void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
			low++;
		while (pivot <= arr[high] && high >= (left + 1))
			high--;

		if (low <= high)
			swap(arr[low], arr[high]);
	}

	swap(arr[left], arr[high]);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main()
{
	int arr[11];
	for (int i = 0; i < 10; i++)
		arr[i] = 10 - i;

	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;

	QuickSort(arr, 0, 9);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}