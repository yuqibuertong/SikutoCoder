#include<bits/stdc++.h>
using namespace std;

bool prime[1000005];

bool makemod(string k, int l) {
	int s = 0, i;
	for (i = 0; i < k.length(); i++)
		s = (s * 10 + (k[i] - '0')) % l;
	return s == 0;
}

int main() {
	int i, j, l;
	string k;
	prime[2] = 1;
    for (i = 3; i < 1000005; i++) if (i % 2) prime[i] = 1;
    else prime[i] = 0;
	for (i = 3; i <= sqrt(1000005); i += 2)
    	for (j = i + i; j < 1000005; j += i) prime[j] = 0;
	while (cin >> k >> l) {
		if (!l) break;
		for (i = 2; i < l; i++)
			if (prime[i] && makemod(k, i)) {
				printf("BAD %d\n", i);
				break;
			}
		if (i == l) printf("GOOD\n");
	}
	return 0;
}
