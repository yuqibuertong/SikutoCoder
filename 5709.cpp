#include <bits/stdc++.h>
using namespace std;

const int maxs = 5001, maxn = 1002;
int n, s, dp[maxn][maxs], w[maxn], k[maxn];

void num() {
	int i, j;
	for (j = 0; j <= s; j++) dp[0][j] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < w[i]; j++) dp[i][j] = dp[i - 1][j];
		for (j = w[i]; j <= s; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + k[i]);
	}	
}

int main() {
	int i;
	scanf("%d%d", &s, &n);
	for (i = 1; i <= n; i++) scanf("%d%d", &w[i], &k[i]);
	num();
	printf("%d\n", dp[n][s]);
    return 0;   
}
