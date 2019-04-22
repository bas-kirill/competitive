#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

vector<int> prefix_function(string s)
{
    int n = s.length();
    vector<int> pi(n);
    pi[0] = 0;
    int val = 0;
    for (int i = 1; i < n; i++)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
        {
            j = pi[j-1];
        }
        if (s[j] == s[i])
        {
            j++;
        }

        pi[i] = j;
    }
    return pi;
}

int main() {
    string s;
    cin >> s;

    vector<int> ans = prefix_function(s);

    for (int x : ans)
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
