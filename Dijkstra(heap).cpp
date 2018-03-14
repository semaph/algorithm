#include <cstdio>

const int MAXN = 20005;
const int MAXM = 300005;
const int inf = 1e9;
int N, M, X;

struct edge
{
	int s, e, t;
	int prv;
} e[MAXM];
int to[MAXN];
int dist[MAXN];

struct HEAP
{
	int x, t;
} h[MAXM], htmp;
int hn; // heapsize

void SWAP(HEAP &a, HEAP &b)
{
	htmp = a; a = b; b = htmp;
}

void push(HEAP x)
{
	h[++hn] = x;
	for (int p = hn; p / 2 >= 1; p /= 2)
	{
		if (h[p].t < h[p / 2].t)
			SWAP(h[p], h[p / 2]);
		else break;
	}
}

HEAP pop()
{
	HEAP ret = h[1];
	h[1] = h[hn--];
	for (int i = 1; i <= hn;)
	{
		int l = i * 2;
		int r = i * 2 + 1;
		int nxt = 0;

		if (l <= hn) nxt = l;
		if (r <= hn && h[r].t < h[nxt].t) nxt = r;
		if (nxt == 0 || h[i].t <= h[nxt].t) break;
		SWAP(h[i], h[nxt]);
		i = nxt;
	}
	return ret;
}

void Dijkstra(int S)
{
	for (int i = 1; i <= N; i++)
		dist[i] = inf;
	dist[S] = 0;
	push({ S, 0 });

	while (hn > 0)
	{
		HEAP now = pop();
		int x = now.x;
		if (now.t > dist[x]) continue;
		for (int i = to[now.x]; i; i = e[i].prv)
		{
			int y = e[i].e, w = e[i].t;
			if (dist[y] > dist[x] + w)
			{
				dist[y] = dist[x] + w;
				push({ y, dist[y] });
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &N, &M, &X);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d%d", &e[i].s, &e[i].e, &e[i].t);
		e[i].prv = to[e[i].s];
		to[e[i].s] = i;
	}
	Dijkstra(X);
	for (int i = 1; i <= N; i++)
	{
		if (dist[i] == inf) puts("INF");
		else printf("%d\n", dist[i]);
	}
}