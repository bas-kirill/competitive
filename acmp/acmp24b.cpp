#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    int n, m;
    cin >> n >> m;

    if (m > n)
    {
        cout << 0;
        return 0;
    }
    else if (n == m)
    {
        cout << 1;
        return 0;
    }
    else if (n > m && m == 1)
    {
        cout << n;
        return 0;
    }

    int ans = n - m + 1;

    for (int shift = 2; shift < n; shift++)
    {
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = i; j < n; j+=shift)
            {
                cnt++;
            }

            if (cnt == m)
            {
                ans++;
            }
        }
    }

    cout << ans;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
