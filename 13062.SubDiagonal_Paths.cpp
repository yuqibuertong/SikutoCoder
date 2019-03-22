#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j;
	long long gun[31][31];
	for (i = 0; i < 30; i++) gun[i][i + 1] = 0;
	for (i = 0; i <= 30; i++) gun[i][0] = 1;
	while (1) {
		cin >> n;
		if (n == 0) break;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= i; j++)
				gun[i][j] = gun[i][j - 1] + gun[i - 1][j];
		cout << gun[n][n] << endl;
	}
	return 0;
}
