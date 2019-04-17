#include<bits/stdc++.h>
using namespace std;

bool prime[10001];
long long sum[10001];

int main() {
	int i, j, n, k;
	prime[2] = 1;
	prime[1] = 1; //1不是质数，此处为了方便如此设置 
	sum[1] = 0;
    for (i = 3; i <= 10000; i++) if (i % 2) prime[i] = 1;
    else prime[i] = 0;
	for (i = 3; i <= 100; i++)
 		if (prime[i])
    		for (j = i + i; j <= 10000; j += i) prime[j] = 0;
    for (i = 2; i <= 10000; i++)
    	sum[i] = (prime[i]? i + sum[i - 1] : sum[i - 1]);
	while (scanf("%d", &n) && n) {
		k = 0;
		for (i = 1; i < 10000; i++)
			for (j = i + 1; j <= 10000; j++)
				if (prime[j] && prime[i] && sum[j] - sum[i] == n) k++;
				else if (sum[j] - sum[i] > n) break;
		printf("%d\n", k);
	}
	return 0;
}
