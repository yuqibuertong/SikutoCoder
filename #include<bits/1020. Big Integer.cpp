#include<bits/stdc++.h> 
using namespace std;

string integer;
int x[400];

void stoi() {
	for (int i = 0; i < integer.length(); i++)
		x[i] = integer[i] - '0';
}

void getmod(int n, int modn[]) {
	int a, i, j;
	for (i = 0; i < n; i++) {
		a = modn[i];
		modn[i] = 0;
		for (j = 0; j < integer.length(); j++)
			modn[i] = (modn[i] * 10 + x[j]) % a;
	}
}

int main() {
	int n, i, t, j;
	int modn[100];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (i = 0; i < n; i++)
			scanf("%d", &modn[i]);
		cin >> integer;
		stoi();
		getmod(n, modn);
		printf("(%d", modn[0]);
		for (i = 1; i < n; i++) printf(",%d", modn[i]);
		printf(")\n");
	}
	return 0;
}
