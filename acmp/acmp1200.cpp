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
    ifstream cin("in.txt");
    int n;
    cin >> n;
    string line;
    getline(cin, line);
    for (int k = 0; k < n; k++)
    {
        getline(cin, line);

        string s = "";
        vector<string> ans;

        for (int i = 0; i < len(line); i++)
        {
            if (isalpha(line[i]))
            {
                s.push_back(line[i]);
            }
            else
            {
                ans.push_back(s);
                s = "";
            }
        }

        if (s != "")
        {
            ans.push_back(s);
        }

        reverse(all(ans));

        for (string x : ans)
        {
            cout << x << " ";
        }

        cout << '\n';
    }
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
