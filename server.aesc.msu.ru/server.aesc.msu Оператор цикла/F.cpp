#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    int n;
    cin >> n;
    int val;
    int mn = 1e9;
    int ans_cnt = 1;
    int cnt = 1;
    while (n--)
    {
        cin >> val;
        if (val < mn)
        {
            mn = val;
            ans_cnt = max(ans_cnt, cnt);
            cnt = 1;
        }
        else if (val == mn)
        {
            ++cnt;
        }
    }

    ans_cnt = max(ans_cnt, cnt);

    cout << ans_cnt;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
