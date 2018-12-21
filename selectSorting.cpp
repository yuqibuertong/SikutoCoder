#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, i, j, min;
	int a[10000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (a[min] > a[j]) min = j;
		}
		swap(a[min], a[i]);
	}
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}
