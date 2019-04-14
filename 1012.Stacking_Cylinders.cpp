#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, i, j;
	while (scanf("%d", &n) && n) {
		vector<pair<double, double> > d(n * (n + 1) / 2);
		for (i = 0; i < n; i++) scanf("%lf", &d[i].first);
		for (i = 0; i < n; i++) d[i].second = 1;
		sort(d.begin(), d.begin() + n);
		while (n > 1) {
			for (j = 0; j < n - 1; j++) {
				double t1 = d[i - n + 1].first - d[i - n].first,
				t2 = d[i - n + 1].second - d[i - n].second,
				a1 = atan(t2 / t1), a2 = acos(sqrt(t1 * t1 + t2 * t2) / 4),
				a = a1 + a2;
				d[i].first = d[i - n].first + 2 * cos(a);
				d[i].second = d[i - n].second + 2 * sin(a);
				++i;
			}
			--n;
		}
		printf("%.4f %.4f\n", d[d.size() - 1].first, d[d.size() - 1].second);
	}
	return 0;
}
