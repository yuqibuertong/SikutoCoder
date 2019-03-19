#include<bits/stdc++.h> 
using namespace std;
int main() {
	int n, i, a, b;
	stack<int> s;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		int id[2 * n + 1];
		for (i = 0; i < n; i++) {
			scanf("%d %d", &a, &b);
			id[a] = b;
			id[b] = a;
		}
		for (i = 1; i <= 2 * n; i++) {
			if (!s.empty() && s.top() == id[i])
				s.pop();
			else s.push(i);
		}
		if (s.empty()) printf("Yes\n");
		else printf("No\n");
		while (s.size()) s.pop();
	}
	return 0;
}
