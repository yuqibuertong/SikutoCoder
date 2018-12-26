#include<bits/stdc++.h>
using namespace std;
void merge(int a[], int l, int mid, int r) {
	int kkk[r - l + 1];
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r) {
		if (a[i] <= a[j]) kkk[k++] = a[i++];
		else kkk[k++] = a[j++];
	}
	while (i <= mid) kkk[k++] = a[i++];
	while (j <= r) kkk[k++] = a[j++];
	for (k = 0; k <= r - l; k++) a[l + k] = kkk[k];
}
void mergesort(int a[], int l, int r) {
	if (l >= r) return;
	int mid = (l + r)/2;
	mergesort(a, l, mid);
	mergesort(a, mid + 1, r);
	merge(a, l, mid, r);
}
int main() {
	int n, gun[10000];
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) scanf("%d", &gun[i]);
	mergesort(gun, 0, n - 1);
	for (i = 0; i < n; i++) printf("%d ", gun[i]);
	return 0;
} 
