#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(X) int((X).size())

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<int> a(2 * n);
    for (auto &x : a) cin >> x;

    const auto cmp = [&](int x, int y) { return a[x] > a[y] || (a[x] == a[y] && x < y); };
    set<int, decltype(cmp)> st(cmp);
    for (int i = 0; i < 2 * n; i++) st.insert(i);

    vector<pii> p;
    vector<int> f(2 * n, -1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        if (a[u] < a[v])
            swap(u, v);
        p.pb({u, v});
        f[u] = v;
        f[v] = u;
        st.erase(u), st.erase(v);
    }

    int t;
    cin >> t;
    if (t == 1) {
        for (int i = 0; i < m; i++) {
            cout << p[i].first + 1 << endl;
            int x; cin >> x;
        }
        while (sz(st)) {
            cout << *st.begin() + 1 << endl;
            st.erase(st.begin());
            int x;
            cin >> x;
            x--;
            st.erase(x);
        }
    } else {
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            x--;
            if (f[x] != -1) { cout << f[x]+1 << endl; f[x] = -1; }
            else {
                st.erase(x);
                for (int i = 0; i < m; i++) {
                    if (f[p[i].first] != -1 && f[p[i].second] != -1) {
                        cout << p[i].first + 1 << endl;
                        int x; cin >> x;
                    }
                }
                break;
            }
        }
        while (sz(st)) {
            cout << *st.begin()+1 << endl;
            st.erase(st.begin());
            if (!sz(st)) return 0;
            int x;
            cin >> x;
            x--;
            st.erase(x);
        }
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
