#include<bits/stdc++.h> 
using namespace std;

struct gun {
	int a[2][4];
	string s;
};

bool match(int x[2][4], int y[2][4]) {
	int i, j;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++)
			if (x[i][j] != y[i][j]) return 0;
	return 1;
}

int target[2][4];
int start[2][4] = {1, 2, 3, 4, 5, 6, 7, 8};
int visit[41000];

gun initial;

int factorial(int n) {
	int i = 1;
	while (n)	{
		i = i * n;
		n--;
	}
	return i;
}

int Cantor(gun& x) {
	int ans = 0, vis[9] = {0}, i, j, k, p, t;
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++) {
    		vis[x.a[i][j]] = 1;
			t = x.a[i][j] - 1;
			p = t;
			for (k = 1; k <= p; k++)
				if (vis[k]) t--;
			ans += t * factorial(8 - 4 * i - j - 1);
		}
	return ans;
}

gun change(gun x, int t) {
	int i, j, k, p;
	if (t == 1) {
		i = x.a[0][0];
		x.a[0][0] = x.a[0][2];
		j = x.a[0][1];
        x.a[0][1] = x.a[0][3];
		k = x.a[1][0];
		x.a[1][0] = x.a[1][2];
		p = x.a[1][1];
		x.a[1][1] = x.a[1][3];
 		x.a[0][2] = i;
		x.a[0][3] = j;
		x.a[1][2] = k;
		x.a[1][3] = p;
		x.s = x.s + "A";
	}
	else if (t == 2) {
		i = x.a[0][0];
		j = x.a[1][0];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
				x.a[i][j] = x.a[i][j + 1];
		x.a[0][3] = i;
		x.a[1][3] = j;
		x.s = x.s + "B";
	}
	else {
		i = x.a[0][1];
		x.a[0][1] = x.a[0][2];
		x.a[0][2] = x.a[1][2];
		x.a[1][2] = x.a[1][1];
		x.a[1][1] = i;
		x.s = x.s + "C";
	}
	return x;
}

void bfs(int n) {
	int i;
	queue<gun> q;
	q.push(initial);
	while (!q.empty()) {
		gun top = q.front();
		if (top.s.length() > n) {
			printf("-1\n");
			return;
		}
 		if (match(top.a, target)) {
			cout << top.s.length() << " " << top.s << endl;
			return;
		}
		if (!visit[Cantor(top)]) {
			for (i = 1; i <= 3; i++) {
				gun x = change(top, i);
				q.push(x);
			}
			visit[Cantor(top)] = 1;
		}
		q.pop();
	}
}


int main() {
	int n, k, i, j;
	initial.s = "";
	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++)
			initial.a[i][j] = start[i][j]; 
	while (scanf("%d", &n) && n != -1) {
		fill(visit, visit + 41000, 0);
		for (i = 0; i < 2; i++)
			for (j = 0; j < 4; j++)
	 			scanf("%d", &target[i][j]);
		bfs(n);
	}
	return 0;
}
