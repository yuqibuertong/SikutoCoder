#include<bits/stdc++.h> 
using namespace std;

int x[101], y[101];
double graph[101][101];
vector<double> edges;

void prim(int n) {
	int i, j;
	bool ifdone[n] = {0};
	double length[n];
	for (i = 0; i < n; i++) length[i] = graph[0][i];
	ifdone[0] = 1;
	edges.clear();
	for (i = 1; i < n ; i++) {
		int next = 0;
		double lowcost = 99999999;
		for (j = 1; j < n; j++)
			if (!ifdone[j] && length[j] < lowcost) {
				lowcost = length[j];
				next = j;
			}
		ifdone[next] = 1;
		edges.push_back(lowcost);
		for (j = 0; j < n; j++)
			if (graph[next][j] < length[j]) length[j] = graph[next][j];
	}
	sort(edges.begin(), edges.end());
}

int main() {
	int n, k, i, j;
	while (scanf("%d %d", &n, &k)) {
		for (i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]);
		for (i = 0; i < n; i++)
			for (j = i; j < n; j++)
				graph[i][j] = graph[j][i] = sqrt(pow(x[j] - x[i], 2) + pow(y[j] - y[i], 2));
		prim(n);
		printf("%.2lf\n", edges[edges.size() - (k - 1)]);
	}
	return 0;
}
