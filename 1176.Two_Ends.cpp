#include <bits/stdc++.h>
using namespace std;

const int maxn = 1001;
int n;
int a[maxn];
int f[maxn][maxn];
bool cal[maxn][maxn];

int dp(int l, int r) {
	if (l > r) return 0;
	if (cal[l][r]) return f[l][r];
	cal[l][r] = 1;
	f[l][r] = 0;
	f[l][r] = max(f[l][r], a[l + 1] >= a[r]? dp(l + 2, r) + a[l] - a[l + 1]: dp(l + 1, r - 1) + a[l] - a[r]);
	f[l][r] = max(f[l][r], a[l] >= a[r - 1]? dp(l + 1, r - 1) + a[r] - a[l] : dp(l, r - 2) + a[r] - a[r - 1]);
	return f[l][r];
}

int twoend() {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0 ; j < n ; j++)
			cal[i][j] = 0;
	return dp(0, n - 1);
}

int main() {
	int i = 1, j;
	while (scanf("%d", &n) && n) {
		for (j = 0; j < n; j++) scanf("%d", &a[j]);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n", i, twoend());
		i++;
	}
	return 0;
}
