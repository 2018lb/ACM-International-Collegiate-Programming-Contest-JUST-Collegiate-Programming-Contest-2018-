#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm> 
#include<map>
#include<cmath>
#define ll long long
 
using namespace std;

inline ll gcd(ll a, ll b) {
  return (!b) ? a : gcd(b, a % b);
}
 
ll work(ll a, ll b, ll mod)
{
	a = a % mod; b = b % mod;
	if (b == 1) return 0;
	ll cnt = 0;
	ll t = 1;
	for (ll g = gcd(a, mod); g != 1; g = gcd(a, mod))
	{
		if (b%g) return -1;
		mod /= g, b /= g;
		t = t * a / g % mod;
		cnt++;
		if (t == b) return cnt;
	}
 
	map<ll, ll> mp;
	int m = ceil(sqrt(1.0 * mod));
	ll e = 1;
	for (int i = 0; i < m; i++)
	{
		mp[e*b%mod] = i;
		e = e * a % mod;
	}
 
	ll nw = t;
	for (int i = 1; i <= m + 1; i++)
	{
		nw = e * nw % mod;
		if (mp.count(nw))
		{
			return i * m - mp[nw] + cnt;
		}
	}
	return -1;
}
int main()
{
	int t, a, b, m;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d %d", &a, &b, &m);
		ll x = work(a, b, m);
		if (x == -1);
		else printf("%lld\n", x);
	}
	return 0;
}
