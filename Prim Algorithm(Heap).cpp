#include <cstdio>

const int MAXN = 10005;
const int MAXM = 200005;
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

// C[x] : x가 이미 스패닝 트리에 속한 정점인지 여부
bool C[MAXN];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		scanf("%d%d%d", &e[i].s, &e[i].e, &e[i].t);
		e[i].prv = to[e[i].s];
		to[e[i].s] = i;
		// 반대 방향도 추가
		e[i + M] = e[i];
	}

	// 반대 방향 고려
	for (int i = M + 1; i <= 2 * M; i++)
	{
		int t = e[i].s; e[i].s = e[i].e; e[i].e = t;
		e[i].prv = to[e[i].s];
		to[e[i].s] = i;
	}

	long long ans = 0;
	push({ 1, 0 });

	while (hn > 0)
	{
		HEAP now = pop();
		if (C[now.x]) continue;
		C[now.x] = true;
		ans += now.t;
		for (int i = to[now.x]; i > 0; i = e[i].prv)
			push({ e[i].e, e[i].t });
	}
	printf("%lld\n", ans);
}