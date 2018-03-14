#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

ll sum(vector<ll> &tree, int i)
{
	ll ans = 0;
	while (i > 0)
	{
		ans += tree[i];
		i -= (i & -i);
	}

	return ans;
}

void update(vector<ll> &tree, int i, ll val)
{
	while (i < tree.size())
	{
		tree[i] += val;
		i += (i & -i);
	}
}

int main()
{
	int T, N, M;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &N, &M);
		vector<ll> arr(N + 1);
		vector<ll> tree(N + 1);
		for (int i = 1; i <= N; i++)
		{
			scanf("%d", &arr[i]);
			update(tree, i, arr[i]);
		}

		int C;
		printf("#%d", tc);
		for (int i = 0; i < M; i++)
		{
			scanf("%d", &C);
			if (C == 1)
			{
				int index;
				ll val;
				scanf("%d %lld", &index, &val);
				arr[index] += val;
				update(tree, index, val);
			}

			else
			{
				int L, R;
				scanf("%d %d", &L, &R);
				printf(" %lld", sum(tree, R) - sum(tree, L - 1));
			}
		}
		printf("\n");
	}
	return 0;
}