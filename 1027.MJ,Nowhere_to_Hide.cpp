#include<bits/stdc++.h> 
using namespace std;
int main() {
	int n, i;
	string id, ip;
	map<string, string> IP;
	map<string, string> ID;
	map<string, string>::iterator it;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		for (i = 0; i < n; i++) {
			cin >> id >> ip;
			if (IP.count(ip)) ID[IP[ip]] = id;
			else IP[ip] = id;
		}
		for (it = ID.begin(); it != ID.end(); it++)
			cout << it->second << " is the MaJia of " << it->first << endl;
		cout << endl;
		IP.clear(); ID.clear();
	}
	return 0;
}
