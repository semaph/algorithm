#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N;
const int MAX_SIZE = 17;
int W[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][1<<MAX_SIZE]; // 1�� �������� 2,3�� �湮�� ���� dp[1][6]

int TSP(int cur, int visited)
{
	// ��� ������ �� �湮�� ���
	// ������ 6�����, 1000000 - 1 = 0111111
	if (visited == (1 << N) - 1)
		return W[cur][0];

	int& ret = dp[cur][visited];
	if (ret > 0) return ret;

	ret = INF;
	for (int nxt = 0; nxt <= N; nxt++)
	{
		// �̹� �湮 �� ���
		if (visited&(1 << nxt))
			continue;

		// ��ΰ� ���� ���
		if (W[cur][nxt] == 0)
			continue;
		
		ret = min(ret, TSP(nxt, visited | (1 << nxt)) + W[cur][nxt]);
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> W[i][j];
		}
	}

	cout << TSP(0, 1) << "\n";
	return 0;
}