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
    ifstream cin("in.txt");
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<int> dp(n + 1, 1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mx_dp = 0;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && dp[mx_dp] < dp[j])
            {
                mx_dp = j;
            }
        }

        dp[i] = dp[mx_dp] + 1;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << ' ';
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
