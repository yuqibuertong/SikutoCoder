#include<bits/stdc++.h>
using namespace std;

long long s[31];
long long num(int a) {
	if (a == 0) return 1;
	if (a == 2) return 3;
	if (s[a]) return s[a];
	long long r = 0;
	int t = a - 2;
	r += 3 * num(t); 
	while (t) {
		t -= 2;
		r += 2 * num(t);
	}
	s[a] = r;
	return r;
}
int main() {
	int n;
	memset(s, 0, sizeof(s));
	while (scanf("%d", &n) && ~n) {
		if (n % 2) printf("0\n");
		else printf("%lld\n", num(n)); 
	}
	return 0;
} 
