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
    int sum = 0;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
        sum += x;
    }

    if (sum & 1)
    {
        cout << "NO";
        return 0;
    }

    int N = sum / 2;
    vector<int> dp(N + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int cur = a[i];
        for (int j = N; j >= 0; --j)
        {
            dp[j] = min(dp[j - cur], )
        }
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
