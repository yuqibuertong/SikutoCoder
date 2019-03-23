#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j;
	string a, b;
	while (cin >> a >> b) {
		int LCS[a.length() + 1][b.length() + 1];
		for (i = 0; i <= a.length(); i++) LCS[i][0]=0;
		for (j = 0; j <= b.length(); j++) LCS[0][j]=0;
		for (i = 1; i <= a.length(); i++)
			for (j = 1; j <= b.length(); j++) {
				if (a[i - 1] == b[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
				else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
			}
		printf("%d\n", LCS[a.length()][b.length()]);
	}
	return 0;
}
