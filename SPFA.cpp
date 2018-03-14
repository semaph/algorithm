#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAXV = 100001;

struct edge
{
	int v, c;
};

vector<edge> g[MAXV];
long long dist[MAXV];
int inQ[MAXV];
int T, V, E, A, B;
int a, b, c;

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> T;
	int tc = T;
	while (T--)
	{
		cin >> V >> E >> A >> B;
		for (int i = 1; i <= V; i++)
		{
			g[i].clear();
			dist[i] = 2e18;
			inQ[i] = 0;
		}

		for (int i = 0; i < E; i++)
		{
			cin >> a >> b >> c;
			g[a].push_back({ b, c });
			g[b].push_back({ a, c });
		}

		dist[A] = 0;
		inQ[A] = 1;
		queue<int> q;
		q.push(A);

		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			inQ[u] = 0;
			for (auto &e : g[u])
			{
				int v = e.v;
				int w = e.c;
				if (dist[v] > dist[u] + w)
				{
					dist[v] = dist[u] + w;
					if (!inQ[v]) q.push(v), inQ[v] = 1;
				}
			}
		}
		cout << "#" << tc - T << " " << dist[B] << "\n";
	}
}