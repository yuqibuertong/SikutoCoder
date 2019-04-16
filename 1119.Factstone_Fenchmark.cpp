#include<bits/stdc++.h>
using namespace std;

int main() {
	int i, a;
	double b, n;
	while (scanf("%d", &a) && a) {
		i = 1;
		n = 0;
		b = 1 << (a / 10 - 194);
		while (n < b)
			n += log(++i) / log(2);
		printf("%d\n", i - 1);
	}
	return 0;
}
