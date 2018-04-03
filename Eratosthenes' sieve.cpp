#include <iostream>
#include <cstring>

using namespace std;

int N;
int prime[1000001];

void setPrime()
{
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= N; i++)
	{
		if (prime[i])
		{
			for (int j = i * i; j <= N; j += i)
			{
				prime[j] = false;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	setPrime();
	return 0;
}