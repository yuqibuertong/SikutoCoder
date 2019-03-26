#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
int n, x[maxn], y[maxn];
double d[maxn][maxn], f[maxn][maxn];

double num() {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			d[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
	f[0][1] = d[0][1];
	for (i = 2; i < n; i++) {
		for (j = 0; j < i - 1; j++)
			f[j][i] = f[j][i - 1] + d[i - 1][i];
		f[i - 1][i] = 99999999;
		for (j = 0; j < i - 1; j++)
			f[i - 1][i] = min(f[i - 1][i], f[j][i - 1] + d[j][i]);	
	}
	return f[n - 2][n - 1] + d[n - 2][n - 1]; 
}

int main() {
	int i;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
		printf("%.2lf\n", num());
	}
	return 0;
}
