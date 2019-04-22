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

    int ans = 0;
    while (n)
    {
        ans += n % 10;
        n /= 10;
    }

    cout << ans;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
