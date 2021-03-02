#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	while (t--)
	{
		long long a,b,d;
		cin >> a >> b >> d;
		double ans = d/sqrt(2);
		printf("%lf\n", ans*ans);
	}
}
