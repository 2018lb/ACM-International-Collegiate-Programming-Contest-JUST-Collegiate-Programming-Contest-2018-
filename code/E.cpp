#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>


using namespace std;
typedef long long LL;
const int N = 10 + 8;
const int ME = 1 << 16;

int n, m;

int ok[ME + 1];
int dp[N][ME + 1];
int ar[N][N];

inline bool adj(int x) { return (x&(x << 1)) || (x&(x >> 1)); }

inline int get_num(int t, int s)
{
	int sum = 0;
	for (int i = 0;i < n;++i)
	{
		if (s&(1 << i))sum += ar[t][i];
	}
	return sum;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		memset(dp, 0, sizeof(dp));
		memset(ok, 0, sizeof(ok));
		int aa = 1 << n, tot = 0;

		for (int i = 0; i < aa; ++i)
		{
			if (adj(i) == 0)ok[tot++] = i;
		}

		for (int i = 0;i < n;++i)
		{
			for (int j = 0;j < n;++j)
			{
				scanf("%d", &ar[i][j]);
			}
		}

		for (int _i = 0, i; _i < tot; ++_i)
		{
			i = ok[_i];
			dp[0][_i] = get_num(0, i);
		}

		for (int _i = 0, i, j; _i < tot; ++_i)
		{
			i = ok[_i];
			for (int _j = 0; _j < tot; ++_j) {
				j = ok[_j];
				if ((i&j) || (i&(j << 1)) || (i&(j >> 1)))continue;
				dp[1][_i] = max(dp[0][_j] + get_num(1, i), dp[1][_i]);
			}
		}

		for (int t = 2, i, j; t < n; ++t)
		{
			for (int _i = 0; _i < tot; ++_i)
			{
				i = ok[_i];
				for (int _j = 0; _j < tot; ++_j)
				{
					j = ok[_j];
					if ((i&j) || (i&(j << 1)) || (i&(j >> 1)))continue;
					dp[t][_i] = max(dp[t - 1][_j] + get_num(t, i), dp[t][_i]);
				}
			}
		}
		
		int ans = 0;
		for (int _i = 0; _i < tot; ++_i)
		{
			ans = max(ans, dp[n - 1][_i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

