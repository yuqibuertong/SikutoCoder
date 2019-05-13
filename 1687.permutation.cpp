#include<bits/stdc++.h> 
using namespace std;

int main() {
	int n, k, i, j, mod = 2007;
	int a[101][101] = {0};
	a[1][0] = 1;
	for (i = 2; i < 101; i++) {
		a[i][0] = 1;
		for (j = 1; j < i; j++) {
			a[i][j] = a[i-1][j-1] * (i-j) + a[i-1][j] * (j+1);
			if (a[i][j] >= 2007) a[i][j] %= 2007;
		}		
	}	
	while(scanf("%d%d", &n, &k) != EOF) printf("%d\n", a[n][k]);
	return 0;
}
