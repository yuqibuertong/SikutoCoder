#include<bits/stdc++.h> 
using namespace std;

bool cmp(const string &ls, const string &rs) {
	return ls + rs < rs + ls;
}

int main() {
	int n, t;
	string a;
	vector<string> v;
	vector<string>::iterator vt;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		while (n--) {
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end(), cmp);
		for (vt = v.begin(); vt != v.end(); vt++)
			cout << *vt;
		cout << endl;
		v.clear();
	}
	return 0;
}
