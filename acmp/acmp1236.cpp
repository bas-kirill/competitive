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
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (auto &x : a)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
    }

    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //printf("j: %d, m-j-1: %d\n", j, m-j-1);
            swap(a[i][j], a[n-i-1][j]);
        }
    }

    for (auto x : a)
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
