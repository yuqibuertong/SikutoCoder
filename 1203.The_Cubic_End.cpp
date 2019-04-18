#include <bits/stdc++.h>
using namespace std;

long long mul(long long a, long long b, long long c) {
	long long d;
	for (d = 0; b != 0; b /= 2) {
		d += (b % 2) * a;
		d %= c;
		a = (a * 2) % c;
	}
	return d;
}
long long cube(long long a, long long b) {
	return mul(mul(a, a, b), a, b);
}
int main() { 
	int t, len, i;
	long long res, temp, p, s;
	string str;
	cin >> t;
	while (t--){
		cin >> str;
		p = 10;
		len = str.length();
		temp = str[len - 1] - '0';
		switch (temp) {
			case 1: res = 1; break;
			case 3: res = 7; break;
			case 7: res = 3; break;
			default: res = 9; break;
		}
		for (i = len - 2; i >= 0; i--) {
			s = p;
			temp += (str[i] - '0') * p;
			p *= 10;
			while (cube(res, p) != temp) res += s;
		}
		printf("%lld\n", res);
	}
	return 0;
}
