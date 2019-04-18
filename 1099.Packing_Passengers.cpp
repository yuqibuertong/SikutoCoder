#include<bits/stdc++.h>

int main () {
    long long pA, pB, costA, costB, e, x, y, k, p;
    int num, t = 1;
    while (scanf("%d", &num) && num) {
        scanf("%lld%lld%lld%lld", &costA, &pA, &costB, &pB);
        if (pA && pB == 0) {
            x = num / pA; 
            y = 0;
            e = num % pA;
        }
		else if (pA ==0 && pB) {
            x = 0;
            y = num / pB;  
            e = num % pB;
        }
		else if (pA == 0 && pB == 0) e = 1;
		else {
            k = costA * pB - costB * pA;
            p = (long long)floor((double)(num / pA));
            if (k > 0)
                for (x = 0; x <= p; x++) {
                    y = (num - pA * x) / pB;
                    e = (num - pA * x) % pB;   
                    if (!e) break;
                }
			else
                for (x = p; x >= 0 ; x--) {
                    y = (num - pA * x) / pB;
                    e = (num - pA * x) % pB;   
                    if (!e) break;
                }
        }
        printf("Data set %d: ", t++);
        if (!e) printf("%lld aircraft A, %lld aircraft B\n", x, y);
        else printf("cannot be flown\n");              
    }
    return 0;
}
