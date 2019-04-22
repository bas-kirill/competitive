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

    vector<vector<int>> a(n*n, vector<int>(n*n));

    for (auto &x : a)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
    }

    bool ok = true;

    //lines
    for (int i = 0; i < n*n; i++)
    {
        vector<bool> nums(n*n + 1, false);
        for (int j = 0; j < n*n; j++)
        {
            nums[a[i][j]] = true;
        }

        for (int j = 1; j < n*n+1; j++)
        {
            if (!nums[j])
            {
                //cout << j << endl;
                ok = false;
            }
        }
    }

    //columns
    for (int j = 0; j < n*n; j++)
    {
        vector<bool> nums(n*n+1, false);
        for (int i = 0; i < n*n; i++)
        {
            nums[a[i][j]] = true;
        }

        for (int j = 1; j < n*n+1; j++)
        {
            if (!nums[j])
            {
                ok = false;
            }
        }
    }

    //squares
    for (int k = 0; k < n*n; k++)
    {
        int b_i = (k / n) * n;
        int b_j = (k % n) * n;
        //printf("b_i: %d, b_j: %d\n", b_i, b_j);
        vector<bool> nums(n*n+1, false);
        for (int i = b_i; i < b_i + n; i++)
        {
            for (int j = b_j; j < b_j + n; j++)
            {
                //printf("i: %d, j: %d\n", i, j);
                nums[a[i][j]] = true;
            }
        }

        for (int i = 1; i < n*n+1; i++)
        {
            if (!nums[i])
            {
                ok = false;
            }
        }
    }

    if (ok)
    {
        cout << "Correct";
    }
    else
    {
        cout << "Incorrect";
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
