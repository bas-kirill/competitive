#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")

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

    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    else if (n == 2)
    {
        cout << 1 << ' ' << 3 << '\n' << 2 << ' ' << 4;
        return 0;
    }

    vector<vector<int>> a(n, vector<int>(n));

    int cnt = 1;
    a[0][0] = cnt++;
    //first part
    for (int i = 1; i < n; i++)
    {
        //odd
        if (i % 2 == 1)
        {
            int x = 0;
            int y = i;

            while (y >= 0)
            {
                a[y][x] = cnt++;
                --y, ++x;
            }
        }
        else
        {
            //even
            int x = i;
            int y = 0;

            while (x >= 0)
            {
                a[y][x] = cnt++;
                ++y, --x;
            }
        }
    }
    vector<vector<int>> part_1(n, vector<int>(n));
    for (int i = n-2; i > 0; --i)
    {
        //odd
        if (i % 2 == 1)
        {
            int x = 0;
            int y = i;

            while (y >= 0)
            {
                part_1[y][x] = cnt++;
                --y, ++x;
            }
        }
        else
        {
            //even
            int x = i;
            int y = 0;

            while (x >= 0)
            {
                part_1[y][x] = cnt++;
                ++y, --x;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            swap(part_1[i][j], part_1[n-j-1][n-i-1]);
        }
    }

//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            cout << part_1[i][j] << " ";
//        }
//        cout << '\n';
//    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
            {
                a[i][j] = part_1[i][j];
            }
        }
    }

    a[n-1][n-1] = n*n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << setw(4) <<  a[i][j] << " ";
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
