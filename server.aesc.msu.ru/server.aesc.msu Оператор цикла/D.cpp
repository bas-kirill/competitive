#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    int n;
    cin >> n;
    int mn_1 = 1e9;
    int mn_2 = 1e9;

    int val;
    while (n--)
    {
        cin >> val;
        if (val < mn_1)
        {
            mn_2 = mn_1;
            mn_1 = val;
        }
        else if (val < mn_2)
        {
            mn_2 = val;
        }
    }

    cout << mn_1 << ' ' << mn_2;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
