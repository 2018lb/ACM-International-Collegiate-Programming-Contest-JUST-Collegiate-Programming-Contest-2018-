#include<cmath> 
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

typedef long long LL;
const int N = 2e6 + 7;
const int ME = 1e6 + 7;
const int M = 1e4 + 7;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
int n, m, top;
int noprime[N], pcnt, p[N / 2];
vector<int> have[N];
int ar[M];
bool is[M];

struct Hopcroft_Carp {
	static const int N = 20000 + 5;
	static const int M = 150000 + 5;
	static const int oo = 0x3f3f3f3f;
	
	int n1, n2, res, tot;
	int ddx[N], ddy[N], mx[N], my[N];
	int que[N << 1];
	bool vis[N << 1];
	int head[N << 1];
	int nex[M], u[M], v[M];
	
	void clear() {
		tot = -1;
		res = 0;
		memset(head, -1, sizeof(head));
		memset(vis, 0, sizeof(vis));
	}
	
	void add(int x, int y) {
		u[++tot] = x;v[tot] = y;
		nex[tot] = head[x];
		head[x] = tot;
	}
	
	bool bfs() {
		memset(ddx, -1, sizeof(ddx));
		memset(ddy, -1, sizeof(ddy));
		res = oo;
		int rear = 1, tail = 1;
		for (int i = 1;i <= n1;++i) {
			if (mx[i] == -1) {
				que[++tail] = i;ddx[i] = 0;
			}
		}
		while (rear <= tail) {
			int x = que[rear];
			if (ddx[x] > res)break;
			for (int i = head[x];~i;i = nex[i]) {
				if (ddy[v[i]] != -1)continue;
				ddy[v[i]] = ddx[x] + 1;
				if (my[v[i]] == -1)res = ddy[v[i]];
				else {
					ddx[my[v[i]]] = ddy[v[i]] + 1;
					que[++tail] = my[v[i]];
				}
			}
			rear++;
		}
		return res != oo;
	}
	
	bool dfs(int x) {
		for (int i = head[x];~i;i = nex[i]) {
			if (vis[v[i]] == 0 && ddy[v[i]] == ddx[x] + 1) {
				vis[v[i]] = 1;
				if (my[v[i]] != -1 && ddy[v[i]] == res)continue;
				if (my[v[i]] == -1 || dfs(my[v[i]])) {
					my[v[i]] = x;
					mx[x] = v[i];
					return true;
				}
			}
		}
		return false;
	}
	
	int maxMatch() {
		int ans = 0;
		memset(mx, -1, sizeof(mx));
		memset(my, -1, sizeof(my));
		while (bfs()) {
			memset(vis, 0, sizeof(vis));
			for (int i = 1;i <= n1;++i) {
				if (mx[i] == -1 && dfs(i))ans++;
			}
		}
		return ans;
	}
}Two;

void getprime() {
	pcnt = 0;
	memset(noprime, 0, sizeof(noprime));
	noprime[0] = noprime[1] = 1;
	for (int i = 2; i < N; ++i) {
		if (!noprime[i])p[pcnt++] = i;
		for (int j = 0; j < pcnt && i * p[j] < N; ++j) {
			noprime[i * p[j]] = 1;
			if (i % p[j] == 0)break;
		}
	}
}

void cal(int t, int id) {
	int tmp = (int)sqrt(t*1.0);
	for (int i = 0; i < pcnt && p[i] <= tmp; ++i) {
		if (t % p[i] == 0) {
			have[p[i]].push_back(id);
			while (t % p[i] == 0) {
				t /= p[i];
			}
		}
		if (t == 1)break;
	}
	if (t > 1)have[t].push_back(id);
}

int main() {
	int tim;
	getprime();
	scanf("%d", &tim);
	while (tim--) {
		scanf("%d", &n);
		for (int i = 0;i < N - 2;++i)have[i].clear();
		for (int i = 1;i <= n;++i) {
			scanf("%d", &ar[i]);
			cal(ar[i], i);
		}
		char s[2];
		for (int i = 1;i <= n;++i) {
			scanf("%s", s);
			is[i] = 0;
			if (s[0] == 'M')is[i] = 1;
		}
		Two.clear();
		Two.n1 = n; Two.n2 = n;
		for (int i = 0;i < N - 2;++i) {
			if (have[i].size() <= 1) {
				have[i].clear();
				continue;
			}
			int len = have[i].size();
			for (int j = 0;j < len;++j) {
				for (int k = 0;k < len;++k) {
					if (j == k)continue;
					if (is[have[i][j]] != is[have[i][k]]) {
						Two.add(have[i][j], have[i][k]);
					}
				}
			}
			have[i].clear();
		}
		printf("%d\n", n - Two.maxMatch() / 2);
	}
	return 0;
}

