#include <iostream>
#include <algorithm>
#define INF 987654321;
using namespace std;

int shortest[505], parent[505];
int n, adj[505][505];

void BellmanFordList()
{
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX;
	dist[src] = 0;

	// BellmanFord
	for (int i = 1; i <= V - 1; i++)
	{
		for (int j = 0; j < E; j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			
			if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
				dist[v] = dist[u] + weight;
		}
	}
}

int main()
{
	memset(shortest, 0, sizeof(shortest));
	memset(parent, 0, sizeof(parent));
	shortest[1] = 0;
	bool update = 1;
	while (update)
	{
		update = 0;
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (shortest[k] > shortest[j] + adj[j][k])
				{
					shortest[k] = shortest[j] + adj[j][k];
					parent[k] = j;
					update = 1;
				}
			}
		}
	}

	return 0;
}