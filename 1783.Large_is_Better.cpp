#include<bits/stdc++.h> 
using namespace std;

bool cmp(const char &a, const char &b) {
	return a > b;
}
int main() {
	int i, t, j;
	string a;
	vector<char> v;
	scanf("%d", &t);
	while (t--) {
		cin >> a;
		for (j = 0; j < a.length(); j++) {
			if (a[j] == '0') {
				sort(v.begin(), v.end(), cmp);
				for (i = 0; i < v.size(); i++) printf("%c", v[i]);
				printf("0");
				v.clear();
				continue;
			}
			v.push_back(a[j]);
		}
		if (v.size()) {
			sort(v.begin(), v.end(), cmp);
			for (i = 0; i < v.size(); i++) printf("%c", v[i]);
			v.clear();
		}
		printf("\n");
	}
	return 0;
}
