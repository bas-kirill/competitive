//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

vector<vector<ll>> h;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    h.resize(m + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        h[a].push_back(b);
    }

    for (int i = 0; i < len(h); i++)
        if(len(h[i]) > 0)
            sort(rall(h[i]));

    vector<ll> sumv(n + 1, 0), sumh(n + 1, 0);

    for (int i = 1; i < m + 1; i++) {
        ll gs = 0;
        for (int j = 0; j < len(h[i]); j++)
            if (gs + h[i][j] >= 0)
                gs += h[i][j];
            else
                h[i][j] = 0;
    }

    for (int i = 1; i < m + 1; i++) {
        int k = len(h[i]);
        for (int j = 0; j < len(h[i]); j++)
            sumh[k] += h[i][j];
    }

    for (int i = 1; i <= m; i++)
        for (int j = 0; j < len(h[i]); j++)
            sumv[j] += h[i][j];

    ll ans = 0, zt = 0;
    for (int i = 0; i < n + 1; i++) {
        zt -= sumh[i], zt += sumv[i];
        ans = max(ans, zt);
    }

    cout << ans;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
