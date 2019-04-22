#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int ans = 0;

void f(int n)
{
    cout << "new: " << n << endl;
    if (n == 2 || n == 1)
    {
        ans++;
    }
    else
    {
        for (int i = n-1; i >= 2; --i)
        {
            cout << n - i << endl;
            f(n - i);
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    f(n);
    cout << ans;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
