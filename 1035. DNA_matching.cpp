#include<bits/stdc++.h> 
using namespace std;

int main() {
	int n, i, t, k, j;
	multimap<string, string> m;
	multimap<string, string>::iterator mt;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		k = 0;
		for (i = 0; i < n; i++) {
			string a, b;
			cin >> a; b = a;
			for (j = 0; j < a.length(); j++)
				switch (a[j]) {
					case 'A': b[j] = 'T'; break;
					case 'T': b[j] = 'A'; break;
					case 'G': b[j] = 'C'; break;
					default: b[j] = 'G'; break;
				}
			if (!m.empty()) {
				mt = m.find(b);
				if (mt != m.end()) {
					m.erase(mt);
					k++;
				}
				else m.insert(make_pair(a, b));
			}
			else m.insert(make_pair(a, b));
		}
		cout << k << endl;
		m.clear();
	}
	return 0;
}
