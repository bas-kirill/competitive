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
    int num;
    int prev_num = -1;
    int ans = 0;
    do
    {
        cin >> num;

        if (prev_num == -1)
        {
            prev_num = num;
        }
        else
        {
            if (num > prev_num)
            {
                ++ans;
            }

            prev_num = num;
        }
    } while (prev_num != 0);

    cout << ans;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
