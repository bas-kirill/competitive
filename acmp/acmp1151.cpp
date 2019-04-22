#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    string s;
    cin >> s;

    bool isLower = false, isUpper = false, isCipher = false;
    for (char c : s)
    {
        if (c >= 'A' && c <= 'Z')
        {
            isUpper = true;
        }
        else if (c >= 'a' && c <= 'z')
        {
            isLower = true;
        }
        else if (c >= '0' && c <= '9')
        {
            isCipher = true;
        }
    }

    if (isLower && isUpper && isCipher && len(s) >= 12)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
