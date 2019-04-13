#include <bits/stdc++.h>
using namespace std;

int a, b[105];
bool visit[10][10];

struct dir {
	int x, y, n;
}d[10];

bool cmp(dir a, dir b) {
	return a.n < b.n;
}

int num(int x, int y)
{
  int i, tx, ty, temp = 0;
  for (i = 0; i < 8; i++)
  {
    tx = x + d[i].x;
    ty = y + d[i].y;
    if (tx >= 0 && tx < 6 && ty >= 0 && ty < 5) temp++;
  }
  return temp;
} 

void dfs(int x, int y, int cur) {
	if (a) return;
	int i;
	b[cur] = x + y * 6 + 1;
	if (cur == 29) {
		for (i = 0; i < 29; i++) printf("%d ", b[i]);
		printf("%d\n", b[i]);
		a = 1;
		return;
	}
	for (i = 0; i < 8; i++) d[i].n = num(x + d[i].x, y + d[i].y);
	sort(d, d + 8, cmp);
	for (i = 0; i < 8; i++) {
		int tx = x + d[i].x;
		int ty = y + d[i].y;
		if (tx >= 0 && tx < 6 && ty >= 0 && ty < 5 && !visit[tx][ty]) {
	    	visit[tx][ty] = 1;
	    	dfs(tx, ty, cur + 1);
	    	visit[tx][ty] = 0;
		}
	}
}

void init() {
	d[0].x = 1; d[0].y = 2;
	d[1].x = 2; d[1].y = 1;
	d[2].x = 1; d[2].y = -2;
	d[3].x = 2; d[3].y = -1;
	d[4].x = -1; d[4].y = 2;
	d[5].x = -2; d[5].y = 1;
	d[6].x = -1; d[6].y = -2;
	d[7].x = -2; d[7].y = -1;	
}

int main()
{
	int i, s;
	init();
	while (scanf("%d", &s) && s != -1) {
    	memset(visit, 0, sizeof(visit));
    	a = 0;
    	s--;
    	visit[s % 6][s / 6] = 1;
    	dfs(s % 6, s / 6, 0);
	}
	return 0;
}
