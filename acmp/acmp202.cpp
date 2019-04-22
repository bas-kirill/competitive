#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

vector<int> prefix(string &s)
{
    int n = len(s);
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}

int main() {
    string s, t;
    cin >> s >> t;

    string t_s = t + "#" + s;

    vector<int> kmp = prefix(t_s);
//    for (int i = 0; i < len(kmp); i++)
//    {
//        cout << "i: " << i << " kmp[i]: " << kmp[i] << endl;
//    }
    for (int i = 0; i < len(kmp); i++)
    {
        if (kmp[i] == len(t))
        {
            cout << i - 2 * len(t) << " ";
        }
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
