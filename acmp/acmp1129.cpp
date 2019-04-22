#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    ld x, p, y;
    cin >> x >> p >> y;

    if (x >= y)
    {
        cout << 0;
        return 0;
    }

    x = x * 100;
    y = y * 100;

    int year = 0;
    while (x < y)
    {
        x = x * (1 + (ld(p) / 100.0));
        cout << x << endl;
        year++;
    }

    cout << year;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
