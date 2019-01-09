#include<bits/stdc++.h>
using namespace std;
void insertionSort(int a[], int n) {
	int i, j, t;
    for (i = 1; i < n; i++) {
    	t = a[i];
        for (j = i; j > 0 && a[j - 1] > t; j--)
            a[j] = a[j - 1];
        a[j] = t;
	}
}
int main() {
	int n, gun[10000];
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) scanf("%d", &gun[i]);
	insertionSort(gun, n);
	for (i = 0; i < n; i++) printf("%d ", gun[i]);
	return 0;
}
