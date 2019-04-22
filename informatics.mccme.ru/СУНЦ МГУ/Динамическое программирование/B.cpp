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

struct client
{
    int A, B, C;
};

int main() {
    int n;
    cin >> n;

    vector<client> clients(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> clients[i].A >> clients[i].B >> clients[i].C;
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = clients[1].A;
    dp[2] = min(clients[1].A + clients[2].A, clients[1].B);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = min({dp[i-1]+clients[i].A, dp[i-2]+clients[i-1].B, dp[i-3]+clients[i-2].C});
    }

    cout << dp[n];
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
