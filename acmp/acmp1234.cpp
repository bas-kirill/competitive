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
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));

    for (auto &x : a)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            swap(a[i][j], a[n-j-1][n-i-1]);
        }
    }

    for (auto x : a)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
