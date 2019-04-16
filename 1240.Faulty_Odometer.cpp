#include<bits/stdc++.h>
using namespace std;

int main() {
	int i, a, c, s;
	string b;
	while (scanf("%d", &a) && a) {
		s = 1;
		c = 0;
		b = to_string(a);
		for (i = 0; i < b.length(); i++)
			if (b[i] > '4') b[i] = b[i] - 1;
		for (i = b.length() - 1; i > -1; i--) {
			c += s * (b[i] - '0');
			s *= 9;
		}
		printf("%d: %d\n", a, c);
	}
	return 0;
}
