#include<bits/stdc++.h>
using namespace std;
int gun[10], k[10] = {0};
int n;
void build(int u) {
	int i;
	if (u == n + 1) {
		for (i = 1; i <= n; i++) {
			printf("%d%s", gun[i], i == n? "\n" : " ");
		}
		return;
	}
	for (i = 1; i <= n; i++) {
		if (!k[i]) {
			gun[u] = i;
			k[i] = 1;
			build(u + 1);
			k[i] = 0;
		}
	}	
}
int main() {
    cin >> n;
    build(1);
	return 0;
}
