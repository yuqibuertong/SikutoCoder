#include<bits/stdc++.h>
using namespace std;

const int maxn = 10000;
pair<int, int> p[maxn];
int s, a[maxn], b[maxn], n = 1;

bool judge()
{
	int i;
	long long sum = s;
	for (i = 0; i < n; i++) p[i] = make_pair(b[i], a[i]);
	sort(p, p + n);
	for (i = 0; i < n; i++) {
		if (sum < p[i].first) return 0;
		sum += p[i].second;
	}
	return 1;
}

int main()
{
	int i;
    scanf("%d%d", &n, &s);
    while (n) {
    	for (i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
    	printf("%s\n", judge()? "YES" : "NO");
    	scanf("%d%d", &n, &s);
	}
	return 0;
}
