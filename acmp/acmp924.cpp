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
    char a[4][4];

    for (auto &x : a)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
    }

    for (auto &x : a)
    {
        for (auto &y : x)
        {
            if (y == 'B')
            {
                y = 0;
            }
            else
            {
                y = 1;
            }
        }
    }

    bool cute = true;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            int sum = a[i-1][j-1] + a[i-1][j] + a[i][j-1] + a[i][j];
            //cout << sum << endl;
            if (sum == 4 || sum == 0)
            {
                cute = false;
            }
        }
    }

    if (cute)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
