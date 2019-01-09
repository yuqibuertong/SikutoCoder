#include<bits/stdc++.h>
using namespace std;
void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++)
        for (int j = i; j > 0 && a[j] < a[j - 1]; j--)
            swap(a[j], a[j - 1]);
    return;
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
