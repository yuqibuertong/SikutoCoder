#include <bits/stdc++.h>
using namespace std;

string a;
int b, ans[105];
void product(string a, int b) {
	if (a == "0" || b == 0) printf("0\n");
	else {
		int i, j = 104, k, p;
		for (i = 0; i < 105; i++) ans[i] = 0;
		for (i = a.length() - 1; i > -1; i--, j--) {
			p = (a[i] - '0') * b;
			k = j;
			do {
				ans[k] += p % 10;
				p /= 10;
				if (ans[k] >= 10) {
					ans[k] %= 10;
					p++;
				}
				k--;
			}while(p);
		}
		for (i = k + 1; i < 105; i++)
			printf("%d", ans[i]);
		printf("\n");
	}
}

int main() {
	int i, t;
	scanf("%d", &t);
	while (t--) {
		cin	>> a >> b;
		product(a, b);
	}
    return 0;   
}
