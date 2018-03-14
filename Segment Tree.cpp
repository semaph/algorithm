#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];

	else
	{
		int mid = (start + end) / 2;
		return tree[node] = init(arr, tree, node * 2, start, mid)
			+ init(arr, tree, node * 2 + 1, mid + 1, end);
	}
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff)
{
	if (index < start || index > end) return;
	tree[node] += diff;
	if (start != end)
	{
		int mid = (start + end) / 2;
		update(tree, node * 2, start, mid, index, diff);
		update(tree, node * 2 + 1, mid + 1, end, index, diff);
	}
}

long long sum(vector<long long> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	return sum(tree, node * 2, start, mid, left, right)
		+ sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	int h = (int)ceil(log2(N));
	int tree_size = (1 << (h + 1));

	vector<long long> arr(N);
	vector<long long> tree(tree_size);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	init(arr, tree, 1, 0, N - 1);
	M += K;

	int a, b, c;
	while (M--)
	{
		cin >> a;
		if (a == 1)
		{
			long long c;
			cin >> b >> c;
			long long diff = c - arr[b - 1];
			arr[b - 1] = c;
			update(tree, 1, 0, N - 1, b - 1, diff);
		}

		else if (a == 2)
		{
			cin >> b >> c;
			cout << sum(tree, 1, 0, N - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}