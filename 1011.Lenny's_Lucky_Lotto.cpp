#include <bits/stdc++.h>
using namespace std;

const int maxn = 11, maxm = 2001;
long long f[maxn][maxm], s[maxn][maxm];

void num() {
	int i, j;
	for (i = 1; i < maxm; i++) {
		f[1][i] = 1;
		s[1][i] = i;
	}
	for (i = 2; i < maxn; i++) {
		f[i][0] = s[i][0] = 0;
		for (j = 1; j < maxm; j++) {
			f[i][j] = s[i - 1][j / 2];
			s[i][j] = s[i][j - 1] + f[i][j];
		}
	}
}

int main() {
	int j, k, m, n;
	num();
	scanf("%d", &j);
	for (k = 1; k <= j; k++) {
		scanf("%d %d", &n, &m);
		printf("Case %d: n = %d, m = %d, # lists = %lld\n", k, n, m, s[n][m]);
	}
	return 0;
}
