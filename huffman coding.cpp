#include<queue>
#include<iostream>
using namespace std;

struct cmp {
	bool operator ()(int &a, int &b) {
		return a > b;
	}
};
int main() {
	int n, b, num1, num2, sum = 0;
	char a;
	priority_queue<int, vector<int>, cmp>q;
	scanf("%d", &n);
	while (n--) {
		cin >> a >> b;
		q.push(b);
	}
	b = 0;
	while (!q.empty()) {
		sum += b;
		if (q.size() == 1) break;
		num1 = q.top(); q.pop();
		num2 = q.top(); q.pop();
		b = num1 + num2;
		q.push(b);
	}
	printf("%d\n", sum);
	return 0;
}
