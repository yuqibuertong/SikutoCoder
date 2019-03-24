#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[31][16];
bool ins[16];

void get() {
	int i, j;
	memset(ins, 0, sizeof(ins));
	for (i = 0; i < 16; i++) {
		bool a = 0, b = 0;
		for (j = 0; j < 4; j++) {
			if ((i >> j & 1) == 1) {
				a |= b;
				b = 0;
			}
			else b ^= 1;
		}
		if (!a && !b) ins[i] = 1;
	}
}

void solve(){
	int i, j, k;
	dp[0][0] = 1;
	for (i = 1; i <= n; i++)
		for (j = 0; j < 16; j++) {
			dp[i][j] = 0;
			for (k = 0; k < 16; k++)
				if (!(k & j) && ins[k|j])
					dp[i][j] += dp[i - 1][k];
		}
	printf("%lld\n", dp[n][0]);
}

int main(){
	int i, k;
	scanf("%d", &k);
	for (i = 1; i <= k; i++) {
		scanf("%d", &n);
		get();
		printf("%d ", i);
		solve();
	}
	return 0;	
}
