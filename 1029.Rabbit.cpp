#include<bits/stdc++.h>
using namespace std;

const int maxn = 200;

struct bign {
    int l, s[maxn];
    bign() {
        memset(s, 0, sizeof(s));
        l = 1;
    }
    bign(int num) {
        *this = num;
    }

    bign operator = (int num) {
        char s[maxn];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    bign operator = (const char *num) {
    	int i;
        l = strlen(num);
        for (i = 0; i < l; i++) s[i] = num[l - i - 1] - '0';
        return *this;
    }

    string str() const {
    	int i;
        string a = "";
        for (i = 0; i < l; i++) a = (char)(s[i] + '0') + a;
        if (a == "") a = "0";
        return a;
    }

    bign operator + (const bign &b) const {
        int a = max(l, b.l), i, d, g;
        bign c;
        c.l = 0;
        for (i = 0, g = 0; g || i < a; i++) {
            d = g;
            if (i < l) d += s[i];
            if (i < b.l) d += b.s[i];
            c.s[c.l++] = d%10;
            g = d / 10;
        }
        return c;
    }
};

ostream& operator << (ostream &a, const bign &b)
{
    a << b.str();
    return a;
}

int main() {
    int m, d, i, j;
    bign num[11];
    while (cin >> m >> d) {
        if (!m && !d) break;
        num[0] = 1;
        for (i = 1; i <= m; i++) num[i] = 0;
        for (i = 1; i <= d; i++) {
            num[0] = num[0] + num[1];
            for (j = 1; j < m; j++) num[j]=num[j + 1];
            num[m] = num[0];
        }
        bign sum = 0;
        for (i = 0; i <= m; i++) sum = sum + num[i];
        cout << sum << endl;
    }
    return 0;
}
