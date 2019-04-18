#include<bits/stdc++.h>
using namespace std;

bool prime[1299710];

int main() {
	int i, j, n;
	prime[2] = 1;
    for (i = 3; i < 1299710; i++) if (i % 2) prime[i] = 1;
    else prime[i] = 0;
	for (i = 3; i <= sqrt(1299710); i++)
 		if (prime[i])
    		for (j = i + i; j < 1299710; j += i) prime[j] = 0;
	while (scanf("%d", &n) && n)
		if (prime[n]) printf("0\n");
		else {
			for (i = n + 1; prime[i] == 0; i++);
			for (j = n - 1; prime[j] == 0; j--);
			printf("%d\n", i - j);
		}
	return 0;
}
