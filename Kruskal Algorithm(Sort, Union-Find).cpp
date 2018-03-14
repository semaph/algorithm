#include <iostream>
#include <algorithm>
#define MAXN 1000

using namespace std;

struct edge
{
	int from, to, cost;
} e[MAXN];

int T, N, M, ans;
int parent[MAXN], _rank[MAXN];

bool cmp(const edge &a, const edge &b)
{
	return a.cost < b.cost;
}

void init()
{
	for (int i = 0; i < N; i++)
	{
		parent[i] = i;
		_rank[i] = 0;
	}
}

int find(int a)
{
	if (parent[a] == a)
		return a;
	else 
		return parent[a] = find(parent[a]);
}

void uni(int a, int b) // union-find 연산할때 (disjoint)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (_rank[a] < _rank[b]) parent[a] = b;
	else
	{
		parent[b] = a;
		if (_rank[a] == _rank[b]) _rank[a]++;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	init();
	for (int i = 0; i < M; i++)
	{
		cin >> e[i].from >> e[i].to >> e[i].cost;
	}

	// sort 직접 구현하면 library 안쓰고도 Kruskal 가능
	sort(e, e + M, cmp);

	int cnt = 0;
	for (int i = 0; i < M; i++)
	{
		// 다른 집합이면
		int a = find(e[i].from);
		int b = find(e[i].to);
		if (a == b) continue;
		parent[b] = a;
		ans += e[i].cost;
		// N-1개의 간선 찾으면 종료하도록, 사실안해도 괜찮
		if (++cnt == N - 1) break;
	}
	cout << ans << endl;
}