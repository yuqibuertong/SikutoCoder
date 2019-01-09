#include<bits/stdc++.h>
using namespace std;
int main() {
	string a;
	cin >> a;
	int i, isValid = 1;
	stack<char> s;
	for (i = 0; i < a.length(); i++) {
		if (a[i] == '(' || a[i] == '[' || a[i] == '{')
			s.push(a[i]);
		switch (a[i]) {
			case ')':
				if (!s.empty() && s.top() == '(') s.pop();
				else isValid = 0;
				break;
			case ']':
				if (!s.empty() && s.top() == '[') s.pop();
				else isValid = 0;
				break;
			case '}':
				if (!s.empty() && s.top() == '{') s.pop();
				else isValid = 0;
				break;
			default: break;
		}
		if (!isValid) break;
	}
	if (!s.empty()) isValid = 0;
	if (isValid) printf("Yes\n");
	else printf("No\n");
	return 0;
}
