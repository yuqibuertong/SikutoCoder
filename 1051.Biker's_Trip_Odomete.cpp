#include<bits/stdc++.h> 
using namespace std;
int main() {
	int rev, i = 0;
	double dia, time, dis, spe, p = 3.1415927 / 63360;
	while (scanf("%lf %d %lf", &dia, &rev, &time)) {
		if (rev == 0) break;
		i++;
		dis = dia * rev * p;
		spe = dis * 3600 / time;
		printf("Trip #%d: %.2lf %.2lf\n", i, dis, spe);
	}
	return 0;
}
