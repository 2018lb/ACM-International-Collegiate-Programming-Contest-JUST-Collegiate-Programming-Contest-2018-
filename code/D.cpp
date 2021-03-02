
#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, ans = 0, num;
		cin >> n;
		while (n--)
		{
			cin >> num;
			if (num) ans++;
		}
		cout << ans <<endl;
	}
}
