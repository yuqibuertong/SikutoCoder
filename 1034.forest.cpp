#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

const int maxn = 101;
int n, m, maxd, maxw, in[maxn], width[maxn];
bool mark[maxn];
vector<int> g[maxn];

bool dfs(int u, int d) {
	int i;
	mark[u] = 1;
	width[d]++;
	maxd = max(maxd, d);
	for (i = 0; i < g[u].size(); i++) {
		int v = g[u][i];
		if (mark[v]) return 0;
		else if (!dfs(v, d + 1)) return 0;
	}
	return 1;
}

bool forest() {
	int i;
	for (i = 0; i < n; i++) {
		g[i].clear();
		mark[i] = 0;
		width[i] = 0;
		in[i] = 0;
	}
	for (i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--;
		v--;
		g[u].push_back(v);
		in[v]++;
	}
	maxd = maxw = 0;
	for (i = 0; i < n; i++)
		if (in[i] == 0)
			if (!dfs(i, 0)) return 0;
	for (i = 0; i < n; i++)
		if (!mark[i]) return 0;
	for (i = 0; i < n; i++) maxw = max(maxw, width[i]);
	printf("%d %d\n", maxd, maxw);
	return 1;
}

int main() {
    while (scanf("%d %d", &n, &m) && n)
    	if (!forest()) printf("INVALID\n");
    return 0;
}
