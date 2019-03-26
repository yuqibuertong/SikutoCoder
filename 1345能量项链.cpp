#include <bits/stdc++.h>
using namespace std;

const int maxn = 200;
int n, w[maxn], f[maxn][maxn];

int num() {
	int i, j, k, m, temp;
	for (i = 0; i < 2 * n; i++) f[i][i] = 0;
	for (k = 2; k <= n; k++)
		for (i = 0; i <= 2 * n - k; i++) {
			m = i + k - 1;
			f[i][m] = 0;
			for (j = i; j < m; j++) {
				temp = f[i][j] + f[j + 1][m] + w[i % n] * w[(j + 1) % n] * w[(m + 1) % n];
				f[i][m] = max(f[i][m], temp);	
			}
		}
	temp = 0;
	for (i = 0; i < n; i++) temp = max(temp, f[i][i + n - 1]);
	return temp; 
}

int main() {
	int i;
	while (scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &w[i]);
			w[n + i] = w[i];
		}
		printf("%d\n", num());
	}
	return 0;
}
