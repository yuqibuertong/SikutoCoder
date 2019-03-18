#include<bits/stdc++.h>
using namespace std; 

struct period {    
	int st, ed;
	double ave;
}; 
 
bool cmp(period a, period b) {      
	if (a.ave > b.ave) return 1;      
	if (a.ave == b.ave && (a.ed - a.st > b.ed - b.st)) return 1;      
  	if (a.ave == b.ave && (a.ed - a.st == b.ed - b.st) && (a.ed < b.ed))         
  		return 1;      
  	return 0;
}

int main() {        
  	int t, i = 1, j, n, len, best, k, q, c;
	int plane[300];
	struct period p[99999];  
  	scanf("%d", &t);      
  	while (t--) {
	  	c = 0;               
  		scanf("%d %d %d", &n, &best, &len);               
  		for (j = 0; j < n; j++) scanf("%d", &plane[j]);        
	  	for (j = len; j <= n; j++)
	  		for (k = 0; k + j <= n; k++) {                
	  			double sum = 0;                
	  			for (q = k; q - k < j; q++) sum += plane[q];
	  			p[c].st = k + 1;                
	  			p[c].ed = j + k;                
	  			p[c].ave = sum / j;                
	  			c++;              
	  		}
	  	sort(p, p + c, cmp);         
	  	printf("Result for run %d:\n", i);
		i++;    
  		for (k = 0; k < best && k < c; k++)
  			printf("%d-%d\n", p[k].st, p[k].ed);      
  	}   
  	return 0;
}
