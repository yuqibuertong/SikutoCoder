#include<bits/stdc++.h>
using namespace std;
typedef struct node{
	int num;
	struct node* next;	
}l;
int main() {
	l* a, *b, *c;
	int k = 0;
	int i;
	a = new node;
	a->next = NULL;
	c = a;
	while (1) {
		cin >> i;
		if (i == -1) break;
		c->next = new node;
		c = c->next;
		c->next = NULL;
		c->num = i;
	}
	b = new node;
	b->next = NULL;
	c = b;
	while (1) {
		cin >> i;
		if (i == -1) break;
		c->next = new node;
		c = c->next;
		c->next = NULL;
		c->num = i;
	}
	a = a->next;
	b = b->next;
	while (a !=NULL && b != NULL) {
		if (a->num <= b->num) {
			if (k) cout << " " << a->num;
			else {
				k++;
				cout << a->num;
			}
			a = a->next;
		}
		else {
			if (k) cout << " " << b->num;
			else {
				k++;
				cout << b->num;
			}
			b = b->next;
		}
	}
	while (a !=NULL) {
		if (k) cout << " " << a->num;
		else {
			k++;
			cout << a->num;
		}
		a = a->next;
	}
	while (b != NULL) {
		if (k) cout << " " << b->num;
		else {
			k++;
			cout << b->num;
		}
		b = b->next;
	}
	if (!k) cout << "NULL";
	return 0;
}
