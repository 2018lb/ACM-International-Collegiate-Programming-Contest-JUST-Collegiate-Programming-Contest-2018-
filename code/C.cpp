#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<iostream>
#define lowbit(x) (x&(-x))

using namespace std;

typedef long long LL;

const int N = 1e5 + 7;

int n, q, tot;
int ar[N], bit[N], br[N];

void add(int x) 
{
	while (x <= n) 
	{
		bit[x]++;
		x += lowbit(x);
	}
}
int query(int x) 
{
	int sum = 0;
	while (x) 
	{
		sum += bit[x];
		x -= lowbit(x);
	}
	return sum;
}
int x, y;
int main() 
{
	int t;
	scanf("%d", &t);
	while (t--) 
	{
		scanf("%d", &n);
		for (int i = 1;i <= n;++i) 
		{
			int x;
			scanf("%d", &x);
			ar[x] = i;
		}
		for (int i = 1;i <= n;++i) 
		{
			int x;
			scanf("%d", &x);
			br[i] = ar[x];
		}
		long long all = 0;
		memset(bit, 0, sizeof(bit));
		for (int i = 1;i <= n;++i) 
		{
			int p = br[i];
			int tmp = query(p);
			all += tmp;
			add(p);
		}
		all = n * 1LL * (n - 1) / 2 - all;
		printf("%lld\n", all);
	}
	return 0;
}

