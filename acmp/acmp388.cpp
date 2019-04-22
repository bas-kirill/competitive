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

    vector<int> min_lines(n);

    for (int i = 0; i < n; i++)
    {
        int mn = 0;
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] < a[i][mn])
            {
                mn = j;
            }
        }

        min_lines[i] = a[i][mn];
    }

    vector<int> max_columns(m);

    for (int j = 0; j < m; j++)
    {
        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] > a[mx][j])
            {
                mx = i;
            }
        }

        max_columns[j] = a[mx][j];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (min_lines[i] == a[i][j] && max_columns[j] == a[i][j])
            {
                ++ans;
//                cout << a[i][j] << endl;
//                cout << a[max_columns[j]][min_lines[i]] << endl;
            }
        }
    }

    cout << ans << '\n';

//    for (int x : min_lines)
//    {
//        cout << x << " ";
//    }
//    cout << endl;
//    for (int x : max_columns)
//    {
//        cout << x << " ";
//    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/

/*
3 3
1 2 3
4 5 6
7 8 9
*/
