#include<bits/stdc++.h>
using namespace std;

int n, num, c[9];

bool isvalid(int r) {
	int i;
	for (i = 0; i < r; i++)
		if (c[r] == c[i] || r - c[r] == i - c[i] || r + c[r] == i + c[i])
			return 0;
	return 1;
}

void solve(int r) {
	int i;
    if (r == n) num++;
    else for (i = 0; i < n; i++) {
    	c[r] = i;
    	if (isvalid(r)) solve(r + 1);
	}
}

int main() {
	while (scanf("%d", &n) != EOF) {
		num = 0;
		solve(0);
    	printf("%d\n", num);
	}
    return 0;
}
