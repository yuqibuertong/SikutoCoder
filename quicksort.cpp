#include<bits/stdc++.h>
using namespace std;
void quicksort(int a[], int l, int r) {
	if (l >= r) return;
	int i = l, j = r;
	int key = a[l];
	while (i != j) {
		while (i < j && a[j] >= key) j--;
		while (i < j && a[i] <= key) i++;
		swap(a[i], a[j]);
	}
	swap(a[i], a[l]);
	quicksort(a, l, i - 1);
	quicksort(a, i + 1, r);
}
int main() {
	int n, gun[10000];
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++) scanf("%d", &gun[i]);
	quicksort(gun, 0, n - 1);
	for (i = 0; i < n; i++) printf("%d ", gun[i]);
	return 0;
} 
