#include <bits/stdc++.h>
using namespace std;

const int maxs = 10001;
int s, a[7];
int w[7] = {0, 3, 5, 2, 6, 11, 8};
double k[7] = {0, 0.01, 0.05, 0.1, 0.25, 0.5, 1}, dp[7][maxs];

void num() {
	int i, j, z;
	double p; 
	for (i = 1; i <= 6; i++)
		for (j = 0; j <= s; j++) {
			if (i > 1) {
				dp[i][j] = dp[i - 1][j];
				if (j / w[i]) {
					p = 0;
					for (z = 1; z <= j / w[i] && z <= a[i]; z++)
						if (dp[i - 1][j - z * w[i]] + z * k[i] > p)
							p = dp[i - 1][j - z * w[i]] + z * k[i];
					dp[i][j] = max(dp[i][j], p);
				}
			}
			else if (j / w[1]) dp[1][j] = j / w[1] * k[1];
		}
}

int main() {
	int i;
	while (scanf("%d", &s) != EOF) {
		for (i = 1; i < 7; i++) scanf("%d", &a[i]);
		num();
		printf("$%.2lf\n", dp[6][s]);
	}
    return 0;
}
