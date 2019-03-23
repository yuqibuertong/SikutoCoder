#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j, al, max = 0;
	scanf("%d", &n);
	int s[n + 1], p[n + 1], l[n + 1];
	for (i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		p[i] = 0;
		l[i] = 1;
		for (j = 1; j < i; j++)
			if (s[i] >= s[j] && l[j] + 1 > l[i]) {
				p[j] = j;
				l[i] = l[j] + 1;
			}
		if (l[i] > max) {
			max = l[i];
			al = s[i];
		}
		else if (l[i] == max)
			al = min(s[i], al);
	}
	printf("%d %d\n", max, al);
	return 0;
}
