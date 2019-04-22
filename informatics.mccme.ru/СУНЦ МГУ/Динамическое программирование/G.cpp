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

vector<vector<int>> dp;
vector<vector<pair<int, int>>> p;
vector<int> a, b;

void print(int i, int j)
{
    if (i == 0 || j == 0)
    {
        return;
    }
    else
    {
        if (p[i][j].first == i - 1 && p[i][j].second == j - 1)
        {
            print(i - 1, j - 1);
            cout << a[i] << ' ';
        }
        else
        {
            if (p[i][j].first == i && p[i][j].second == j - 1)
            {
                print(i, j - 1);
            }
            else if (p[i][j].first == i - 1 && p[i][j].second == j)
            {
                print(i - 1, j);
            }
        }
    }
}

int main() {
    //ifstream cin("in.txt");
    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    int m;
    cin >> m;
    b.resize(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }

    dp.resize(n + 2, vector<int>(m + 2, 0));
    p.resize(n + 2, vector<pair<int,int>>(m + 2));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                p[i][j] = {i - 1, j - 1};
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    p[i][j] = {i - 1, j};
                }
                else
                {
                    p[i][j] = {i, j - 1};
                }
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            cout << dp[i][j] << " ";
//        }
//
//        cout << '\n';
//    }


    print(n, m);
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
