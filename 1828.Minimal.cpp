#include <bits/stdc++.h>
using namespace std;

const int maxn = 501;
int a[maxn], b[maxn], n, m;
int f[maxn][maxn];

int num() {
	int i, j;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	for (i = 1; i <= n; i++) {
		if (i == 1) f[i][i] = abs(a[i] - b[i]);
		else f[i][i] = f[i - 1][i - 1] + abs(a[i] - b[i]);
		
	}
	for (i = 1; i <=n; i++)
		for (j = i + 1; j <= m; j++)
			f[i][j] = min(f[i][j - 1], f[i - 1][j - 1] + abs(a[i] - b[j]));
	return f[n][m]; 
}

int main() {
	int k, i;
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d", &n, &m);
		for (i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (i = 1; i <= m; i++) scanf("%d", &b[i]);
		printf("%d\n", num());
	}
	return 0;
}
