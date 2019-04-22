#include <bits/stdc++.h>
using namespace std;

int my_pow(int x, int n)
{
    int k = 1;
    for (int i = 1; i <= n; i++)
        k = k * x;
    return k;
}

bool is_num(char c) { return (c >= '0' && c <= '9'); }
bool is_char(char c) { return (c >= 'A' && c <= 'Z'); }

int main() {
    string s;
    int p;
    cin >> s >> p;

    for (int i = s.length() - 1; i >= 0; --i) {
        int n;
        if (p <= 10)
            if (!is_num(s[i])) {
                cout << "WRONG INPUT";
                return 0;
            }
        else
            if (!is_num(s[i]))
                if (!is_char(s[i])) {
                    cout << "WRONG INPUT";
                    return 0;
                }
    }

    for (int i = s.length() - 1; i >= 0; --i) {
        int n;
        if (p <= 10)
            n = s[i] - '0';
        else
            if (!is_num(s[i])) {
                n = s[i] - 'A' + 10;
            } else n = s[i] - '0';

        if (n >= p)
        {
            cout << "WRONG INPUT";
            return 0;
        }
    }

    int tmp = 0;
    for (int i = s.length() - 1; i >= 0; --i) {
        int n;
        if (p <= 10)
            n = s[i] - '0';
        else
            if (!is_num(s[i])) {
                n = s[i] - 'A' + 10;
            } else n = s[i] - '0';

        tmp = tmp + my_pow(p, s.length() - i - 1) * n;
        //cout << i << "  " << n << " " << tmp << '\n';
    }

    cout << s << "(" << p << ")=" << tmp << "(10)";
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
