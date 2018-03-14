#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

struct edge
{
	int to, cost;
};

vector<edge> g[1001];
int dist[1001];
queue<edge> q;
int N, E, V1, V2;
int a, b, c;
edge ed1, ed2;

int main()
{
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		cin >> a >> b >> c;
		g[a].push_back({ b, c });
	}

	cin >> V1 >> V2;

	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}

	q.push({ V1, 0 });
	dist[V1] = 0;

	while (!q.empty())
	{
		ed1 = q.front();
		q.pop();
		
		int qsize = g[ed1.to].size();
		for (int i = 0; i < qsize; i++)
		{
			ed2 = g[ed1.to][i];
			if (dist[ed2.to] > ed1.cost + ed2.cost)
			{
				dist[ed2.to] = ed1.cost + ed2.cost;
				ed2.cost = dist[ed2.to];
				q.push(ed2);
			}
		}
	}

	cout << dist[V2] << endl;
	return 0;
}