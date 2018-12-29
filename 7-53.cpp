#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int num;
	struct node* next;	
}l;
int main() {
	l* a, *b, *c;
	int k = 1;
	int i, n, j;
	cin >> n;
	a = new node;
	a->next = NULL;
	c = a;
	for (j = 0; j < n; j++) {
		cin >> i;
		c->next = new node;
		c = c->next;
		c->next = NULL;
		c->num = i;
	}
	b = new node;
	b->next = NULL;
	c = b;
	for (j = 0; j < n; j++) {
		cin >> i;
		c->next = new node;
		c = c->next;
		c->next = NULL;
		c->num = i;
	}
	a = a->next;
	b = b->next;
	while (a !=NULL && b != NULL) {
		if (a->num <= b->num) {
			if (k == n) {
				cout << a->num;
				return 0;
			}
			else {
				k++;
				a = a->next;
			}
		}
		else {
			if (k == n) {
				cout << b->num;
				return 0;
			}
			else {
				k++;
				b = b->next;
			}
		}
	}
	return 0;
}
