#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
int l, s, t, m, pos[101], f[maxn];
bool has[maxn];

int num(){
	int i, j, k = 0, temp = 0;
    if (s == t) {
        for (i = 1; i <= m; i++)
			if (pos[i] % s == 0) k++;
        return k;
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    sort(pos + 1, pos + m + 1);
    for (i = 1; i <= m; i++) {
    	temp += min(pos[i] - pos[i - 1], 100);
		has[temp] = 1;
	}
    temp += min(l - pos[m], 100);
    for (i = 1; i <= temp + 9; i++)
        for (j = s; j <= t; j++)
			if (i >= j) f[i] = min(f[i], f[i - j] + has[i]);
    k = 1e9;
    for (i = temp; i <= temp + 9; i++) k = min(k,f[i]);
    return k;
}

int main(){
	int i;
    scanf("%d%d%d%d", &l, &s, &t, &m);
    for (i = 1; i <= m; i++) scanf("%d", &pos[i]);
    printf("%d\n", num());
    return 0;   
}
