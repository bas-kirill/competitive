#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define len(x) int((x).size())
#define all(x) (x).begin(), (x).end()

int main() {
    //ifstream cin("in.txt");
    string s, s1;
    cin >> s;
    cin >> s1;

    int n = len(s);
    int m = len(s1);

    if (m > n)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    for (int i = 0; i <= n - m; i++)
    {
        if (s.substr(i, m) == s1)
        {
            cout << s;
            return 0;
        }
    }

    for (int shift = 25; shift >= 0; --shift) {
        string cs = s;
        for (char &c : cs) {
            c += shift;
            if (c > 'Z')
            {
                c = (c - 'Z') + 'A' - 1;
            }
        }

        for (int i = 0; i <= n - m; i++)
        {
            if (cs.substr(i, m) == s1)
            {
                cout << cs;
                return 0;
            }
        }

        //cout << cs << endl;
    }
    cout << "IMPOSSIBLE";
    return 0;
}

/*
* (Actually read this pls)
    * Rlly bad errors: int overflow, array bounds
    * Less bad errors: special cases (n=1?), set tle
    * Common sense: do smth instead of nothing
*/
