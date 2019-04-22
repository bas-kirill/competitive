#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    int n, m;
    ll ans = 0;
    cin >> n >> m;

    vector<int> cnt(m);
    for (int i = 1; i < m + 1; i++) {
        cnt[(i * i) % m] += (n / m) + (n % m >= i);
    }

    for (int i = 0; i < m; i++) {
        ans += cnt[i] * 1ll * cnt[(m - i) % m];
    }

    cout << ans;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
