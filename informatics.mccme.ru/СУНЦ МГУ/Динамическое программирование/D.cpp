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

int n, m;
ll dp[20][20];

ll f(int i, int j)
{
    //cout << "i: " << i << " " << "j: " << j << " " << dp[i][j] << endl;
    if (!(i >= 1 && i <= n && j >= 1 && j <= m))
    {
        return 0;
    }
    else if (dp[i][j] == 1)
    {
        return 1;
    }
    else
    {
        //first
        dp[i][j] = 0;

        dp[i][j] += f(i-1, j-2);
        dp[i][j] += f(i+1, j-2);
        dp[i][j] += f(i - 2, j - 1);
        dp[i][j] += f(i - 2, j + 1);
    }
    return dp[i][j];
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = -1;
        }
    }

    dp[1][1] = 1;

    cout << f(n, m) << endl;

//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cout << setw(4) << dp[i][j] << " ";
//        }
//        cout << endl;
//    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
