#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    long long a, b;
    cin >> a >> b;
    if (a == 0)
    {
        cout << 0;
    }
    else if (a > 0)
    {
        if (b > 0)
        {
            cout << a % b;
        }
        else
        {
            cout << a % abs(b);
        }
    }
    else if (a < 0)
    {
        long long ost = abs(a / b);
        if (b > 0)
        {
            cout << ((ost + 1) * abs(b) + a) % abs(b);
        }
        else
        {
            cout << ((ost + 1) * abs(b) + a) % abs(b);
        }
    }
}
m
/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
