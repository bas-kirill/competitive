#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    string s, t;
    cin >> s >> t;

    string tt = t + t;

    for (int i = 0; i < len(tt) - len(s); i++)
    {
        if (tt.substr(i, len(s)) == s)
        {
            cout << i;
            return 0;
        }
    }

    cout << -1;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
