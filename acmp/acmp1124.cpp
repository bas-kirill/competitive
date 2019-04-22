#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    int x1, y1;
    int x2, y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;

    if (x1 == x2 || y1 == 1)
    {
        if (y1 == 2 && (y1 + 1 == y2 || y1 + 2 == y2))
        {
            cout << "YES";
        }
        else if (y1 > 2 && (y1 + 1 == y2))
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }
    else
    {
        cout << "NO";
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
