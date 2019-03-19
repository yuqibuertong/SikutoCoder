#include<bits/stdc++.h> 
using namespace std;

bool cmp(const int &a, const int &b) {
	return a > b;
}

int main() {
	int i, n, t, p;
	vector<int> v;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%d", &p);
			v.push_back(p);
		}
		sort(v.begin(), v.end(), cmp);
		p = 0;
		for (i = 2; i < n; i += 3) p += v[i];
		printf("%d\n", p);
		v.clear();
	}
	return 0;
}
