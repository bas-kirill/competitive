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
    int prev_num = -1;
    int num;

    int ans_i = 0;
    int ans_d = 0;
    int cnt = 1;
    do
    {
        prev_num = num;
        cin >> num;

        if (prev_num > num)
        {
            ans_i++;
        }
        else
        {
            if (cnt > ans_i)
        }

        //printf("%d:%d\n", ans_i, ans_d);
    } while (num != 0);

    cout << max(ans_i, ans_d-1);
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
