#include<bits/stdc++.h>
using namespace std;

unsigned l, k = 0;

unsigned reverse(unsigned num)
{
    unsigned a = 0;
    while (num) {
        a = a << 1 | (num & 1);
        num >>= 1;
    }
    return a;
}

void dfs(unsigned sum, int a)
{
    if (a)
    {
	    dfs(sum << 1, a - 1);
	    dfs((sum << 1) + 1, a - 1);
    }
	else if (sum != 0) {
    	unsigned len = 0, b = sum;
    	while (b) {
    		b >>= 1;
			len++;
		}
    	if(((sum << len) | (reverse(sum))) <= l) k++;
    	if(((sum << len - 1) | reverse(sum >> 1)) <= l) k++;
	}
}

int main()
{
	scanf("%u", &l);
    dfs(0, 16);
    printf("%u\n", k);
    return 0;
}
