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

const int maxn = 1e5;

int n;
int a[maxn + 100], b[maxn + 100], t[maxn + 100];

void f(int i, int v)
{
    if (i == n)
    {
        return;
    }
    for (int k = 0; k <= 3; k++)
    {
        if ((v | k) == a[i] && (v & k) == b[i])
        {
            t[i] = v;
            f(i + 1, k);
            break;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }


    for (int i = 0; i <= 3; i++)
    {
        f(0, i);
    }

    for (int i = 0; i < n - 1; i++)
    {
        cout << t[i] << ' ';
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
