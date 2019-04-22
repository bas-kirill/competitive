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
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    ull l, r;
    cin >> l >> r;
    vector<ull> a = {6LL, 28LL, 496LL, 8128LL, 33550336L, ll(8589869056), 137438691328, 2305843008139952128 * 1ll};
    //for (ull x : a) cout << x << '\n';
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        if (a[i] >= l && a[i] <= r) ++cnt, cout << a[i] << '\n';
    }

    if (cnt == 0) cout << "Absent";
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
