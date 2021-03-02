#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int M = 1e4+100; 
int Sum[M];

int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		memset(Sum, 0, sizeof(Sum));
		int n, ans = 0, Maxx = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int a;
			cin >> a;
			Maxx = max(a, Maxx);
			Sum[a]++;
		}
		
		for(int i = 0; i < Maxx; i++) ans = max(ans, Sum[i]+Sum[i+1]);
		cout << ans << endl;
	}
}
