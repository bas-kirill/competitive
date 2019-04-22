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
    ull n;
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        bool flag = false;
        for (int j = 29; j >= 1; --j)
        {
            bool _1 = (i & (1 << (j+1)));
            bool _2 = (i & (1 << j));
            bool _3 = (i & (1 << (j-1)));
            if (_1 + _2 + _3 == 3)
            {
                flag = true;
            }
        }

//        int tmp_i = i;
//        while (tmp_i)
//        {
//            cout << tmp_i % 2;
//            tmp_i /= 2;
//        } cout << endl;

        //printf("i: %d, flag: %d\n", i, flag);
        if (!flag)
        {
            dp[int(log2(i))]++;
        }
    }

    for (int x : dp)
    {
        cout << x << " ";
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
