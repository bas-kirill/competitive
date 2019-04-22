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
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> a(n, vector<int>(m)), b(m, vector<int>(p));

    for (auto &x : a)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
    }

    for (auto &x : b)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
    }

    if (m > p)
    {
        swap(a, b);
    }

    vector<vector<int>> c(n, vector<int>(p, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < m; k++)
            {
                c[i][j] += (a[i][k] * b[k][j]);
            }
        }
    }

    for (auto x : c)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << '\n';
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
