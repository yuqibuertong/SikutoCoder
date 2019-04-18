#include<bits/stdc++.h>
using namespace std;

int twesum(int a) {
    int b = 1728, s = 0, gun[4], i;
    for (i = 0; i < 4; i++) {
    	gun[i] = a / b;
    	a -= gun[i] * b;
    	b /= 12;
    	s += gun[i];
	}
	return s;
}

int decsum(int a) {
    int b = 10, s = 0;
    while (a) {
    	s += a % b;
    	a /= b;
	}
	return s;
}

int hexsum(int a) {
	int b = 4096, s = 0, gun[4], i;
    for (i = 0; i < 4; i++) {
    	gun[i] = a / b;
    	a -= gun[i] * b;
    	b /= 16;
    	s += gun[i];
	}
	return s;
}

int main()
{
	int i, a;
	for (i = 2992; i < 10000; i++) {
		a = decsum(i);
		if (a == twesum(i) && a == hexsum(i))
			printf("%d\n", i);
	}
    return 0;
}
