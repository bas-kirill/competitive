#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    cout.precision(2);
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int det = a * d - b * c;
    int det_x = e * d - b * f;
    int det_y = a * f - e * c;

    if (det != 0)
    {
        long double x = det_x / det;
        long double y = det_y / det;
        cout << 2 << " " << fixed << x << " " << y;
    }
    else
    {
        if (det_x == 0 || det_y == 0)
        {
            cout << "2XY";
        }
        else
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
