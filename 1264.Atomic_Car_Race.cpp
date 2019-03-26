#include <bits/stdc++.h>
using namespace std;

const int maxn = 100, maxm = 10001;
int n, a[maxn];
double b, e, f, v, r, dp[maxn], g[maxm];

double num() {
	int i, j;
	g[0] = 0;
	for (i = 0; i < a[n - 1]; i++)
		g[i + 1] = g[i] + (i < r? 1/(v - f*(r - i)) : 1/(v - e*(i - r)));
	for (i = 0; i < n; i++) {
		dp[i] = g[a[i]];
		for (j = 0; j < i; j++) dp[i] = min(dp[i], dp[j] + g[a[i] - a[j]] + b);
	}
	return dp[n - 1];	
}

int main() {
	int i;
	while (scanf("%d", &n) && n) {
		for (i = 0; i < n; i++) scanf("%d", &a[i]);
		scanf("%lf%lf%lf%lf%lf", &b, &r, &v, &e, &f);
		printf("%.4lf\n", num());
	}
    return 0;   
}
