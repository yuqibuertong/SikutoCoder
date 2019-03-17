#include<bits/stdc++.h> 
using namespace std;

int main() {
	int i, add, k = 1, w, p;
	int lower[4] = {0}, upper[4], price[4];
	while (scanf("%d", &upper[0]) != EOF) {
		scanf("%d", &price[0]);
		lower[1] = upper[0] + 1;
		for (i = 1; i < 3; i++) {
			scanf("%d %d", &upper[i], &price[i]);
			lower[i + 1] = upper[i] + 1;
		}
		upper[i] = 1001;
		scanf("%d", &price[i]);
		printf("Set number %d:\n", k);
		while (1) {
			scanf("%d", &w);
			if (w == 0) {
				k++;
				printf("\n");
				break;
			}
			for (i = 0; i < 4; i++) {
				if (w >= lower[i] && w <= upper[i]) {
					p = w * price[i];
					add = 0;
				}
				else if (w < lower[i] && p > lower[i] * price[i]) {
					add = lower[i] - w;
					p = lower[i] * price[i];
				}
			}
			printf("Weight (%d) has best price $%d (add %d pounds)\n", w, p, add);	
		}
	}
	return 0;
}
