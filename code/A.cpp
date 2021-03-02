#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<iostream>
#include<cstring> 

using namespace std;

const int M = 1e5 + 100; 
map<int, int> A;
int Num[M];

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		
		A.clear();
		memset(Num, 0, sizeof(Num));
		int n, m, tot = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &Num[i]);
			if (A[Num[i]]++ == 0 && Num[i]) tot++;
		}
		
		for (int i = 1; i <= m; i++)
		{
			int op;
			scanf("%d", &op);
			if (op == 2) 
				printf("%d\n", tot);
			else
			{
				int p, v;
				scanf("%d%d", &p, &v);
				if (--A[Num[p]] == 0 && Num[p]) tot--;
				if (A[v]++ == 0 && v) tot++;
				Num[p] = v;
			}
		}
	}
}
